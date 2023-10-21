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

void safe(void);
void mg_init(void);
void npc_move(int player);

int px[PLAYER_MAX], py[PLAYER_MAX], period[PLAYER_MAX];  // �� �÷��̾� ��ġ, �̵� �ֱ�
int prev_px[PLAYER_MAX], prev_py[PLAYER_MAX]; //������ ���� ��ǥ ���
int winner[20];

void u_1(int count) {
    //char massage[100] = "�� �� ȭ �� �� �� �� �� �� ��";
    if (count == 100) {
        gotoxy(N_ROW, 0);
        printf("��");
    }
    if (count == 300) {
        gotoxy(N_ROW, 0);
        printf("�� ��");
    }
    if (count == 600) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ");
    }
    if (count == 1000) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ ��");
    }
    if (count == 1400) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ �� ��");
    }
    if (count == 1700) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ �� �� ��");
    }
    if (count == 2100) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ �� �� �� ��");
    }
    if (count == 2500) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ �� �� �� �� ��");
    }
    if (count == 2800) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ �� �� �� �� �� ��");
    }
    if (count == 3000) {
        gotoxy(N_ROW, 0);
        printf("�� �� ȭ �� �� �� �� �� �� ��");
        uh = 1;
    }
    if (count == 6000) {
        gotoxy(N_ROW, 0);
        printf("                                   ");
        
    }
}
int random_chance;
char dg;
int is;

void npc_move(int player, int dir) {
	//���� 70% / ��, �Ʒ�, ���ڸ� 10% ���� Ȯ�� �߻���
	//�÷��̾� ���� �̵�
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
		// ���� �ڸ��� ������ �ٽ� ����
		do {
			x = 3 + i;
			y = (N_COL - 2);
		} while (!placable(x, y));
		px[i] = x;
		py[i] = y;
		period[i] = randint(100, 300);
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
		winner[p] = 111;
		back_buf[px[p]][py[p]] = ' ';
	}
}

void mugunghwa(void) {
	mg_init();
	system("cls");
	display_m();
	int aa = 4;
	int dead_players = 0;
	int ii = 0;
	char dg[100] = "player  dead!";
	int is = 6;
	int a;
	while (1) {
		//player 0�� ������ ������(4����)
		key_t key = get_key();
		if (key == K_QUIT) {
			break;
		}
		else if (key != K_UNDEFINED) {
			int prev_x = px[0];
			int prev_y = py[0];
			move_manual(key);
			if (uh == 1) {
				int state = 0;
				for (int j = 0; j < n_player; j++) {
					if (px[j] == px[0] && py[j] < py[0]) {
						state = 1;
						break;
					}
				}
				if (player[0] == true) {
					if (px[0] != prev_x || py[0] != prev_y) {
						if (state == 0) {
							player[0] = false;
							if (player[0] == false) n_alive--; dead_players++;
							back_buf[px[0]][py[0]] = ' ';
							int length = strlen(dg);
							for (int j = length; j >= is; j--) {
								dg[j + 1] = dg[j];
							}
							dg[is] = ',';
							is++;
							for (int j = length; j >= is; j--) {
								dg[j + 1] = dg[j];
							}
							dg[is] = '0';
							is++;
							gotoxy(N_ROW + 3, 0);
							printf("%d", dead_players);
						}

					}
				}
				if (px[0] != prev_x || py[0] != prev_y) {
					if (state == 0) {
						player[0] = false;
						back_buf[px[0]][py[0]] = ' ';
					}
				}
			}
		}

		// player 1 ���ʹ� �������� ������(4����)
		for (int i = 1; i < n_player; i++) {
			
			if (tick % period[i] == 0) {//period[i] = randint(100, 500);
				if (uh == 1) {
					random_chance = randint(1, 10); // 1/10 Ȯ���� npc move
					if (random_chance == 1) {
						if (winner[i] != 111) {
							npc_move(i, -1);
						}
						if (player[i] == true) {
							if (px[i] != prev_px[i] || py[i] != prev_py[i]) {
								int length = strlen(dg);
								for (int j = length; j >= is; j--) {
									dg[j + 1] = dg[j];
								}
								dg[is] = ',';
								is++;
								for (int j = length; j >= is; j--) {
									dg[j + 1] = dg[j];
								}
								dg[is] = i + '0';
								is++;
								dead_players++;
								gotoxy(N_ROW + 3, 0);
								printf("%d", dead_players);
								player[i] = false;
								back_buf[px[i]][py[i]] = ' ';
								n_alive--;
								ii++;
							}
						}
					}
					else {
						int state = false;
						for (int j = 0; j < n_player; j++) {
							if (px[j] == px[i] && py[j] < py[i]) {
								state = true;
								break; // �ٸ� �÷��̾ �տ� ������ Ż�� ���ϵ��� �н��ϱ�
							}
						}
						if (state == true) {
							continue;
						}
					}


					prev_px[i] = px[i]; //����� x, y��ǥ �ٽ� �ٲ�
					prev_py[i] = py[i];
				}
				else {
					npc_move(i, -1);

				}
			}
		}
		if (tick == 6000) {
			uh = 0;
			if (dead_players != 0) {
				dialog_m(dg);
				dead_players = 0;
				for (int i = 0; i < 23; i++) {
					dg[i] = ' ';
				}
				dg[0] = 'p';
				dg[1] = 'l';
				dg[2] = 'a';
				dg[3] = 'y';
				dg[4] = 'e';
				dg[5] = 'r';
				dg[6] = ' ';
				dg[7] = ' ';
				dg[8] = 'd';
				dg[9] = 'e';
				dg[10] = 'a';
				dg[11] = 'd';
				dg[12] = '!';
				is = 6;
			}
		}
		if (tick >= 6010) {
			tick = 0;
		}
		u_1(tick);
		display_m();
		Sleep(10);
		tick += 10;
		gotoxy(N_ROW + 2, 0);
		printf("%d", tick);
		int a = 0;
		for (int i = 0; i < 10; i++) {
			if (player[i] == true && winner[i] == 111) {
				a++;
			}
		}
		if (a == n_alive) {
			break;
		}
		if (n_alive == 1) {
			break;
		}
	}
}