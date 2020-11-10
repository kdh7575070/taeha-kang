#include <stdio.h>
#include <stdlib.h>

typedef struct element{
						int key;
						char name[10];
						int grade;
				} element;

element s[100];
//int cnt;

void insert(element e, element a[], int i)
{
	a[0] = e;
	while (e.key < a[i].key)
	{
		a[i+1] = a[i];
		i--;
		//cnt++;
	}
	a[i+1] = e;
}

void insertionSort(element a[],int n)
{
	int j;
	for (j =2 ; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j-1);
	}
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	FILE *fpo = fopen("output.txt", "w");

	int a, i=1;
	element e;

	fscanf(fp, "%d", &a);

	while(!feof(fp))
	{
		fscanf(fp, "%d %s %d", &e.key, e.name, &e.grade);
		//printf("%d %s %d\n", e.key, e.name, e.grade);
		s[i] = e;
		i++;
	}

	insertionSort(s, a);

	for(i =1; i<= a; i++)
	{
		printf("%d %s %d\n", s[i].key, s[i].name, s[i].grade);
		fprintf(fpo, "%d %s %d\n", s[i].key, s[i].name, s[i].grade);
	}

	//printf("%dȸ\n", cnt);
	//fprintf(fpo, "%dȸ\n", cnt);

	fclose(fp);
	fclose(fpo);

	return 0;
}
