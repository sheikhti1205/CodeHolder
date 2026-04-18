import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:libre_notes_flutter/src/data/vault_repository.dart';
import 'package:libre_notes_flutter/src/ui/app_controller.dart';
import 'package:libre_notes_flutter/src/ui/libre_notes_app.dart';
import 'package:shared_preferences/shared_preferences.dart';

void main() {
  TestWidgetsFlutterBinding.ensureInitialized();

  testWidgets('boots into the LibreNotes home screen', (WidgetTester tester) async {
    SharedPreferences.setMockInitialValues(<String, Object>{});

    final controller = AppController(VaultRepository());

    await tester.pumpWidget(
      LibreNotesBootstrap(controller: controller),
    );

    expect(find.byType(CircularProgressIndicator), findsOneWidget);

    await tester.pumpAndSettle();

    expect(find.text('LibreNotes'), findsOneWidget);
    expect(find.text('Focus ritual'), findsOneWidget);
  });
}
