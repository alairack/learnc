#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("please enter parameter!\n");
		return 3;
	}
	int ch;
	FILE* src;
	FILE* export;
	const char convert_ch[10] = {' ', '.', '`', ':', '~', '*', '=', '&', '%', '#'};
	src = fopen(argv[1], "rb");
	export = fopen("export.txt", "w");
	if (src == NULL)
	{
		printf("open file is failed!\n");
		exit(1);
	}
	ch = getc(src);
	while (ch != EOF && export != NULL)
	{
		printf("%c", convert_ch[ch - 48]);
		putc(convert_ch[ch - 48], export);
		ch = getc(src);
		while ((ch == 10) || (ch == 32) || (ch == 13))    /*如获取到换行符、空格、回车键则获取下一个*/
		{
			if (ch == 10)                         /*注意：windows行末使用 /r/n */
			{
				putc(10, export);
			}
			ch = getc(src);
		}
		if (ch == EOF)                   /*文件关闭及相关提示*/
		{
			if (fclose(src) != 0 || fclose(export) != 0)
			{
				printf("\nError in closing files\n");
				exit(2);
			}
			printf("\nclose file comlete!\n");
			exit(0);
		}
	}
}
