#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// infix to postfix
typedef enum { lparen, rparen, and, or, not, eos, operand } logical;
int isp[] = { 0, 19, 12, 11, 13, 0};
int icp[] = { 20, 19, 12, 11, 13, 0};

// stack

void push(logical item);
void stackFull();
logical pop();
logical stackEmpty();

logical stack[MAX_STACK_SIZE];
int top = -1;

// infix expression
char expr[81];

void postfix(void);
logical getToken(char *symbol, int *n);
void printToken(logical);

FILE *fp;

int main(void)
{
	fp = fopen("input.txt", "r");

	fgets(expr, 80, fp); // input infix expression

	printf("<<<<<<<<<< infix to postfix >>>>>>>>>>>>>\n");
	printf("infix expression\t: %s\n", expr);
	printf("postfix expression\t: ");

	postfix();	// infix to postfix

	fclose(fp);
	return 0;
}

void postfix(void)
{
	char symbol;
	logical token;
	int n = 0;
	top = -1;
	stack[++top] = eos; //eos를 먼저 넣어야 편했었지

	for ( token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if ( token == operand )
		{
			printf("%c", symbol);
		}
		else if ( token == rparen)
		{
			while (stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else
		{
			while ( isp[stack[top]] >= icp[token] )
				printToken(pop());
			push(token);
		}
	}

	while ( ( token = pop()) != eos )
		printToken(token);
	printf("\n");
}

logical getToken(char *symbol, int *n)
{
	*symbol = expr[ (*n)++ ];
	switch ( *symbol)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '&' : return and;
		case '|' : return or;
		case '~' : return not;
		case '\0' : return eos;
		default : return operand;
	}
}

void printToken(logical pre)
{
	switch(pre)
	{
		// in postfix expression, there are no parentheses
		case and	:	printf( "%c", '&' ); break;
		case or		:	printf( "%c", '|' ); break;
		case not	:	printf( "%c", '~' ); break;
		//case eos	:	printf( "%c", '\0' );	fprintf( fpP, "%c", '\0' );	break;
	}
}

/////////////////////// stack operations ///////////////////////////////////
logical pop()
{
	if ( top == -1 )
		return stackEmpty();
	return stack[top--];
}
logical stackEmpty()
{
	logical item;
	item = operand;  // error key!
	return item;
}
void push(logical item)
{
	if ( top >= MAX_STACK_SIZE-1 )
		stackFull();
	stack[++top] = item;
}
void stackFull()
{
	fprintf(stderr, "stack is full, cannot add int\n");
	exit(EXIT_FAILURE);
}
