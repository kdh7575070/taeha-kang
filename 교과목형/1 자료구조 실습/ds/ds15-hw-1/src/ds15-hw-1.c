#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct{
				int key;
		} element;

element heap[MAX_ELEMENTS];
int n = 0; //현재 힙의 사이즈

element pop(int *n);
void push(element item, int *n);

int main()
{
	int a;
	int i;
	element data;

	FILE *fp = fopen("input.txt", "r");

	while(!feof(fp))
	{
		fscanf(fp, "%d", &a);
		data.key = a;
		push(data, &n);
		for(i = 1; i<=n; i++) printf("%d ", heap[i].key);
		printf("\n");
	}
	printf("\n");

	while(n)
	{
		pop(&n);
		for(i = 1; i<=n; i++) printf("%d ", heap[i].key);
		printf("\n");
	}

	fclose(fp);
	return 0;
}

void push(element item, int *n)
{
	int i;

	if (HEAP_FULL(*n))
	{ //풀여부판단
		fprintf(stderr, "The heap is full. \n");
		exit(EXIT_FAILURE);
	}

	i = ++(*n); //힙사이즈1증가
	while ((i != 1) && (item.key > heap[i/2].key)) //루트가아니고 & 대소비교 //< min
	{
		heap[i] = heap[i/2]; //parent의 index가 i/2 즉  parent를 자식으로 내리고
		i /= 2; //포인터올려
	} //대소 맞아질때까지 반복
	heap[i] = item; //결정된 위치에 삽입
}

element pop(int *n)
{
	int parent, child;
	element item, temp;

	if (HEAP_EMPTY(*n))
	{ //empty여부 판단
		fprintf(stderr, "The heap is full. \n");
		exit(EXIT_FAILURE);
	}

	//무조건 루트만 리턴할 수 있다
	item = heap[1]; //루트 리턴

	temp = heap[(*n)--]; //힙의 맨 마지막을 임시변수로 두고 힙1 감소

	parent = 1;
	child = 2;
	//루트를 비워서 자리 재조정 - 위에서 부터 내려오면서 빈자리에 드가
	while(child <= *n)
	{
		//대소비교
		if((child <*n) && (heap[child].key < heap[child+1].key)) child++; //>
		if(temp.key >= heap[child].key) break; //<

		//다음레벨
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
