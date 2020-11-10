#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 10
#define TABLE_SIZE 11

typedef struct element{
						char name[MAX_STRING];
						int key;
				} element;

element *ht[TABLE_SIZE];

int cnt;

int stringToInt(char *key)
{
	//아스키value들을 다 더하는 것임
	int number = 0;
	while(*key) number += *key++;
	return number;
}

int hashFunction(char *key)
{
	return stringToInt(key) % TABLE_SIZE;
}

element* search(int k)
{
	cnt = 1;
	int homeBucket, currentBucket;
	homeBucket = k % TABLE_SIZE; // 0 <= h(k) < b

	for(currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
	{
		currentBucket = (currentBucket + 1) % TABLE_SIZE;
		cnt++;
		if (currentBucket == homeBucket) return NULL; //꽉차서 한바퀴 돌았다 근데도 없다
	}

	printf("comparison %d \n", cnt);

	if (ht[currentBucket] && ht[currentBucket]->key ==k)
		return ht[currentBucket]; //for문 빠져 나온 경우 - 찾았다

	return NULL; //for, if문 조건 위배 경우 - ht[currentBucket]자체가 텅비었다
}

int insert(element *item)
{
    int homeBucket, currentBucket;
    currentBucket = homeBucket = hashFunction(item->name);

    while(ht[currentBucket])
    {
        if((strcmp(item->name, ht[currentBucket]->name))==0)
        {
            printf("이름이 중복되었습니다\n");
            return -1;
        }

        currentBucket = (currentBucket+1) % TABLE_SIZE;

        if(currentBucket==homeBucket) //테이블이 가득 참
        {
            printf("테이블이 가득찼습니다\n");
            return -1;
        }
    }
    ht[currentBucket] = item; //빈 버켓을 찾아 while문 나온 케이스 - 애초에 버켓이 비어있었다면 바로 정상삽입될 것
    return 1;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");

	int i;
	char a[10];
	element *item;

	while(!feof(fp))
	{
		item = malloc(sizeof(element)); //안에 안넣어서 계속계속 초기화 해줘야죠
		fscanf(fp, "%s", a);
		strcpy(item->name, a);
		item->key = stringToInt(a);
//		printf("%10s %5d %5d\n", item->name, item->key, hashFunction(item->name));
		insert(item);
	}

	for(i=0; i<TABLE_SIZE; i++)
	{
		if(ht[i]) printf("hashtable[%d] : %10s %5d \n", i, ht[i]->name, ht[i]->key);
		else printf("hashtable[%d] : \n", i);
	}

	//setvbuf(stdout, NULL, _IONBF, 0); //콘솔창띄우기-이클립스
	//setvbuf(stderr, NULL, _IONBF, 0); //콘솔창띄우기-이클립스

	char exit[10] = "Z"; //탈출문자

	char x[10];
	int check;

	while(1)
	{
		check = 0;
		gets(x); //"float" "define" "bbb" "Z";
		printf("%s을 탐색\n", x);

		if(!(strcmp(x,exit))) return 0; //탈출

		for(i=0; i<TABLE_SIZE; i++)
		{
			if(ht[i] && !(strcmp(x, ht[i]->name))) {search(stringToInt(x)); check = 1;}
		}
		if (check == 0) printf("없습니다\n");
	}
}
