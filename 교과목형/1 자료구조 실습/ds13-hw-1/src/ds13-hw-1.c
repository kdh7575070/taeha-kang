#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20
#define IS_EMPTY(first)(!(first))

#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node *treePointer;
typedef struct node {
					char data; // char 문자출력을 위해 형으로 지정
					treePointer leftChild, rightChild;
				}node;

treePointer root = NULL;

treePointer stack[MAX_STACK_SIZE];
int top = -1;

typedef enum {
			lparen, rparen, plus, minus, times, divide, mod, eos, operand
			} precedence;
char expr[81]; // postfix expression

treePointer stackEmpty()
{
	printf("EMPTY\n");
	exit(EXIT_FAILURE);
}
treePointer pop()
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
void push(treePointer node)
{
	if (top == MAX_STACK_SIZE-1)
		stackFull(); //return stackFUll(); 이라면
	stack[++top] = node;
}

precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch(*symbol){
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

treePointer createNode(char a)
{
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = a;
	temp->leftChild = temp->rightChild = NULL; //이과정 생략XXXX !!!!!!!!!!!

	return temp;
}

treePointer createBinTree(FILE *fp)
{
	treePointer temp;

	precedence token;
	char symbol;
	int n = 0;

	fscanf(fp, "%s", expr);

	token = getToken(&symbol, &n);

	while (token != eos)
	{
		if (token == operand)
		{
			temp = createNode(symbol);
			push(temp);
		}
		else
		{
			temp = createNode(symbol);
			temp->rightChild = pop();
			temp->leftChild = pop();
			push(temp);
		}
		token = getToken(&symbol, &n);
	}
	return temp;
}

void inorder(treePointer ptr)
{
	if(ptr){
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}
void preorder(treePointer ptr)
{
	if(ptr){
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr)
{
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}

int main(void)
{
	FILE *fpIn = fopen("input.txt","r");

	root = createBinTree(fpIn);

	printf("inorder:");
	inorder(root);
	printf("\npreorder:");
	preorder(root);
	printf("\npostorder:");
	postorder(root);
	fclose(fpIn);

	return 0;
}

