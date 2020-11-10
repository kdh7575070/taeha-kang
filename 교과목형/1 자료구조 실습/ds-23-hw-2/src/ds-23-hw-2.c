#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 10
#define TABLE_SIZE 11

typedef struct element{
					char name[MAX_STRING];
					int key;
				} element;

typedef struct node *nodePointer;
typedef struct node{
					element data;
					nodePointer link;
}node;

nodePointer ht[TABLE_SIZE];

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

	nodePointer current;

	int homeBucket;
	homeBucket = k % TABLE_SIZE; // 0 <= h(k) < b

	for(current = ht[homeBucket]; current; current = current->link)
	{
		if (current->data.key == k) {printf("comparison %d \n", cnt); return &current->data;}
		cnt++;
	}

	printf("comparison %d \n", cnt); return NULL;
}

int insert(nodePointer temp)
{
    nodePointer current;
    int homeBucket = hashFunction(temp->data.name);

    if(ht[homeBucket]) //요거 잊지마..!
    {
		current = ht[homeBucket];
		while(current->link)
		{
			if((strcmp(temp->data.name, current->link->data.name))==0)
			{
				printf("이름이 중복되었습니다\n");
				return -1;
			}
			current = current->link;
		}
		current->link = temp;
    }

    else ht[homeBucket] = temp;
    return 1;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");

	int i;

	char a[10];
	nodePointer temp;

	while(!feof(fp))
	{
		temp = malloc(sizeof(node));
		fscanf(fp, "%s", a);
		strcpy(temp->data.name, a);
		temp->data.key = stringToInt(a);
		temp->link = NULL; //제발꼭....!
//		printf("%10s %5d %5d\n", temp->data.name, temp->data.key, hashFunction(temp->data.name));
		insert(temp);
	}

	nodePointer node;

	for(i=0; i<TABLE_SIZE; i++)
	{
		if(ht[i])
		{
			printf("hashtable[%d] : ", i);
			for(node = ht[i]; node; node = node->link) // node = node->link 문법주의
			{
				printf("%10s %3d ", node->data.name, node->data.key);
			}
			printf("\n");
		}
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
			if(ht[i])
			{
				for(node = ht[i]; node; node = node->link) // node = node->link 문법주의
				{
					if(!(strcmp(x, node->data.name))) {search(stringToInt(x)); check = 1;} //printf(search(stringToInt(x))->name);
				}
			}
		}
		if (check == 0) printf("없습니다\n");
	}
}
