#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>                 
#include <stdlib.h>                // 동적 메모리 함수(malloc, free) 사용을 위한 헤더

int main(void) {

    int* ptr1 = (int*)malloc(sizeof(int));   // int 크기(4바이트 정도)의 메모리를 동적으로 할당받고, 그 주소를 ptr1이 가리키게 함
    int* ptr2 = (int*)malloc(sizeof(int));   // int 크기(4바이트)의 메모리를 또 하나 할당받고, ptr2가 가리키게 함

    *ptr1 = 20;                    // ptr1이 가리키는 메모리에 20 저장

    for (int i = 0; i < 3; i++)    // i가 0부터 2까지 반복
        ptr2[i] = i;               // ptr2가 가리키는 공간에 i 저장

    printf("%d\n", *ptr1);         // ptr1이 가리키는 값(20)을 출력

    for (int i = 0; i < 3; i++)    // i가 0부터 2까지 반복
        printf("%d ", ptr2[i]);    // ptr2의 i번째 정수값 출력

    free(ptr1);                    // ptr1이 가리키는 동적 메모리를 해제
    free(ptr2);                    // ptr2가 가리키는 메모리를 해제

    return 0;                      // 정상 종료

}
//위 과정을 거치면 ptr1의 주소에 20이 저장되어 있으므로 20을 출력, 그리고 ptr2에는 각각 0, 1, 2가 저장되어 0, 1, 2를 순서대로 출력한다.
