#include <stdio.h>
#include<stdlib.h>

int LSR_gossip(int Gender)
{
	Gender = 1;
	printf("교수님은 게이야..");
	return 0;
}

int wife_Command(int *Gender)
{
	Gender[0] = 1;
	printf("\n와이프: 넌 오늘부로 게이야");
	return 0;
}












int main()
{
	int* ES_maum;
	ES_maum = (int*)malloc(sizeof(int) * 2);

	/*[0]좋아하는 성별,
	* 0:여자
	  1:남자
	  2:기타
	[1] 애인 유무
	  0:없음
	  1:있음
	*/
	ES_maum[0] = 0;
	ES_maum[0] = 1;

	//LSR_gossip(ES_maum[0]);
	wife_Command(ES_maum);

	if (ES_maum[0] == 1)
	{
		printf("\n그는 게이였다");
	}

	else if (ES_maum[0] == 0)
	{
		printf("\n그는 여성을 사랑한다");
	}

	if (ES_maum[1] == 1)
	{
		printf("그는 사랑꾼이다");
	}

	else if (ES_maum[1] == 0)
	{
		printf("그는 사랑꾼이 아니다");
	}


	free(ES_maum);
	return 0;
}