#include <stdio.h>
#include <stdlib.h>

#define IS_EMPTY(first)(!(first))
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node *nodePointer;
typedef struct node {
					nodePointer llink;
					int data;
					nodePointer rlink;
				} node;

nodePointer header = NULL;

//���� ������ �յڷ� �Դٰ��� �� �� �ִ�!!

void dinsert(nodePointer node, int a) //���������� ����
{
	nodePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = a;

	temp->llink = node;
	temp->rlink = node->rlink;
	node->rlink->llink = temp;
	node->rlink = temp;
}

void ddelete(nodePointer node, nodePointer deleted)
{
	if(node == deleted) //������϶�
		printf("Deletion of header node not permitted.\n");
	else
	{
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
	}
	free(deleted);
}

void printBList(nodePointer node)
{
	nodePointer temp;
	int cnt=0;

	if(header) //empty list �ƴѰ��
	{
		temp = node->rlink;
		do{
			printf("%d ", temp->data);
			temp = temp->rlink;

			cnt++;
			if(cnt%10==0) puts("");

		}while(temp != header); //ó���� header���� ����ϹǷ� do�� ���� �ؼ� �Űܾ� �Ѵ�
	}
	else printf("None");
}

void printBListB(nodePointer node)
{
	nodePointer temp;
	int cnt=0;

	if(header) //empty list �ƴѰ��
	{
		temp = node->llink; //��������
		do{
			printf("%d ", temp->data);
			temp = temp->llink;

			cnt++;
			if(cnt%10==0) puts("");

		}while(temp != header);
	}
	else printf("None");
}

int main(void)
{
	int a;
	FILE *fpIn = fopen("input.txt","r");

	MALLOC(header, sizeof(*header));
    header->llink = header;
    header->data = -1;
    header->rlink = header;

    printf("Regular\n");
	while( !feof(fpIn) )
	{

		fscanf(fpIn, "%d", &a);
		dinsert(header->llink, a); //l�ΰ���!!
	}

	printBList(header);
	puts("");
	printBListB(header);
	puts("");


	printf("Deleted 1\n");
	//�ѹ������鼭 50���� ��� ���ֱ�
	nodePointer delete_node;
	nodePointer next; //delete �������� �޾��� ���������
	delete_node = header->rlink;
	do{
	   next = delete_node->rlink; //next��� link�̵� ���ָ�? ���� ��尡 free�ǹǷ� �̵��� �ȵ���
	   if (delete_node->data <= 50) ddelete(header, delete_node);
	      delete_node = next;
	} while (delete_node != header);

	printBList(header);
	puts("\n");
	printBListB(header);
	puts("\n");

	// ��ü��� ����
	nodePointer delete_node2;
	nodePointer next2;
	delete_node2 = header->rlink;
	do{
	   next2 = delete_node2->rlink;
	   ddelete(header, delete_node2);
	   delete_node2 = next2;
	} while (delete_node2 != header);

	printBList(header);
	puts("\n");
	printBListB(header);
	puts("");

	fclose(fpIn);

	return 0;
}
