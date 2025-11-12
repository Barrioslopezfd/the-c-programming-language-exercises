#include <stdio.h>

#define MAX_SIZE 1000
#define SQUOTE '\''
#define BSLASH '\\'
#define NL '\n'
#define SLASH '/'
#define ASSTERSIK '*'

int getln(char line[]);
void clean(char line[]);

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
	clean(line);

	char c;
	char lastchar = -1;
	char lastlastchar = -1;
	char toc = -1;
	int i = 0;
	int wasjustinside = 0;
	int inside = 0;

	while (i < MAX_SIZE - 1 && (c = getchar()) != EOF)
	{
		wasjustinside = 0;
		if ( lastchar == SLASH && (c == SLASH || c == ASSTERSIK) )
		{
			toc = c;
			inside = 1;
			// if we are inside we need to go back 
			// 2 characters to delete the first "/"
			// from "//" or "/*"
			i--; 
		}
		
	
		if ( inside == 1 && (( toc == SLASH && lastchar == NL ) || ( toc == ASSTERSIK && lastlastchar == ASSTERSIK && lastchar == SLASH )))
		{
			wasjustinside = 1;
			inside = 0;
		}

		if ( inside == 0 && wasjustinside != 1)
		{
			line[i] = c;
			i++;
		}

		lastlastchar = lastchar;
		lastchar = c;
	}
	return i;
}

void clean(char line[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		line[i] = '\0';
	}
}
