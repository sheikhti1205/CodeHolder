#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate(char str[]) {

  char tokens[10][20]; // Array to store the tokens assuming each token is max.
                       // 10 words.
  int i;
  // printf("2nd test: %s", str);  // The string is copied successfully.
  char *token = strtok(str, " ");
  // Helps tokenize the string using the spaces between them as separators.

  for (i = 0; token != NULL;) {
    strcpy(tokens[i], token);
    i++;

    token = strtok(NULL, " ");
  }

  /*
    for (int j = 0; j < i; j++) {
    printf("%s ", tokens[j]);
  }
  */  // The tokens are stored correctly.

  if ((strcmp(tokens[0], "CU") != 0))
    return 0; // First is CU

  if (strlen(tokens[1]) != 3)
    return 0; // Second has only three charcters

  for (int j = 0; tokens[1][j] != '\0'; j++) {
    if (!isupper(tokens[1][j]))
      return 0; // Second is all upper
  }

  if (strlen(tokens[2]) != 6)
    return 0; // Third has 6 letters

  for (int j = 0; tokens[2][j] != '\0'; j++) {
    if (!isdigit(tokens[2][j]))
      return 0; // Third has all numbers
  }

  if (strlen(tokens[3]) != 4)
    return 0; // Fourth has 4 letters

  for (int j = 0; tokens[3][j] != '\0'; j++) {
    if (!isdigit(tokens[3][j]))
      return 0; // Fourth has all numbers
  }

  if (strlen(tokens[4]) != 3)
    return 0; // Fifth has three characters

  for (int j = 0; tokens[4][j] != '\0'; j++) {
    if (!isupper(tokens[4][j]))
      return 0; // Fifth is all upper
  }

  if (strlen(tokens[5]) != 6)
    return 0; // Sixth has 6 letters

  for (int j = 0; tokens[5][j] != '\0'; j++) {
    if (!isdigit(tokens[5][j]))
      return 0; // Sixth is all numbers
  }

  if (strlen(tokens[6]) != 4)
    return 0; // Seventh has 4 letters

  for (int j = 0; tokens[6][j] != '\0'; j++) {
    if (!isdigit(tokens[6][j]))
      return 0; // Seventh is all digits
  }

  int hscyear = atoi(tokens[2]);
  int sscyear = atoi(tokens[6]);

  if (hscyear < sscyear + 2)
    return 0;

  return 1;
}

int main() {
  char str[40];
  printf("Enter your SMS below: \n");
  scanf("%[^\n]s", str); // For some reason the & is not needed here.

  printf("\nYou entered: %s\n", str);

  int ret = validate(str);

  printf("The output is: \n%d", ret);

  return 0;
}
