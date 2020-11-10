#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int n;
int cnt=0;
int s[100];

FILE *fpo;

void quickSort(int a[], int left, int right)
{
	//��º�
	cnt++;
	int k;
	for(k = 0; k < n; k++) {printf("%d ", s[k]); fprintf(fpo, "%d ", s[k]);}
	printf("\n"); fprintf(fpo,"\n");

	//�Լ���
	int pivot, i, j;
	int temp;

	if(left<right)
	{
		i = left; j = right + 1;
		pivot = a[left];
		do{
			do i++; while(a[i] < pivot);
			do j--; while(a[j] > pivot);
			if (i<j) SWAP(a[i],a[j],temp);
		} while(i<j);

		SWAP(a[left], a[j], temp);
		quickSort(a,left,j-1);
		quickSort(a,j+1,right);
	}
}

int main(void)
{

	FILE *fp = fopen("input.txt", "r");
	fpo = fopen("output.txt", "w");

	int i = 0;

	fscanf(fp, "%d", &n);

	while(!feof(fp))
	{
		fscanf(fp, "%d", &s[i]);
		i++;
	}

	quickSort(s, 0, 10);

	printf("�������: "); fprintf(fpo, "�������: ");
	for(i = 0; i< n; i++) {printf("%d ", s[i]); fprintf(fpo, "%d ", s[i]);}

	printf("\n%dȸ ���", cnt); fprintf(fpo, "\n%dȸ ���", cnt);

	fclose(fp);
	fclose(fpo);
	return 0;
}
