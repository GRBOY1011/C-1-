#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>                 

int main(void) {

    char name[10];                 // 이름을 저장할 문자열 배열(최대 9글자 + NULL문자)
    int age;                       // 나이를 저장할 정수 변수

    FILE* fp = fopen("student.txt", "wt");  // student.txt 파일을 쓰기 모드(text)로 엶 (없으면 새로 생성, 있으면 덮어씀)

    for (int i = 0; i < 3; i++) {           // 3명의 학생 정보를 입력받기 위한 반복문
        printf("다음 순서로 입력 (name age) :");  // 사용자에게 입력 안내 출력
        scanf("%s %d", name, &age);          // 이름(문자열)과 나이(정수)를 입력받음
        getchar();                          // 입력 버퍼에 남아 있는 개행 문자('\n') 제거 (다음 입력 오류 방지)
        fprintf(fp, "%s %d\n", name, age);   // 입력받은 데이터를 파일에 "이름 나이" 형태로 기록하고 줄바꿈
    }

    fclose(fp);                    // 파일을 닫고 버퍼?의 내용을 디스크에 저장
    return 0;                      // 프로그램 정상 종료
}
// 위 과정을 거치면 student.txt 파일에 세 명의 (이름 나이) 세트가 한줄씩 적혀있다.