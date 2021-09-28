/*转换时间工具：1.把秒转换为 x天x时x分x秒 ，通过控制台运行时在文件名后加上 - second 参数， 第二个参数输入 秒数
                2.把分钟转换为 x天x时x分x秒 ， 通过通过控制台运行时在文件名后加上 - minute 参数， 第二个参数输入 分钟数*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define AN_HOUR_OF_MINUTES 60
#define A_DAY_OF_HOURS 24
#define A_MINUTE_OF_SECONDS 60
#define AN_HOUR_OF_SECONDS 3600

int main(int argc, char *argv [])
{
	if (argc < 2)
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
	}
	else
	{
		if (argc == 2)
		{
			printf("please input value !");
		}
		else
		{
			if (strcmp(argv[1], "-second") == 0)
			{
				long input_seconds = atoi(argv[2]);
				int days = input_seconds / (A_DAY_OF_HOURS * AN_HOUR_OF_SECONDS);
				int hours = (input_seconds % (A_DAY_OF_HOURS * AN_HOUR_OF_SECONDS)) / (AN_HOUR_OF_SECONDS);
				int minutes = (input_seconds - (days * A_DAY_OF_HOURS + hours) * AN_HOUR_OF_SECONDS) / A_MINUTE_OF_SECONDS;
				int sec = input_seconds - (days * A_DAY_OF_HOURS + hours) * AN_HOUR_OF_SECONDS - minutes * A_MINUTE_OF_SECONDS;
				printf("%d secoonds has %d days %d hours %d minutes %d seconds ", input_seconds, days, hours, minutes, sec);
			}
			if (strcmp(argv[1], "-hour") == 0)
			{
				int input_hour = atoi(argv[2]);
				int day = input_hour / A_DAY_OF_HOURS;
				int hour = (input_hour % A_DAY_OF_HOURS);
			}
			if (strcmp(argv[1], "-minute") == 0)
			{
				int input_minutes = atoi(argv[2]);
				int days = input_minutes / (A_DAY_OF_HOURS * AN_HOUR_OF_MINUTES);
				int hours = input_minutes % (A_DAY_OF_HOURS * AN_HOUR_OF_MINUTES) / AN_HOUR_OF_MINUTES;
				int minutes = input_minutes - days * A_DAY_OF_HOURS * AN_HOUR_OF_MINUTES - hours * AN_HOUR_OF_MINUTES;
				printf("%d minutes has %d days %d hours %d minutes ", input_minutes, days, hours, minutes);
			}
			else
			{
				printf("unknown parameter!");
				exit(2);
			}
		}
	}
	return 0;
}