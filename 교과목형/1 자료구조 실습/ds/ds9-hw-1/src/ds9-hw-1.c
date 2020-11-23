#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

typedef enum {
			lparen, rparen, plus, minus, times, divide, mod, eos, operand
			} precedence;

int stackEmpty()
{
	printf("EMPTY\n");
	exit(EXIT_FAILURE);
}

int pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

void stackFull()
{
	printf("FULL\n");
	exit(EXIT_FAILURE);
}

void push(char *symbol)
{
	if (top == MAX_STACK_SIZE-1)
		stackFull();
	stack[++top] = symbol;
}

precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++]; // 한칸씩 문장을 읽어와
	switch(*symbol)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '*' : return times;
		case '/' : return divide;
		case '%' : return mod;
		case '\0' : return eos;
		default : return operand;
	}
}

int eval(void)
{
	precedence token;
	char symbol;
	int n = 0;
	token = getToken(&symbol, &n);

	top = -1; //생략가능
	int op1, op2;

	while (token != eos){
		if (token == operand)
			push(symbol-'0'); //문자열 정수화
		else
		{
			op2 = pop();
			op1 = pop();
			switch(token)
			{
				case plus: push(op1+op2);
							break;
				case minus: push(op1-op2);
							break;
				case times: push(op1*op2);
							break;
				case divide: push(op1/op2);
							break;
				case mod: push(op1%op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop(); //최종결과 넘겨주기
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");

	fscanf(fp, "%s", expr);
	printf("expr : %s\n", expr);

	printf("rslt : %d", eval());

	fclose(fp);
	return 0;
}
