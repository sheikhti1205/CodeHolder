import 'dart:convert';

import 'package:shared_preferences/shared_preferences.dart';

import '../model/note_models.dart';

class VaultRepository {
  static const String _notesKey = 'libre_notes.notes';
  static const String _themeKey = 'libre_notes.theme_mode';

  Future<VaultSnapshot> loadSnapshot() async {
    final prefs = await SharedPreferences.getInstance();
    final rawNotes = prefs.getString(_notesKey);
    final rawTheme = prefs.getString(_themeKey);

    List<Note> notes;
    if (rawNotes == null || rawNotes.trim().isEmpty) {
      notes = seedNotes();
      await saveNotes(notes);
    } else {
      try {
        final decoded = jsonDecode(rawNotes) as List<dynamic>;
        notes = decoded
            .map((dynamic item) => Note.fromJson(item as Map<String, dynamic>))
            .toList();
      } catch (_) {
        notes = seedNotes();
        await saveNotes(notes);
      }
    }

    final themeMode = _readThemeMode(rawTheme);
    return VaultSnapshot(notes: notes, themeMode: themeMode);
  }

  Future<void> saveNotes(List<Note> notes) async {
    final prefs = await SharedPreferences.getInstance();
    final encoded = jsonEncode(
      notes.map((Note note) => note.toJson()).toList(),
    );
    await prefs.setString(_notesKey, encoded);
  }

  Future<void> saveThemeMode(ThemeModePreference themeMode) async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setString(_themeKey, themeMode.name);
  }

  String exportVault({
    required List<Note> notes,
    required ThemeModePreference themeMode,
  }) {
    final payload = <String, dynamic>{
      'app': 'LibreNotes Flutter',
      'exportedAt': DateTime.now().toIso8601String(),
      'themeMode': themeMode.name,
      'notes': notes.map((Note note) => note.toJson()).toList(),
    };
    return const JsonEncoder.withIndent('  ').convert(payload);
  }

  List<Note> mergeWithDemoNotes(List<Note> existing) {
    final byTitle = <String, Note>{
      for (final Note note in seedNotes()) NoteParsers.normalizeTitle(note.displayTitle): note,
      for (final Note note in existing) NoteParsers.normalizeTitle(note.displayTitle): note,
    };
    return byTitle.values.toList();
  }

  ThemeModePreference _readThemeMode(String? rawTheme) {
    return ThemeModePreference.values.firstWhere(
      (ThemeModePreference item) => item.name == rawTheme,
      orElse: () => ThemeModePreference.system,
    );
  }

  List<Note> seedNotes() {
    final focus = Note.create(
      title: 'Focus ritual',
      content: '''
# Focus ritual

- [ ] Start a 25 minute session
- [ ] Put the phone away
- [ ] Open [[Daily desk]]

> Keep the capture surface calm and local.

#deep-work
''',
      tags: const <String>['routine', 'focus'],
      isPinned: true,
    );

    final dailyDesk = Note.create(
      title: 'Daily desk',
      content: '''
# Daily desk

Today's scratchpad lives here.

Link out to [[Project map]] when an idea becomes real.
Check in with [[Focus ritual]] before writing.

## Prompts
- What matters today?
- What can wait?
- Which note should become a permanent note?

#today
''',
      tags: const <String>['daily', 'journal'],
    );

    final projectMap = Note.create(
      title: 'Project map',
      content: '''
# Project map

## Current tracks
- Cross-platform notes
- Offline search
- Graph view

Related notes:
- [[Daily desk]]
- [[Idea nursery]]

#planning
''',
      tags: const <String>['planning', 'roadmap'],
    );

    final ideaNursery = Note.create(
      title: 'Idea nursery',
      content: '''
# Idea nursery

Small ideas that do not deserve a full project yet.

- Ambient focus sounds
- On-device lock screen
- Export bundles for [[Project map]]

#ideas
''',
      tags: const <String>['ideas'],
    );

    return <Note>[focus, dailyDesk, projectMap, ideaNursery];
  }
}
