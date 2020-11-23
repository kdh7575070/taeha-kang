#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2001

// 2015112806 강태하
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

void main(void) {

	int i, n, step=10;
	int a[MAX_SIZE];
	clock_t start;
	double duration;
	FILE *fpOut = fopen("out.txt","w");

	fprintf(fpOut, "    n     repetitions   time\n");

	for (n=0; n<=2000; n += step){

		long repetitions = 0;
		start = clock();

		do
		{
			repetitions++;

			for(i=0; i<n;i++)
				a[i] = n-1;

			sort(a,n);

		}while (clock()-start<1000); //1초동안반복해서돌림
		
		duration = ((double)(clock() - start))/CLOCKS_PER_SEC; //총걸린시간 - 1초 돌렸으니까 다 일초나오겠지
		duration /= repetitions; //reptitions(몇번 반복했는지)으로 나누면 1번에 몇초 걸렸는지 평균이 나옴

		printf("%6ld   %9ld   %f\n", n, repetitions, duration);
		fprintf(fpOut, "%6ld   %9ld   %f\n", n, repetitions, duration);
		if (n == 100) step = 100;
	}
}
