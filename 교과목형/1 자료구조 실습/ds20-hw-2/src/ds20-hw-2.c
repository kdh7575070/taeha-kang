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
	//������ ü���� ���� �����ϴµ� - ü�δ�ſ� ���߸���Ʈ�� ������� ù��°����Ʈ�� ü�̴��� ��

	int i;
	int last1, last2, lastResult = 0; //��� ���� ���� �������� ������ �Ұ��� - last 1 2 ��  �����迭������, Result�� ���迭������

	for (last1 = start1, last2 = start2; last1 && last2;) //last1 && last2 (�����Ͱ� ����Ű�°�)�Ѵ� NULL�ε��� �ݺ��ȴ�
	{
		if(a[last1].key <= a[last2].key) //�տ��� ũ��
		{
			link[lastResult]=last1;
			lastResult = last1;
			last1 = link[last1];
		}
		else							 //�ڿ��� �۴�
		{
			link[lastResult]=last2;      //�������� �ε����� �ֱ� (result�迭�� ������ ü�̴�)
			lastResult = last2;			 //             (result�迭�� �������̵�)
			last2 = link[last2]; 		 //�����ִ� �ε����� �������� ���� �ε����� �ֱ� (������ �迭�� �������̵�)
		}
	}
	if
		(last1==0) link[lastResult] = last2;
	else								//�ڿ��� �۴�
		link[lastResult] = last1;       //ū���� �ε��� �ֱ� (result�迭�� ū�� ü�̴�)

	for(i =0; i<= n; i++) printf("%3d ", link[i]);
	printf("\n");
	for(i =0; i<= n; i++) printf("%3d ", a[i].key);
	printf("\n\n");

	return link[0];
}

int rmergeSort(element a[], int link[], int left, int right)
{
	int mid;

	if (left>=right) return left; // ��������

	mid = (left+right) / 2;

	return listMerge(a,link,rmergeSort(a,link,left,mid),rmergeSort(a,link,mid+1,right));
	//�Լ� ���ڴ� �����ʿ��� �������� �򰡵Ǿ� right half�� ���� rmergeSort ȣ���� ����-RVL

	//return listMerge(a,link,rmergeSort(a,link,mid+1,right),rmergeSort(a,link,left,mid));
	//�Լ� ���ڴ� �����ʿ��� �������� �򰡵Ǿ� left half�� ���� rmergeSort ȣ���� ���� - LVR
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
