#include <stdio.h>
#include <string.h>

struct Mahsulot {
    char nomi[50];
    int narx;
    int soni;
};

int main() {
    struct Mahsulot m[5];
    int max = 0;
    char qidiruv[50];
    int topildi = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%s %d %d", m[i].nomi, &m[i].narx, &m[i].soni);
    }

    for (int i = 1; i < 5; i++) {
        if (m[i].narx > m[max].narx) {
            max = i;
        }
    }

    scanf("%s", qidiruv);

    for (int i = 0; i < 5; i++) {
        if (strcmp(m[i].nomi, qidiruv) == 0) {
            printf("Mahsulot topildi!\n");
            printf("Nomi: %s\n", m[i].nomi);
            printf("Narxi: %d\n", m[i].narx);
            printf("Soni: %d\n", m[i].soni);
            topildi = 1;
            break;
        }
    }

    if (!topildi) {
        printf("Mahsulot topilmadi!\n");
    }

    FILE *f = fopen("mahsulotlar.txt", "w");

    if (f == NULL) {
        printf("Fayl ochilmadi!");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(f, "%s %d %d\n", m[i].nomi, m[i].narx, m[i].soni);
    }

    fclose(f);

    printf("\nMa'lumotlar mahsulotlar.txt fayliga saqlandi.");

    return 0;
}