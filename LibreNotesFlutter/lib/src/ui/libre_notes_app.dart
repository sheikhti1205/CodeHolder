import 'dart:math' as math;

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import '../model/note_models.dart';
import '../widgets/markdown_preview.dart';
import 'app_controller.dart';
import 'theme.dart';

class LibreNotesBootstrap extends StatefulWidget {
  const LibreNotesBootstrap({
    super.key,
    required this.controller,
  });

  final AppController controller;

  @override
  State<LibreNotesBootstrap> createState() => _LibreNotesBootstrapState();
}

class _LibreNotesBootstrapState extends State<LibreNotesBootstrap> {
  @override
  void initState() {
    super.initState();
    widget.controller.initialize();
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: widget.controller,
      builder: (BuildContext context, Widget? child) {
        return MaterialApp(
          debugShowCheckedModeBanner: false,
          title: 'LibreNotes',
          themeMode: resolveThemeMode(widget.controller.themeMode),
          theme: buildLightTheme(),
          darkTheme: buildDarkTheme(),
          home: widget.controller.isReady
              ? LibreNotesHome(controller: widget.controller)
              : const _LoadingScaffold(),
        );
      },
    );
  }
}

class LibreNotesHome extends StatefulWidget {
  const LibreNotesHome({
    super.key,
    required this.controller,
  });

  final AppController controller;

  @override
  State<LibreNotesHome> createState() => _LibreNotesHomeState();
}

class _LibreNotesHomeState extends State<LibreNotesHome> {
  late final TextEditingController _searchController;

  @override
  void initState() {
    super.initState();
    _searchController = TextEditingController(text: widget.controller.query);
  }

  @override
  void dispose() {
    _searchController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final controller = widget.controller;
    return AnimatedBuilder(
      animation: controller,
      builder: (BuildContext context, Widget? child) {
        final tabs = <Widget>[
          _NotesTab(
            controller: controller,
            searchController: _searchController,
            onCreate: _createNote,
            onOpenDetails: _openDetails,
            onEdit: _editNote,
            onDelete: _deleteNote,
          ),
          _GraphTab(
            controller: controller,
            onOpenDetails: _openDetails,
          ),
          _SettingsTab(
            controller: controller,
            onExportVault: _showExportDialog,
          ),
        ];

        return LayoutBuilder(
          builder: (BuildContext context, BoxConstraints constraints) {
            final wide = constraints.maxWidth >= 980;
            return Scaffold(
              appBar: AppBar(
                title: Text(_titleForTab(controller.tabIndex)),
                actions: <Widget>[
                  if (controller.tabIndex == 0 && controller.notes.isNotEmpty)
                    IconButton(
                      tooltip: 'New note',
                      onPressed: _createNote,
                      icon: const Icon(Icons.add),
                    ),
                ],
              ),
              body: wide
                  ? Row(
                      children: <Widget>[
                        NavigationRail(
                          selectedIndex: controller.tabIndex,
                          onDestinationSelected: controller.setTabIndex,
                          labelType: NavigationRailLabelType.all,
                          destinations: const <NavigationRailDestination>[
                            NavigationRailDestination(
                              icon: Icon(Icons.notes_outlined),
                              selectedIcon: Icon(Icons.notes),
                              label: Text('Notes'),
                            ),
                            NavigationRailDestination(
                              icon: Icon(Icons.hub_outlined),
                              selectedIcon: Icon(Icons.hub),
                              label: Text('Graph'),
                            ),
                            NavigationRailDestination(
                              icon: Icon(Icons.tune_outlined),
                              selectedIcon: Icon(Icons.tune),
                              label: Text('Settings'),
                            ),
                          ],
                        ),
                        const VerticalDivider(width: 1),
                        Expanded(child: tabs[controller.tabIndex]),
                      ],
                    )
                  : tabs[controller.tabIndex],
              bottomNavigationBar: wide
                  ? null
                  : NavigationBar(
                      selectedIndex: controller.tabIndex,
                      onDestinationSelected: controller.setTabIndex,
                      destinations: const <NavigationDestination>[
                        NavigationDestination(
                          icon: Icon(Icons.notes_outlined),
                          selectedIcon: Icon(Icons.notes),
                          label: 'Notes',
                        ),
                        NavigationDestination(
                          icon: Icon(Icons.hub_outlined),
                          selectedIcon: Icon(Icons.hub),
                          label: 'Graph',
                        ),
                        NavigationDestination(
                          icon: Icon(Icons.tune_outlined),
                          selectedIcon: Icon(Icons.tune),
                          label: 'Settings',
                        ),
                      ],
                    ),
              floatingActionButton: controller.tabIndex == 0
                  ? FloatingActionButton.extended(
                      onPressed: _createNote,
                      icon: const Icon(Icons.edit_note),
                      label: const Text('New note'),
                    )
                  : null,
            );
          },
        );
      },
    );
  }

