#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

int main(void) {
	int ii = 3;
	if (ii > 0) {
		for (int i = 4; i > 0; i--) {
			printf("*************************\n");
			printf("*%d �� ������ ���۵˴ϴ�.*\n", i);
			printf("*************************\n");
			sleep(1000);
			system("cls");
			ii--;
		}
	}
	/*jjuggumi_init();
	sample();*/
	//dialog();
	//mugunghwa();
	//nightgame();
	//juldarigi();
	//jebi();
	return 0;
}