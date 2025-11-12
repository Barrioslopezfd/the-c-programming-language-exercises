#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define TABSTOP 8
#define N 10
#define BLANK ' '
#define TAB '\t'

int getln(char line[]);

int main()
{
	int len;
	char line[MAX_SIZE];
	while ((len = getln(line)) > 0)
	{
		printf("%s\n", line);
	}
}

int getln(char line[])
{
	memset(line, 0, MAX_SIZE);

	int lastblank = -1;
	int word = -1;
	int c;
	int i = 0;
	while (i < MAX_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
	{

		line[i] = c;
		if (c == BLANK || c == TAB)
		{
			lastblank = i;
		}

		if ((i % N) == 0 && i > 0)
		{
			if ( lastblank < 1 )
			{
				if ( c == BLANK || c == TAB ) 
				{
					line[i] = '\n';
				}
				else
				{
					word = 1;
				}
				i++;
				continue;
			}
			if ( (c == BLANK || c == TAB) )
			{
				line[i] = '\n';
				i++;
				continue;
			}
			else
			{
				for ( int j = i; j >= lastblank; j--)
				{
					if (line[j] == BLANK)
						line[j] = '\n';
				}
				i++;
				continue;
			}
		}

		if ( word == 1 )
		{
			if ( c == BLANK || c == TAB ) 
			{
				line[i] = '\n';
			}
		}
		i++;
	}
	return i;
}
