#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define TABSTOP 8

int getln(char line[]);

int main()
{
	int len;
	char line[MAX_SIZE];
	while ((len = getln(line)) > 0)
	{
		printf("\"%s\"\n", line);
	}
}

int getln(char line[])
{
	memset(line, 0, MAX_SIZE);

	int resto, c;
	int i = 0;
	while (i < MAX_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
	{
		if ( c == '\t')
		{
			resto = TABSTOP - (i % TABSTOP);
			for (int j = 0; j < resto; j++)
			{
				line[i] = '@';
				++i;
			}
		}
		else
		{
			line[i] = c;
			++i;
		}
	}
	return i;
}
