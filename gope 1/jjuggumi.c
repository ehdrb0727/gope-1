// 2023-2 ������α׷��� ����: �޲ٹ� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

int jjuggumi_init(void);

// low �̻� high ���� ������ �߻���Ű�� �Լ�
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("�÷��̾� ��: ");
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
        printf("�ε���... (���� �ð�: %d��)\n", i);
        printf("   ����\n");
        printf("������������\n");
        printf("��/����������\n");
        printf("( /�������� ��)\n");
        printf("/������������\n");
        printf("f������������i\n");
        printf("| �ܡ����ܡ� ��\n");
        printf("|�� �䡡������\n");
        printf("?�ߣ� �� ����\n");
        printf("|||���ˣ�l��\n");
        printf("��(((��L��)��\n");
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

