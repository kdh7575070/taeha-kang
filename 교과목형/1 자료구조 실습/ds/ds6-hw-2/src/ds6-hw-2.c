#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 10
#define MAX_COL 10

// 2015112806 강태하
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

typedef struct {
				int row;
				int col;
				int value;
		   }term;

term mats[MAX_COL];
term out[MAX_COL];

void fastTranspose(term a[], term b[])
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms >0)
	{
		for(i=0; i<numCols; i++)
			 rowTerms[i] = 0;
		// 0짜리 배열

		for(i=1; i<= numTerms; i++)
			rowTerms[a[i].col]++;
		// 카운팅

		startingPos[0] = 1;
		// 자리지정(출발점)

		for(i=1; i< numCols; i++)
			startingPos[i] = startingPos[i-1]+rowTerms[i-1];
		// 자리지정

		for(i=1; i<= numTerms; i++)
		{
			j = startingPos[a[i].col];
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
			startingPos[a[i].col]++;
		}
		//트랜스포즈
	}
}

void printmat(int m[][MAX_COL], term a[], int r, int c, int v)
{
	int i, j;
	for (i = 1; i <= v; i++) m[a[i].row][a[i].col] = a[i].value;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++) printf("%2d ", m[i][j]);
	    printf("\n");
	}
	printf("\n");
}
/*
{
	int i, j, k;
	for (i=1; i <= r; i++)
	{
		for (j=1; j<= c; j++)
		{
			for (k=0; k <= v; k++) {if (a[k].row == i && a[k].col == j) m[i][j] = a[k].value;}
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
*/

int main(void)
{
	FILE *fpIn = fopen("a.txt", "r");
	FILE *fpOut = fopen("b.txt", "w");

	int row0, col0, value0;
	int row, col, value;
	int i, j;

	fscanf(fpIn, "%d", &row0);
	mats[0].row = row0;
	fscanf(fpIn, "%d", &col0);
	mats[0].col = col0;
	fscanf(fpIn, "%d", &value0);
	mats[0].value = value0;

	for(i=1; i<=value0; i++)
	{
		fscanf(fpIn, "%d", &row);
		mats[i].row = row;
		fscanf(fpIn, "%d", &col);
		mats[i].col = col;
		fscanf(fpIn, "%d", &value);
		mats[i].value = value;
	}

	printf("A\n");
	int m[MAX_ROW][MAX_COL] = {0, };
	printmat(m, mats, row0, col0, value0);

	fastTranspose(mats, out);

	printf("B\n");
	int o[MAX_ROW][MAX_COL] = {0, };
	printmat(o, out, col0, row0, value0);

	for (i=1; i <= value0; i++)
	{
		fprintf(fpOut,"%d %d %d", out[i].row, out[i].col, out[i].value);
		fprintf(fpOut,"\n");
	}

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
