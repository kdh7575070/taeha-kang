#include<stdio.h>
#include<stdlib.h>

typedef struct graphNode* graphPointer;

typedef struct graphNode {
							int data1;
							int data2;
							graphPointer link1;
							graphPointer link2;
}graphNode;

graphPointer* adjList; // �� �����Ҵ����� ����

graphPointer createEdge(int ver1, int ver2); // create the edge node
void addEdge(graphPointer temp, int ver1, int ver2);
void printMultilist(int numVertex, int choice); // choice: 0 or 1

int main()
{
    int vertex, edge;
    int a, b;
    int i;

    FILE* fp = fopen("input.txt", "r");

    fscanf(fp, "%d", &vertex);
    fscanf(fp, "%d", &edge);

    adjList = malloc(sizeof(graphPointer)*vertex);

    for (i = 0; i < vertex; i++)
    {
        adjList[i] = NULL;
    }//��������

    graphPointer temp;

    //while(!feof(fp))
    for (i = 0; i < edge; i++)
    {
        fscanf(fp, "%d %d", &a, &b);
        temp = createEdge(a, b);
        addEdge(temp, a, b);
    }

    for(int j = 0; j < vertex; j++)
        printMultilist(j, 0);
    printf("\n");

    //������ ������ �������� ���
    for(int j = 0; j < vertex; j++)
    	printMultilist(j, 1);
    printf("\n");

    fclose(fp);

    return 0;
}

graphPointer createEdge(int a, int b)
{
    graphPointer node1;
    node1 = malloc(sizeof(graphNode));

    node1->data1 = a;
    node1->data2 = b;
    node1->link1 = NULL; //�����ָ� return�Ҷ� ���� ����� - addEgde �Լ� �ȿ��� ó�����ָ� �������
    node1->link2 = NULL;

    return node1;
}

void addEdge(graphPointer temp, int a, int b)
{
    graphPointer cur;

    if (adjList[a] == NULL) adjList[a] = temp; //ù ���
    else
    {
    	cur = adjList[a]; //�߿�!! �����ǵ�� �ȵ�

        while (1)
        {
            if (cur->data1 == a)
            {
                if (cur->link1 == NULL) {cur->link1 = temp; break;}
                else cur = cur->link1;
            }
            else if(cur->data2 == a)
            {
                if (cur->link2 == NULL) {cur->link2 = temp; break;}
                else cur = cur->link2;
            }
            else break;
        }
    }

    // b�ʿ��� ����
    if (adjList[b] == NULL) adjList[b] = temp;
    else
    {
        cur = adjList[b];

        while (1)
        {
            if (cur->data1 == b)
            {
                if (cur->link1 == NULL) {cur->link1 = temp; break;}
                else cur = cur->link1;
            }
            else if (cur->data2 == b)
            {
                if (cur->link2 == NULL) {cur->link2 = temp; break;}
                else cur = cur->link2;
            }
            else break;
        }
    }
}
void printMultilist(int numVertex, int choice)
{
    graphPointer cur = adjList[numVertex];
    printf("adjList[%d]:", numVertex);
    if (choice == 0)
    {
       while (cur != NULL)
       {
          printf(" (%d, %d)", cur->data1, cur->data2);
          if (cur->data1 == numVertex)
             cur = cur->link1;
          else if (cur->data2 == numVertex)
             cur = cur->link2;
       }
       printf("\n");
    }
    else if (choice == 1) //������ ���� ����
    {
		while (cur != NULL)
		{
			if (cur->data1 == numVertex)
			{
				printf(" (%d, %d)", cur->data1, cur->data2);
				cur = cur->link1;
			}
			else if (cur->data2 == numVertex)
			{
				printf(" (%d, %d)", cur->data2, cur->data1);
				cur = cur->link2;
			}
		}
		printf("\n");
    }
}
