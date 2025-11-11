#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <errno.h> // 오류 진단 함수인 perror()를 사용하기 위해 추가

int main() {
    FILE* org = NULL;
    FILE* copy = NULL;
    char str[20];
    int return_code = -1; // 기본적으로 실패(-1)로 설정

    // 1. input.txt 열기 시도
    org = fopen("input.txt", "rt");
    if (org == NULL) {
        printf("input.txt 파일 열기 실패.\n");
        perror("Details");
        return -1; // 즉시 종료
    }

    // 2. output.txt 열기 시도
    copy = fopen("output.txt", "wt");
    if (copy == NULL) {
        printf("output.txt 파일 열기 실패.\n");
        perror("Details");
        // org는 열렸으므로 닫아줍니다.
        fclose(org);
        return -1; // 즉시 종료
    }

    // 3. 파일 복사 및 쓰기 오류 확인
    while (fgets(str, sizeof(str), org) != NULL) {
        // 쓰기 실패 시 즉시 루프 탈출
        if (fputs(str, copy) == EOF) {
            printf("output 파일에 쓰기 실패.\n");
            break;
        }
    }

    // 4. 복사 결과 확인 및 최종 코드 설정
    if (feof(org) != 0) {
        // EOF에 도달했고, 복사 루프가 중단되지 않았으면 성공
        printf("파일 카피 성공! (파일 끝(EOF)에 도달).\n");
        return_code = 0; // 성공
    }
    else {
        // EOF에 도달하지 못했다면 (read error 또는 fputs EOF로 인한 break) 실패
        printf("파일 카피 실패 (파일 끝(EOF)에 도달 실패).\n");
        return_code = -1; // 실패
    }

    // 5. 버퍼 플러시 및 파일 닫기 (가장 중요한 안정화 부분)
    // output 파일 버퍼를 디스크에 강제 기록합니다.
    // 앞으로는 fflush 꼭 쓰고 코드 짜야될듯?
    fflush(copy);

    // 파일들을 안전하게 닫습니다.
    fclose(org);
    fclose(copy);

    printf("최종 실패/성공 판단 (0이면 성공 -1이면 실패) : %d", return_code);
    return return_code;
}

// 위 과정을 거치고 나면 input 파일에 있는 내용이 output 파일에 그대로 복사된다.