import 'package:flutter/foundation.dart';

import '../data/vault_repository.dart';
import '../model/note_models.dart';

class AppController extends ChangeNotifier {
  AppController(this._repository);

  final VaultRepository _repository;

  bool _ready = false;
  int _tabIndex = 0;
  String _query = '';
  List<Note> _notes = <Note>[];
  ThemeModePreference _themeMode = ThemeModePreference.system;
  String? _selectedNoteId;

  bool get isReady => _ready;
  int get tabIndex => _tabIndex;
  String get query => _query;
  ThemeModePreference get themeMode => _themeMode;
  List<Note> get notes => List<Note>.unmodifiable(_notes);
  Note? get selectedNote => noteById(_selectedNoteId);

  List<Note> get filteredNotes {
    final needle = _query.trim().toLowerCase();
    final results = _notes.where((Note note) {
      if (needle.isEmpty) {
        return true;
      }
      final haystacks = <String>[
        note.displayTitle,
        note.content,
        note.allTags.join(' '),
      ];
      return haystacks.any((String haystack) => haystack.toLowerCase().contains(needle));
    }).toList();
    sortNotes(results);
    return results;
  }

  Future<void> initialize() async {
    final snapshot = await _repository.loadSnapshot();
    _notes = snapshot.notes;
    sortNotes(_notes);
    _themeMode = snapshot.themeMode;
    _selectedNoteId = _notes.isEmpty ? null : _notes.first.id;
    _ready = true;
    notifyListeners();
  }

  Future<void> saveDraft(NoteDraft draft) async {
    final existing = draft.noteId == null ? null : noteById(draft.noteId);
    final next = draft.toNote(existing: existing);
    final nextNotes = <Note>[
      for (final Note note in _notes)
        if (note.id != next.id) note,
    ];
    nextNotes.add(next);
    sortNotes(nextNotes);
    _notes = nextNotes;
    _selectedNoteId = next.id;
    notifyListeners();
    await _repository.saveNotes(_notes);
  }

  Future<void> deleteNote(Note note) async {
    _notes = _notes.where((Note item) => item.id != note.id).toList();
    sortNotes(_notes);
    if (_selectedNoteId == note.id) {
      _selectedNoteId = _notes.isEmpty ? null : _notes.first.id;
    }
    notifyListeners();
    await _repository.saveNotes(_notes);
  }

  Future<void> togglePinned(Note note) async {
    final updated = note.copyWith(
      isPinned: !note.isPinned,
      updatedAt: DateTime.now(),
    );
    await saveDraft(updated.toDraft());
  }

  Future<void> setThemeMode(ThemeModePreference value) async {
    _themeMode = value;
    notifyListeners();
    await _repository.saveThemeMode(value);
  }

  Future<void> restoreDemoNotes() async {
    _notes = _repository.mergeWithDemoNotes(_notes);
    sortNotes(_notes);
    _selectedNoteId ??= _notes.isEmpty ? null : _notes.first.id;
    notifyListeners();
    await _repository.saveNotes(_notes);
  }

  void setTabIndex(int value) {
    if (_tabIndex == value) {
      return;
    }
    _tabIndex = value;
    notifyListeners();
  }

  void setQuery(String value) {
    if (_query == value) {
      return;
    }
    _query = value;
    notifyListeners();
  }

  void selectNote(String? noteId) {
    if (_selectedNoteId == noteId) {
      return;
    }
    _selectedNoteId = noteId;
    notifyListeners();
  }

  Note? noteById(String? id) {
    if (id == null) {
      return null;
    }
    for (final Note note in _notes) {
      if (note.id == id) {
        return note;
      }
    }
    return null;
  }

  Note? findByTitle(String title) {
    final normalized = NoteParsers.normalizeTitle(title);
    for (final Note note in _notes) {
      if (NoteParsers.normalizeTitle(note.displayTitle) == normalized) {
        return note;
      }
    }
    return null;
  }

  List<Note> backlinksFor(Note note) {
    final normalized = NoteParsers.normalizeTitle(note.displayTitle);
    final matches = _notes.where((Note candidate) {
      if (candidate.id == note.id) {
        return false;
      }
      return candidate.linkTargets.any(
        (String target) => NoteParsers.normalizeTitle(target) == normalized,
      );
    }).toList();
    sortNotes(matches);
    return matches;
  }

  List<String> get allTags {
    final seen = <String>{};
    final tags = <String>[];
    for (final Note note in _notes) {
      for (final String tag in note.allTags) {
        final key = tag.toLowerCase();
        if (seen.add(key)) {
          tags.add(tag);
        }
      }
    }
    tags.sort((String a, String b) => a.toLowerCase().compareTo(b.toLowerCase()));
    return tags;
  }

  int get graphEdgeCount {
    var count = 0;
    for (final Note note in _notes) {
      for (final String target in note.linkTargets) {
        if (findByTitle(target) != null) {
          count += 1;
        }
      }
    }
    return count;
  }

  String exportVaultJson() {
    return _repository.exportVault(notes: _notes, themeMode: _themeMode);
  }

  void sortNotes(List<Note> notes) {
    notes.sort((Note a, Note b) {
      if (a.isPinned != b.isPinned) {
        return a.isPinned ? -1 : 1;
      }
      return b.updatedAt.compareTo(a.updatedAt);
    });
  }
}
