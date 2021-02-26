#include "game.h"


void menu() {
	printf("*******************É¨À×*****************\n");
	printf("****************1.¿ªÊ¼ÓÎÏ·**************\n");
	printf("****************0.ÍË³öÓÎÏ·**************\n");
	printf("*******************É¨À×*****************\n");
	printf("ÇëÑ¡Ôñ(1/0):");
}

void game() {
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int x, y,sum;
	InitBoard(show, ROWS, COLS,'*');
	InitBoard(mine, ROWS, COLS, '0');
	DisplayBoard(show, ROW, COL);

	SetMine(mine,ROW,COL);
	DisplayBoard(mine, ROW, COL);
	while (1)
	{
		while (1)
		{
			printf("ÇëÊäÈëÅÅÀ×µÄ×ø±ê£º");
			scanf("%d,%d", &x, &y);
			if (x >= 1 && x <= 9 && y >= 1 && x <= 9) {
				break;
			}else
			{
				printf("×ø±ê·Ç·¨,ÇëÖØÊä£¡£¡");
			}
		}
		sum = FindMine(mine, show, ROW, COL, x, y);
		if (sum == 1) {
			printf("ÅÅÀ×Ê§°Ü");
			break;
		}
		else if(sum == -1){
			DisplayBoard(mine, ROW, COL);
			printf("ÅÅÀ×³É¹¦\n");
			break;
		};
		DisplayBoard(show, ROW, COL);
	}

};

void test() {
	srand((unsigned int)time(NULL));
	int select;
	do {
		menu();
		scanf("%d",&select);

		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÍË³öÓÎÏ·£¬Ð»Ð»ÓÎÍæ\n");
			break;
		default:
			printf("ÇëÊäÈë1/0£¬Ð»Ð»\n");
			break;
		}
	} while (select);
}


int main() {

	test();
	
}