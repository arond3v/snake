#include "logo.h"

void logoprint(int p) {
  char ch;
  FILE *file;
  switch (p) {
  case 0:
    file = fopen("../img/temp.txt", "r");
    while ((ch = fgetc(file)) != EOF)
      printf("%c", ch);
    fclose(file);
    break;
  case 1:
    file = fopen("../img/temp1.txt", "r");
    while ((ch = fgetc(file)) != EOF)
      printf("%c", ch);
    fclose(file);
    break;
  case 2:
    file = fopen("../img/temp2.txt", "r");
    while ((ch = fgetc(file)) != EOF)
      printf("%c", ch);
    fclose(file);
    break;
  }
}
