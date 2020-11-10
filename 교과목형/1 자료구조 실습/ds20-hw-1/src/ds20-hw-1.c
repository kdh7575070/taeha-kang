#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 2015112806 강태하
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

typedef struct element{
						int key;
				} element;
element v[MAX_SIZE];
int a;

void merge(element initList[], element mergedList[], int i, int m, int n)
{
	//정렬알고리즘

	int j,k,t;
	j = m+1;
	k=i;

	while(i<=m && j<=n)
	{
		if(initList[i].key <= initList[j].key)
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if (i>m)
		for(t=j; t<=n; t++)
			mergedList[t] = initList[t];
	else
	{
		for(t=i; t<=m; t++)
			mergedList[k+t-i] = initList[t];
	}
}

void mergePass(element initList[], element mergedList[], int n, int s)
{
	int i, j;

	for (i=1; i+2*s-1<=n; i+=2*s)
		merge(initList,mergedList,i,i+s-1,i+2*s-1); //merge

	//나머지부분에 대해서
	if (i+s-1 < n)
		merge(initList,mergedList,i,i+s-1,n); //절반이 넘으면
	else
	{
		for(j=i;j<=n;j++) mergedList[j] = initList[j]; //절반도 안되면
	}
}

void mergeSort(element v[], int n)
{
	int i, s = 1;
	element extra[MAX_SIZE];

	while(s<n)
	{
		mergePass(v,extra, n,s);

		printf("%d\n", s);
		for(i =1; i<= a; i++) printf("%d ", v[i].key);
		printf("\n");
		for(i =1; i<= a; i++) printf("%d ", extra[i].key);
		printf("\n\n");

		s*=2;

		//한번 하고나면 두 포인터의 위치가 바뀐다

		mergePass(extra,v, n,s);

		printf("%d\n", s);
		for(i =1; i<= a; i++) printf("%d ", extra[i].key);
		printf("\n");
		for(i =1; i<= a; i++) printf("%d ", v[i].key);
		printf("\n\n");

		s*=2;
	}
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");

	int i=1;
	element e;

	fscanf(fp, "%d", &a);

	while(!feof(fp))
	{
		fscanf(fp, "%d", &e.key);
		printf("%d ", e.key);
		v[i] = e;
		i++;
	}

	printf("\n\n");
	mergeSort(v, a);

	fclose(fp);

	return 0;
}
