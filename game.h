#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Count 80

void menu();
void Intiboard(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void setMine(char board[ROWS][COLS], int row, int col);
void find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_count(char mine[ROWS][COLS], int i, int j);