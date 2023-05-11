#include "game.h"
#include "logo.h"
#include "qlearn.h"
#include "snake.h"
#define No 7

extern int no;
int main() {
  int pos = 0;
  char ch;
  char gamename[][20] = {"Play", "Let AI Play", "Speed:Slow", "Seed",
                         "Help", "Donotclick",  "Exit"};
  clrscr();
  printf("\e[?25l");
  do {
    clrscr();
    // logoprint(1); //dono why seg fault
    for (int i = 0; i < No; i++) {
      printf("%d ", i + 1);
      if (pos == i)
        printf(" > ");
      printf("%s ", gamename[i]);
      if (pos == i)
        printf("<");
      printf("\n");
    }
    ch = getch();
    if (ch == DOWN)
      pos = (pos + 1) % No;
    else if (ch == UP)
      pos = (pos + 6) % No;
    if (ch == 13)
      switch (pos) {
      case 0:
        snake__init__();
        no = (no + 1) % 3;
        break;
      case 1:
        Qsnake__init__();
        no = (no + 1) % 3;
        break;
      case 2:
        Speed(gamename);
        break;
      case 3:
        Seed();
        break;
      case 4:
        Help();
        break;
      case 5:
        continue;
        break;
      case 6:
        ch = '7';
      }

  } while (ch != '7');
  clrscr();
  printf("\e[?25h");
  return 0;
}
