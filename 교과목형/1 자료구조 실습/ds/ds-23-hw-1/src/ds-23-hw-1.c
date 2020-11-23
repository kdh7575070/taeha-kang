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
		if (currentBucket == homeBucket) return NULL; //c��� -> ������ �ѹ��� ���Ҵ� �ٵ� ����
	}

	printf("comparison %d \n", cnt);

	if (ht[currentBucket] && ht[currentBucket]->key ==k) return ht[currentBucket]; //ã�Ҵ�

	return NULL; //b��� -> for�� ���� ���� ��� - �� ht[currentBucket]��  empty��
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
            printf("�̸��� �ߺ��Ǿ����ϴ�\n");
            return -1;
        }

        currentBucket = (homeBucket + randNum[i]) % TABLE_SIZE;
        i++;

        if(currentBucket==homeBucket) // ���̺��� ���� ��
        {
            printf("���̺��� ����á���ϴ�\n");
            return -1;
        }
    }
    ht[currentBucket] = item; // ������ ����ִٸ� �ٷ� ����
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
		item = malloc(sizeof(element)); //�ȿ� �ȳ־ ��Ӱ�� �ʱ�ȭ �������
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
			printf("\n%d�� ����մϴ�\n", ht[x]->key);
			search(ht[x]->key);
		}
	}

	printf("\n2�� ����մϴ�\n");
	int y = 2;
	int check = 0;

	for(i=0; i<TABLE_SIZE; i++)
	{
		if(ht[i] && (y == ht[i]->key)) {search(y); check = 1;}
	}
	if (check == 0) printf("�����ϴ�\n");
	return 0;
}
