#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
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

treePointer root;
treePointer queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

//여기서 queue는 저장용도

treePointer queueEmpty()
{
	printf("EMPTY\n");
	return NULL;
}
treePointer deleteq()
{
	if (front == rear)
		return queueEmpty();
	return queue[++front];
}
void queueFull()
{
	printf("error");
	exit(EXIT_FAILURE);
}
void addq(treePointer node)
{
	if (rear == MAX_QUEUE_SIZE-1)
		queueFull();
	queue[++rear] = node;
}

//

treePointer getFront()
{
	return queue[front+1];
}

int hasBothChild(treePointer node)
{
	if ((node->leftChild)&&(node->rightChild)) return 1;
	return 0;
}

void insert(treePointer *treeRoot, treePointer node)
{
	if(!(*treeRoot)) *treeRoot = node;

	else
	{
		if(!(getFront()->leftChild))
			getFront()->leftChild = node;
		else if(!(getFront()->rightChild))
			getFront()->rightChild = node;
		//if(hasBothChild()) deleteq(); 해서 hasBothChild에서  getFront()불러와도 무방
		if(hasBothChild(getFront())) deleteq();
		//else deleteq(); 하면 당연히 안됀다 -> ex 원래 A-B-C-D-D 식으로 D에서 A가 delete되고 나면 D를 넣어주기위해 한번더 돌아야하는데
						  //else 해버리면 A-B-C-D-E 즉 D에서 A가 delete되고 바로 E가 와서 D가 못들어간다
	}
	addq(node);
}

treePointer createNode(char a)
{
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = a;
	temp->leftChild = temp->rightChild = NULL; //이과정 생략XXXX !!!!!!!!!!!

	return temp;
}

treePointer createCompBinTree(FILE *fp)
{
    char a;

    treePointer treeRoot = NULL; // 초기화 까먹지말고..!!!
    treePointer temp;

    while(!feof(fp))
    {
    	//fscanf(fp, "%c", &a); eos들어오는거 방지 아래 두문장으로 처리
    	a = fgetc(fp);
    	if (a == EOF) break;
    	temp = createNode(a);
    	insert(&treeRoot, temp);
    }
    return treeRoot;//
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

	root = createCompBinTree(fpIn);

	printf("inorder:");
	inorder(root);
	printf("\npreorder:");
	preorder(root);
	printf("\npostorder:");
	postorder(root);
	fclose(fpIn);

	return 0;
}
