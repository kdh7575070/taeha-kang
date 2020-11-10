#include <stdio.h>
#include <stdlib.h>

// 2015112806 강태하
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

int sumAry3D_f1( int [][2][3], int , int , int );
int sumAry3D_f2( int [][2][3], int , int , int );
int sumAry3D_f3( int [][2][3], int , int , int );

int main(int argc, char *argv[]) {

//배열포인터를 이용해서 3차원 배열 출력

	int i, j, k;

	int aaa[][2][3] = {{{1,2,3},{4,5,6}},{{7,8,9},{9,10,11}}};
	int (*paaa)[2][3] = aaa;

	for(i=0; i<2;i++){
		for(j=0; j<2; j++){
			for(k=0; k<3; k++){
				printf("%d ", *(paaa[i][j]+k));
				//printf("%d ", *(*(paaa[i]+j)+k));
				//printf("%d ", *(*(*(paaa+i)+j)+k));
			}
		printf("\n");
		}
	printf("\n");
	}

//포인터 배열의 배열요소를 이용한 a,b,c출력

	int a = 2;
	int b = 3;
	int c = 4;

	int *d[] = { &a, &b, &c };

	printf("\n a : %d b : %d c : %d", *d[0], *d[1], *d[2]);

// 함수에 사용될때

	int ary3D[][2][3] = {{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};

	printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D, 2, 2, 3));
	printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D, 2, 2, 3));
	printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D, 2, 2, 3));

	return 0;
}

int sumAry3D_f1( int ary[][2][3], int SEC, int ROW, int COL )
{
	int s, r, c;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += ary[s][r][c];
	return a;
}

int sumAry3D_f2( int (*ary)[2][3], int SEC, int ROW, int COL )
{
	int s, r, c;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += ary[s][r][c];
	return a;
}

int sumAry3D_f3( int ary[2][2][3], int SEC, int ROW, int COL )
{
	int s, r, c;
	int a = 0;

	for(s=0; s<SEC; s++)
		for(r=0; r<ROW; r++)
			for(c=0; c<COL; c++)
				a += ary[s][r][c];
	return a;
}
