#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct element{
						int key;
				} element;

element a[MAX_SIZE];
int link[MAX_SIZE] = {0};
int n;

int listMerge(element a[], int link[], int start1, int start2)
{
	//원래는 체인을 통해 병합하는데 - 체인대신에 이중리스트을 사용하자 첫번째리스트가 체이닝인 셈

	int i;
	int last1, last2, lastResult = 0; //헤더 따로 없이 마지막만 포인팅 할것임 - last 1 2 가  원래배열포인터, Result가 새배열포인터

	for (last1 = start1, last2 = start2; last1 && last2;) //last1 && last2 (포인터가 가르키는게)둘다 NULL인동안 반복된다
	{
		if(a[last1].key <= a[last2].key) //앞에가 크다
		{
			link[lastResult]=last1;
			lastResult = last1;
			last1 = link[last1];
		}
		else							 //뒤에가 작다
		{
			link[lastResult]=last2;      //작은놈의 인덱스를 넣기 (result배열에 작은놈 체이닝)
			lastResult = last2;			 //             (result배열의 포인터이동)
			last2 = link[last2]; 		 //원래있던 인덱스에 작은놈의 이전 인덱스를 넣기 (작은놈 배열의 포인터이동)
		}
	}
	if
		(last1==0) link[lastResult] = last2;
	else								//뒤에가 작다
		link[lastResult] = last1;       //큰놈의 인덱스 넣기 (result배열에 큰놈 체이닝)

	for(i =0; i<= n; i++) printf("%3d ", link[i]);
	printf("\n");
	for(i =0; i<= n; i++) printf("%3d ", a[i].key);
	printf("\n\n");

	return link[0];
}

int rmergeSort(element a[], int link[], int left, int right)
{
	int mid;

	if (left>=right) return left; // 종료조건

	mid = (left+right) / 2;

	return listMerge(a,link,rmergeSort(a,link,left,mid),rmergeSort(a,link,mid+1,right));
	//함수 인자는 오른쪽에서 왼쪽으로 평가되어 right half에 대한 rmergeSort 호출을 먼저-RVL

	//return listMerge(a,link,rmergeSort(a,link,mid+1,right),rmergeSort(a,link,left,mid));
	//함수 인자는 오른쪽에서 왼쪽으로 평가되어 left half에 대한 rmergeSort 호출을 먼저 - LVR
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");

	int i=1;
	int r;
	element e;

	fscanf(fp, "%d", &n);

	while(!feof(fp))
	{
		fscanf(fp, "%d", &e.key);
		printf("%d ", e.key);
		a[i] = e;
		i++;
	}

	printf("\n\n");
	r = rmergeSort(a, link, 1, n);

	while(r)
	//for(i=1; i<=n; i++)
	{
		printf("%d ", a[r].key);
		r = link[r];
	}

	fclose(fp);

	return 0;
}
