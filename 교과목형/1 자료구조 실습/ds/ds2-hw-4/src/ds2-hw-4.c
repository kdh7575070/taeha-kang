#include <stdio.h>
#include <stdlib.h>

int alloc(int n)
{
	int * p = (int*)malloc(sizeof(int)*n);
	return p;
}

void input(int *p, int num, FILE *fpIn)
{
	int i,j;
	for (i = 0; i<num ; i++){
		fscanf(fpIn, "%d", &j);
		p[i] = j;
	}
}

void increase(int *p, int num)
{
	int i;
	for (i = 0; i<num ; i++){
		p[i] += 1;
	}
}

void output(int *p, int num, FILE *fpOut){
	int i;
	fprintf(fpOut, "%d\n", num);
	for (i = 0; i<num ; i++){
		fprintf(fpOut, "%d ", p[i]);
	}
}

int main(void) {

	int num, *pNum;

	FILE *fpIn = fopen("input.txt","r");
	FILE *fpOut = fopen("output.txt","w");

	fscanf(fpIn, "%d", &num);
	pNum = alloc(num);

	input(pNum, num, fpIn);
	increase(pNum, num);
	output(pNum, num, fpOut);

	free(pNum);
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
