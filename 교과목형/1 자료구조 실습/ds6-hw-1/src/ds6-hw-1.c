#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
#define COMPARE(x,y) (((x)<(y))? -1:((x)>(y))? 1 : 0)

typedef struct {
				float coef;
				int expon;
		    }term;

term terms[MAX_TERMS];
int avail = 0;

void attach(float coefficient, int exponent)
{

	if (avail >= MAX_TERMS)
	{
		printf("Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail].expon = exponent;
	avail++;
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
	float coefficient;
	*startD = avail;

	while(startA <= finishA && startB <= finishB)
	{
		switch(COMPARE((terms[startA].expon),(terms[startB].expon)))
		{
			case -1:
				attach(terms[startB].coef, terms[startB].expon);
				startB++;
				break;

			case 0:
				coefficient = terms[startA].coef + terms[startB].coef;
				if(coefficient) attach(coefficient, terms[startA].expon);
				startA++;
				startB++;
				break;

			case 1:
				attach(terms[startA].coef, terms[startA].expon);
				startA++;
		}
	}

	for(; startA <= finishA ; startA++)
		attach(terms[startA].coef, terms[startA].expon);

	for(; startB <= finishB ; startB++)
		attach(terms[startB].coef, terms[startB].expon);

	*finishD = avail-1;
}

int main(void)
{
//다항식비교

	FILE *fpIn = fopen("input.txt","r");

	int num1, num2;
	int i;
	float c; int e;
	int start=0, finish=0;

	fscanf(fpIn, "%d", &num1);
	printf("%d ", num1);

	fscanf(fpIn, "%d", &num2);
	printf("%d ", num2);
	printf("\n");

	avail = num1+num2;

	for(i=0; i<=avail; i++)
	{
		fscanf(fpIn, "%f", &c);
		terms[i].coef = c;
		printf("%f ", terms[i].coef);

		fscanf(fpIn, "%d", &e);
		terms[i].expon = e;
		printf("%d ", terms[i].expon);
		printf("\n");
	}

	padd(0, num1-1, num1, num1+num2-1, &start, &finish);

	printf("D(x)=A(x)+B(x)\n");

	for(i=start; i<= finish ; i++)
		printf(("%.1fx^%d + "), terms[i].coef, terms[i].expon );

	printf("\b\b\b\b\b\b");

	fclose(fpIn);

	return 0;
}
