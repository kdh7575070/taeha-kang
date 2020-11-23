#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2001

void main(void) {

	int i, n, step=10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	FILE *fpOut = fopen("ing.txt","w");

	fprintf(fpOut, "    n    time\n");

	for (n=0; n<=2000; n += step){

		for(i=0; i<n;i++)
			a[i] = n-1;

		start = clock();
		sort(a,n);
		duration = ((double)(clock() - start))/CLOCKS_PER_SEC;
	
		fprintf(fpOut, "%6d   %f\n", n, duration);
		if(n==100) step = 100;
	}

}

