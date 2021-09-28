/* 把用分钟表示的时间转换成用小时和分钟表示的时间 */
#include <stdio.h>
#define AN_HOUR_OF_MINUTES 60

int main(void)
{
	int time;
	int hr;
	int min;
	while (1)
	{
		printf("please input time.\n");
		if (scanf("%d", &time) <= 0)
		{
			printf("do not input error char!\n");
			break;
		}
		if (time <= 0)
			break;
		else
		{
			hr = time / AN_HOUR_OF_MINUTES;
			min = time % AN_HOUR_OF_MINUTES;
			printf("%d h %d min\n", hr, min);
		}
	}
	return 0;
}