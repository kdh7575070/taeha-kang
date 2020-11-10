#include <stdio.h>
#include <stdlib.h>

int cnt;
float rsum(float list[], int n)
{
	cnt++;
	if(n){
		cnt++;
		return rsum(list, n-1) + list[n-1];
	}
	cnt++;
	return 0;
}

int main(void) {

	int n=0, i;
	float a[n];
	float m;

	FILE *fpIn = fopen("a.txt","r");

	while(!feof(fpIn)){ //¿ä ¹®¹ý
		fscanf(fpIn, "%f", &m);
		a[n] = m;
		n++;
	}

	m = rsum(a,n);

	printf("%f", m);
	printf("\ncnt = %d ", cnt);

	fclose(fpIn);

	return 0;
}
