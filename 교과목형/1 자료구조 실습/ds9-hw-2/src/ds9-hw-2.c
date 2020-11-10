#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum { // 0 1 2 3 4 5 6 .. �� ��Ī�����ִ� ����
			lparen, rparen, plus, minus, times, divide, mod, eos, operand
			} precedence;

//�������� - ���ϳ������� ������
static int isp[]={0, 19, 12, 12, 13, 13, 13, 0}; //(�� �ȿ� ������ ���� ����
static int icp[]={20, 19, 12, 12, 13, 13, 13, 0}; //(�� �ۿ� �������� ���� ����

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
		stackFull(); //return stackFUll(); �̶��
	stack[++top] = token;
}

void printToken(precedence token)
{
	switch(token)
	{
		case plus : printf("+"); fprintf(fpOut, "+"); //token�� "plus" �̷������� �Ⱦ��� "" ����
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

	//token = getToken(&symbol, &n); //�Լ� ���ȭ ������ ������������ �־�

	stack[0] = eos; //����, �� �������� �Լ� ���Ը����
	top = 0; //�׷��Ƿ� -1�ƴϴ�

	for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{ //���ڴ� �ٷ����
			printf("%c", symbol);
			fprintf(fpOut, "%c", symbol);
		}
		else if (token == rparen)
		{ //)�� ������
			while (stack[top] != lparen) // (�� ���ö����� pop
				printToken(pop());
			pop(); //(�� ����Ʈ ���� �׳� ����
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
			//���� ��ūicp���� stack�� isp�� ���ų� ������ �� ����
				printToken(pop());
			push(token); //���� ��ūicp���� ������ isp�� �������� push
		}
	}
	while( (token=pop()) != eos )//�����ִ� ��ū ��� - ���ǹ����� pop�� ���ش�
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
