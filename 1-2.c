#include <stdio.h>
int main(void)
{
    char c;
    if (scanf_s(" %c", &c) != 1) return 0;
    printf("%d\n", (int)c);
    return 0;
}
