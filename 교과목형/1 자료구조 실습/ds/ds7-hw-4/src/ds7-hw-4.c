//동적큐

#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 11

typedef struct {
				int id; // unique id
				char name[MAX_NAME_SIZE]; // last name
			} element;

int capacity = 1;
element *queue;
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
		printf("reallocing...\n");
		capacity *= 2;
		queue = (element*)realloc(queue, capacity*(sizeof(*queue)));

	}
	else
	{
		printf("SHITF\n");
		for (i = 0; i < capacity-length; i++) // 이동 횟수 계산
		{
			for (j=length; j>0; j--) // 좌로이동
			{
				queue[rear-j] = queue[rear+1-j];
				printf("%d...",j);
			}
			front--;
			rear--;
			printf("%d번째shift\n", i+1);
		}
	}
}

void addq(element item)
{
	if (rear == capacity-1)
		queueFull();
	queue[++rear] = item;
}

void queueStop()
{
	printf("STOP\n");
	while(front<rear)
	{
		printf("%d %s\n", queue[front+1].id, queue[front+1].name);
		deleteq();
	}
	exit(EXIT_FAILURE);
}

int main(void)
{
	queue = (element*)malloc(capacity*(sizeof(*queue)));

	char input[80];				// 받아올 인풋
	char * delimiter = " \n";	// delimiter for tokenizing
	char * op = NULL;			// push or pop
	element student;

	//setvbuf(stdout, NULL, _IONBF, 0); //콘솔창띄우기-이클립스
	//setvbuf(stderr, NULL, _IONBF, 0); //콘솔창띄우기-이클립스

	printf("op id name 순서로 작성\n");
	printf("*******************\n");

	while (1)
	{
		gets(input); //input 스캔받아서
		op = strtok(input, delimiter); // del 기준 자르기
		if (!strcmp(op, "add"))
		{
			student.id = atoi(strtok(NULL, delimiter));
			strcpy(student.name, strtok(NULL, delimiter));
			addq(student);
			//아니면
			//sscanf(input + strlen(op) + 1, "%d %s", &student.id, student.name);
			//input(주소) + strlen(op) + 1이 scan시작점을 포인터로 나타내주는 것
			//시작위치(input)+4(op길이)하면 커서가  push(요기)4 Kang
			//띄워쓰기공간인 1을 더해야 4를 가르키게 되면서 4부터 들어온다!!
		}
		else if (!strcmp(op, "delete"))
			deleteq();
		else if (!strcmp(op, "stop"))
			queueStop();
		else
			printf("wrong command! try again!\n");
	}

	return 0;
}
