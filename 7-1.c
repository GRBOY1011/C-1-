#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100
#define FILENAME "todo_list.txt"

typedef struct {
    char task[MAX_LENGTH];     // 할 일 내용
    int completed;             // 완료 여부
    char date[11];             // 사용자 입력 예정일
    char added_time[20];       // 자동 기록: 추가한 시간
    char completed_time[20];   // 자동 기록: 완료 시간
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;


// 현재 시간 문자열 반환 (HH:MM)
void getCurrentTime(char* buffer) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    sprintf(buffer, "%02d:%02d", t->tm_hour, t->tm_min);
}


// 파일 불러오기
void loadTasks() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) return;

    while (fscanf(file, "%d %10s %19s %19s %[^\n]",
        &tasks[task_count].completed,
        tasks[task_count].date,
        tasks[task_count].added_time,
        tasks[task_count].completed_time,
        tasks[task_count].task) == 5)
    {
        task_count++;
    }
    fclose(file);
}


// 파일 저장
void saveTasks() {
    FILE* file = fopen(FILENAME, "w");
    if (!file) return;

    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d %s %s %s %s\n",
            tasks[i].completed,
            tasks[i].date,
            tasks[i].added_time,
            tasks[i].completed_time,
            tasks[i].task);
    }

    fclose(file);
}


// 할 일 추가
void addTask() {
    if (task_count >= MAX_TASKS) {
        printf("더 이상 추가할 수 없습니다.\n");
        return;
    }

    getchar();

    printf("새로운 할 일: ");
    fgets(tasks[task_count].task, MAX_LENGTH, stdin);
    tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = '\0';

    printf("완료 날짜 (YYYY-MM-DD): ");
    scanf("%10s", tasks[task_count].date);

    // 추가한 시간 자동 저장
    getCurrentTime(tasks[task_count].added_time);

    strcpy(tasks[task_count].completed_time, "-");  // 아직 완료 안됨
    tasks[task_count].completed = 0;

    printf("할 일이 추가되었습니다! (%s에 추가됨)\n", tasks[task_count].added_time);

    task_count++;
}


// 목록 출력
void displayTasks() {
    if (task_count == 0) {
        printf("할 일이 없습니다!\n");
        return;
    }

    printf("\n===== TODO List =====\n");

    for (int i = 0; i < task_count; i++) {
        printf("%d. [%s] %s (완료 기한: %s) (추가: %s)",
            i + 1,
            tasks[i].completed ? "X" : " ",
            tasks[i].task,
            tasks[i].date,
            tasks[i].added_time);

        if (tasks[i].completed)
            printf(" (완료: %s)", tasks[i].completed_time);

        printf("\n");
    }
}


// 삭제
void deleteTask() {
    int num;
    displayTasks();
    if (task_count == 0) return;

    printf("삭제할 할 일 번호: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    for (int i = num - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;

    printf("삭제되었습니다!\n");
}


// 완료 체크
void completeTask() {
    int num;
    displayTasks();
    if (task_count == 0) return;

    printf("완료할 할 일 번호: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    tasks[num - 1].completed = 1;

    // 완료 시간 자동 기록
    getCurrentTime(tasks[num - 1].completed_time);

    printf("할 일이 완료되었습니다! (%s에 완료됨)\n",
        tasks[num - 1].completed_time);
}



// 메인
int main() {
    int choice;

    loadTasks();

    while (1) {
        printf("\n===== TODO MENU =====\n");
        printf("1. 할 일 추가\n");
        printf("2. 할 일 삭제\n");
        printf("3. 목록 보기\n");
        printf("4. 완료 체크\n");
        printf("5. 종료\n");
        printf("선택 : ");

        scanf("%d", &choice);

        switch (choice) {
        case 1: addTask(); break;
        case 2: deleteTask(); break;
        case 3: displayTasks(); break;
        case 4: completeTask(); break;
        case 5:
            saveTasks();
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}
