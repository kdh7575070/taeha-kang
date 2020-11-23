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

	treePointer root = NULL; //제발 초기화좀 해줘..!!!!!!!!!!!

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
	if (!root) {printf("no such element"); return NULL;}//empty 이거나 끝까지 갔는데 못찾은  경우
	if (k==root->data.key) {printf("the element is %d", root->data.key); return &(root->data);}//찾았다 - 주소반환
	if (k < root->data.key) return search(root->leftChild, k);//크기비교상 있다면 왼쪽에 있을것
	return search(root->rightChild, k);//크기비교상 있다면 오른쪽에 있을것
}

element* iterSearch(treePointer tree, int k)
{
	//return a pointer to the element whose key is k, if there is no such element, return NULL
	while(tree)
	{
		if (k==tree->data.key) return & (tree->data); //찾았다
		if (k < tree->data.key) tree = tree->leftChild; //왼
		else tree = tree->rightChild; //오
	}
	return NULL;
}

treePointer modifiedSearch(treePointer node, int k)
{
	//iterSearch의 변형된 형태로서  k가 중복되면 그냥  NULL 중복 그게 아니면  insert위치를 찾아준다

	if(!(node)) return NULL;

	treePointer temp = node;
	while (node)
	{
		temp = node;
		if (k < node->data.key) node = node->leftChild; //왼쪽으로 가서 다시 검색
		else if (k > node->data.key) node = node->rightChild; // 오른쪽으로 가서 다시 검색
		else return NULL;
	}
	return temp;
}

void insert(treePointer *node, int k, iType theItem) //서치해서 만든노드를 계속 유지해야하므로 call by reference
{
	// 삽입할 노드의 키값 k를 가지는 Item을 *node 위치로 insert

	treePointer ptr;
	treePointer temp = modifiedSearch(*node, k); //k값을 탐색

	if (temp || !(*node)) //temp가  NULL아니고 (중복없고)|| empty tree면
	{
		MALLOC(ptr, sizeof(*ptr));
		ptr->data.key = k;
		ptr->data.item = theItem;
		ptr->leftChild = ptr->rightChild = NULL; //생성

		//temp의 child로 insert
		if(*node)  //empty tree아니면
		{
			if(k < temp->data.key) temp->leftChild = ptr; //왼
			else temp->rightChild = ptr; //오
		}
		else *node = ptr; //empty tree면
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
