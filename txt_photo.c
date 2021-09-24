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
	const char convert_ch[14] = {' ', '.', '`', ':', '~', '*', '=', '&', '%', '#'};
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
