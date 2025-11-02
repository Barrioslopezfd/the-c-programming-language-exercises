#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getln(line, MAXLINE)) > 0)
	{
        if (len > 0) {
			printf("%d - \"%s\"\n", len, line);
        }
	}

    return 0;
}

int getln(char s[], int maxline)
{
    int c, i;
	int isblank = 0;
	int in = 0;

	memset(s, 0, sizeof(s));
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i > 0 && (s[i-1] != ' ' && s[i-1] != '\t') && (c == ' ' || c == '\t'))
		{
			isblank = i;
		}
		else 
		{
			isblank = 0;
		}
		s[i] = c;
	}

	printf("%d", isblank);
	if (isblank > 0)
	{
		for (int j = isblank; j < maxline; ++j)
		{
			s[j] = '\0';
		}
	}

    s[i] = '\0';
    return i;
}

