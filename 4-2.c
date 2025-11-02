#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct { int w, h; } Person;

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    Person p[50];
    for (int i = 0; i < N; i++) scanf("%d %d", &p[i].w, &p[i].h);

    for (int i = 0; i < N; i++) {
        int rank = 1;                    // 기본 등수는 1
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (p[i].w < p[j].w && p[i].h < p[j].h) rank++;   // i보다 더 큰 덩치 발견
        }
        printf("%d", rank);
        if (i != N - 1) printf(" ");
    }
    return 0;
}
