#include "qlearn.h"

extern int cherry, seed, speed;
extern int snake[800];
extern char dir, len;
unsigned char qlearn[41][41];
void Qlearn(int cherry, int n) {
  for (int i = 0; i < 41; i++)
    for (int j = 0; j < 41; j++)
      qlearn[i][j] = 1;
  qlearn[cherry >> 6][cherry & 0x3F] = n;
  for (int i = 0; i < 80; i++)
    for (int j = 1; j < 41; j++)
      for (int k = 1; k < 41; k++) {
        if ((qlearn[(j + 1)][k] - 1) > qlearn[j][k])
          qlearn[j][k] = qlearn[(j + 1)][k] - 1;
        if ((qlearn[(j - 1)][k] - 1) > qlearn[j][k])
          qlearn[j][k] = qlearn[(j - 1)][k] - 1;
        if ((qlearn[j][(k + 1)] - 1) > qlearn[j][k])
          qlearn[j][k] = qlearn[j][(k + 1)] - 1;
        if ((qlearn[j][(k - 1)] - 1) > qlearn[j][k])
          qlearn[j][k] = qlearn[j][(k - 1)] - 1;
        /*
        if((qlearn[(j+1)][k]==0))
                qlearn[j][k]--;
        else if((qlearn[(j-1)][k]==0))
                qlearn[j][k]--;
        else if((qlearn[j][(k+1)]==0))
                qlearn[j][k]--;
        else if((qlearn[j][(k-1)]==0))
                qlearn[j][k]--;
        */
      }
  /*

          for(int i=0;i<38;i++)
                  for(int j=0;j<38;j++)
                  {
                          gotoxy(j*2+3,i+3);
                          printf("%d",qlearn[i][j]%100);
                  }
  */
  /*
          if(x>2&&x<38&&y>2&&y<38)
          {
                  if(qlearn[y+1][x]<(n-1))
                          Qlearn(cherry+64,n-1);
                  if(qlearn[y-1][x]<(n-1))
                          Qlearn(cherry-64,n-1);
                  if(qlearn[y][x+1]<(n-1))
                          Qlearn(cherry+1,n-1);
                  if(qlearn[y][x-1]<(n-1))
                          Qlearn(cherry-1,n-1);
          }
  */
}
void pocket() {
  int i = 1;
  while (i < len && (snake[0] + 1) != snake[i] && (snake[0] - 1) != snake[i] &&
         (snake[0] + 64) != snake[i] && (snake[0] - 64) != snake[i])
    ;
  if ((snake[i] - snake[i - 1]) == -1 && dir == RIGHT)
    dir = LEFT;
  else if ((snake[i] - snake[i - 1]) == 1 && dir == LEFT)
    dir = RIGHT;
  else if ((snake[i] - snake[i - 1]) == 64 && dir == UP)
    dir = DOWN;
  else if ((snake[i] - snake[i - 1]) == -64 && dir == DOWN)
    dir = UP;
}
void Qcontrol() {
  Qlearn(cherry, 255);
  int a, b;
  char c, d;
  for (int i = 0; i < len; i++)
    qlearn[snake[i] >> 6][snake[i] & 0x3F] = 0;
  int x = snake[0] & 0x3F, y = snake[0] >> 6;
  if (qlearn[y + 1][x] > qlearn[y - 1][x]) {
    c = DOWN;
    a = qlearn[y + 1][x];
  } else {
    c = UP;
    a = qlearn[y - 1][x];
  }
  if (qlearn[y][x + 1] > qlearn[y][x - 1]) {
    d = RIGHT;
    b = qlearn[y][x + 1];
  } else {
    d = LEFT;
    b = qlearn[y][x - 1];
  }
  if (a > b)
    dir = c;
  else
    dir = d;
}
/*
void Qhead()
{
        gotoxy(((snake[0]&0x3F))*2+3,((snake[0]>>6))+3);
        printf("O");
        for(int i=1;i<len;i++)
                snake[len-i]=snake[len-i-1];

        if(prev!=DOWN&&dir==UP)
                prev=dir;
        else if(dir==DOWN&&prev!=UP)
                prev=dir;
        else if(dir==LEFT&&prev!=RIGHT)
                prev=dir;
        else if(dir==RIGHT&&prev!=LEFT)
                prev=dir;
        else
                dir=prev;

        switch (dir){
                case UP:
                        snake[0]-=64;
                        break;
                case DOWN:
                        snake[0]+=64;
                        break;
                case LEFT:
                        snake[0]-=1;
                        break;
                case RIGHT:
                        snake[0]+=1;
        }
        if((snake[0]&0x3F)<1)
                snake[0]+=39;
        else if((snake[0]&0x3F)>39)
                snake[0]=(snake[0]&0xFC0)+1;
        else if((snake[0]>>6)<1)
                snake[0]+=2560;
        else if((snake[0]>>6)>40)
                snake[0]-=2560;
        gotoxy(((snake[0]&0x3F))*2+3,((snake[0]>>6))+3);
        printf("0");
}
void Qend()
{
        gotoxy(((snake[len-1]&0x3F))*2+3,((snake[len-1]>>6))+3);
        printf(" ");
}
*/
void Qsnake__init__() {

  clrscr();
  int temp = 0;
  char foo;
  snake[0] = 1300;
  snake[1] = 1301;
  len = 2;
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
    /*
                    gotoxy(1,1);
                    if(kbhit())
                            dir=getch();
                    gotoxy(1,1);
                    printf("                     ");
                    Qlearn(snake[0],99);
            */
    if (kbhit())
      foo = getch();
    Qcontrol();
    pocket();
    if (cherry == snake[0]) {
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

  getch();
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
