#include "jjuggumi.h"
#include "canvas.h"
#include "keyin.h"
#include <stdio.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_LEFT	2
#define DIR_RIGHT	3
#define DIR_ZERO	3

void sample_init(void);
void move_manual(key_t key);
void move_random(int i, int dir);
void move_tail(int i, int nx, int ny);
void move_tail_1(int i, int nx, int ny);
void mg_init(void);
void npc_move(int player);

int px[PLAYER_MAX], py[PLAYER_MAX], period[PLAYER_MAX];  // 각 플레이어 위치, 이동 주기
int prev_px[PLAYER_MAX], prev_py[PLAYER_MAX]; //움직임 전의 좌표 기억

void sample_init(void) {
	map_init(15, 40);
	int x, y;
	for (int i = 0; i < n_player; i++) {
		// 같은 자리가 나오면 다시 생성
		do {
			x = randint(1, N_ROW - 2);
			y = randint(1, N_COL - 2);
		} while (!placable(x, y));
		px[i] = x;
		py[i] = y;
		period[i] = randint(100, 500);

		back_buf[px[i]][py[i]] = '0' + i;  // (0 .. n_player-1)
	}

	tick = 0;
}

void move_manual(key_t key) {
	// 각 방향으로 움직일 때 x, y값 delta
	static int dx[4] = { -1, 1, 0, 0 };
	static int dy[4] = { 0, 0, -1, 1 };

	int dir;  // 움직일 방향(0~3)
	switch (key) {
	case K_UP: dir = DIR_UP; break;
	case K_DOWN: dir = DIR_DOWN; break;
	case K_LEFT: dir = DIR_LEFT; break;
	case K_RIGHT: dir = DIR_RIGHT; break;
	default: return;
	}

	// 움직여서 놓일 자리
	int nx, ny;
	nx = px[0] + dx[dir];
	ny = py[0] + dy[dir];
	if (!placable(nx, ny)) {
		return;
	}

	safe(0, nx, ny);

}

// 0 <= dir < 4가 아니면 랜덤
void move_random(int player, int dir) {
	int p = player;  // 이름이 길어서...
	int nx, ny;  // 움직여서 다음에 놓일 자리

	// 움직일 공간이 없는 경우는 없다고 가정(무한 루프에 빠짐)	

	do {
		nx = px[p] + randint(-1, 1);
		ny = py[p] + randint(-1, 0);
	} while (!placable(nx, ny));

	safe(p, nx, ny);
	//move_tail(p, nx, ny);

}

// back_buf[][]에 기록
void move_tail(int player, int nx, int ny) {
	int p = player;  // 이름이 길어서...
	back_buf[nx][ny] = back_buf[px[p]][py[p]];
	back_buf[px[p]][py[p]] = ' ';
	px[p] = nx;
	py[p] = ny;

	//if ((nx == 5 && nx == 1) || (nx == 6 && ny == 2) || (nx == 7 && ny == 2) ||
	//	(nx == 8 && ny == 2) || (nx == 9 && ny == 1))


}




void sample(void) {
	sample_init();

	system("cls");
	display();
	int aa = 4;
	if (aa == 4) {
		dialog("곧 게임이 시작됩니다.");
		aa--;
	}
	//while (1) {
	//	/*if (aa == 4) {
	//		dialog("곧 게임이 시작됩니다.");
	//		aa--;
	//	}*/
	//	// player 0만 손으로 움직임(4방향)
	//	key_t key = get_key();
	//	if (key == K_QUIT) {
	//		break;
	//	}
	//	else if (key != K_UNDEFINED) {
	//		move_manual(key);
	//	}

	//	// player 1 부터는 랜덤으로 움직임(8방향)
	//	for (int i = 1; i < n_player; i++) {
	//		if (tick % period[i] == 0) {//period[i] = randint(100, 500);
	//			move_random(i, -1);
	//		}
	//	 }
	//	
	//	display();
	//	Sleep(10);
	//	tick += 10;

}

