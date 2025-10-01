#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x, n;
    scanf("%d", &x); // 총 금액
    scanf("%d", &n); // 물건 종류 개수

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int price, count;
        scanf("%d %d", &price, &count);
        sum += price * count;
    }

    if (sum == x) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}
