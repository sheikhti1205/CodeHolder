import 'package:flutter/material.dart';

import '../model/note_models.dart';

class MarkdownPreview extends StatelessWidget {
  const MarkdownPreview({
    super.key,
    required this.content,
  });

  final String content;

  @override
  Widget build(BuildContext context) {
    final lines = content.split('\n');
    if (lines.every((String line) => line.trim().isEmpty)) {
      return Text(
        'No content yet.',
        style: Theme.of(context).textTheme.bodyLarge,
      );
    }

    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: <Widget>[
        for (final String line in lines) ...<Widget>[
          _PreviewLine(text: line),
          const SizedBox(height: 8),
        ],
      ],
    );
  }
}

class _PreviewLine extends StatelessWidget {
  const _PreviewLine({required this.text});

  final String text;

  @override
  Widget build(BuildContext context) {
    final theme = Theme.of(context);
    final clean = NoteParsers.sanitizeInlineText(text.trim());

    if (clean.isEmpty) {
      return const SizedBox(height: 8);
    }

    if (text.startsWith('### ')) {
      return Text(
        NoteParsers.sanitizeInlineText(text.substring(4)),
        style: theme.textTheme.titleMedium,
      );
    }

    if (text.startsWith('## ')) {
      return Text(
        NoteParsers.sanitizeInlineText(text.substring(3)),
        style: theme.textTheme.titleLarge,
      );
    }

    if (text.startsWith('# ')) {
      return Text(
        NoteParsers.sanitizeInlineText(text.substring(2)),
        style: theme.textTheme.headlineSmall,
      );
    }

    if (text.startsWith('- [ ] ') || text.startsWith('- [x] ') || text.startsWith('- [X] ')) {
      final checked = text.startsWith('- [x] ') || text.startsWith('- [X] ');
      final body = NoteParsers.sanitizeInlineText(text.substring(6));
      return Row(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Padding(
            padding: const EdgeInsets.only(top: 1),
            child: Icon(
              checked ? Icons.check_box : Icons.check_box_outline_blank,
              size: 20,
              color: checked ? theme.colorScheme.primary : theme.colorScheme.onSurfaceVariant,
            ),
          ),
          const SizedBox(width: 10),
          Expanded(
            child: Text(
              body,
              style: theme.textTheme.bodyLarge?.copyWith(
                decoration: checked ? TextDecoration.lineThrough : null,
              ),
            ),
          ),
        ],
      );
    }

    if (text.startsWith('- ') || text.startsWith('* ')) {
      final body = NoteParsers.sanitizeInlineText(text.substring(2));
      return Row(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Padding(
            padding: const EdgeInsets.only(top: 8),
            child: Container(
              width: 6,
              height: 6,
              decoration: BoxDecoration(
                color: theme.colorScheme.primary,
                shape: BoxShape.circle,
              ),
            ),
          ),
          const SizedBox(width: 10),
          Expanded(child: Text(body, style: theme.textTheme.bodyLarge)),
        ],
      );
    }

    if (text.startsWith('> ')) {
      return Container(
        decoration: BoxDecoration(
          border: Border(
            left: BorderSide(color: theme.colorScheme.primary, width: 3),
          ),
          color: theme.colorScheme.surfaceContainerHighest.withOpacity(0.35),
        ),
        padding: const EdgeInsets.fromLTRB(12, 10, 12, 10),
        child: Text(
          NoteParsers.sanitizeInlineText(text.substring(2)),
          style: theme.textTheme.bodyLarge,
        ),
      );
    }

    return Text(clean, style: theme.textTheme.bodyLarge);
  }
}
