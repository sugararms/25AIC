#include <stdio.h>
#include <stdlib.h>

#define Key_a 97    // 'a'�� ASCII �ڵ� ��
#define Key_z 122   // 'z'�� ASCII �ڵ� ��

// �� ������ ���� ���� �ٲٴ� �Լ�
void swap(char* a, char* b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

// ���� ���� �Լ�: �迭 arr�� ũ�� n��ŭ �������� ����
void bubbleSort(char arr[], int n)
{
    int i, j;   // �ݺ��� ����

    // ��ü �迭�� n-1�� �ݺ��ϸ鼭 ����
    for (i = 0; i < n - 1; i++)
    {
        // ���� ���ĵ��� ���� �κ��� ������ �� ���Ҿ� ��
        for (j = 0; j < n - i - 1; j++)
        {
            // ���� ���� ���Ұ� ���� ���Һ��� ũ�� ��ġ�� �ٲ�
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    // ���ĺ� �ҹ��� ������ŭ ũ�� ����
    char random[Key_z - Key_a + 1];

    int i = 0;

    // �迭 �ʱ�ȭ (��� ���� 0���� ����)
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        random[i] = 0;
    }

    // ���ĺ��� ������ ��ġ�� ��ġ�ϴ� ����
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        while (1)
        {
            int rand_index = rand() % (Key_z - Key_a + 1);  // 0~25 ���� ���� ����
            if (random[rand_index] == 0)                     // �ش� ��ġ�� ���������
            {
                random[rand_index] = (char)(i + Key_a);     // i�� �����ϴ� ���ĺ� ����
                break;                                      // ���� ���ڷ� �̵�
            }
        }
    }

    // ���ݱ��� �����ϰ� ���� �迭�� ���� ���ķ� �������� ����
    bubbleSort(random, Key_z - Key_a + 1);

    // ��� ��� - �ε����� ���ĺ� ����
    printf("\tindex\talphabet\n");
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        printf("\t%d\t%c\n", i, random[i]);
    }

    return 0;
}
