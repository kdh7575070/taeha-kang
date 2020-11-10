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

//이중 연결은 앞뒤로 왔다갔다 할 수 있다!!

void dinsert(nodePointer node, int a) //오른쪽으로 삽입
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
	if(node == deleted) //헤더뿐일때
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

	if(header) //empty list 아닌경우
	{
		temp = node->rlink;
		do{
			printf("%d ", temp->data);
			temp = temp->rlink;

			cnt++;
			if(cnt%10==0) puts("");

		}while(temp != header); //처음에 header에서 출발하므로 do를 먼저 해서 옮겨야 한다
	}
	else printf("None");
}

void printBListB(nodePointer node)
{
	nodePointer temp;
	int cnt=0;

	if(header) //empty list 아닌경우
	{
		temp = node->llink; //백워드출력
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
		dinsert(header->llink, a); //l로간다!!
	}

	printBList(header);
	puts("");
	printBListB(header);
	puts("");


	printf("Deleted 1\n");
	//한바퀴돌면서 50이하 노드 없애기
	nodePointer delete_node;
	nodePointer next; //delete 다음꺼를 받아줄 노드포인터
	delete_node = header->rlink;
	do{
	   next = delete_node->rlink; //next대신 link이동 해주면? 원래 노드가 free되므로 이동이 안되죠
	   if (delete_node->data <= 50) ddelete(header, delete_node);
	      delete_node = next;
	} while (delete_node != header);

	printBList(header);
	puts("\n");
	printBListB(header);
	puts("\n");

	// 전체노드 삭제
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
