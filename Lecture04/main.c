#include <stdio.h>      // 표준 입출력 함수 사용을 위해 포함
#include <stdlib.h>     // rand(), srand() 등 난수 생성 함수 사용을 위해 포함
#include <time.h>       // time() 함수를 사용하기 위해 포함 (랜덤 시드 초기화용)

#define num 10          // 배열 크기를 5로 정의 (코드 내에서 num을 5로 사용)

int main()             // main 함수: 프로그램 실행 시작점
{
    int a[num];        // 크기가 num(5)인 정수형 배열 a 선언

    for (int i = 0; i < num; i++)    // 0부터 num-1까지 반복하는 for문 시작
    {
        a[i] = i;                   // 배열 a의 각 요소에 인덱스 값을 저장 (0,1,2,3,4)
    }

    srand(time(NULL));              // 현재 시간을 기반으로 랜덤 시드를 초기화 (매번 다른 랜덤값 생성)

    for (int i = num - 1; i > 0; i--)  // num-1 부터 1까지 거꾸로 반복 (4,3,2,1)
    {
        int j = rand() % (i + 1);       // 0부터 i까지 랜덤한 인덱스 j 생성
        int temp = a[i];                // a[i] 값을 임시 변수 temp에 저장
        a[i] = a[j];                    // a[j] 값을 a[i] 위치로 이동
        a[j] = temp;                   // temp 값을 a[j] 위치로 이동 (두 값 위치 교환)
    }

    for (int i = 0; i < num; i++)   // 배열 a의 모든 요소를 처음부터 끝까지 반복
    {
        printf("%d ", a[i]);        // 배열 a의 i번째 요소를 출력, 공백 포함
    }
    printf("\n");                   // 출력 후 줄바꿈

    return 0;                      // 프로그램 종료 (정상 종료 신호 반환)
}