  Future<void> _createNote() async {
    await Navigator.of(context).push<void>(
      MaterialPageRoute<void>(
        builder: (BuildContext context) => NoteEditorPage(
          controller: widget.controller,
        ),
      ),
    );
  }

  Future<void> _editNote(Note note) async {
    await Navigator.of(context).push<void>(
      MaterialPageRoute<void>(
        builder: (BuildContext context) => NoteEditorPage(
          controller: widget.controller,
          noteId: note.id,
        ),
      ),
    );
  }

  Future<void> _openDetails(Note note) async {
    widget.controller.selectNote(note.id);
    await Navigator.of(context).push<void>(
      MaterialPageRoute<void>(
        builder: (BuildContext context) => NoteDetailsPage(
          controller: widget.controller,
          noteId: note.id,
        ),
      ),
    );
  }

  Future<void> _deleteNote(Note note) async {
    final confirmed = await _confirmDelete(note);
    if (!mounted || !confirmed) {
      return;
    }
    await widget.controller.deleteNote(note);
    if (!mounted) {
      return;
    }
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text('Deleted "${note.displayTitle}".')),
    );
  }

  Future<bool> _confirmDelete(Note note) async {
    final result = await showDialog<bool>(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: const Text('Delete note?'),
          content: Text('This will remove "${note.displayTitle}" from your local vault.'),
          actions: <Widget>[
            TextButton(
              onPressed: () => Navigator.of(context).pop(false),
              child: const Text('Cancel'),
            ),
            FilledButton(
              onPressed: () => Navigator.of(context).pop(true),
              child: const Text('Delete'),
            ),
          ],
        );
      },
    );
    return result ?? false;
  }

  Future<void> _showExportDialog() async {
    final json = widget.controller.exportVaultJson();
    if (!mounted) {
      return;
    }
    await showDialog<void>(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: const Text('Export vault'),
          content: SizedBox(
            width: 720,
            child: SingleChildScrollView(
              child: SelectableText(json),
            ),
          ),
          actions: <Widget>[
            TextButton(
              onPressed: () => Navigator.of(context).pop(),
              child: const Text('Close'),
            ),
            FilledButton.icon(
              onPressed: () async {
                await Clipboard.setData(ClipboardData(text: json));
                if (!context.mounted) {
                  return;
                }
                Navigator.of(context).pop();
                ScaffoldMessenger.of(context).showSnackBar(
                  const SnackBar(content: Text('Vault JSON copied to clipboard.')),
                );
              },
              icon: const Icon(Icons.copy_all),
              label: const Text('Copy JSON'),
            ),
          ],
        );
      },
    );
  }
}

class _LoadingScaffold extends StatelessWidget {
  const _LoadingScaffold();

  @override
  Widget build(BuildContext context) {
    return const Scaffold(
      body: Center(
        child: CircularProgressIndicator(),
      ),
    );
  }
}

class _NotesTab extends StatelessWidget {
  const _NotesTab({
    required this.controller,
    required this.searchController,
    required this.onCreate,
    required this.onOpenDetails,
    required this.onEdit,
    required this.onDelete,
  });

  final AppController controller;
  final TextEditingController searchController;
  final VoidCallback onCreate;
  final ValueChanged<Note> onOpenDetails;
  final ValueChanged<Note> onEdit;
  final ValueChanged<Note> onDelete;

  @override
  Widget build(BuildContext context) {
    final notes = controller.filteredNotes;
    final wide = MediaQuery.sizeOf(context).width >= 1100;

    final listPane = _NoteListPane(
      controller: controller,
      searchController: searchController,
      notes: notes,
      onCreate: onCreate,
      onOpenDetails: onOpenDetails,
      onEdit: onEdit,
      onDelete: onDelete,
    );

    if (!wide) {
      return listPane;
    }

    return Row(
      children: <Widget>[
        SizedBox(
          width: 400,
          child: listPane,
        ),
        const VerticalDivider(width: 1),
        Expanded(
          child: controller.selectedNote == null
              ? const _EmptyDetailPane()
              : _NoteDetailPane(
                  controller: controller,
                  note: controller.selectedNote!,
                  onOpenDetails: onOpenDetails,
                  onEdit: onEdit,
                  onDelete: onDelete,
                  embedded: true,
                ),
        ),
      ],
    );
  }
}

class _NoteListPane extends StatelessWidget {
  const _NoteListPane({
    required this.controller,
    required this.searchController,
    required this.notes,
    required this.onCreate,
    required this.onOpenDetails,
    required this.onEdit,
    required this.onDelete,
  });

  final AppController controller;
  final TextEditingController searchController;
  final List<Note> notes;
  final VoidCallback onCreate;
  final ValueChanged<Note> onOpenDetails;
  final ValueChanged<Note> onEdit;
  final ValueChanged<Note> onDelete;

