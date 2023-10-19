#include "jjuggumi.h"
#include "canvas.h"
#include "keyin.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_LEFT	2
#define DIR_RIGHT	3
#define DIR_ZERO	4

void u_1(int count) {
    char massage[100] = "무 궁 화 꽃 이 피 었 습 니 다";
    if (count == 700) {
        gotoxy(N_ROW, 0);
        printf("%c%c", massage[0], massage[2]);
    }
    if (count == 900) {
        gotoxy(N_ROW, 2);
        printf("%c%c", massage[3], massage[5]);
    }
    if (count == 1200) {
        gotoxy(N_ROW, 4);
        printf("%c%c", massage[6], massage[8]);
    }
    if (count == 1600) {
        gotoxy(N_ROW, 6);
        printf("%c%c", massage[9], massage[11]);
    }
    if (count == 2200) {
        gotoxy(N_ROW, 8);
        printf("%c%c", massage[12], massage[14]);
    }
    if (count == 3000) {
        gotoxy(N_ROW, 10);
        printf("%c%c", massage[15], massage[17]);
    }
    if (count == 3800) {
        gotoxy(N_ROW, 12);
        printf("%c%c", massage[18], massage[20]);
    }
    if (count == 4400) {
        gotoxy(N_ROW, 14);
        printf("%c%c", massage[21], massage[23]);
    }
    if (count == 4800) {
        gotoxy(N_ROW, 16);
        printf("%c%c", massage[24], massage[26]);
    }
    if (count == 5000) {
        gotoxy(N_ROW, 18);
        printf("%c", massage[27]);
    }
    if (count == 8000) {
        gotoxy(N_ROW, 0);
        printf("                                   ");
    }
}
//void sample_init(void);
//void move_manual(key_t key);
//void move_random(int i, int dir);
//void move_tail_1(int i, int nx, int ny);
//void mg_init(void);
//void npc_move(int player);
//
//int px[PLAYER_MAX], py[PLAYER_MAX], period[PLAYER_MAX];  // 각 플레이어 위치, 이동 주기
//
//
//void npc_move(int player) {
//	//왼쪽 70% / 위, 아래, 제자리 10% 랜덤 확률 발생기
//	int ran = rand()% 10 + 1;
//	int ndir;
//	static int dx[5] = { -1, 1, 0, 0, 0 };
//	static int dy[5] = { 0, 0, -1, 1, 0 };
//	if (ran >= 1 && ran <= 7) ndir = DIR_LEFT;
//	else if (ran == 8) ndir = DIR_UP;
//	else if (ran == 9) ndir = DIR_DOWN;
//	else ndir = DIR_ZERO;
//
//	//플레이어 랜덤 이동
//	int p = player;
//	int nx, ny;
//	int ai = 1;
//	do {
//		nx = px[p] + dx[ndir];
//		ny = py[p] + dx[ndir];
//		//ai++;
//	} while (!placable(nx, ny));
//
//	//move_tail(p, nx, ny);
//
//	move_tail(p, nx, ny);
//}
//void move_tail_1(int player, int nx, int ny) {
//	int p = player;  // 이름이 길어서...
//	back_buf[nx][ny] = back_buf[px[p]][py[p]];
//	back_buf[px[p]][py[p]] = ' ';
//	px[p] = nx;
//	py[p] = ny;
//}
//
//int npc_per(int low, int high) {
//	int rnum = rand() % (high - low + 1) + low;
//	return rnum;
//}
//
//void npc(int player, int dir) {
//	int p = player;  // 이름이 길어서...
//	int nx, ny;  // 움직여서 다음에 놓일 자리
//
//	// 움직일 공간이 없는 경우는 없다고 가정(무한 루프에 빠짐)	
//
//	do {
//		nx = px[p] + randint(-1, 1);
//		ny = py[p] + randint(-1, 1);
//	} while (!placable(nx, ny));
//
//	move_tail(p, nx, ny);
//}
//
//void mg_init() {
//	map_init(15, 35);
//	int x, y;
//	for (int i = 0; i < n_player; i++) {
//		// 같은 자리가 나오면 다시 생성
//		do {
//			x = 3 + i;
//			y = (N_COL - 2);
//		} while (!placable(x, y));
//		px[i] = x;
//		py[i] = y;
//		period[i] = randint(100, 500);
//		back_buf[px[i]][py[i]] = '0' + i;  // (0 .. n_player-1)
//	}
//	tick = 0;
//}
//
//void mugunghwa(void) {
//	mg_init();
//	system("cls");
//	display();
//	int aa = 4;
//	while (1) {
//		/*if (aa == 4) {
//			dialog("곧 게임이 시작됩니다.");
//			aa--;
//		}*/
//		// player 0만 손으로 움직임(4방향)
//		key_t key = get_key();
//		if (key == K_QUIT) {
//			break;
//		}
//		else if (key != K_UNDEFINED) {
//			move_manual(key);
//		}
//
//		// player 1 부터는 랜덤으로 움직임(8방향)
//		for (int i = 1; i < n_player; i++) {
//			if (tick % period[i] == 0) {//period[i] = randint(100, 500);
//				npc_move(i);
//			}
//		}
//
//		display();
//		Sleep(10);
//		tick += 10;
//	}
//}