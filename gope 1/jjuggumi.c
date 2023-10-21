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
int main() {
    jjuggumi_init();
    sample();
    mugunghwa();
    return 0;
}

