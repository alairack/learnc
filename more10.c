/*����һ����������ӡ�ȸ������10������*/
#include <stdio.h>

int main(void)
{	
	int num;
	int count;
	printf("please input a number\n");
	scanf("%d", &num);
	for (count = 1; count < 12; count++, num++)
	{
		printf("%d  ", num);
	}
	return 0;
}