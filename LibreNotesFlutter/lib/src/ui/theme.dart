import 'package:flutter/material.dart';

import '../model/note_models.dart';

ThemeMode resolveThemeMode(ThemeModePreference preference) {
  switch (preference) {
    case ThemeModePreference.system:
      return ThemeMode.system;
    case ThemeModePreference.light:
      return ThemeMode.light;
    case ThemeModePreference.dark:
      return ThemeMode.dark;
  }
}

ThemeData buildLightTheme() {
  final colorScheme = ColorScheme.fromSeed(
    seedColor: const Color(0xFF476A57),
    brightness: Brightness.light,
  );
  return ThemeData(
    useMaterial3: true,
    colorScheme: colorScheme,
    scaffoldBackgroundColor: const Color(0xFFF5F1E7),
    inputDecorationTheme: const InputDecorationTheme(
      border: OutlineInputBorder(),
      filled: true,
      fillColor: Colors.white,
    ),
  );
}

ThemeData buildDarkTheme() {
  final colorScheme = ColorScheme.fromSeed(
    seedColor: const Color(0xFFC8B89D),
    brightness: Brightness.dark,
  );
  return ThemeData(
    useMaterial3: true,
    colorScheme: colorScheme,
    scaffoldBackgroundColor: const Color(0xFF0F1417),
    inputDecorationTheme: InputDecorationTheme(
      border: const OutlineInputBorder(),
      filled: true,
      fillColor: colorScheme.surfaceContainerHighest,
    ),
  );
}
