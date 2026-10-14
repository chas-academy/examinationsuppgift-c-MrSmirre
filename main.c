#include <stdio.h>
#include <ctype.h>

int main() {
    char namn[5][11];
    double medel[5];

    double total = 0;
    int bastElev = 0;

    for (int i = 0; i < 5; i++) {
        int summa = 0;

        scanf("%10s", namn[i]);

        for (int j = 0; j < 13; j++) {
            int poang;
            scanf("%d", &poang);
            summa = summa + poang;
        }

        medel[i] = summa / 13.0;
        total = total + summa;

        if (medel[i] > medel[bastElev]) {
            bastElev = i;
        }
    }

    double gruppMedel = total / 65.0;

    namn[bastElev][0] = toupper(namn[bastElev][0]);
    for (int i = 1; namn[bastElev][i] != '\0'; i++) {
        namn[bastElev][i] = tolower(namn[bastElev][i]);
    }

    printf("%s\n", namn[bastElev]);

    for (int i = 0; i < 5; i++) {
        if (medel[i] < gruppMedel) {
            namn[i][0] = toupper(namn[i][0]);

            for (int j = 1; namn[i][j] != '\0'; j++) {
                namn[i][j] = tolower(namn[i][j]);
            }

            printf("%s\n", namn[i]);
        }
    }

    return 0;
}