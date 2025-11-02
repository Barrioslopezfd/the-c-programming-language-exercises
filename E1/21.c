#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define TABSTOP 8
#define BLANK ' '

int getln(char line[]);
void clear(char to[], char from[], int size_t);

int debug_counter = 0;

int main()
{
	int len;
	char line[MAX_SIZE];
	char clean[MAX_SIZE];
	while ((len = getln(line)) > 0)
	{
		printf(" < that should be printed: %d\n", debug_counter);
		printf("\"%s\"\n", line);
		// printf("\"");
		// for (int i = 0; i < (sizeof(line) - sizeof(char)); i++)
		// {
		// 	if (line[i] == '\0') { printf("\\0"); }
		// 	else { putchar(line[i]); }
		// 	if ((i % 8) == 7) { printf(" | "); }
		// }
		// printf("\n");
		// for (int i = 0; i < (sizeof(clean) - sizeof(char)); i++)
		// {
		// 	if (clean[i] == '\0') { printf("\\0"); }
		// 	else { putchar(clean[i]); }
		// 	if ((i % 8) == 7) { printf(" | "); }
		// }
		// printf("\"");
		// printf("\n");
	}
}

int getln(char line[])
{
	memset(line, 0, MAX_SIZE);
	debug_counter = 0;

	int c;
	int i = 0;
	int z = 0;
	int blanks=0;
	int last = -1;

	while (i < MAX_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
	{
		if (c == BLANK)
		{
			blanks++;
			if ( (i % TABSTOP) == 7 )
			{
				if (last == -1) 
				{
					last = z - blanks;
					line[last] = '>';
				}
				else
				{
					line[last + 1]='>';
					last++;
					debug_counter++;
					blanks = 0;
				}
			}
		}
		else
		{
			line[z]=c;
			last = z;
			blanks = 0;
		}
		i++;
		z++;
	}
	return z;
}
