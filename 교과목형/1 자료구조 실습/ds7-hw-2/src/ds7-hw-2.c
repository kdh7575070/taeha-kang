#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 11

typedef struct {
				int id; // unique id
				char name[MAX_NAME_SIZE]; // last name
			} element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

element queueEmpty()
{
	printf("EMPTY\n");
	queue[++rear].id = -1;
	return queue[rear];
}

element deleteq()
{
	if (front == rear)
		return queueEmpty();
	return queue[++front];
}

void queueFull()
{
	int i, j, length;
	length = rear - front;

	if (front == -1)
	{
		printf("FULL\n");
		while(front<rear)
		{
			printf("%d %s\n", queue[front+1].id, queue[front+1].name);
			deleteq();
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("SHITF\n");
		for (i = 0; i < MAX_QUEUE_SIZE-length; i++) // �̵� Ƚ�� ���
		{
			for (j=length; j>0; j--) // �·��̵�
			{
				queue[rear-j] = queue[rear+1-j];
				printf("%d...",j);
			}
			front--;
			rear--;
			printf("%d��°shift\n", i+1);
		}
	}
}

void addq(element item)
{
	if (rear == MAX_QUEUE_SIZE-1)
		queueFull();
	queue[++rear] = item;
}

int main(void)
{
//����ť

	char input[80];				// input a line of string
	char * delimiter = " \n";	// delimiter for tokenizing
	char * op = NULL;			// push or pop
	element student;

	//setvbuf(stdout, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����
	//setvbuf(stderr, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����

	printf("MAX SIZE IS 5\n");
	printf("op id name ������ �ۼ�\n");
	printf("*******************\n");

	while (1)
	{
		gets(input);
		op = strtok(input, delimiter); // del ���� �ڸ���
		if (!strcmp(op, "add"))
		{
			student.id = atoi(strtok(NULL, delimiter));
			strcpy(student.name, strtok(NULL, delimiter));
			addq(student);
			//�ƴϸ�
			//sscanf(input + strlen(op) + 1, "%d %s", &student.id, student.name);
			//input(�ּ�) + strlen(op) + 1�� scan�������� �����ͷ� ��Ÿ���ִ� ��
			//������ġ(input)+4(op����)�ϸ� Ŀ����  push(���)4 Kang
			//������������ 1�� ���ؾ� 4�� ����Ű�� �Ǹ鼭 4���� ���´�!!
		}
		else if (!strcmp(op, "delete"))
			deleteq();
		else if (!strcmp(op, "stop"))
			break;
		else
			printf("wrong command! try again!\n");
	}

	return 0;
}
