#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROWS ROW+2
#define COLS COL+2

#define ROW 16
#define COL 16
#define MINE 40

void Initboard(char board[ROWS][COLS], int rows, int cols, char ch);
void printboard(char board[ROWS][COLS], int row, int col);
void Set_Mine(char Mine[ROWS][COLS], int row, int col);
void Mine_sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
