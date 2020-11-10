#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum { // 0 1 2 3 4 5 6 .. 에 매칭시켜주는 구조
			lparen, rparen, plus, minus, times, divide, mod, eos, operand
			} precedence;

//정적선언 - 파일내에서만 쓰도록
static int isp[]={0, 19, 12, 12, 13, 13, 13, 0}; //(는 안에 들어오면 제일 낮고
static int icp[]={20, 19, 12, 12, 13, 13, 13, 0}; //(는 밖에 있을때는 제일 높다

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

FILE *fpOut;

void stackEmpty()
{
	printf("EMPTY\n");
	exit(EXIT_FAILURE);
}

precedence pop()
{
	if (top == -1)
		stackEmpty();
	return stack[top--];
}

void stackFull()
{
	printf("FULL\n");
	exit(EXIT_FAILURE);
}

void push(precedence token)
{
	if (top == MAX_STACK_SIZE-1)
		stackFull(); //return stackFUll(); 이라면
	stack[++top] = token;
}

void printToken(precedence token)
{
	switch(token)
	{
		case plus : printf("+"); fprintf(fpOut, "+"); //token은 "plus" 이런식으로 안쓴다 "" 떼줘
					break;
		case minus : printf("-"); fprintf(fpOut, "-");
					break;
		case times : printf("*"); fprintf(fpOut, "*");
					break;
		case divide : printf("/"); fprintf(fpOut, "/");
					break;
		case mod : printf("%"); fprintf(fpOut, "%");
					break;
	}
}
precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
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
void postfix(void)
{
	precedence token;
	char symbol;
	int n = 0;

	//token = getToken(&symbol, &n); //함수 모듈화 과정을 루프조건으로 넣어

	stack[0] = eos; //시작, 끝 과정에서 함수 쉽게만들어
	top = 0; //그러므로 -1아니다

	for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{ //숫자는 바로출력
			printf("%c", symbol);
			fprintf(fpOut, "%c", symbol);
		}
		else if (token == rparen)
		{ //)이 나오면
			while (stack[top] != lparen) // (이 나올때까지 pop
				printToken(pop());
			pop(); //(는 프린트 없이 그냥 빼기
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
			//들어가는 토큰icp보다 stack의 isp가 같거나 높으면 다 빼기
				printToken(pop());
			push(token); //들어가는 토큰icp보다 스택의 isp가 낮아지면 push
		}
	}
	while( (token=pop()) != eos )//남아있는 토큰 출력 - 조건문에서 pop을 해준다
		printToken(token);
}

int main(void)
{
	FILE *fpIn = fopen("input2.txt", "r");
	fpOut = fopen("output2.txt", "w");

	fscanf(fpIn, "%s", expr);
	printf("expr : ");

	postfix();

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
