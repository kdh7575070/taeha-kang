#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_EMPTY(first)(!(first))
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct listNode *listPointer;
typedef struct listNode {
						char data[4]; //3�ϸ� �� �ȵ���?
						listPointer link;
				}listNode;

listPointer first = NULL; //�ʱ�ȭ ��!

//������ ���̽��� �����°� �� ������ �ٽ�
//�����δ� ���ʿ� first�� �����Ⱚ�� �ϳ� �־���� �����ϸ�
//first����� �����൵�ǹǷ�
//insert�� find���� �ξ� �����ϴ�

listPointer find(char *c) //�����ø� �ϴ°Ŷ� call by ref
{
	listPointer x = first; //first�� �ű�� �ȵ���

	if (x == NULL)
	{//(a)�ֺ���� ��
		printf("1");
	    return NULL;
	}

	if (x->data[0] > c[0])
	{ //(b)�����ڸ��� ���� ���� ��
		printf("2");
		return NULL;
	}

	//(c)������ �ű�� ���� �ڸ��� ã���� ��
	while(x->link) // 1 x�� �ϸ� ���������� ������ NULL�� �ȴ� ������ ������ϹǷ� x->link�� NULL�� �ƴѵ���
	{
		if (x->link->data[0] > c[0]) // 2 �׷��� (x->data > n)�� ������ ����  �� ������ũ���� ���Ѵ�
		{
			printf("3-1");
			return x;
		}
		//else(x->data <= n)��
		x = x->link;
		printf("0");
	}

	//(c)������ �Ű��� �� (while�� ������������)
	printf("3-2");
	return x; //
}

void insert(listPointer *first, listPointer x, char *data) //���� ������ �����ؾ��ϴ� �κ� first��  �ּ�ȣ�� x�� ����Ű�⸸��
{/* ü���� x ��� �ٷ� �ڿ� data ���� ������ �� ��带 �߰� */

	/* �� ��� �Ҵ� �� ������ ���� */
	listPointer temp;
	MALLOC(temp, sizeof(*temp));

	strcpy(temp->data, data);

	if( *first == NULL )
	{ /* (a) �ֺ� ����Ʈ�� ��� �߰� */
		temp->link = NULL;
		*first = temp;
		printf("a");
	}
	else
	{ /* ��� ���� ���� ����Ʈ�� �߰� */

		if ( x == NULL )
		{ // (b) ù ���� �߰�
			temp->link = *first;
			*first = temp;
			printf("b");
		}
		else
		{ // (c) �� ��° �̻� ��ġ�� �߰�
			temp->link = x->link;
			x->link = temp;
			printf("c");
		}
	}
}

void delete(listPointer *first, listPointer trail, listPointer x)
{
	if(trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void printList(listPointer first)
{
	int cnt = 0;
	printf("\nThe list contains: \n");
	for(; first; first = first->link)
	{
		printf("%s ", first->data);
		cnt++;
		if(cnt%10==0) printf("\n");
	}
}

int main(void)
{
	char c[4];
	listPointer x,y ;
	FILE *fpIn = fopen("input.txt","r");

	while( !feof(fpIn) )
	{
		fscanf(fpIn, "%s", c);
		x = find(c);// find insert position x
		insert(&first, x, c); // insert data first after node x
	}

	printList(first);

	printf("\n\n");
	y = find("GAT"); //y�� BAT�� ����Ų��
	//GAT�� �ҷ��� find����  if (x->link->data[0] >= c[0]) �� �������ָ�ȴ�
	delete(&first, y, y->link);

	printf("\nDeleted GAT--");
	printList(first);

	fclose(fpIn);

	return 0;
}
