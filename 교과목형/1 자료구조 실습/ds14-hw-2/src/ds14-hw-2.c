#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node *treePointer;
typedef struct node{
					char data;		// operator or operand in char type
					treePointer leftChild, rightChild;
				}node;

treePointer root = NULL;

// stack
void push(treePointer item);
void stackFull();
treePointer pop();
treePointer stackEmpty();

treePointer stack[MAX_STACK_SIZE];
int top = -1;

// postfix expression
char expr[81];

typedef enum { and, or, not, eos, operand } logical;
logical getToken(char *symbol, int *n);
treePointer createBinTree(FILE *fp);

void inorder(treePointer ptr);

FILE *fp;

int main(void)
{
	if((fp = fopen("input.txt", "r"))  == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fgets(expr, 80, fp);
	printf("input string (postfix expression) : %s\n", expr);

	root = createBinTree(fp);

	printf("inorder traversal : ");
	inorder(root);

	return 0;
}

treePointer createBinTree(FILE *fp)
{
	treePointer treeRoot = NULL;

	logical token;
	char symbol;
	int n = 0;

	fscanf(fp, "%s", expr);

	token = getToken(&symbol, &n);

	while (token != eos)
	{
		treePointer temp;
		MALLOC(temp, sizeof(*temp));
		temp->data = symbol;
		temp->leftChild = temp->rightChild = NULL;

		if (token == operand)
		{
			treeRoot = temp;
			push(treeRoot);
		}
		else if (token == not)
		{
			treeRoot = temp;
			treeRoot->rightChild = pop();
			push(treeRoot);
		}
		else
		{
			treeRoot = temp;
			treeRoot->rightChild = pop();
			treeRoot->leftChild = pop();
			push(treeRoot);
		}
		token = getToken(&symbol, &n);
	}
	return treeRoot;
}

logical getToken(char *symbol, int *n)
{
	*symbol = expr[ (*n)++ ];
	switch ( *symbol)
	{
		case '&' : return and;
		case '|' : return or;
		case '~' : return not;
		case '\0' : return eos;
		default : return operand;
	}
}

///////////////////// binary tree traversals //////////////////////////////

void inorder(treePointer ptr)
{
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

/////////////////////// stack operations ///////////////////////////////////
treePointer pop()
{
	if ( top == -1 )
		return stackEmpty();
	return stack[top--];
}
treePointer stackEmpty()
{
	treePointer item;
	item = NULL;  // error key
	return item;
}
void push(treePointer item)
{
	if ( top >= MAX_STACK_SIZE-1 )
		stackFull();
	stack[++top] = item;
}
void stackFull()
{
	fprintf(stderr, "stack is full, cannot add item\n");
	exit(EXIT_FAILURE);
}
