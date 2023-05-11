#include "game.h"

int no = 0;
int speed = 1;
int seed = 1;
int color;
void clrscr() { system("clear"); }
void gotoxy(int x, int y) { printf("\e[%d;%df", y, x); }
void zerozero() {

  printf("\e[2J");
  printf("\e[1000D");
  printf("\e[1000A");
}
char getch() {
  char ch;
  system("stty raw");
  ch = getchar();
  system("stty sane");
  return ch;
}
int kbhit() {
  struct termios a, b;
  int ch;
  int temp;
  tcgetattr(STDIN_FILENO, &a);
  b = a;
  b.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &b);
  temp = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, temp | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &a);
  fcntl(STDIN_FILENO, F_SETFL, temp);
  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}
void delay(long milsec) {
  struct timeval start, stop;
  gettimeofday(&start, NULL);
  do {
    gettimeofday(&stop, NULL);
  } while ((stop.tv_sec - start.tv_sec) < 1 &&
           (stop.tv_usec - start.tv_usec) < milsec * 1000);
}
void Speed(char arr[][20]) {
  switch (speed) {
  case 50:
    for (int i = 0; i <= 4; i++)
      arr[2][6 + i] = "Slow"[i];
    speed = 1;
    break;
  case 1:
    for (int i = 0; i <= 6; i++)
      arr[2][6 + i] = "Normal"[i];
    speed = 5;
    break;
  case 5:
    for (int i = 0; i <= 4; i++)
      arr[2][6 + i] = "Fast"[i];
    speed = 10;
    break;
  case 10:
    for (int i = 0; i <= 9; i++)
      arr[2][6 + i] = "SuperFast"[i];
    speed = 50;
    break;
  default:
    speed = 1;
  }
}
void Seed() {
  clrscr();
  printf("Seed: ");
  scanf("%d", &seed);
}
void Help() {
  clrscr();
  printf("Up:\t%c\n", UP);
  printf("Down:\t%c\n", DOWN);
  printf("Left:\t%c\n", LEFT);
  printf("Right:\t%c\n", RIGHT);
  getch();
}
