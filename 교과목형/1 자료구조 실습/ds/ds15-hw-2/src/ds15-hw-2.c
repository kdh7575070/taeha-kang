#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
   if( !( (p) = malloc( s ) ) ){   \
      fprintf(stderr, "Insufficient memory");\
      exit(EXIT_FAILURE);\
   }

typedef int iType;
typedef struct{
				int key;
				iType item;
		} element;

typedef struct node *treePointer;
typedef struct node{
	element data;
	treePointer leftChild, rightChild;
}node;

element* search(treePointer root, int k);
void insert(treePointer *node, int k, iType theItem);
treePointer modifiedSearch(treePointer node, int k);
void inorder(treePointer ptr);

int main(void)
{
	int a = 22;
	int i = 15;
	int k = 43;

	element data;

	treePointer root = NULL; //���� �ʱ�ȭ�� ����..!!!!!!!!!!!

	srand(a);

	while(i--)
	{
		data.item = (rand()%500)+1 ;
		data.key = data.item;
		insert(&root, data.key, data.item);
		printf("%d ", data.key);
	}
	printf("\n");
	search(root, k);
	printf("\n");
	inorder(root);

	return 0;
}

element* search(treePointer root, int k)
{
	//return a pointer to the element whose key is k, if there is no such element, return NULL
	if (!root) {printf("no such element"); return NULL;}//empty �̰ų� ������ ���µ� ��ã��  ���
	if (k==root->data.key) {printf("the element is %d", root->data.key); return &(root->data);}//ã�Ҵ� - �ּҹ�ȯ
	if (k < root->data.key) return search(root->leftChild, k);//ũ��񱳻� �ִٸ� ���ʿ� ������
	return search(root->rightChild, k);//ũ��񱳻� �ִٸ� �����ʿ� ������
}

element* iterSearch(treePointer tree, int k)
{
	//return a pointer to the element whose key is k, if there is no such element, return NULL
	while(tree)
	{
		if (k==tree->data.key) return & (tree->data); //ã�Ҵ�
		if (k < tree->data.key) tree = tree->leftChild; //��
		else tree = tree->rightChild; //��
	}
	return NULL;
}

treePointer modifiedSearch(treePointer node, int k)
{
	//iterSearch�� ������ ���·μ�  k�� �ߺ��Ǹ� �׳�  NULL �ߺ� �װ� �ƴϸ�  insert��ġ�� ã���ش�

	if(!(node)) return NULL;

	treePointer temp = node;
	while (node)
	{
		temp = node;
		if (k < node->data.key) node = node->leftChild; //�������� ���� �ٽ� �˻�
		else if (k > node->data.key) node = node->rightChild; // ���������� ���� �ٽ� �˻�
		else return NULL;
	}
	return temp;
}

void insert(treePointer *node, int k, iType theItem) //��ġ�ؼ� �����带 ��� �����ؾ��ϹǷ� call by reference
{
	// ������ ����� Ű�� k�� ������ Item�� *node ��ġ�� insert

	treePointer ptr;
	treePointer temp = modifiedSearch(*node, k); //k���� Ž��

	if (temp || !(*node)) //temp��  NULL�ƴϰ� (�ߺ�����)|| empty tree��
	{
		MALLOC(ptr, sizeof(*ptr));
		ptr->data.key = k;
		ptr->data.item = theItem;
		ptr->leftChild = ptr->rightChild = NULL; //����

		//temp�� child�� insert
		if(*node)  //empty tree�ƴϸ�
		{
			if(k < temp->data.key) temp->leftChild = ptr; //��
			else temp->rightChild = ptr; //��
		}
		else *node = ptr; //empty tree��
	}
}
	
void inorder(treePointer ptr)
{
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("%d ", ptr->data.key);
		inorder(ptr->rightChild);
	}
}
