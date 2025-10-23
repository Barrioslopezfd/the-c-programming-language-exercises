#include <stdio.h>

#define UNIT "|"

int main() 
{
	int charr[26]={0};
	char c;

	while ((c=getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			charr[c-'a']++;
		}
		if (c >= 'A' && c <= 'Z')
		{
			charr[c-'A']++;
		}
	}

	int len = sizeof(charr) / sizeof(charr[0]);
	for(int i=0; i<len; i++)
	{
		printf("%c ", i+'a');
		for(int j=charr[i]; j > 0; j--)
		{
			printf(UNIT);
		}
		printf("\n");
	}
}

