#pragma once
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void clrscr();
void gotoxy(int x, int y);
char getch();
void zerozero();
int kbhit();
void delay(long milsec);
void Speed(char arr[][20]);
void Seed();
void Help();