  @override
  Widget build(BuildContext context) {
    final selectedId = controller.selectedNote?.id;
    return Padding(
      padding: const EdgeInsets.all(20),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Text(
            'Local-first notes, no paywall required.',
            style: Theme.of(context).textTheme.titleMedium,
          ),
          const SizedBox(height: 6),
          Text(
            '${controller.notes.length} notes, ${controller.graphEdgeCount} links, ${controller.allTags.length} tags',
            style: Theme.of(context).textTheme.bodyMedium?.copyWith(
                  color: Theme.of(context).colorScheme.onSurfaceVariant,
                ),
          ),
          const SizedBox(height: 18),
          TextField(
            controller: searchController,
            onChanged: controller.setQuery,
            decoration: const InputDecoration(
              prefixIcon: Icon(Icons.search),
              hintText: 'Search notes, content, or tags',
            ),
          ),
          const SizedBox(height: 12),
          SingleChildScrollView(
            scrollDirection: Axis.horizontal,
            child: Wrap(
              spacing: 8,
              children: controller.allTags
                  .map(
                    (String tag) => ActionChip(
                      label: Text('#$tag'),
                      onPressed: () {
                        searchController.text = '#$tag';
                        searchController.selection = TextSelection.fromPosition(
                          TextPosition(offset: searchController.text.length),
                        );
                        controller.setQuery(searchController.text);
                      },
                    ),
                  )
                  .toList(),
            ),
          ),
          const SizedBox(height: 16),
          Expanded(
            child: notes.isEmpty
                ? _EmptyListState(onCreate: onCreate)
                : ListView.separated(
                    itemCount: notes.length,
                    separatorBuilder: (_, __) => const SizedBox(height: 12),
                    itemBuilder: (BuildContext context, int index) {
                      final note = notes[index];
                      return _NoteCard(
                        note: note,
                        selected: note.id == selectedId,
                        controller: controller,
                        onTap: () {
                          final wide = MediaQuery.sizeOf(context).width >= 1100;
                          controller.selectNote(note.id);
                          if (!wide) {
                            onOpenDetails(note);
                          }
                        },
                        onEdit: () => onEdit(note),
                        onDelete: () => onDelete(note),
                      );
                    },
                  ),
          ),
        ],
      ),
    );
  }
}

class _NoteCard extends StatelessWidget {
  const _NoteCard({
    required this.note,
    required this.selected,
    required this.controller,
    required this.onTap,
    required this.onEdit,
    required this.onDelete,
  });

  final Note note;
  final bool selected;
  final AppController controller;
  final VoidCallback onTap;
  final VoidCallback onEdit;
  final VoidCallback onDelete;

