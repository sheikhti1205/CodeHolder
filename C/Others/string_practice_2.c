#include <stdio.h>
#include <string.h>

void RetroP(int x, int y, char dir[1000]);

int main() {
  int x = 0, y = 0;
  char str[1000], choice;

  printf("Would you like to set a custom starting point (note that default is "
         "0, 0 )? (n to cancel)\n");
  scanf("%c", &choice);

  while (choice != 'n') {
    printf("Enter position in x, y: \n");
    scanf("%d, %d", &x, &y);
    printf("You entered %d, %d. Is this correct? (y to continue): \n", x, y);
    getchar();
    scanf("%c", &choice);
    if (choice == 'y') {
      break;
    }
  }

  getchar();

  printf("\nEnter your string of command: \n");
  fgets(str, sizeof(str), stdin);

  RetroP(x, y, str);

  return 0;
}

void RetroP(int x, int y, char dir[1000]) {

  for (int i = 0; i < strlen(dir); i++) {
    if (dir[i] == 'R')
      x++;
    if (dir[i] == 'L')
      x--;
    if (dir[i] == 'U')
      y++;
    if (dir[i] == 'D')
      y--;
  }

  printf("Updated location: %d, %d", x, y);
}