void npc_move(int player, int dir) {
	//왼쪽 70% / 위, 아래, 제자리 10% 랜덤 확률 발생기
	//플레이어 랜덤 이동
	srand((unsigned)time(NULL));
	int p = player;
	int nx, ny;
	int ai = 1;

	//gotoxy(N_ROW + 1, 0);
	//printf("%d", ran);
	do {
		int ran = randint(1, 10);
		if (ran >= 1 && ran <= 7) {
			nx = px[p];
			ny = py[p] - 1; //(px[4], py[4])

		}
		else if (ran == 8) {
			nx = px[p] - 1;
			ny = py[p];
		}
		else if (ran == 9) {
			nx = px[p] + 1;
			ny = py[p];
		}
		else {
			nx = px[p];
			ny = py[p];
		}
	} while (!placable(nx, ny));
	safe(p, nx, ny);
}
void mg_init() {
	map_init(15, 40);
	int x, y;
	for (int i = 0; i < n_player; i++) {
		// 같은 자리가 나오면 다시 생성
		do {
			x = 3 + i;
			y = (N_COL - 2);
		} while (!placable(x, y));
		px[i] = x;
		py[i] = y;
		period[i] = randint(100, 500);
		back_buf[px[i]][py[i]] = '0' + i;  // (0 .. n_player-1)
	}
	tick = 0;
}

void safe(int player, int nx, int ny) {
	int p = player;
	back_buf[nx][ny] = back_buf[px[p]][py[p]];
	back_buf[px[p]][py[p]] = ' ';
	px[p] = nx;
	py[p] = ny;
	if ((nx == 5 && ny == 1) || (nx == 6 && ny == 2) || (nx == 7 && ny == 2) ||
		(nx == 8 && ny == 2) || (nx == 9 && ny == 1)) {

		back_buf[px[p]][py[p]] = ' ';
	}
}

void mugunghwa(void) {
	mg_init();
	system("cls");
	display_m();
	int aa = 4;
	int alive_players = n_player;
	int dead_players = 0;
	while (1) {
		//player 0만 손으로 움직임(4방향)
		key_t key = get_key();
		if (key == K_QUIT) {
			break;
		}
		else if (key != K_UNDEFINED) {
			int prev_x = px[0];
			int prev_y = py[0];
			move_manual(key);
			if (tick >= 4000 && tick < 7000) {
				int state = 0;
				for (int j = 0; j < n_player; j++) {
					if (px[j] == px[0] && py[j] < py[0]) {
						state = 1;
						break;
					}
				}
				if (px[0] != prev_x || py[0] != prev_y) {
					if (state == 1) {
						player[0] = false;
						back_buf[px[0]][py[0]] = ' ';
					}
				}
			}
		}

		// player 1 부터는 랜덤으로 움직임(4방향)
		for (int i = 1; i < n_player; i++) {
			if (tick % period[i] == 0) {//period[i] = randint(100, 500);
				if (tick >= 4000 && tick < 7000) {
					if (tick % 200 == 0) {
						int random_chance = rand() % 10; // 1/10 확률로 npc move
						if (random_chance == 0) {
							npc_move(i, -1);
							if (px[i] != prev_px[i] || py[i] != prev_py[i]) {
								player[i] = false;
								back_buf[px[i]][py[i]] = ' ';
							}
						}
					}
					else {
						int state = false;
						for (int j = 0; j < n_player; j++) {
							if (px[j] == px[i] && py[j] < py[i]) {
								state = true;
								break; // 다른 플레이어가 앞에 가려서 탈락 안하도록 패스하기
							}
						}
						if (state == true) {
							continue;
						}
					}

					prev_px[i] = px[i]; //저장된 x, y좌표 다시 바꿈
					prev_py[i] = py[i];
				}
				else {
					npc_move(i, -1);

				}
			}
		}
		if (tick == 8010) {
			dialog_m(alive_players, dead_players);
		}
		if (tick >= 8030) {
			tick = 0;
		}

		u_1(tick);

		display_m();
		Sleep(10);
		tick += 10;
	}
}