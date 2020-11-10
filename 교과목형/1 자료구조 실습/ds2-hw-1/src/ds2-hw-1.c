#include <stdio.h>
#include <stdlib.h>

void swap1(int, int);
void swap2(int*, int*);
void swap3(int**, int**);

void func(int num){
	int *pNum = (int *)malloc(sizeof(int));
	*pNum = num;
	printf(" %d\n", *pNum);
}

int main(void) {

// 실행

	int a, b;

	int *pa = &a;
	int **ppa = &pa;

	int *pb = &b;
	int **ppb = &pb;

	a=1; b=2; swap1(a,b);
	printf("After calling swap1(a,b), a: %d, b:%d\n\n",a,b);
	a=1; b=2; swap2(&a,&b);
	printf("After calling swap2(&a,&b), a: %d, b:%d\n\n",a,b);
	a=1; b=2; swap2(pa,pb);
	printf("After calling swap2(pa,pb), a: %d, b:%d\n\n",a,b);
	a=1; b=2; swap3(&pa,&pb);
	printf("After calling swap3(&pa,&pb), a: %d, b:%d\n\n",a,b);
	a=1; b=2; swap3(ppa,ppb);
	printf("After calling swap3(ppa,ppb), a: %d, b:%d\n\n",a,b);

// 실행

	int num = 1;
	func(num);
	printf(" %d\n", num);

	return 0;
}

void swap1(int a , int b){

	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swap2(int *a, int *b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap3(int **a, int **b){
	int tmp;

	tmp = **a;
	**a = **b;
	**b = tmp;
}
