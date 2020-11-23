#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define IS_EMPTY(first)(!(first))
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node *treePointer;
typedef struct node {
					char data; // 문자출력을 위해 char 형으로 지정
					treePointer leftChild, rightChild;
				}node;

FILE *fpIn;
int top = -1;
treePointer stack[MAX_STACK_SIZE];

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

int hasBothChild(treePointer node)
{
	if ((node->leftChild)&&(node->rightChild)) return 1;
	return 0;
}

treePointer createNode(char a)
{
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = a;
	temp->leftChild = temp->rightChild = NULL; //이과정 생략XXXX !!!!!!!!!!!

	return temp;
}

/*
void createBinTree()
{
	treePointer temp;
	char a;

	fscanf(fpIn, "%c", &a);
	root = createNode(root, a, 'n'); //void반환 할꺼면 전역 root에 바로 덧씌운다!!!

	fscanf(fpIn, "%c", &a);
	temp = createNode(root, a, 'l');

	fscanf(fpIn, "%c", &a);
	createNode(root, a, 'r');

	fscanf(fpIn, "%c", &a);
	createNode(temp, a, 'l');

	fscanf(fpIn, "%c", &a);
	createNode(temp, a, 'r');
}

	//return없이 바로 덧씌우기  - create과정에서 더 많은 인자 (char a, char rl) & 조건들 필요함
	 * if(!(node)) node = temp;
	 * if(rl == 'l') node->leftChild = temp;
	 * else if(rl == 'r') node->rightChild = temp;
*/

treePointer createBinTree()
{
	treePointer treeRoot;
    char a;

    fscanf(fpIn, "%c", &a);
    treeRoot = createNode(a);

    fscanf(fpIn, "%c", &a);
    treeRoot->leftChild = createNode(a);

    fscanf(fpIn, "%c", &a);
    treeRoot->rightChild = createNode(a);

    fscanf(fpIn, "%c", &a);
    treeRoot->leftChild->leftChild = createNode(a);

    fscanf(fpIn, "%c", &a);
    treeRoot->leftChild->rightChild = createNode(a);

    return treeRoot; // -> main함수에서 리턴 받아야해 (or 전역변수로 설정해서 void로 바로 연결힐 수도 있다)
}

/* 스택사용- 실패...
treePointer createBinTree()
{
	treePointer temp, treeRoot, p=NULL, dummy=NULL;
    char a;

    while(!feof(fpIn))
    {
    	fscanf(fpIn, "%c", &a);
    	temp = createNode(a);

    	if(!(treeRoot)) treeRoot = temp;

    	else
    	{
    		if(!(stack[top]->leftChild)) stack[top]->leftChild = temp;
    		else if(!(stack[top]->rightChild)) stack[top]->rightChild = temp;
    	}
    	push(temp);

		if(hasBothChild(stack[top]) && !p) p = pop(); // A-BC 연결되있으면 C pop
		if(hasBothChild(stack[top]) && p) {dummy=p ; p = pop(); push(dummy);} //A-B-DE 연결되어있으니 E를 pop C를 push
    }

    return treeRoot;
}
*/

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
	fpIn = fopen("input.txt","r");

	treePointer root;

	root = createBinTree();

	printf("inorder:");
	inorder(root);
	printf("\npreorder:");
	preorder(root);
	printf("\npostorder:");
	postorder(root);
	fclose(fpIn);

	return 0;
}
