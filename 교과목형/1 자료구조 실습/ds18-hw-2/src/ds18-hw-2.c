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

graphPointer front, rear;

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
void addq(int i)
{
	graphPointer temp;
	temp = malloc(sizeof(graphNode));

	temp->vertex = i;
	temp->link = NULL;

	if(front)
		rear->link = temp;
	else
		front = temp;
	rear = temp;
}
int queueEmpty()
{
	printf("empty");
	exit(EXIT_FAILURE);
}
int deleteq()
{
	graphPointer temp = front;
	int i;

	if(!temp)
		return queueEmpty();

	i = temp->vertex;
	front = temp->link;

	free(temp);
	return i;
}
void bfs(int v)
{
	graphPointer w;
	front = rear = NULL;
	printf("%5d", v);
	visited[v] = TRUE;
	addq(v);
	while(front){
		v = deleteq();
		for (w = adjList[v]; w; w = w->link)
		{
			if(!visited[w->vertex])
			{
				printf("%5d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
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
		printf("bfs[%d]: ", i);
		bfs(i);
		printf("\n");
		for(j = 0; j<vertex; j++) visited[j]=0;
	}

	fclose(fp);
}
