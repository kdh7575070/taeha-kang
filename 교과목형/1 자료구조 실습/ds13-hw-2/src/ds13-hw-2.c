#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20
#define MAX_QUEUE_SIZE 20
#define IS_EMPTY(first)(!(first))
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node *treePointer;
typedef struct node {
			char data; // 문자출력
			treePointer leftChild, rightChild;
			}node;

treePointer root = NULL;

// 반복문을 위한 stack
treePointer stack[MAX_STACK_SIZE];
int top = -1;

// circular queue
treePointer queue[MAX_QUEUE_SIZE];
int front=0, rear=0;

typedef enum {
			lparen, rparen, plus, minus, times, divide, mod, eos, operand
			} precedence;
char expr[81]; // postfix expression

treePointer stackEmpty()
{
	return NULL;
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


treePointer queueEmpty()
{
	return NULL;
}
treePointer deleteq()
{
	if (front == rear)
		return queueEmpty();
	front = (front+1)%MAX_QUEUE_SIZE;
	return queue[front];
}
void queueFull()
{
	printf("FULLq\n");
	exit(EXIT_FAILURE);
}
void addq(treePointer node)
{
	rear = (rear+1)%MAX_QUEUE_SIZE;
	if (rear == MAX_QUEUE_SIZE-1)
		queueFull();
	queue[rear] = node;
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
	treePointer temp = NULL;

	precedence token;
	char symbol;
	int n = 0;

	fscanf(fp, "%s", expr);

	token = getToken(&symbol, &n);

	while (token != eos){
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
void iterInorder(treePointer node)
{
	top = -1;

	for(;;){
		for(; node; node = node->leftChild)
			push(node); //add to stack
		node = pop(); //delete from stack
		if(!node) break; //empty stack
		printf("%c", node->data);
		node = node->rightChild;
	}
}

void levelOrder(treePointer ptr)
{
	if(!ptr) return; //empty tree

	addq(ptr);
	for(; ;)
	{
		ptr = deleteq();
		if(ptr)
		{
			printf("%c", ptr->data);
				if(ptr->leftChild)	addq(ptr->leftChild);
				if(ptr->rightChild) addq(ptr->rightChild);
		}
		else break;
	}
}
int main(void)
{
	FILE *fpIn = fopen("input.txt","r");

	root = createBinTree(fpIn);

	printf("iterInorder:");
	iterInorder(root);
	//끝에 +E 왜 두개?

	printf("\nlevelOrder:");
	levelOrder(root);

	fclose(fpIn);

	return 0;
}
