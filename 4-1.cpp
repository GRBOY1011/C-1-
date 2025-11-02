#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int arr[9][9];
    int max = -1;
    int row = 0, col = 0;

    // 9x9 ют╥б
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max) {
                max = arr[i][j];
                row = i + 1; // 1-based index
                col = j + 1;
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d\n", row, col);
    return 0;
}
