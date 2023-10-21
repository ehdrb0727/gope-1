// 2023-2 고급프로그래밍 과제: 쭈꾸미 게임
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

int jjuggumi_init(void);

// low 이상 high 이하 난수를 발생시키는 함수
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("플레이어 수: ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true;
	}
	return 0;
}

int intro(void) {
    system("cls");
    for (int i = 3; i > 0; i--) {
        printf("로딩중... (남은 시간: %d초)\n", i);
        printf("   ／⌒\n");
        printf("　／　　　＼\n");
        printf("　/　　　　＼\n");
        printf("( /　　　　 　)\n");
        printf("/　　　　　”\n");
        printf("f　　　　　　i\n");
        printf("| ●　　●　 ｜\n");
        printf("|　 ▽　　　｜\n");
        printf("?＿＿ 　 　ノ\n");
        printf("|||丁丁￣l＼\n");
        printf("く(((＿L＿)ノ\n");
        Sleep(1000);
        system("cls");
    }
    system("cls");
}
int a;
void ending(void) {
	if (n_alive == 1) {
		system("cls");
		for (int i = 0; i < n_player; i++) {
			if (player[i]) {
				printf(" ##   ##   ####    ##   ##  ##   ##  #######  ######\n");
				printf(" ##   ##    ##     ###  ##  ###  ##   ##   #   ##  ##\n");
				printf(" ##   ##    ##     #### ##  #### ##   ## #     ##  ##\n");
				printf(" ## # ##    ##     ## ####  ## ####   ####     #####\n");
				printf(" #######    ##     ##  ###  ##  ###   ## #     ## ##\n");
				printf(" ### ###    ##     ##   ##  ##   ##   ##   #   ##  ##\n");
				printf(" ##   ##   ####    ##   ##  ##   ##  #######  #### ##\n");
				printf("\n");
				printf("우승자: player %d", i);
				printf("\n");
				printf("\n");
			}

		}
		printf("아무 키를 누르면 종료됩니다...\n");
		// 아무 키 입력 대기
		while (!kbhit()) {}

		// 프로그램 종료
		exit(0);
	}
	else {
				printf("우승자를 찾을 수 없습니다.\n");
			

		}
		printf("아무 키를 누르면 종료됩니다...\n");
		// 아무 키 입력 대기
		while (!kbhit()) {}

		// 프로그램 종료
		exit(0);
	}

int main() {
    jjuggumi_init();
    sample();
    mugunghwa();
    ending();
    return 0;
}

