#include <stdio.h>

int main() {
    FILE *f = fopen("matn.txt", "w");

    if (f == NULL) {
        printf("Fayl ochilmadi!");
        return 1;
    }

    fprintf(f, "Salom, C dasturlash!");

    fclose(f);

    printf("Matn faylga yozildi.");

    return 0;
}