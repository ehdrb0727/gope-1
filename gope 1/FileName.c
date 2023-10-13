#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

int main(void) {
	int ii = 3;
	if (ii > 0) {
		for (int i = 4; i > 0; i--) {
			printf("%d 곧 게임이 시작됩니다.\n", i);
			Sleep(1000);
			system("cls");
			ii--;
		}
			
	}
	//jjuggumi_init();
	//sample();
	//dialog();
	//mugunghwa();
	//nightgame();
	//juldarigi();
	//jebi();
	return 0;
}