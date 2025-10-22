#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

struct Fish {
    const char* name;
    const char* talk;
    int answer;
    const char* talk_O;
    const char* talk_X;
};


int main() {
    // 물고기 데이터
    struct Fish fishes[5] = {
        {"말파이트", "다음 중 AP 챔피언은?\n1. 제드 2. 르블랑 3. 탈론", 2, "정답이다.", "넌 졌다."},
        {"다리우스", "다음 중 원거리 딜러가 아닌것은?\n1. 애쉬 2. 트리스타나 3. 이렐리아", 3, "대단하군", "아쉽군!"},
        {"가렌", "AP 아이템이 아닌것은?\n1. 스테락의도전 2. 내셔의이빨 3. 루덴의메아리", 1, "데마시아!(정답)", "데마시아ㅠㅠ(오답)"},
        {"티모", "탑 라이너가 지켜야할 덕목이 아닌 것\n1. 점멸은 솔킬용 2. 텔레포트는 라인복귀용 3. 갱 부르기", 3, "으흐흐", "탑의 자격이 없다."},
        {"마스터이", "혼자만 성질이 다른 정글 챔피언은?\n1. 세주아니 2. 자크 3. 샤코", 3, "정답!", "더 생각하시오."}
    };

    // 게임 횟수 및 정답 수 불러오기
    FILE* log = fopen("log.txt", "a+"); // append + read
    int total = 0, correct = 0;
    char line[100];
    rewind(log);
    while (fgets(line, sizeof(line), log)) {
        if (line[0] == 'O') correct++;
        if (line[0] == 'O' || line[0] == 'X') total++;
    }

    printf("%d번째 게임입니다!!\n", total + 1);
    printf("정답률 %d/%d\n\n", correct, total);

    // 사용자 입력
    char yn;
    while (1) {
        printf("찌를 던진다 (Y/N) > ");
        yn = _getch();
        printf("%c\n", yn);

        if (yn == 'Y' || yn == 'y') break;
        else if (yn == 'N' || yn == 'n') {
            printf("게임을 종료합니다.\n");
            fclose(log);
            return 0;
        }
        else {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    }

    // 500ms마다 . 출력 (총 5개)
    for (int i = 0; i < 5; i++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    printf("\n");

    // 녹색으로 입질 메시지 출력
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("입질이 왔다!!!\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 원래대로

    // 랜덤 물고기
    srand((unsigned int)time(NULL));
    int index = rand() % 5;
    struct Fish f = fishes[index];

    // 퀴즈
    printf("%s : %s\n", f.name, f.talk);
    printf("정답 번호 입력 > ");
    int user;
    scanf("%d", &user);

    // 결과 출력
    if (user == f.answer) {
        printf("%s\n", f.talk_O);
        fprintf(log, "%s\nO\n", f.name);
    }
    else {
        printf("%s\n", f.talk_X);
        fprintf(log, "%s\nX\n", f.name);
    }

    fclose(log);
    return 0;
}
