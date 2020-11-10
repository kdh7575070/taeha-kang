#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 8

typedef struct element{
						int key;
				} element;

element *ht[TABLE_SIZE];
int randNum[TABLE_SIZE-1];
int cnt;

int hashFunction(int k)
{
	return k % TABLE_SIZE;
}

element* search(int k)
{
	int i=1; cnt=1;

	int homeBucket, currentBucket;
	homeBucket = hashFunction(k); // 0 <= h(k) < b

	for(currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
	{
		currentBucket = (homeBucket + randNum[i]) % TABLE_SIZE;
		i++; cnt++;
		if (currentBucket == homeBucket) return NULL; //c경우 -> 꽉차서 한바퀴 돌았다 근데 없다
	}

	printf("comparison %d \n", cnt);

	if (ht[currentBucket] && ht[currentBucket]->key ==k) return ht[currentBucket]; //찾았다

	return NULL; //b경우 -> for문 조건 위배 경우 - 즉 ht[currentBucket]가  empty다
}

int insert(element *item)
{
	int i=1;

    int homeBucket, currentBucket;
    currentBucket = homeBucket = hashFunction(item->key);

    while(ht[currentBucket])
    {
        if(item->key == ht[currentBucket]->key)
        {
            printf("이름이 중복되었습니다\n");
            return -1;
        }

        currentBucket = (homeBucket + randNum[i]) % TABLE_SIZE;
        i++;

        if(currentBucket==homeBucket) // 테이블이 가득 참
        {
            printf("테이블이 가득찼습니다\n");
            return -1;
        }
    }
    ht[currentBucket] = item; // 버켓이 비어있다면 바로 삽입
    return 1;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");

	int a;
	int i, j;
	element *item;

	srand(1);

	for(i=1; i<TABLE_SIZE; i++)
	{
		randNum[i] = (rand()%(TABLE_SIZE-1))+1;

		for (j=1; j < i; j++) {
			if (randNum[i] == randNum[j]) {
				i--;
				break;
			}
		}
	}

	for(i=1; i<TABLE_SIZE; i++) printf("randNum[%d]: %d\n", i, randNum[i]);
	printf("\n");

	while(!feof(fp))
	{
		item = malloc(sizeof(element)); //안에 안넣어서 계속계속 초기화 해줘야죠
		fscanf(fp, "%d", &a);
		item->key = a;
		insert(item);
	}

	for(i=0; i<TABLE_SIZE; i++)
	{
		if(ht[i]) printf("hashtable[%d] : %5d \n", i, ht[i]->key);
		else printf("hashtable[%d] : \n", i);
	}

	int x;
	for(x=0; x<TABLE_SIZE; x++)
	{
		if(ht[x])
		{
			printf("\n%d을 출력합니다\n", ht[x]->key);
			search(ht[x]->key);
		}
	}

	printf("\n2를 출력합니다\n");
	int y = 2;
	int check = 0;

	for(i=0; i<TABLE_SIZE; i++)
	{
		if(ht[i] && (y == ht[i]->key)) {search(y); check = 1;}
	}
	if (check == 0) printf("없습니다\n");
	return 0;
}