  @override
  Widget build(BuildContext context) {
    final theme = Theme.of(context);
    final backlinks = controller.backlinksFor(note).length;

    return Card(
      color: selected ? theme.colorScheme.primaryContainer : null,
      child: InkWell(
        onTap: onTap,
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              Row(
                children: <Widget>[
                  Expanded(
                    child: Text(
                      note.displayTitle,
                      style: theme.textTheme.titleMedium,
                    ),
                  ),
                  if (note.isPinned)
                    Padding(
                      padding: const EdgeInsets.only(right: 8),
                      child: Icon(
                        Icons.push_pin,
                        size: 18,
                        color: theme.colorScheme.primary,
                      ),
                    ),
                  PopupMenuButton<String>(
                    onSelected: (String value) async {
                      switch (value) {
                        case 'edit':
                          onEdit();
                          break;
                        case 'pin':
                          await controller.togglePinned(note);
                          break;
                        case 'delete':
                          onDelete();
                          break;
                      }
                    },
                    itemBuilder: (BuildContext context) {
                      return <PopupMenuEntry<String>>[
                        const PopupMenuItem<String>(
                          value: 'edit',
                          child: Text('Edit'),
                        ),
                        PopupMenuItem<String>(
                          value: 'pin',
                          child: Text(note.isPinned ? 'Unpin' : 'Pin'),
                        ),
                        const PopupMenuItem<String>(
                          value: 'delete',
                          child: Text('Delete'),
                        ),
                      ];
                    },
                  ),
                ],
              ),
              const SizedBox(height: 8),
              Text(
                note.excerpt,
                style: theme.textTheme.bodyMedium?.copyWith(
                  color: theme.colorScheme.onSurfaceVariant,
                ),
              ),
              const SizedBox(height: 12),
              Wrap(
                spacing: 8,
                runSpacing: 8,
                children: <Widget>[
                  ...note.allTags.map((String tag) => Chip(label: Text('#$tag'))),
                  Chip(
                    avatar: const Icon(Icons.link, size: 16),
                    label: Text('${note.linkTargets.length} links'),
                  ),
                  Chip(
                    avatar: const Icon(Icons.arrow_back, size: 16),
                    label: Text('$backlinks backlinks'),
                  ),
                ],
              ),
              const SizedBox(height: 10),
              Text(
                'Updated ${_formatTimestamp(note.updatedAt)}',
                style: theme.textTheme.labelMedium?.copyWith(
                  color: theme.colorScheme.onSurfaceVariant,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class NoteDetailsPage extends StatelessWidget {
  const NoteDetailsPage({
    super.key,
    required this.controller,
    required this.noteId,
  });

  final AppController controller;
  final String noteId;

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: controller,
      builder: (BuildContext context, Widget? child) {
        final note = controller.noteById(noteId);
        if (note == null) {
          return Scaffold(
            appBar: AppBar(),
            body: const Center(child: Text('This note no longer exists.')),
          );
        }
        return Scaffold(
          appBar: AppBar(
            title: Text(note.displayTitle),
            actions: <Widget>[
              IconButton(
                tooltip: 'Edit',
                onPressed: () {
                  Navigator.of(context).push<void>(
                    MaterialPageRoute<void>(
                      builder: (BuildContext context) => NoteEditorPage(
                        controller: controller,
                        noteId: note.id,
                      ),
                    ),
                  );
                },
                icon: const Icon(Icons.edit_outlined),
              ),
            ],
          ),
          body: _NoteDetailPane(
            controller: controller,
            note: note,
            onOpenDetails: (Note next) {
              Navigator.of(context).push<void>(
                MaterialPageRoute<void>(
                  builder: (BuildContext context) => NoteDetailsPage(
                    controller: controller,
                    noteId: next.id,
                  ),
                ),
              );
            },
            onEdit: (Note target) {
              Navigator.of(context).push<void>(
                MaterialPageRoute<void>(
                  builder: (BuildContext context) => NoteEditorPage(
                    controller: controller,
                    noteId: target.id,
                  ),
                ),
              );
            },
            onDelete: (Note target) async {
              final confirmed = await showDialog<bool>(
                context: context,
                builder: (BuildContext context) {
                  return AlertDialog(
                    title: const Text('Delete note?'),
                    content: Text('This will remove "${target.displayTitle}" from the vault.'),
                    actions: <Widget>[
                      TextButton(
                        onPressed: () => Navigator.of(context).pop(false),
                        child: const Text('Cancel'),
                      ),
                      FilledButton(
                        onPressed: () => Navigator.of(context).pop(true),
                        child: const Text('Delete'),
                      ),
                    ],
                  );
                },
              );
              if (confirmed != true || !context.mounted) {
                return;
              }
              await controller.deleteNote(target);
              if (!context.mounted) {
                return;
              }
              Navigator.of(context).pop();
            },
            embedded: false,
          ),
        );
      },
    );
  }
}

class _NoteDetailPane extends StatelessWidget {
  const _NoteDetailPane({
    required this.controller,
    required this.note,
    required this.onOpenDetails,
    required this.onEdit,
    required this.onDelete,
    required this.embedded,
  });

  final AppController controller;
  final Note note;
  final ValueChanged<Note> onOpenDetails;
  final ValueChanged<Note> onEdit;
  final ValueChanged<Note> onDelete;
  final bool embedded;

  @override
  Widget build(BuildContext context) {
    final outgoing = note.linkTargets;
    final backlinks = controller.backlinksFor(note);

    return SingleChildScrollView(
      padding: const EdgeInsets.all(24),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Row(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: <Widget>[
                    Text(
                      note.displayTitle,
                      style: Theme.of(context).textTheme.headlineMedium,
                    ),
                    const SizedBox(height: 8),
                    Text(
                      'Updated ${_formatTimestamp(note.updatedAt)}',
                      style: Theme.of(context).textTheme.bodyMedium?.copyWith(
                            color: Theme.of(context).colorScheme.onSurfaceVariant,
                          ),
                    ),
                  ],
                ),
              ),
              if (note.isPinned)
                Padding(
                  padding: const EdgeInsets.only(right: 8),
                  child: Chip(
                    avatar: const Icon(Icons.push_pin, size: 16),
                    label: const Text('Pinned'),
                  ),
                ),
              FilledButton.tonalIcon(
                onPressed: () => onEdit(note),
                icon: const Icon(Icons.edit_outlined),
                label: const Text('Edit'),
              ),
              const SizedBox(width: 8),
              IconButton(
                tooltip: 'Delete',
                onPressed: () => onDelete(note),
                icon: const Icon(Icons.delete_outline),
              ),
            ],
          ),
          if (note.allTags.isNotEmpty) ...<Widget>[
            const SizedBox(height: 16),
            Wrap(
              spacing: 8,
              runSpacing: 8,
              children: note.allTags.map((String tag) => Chip(label: Text('#$tag'))).toList(),
            ),
          ],
          const SizedBox(height: 24),
          _InfoSection(
            title: 'Preview',
            child: MarkdownPreview(content: note.content),
          ),
          const SizedBox(height: 20),
          _InfoSection(
            title: 'Outgoing links',
            child: outgoing.isEmpty
                ? const Text('No links yet. Use [[Note Title]] inside the editor to connect notes.')
                : Wrap(
                    spacing: 8,
                    runSpacing: 8,
                    children: outgoing.map((String target) {
                      final linked = controller.findByTitle(target);
                      return ActionChip(
                        avatar: Icon(
                          linked == null ? Icons.add_link : Icons.open_in_new,
                          size: 16,
                        ),
                        label: Text(target),
                        onPressed: () {
                          if (linked != null) {
                            controller.selectNote(linked.id);
                            if (!embedded) {
                              onOpenDetails(linked);
                            }
                          } else {
                            Navigator.of(context).push<void>(
                              MaterialPageRoute<void>(
                                builder: (BuildContext context) => NoteEditorPage(
                                  controller: controller,
                                  initialTitle: target,
                                ),
                              ),
                            );
                          }
                        },
                      );
                    }).toList(),
                  ),
          ),
          const SizedBox(height: 20),
          _InfoSection(
            title: 'Backlinks',
            child: backlinks.isEmpty
                ? const Text('No notes link back here yet.')
                : Wrap(
                    spacing: 8,
                    runSpacing: 8,
                    children: backlinks.map((Note backlink) {
                      return ActionChip(
                        avatar: const Icon(Icons.arrow_back, size: 16),
                        label: Text(backlink.displayTitle),
                        onPressed: () {
                          controller.selectNote(backlink.id);
                          if (!embedded) {
                            onOpenDetails(backlink);
                          }
                        },
                      );
                    }).toList(),
                  ),
          ),
          const SizedBox(height: 20),
          FilledButton.tonalIcon(
            onPressed: () async {
              final markdown = '# ${note.displayTitle}\n\n${note.content}';
              await Clipboard.setData(ClipboardData(text: markdown));
              if (!context.mounted) {
                return;
              }
              ScaffoldMessenger.of(context).showSnackBar(
                const SnackBar(content: Text('Note copied to clipboard.')),
              );
            },
            icon: const Icon(Icons.copy_outlined),
            label: const Text('Copy note'),
          ),
        ],
      ),
    );
  }
}

