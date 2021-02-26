#pragma once
#ifndef _Game
#define _Game
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 50

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[COLS][ROWS], int row, int col,char set);
void DisplayBoard(char board[COLS][ROWS], int row, int col);
void SetMine(char board[COLS][ROWS], int row, int col);
int FindMine(char board[COLS][ROWS], char board2[COLS][ROWS], int row, int col, int x,int y);
void DetectionMine(char board[COLS][ROWS], char board2[COLS][ROWS], int x, int y);

#endif