# LibreNotes Flutter

LibreNotes Flutter is a clean-room, cross-platform note-taking MVP inspired by the public feature set of privacy-first, local-first apps such as Bardo Notes. It does not reuse any proprietary branding, assets, or source code.

## Why Flutter

Flutter is a good fit for this project because it can ship one UI codebase across:

- Android
- iPhone
- web
- Windows
- macOS
- Linux

For a notes app, Flutter is not inherently slow. This app is mostly text, local persistence, list rendering, and lightweight custom drawing for a graph view, which are all well within Flutter's comfort zone.

## What this MVP includes

- Local-first storage with `shared_preferences`
- Search across title, content, and tags
- Pinned notes
- Wiki-style note links with `[[Note Title]]`
- Backlinks
- Markdown-ish preview for headings, bullets, quotes, and checklists
- Graph view for note relationships
- Light, dark, and system theme modes
- Vault export as pretty JSON with copy-to-clipboard
- Demo notes on first launch

## Important setup note

Flutter was not installed in this environment, so I wrote the app source and project metadata directly but could not run `flutter create` to generate the host runner folders.

After installing Flutter, generate platform runners from the project root:

```bash
flutter create . --platforms=android,ios,web,windows,macos,linux
flutter pub get
flutter run -d chrome
```

## Free cloud builds

If you want to avoid installing Flutter locally, this repo now includes a GitHub Actions workflow at `.github/workflows/librenotes_flutter_build.yml`.

What it does:

- installs Flutter on a GitHub-hosted runner
- generates the missing Android and web platform folders during CI
- runs `flutter test`
- builds a downloadable Android debug APK
- builds a downloadable web bundle

How to use it:

1. Push this repository to GitHub.
2. Open the repository's `Actions` tab.
3. Run `Build LibreNotes Flutter` or push changes under `LibreNotesFlutter`.
4. Open the finished workflow run and download the artifacts.

Free-tier note as of April 18, 2026:

- public repositories: standard GitHub-hosted runners are free
- private repositories on GitHub Free: 2,000 included minutes per month

## Main files

- `lib/main.dart`
- `lib/src/model/note_models.dart`
- `lib/src/data/vault_repository.dart`
- `lib/src/ui/app_controller.dart`
- `lib/src/ui/libre_notes_app.dart`
- `lib/src/widgets/markdown_preview.dart`
