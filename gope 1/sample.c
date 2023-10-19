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

int px[PLAYER_MAX], py[PLAYER_MAX], period[PLAYER_MAX];  // �� �÷��̾� ��ġ, �̵� �ֱ�

void sample_init(void) {
	map_init(15, 40);
	int x, y;
	for (int i = 0; i < n_player; i++) {
		// ���� �ڸ��� ������ �ٽ� ����
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
	// �� �������� ������ �� x, y�� delta
	static int dx[4] = { -1, 1, 0, 0 };
	static int dy[4] = { 0, 0, -1, 1 };

	int dir;  // ������ ����(0~3)
	switch (key) {
	case K_UP: dir = DIR_UP; break;
	case K_DOWN: dir = DIR_DOWN; break;
	case K_LEFT: dir = DIR_LEFT; break;
	case K_RIGHT: dir = DIR_RIGHT; break;	
	default: return;
	}

	// �������� ���� �ڸ�
	int nx, ny;
	nx = px[0] + dx[dir];
	ny = py[0] + dy[dir];
	if (!placable(nx, ny)) {
		return;
	}

	move_tail(0, nx, ny);
}

// 0 <= dir < 4�� �ƴϸ� ����
void move_random(int player, int dir) {
	int p = player;  // �̸��� ��...
	int nx, ny;  // �������� ������ ���� �ڸ�

	// ������ ������ ���� ���� ���ٰ� ����(���� ������ ����)	

	do {
		nx = px[p] + randint(-1, 1);
		ny = py[p] + randint(-1, 0);
	} while (!placable(nx, ny));

	move_tail(p, nx, ny);
}

// back_buf[][]�� ���
void move_tail(int player, int nx, int ny) {
	int p = player;  // �̸��� ��...
	back_buf[nx][ny] = back_buf[px[p]][py[p]];
	back_buf[px[p]][py[p]] = ' ';
	px[p] = nx;
	py[p] = ny;
}



void sample(void) {
	sample_init();

	system("cls");
	display();
	int aa = 4;
	 if (aa == 4) {
			dialog("�� ������ ���۵˴ϴ�.");
			aa--;
		}
	//while (1) {
	//	/*if (aa == 4) {
	//		dialog("�� ������ ���۵˴ϴ�.");
	//		aa--;
	//	}*/
	//	// player 0�� ������ ������(4����)
	//	key_t key = get_key();
	//	if (key == K_QUIT) {
	//		break;
	//	}
	//	else if (key != K_UNDEFINED) {
	//		move_manual(key);
	//	}

	//	// player 1 ���ʹ� �������� ������(8����)
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
		if (ran >= 1 && ran <= 7){
			nx = px[p];
			ny = py[p] - 1;
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
	move_tail(p, nx, ny);
}
void mg_init() {
	map_init(15, 35);
	int x, y;
	for (int i = 0; i < n_player; i++) {
		// ���� �ڸ��� ������ �ٽ� ����
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

void mugunghwa(void) {
	mg_init();
	system("cls");
	display();
	int aa = 4;
	//u_1();
	while (1) {
		
		// player 0�� ������ ������(4����)��
		key_t key = get_key();
		if (key == K_QUIT) {
			break;
		}
		else if (key != K_UNDEFINED) {
			move_manual(key);
		}

		// player 1 ���ʹ� �������� ������(8����)
		for (int i = 1; i < n_player; i++) {
			if (tick % period[i] == 0) {//period[i] = randint(100, 500);
				npc_move(i, -1);
			}
		}
		display();
		Sleep(10);
		tick += 10;
	}
}