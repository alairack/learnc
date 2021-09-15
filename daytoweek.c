/*输入天数，把天数转换为周数和天数*/
#include <stdio.h>
#define week 7

int main(void)
{
	int input_days;
	int weeks;
	int days;
	while (1)
	{
		printf("please input a number\n");
		if (scanf("%d", &input_days) <= 0)
		{
			printf("do not input error char!\n");
			break;
		}
		if (input_days <= 0)
			break;
		else
		{
			weeks = input_days / week;
			days = input_days % week;
			printf("%d days are %d weeks, %d days\n", input_days, weeks, days);
		}
	}
	return 0;
}