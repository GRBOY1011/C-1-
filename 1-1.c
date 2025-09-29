#include <stdio.h>

int main(void) {
    long long A, B;
    if (scanf("%lld %lld", &A, &B) != 2) return 0;
    printf("%lld\n", A + B); // µ¡¼À
    printf("%lld\n", A - B); // »¬¼À
    printf("%lld\n", A * B); // °ö¼À
    printf("%lld\n", A / B); // ³ª´°¼À
    printf("%lld\n", A % B); // ³ª¸ÓÁö
    return 0;
}