class NoteEditorPage extends StatefulWidget {
  const NoteEditorPage({
    super.key,
    required this.controller,
    this.noteId,
    this.initialTitle,
  });

  final AppController controller;
  final String? noteId;
  final String? initialTitle;

  @override
  State<NoteEditorPage> createState() => _NoteEditorPageState();
}

class _NoteEditorPageState extends State<NoteEditorPage> {
  late final TextEditingController _titleController;
  late final TextEditingController _tagsController;
  late final TextEditingController _contentController;
  late bool _isPinned;
  bool _previewMode = false;

  Note? get _existingNote => widget.noteId == null ? null : widget.controller.noteById(widget.noteId);

  @override
  void initState() {
    super.initState();
    final draft = _existingNote?.toDraft() ?? NoteDraft(title: widget.initialTitle ?? '');
    _titleController = TextEditingController(text: draft.title);
    _tagsController = TextEditingController(text: draft.tagsText);
    _contentController = TextEditingController(text: draft.content);
    _isPinned = draft.isPinned;
  }

  @override
  void dispose() {
    _titleController.dispose();
    _tagsController.dispose();
    _contentController.dispose();
    super.dispose();
  }

  Note get _previewNote {
    return NoteDraft(
      noteId: widget.noteId,
      title: _titleController.text,
      content: _contentController.text,
      tagsText: _tagsController.text,
      isPinned: _isPinned,
      createdAt: _existingNote?.createdAt,
    ).toNote(existing: _existingNote);
  }

