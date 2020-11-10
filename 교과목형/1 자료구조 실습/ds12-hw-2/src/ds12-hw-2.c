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
					char data; // ��������� ���� char ������ ����
					treePointer leftChild, rightChild;
				}node;

treePointer root;
treePointer queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

//���⼭ queue�� ����뵵

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
		//if(hasBothChild()) deleteq(); �ؼ� hasBothChild����  getFront()�ҷ��͵� ����
		if(hasBothChild(getFront())) deleteq();
		//else deleteq(); �ϸ� �翬�� �ȉ´� -> ex ���� A-B-C-D-D ������ D���� A�� delete�ǰ� ���� D�� �־��ֱ����� �ѹ��� ���ƾ��ϴµ�
						  //else �ع����� A-B-C-D-E �� D���� A�� delete�ǰ� �ٷ� E�� �ͼ� D�� ������
	}
	addq(node);
}

treePointer createNode(char a)
{
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = a;
	temp->leftChild = temp->rightChild = NULL; //�̰��� ����XXXX !!!!!!!!!!!

	return temp;
}

treePointer createCompBinTree(FILE *fp)
{
    char a;

    treePointer treeRoot = NULL; // �ʱ�ȭ ���������..!!!
    treePointer temp;

    while(!feof(fp))
    {
    	//fscanf(fp, "%c", &a); eos�����°� ���� �Ʒ� �ι������� ó��
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
