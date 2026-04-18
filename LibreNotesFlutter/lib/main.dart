import 'package:flutter/material.dart';

import 'src/data/vault_repository.dart';
import 'src/ui/app_controller.dart';
import 'src/ui/libre_notes_app.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  final controller = AppController(VaultRepository());
  runApp(LibreNotesBootstrap(controller: controller));
}
