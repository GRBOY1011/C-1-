#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x, n;
    scanf("%d", &x); // �� �ݾ�
    scanf("%d", &n); // ���� ���� ����

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
