#include <stdio.h>
#include <stdlib.h>

#define Key_a 97    // 'a'의 ASCII 코드 값
#define Key_z 122   // 'z'의 ASCII 코드 값

// 두 문자의 값을 서로 바꾸는 함수
void swap(char* a, char* b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

// 버블 정렬 함수: 배열 arr를 크기 n만큼 오름차순 정렬
void bubbleSort(char arr[], int n)
{
    int i, j;   // 반복문 변수

    // 전체 배열을 n-1번 반복하면서 정렬
    for (i = 0; i < n - 1; i++)
    {
        // 아직 정렬되지 않은 부분을 인접한 두 원소씩 비교
        for (j = 0; j < n - i - 1; j++)
        {
            // 만약 현재 원소가 다음 원소보다 크면 위치를 바꿈
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    // 알파벳 소문자 개수만큼 크기 설정
    char random[Key_z - Key_a + 1];

    int i = 0;

    // 배열 초기화 (모든 원소 0으로 세팅)
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        random[i] = 0;
    }

    // 알파벳을 랜덤한 위치에 배치하는 루프
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        while (1)
        {
            int rand_index = rand() % (Key_z - Key_a + 1);  // 0~25 사이 난수 생성
            if (random[rand_index] == 0)                     // 해당 위치가 비어있으면
            {
                random[rand_index] = (char)(i + Key_a);     // i에 대응하는 알파벳 저장
                break;                                      // 다음 문자로 이동
            }
        }
    }

    // 지금까지 랜덤하게 섞인 배열을 버블 정렬로 오름차순 정렬
    bubbleSort(random, Key_z - Key_a + 1);

    // 결과 출력 - 인덱스와 알파벳 문자
    printf("\tindex\talphabet\n");
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        printf("\t%d\t%c\n", i, random[i]);
    }

    return 0;
}
