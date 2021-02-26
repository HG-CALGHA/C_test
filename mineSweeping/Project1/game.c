#include "game.h"


void InitBoard(char board[COLS][ROWS], int row, int col,char set) {
	for (int x = 0; x < row; x++) {
		for (int y = 0;y < col;y++) {
			board[x][y] = set;
		}
	}
};

void DisplayBoard(char board[COLS][ROWS], int row, int col) {
	for (int y = 0;y <= col;y++) {
		printf("%d ", y);
	}
	printf("\n");
	for (int x = 0; x < row; x++) {
		printf("%d ", x+1);
		for (int y = 0;y < col;y++) {
			printf("%c ", board[x + 1][y + 1]);
		}
		printf("\n");
	}

}

void SetMine(char board[COLS][ROWS], int row, int col){
	int x, y,i = 0;
	while(i < EASY_COUNT)
	{
			x = rand() % row + 1;
			y = rand() % col + 1;
			
			if (board[x][y] == '0') {
				board[x][y] = '@';
				i++;
			};
	}
}

int FindMine(char board[COLS][ROWS], char board2[COLS][ROWS], int row, int col, int x, int y) {
	int sum = EASY_COUNT;
	if (board2[x][y] == ' ') {
		printf("该坐标已排查,请重输！\n");
		return 0;
	};

	if (board[x][y] == '@') {
		return 1;
	}
	else if(board[x][y] == '0'){
		DetectionMine(board, board2, x, y);
	}

	if (win(board2,row,col) == (row*col)-sum) {
		return -1;
	}
	printf("%d\n", win(board2, row, col));
	return 0;
}

void DetectionMine(char board[COLS][ROWS],char board2[COLS][ROWS],int x, int y) {
	int sum = 0;
	for (int i = 0;i < 3;i++) {
		for (int O = 0; O < 3; O++)
		{
			if (board[(x - 1) + i][(y - 1) + O] == '@') {
				sum++;
			}
		}
	}
	if (sum == 0) {
		for (int i = 0;i < 3;i++) {
			for (int O = 0; O < 3; O++)
			{
				if(board2[(x - 1) + i][(y - 1) + O] == '*') board2[(x - 1) + i][(y - 1) + O] = ' ';
			}
		}
	}
	else board2[x][y] = (char)sum + 48;
}

int win(char board2[COLS][ROWS], int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int y = 0; y < col; y++)
		{
			if (board2[i+1][y+1] != '*') {
				sum++;
			}
		}
	}
	return sum;
};