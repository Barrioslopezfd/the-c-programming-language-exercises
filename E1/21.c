#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define TABSTOP 8
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

	int resto, c;
	int i = 0;
	int z = 0;
	int aux = 0;
	int blanks = 0;
	int tabs = 0;
	int col = 0;
	while (i < MAX_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
	{
		if (c == BLANK)
		{
			blanks++;
			i++;
			continue;
		}

		while (blanks > 1)
		{
			aux = TABSTOP - (col % TABSTOP);
			if (aux > 0)
			{
				line[z] = TAB;
				col = col + 8;
				z++;
				blanks = blanks - aux;
			}

			if ((blanks / TABSTOP) > 0)
			{
				for (int j = 0; j < blanks / TABSTOP; j++)
				{
					line[z] = TAB;
					col++;
					z++;
				}
				blanks = blanks - ((blanks / TABSTOP) * TABSTOP);
				if (blanks > 0)
				{
					for (int j = 0; j < blanks; j++)
					{
						line[z] = BLANK;
						col++;
						z++;
					}
					blanks = 0;
				}
			}
		}
		if (blanks == 1) 
		{
			line[z] = BLANK;
			z++;
			col++;
			i++;
		}
	
		line[z] = c;
		if (c == TAB)
			col = col + 8;
		else
			col++;
		z++;
		blanks = 0;

		i++;
	}
	return z;
}
