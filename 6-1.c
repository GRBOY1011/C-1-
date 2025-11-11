#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 10000  // 명령 수 최대값 (큐 크기 제한)

int queue[MAX];    // 큐를 저장할 배열
int front = 0;     // 큐의 맨 앞 인덱스
int rear = 0;      // 큐의 맨 뒤 다음 위치 인덱스 (삽입 위치)

// push 함수: 큐의 맨 뒤에 데이터 추가
void push(int x) {
    queue[rear++] = x;   // rear 위치에 값 저장 후 rear 증가
}

// pop 함수: 큐의 맨 앞 데이터를 꺼내고 제거
int pop() {
    if (front == rear)   // 큐가 비어있는 경우
        return -1;
    return queue[front++];  // front 위치의 값을 반환하고 front 증가
}

// size 함수: 큐에 들어있는 데이터 개수 반환
int size() {
    return rear - front;
}

// empty 함수: 큐가 비어있으면 1, 아니면 0
int empty() {
    return (front == rear) ? 1 : 0;
}

// front 함수: 큐 맨 앞의 값 반환
int front_value() {
    if (front == rear)   // 비었으면 -1
        return -1;
    return queue[front];
}

// back 함수: 큐 맨 뒤의 값 반환
int back_value() {
    if (front == rear)   // 비었으면 -1
        return -1;
    return queue[rear - 1];
}

int main() {
    int n;
    scanf("%d", &n);     // 명령의 개수 입력

    for (int i = 0; i < n; i++) {
        char cmd[10];    // 명령어 문자열 저장
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {   // push X
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
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", front_value());
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", back_value());
        }
    }

    return 0;
}
// 명령어 10개로 해서 작동시켜봤는데 잘 작동되었다