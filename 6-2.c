#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 10000   // 명령의 최대 개수 (스택 크기 제한)

int stack[MAX];     // 스택을 저장할 배열
int top_index = -1; // 스택의 맨 위 인덱스 (비어있으면 -1)

// push 함수: 스택의 맨 위에 데이터 추가
void push(int x) {
    stack[++top_index] = x; // top_index를 1 증가시키고 그 위치에 x 저장
}

// pop 함수: 스택의 맨 위 데이터를 꺼내고 반환
int pop() {
    if (top_index == -1)    // 스택이 비어있으면
        return -1;
    return stack[top_index--]; // top 위치의 값을 반환하고 인덱스를 1 감소
}

// size 함수: 스택에 들어있는 원소의 개수 반환
int size() {
    return top_index + 1;   // top이 -1이면 0, 0이면 1개, …
}

// empty 함수: 스택이 비어있으면 1, 아니면 0
int empty() {
    return (top_index == -1) ? 1 : 0;
}

// top 함수: 스택의 맨 위 값 반환
int top() {
    if (top_index == -1)
        return -1;
    return stack[top_index];
}

int main() {
    int n;                // 명령 개수
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char cmd[10];     // 명령어 저장용 문자열
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(cmd, "top") == 0) {
            printf("%d\n", top());
        }
    }

    return 0;
}
// 명령어 10개로 해서 실행시켰더니 잘 작동되었다. Last in First Out 방식인거 알고 있으면 될 듯