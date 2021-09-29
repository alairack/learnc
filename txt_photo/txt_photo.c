#include <stdio.h>
#include <stdlib.h>


char * configuration(void)
{
	FILE* config;
	config = fopen("config.txt", "r");
	if (config == NULL)
	{
		static char convert_ch[14] = { ' ', '.', '`', ':', '~', '*', '=', '&', '%', '#' };
		FILE* write_config = fopen("config.txt", "w");
		for (int x = 0; x < 10; x++)
			fprintf(write_config, "%d %c\n", x, convert_ch[x]);
		fclose(write_config);
		return convert_ch;
	}
	else
	{
		static char convert_ch[15];
		char line[12];
		while (fgets(line, 10, config) != NULL)
		{
			convert_ch[line[0] - '0'] = line[2];                              /*  -'0' 方法把char转换为int */
		}
		fclose(config);
		return convert_ch;
	}

}

int main(int argc, char* argv[])
{
	if (argc < 2 || argc > 6)
	{
		printf("please check parameter!\n");
		return 3;
	}
	const char* convert_ch = configuration();
	int ch;
	FILE* src;
	FILE* export;
	src = fopen(argv[1], "rb");
	export = fopen("export.txt", "w");
	if (export == NULL)
	{
		printf("export is failed!\n");
		exit(4);
	}
	if (src == NULL)
	{
		printf("open source-file is failed!\n");
		exit(1);
	}
	ch = getc(src);
	while (ch != EOF)
	{
		printf("%c", convert_ch[ch-48]);                      
		putc(convert_ch[ch-48], export);
		ch = getc(src);
		while (ch == 32 || ch == 13 || ch == 10)    /*如获取到空格则获取下一个*/
		{
			if (ch == 10)
			{
				putc(10, export);
			}
			if (ch == 32)                      /*如果是空格则直接打印和保存*/
			{
				putc(32, export);
				putchar(32);
			}
			ch = getc(src);
		}
	}
	if (fclose(src) != 0)                /*文件关闭及相关提示*/
	{
		printf("\nError in closing source-file \n");
		exit(2);
	}
	if (fclose(export) != 0)
	{
		printf("\nError in closing output-file \n");
		exit(2);
	}
	printf("\nclose file comlete!\n");
	exit(0);
}
