#include <stdio.h>

#define UNIT "|"

int main() 
{
	int char_count=0;
	int charr[10]={0};
	char last_char, c;

	while ((c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (char_count > 0)
			{
				charr[char_count-1]++;
				char_count=0;
			}
		} else {
			char_count++;
		}
	}

	int len = sizeof(charr) / sizeof(charr[0]);
	for(int i=0; i<len; i++)
	{
		printf("%2d ", i+1);
		for(int j=charr[i]; j > 0; j--)
		{
			printf(UNIT);
		}
		printf("\n");
	}
}

