#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

int make2dArray(int rows, int cols)
{
	int **x, i;

	MALLOC(x, rows * sizeof (*x));

	for(i = 0; i<rows; i++)
		MALLOC(x[i], cols * sizeof (**x));
	return x;
}
void init2dArray(int **a, int rows, int cols)
{
	int i, j;
	for (i=0; i< rows; i++)
		for (j=0; j< cols; j++)
			a[i][j]=rand()%10;
}
void print2dArray(int **a, int rows, int cols)
{
	printf("\n");

	int i, j;
	for (i=0; i< rows; i++)
	{
		for (j=0; j< cols; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void add(int **a, int **b, int **c, int rows, int cols)
{
	int i, j;
	for (i=0; i< rows; i++)
		for (j=0; j< cols; j++)
			c[i][j]=a[i][j]+b[i][j];
}
void freeAry2D( int **a, int rows )
{
	int r;

	for(r = 0; r<rows; r++)
		free(a[r]);
	free(a);
	printf("\n2d array free");
}

int main(void)
{
// 동적배열 이용한 행렬 더하기

	//setvbuf(stdout, NULL, _IONBF, 0); //콘솔창띄우기-이클립스
	//setvbuf(stderr, NULL, _IONBF, 0); //콘솔창띄우기-이클립스

	int a, b;
	int **ary1, **ary2, **ary3;

	printf("Enter row and col size (ex) 3 4 :");
	scanf("%d %d", &a, &b);    // 값을 두 개 입력받아서 변수 두 개에 저장

	ary1 = make2dArray(a, b);
	ary2 = make2dArray(a, b);
	ary3 = make2dArray(a, b);

	init2dArray(ary1,a, b);
	init2dArray(ary2,a, b);
	print2dArray(ary1,a, b);
	print2dArray(ary2,a, b);
	add(ary1, ary2, ary3, a, b);
	print2dArray(ary3,a, b);
	freeAry2D(ary1,2);
	freeAry2D(ary2,2);
	freeAry2D(ary3,2);

	return 0;
}
