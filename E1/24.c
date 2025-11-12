#include <stdio.h>

#define MAX_SIZE 1000
#define MAX_MSG_LEN 240
#define SLASH '/'
#define ASSTERSIK '*'
#define NL '\n'

#define DQUOTE '\"'
#define SQUOTE '\''
#define OPAREN '('
#define CPAREN ')'
#define OCURLY '{'
#define CCURLY '}'
#define OSQR '['
#define CSQR ']'

typedef struct {
	char c;
	int line;
	int column;
} Token;

typedef struct {
	Token data[MAX_SIZE];
	int size;
} Stack;

typedef struct {
	char data[MAX_SIZE][MAX_MSG_LEN];
	int size;
} Error;

int readln(Stack *s, Error *e);
void incomment(int *incom, char lastchar, char curchar, char *com);
void instring(int *instr, char curchar);
void inchar(int *inch, char curchar);
void appendbracket(char curchar, Stack *s, int line, int column);
void closebracket(char curchar, Stack *s, Error *e, int line, int column);
void initstack(Stack *s);
void pushch(Stack *s, Token tk);
char pop(Stack *s);
void initerr(Error *e);
void pusherr(Error *e, char msg[]);
int strcpy_(char to[], const char src[]);

int main()
{
	int len;
	Stack st;
	initstack(&st);
	Error err;
	initerr(&err);

	readln(&st, &err);
	for (int i = 0; i <= err.size; i++)
	{
		printf("%s\n", err.data[i]);
	}
}

int readln(Stack *st, Error *err)
{
	char lastchar, curchar, nextchar, com;
	int incom = 0;
	int instr = 0;
	int inch = 0;
	int line = 1;
	int column = 0;
	char msg[MAX_MSG_LEN];

	int i = 0;
	while (i < MAX_SIZE - 1 && nextchar != EOF)
	{
		column++;
		nextchar = getchar();
		incomment(&incom, lastchar, curchar, &com);
		instring(&instr, curchar);
		inchar(&inch, curchar);

		if ( instr && curchar == NL)
		{
			sprintf(msg, "%d:%d - invalid string", line, column);
			pusherr(err, msg);
		}			
		if (incom == 0)
		{
			appendbracket(curchar, st, line, column);
			closebracket(curchar, st, err, line, column);
		}

		if ( curchar == NL)
		{
			column = 0;
			line++;
		}
		lastchar = curchar;
		curchar = nextchar;
		i++;
	}
	return i;
}

void incomment(int *incom, char lastchar, char curchar, char *com)
{
		if (lastchar == SLASH && (curchar == SLASH || curchar == ASSTERSIK))
		{
			*com = curchar;
			*incom = 1;
		}
		if ( *incom == 1 )
		{
			if ( *com == SLASH && curchar == NL )
				*incom = 0;
			if ( *com == ASSTERSIK && lastchar == ASSTERSIK && curchar == SLASH )
				*incom = 0;
		}
}

void instring(int *instr, char curchar)
{
		if ( curchar == DQUOTE )
		{
			*instr = !*instr;
		}
}

void inchar(int *inch, char curchar)
{
	if ( curchar == SQUOTE )
	{
		*inch = !*inch;
	}
}



/* STACK FUNCTIONS */
void initstack(Stack *s)
{
	s->size = -1;
}

void pushch(Stack *s, Token tk)
{
	s->size++;
	s->data[s->size] = tk;
}

Token popch(Stack *s)
{
	return s->data[s->size--];
}
/* FIN */

/* ERROR FUNCTIONS */
void initerr(Error *e)
{
	e->size = -1;
}

void pusherr(Error *e, char msg[])
{
	e->size++;
	strcpy_(e->data[e->size], msg);
}
/* FIN */

int strcpy_(char to[], const char src[])
{
	to[MAX_MSG_LEN - 1] = '\0';
	for (int i = 0; i < MAX_MSG_LEN; i++)
	{
		to[i] = src[i];
	}
	return 1;
}

int iseq(char a, Stack *s)
{
	Token b = s->data[s->size];
	return (a == b.c);
}

void closebracket(char curchar, Stack *s, Error *e, int line, int column)
{
	char msg[MAX_MSG_LEN];

	switch (curchar) 
	{
		case CPAREN:
			if (iseq(OPAREN, s) != 1)
			{
				sprintf(msg, "%d:%d - %c left open\n", line, column, s->data[s->size].c);
				pusherr(e, msg);
			}
			popch(s);
			break;
		case CSQR:
			if (iseq(OSQR, s) != 1)
			{
				sprintf(msg, "%d:%d - %c left open\n", line, column, s->data[s->size].c);
				pusherr(e, msg);
			}
			popch(s);
			break;
		case CCURLY:
			if (iseq(OCURLY, s) != 1)
			{
				sprintf(msg, "%d:%d - %c left open\n", line, column, s->data[s->size].c);
				pusherr(e, msg);
			}
			popch(s);
			break;
	}
}


void appendbracket(char curchar, Stack *s, int line, int column)
{
	char validchars[] = { '(', '[', '{' };
	int len = sizeof(validchars) / sizeof(char);

	for (int i = 0; i < len; i++)
	{
		if (curchar == validchars[i])
		{
			Token tk;
			tk.c = curchar;
			tk.line = line;
			tk.column = column;
			pushch(s, tk);
		}
	}
}
