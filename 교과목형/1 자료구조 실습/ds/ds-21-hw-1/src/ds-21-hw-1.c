#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 100

typedef struct element{
						int key;
				} element;

element a[MAX_SIZE];
FILE *fpo;

void printHeap(int n)
{
	int i;
	for(i=1; i <= n; i++) {printf("%3d ", a[i].key); fprintf(fpo, "%3d ", a[i].key);}
	printf("\n"); fprintf(fpo, "\n");
}

void adjust(element a[], int root, int n)
{
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2*root;
	while(child<=n){
		if((child<n) && (a[child].key <a[child+1].key))
			child++;
		if(rootkey>a[child].key)
			break;
		else {
			a[child/2]=a[child];
			child*=2;
		}
	}
	a[child/2]=temp;
}

void heapSort(element a[], int n)
{
	int i;
	element temp;

	//max heap 구성 및 출력 - 앞에서 max힙 만든 것(쉬운 배열 방식)
	for(i=n/2; i>0; i--) adjust(a,i,n);

	printHeap(n);
	printf("\n"); fprintf(fpo, "\n");

	//처음과 마지막을 바꾼 뒤에 root를 다시 adjust - 즉 맥스힙을 반복구성하는 식
	for(i=n-1; i>0; i--)
	{
		SWAP(a[1],a[i+1],temp);
		adjust(a,1,i);
		//출력
		printHeap(n);
	}
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	fpo = fopen("output.txt", "w");

	int n, i=1;
	element e;

	fscanf(fp, "%d", &n);

	while(!feof(fp))
	{
		fscanf(fp, "%d", &e.key);
		printf("%3d ", e.key); fprintf(fpo, "%3d ", e.key);
		a[i] = e;
		i++;
	}

	printf("\n\n Excuting\n"); fprintf(fpo, "\n\n Excuting\n");
	heapSort(a,n);

	printf("\n\n Sorted List: "); fprintf(fpo, "\n\n Sorted List: ");
	for(i=1; i <= n; i++) {printf("%3d ", a[i].key); fprintf(fpo, "%3d ", a[i].key);}

	fclose(fp);
	fclose(fpo);

	return 0;
}
