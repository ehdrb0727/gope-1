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
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 19) {
				map[i][j] = '#';
			}
			else
				map[i][j] = ' ';
		}
	}
	srand(time(NULL));
	map[1][1] = '*';
	map[5][10] = '@';
	int dx[4] = { -1 , 1, 0 ,0 };
	int dy[4] = { 0,0,-1,1 };
	int x = 1, y = 1;
	int m = 5, n = 10;
	int dir = 3;
	while (1) {
		int ai = rand() % 4;
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case 'w': dir = 0; break;
			case 's': dir = 1; break;
			case 'a': dir = 2; break;
			case 'd': dir = 3; break;
			case 'q': return 0;
			}
		}	
		if (tick % 100 == 0) {
			int nx = x + dx[dir]; //x 의 좌표에다가 dx[dir]에 해당하는 값을 더해준다는 거지
			int ny = y + dy[dir]; //y의 좌표에다가 dy[dir]에 해당하는 값을 더해줌
			int nxx = m + dx[ai];
			int nyy = n + dy[ai];
			if (nx > 0 && nx < 9 &&
				ny > 0 && ny < 19) {
				gotoxy(x, y); printf(" ");
				map[x][y] = ' ';
				x = nx; y = ny;
				gotoxy(x, y); printf("*");
				map[x][y] = ' ';
			}
			if (nxx > 0 && nxx< 9 &&
				nyy > 0 && nyy < 19) {
				gotoxy(m, n); printf(" ");
				map[m][n] = ' ';
				m = nxx; n = nyy;
				gotoxy(m, n); printf("@");
				map[m][n] = ' ';
			}
			if (m == x && n == y) break;
		}
		draw();
		Sleep(10);
		tick += 10;
	}
	
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
			printf("안녕하세요\n");
		}
		if (tick % 1000 == 0) {
			printf("sec: %d\n",y);
			y++;
		}
		Sleep(10);
		tick += 10;
	}*/