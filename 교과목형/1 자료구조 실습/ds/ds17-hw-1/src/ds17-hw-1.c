#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 50
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct graphNode *graphPointer;
typedef struct graphNode {
							int data;
							graphPointer link;
				}graphNode;
graphPointer adjList[MAX_VERTEX];

void addundEdge(int a, int b)
{
	graphPointer node1;
	graphPointer node2;

	MALLOC(node1, sizeof(*node1));
	MALLOC(node2, sizeof(*node2));

	node1->data = b;
	if( adjList[a] == NULL )
	{
		node1->link = NULL;
		adjList[a] = node1;
	}
	else
	{
		node1->link = adjList[a];
		adjList[a] = node1;
	}

	node2->data = a;
	if( adjList[b] == NULL )
	{
		node2->link = NULL;
		adjList[b] = node2;
	}
	else
	{
		node2->link = adjList[b];
		adjList[b] = node2;
	}
}

void adddirEdge(int a, int b)
{
	graphPointer node1;

	MALLOC(node1, sizeof(*node1));

	node1->data = b;
	if( adjList[a] == NULL )
	{
		node1->link = NULL;
		adjList[a] = node1;
	}
	else
	{
		node1->link = adjList[a];
		adjList[a] = node1;
	}
}

int main()
{
	char c;
	int vertex, edge;
	int a,b;
	int i;

	FILE *fp = fopen("input3.txt", "r");

	fscanf(fp, "%c", &c);
	fscanf(fp, "%d", &vertex);
	fscanf(fp, "%d", &edge);

	//adjList = (graphNode*)malloc(sizeof(graphNode)*vertex);

	for(i = 0; i < vertex; i++)
	{
		adjList[i] = NULL;
	} //생략가능

	//while(!feof(fp))
	for(i = 0; i < edge; i++)
	{
		fscanf(fp, "%d %d", &a, &b);
		if(c=='u') addundEdge(a,b);
		else if(c=='d') adddirEdge(a,b);
	}

	i=0;
	for(i = 0; i < vertex; i++)
	{
		printf("adjList[%d]:", i);
		while(adjList[i])
		{
			printf("  %d", adjList[i]->data);
			adjList[i] = adjList[i]->link;
		}
		printf("\n");
	}//출력

	fclose(fp);

	return 0;
}
