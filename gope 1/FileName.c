#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

void gotoxy(int row, int col);

void gotoxy(int row, int col) {
	COORD pos = { col ,row };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		pos
	);
}
//int tick = 0;
char map[10][20]; front[10][20];
void draw(void) {
	//system("cls");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			//printf("%c", map[i][j]);
			if (front[i][j] != map[i][j]) {
				front[i][j] = map[i][j];
				gotoxy(i, j);
				printf("%c", front[i][j]);
			}
		}
		//printf("\n");
	}
}

int tick = 0;


int main(void) {
	printf("hello world");
	printf("aaaa");
	
}
/*int y = 1;
	while (1) {
		if (_kbhit()) {
			int key = _getch();
			if (key == 224) {
				int key = _getch();
				switch (key) {
				case 75: printf("<-\n"); break;
				case 77: printf("->\n"); break;
				}
			}
			if (key == 'q') { break; }
		}
		if (tick % 100 == 0) {
			gotoxy(1, y); printf(" ");
			y++;
			gotoxy(1, y); printf("*");
		}
		Sleep(10);
		tick += 10;
	}*/
/*int y = 1;
	while (1) {
		if (_kbhit()) {
			int key = _getch();
			if (key == 'q') { break; }
		}
		if (tick % 100 == 0) {
			gotoxy(1, y); printf(" ");
			y++;
			gotoxy(1, y); printf("*");
		}
		Sleep(10);
		tick += 10;
	}*/
/*int y = 1;
	while (1) {
		if (tick % 100 == 0) {
			gotoxy(1, y); printf(" ");
			y++;
			gotoxy(1, y); printf("*");
		}
		Sleep(10);
		tick += 10;
	}*/
/*int y = 1;
	while (1) {
		if (tick % 3000 == 0) {
			printf("æ»≥Á«œººø‰\n");
		}
		if (tick % 1000 == 0) {
			printf("sec: %d\n",y);
			y++;
		}
		Sleep(10);
		tick += 10;
	}*/