#include <stdio.h>
#include<stdlib.h>

int LSR_gossip(int Gender)
{
	Gender = 1;
	printf("�������� ���̾�..");
	return 0;
}

int wife_Command(int *Gender)
{
	Gender[0] = 1;
	printf("\n������: �� ���úη� ���̾�");
	return 0;
}












int main()
{
	int* ES_maum;
	ES_maum = (int*)malloc(sizeof(int) * 2);

	/*[0]�����ϴ� ����,
	* 0:����
	  1:����
	  2:��Ÿ
	[1] ���� ����
	  0:����
	  1:����
	*/
	ES_maum[0] = 0;
	ES_maum[0] = 1;

	//LSR_gossip(ES_maum[0]);
	wife_Command(ES_maum);

	if (ES_maum[0] == 1)
	{
		printf("\n�״� ���̿���");
	}

	else if (ES_maum[0] == 0)
	{
		printf("\n�״� ������ ����Ѵ�");
	}

	if (ES_maum[1] == 1)
	{
		printf("�״� ������̴�");
	}

	else if (ES_maum[1] == 0)
	{
		printf("�״� ������� �ƴϴ�");
	}


	free(ES_maum);
	return 0;
}