#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

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
    /*printf("�ε���... (���� �ð�: %d��)\n");
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
    Sleep(1000);
    Sleep(1000);*/
    system("cls");
}
//char massage[100] = "�� �� ȭ �� �� �� �� �� �� ��";
//int aa[] = {0};
int main() {
    jjuggumi_init();
    mugunghwa();
    return 0;
}