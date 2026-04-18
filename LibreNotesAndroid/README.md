# LibreNotes Android

LibreNotes is a clean-room Android MVP inspired by the public feature set of privacy-first, local-first note apps such as Bardo Notes. It does not copy any branding, assets, or proprietary code. Everything in this project is meant to stay on-device and work offline.

## What is already built

- Local-first notes saved as JSON in the app's private storage
- Search across title, content, and tags
- Pinned notes
- Markdown-ish preview for headings, lists, checklists, quotes, and inline emphasis
- Wiki-style note linking with `[[Note Title]]`
- Backlink detection
- Graph view for note connections
- Theme switching: system, light, and dark
- Share/export for a single note or the full vault as JSON text
- Seed/demo notes so the graph view is understandable on first launch

## Stack

- Kotlin
- Jetpack Compose
- Single-activity architecture
- No login
- No cloud sync
- No ads
- No subscriptions

## Project Layout

- `app/src/main/java/com/sheikcodes/librenotes/MainActivity.kt`: app entry point
- `app/src/main/java/com/sheikcodes/librenotes/ui/LibreNotesApp.kt`: all screens and interaction flow
- `app/src/main/java/com/sheikcodes/librenotes/data/LocalVaultRepository.kt`: local JSON storage
- `app/src/main/java/com/sheikcodes/librenotes/model/NoteModels.kt`: notes, drafts, parsing helpers

## Notes on Scope

This is an MVP, not a full clone. I focused on the parts that make the experience feel useful immediately without relying on paid APIs or cloud services. OCR, offline speech-to-text, encryption-at-rest, and advanced canvas editing can be layered in later.

## How to Run

1. Open `LibreNotesAndroid` in Android Studio on Windows.
2. Let Gradle sync.
3. Install the Android SDK for API 36 if Studio prompts for it.
4. Run the `app` configuration on an emulator or physical device.

## Why Windows Here

This repo is already on a Windows path and Android Studio, the emulator, USB debugging, signing, and SDK management are usually smoother on native Windows than inside WSL.
