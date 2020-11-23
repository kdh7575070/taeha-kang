#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct{
				int key;
		} element;

element heap[MAX_ELEMENTS];
int n = 0; //���� ���� ������

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
	{ //Ǯ�����Ǵ�
		fprintf(stderr, "The heap is full. \n");
		exit(EXIT_FAILURE);
	}

	i = ++(*n); //��������1����
	while ((i != 1) && (item.key > heap[i/2].key)) //��Ʈ���ƴϰ� & ��Һ� //< min
	{
		heap[i] = heap[i/2]; //parent�� index�� i/2 ��  parent�� �ڽ����� ������
		i /= 2; //�����Ϳ÷�
	} //��� �¾��������� �ݺ�
	heap[i] = item; //������ ��ġ�� ����
}

element pop(int *n)
{
	int parent, child;
	element item, temp;

	if (HEAP_EMPTY(*n))
	{ //empty���� �Ǵ�
		fprintf(stderr, "The heap is full. \n");
		exit(EXIT_FAILURE);
	}

	//������ ��Ʈ�� ������ �� �ִ�
	item = heap[1]; //��Ʈ ����

	temp = heap[(*n)--]; //���� �� �������� �ӽú����� �ΰ� ��1 ����

	parent = 1;
	child = 2;
	//��Ʈ�� ����� �ڸ� ������ - ������ ���� �������鼭 ���ڸ��� �尡
	while(child <= *n)
	{
		//��Һ�
		if((child <*n) && (heap[child].key < heap[child+1].key)) child++; //>
		if(temp.key >= heap[child].key) break; //<

		//��������
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
