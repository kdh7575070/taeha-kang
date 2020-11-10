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
	//�ƽ�Űvalue���� �� ���ϴ� ����
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
		if (currentBucket == homeBucket) return NULL; //������ �ѹ��� ���Ҵ� �ٵ��� ����
	}

	printf("comparison %d \n", cnt);

	if (ht[currentBucket] && ht[currentBucket]->key ==k)
		return ht[currentBucket]; //for�� ���� ���� ��� - ã�Ҵ�

	return NULL; //for, if�� ���� ���� ��� - ht[currentBucket]��ü�� �ֺ����
}

int insert(element *item)
{
    int homeBucket, currentBucket;
    currentBucket = homeBucket = hashFunction(item->name);

    while(ht[currentBucket])
    {
        if((strcmp(item->name, ht[currentBucket]->name))==0)
        {
            printf("�̸��� �ߺ��Ǿ����ϴ�\n");
            return -1;
        }

        currentBucket = (currentBucket+1) % TABLE_SIZE;

        if(currentBucket==homeBucket) //���̺��� ���� ��
        {
            printf("���̺��� ����á���ϴ�\n");
            return -1;
        }
    }
    ht[currentBucket] = item; //�� ������ ã�� while�� ���� ���̽� - ���ʿ� ������ ����־��ٸ� �ٷ� ������Ե� ��
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
		item = malloc(sizeof(element)); //�ȿ� �ȳ־ ��Ӱ�� �ʱ�ȭ �������
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

	//setvbuf(stdout, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����
	//setvbuf(stderr, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����

	char exit[10] = "Z"; //Ż�⹮��

	char x[10];
	int check;

	while(1)
	{
		check = 0;
		gets(x); //"float" "define" "bbb" "Z";
		printf("%s�� Ž��\n", x);

		if(!(strcmp(x,exit))) return 0; //Ż��

		for(i=0; i<TABLE_SIZE; i++)
		{
			if(ht[i] && !(strcmp(x, ht[i]->name))) {search(stringToInt(x)); check = 1;}
		}
		if (check == 0) printf("�����ϴ�\n");
	}
}
