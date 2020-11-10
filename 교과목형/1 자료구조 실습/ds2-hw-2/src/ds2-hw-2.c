#include <stdio.h>
#include <stdlib.h>

int func(int num){
	int *pnum = (int *)malloc(sizeof(int));
	*pnum = num;
	printf(" %d\n", *pnum);
	return pnum;
}

int func1(){
	int *p = (int *)malloc(sizeof(int));
	*p = 0;
	return p;
}

int *func2(int *num){
	*num = 100;
	return num;
}

int **func3(int **num){
	**num = 200;
	return num;
}

int main(void) {

	// 실행

	int num = 1;
	int *pnum= func(num);
	printf("%d\n", num);
	free(pnum);

// 실행

	int *pNum = func1();
	printf("%d\n", *pNum);
	printf("%d\n", *func2(pNum));
	printf("%d\n", **func3(&pNum));
	free(pNum);

	return 0;
}
