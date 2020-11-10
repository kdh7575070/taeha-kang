#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2001

// 2015112806 ������
// ������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�

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

		}while (clock()-start<1000); //1�ʵ��ȹݺ��ؼ�����
		
		duration = ((double)(clock() - start))/CLOCKS_PER_SEC; //�Ѱɸ��ð� - 1�� �������ϱ� �� ���ʳ�������
		duration /= repetitions; //reptitions(��� �ݺ��ߴ���)���� ������ 1���� ���� �ɷȴ��� ����� ����

		printf("%6ld   %9ld   %f\n", n, repetitions, duration);
		fprintf(fpOut, "%6ld   %9ld   %f\n", n, repetitions, duration);
		if (n == 100) step = 100;
	}
}
