#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 50
#define FALSE 0
#define TRUE 1

typedef struct graphNode *graphPointer;
typedef struct graphNode {
							int vertex;
							graphPointer link;
				}graphNode;
graphPointer adjList[MAX_VERTEX];

short int visited[MAX_VERTEX];

void addEdge(int a, int b)
{
	graphPointer node1;
	graphPointer node2;

	node1 = malloc(sizeof(graphNode));
	node2 = malloc(sizeof(graphNode));

	node1->vertex = b;
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

	node2->vertex = a;
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
void dfs(int v)
{
	graphPointer w;
	visited[v] = TRUE;
	printf("%5d", v);
	for (w = adjList[v]; w; w = w->link)
	{
		if(!visited[w->vertex]) {dfs(w->vertex);}
	}
}

void main()
{
	int vertex, edge;
	int a,b;
	int i, j;

	FILE *fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &vertex);
	fscanf(fp, "%d", &edge);

	for(i = 0; i < vertex; i++)
	{
		adjList[i] = NULL;
	} //생략가능

	//while(!feof(fp))
	for(i = 0; i < edge; i++)
	{
		fscanf(fp, "%d %d", &a, &b);
		addEdge(a,b);
	}

	graphPointer w;
	i=0;
	for(i = 0; i < vertex; i++)
	{
		printf("adjList[%d]:", i);
		w = adjList[i];
		while(w)
		{
			printf("  %d", w->vertex);
			w = w->link;
		}
		printf("\n");
	}

	for(i = 0; i < vertex; i++)
	{
		printf("dfs[%d]: ", i);
		dfs(i);
		printf("\n");
		for(j = 0; j<vertex; j++) visited[j]=0;
	}

	fclose(fp);
}
