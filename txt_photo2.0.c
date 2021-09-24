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
		while ((ch == 10) || (ch == 32) || (ch == 13))    /*���ȡ�����з����ո񡢻س������ȡ��һ��*/
		{
			if (ch == 10)                         /*ע�⣺windows��ĩʹ�� /r/n */
			{
				putc(10, export);
			}
			ch = getc(src);
		}
		if (ch == EOF)                   /*�ļ��رռ������ʾ*/
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