  @override
  Widget build(BuildContext context) {
    final isEditing = _existingNote != null;
    return Scaffold(
      appBar: AppBar(
        title: Text(isEditing ? 'Edit note' : 'New note'),
        actions: <Widget>[
          TextButton(
            onPressed: _save,
            child: const Text('Save'),
          ),
        ],
      ),
      body: ListView(
        padding: const EdgeInsets.all(20),
        children: <Widget>[
          Wrap(
            spacing: 8,
            children: <Widget>[
              ChoiceChip(
                label: const Text('Write'),
                selected: !_previewMode,
                onSelected: (_) => setState(() => _previewMode = false),
              ),
              ChoiceChip(
                label: const Text('Preview'),
                selected: _previewMode,
                onSelected: (_) => setState(() => _previewMode = true),
              ),
            ],
          ),
          const SizedBox(height: 18),
          if (!_previewMode) ...<Widget>[
            TextField(
              controller: _titleController,
              textInputAction: TextInputAction.next,
              decoration: const InputDecoration(
                labelText: 'Title',
                hintText: 'Untitled note',
              ),
            ),
            const SizedBox(height: 16),
            TextField(
              controller: _tagsController,
              textInputAction: TextInputAction.next,
              decoration: const InputDecoration(
                labelText: 'Tags',
                hintText: 'research, journal, project',
              ),
            ),
            const SizedBox(height: 16),
            SwitchListTile.adaptive(
              contentPadding: EdgeInsets.zero,
              title: const Text('Pin this note'),
              value: _isPinned,
              onChanged: (bool value) => setState(() => _isPinned = value),
            ),
            const SizedBox(height: 8),
            TextField(
              controller: _contentController,
              maxLines: 20,
              minLines: 16,
              decoration: const InputDecoration(
                alignLabelWithHint: true,
                labelText: 'Content',
                hintText: 'Use [[Note Title]] to create links between notes.',
              ),
            ),
          ] else ...<Widget>[
            Text(
              _previewNote.displayTitle,
              style: Theme.of(context).textTheme.headlineSmall,
            ),
            const SizedBox(height: 8),
            if (_previewNote.allTags.isNotEmpty)
              Wrap(
                spacing: 8,
                runSpacing: 8,
                children: _previewNote.allTags.map((String tag) => Chip(label: Text('#$tag'))).toList(),
              ),
            const SizedBox(height: 18),
            MarkdownPreview(content: _previewNote.content),
            const SizedBox(height: 20),
            Text(
              'Detected links',
              style: Theme.of(context).textTheme.titleMedium,
            ),
            const SizedBox(height: 10),
            Wrap(
              spacing: 8,
              runSpacing: 8,
              children: _previewNote.linkTargets.isEmpty
                  ? <Widget>[const Chip(label: Text('No links yet'))]
                  : _previewNote.linkTargets.map((String item) => Chip(label: Text(item))).toList(),
            ),
          ],
        ],
      ),
    );
  }

  Future<void> _save() async {
    final draft = NoteDraft(
      noteId: widget.noteId,
      title: _titleController.text,
      content: _contentController.text,
      tagsText: _tagsController.text,
      isPinned: _isPinned,
      createdAt: _existingNote?.createdAt,
    );
    await widget.controller.saveDraft(draft);
    if (!mounted) {
      return;
    }
    Navigator.of(context).pop();
  }
}

class _GraphTab extends StatelessWidget {
  const _GraphTab({
    required this.controller,
    required this.onOpenDetails,
  });

  final AppController controller;
  final ValueChanged<Note> onOpenDetails;

  @override
  Widget build(BuildContext context) {
    final selected = controller.selectedNote;
    return ListView(
      padding: const EdgeInsets.all(20),
      children: <Widget>[
        Text(
          'A lightweight local graph of note relationships.',
          style: Theme.of(context).textTheme.titleMedium,
        ),
        const SizedBox(height: 6),
        Text(
          '${controller.notes.length} nodes and ${controller.graphEdgeCount} edges',
          style: Theme.of(context).textTheme.bodyMedium?.copyWith(
                color: Theme.of(context).colorScheme.onSurfaceVariant,
              ),
        ),
        const SizedBox(height: 20),
        _GraphCanvas(
          controller: controller,
          onSelect: (Note note) {
            controller.selectNote(note.id);
          },
        ),
        const SizedBox(height: 20),
        if (selected != null)
          Card(
            child: Padding(
              padding: const EdgeInsets.all(16),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: <Widget>[
                  Text(selected.displayTitle, style: Theme.of(context).textTheme.titleLarge),
                  const SizedBox(height: 8),
                  Text(selected.excerpt),
                  const SizedBox(height: 12),
                  Wrap(
                    spacing: 8,
                    runSpacing: 8,
                    children: <Widget>[
                      Chip(
                        avatar: const Icon(Icons.link, size: 16),
                        label: Text('${selected.linkTargets.length} outgoing'),
                      ),
                      Chip(
                        avatar: const Icon(Icons.arrow_back, size: 16),
                        label: Text('${controller.backlinksFor(selected).length} backlinks'),
                      ),
                    ],
                  ),
                  const SizedBox(height: 14),
                  FilledButton.tonalIcon(
                    onPressed: () => onOpenDetails(selected),
                    icon: const Icon(Icons.open_in_new),
                    label: const Text('Open note'),
                  ),
                ],
              ),
            ),
          ),
      ],
    );
  }
}

class _GraphCanvas extends StatelessWidget {
  const _GraphCanvas({
    required this.controller,
    required this.onSelect,
  });

