#include "game.h"


void menu() {
	printf("*******************ɨ��*****************\n");
	printf("****************1.��ʼ��Ϸ**************\n");
	printf("****************0.�˳���Ϸ**************\n");
	printf("*******************ɨ��*****************\n");
	printf("��ѡ��(1/0):");
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
			printf("���������׵����꣺");
			scanf("%d,%d", &x, &y);
			if (x >= 1 && x <= 9 && y >= 1 && x <= 9) {
				break;
			}else
			{
				printf("����Ƿ�,�����䣡��");
			}
		}
		sum = FindMine(mine, show, ROW, COL, x, y);
		if (sum == 1) {
			printf("����ʧ��");
			break;
		}
		else if(sum == -1){
			DisplayBoard(mine, ROW, COL);
			printf("���׳ɹ�\n");
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
			printf("�˳���Ϸ��лл����\n");
			break;
		default:
			printf("������1/0��лл\n");
			break;
		}
	} while (select);
}


int main() {

	test();
	
}