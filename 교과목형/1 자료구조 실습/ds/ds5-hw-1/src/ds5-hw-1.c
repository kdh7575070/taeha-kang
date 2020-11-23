#include <stdio.h>
#include <stdlib.h>

int sumAry2D_f1( int [][3], int , int );
int sumAry2D_f2( int [][3], int , int );
int sumAry2D_f3( int [][3], int , int );
int sumAry2D_f4( int **, int , int );
int sumAry2D_f5( int ***, int , int );
void freeAry2D( int **, int );

int main(void)
{
// �����迭 �����迭�� �Լ��� �����ϴ� ����� �� - 2����
	int ary2D[ ][3] = {{1, 2, 3},
					 {4, 5, 6}};

	int r,c;
	int **ary = (int**)malloc(sizeof(int*) * 2);

	for(r = 0; r<2; r++)
		ary[r] = (int *)malloc(sizeof(int) * 3);

	for (r=0; r<2; r++)
		for (c=0; c<3; c++)
			ary[r][c]=r+c;

	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));

	printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, 2, 3));
	printf("sumAry2D_f5() %d\n", sumAry2D_f5(&ary, 2, 3));

	freeAry2D(ary,2);

	return 0;
}

int sumAry2D_f1( int ary[2][3], int ROW, int COL )
{
	int r, c = 0;
	int a = 0;

	for(r=0; r<ROW; r++)
		for(c=0; c<COL; c++)
			a += ary[r][c];
	return a;
}

int sumAry2D_f2( int ary[][3], int ROW, int COL )
{
	int r, c = 0;
	int a = 0;

	for(r=0; r<ROW; r++)
		for(c=0; c<COL; c++)
			a += ary[r][c];
	return a;
}

int sumAry2D_f3( int (*ary)[3], int ROW, int COL )
{
	int r, c = 0;
	int a = 0;

	for(r=0; r<ROW; r++)
		for(c=0; c<COL; c++)
			a += ary[r][c];
	return a;
}

int sumAry2D_f4( int **ary, int ROW, int COL )
{
	int r, c = 0;
	int a = 0;

	for(r=0; r<ROW; r++)
		for(c=0; c<COL; c++)
			a += *(*ary+r)+c; //a += *ary[r][c] �� �ƴϰ� (*ary)[r][c] �̷��� ��ߵȴ�
	return a;
}

int sumAry2D_f5( int ***ary, int ROW, int COL )
{
	int r, c = 0;
	int a = 0;

	for(r=0; r<ROW; r++)
		for(c=0; c<COL; c++)
			a += *(**ary+r)+c;

	return a;
}

void freeAry2D( int **ary, int a )
{
	int r;

	for(r = 0; r<a; r++)
		free(ary[r]); //ary���� free
	free(ary);
	printf("2d array free");
}
