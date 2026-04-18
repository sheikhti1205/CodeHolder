import 'dart:convert';

enum ThemeModePreference {
  system,
  light,
  dark,
}

class VaultSnapshot {
  const VaultSnapshot({
    required this.notes,
    required this.themeMode,
  });

  final List<Note> notes;
  final ThemeModePreference themeMode;
}

class Note {
  Note({
    required this.id,
    required this.title,
    required this.content,
    required this.tags,
    required this.isPinned,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Note.create({
    required String title,
    required String content,
    List<String> tags = const <String>[],
    bool isPinned = false,
    String? id,
    DateTime? createdAt,
    DateTime? updatedAt,
  }) {
    final created = createdAt ?? DateTime.now();
    return Note(
      id: id ?? _nextId(),
      title: title,
      content: content,
      tags: tags.normalizedDistinct(),
      isPinned: isPinned,
      createdAt: created,
      updatedAt: updatedAt ?? created,
    );
  }

  factory Note.fromJson(Map<String, dynamic> json) {
    final now = DateTime.now();
    final tags = (json['tags'] as List<dynamic>? ?? const <dynamic>[])
        .map((dynamic item) => item.toString())
        .toList();

    return Note(
      id: json['id']?.toString() ?? _nextId(),
      title: json['title']?.toString() ?? 'Untitled note',
      content: json['content']?.toString() ?? '',
      tags: tags.normalizedDistinct(),
      isPinned: json['isPinned'] == true,
      createdAt: DateTime.fromMillisecondsSinceEpoch(
        (json['createdAt'] as num?)?.toInt() ?? now.millisecondsSinceEpoch,
      ),
      updatedAt: DateTime.fromMillisecondsSinceEpoch(
        (json['updatedAt'] as num?)?.toInt() ?? now.millisecondsSinceEpoch,
      ),
    );
  }

  final String id;
  final String title;
  final String content;
  final List<String> tags;
  final bool isPinned;
  final DateTime createdAt;
  final DateTime updatedAt;

  String get displayTitle => title.trim().isEmpty ? NoteParsers.inferTitle(content) : title.trim();

  List<String> get allTags => <String>[...tags, ...NoteParsers.extractInlineTags(content)].normalizedDistinct();

  List<String> get linkTargets => NoteParsers.extractLinks(content);

  String get excerpt {
    final compact = content.replaceAll(RegExp(r'\s+'), ' ').trim();
    if (compact.isEmpty) {
      return 'Tap to start writing.';
    }
    if (compact.length <= 160) {
      return compact;
    }
    return '${compact.substring(0, 160).trimRight()}...';
  }

  Note copyWith({
    String? id,
    String? title,
    String? content,
    List<String>? tags,
    bool? isPinned,
    DateTime? createdAt,
    DateTime? updatedAt,
  }) {
    return Note(
      id: id ?? this.id,
      title: title ?? this.title,
      content: content ?? this.content,
      tags: tags ?? this.tags,
      isPinned: isPinned ?? this.isPinned,
      createdAt: createdAt ?? this.createdAt,
      updatedAt: updatedAt ?? this.updatedAt,
    );
  }

  Map<String, dynamic> toJson() {
    return <String, dynamic>{
      'id': id,
      'title': title,
      'content': content,
      'tags': tags,
      'isPinned': isPinned,
      'createdAt': createdAt.millisecondsSinceEpoch,
      'updatedAt': updatedAt.millisecondsSinceEpoch,
    };
  }
}

class NoteDraft {
  const NoteDraft({
    this.noteId,
    this.title = '',
    this.content = '',
    this.tagsText = '',
    this.isPinned = false,
    this.createdAt,
  });

  final String? noteId;
  final String title;
  final String content;
  final String tagsText;
  final bool isPinned;
  final DateTime? createdAt;

  Note toNote({Note? existing}) {
    final now = DateTime.now();
    final tags = tagsText
        .split(RegExp(r'[,\n]'))
        .map((String part) => part.trim().replaceFirst(RegExp(r'^#'), ''))
        .where((String part) => part.isNotEmpty)
        .toList()
        .normalizedDistinct();

    return Note.create(
      id: existing?.id ?? noteId,
      title: title.trim().isEmpty ? NoteParsers.inferTitle(content) : title.trim(),
      content: content.trimRight(),
      tags: tags,
      isPinned: isPinned,
      createdAt: existing?.createdAt ?? createdAt,
      updatedAt: now,
    );
  }
}

extension NoteDraftX on Note {
  NoteDraft toDraft() {
    return NoteDraft(
      noteId: id,
      title: title,
      content: content,
      tagsText: tags.join(', '),
      isPinned: isPinned,
      createdAt: createdAt,
    );
  }
}

class NoteParsers {
  static final RegExp _linkRegex = RegExp(r'\[\[([^\]]+)]]');
  static final RegExp _tagRegex = RegExp(r'(^|[^\w])#([A-Za-z0-9_-]+)', multiLine: true);

  static List<String> extractLinks(String content) {
    return _linkRegex
        .allMatches(content)
        .map((Match match) => match.group(1)?.trim() ?? '')
        .where((String value) => value.isNotEmpty)
        .toList()
        .normalizedDistinct();
  }

  static List<String> extractInlineTags(String content) {
    return _tagRegex
        .allMatches(content)
        .map((Match match) => match.group(2)?.trim() ?? '')
        .where((String value) => value.isNotEmpty)
        .toList()
        .normalizedDistinct();
  }

  static String inferTitle(String content) {
    for (final String line in const LineSplitter().convert(content)) {
      final trimmed = line.trim();
      if (trimmed.isEmpty) {
        continue;
      }
      final clean = trimmed.startsWith('#') ? trimmed.replaceFirst(RegExp(r'^#+\s*'), '') : trimmed;
      if (clean.length <= 48) {
        return clean;
      }
      return '${clean.substring(0, 48).trimRight()}...';
    }
    return 'Untitled note';
  }

  static String normalizeTitle(String value) {
    return value.trim().toLowerCase();
  }

  static String sanitizeInlineText(String value) {
    return value
        .replaceAll('[[', '')
        .replaceAll(']]', '')
        .replaceAll('**', '')
        .replaceAll('*', '')
        .replaceAll('`', '');
  }
}

extension _NormalizedStrings on Iterable<String> {
  List<String> normalizedDistinct() {
    final seen = <String>{};
    final result = <String>[];
    for (final String item in this) {
      final cleaned = item.trim();
      if (cleaned.isEmpty) {
        continue;
      }
      final key = cleaned.toLowerCase();
      if (seen.add(key)) {
        result.add(cleaned);
      }
    }
    return result;
  }
}

String _nextId() {
  return DateTime.now().microsecondsSinceEpoch.toString();
}
