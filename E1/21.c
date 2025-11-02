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
		clear(clean, line, len);
		// printf("\"%s\"\n", clean);
		printf("\"");
		for (int i = 0; i < (sizeof(line) - sizeof(char)); i++)
		{
			if (line[i] == '\0') { printf("\\0"); }
			else { putchar(line[i]); }
			if ((i % 8) == 7) { printf(" | "); }
		}
		printf("\n");
		printf(" < that should be printed: %d\n", debug_counter);
		for (int i = 0; i < (sizeof(clean) - sizeof(char)); i++)
		{
			if (clean[i] == '\0') { printf("\\0"); }
			else { putchar(clean[i]); }
			if ((i % 8) == 7) { printf(" | "); }
		}
		printf("\"");
		printf("\n");
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
	int last = 0;
	int mult = 0;

	while (i < MAX_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
	{
		if (c == BLANK)
		{
			blanks++;
			if ( (i % TABSTOP) == 7 )
			{
				if ((blanks % TABSTOP) == 0) { mult++; }
				printf(" i=%d - z=%d - blanks=%d - last=%d - mult=%d \n", i, z, blanks, last, mult);
				z = i-(blanks+last);
				printf("\n z=%d\n", z);
				last = z;
				line[last + 1]='>';
				debug_counter++;
				blanks = 0;
			}
		}
		else
		{
			line[z]=c;
			mult = 0;
		}
		i++;
		z++;
	}
	return z;
}

void clear(char to[],char from[], int len)
{
	memset(to, 0, MAX_SIZE);
	int lastchar;
	int z = 0;
	for (int i = 0; i < len; i++)
	{
		if (from[i] != '\0') { 
			to[z] = from[i];	
			++z;
			lastchar = z;
		}
	}
	putchar(to[lastchar]);
	to[lastchar] = '\0';
}
