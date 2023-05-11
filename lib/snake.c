#include "snake.h"

extern int seed, speed;
unsigned int snakedisp[10][10] = {0};
unsigned int snake[800] = {0};
char dir = LEFT, prev = LEFT;
unsigned char len = 2;
unsigned int cherry;

void head() {
  gotoxy(((snake[0] & 0x3F)) * 2 + 3, ((snake[0] >> 6)) + 3);
  printf("O");
  for (int i = 1; i < len; i++)
    snake[len - i] = snake[len - i - 1];
  if (prev != DOWN && dir == UP)
    prev = dir;
  else if (dir == DOWN && prev != UP)
    prev = dir;
  else if (dir == LEFT && prev != RIGHT)
    prev = dir;
  else if (dir == RIGHT && prev != LEFT)
    prev = dir;
  else
    dir = prev;
  switch (dir) {
  case UP:
    snake[0] -= 64;
    break;
  case DOWN:
    snake[0] += 64;
    break;
  case LEFT:
    snake[0] -= 1;
    break;
  case RIGHT:
    snake[0] += 1;
  }
  if ((snake[0] & 0x3F) < 1)
    snake[0] += 39;
  else if ((snake[0] & 0x3F) > 39)
    snake[0] = (snake[0] & 0xFC0) + 1;
  else if ((snake[0] >> 6) < 1)
    snake[0] += 2560;
  else if ((snake[0] >> 6) > 40)
    snake[0] -= 2560;
  gotoxy(((snake[0] & 0x3F)) * 2 + 3, ((snake[0] >> 6)) + 3);
  printf("0");
}
void end() {
  gotoxy(((snake[len - 1] & 0x3F)) * 2 + 3, ((snake[len - 1] >> 6)) + 3);
  printf(" ");
}
void snake__init__() {

  clrscr();
  int temp = 0;
  char foo;
  struct timeval val;
  len = 2;
  snake[0] = 1300;
  snake[1] = 1301;
  cherry = (rand() % 38 + 2) * 64 + (rand() % 38 + 2);
  gotoxy(((cherry & 0x3F)) * 2 + 3, ((cherry >> 6)) + 3);
  printf("*");
  for (int i = 2; i < 42; i++) {
    gotoxy(3, i + 2);
    printf("|");
    gotoxy(83, i + 2);
    printf("|");
  }
  for (int i = 4; i < 83; i++) {
    gotoxy(i, 3);
    printf("-");
    gotoxy(i, 44);
    printf("-");
  }
  gotoxy(((snake[0] & 0x3F)) * 2 + 3, ((snake[0] >> 6)) + 3);
  printf("0");
  gotoxy(((snake[1] & 0x3F)) * 2 + 3, ((snake[1] >> 6)) + 3);
  printf("O");
  do {
    temp++;
    gotoxy(1, 1);
    if (kbhit())
      dir = getch();
    foo = dir;
    gotoxy(1, 1);
    printf("                     ");
    if (cherry == snake[0]) {
      gettimeofday(&val, NULL);
      cherry = ((seed * rand()) % 38 + 2) * 64 + ((seed * rand()) % 38 + 2);
      gotoxy(((cherry & 0x3F)) * 2 + 3, ((cherry >> 6)) + 3);
      printf("*");
      len++;
      temp++;
    } else
      end();
    head();
    for (int i = 1; i < len; i++)
      if (snake[0] == snake[i])
        foo = 'q';
    delay(500 / speed);
  } while (foo != 'q');

  printf("\n");
}
/*
void displaysnake()
{
        for(int i=0;i<10;i++)
                for(int j=0;j<10;j++)
                {
                        for(int k=0;k<4;k++)
                                for(int l=0;l<4;l++)
                                {
                                        gotoxy(((j*4+2)+l)*2,((i*4+3)+k));
                                        int temp=snakedisp[j][i];
                                        if((((temp>>k*8)>>l*2)&0x03)==1)
                                                printf("O");
                                }
                }
}
*/
