#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define INF_NUM 10000

// min값이 이기는 winner tree

// 1. 첫 항들로 토너먼트 구성 -> 토너먼트 실행
// 2. 항을 하나씩 올리면서 트리 전체를 재조정

int nums[ MAX_SIZE+1 ][11] = { 0 }; // keys to sort
int winTree[ 2 * MAX_SIZE ] = { 0 }; // winner tree

int sortedIdx[ MAX_SIZE+1 ] = { 0 }; // sorted idx
int sorted[ MAX_SIZE*10+1 ] = { 0 }; // final result
//배열로 링크를 표시한다

void initWinner(int cur, int k, int winTree[]);
void adjustWinner(int min, int k, int winTree[]);

int main(void)
{
	int a = 2;
	int k = 8;
	int i, j;

	srand(a);

	for(j=1; j<=k; j++)
	{//랜덤배열 만들어 1씩증가하는 형태
		nums[1][j] = (rand()%100)+1 ;

		for(i=2;i<=10; i++)
			nums[i][j]=nums[1][j]+i-1;
	}

	for(i=1; i<=10; i++)
	{//출력
		for(j=1; j<=k; j++)
			printf("%5d ", nums[i][j]);
		printf("\n");
	}
	printf("\n");

	for(j=1; j<=k; j++)
	{//초기화
		sortedIdx[j] = 1;
		winTree[j] = 1;
	}

	i = 1;
	for(j=k; j<k*2; j++)
	{//초기화
		winTree[j] = i;
		i++;
	}

	initWinner(1, k, winTree); //초기위너트리구성

	for(i=1; i<k*2; i++)
		printf("%d ", winTree[i]);
	printf("\n\n"); //출력

	//
	for(i=1; i<=k*10; i++)
	{ //후기위너트리 구성

		sorted[i] = nums[sortedIdx[winTree[1]]][winTree[1]]; //승자출력

		if (sortedIdx[winTree[1]]==10) nums[sortedIdx[winTree[1]]][winTree[1]]=1000; //다음 올릴 주자를 위해 sortedIdx 재구성
		else sortedIdx[winTree[1]]++;

		adjustWinner(1, k, winTree);
	}

	int cnt = 0;
	for(i=1; i<=k*10; i++)
	{ //전체출력
		printf("%5d ", sorted[i]);
		cnt++;
		if(cnt%8==0) printf("\n");
	}
	printf("\n");
}

void initWinner(int cur, int k, int winTree[])
{
	if(cur*2<k) initWinner(cur*2, k, winTree);
	if(cur*2<k) initWinner(cur*2+1, k, winTree);

	if(nums[sortedIdx[winTree[cur*2]]][winTree[cur*2]] > nums[sortedIdx[winTree[cur*2+1]]][winTree[cur*2+1]])
		winTree[cur] = winTree[cur*2+1];
	else
		winTree[cur] = winTree[cur*2];
}

void adjustWinner(int min, int k, int winTree[])
{
	if(min*2<k) initWinner(min*2, k, winTree);
	if(min*2<k) initWinner(min*2+1, k, winTree);

	if(nums[sortedIdx[winTree[min*2]]][winTree[min*2]] > nums[sortedIdx[winTree[min*2+1]]][winTree[min*2+1]])
		winTree[min] = winTree[min*2+1];
	else
		winTree[min] = winTree[min*2];
}
