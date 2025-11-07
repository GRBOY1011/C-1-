#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>                

int main() {                       

    char ch;                       // 읽어온 문자를 담을 변수 (주의: fgetc의 반환형은 int이기 때문!)

    FILE* fp = fopen("C:/Users/nara/source/repos/ex5-1.c/ex5-1.c/data.txt", "rt");

    // 파일을 텍스트 모드로 읽기(rt)로 열고, 경로를 지정해준다
    // 존재하지 않으면 NULL 반환

    if (fp == NULL) {              // 파일 열기에 실패했는지 검사
        printf("Failed to open file"); // 실패 메시지 출력(마찬가지로 perror도 사용 가능)
        return -1;                 // 비정상 종료 코드 반환
    }

    for (int i = 0; i < 3; i++) {  // 총 3개의 문자를 읽어 출력하는 루프(i가 0부터 2까지)
        ch = fgetc(fp);            // 파일에서 문자 1개를 읽음
        printf("%c\n", ch);        // 읽은 문자를 한 줄에 하나씩 출력
    }

    fclose(fp);                    // 열린 파일 스트림을 닫고 버퍼?를 비움
    return 0;                      // 정상 종료 코드 반환
}

//위 과정을 거치고 나면 A,B,C가 차례차례 한줄씩 출력된다. (data.txt에 ABC가 있으니까 하나씩 읽어오는 것)

