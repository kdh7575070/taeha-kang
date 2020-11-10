#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

int cnt=0;
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols)
{
	int i, j;
	for (i = 0; i<rows;i++){
		cnt++;
		for (j = 0; j<cols;j++){
			cnt++;
			c[i][j] = a[i][j]+b[i][j];
			cnt++;
		}cnt++;
	}cnt++;
}

int main(void)
{

	int n, i,j;
	int a[3][4];
	int b[3][4];
	int c[3][4];

	FILE *fpIn1 = fopen("a.txt","r");
	FILE *fpIn2 = fopen("b.txt","r");
	FILE *fpOut = fopen("c.txt","w");

	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			fscanf(fpIn1, "%d", &n);
			a[i][j] = n;
		}
	}
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			fscanf(fpIn2, "%d", &n);
			b[i][j] = n;
		}
	}
	add(a, b, c, 3, 4);
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ", c[i][j]);
			fprintf(fpOut, "%d ", c[i][j]);
		}
		fprintf(fpOut, "\n");
	}
	printf("\ncnt = %d ", cnt);

	fclose(fpIn1);
	fclose(fpIn2);
	fclose(fpOut);

	return 0;
}
