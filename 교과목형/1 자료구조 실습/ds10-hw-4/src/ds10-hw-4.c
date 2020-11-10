#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_EMPTY(first)(!(first))
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct listNode *listPointer;
typedef struct listNode {
						char data[4]; //3하면 왜 안되지?
						listPointer link;
				}listNode;

listPointer first = NULL; //초기화 꼭!

//세가지 케이스로 나누는게 이 문제의 핵심
//팁으로는 애초에 first를 쓰레기값을 하나 넣어놓고 시작하면
//first계산을 안해줘도되므로
//insert나 find에서 훨씬 간단하다

listPointer find(char *c) //포인팅만 하는거라 call by ref
{
	listPointer x = first; //first는 옮기면 안되지

	if (x == NULL)
	{//(a)텅비었을 때
		printf("1");
	    return NULL;
	}

	if (x->data[0] > c[0])
	{ //(b)들어오자마자 제일 작을 때
		printf("2");
		return NULL;
	}

	//(c)끝까지 옮기기 전에 자리를 찾았을 때
	while(x->link) // 1 x로 하면 빠져나갈때 무조건 NULL이 된다 그전에 빼줘야하므로 x->link가 NULL이 아닌동안
	{
		if (x->link->data[0] > c[0]) // 2 그래서 (x->data > n)로 데이터 역시  그 다음링크꺼를 비교한다
		{
			printf("3-1");
			return x;
		}
		//else(x->data <= n)면
		x = x->link;
		printf("0");
	}

	//(c)끝까지 옮겼을 때 (while문 빠져나왔을때)
	printf("3-2");
	return x; //
}

void insert(listPointer *first, listPointer x, char *data) //값을 실제로 대입해야하는 부분 first는  주소호출 x는 가리키기만함
{/* 체인의 x 노드 바로 뒤에 data 값을 가지는 새 노드를 추가 */

	/* 새 노드 할당 및 데이터 저장 */
	listPointer temp;
	MALLOC(temp, sizeof(*temp));

	strcpy(temp->data, data);

	if( *first == NULL )
	{ /* (a) 텅빈 리스트에 노드 추가 */
		temp->link = NULL;
		*first = temp;
		printf("a");
	}
	else
	{ /* 비어 있지 않은 리스트에 추가 */

		if ( x == NULL )
		{ // (b) 첫 노드로 추가
			temp->link = *first;
			*first = temp;
			printf("b");
		}
		else
		{ // (c) 두 번째 이상 위치에 추가
			temp->link = x->link;
			x->link = temp;
			printf("c");
		}
	}
}

void delete(listPointer *first, listPointer trail, listPointer x)
{
	if(trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void printList(listPointer first)
{
	int cnt = 0;
	printf("\nThe list contains: \n");
	for(; first; first = first->link)
	{
		printf("%s ", first->data);
		cnt++;
		if(cnt%10==0) printf("\n");
	}
}

int main(void)
{
	char c[4];
	listPointer x,y ;
	FILE *fpIn = fopen("input.txt","r");

	while( !feof(fpIn) )
	{
		fscanf(fpIn, "%s", c);
		x = find(c);// find insert position x
		insert(&first, x, c); // insert data first after node x
	}

	printList(first);

	printf("\n\n");
	y = find("GAT"); //y는 BAT를 가르킨다
	//GAT로 할려면 find에서  if (x->link->data[0] >= c[0]) 로 수정해주면된다
	delete(&first, y, y->link);

	printf("\nDeleted GAT--");
	printList(first);

	fclose(fpIn);

	return 0;
}