  final AppController controller;
  final ValueChanged<Note> onSelect;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 420,
      child: LayoutBuilder(
        builder: (BuildContext context, BoxConstraints constraints) {
          final size = Size(constraints.maxWidth, 420);
          final layout = _buildGraphLayout(controller.notes, controller, size);

          return Card(
            child: ClipRect(
              child: Stack(
                children: <Widget>[
                  Positioned.fill(
                    child: CustomPaint(
                      painter: _GraphPainter(
                        layout: layout,
                        selectedId: controller.selectedNote?.id,
                        colorScheme: Theme.of(context).colorScheme,
                      ),
                    ),
                  ),
                  ...layout.map((GraphNodeLayout node) {
                    final width = math.max(84.0, math.min(150.0, size.width * 0.22)).toDouble();
                    final left = node.position.dx - (width / 2);
                    final top = node.position.dy - 20;
                    final isSelected = controller.selectedNote?.id == node.note.id;
                    return Positioned(
                      left: left.clamp(8.0, math.max(8.0, size.width - width - 8)).toDouble(),
                      top: top.clamp(8.0, 420 - 40).toDouble(),
                      width: width,
                      child: Material(
                        color: isSelected
                            ? Theme.of(context).colorScheme.primaryContainer
                            : Theme.of(context).colorScheme.surface,
                        elevation: isSelected ? 3 : 1,
                        borderRadius: BorderRadius.circular(18),
                        child: InkWell(
                          borderRadius: BorderRadius.circular(18),
                          onTap: () => onSelect(node.note),
                          child: Padding(
                            padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 10),
                            child: Text(
                              node.note.displayTitle,
                              maxLines: 2,
                              overflow: TextOverflow.ellipsis,
                              style: Theme.of(context).textTheme.labelLarge,
                              textAlign: TextAlign.center,
                            ),
                          ),
                        ),
                      ),
                    );
                  }),
                ],
              ),
            ),
          );
        },
      ),
    );
  }
}

class _SettingsTab extends StatelessWidget {
  const _SettingsTab({
    required this.controller,
    required this.onExportVault,
  });

  final AppController controller;
  final Future<void> Function() onExportVault;

  @override
  Widget build(BuildContext context) {
    return ListView(
      padding: const EdgeInsets.all(20),
      children: <Widget>[
        Text(
          'Everything here stays local unless you explicitly export it.',
          style: Theme.of(context).textTheme.titleMedium,
        ),
        const SizedBox(height: 20),
        Card(
          child: Padding(
            padding: const EdgeInsets.all(16),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                Text('Theme', style: Theme.of(context).textTheme.titleMedium),
                const SizedBox(height: 12),
                RadioListTile<ThemeModePreference>(
                  contentPadding: EdgeInsets.zero,
                  value: ThemeModePreference.system,
                  groupValue: controller.themeMode,
                  onChanged: (ThemeModePreference? value) {
                    if (value != null) {
                      controller.setThemeMode(value);
                    }
                  },
                  title: const Text('System'),
                ),
                RadioListTile<ThemeModePreference>(
                  contentPadding: EdgeInsets.zero,
                  value: ThemeModePreference.light,
                  groupValue: controller.themeMode,
                  onChanged: (ThemeModePreference? value) {
                    if (value != null) {
                      controller.setThemeMode(value);
                    }
                  },
                  title: const Text('Light'),
                ),
                RadioListTile<ThemeModePreference>(
                  contentPadding: EdgeInsets.zero,
                  value: ThemeModePreference.dark,
                  groupValue: controller.themeMode,
                  onChanged: (ThemeModePreference? value) {
                    if (value != null) {
                      controller.setThemeMode(value);
                    }
                  },
                  title: const Text('Dark'),
                ),
              ],
            ),
          ),
        ),
        const SizedBox(height: 16),
        Card(
          child: Padding(
            padding: const EdgeInsets.all(16),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                Text('Vault stats', style: Theme.of(context).textTheme.titleMedium),
                const SizedBox(height: 12),
                Wrap(
                  spacing: 8,
                  runSpacing: 8,
                  children: <Widget>[
                    Chip(label: Text('${controller.notes.length} notes')),
                    Chip(label: Text('${controller.graphEdgeCount} graph edges')),
                    Chip(label: Text('${controller.allTags.length} unique tags')),
                  ],
                ),
              ],
            ),
          ),
        ),
        const SizedBox(height: 16),
        Card(
          child: Padding(
            padding: const EdgeInsets.all(16),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                Text('Actions', style: Theme.of(context).textTheme.titleMedium),
                const SizedBox(height: 12),
                FilledButton.tonalIcon(
                  onPressed: onExportVault,
                  icon: const Icon(Icons.download_outlined),
                  label: const Text('Export vault JSON'),
                ),
                const SizedBox(height: 12),
                FilledButton.tonalIcon(
                  onPressed: () async {
                    await controller.restoreDemoNotes();
                    if (!context.mounted) {
                      return;
                    }
                    ScaffoldMessenger.of(context).showSnackBar(
                      const SnackBar(content: Text('Demo notes merged into the vault.')),
                    );
                  },
                  icon: const Icon(Icons.auto_awesome),
                  label: const Text('Restore demo notes'),
                ),
              ],
            ),
          ),
        ),
      ],
    );
  }
}

class _InfoSection extends StatelessWidget {
  const _InfoSection({
    required this.title,
    required this.child,
  });

  final String title;
  final Widget child;

