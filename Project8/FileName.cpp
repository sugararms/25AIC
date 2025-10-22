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
    // ����� ������
    struct Fish fishes[5] = {
        {"������Ʈ", "���� �� AP è�Ǿ���?\n1. ���� 2. ����� 3. Ż��", 2, "�����̴�.", "�� ����."},
        {"�ٸ��콺", "���� �� ���Ÿ� ������ �ƴѰ���?\n1. �ֽ� 2. Ʈ����Ÿ�� 3. �̷�����", 3, "����ϱ�", "�ƽ���!"},
        {"����", "AP �������� �ƴѰ���?\n1. ���׶��ǵ��� 2. �������̻� 3. �絧�Ǹ޾Ƹ�", 1, "�����þ�!(����)", "�����þƤФ�(����)"},
        {"Ƽ��", "ž ���̳ʰ� ���Ѿ��� ������ �ƴ� ��\n1. ������ ��ų�� 2. �ڷ���Ʈ�� ���κ��Ϳ� 3. �� �θ���", 3, "������", "ž�� �ڰ��� ����."},
        {"��������", "ȥ�ڸ� ������ �ٸ� ���� è�Ǿ���?\n1. ���־ƴ� 2. ��ũ 3. ����", 3, "����!", "�� �����Ͻÿ�."}
    };

    // ���� Ƚ�� �� ���� �� �ҷ�����
    FILE* log = fopen("log.txt", "a+"); // append + read
    int total = 0, correct = 0;
    char line[100];
    rewind(log);
    while (fgets(line, sizeof(line), log)) {
        if (line[0] == 'O') correct++;
        if (line[0] == 'O' || line[0] == 'X') total++;
    }

    printf("%d��° �����Դϴ�!!\n", total + 1);
    printf("����� %d/%d\n\n", correct, total);

    // ����� �Է�
    char yn;
    while (1) {
        printf("� ������ (Y/N) > ");
        yn = _getch();
        printf("%c\n", yn);

        if (yn == 'Y' || yn == 'y') break;
        else if (yn == 'N' || yn == 'n') {
            printf("������ �����մϴ�.\n");
            fclose(log);
            return 0;
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }

    // 500ms���� . ��� (�� 5��)
    for (int i = 0; i < 5; i++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    printf("\n");

    // ������� ���� �޽��� ���
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("������ �Դ�!!!\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �������

    // ���� �����
    srand((unsigned int)time(NULL));
    int index = rand() % 5;
    struct Fish f = fishes[index];

    // ����
    printf("%s : %s\n", f.name, f.talk);
    printf("���� ��ȣ �Է� > ");
    int user;
    scanf("%d", &user);

    // ��� ���
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
