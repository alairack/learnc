/*��һ���ں�һЩ0~9���֣����ּ��ÿո�������ı��ļ�������ͼ��ʾ���������ִ�Сת������Ӧ��С���ַ������������׼����͵�ǰĿ¼��"output.txt"�ļ��С��Դ�������һ��"ͼƬ"��
����ʱ����Ҫ��Ҫת�����ı��ļ�������exeͬ����Ŀ¼�£���һ���������������ļ���*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char convert(char* former)              
{
	switch (*former)
	{
	case '0':
		return ' ';
	case '1':
		return '.';
	case '2':
		return '`';
	case '3':
		return ':';
	case '4':
		return '~';
	case '5':
		return '*';
	case '6':
		return '=';
	case '7':
		return '&';
	case '8':
		return '%';
	case '9':
		return '#';
	default: return 1;
	}
}



int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("please enter parameter!\n");
		return 1;
	}
	int ch;
	int x = 0;
	int y = 0;
	int a_line_word = 0;
	int line_num = 0;
	FILE* fp;
	FILE* output;
	fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		printf("open file is failed!\n");
		exit(2);
	}
	ch = getc(fp);
	while (fp != NULL)
	{
		if (ch == 10)
		{
			line_num++;
		}
		if (line_num == 0)
		{
			a_line_word++;
		}
		ch = getc(fp);
		while (ch == 32 || ch == 13)
		{
			ch = getc(fp);
		}
		if (feof(fp) != 0)
		{
			line_num++;
			break;
		}
	}
	int read_file[line_num][a_line_word];
	char save_ch[line_num][a_line_word][6];
	fseek(fp, 0L, SEEK_SET);
	ch = getc(fp);
	output = fopen("output.txt", "w");
	while (feof(fp) == 0)
	{
		if (fp == NULL)
		{
			printf("read file error!please check the file!\n");
			break;
		}
		if (y == a_line_word)
		{
			if (x == line_num)
			{
				if (fclose(fp) != 0)
					printf("Error in closing files\n");
				printf("\n END OF ARRAY\n");
				break;
			}
			x++;
			y = 0;
		}
		read_file[x][y] = ch;
    	*(save_ch[x][y]) = (char)read_file[x][y];
		*(save_ch[x][y]) = convert(save_ch[x][y]);   
		ch = getc(fp);
		while ((ch == 10) || (ch == 32) || (ch == 13))    /*���ȡ�����з����ո񡢻س������ȡ��һ��*/
		{
			ch = getc(fp);
		}
		if (ferror(fp) != 0)
		{
			printf("error!\n");
		}
		if (feof(fp) != 0)
		{
			printf("complete read file\n");
		}
		y++;
	}

	x = 0;
	y = 0;
	while ((x < line_num) && (output != NULL))           /*��ѭ����ת����������ӡ����׼����ʹ洢���ı��ļ�*/
	{
		if (y == a_line_word)
		{
			putc(10, output);
			y = 0;
			x++;
			if (x == line_num)
			{
				fclose(output);
				break;
			}
		}
		printf("%c", *(save_ch[x][y]));
		putc(*(save_ch[x][y]), output);
		y++;
	}
	return 0;
}