  @override
  Widget build(BuildContext context) {
    return Card(
      child: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: <Widget>[
            Text(title, style: Theme.of(context).textTheme.titleLarge),
            const SizedBox(height: 14),
            child,
          ],
        ),
      ),
    );
  }
}

class _EmptyListState extends StatelessWidget {
  const _EmptyListState({
    required this.onCreate,
  });

  final VoidCallback onCreate;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: <Widget>[
          const Icon(Icons.menu_book_outlined, size: 48),
          const SizedBox(height: 12),
          Text(
            'No notes match this search.',
            style: Theme.of(context).textTheme.titleMedium,
          ),
          const SizedBox(height: 10),
          FilledButton.icon(
            onPressed: onCreate,
            icon: const Icon(Icons.add),
            label: const Text('Create note'),
          ),
        ],
      ),
    );
  }
}

class _EmptyDetailPane extends StatelessWidget {
  const _EmptyDetailPane();

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: <Widget>[
          const Icon(Icons.notes_outlined, size: 48),
          const SizedBox(height: 12),
          Text(
            'Pick a note to preview it here.',
            style: Theme.of(context).textTheme.titleMedium,
          ),
        ],
      ),
    );
  }
}

String _titleForTab(int index) {
  switch (index) {
    case 0:
      return 'LibreNotes';
    case 1:
      return 'Graph';
    case 2:
      return 'Settings';
    default:
      return 'LibreNotes';
  }
}

String _formatTimestamp(DateTime value) {
  final now = DateTime.now();
  final difference = now.difference(value);
  if (difference.inMinutes < 1) {
    return 'just now';
  }
  if (difference.inHours < 1) {
    return '${difference.inMinutes}m ago';
  }
  if (difference.inDays < 1) {
    return '${difference.inHours}h ago';
  }
  if (difference.inDays < 7) {
    return '${difference.inDays}d ago';
  }
  return '${value.year}-${value.month.toString().padLeft(2, '0')}-${value.day.toString().padLeft(2, '0')}';
}

List<GraphNodeLayout> _buildGraphLayout(List<Note> notes, AppController controller, Size size) {
  if (notes.isEmpty) {
    return <GraphNodeLayout>[];
  }

  final center = Offset(size.width / 2, size.height / 2);
  final result = <GraphNodeLayout>[];
  final count = notes.length;

  for (var index = 0; index < count; index += 1) {
    final note = notes[index];
    final angle = (math.pi * 2 * index) / math.max(1, count).toDouble();
    final ring = (index % 3) * 44;
    final radius = math.min(size.width, size.height).toDouble() * 0.24 + ring.toDouble();
    final position = Offset(
      center.dx + math.cos(angle) * radius,
      center.dy + math.sin(angle) * radius,
    );
    final weight = note.linkTargets.length + controller.backlinksFor(note).length + (note.isPinned ? 1 : 0);
    result.add(
      GraphNodeLayout(
        note: note,
        position: position,
        weight: weight,
      ),
    );
  }

  return result;
}

class GraphNodeLayout {
  const GraphNodeLayout({
    required this.note,
    required this.position,
    required this.weight,
  });

  final Note note;
  final Offset position;
  final int weight;
}

class _GraphPainter extends CustomPainter {
  _GraphPainter({
    required this.layout,
    required this.selectedId,
    required this.colorScheme,
  });

  final List<GraphNodeLayout> layout;
  final String? selectedId;
  final ColorScheme colorScheme;

  @override
  void paint(Canvas canvas, Size size) {
    final titleIndex = <String, GraphNodeLayout>{
      for (final GraphNodeLayout node in layout) NoteParsers.normalizeTitle(node.note.displayTitle): node,
    };

    final edgePaint = Paint()
      ..color = colorScheme.outlineVariant
      ..strokeWidth = 1.4
      ..style = PaintingStyle.stroke;

    for (final GraphNodeLayout node in layout) {
      for (final String target in node.note.linkTargets) {
        final targetNode = titleIndex[NoteParsers.normalizeTitle(target)];
        if (targetNode == null) {
          continue;
        }
        canvas.drawLine(node.position, targetNode.position, edgePaint);
      }
    }

    final glowPaint = Paint()
      ..color = colorScheme.primary.withOpacity(0.16)
      ..style = PaintingStyle.fill;
    final dotPaint = Paint()
      ..color = colorScheme.primary
      ..style = PaintingStyle.fill;

    for (final GraphNodeLayout node in layout) {
      final selected = node.note.id == selectedId;
      final dotRadius = 4.0 + math.min(10.0, node.weight.toDouble()).toDouble();
      if (selected) {
        canvas.drawCircle(node.position, dotRadius + 12, glowPaint);
      }
      canvas.drawCircle(node.position, dotRadius, dotPaint);
    }
  }

  @override
  bool shouldRepaint(covariant _GraphPainter oldDelegate) {
    return oldDelegate.layout != layout || oldDelegate.selectedId != selectedId;
  }
}
