import 'package:flutter_test/flutter_test.dart';
import 'package:libre_notes_flutter/src/model/note_models.dart';

void main() {
  test('extracts wiki links and inline tags', () {
    const content = '''
# Daily desk
Open [[Project map]] after writing.
#focus #notes
''';

    expect(NoteParsers.extractLinks(content), <String>['Project map']);
    expect(NoteParsers.extractInlineTags(content), <String>['focus', 'notes']);
  });

  test('infers title from first meaningful line', () {
    const content = '''

## My heading
Body text
''';

    expect(NoteParsers.inferTitle(content), 'My heading');
  });
}
