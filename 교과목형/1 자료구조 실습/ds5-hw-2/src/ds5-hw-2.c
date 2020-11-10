#include <stdio.h>
#include <stdlib.h>

int sumAry3D_f1( int [][3][4], int , int , int );
int sumAry3D_f2( int [][3][4], int , int , int );
int sumAry3D_f3( int [][3][4], int , int , int );
int sumAry3D_f4( int ***, int , int, int );
int sumAry3D_f5( int ****, int , int, int );
void freeAry3D( int ***, int, int );

int main(void)
{
// 정적배열 동적배열을 함수로 전달하는 방법을 비교 - 2차원
	int ary3D[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
							{{2, 3, 4, 5}, {6, 7, 8, 9}, {10, 11, 12, 13}}};

	int r,c,s;

	int ***ary = (int***)malloc(sizeof(int**) * 2);
	for(r = 0; r<2; r++)
	{
		ary[r] = (int**)malloc(sizeof(int*) * 3);
		for(c = 0; c<3; c++)
			ary[r][c] = (int*)malloc(sizeof(int) * 4);
	}

	for (s=0; s<2; s++)
	{
		for (r=0; r<3; r++)
		{
			for (c=0; c<4; c++)
			{
				ary[s][r][c]=s+r+c;
				printf("%d ", ary[s][r][c]);
			}
		printf("\n");
		}
	printf("\n");
	}

	printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D, 2, 3, 4));
	printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D, 2, 3, 4));
	printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D, 2, 3, 4));
	printf("sumAry3D_f3() %d\n", sumAry3D_f4(ary, 2, 3, 4));
	printf("sumAry3D_f3() %d\n", sumAry3D_f5(&ary, 2, 3, 4));

	freeAry3D(ary,2,3);

	return 0;
}

int sumAry3D_f1( int ary[2][3][4], int SEC, int ROW, int COL )
{
	int s, r, c;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += ary[s][r][c];
	return a;
}

int sumAry3D_f2( int ary[][3][4], int SEC, int ROW, int COL )
{
	int s, r, c;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += ary[s][r][c];
	return a;
}

int sumAry3D_f3( int (*ary)[3][4], int SEC, int ROW, int COL )
{
	int s, r, c;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += ary[s][r][c];
	return a;
}

int sumAry3D_f4( int ***ary, int SEC, int ROW, int COL )
{
	int s, r, c = 0;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += *(*(*ary+s)+r)+c;
	return a;
}

int sumAry3D_f5( int ****ary, int SEC, int ROW, int COL )
{
	int s, r, c = 0;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += *(*(**ary+s)+r)+c; //(*ary)[s][r][c]

	return a;
}

void freeAry3D( int ***ary, int a, int b )
{
	int r,c;

	for(r = 0; r<a; r++)
	{
		for(c = 0; c<b; c++)
			free(ary[r][c]);
		free(ary[r]); //순서주의!!!!!!!!!!
	}
	free(ary);
	printf("3d array free");
}
