#define _CRT_SECURE_NO_WARNINGS    // Visual Studio에서 fopen 등 C 표준 함수?의 보안 경고를 끄기 위한 매크로
#include <stdio.h>                 // 표준 입출력 함수 선언을 포함하는 헤더 파일

int main() {                       // 메인함수 시작점
    FILE* fp = fopen("data.txt", "wt");  // "data.txt"를 텍스트 모드로 쓰기 열기(존재하면 덮어쓰기, 없으면 새로 생성)

    if (fp == NULL) {              // 파일 열기에 실패했는지 확인하는 과정
        printf("Failed to open file"); // 실패 메시지 출력(perror도 사용 가능)
        return -1;                 // 비정상 종료 코드 반환
    }

    fputc('A', fp);                // 파일에 문자 'A'를 기록
    fputc('B', fp);                // 파일에 문자 'B' 기록
    fputc('C', fp);                // 파일에 문자 'C' 기록

    fclose(fp);                    // 열어둔 파일 스트림을 닫고 버퍼를 비움
    return 0;                      // 정상 종료 코드 반환
}
// 이 과정을 거치면 data 파일에 ABC가 기록되어 나옴