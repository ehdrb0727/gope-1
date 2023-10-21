#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int intro(void) {
    system("cls");
    for (int i = 3; i > 0; i--) {
        printf("·ÎµùÁß... (³²Àº ½Ã°£: %dÃÊ)\n", i);
        printf("   £¯¡Ò\n");
        printf("¡¡£¯¡¡¡¡¡¡¡¬\n");
        printf("¡¡/¡¡¡¡¡¡¡¡¡¬\n");
        printf("( /¡¡¡¡¡¡¡¡ ¡¡)\n");
        printf("/¡¡¡¡¡¡¡¡¡¡¡±\n");
        printf("f¡¡¡¡¡¡¡¡¡¡¡¡i\n");
        printf("| ¡Ü¡¡¡¡¡Ü¡¡ £ü\n");
        printf("|¡¡ ¡ä¡¡¡¡¡¡£ü\n");
        printf("?£ß£ß ¡¡ ¡¡«Î\n");
        printf("|||ïËïË£þl¡¬\n");
        printf("ª¯(((£ßL£ß)«Î\n");
        Sleep(1000);
        system("cls");
    }
    /*printf("·ÎµùÁß... (³²Àº ½Ã°£: %dÃÊ)\n");
    printf("   £¯¡Ò\n");
    printf("¡¡£¯¡¡¡¡¡¡¡¬\n");
    printf("¡¡/¡¡¡¡¡¡¡¡¡¬\n");
    printf("( /¡¡¡¡¡¡¡¡ ¡¡)\n");
    printf("/¡¡¡¡¡¡¡¡¡¡¡±\n");
    printf("f¡¡¡¡¡¡¡¡¡¡¡¡i\n");
    printf("| ¡Ü¡¡¡¡¡Ü¡¡ £ü\n");
    printf("|¡¡ ¡ä¡¡¡¡¡¡£ü\n");
    printf("?£ß£ß ¡¡ ¡¡«Î\n");
    printf("|||ïËïË£þl¡¬\n");
    printf("ª¯(((£ßL£ß)«Î\n");
    Sleep(1000);
    Sleep(1000);
    Sleep(1000);*/
    system("cls");
}
//char massage[100] = "¹« ±Ã È­ ²É ÀÌ ÇÇ ¾ú ½À ´Ï ´Ù";
//int aa[] = {0};
int main() {
    jjuggumi_init();
    mugunghwa();
    return 0;
}