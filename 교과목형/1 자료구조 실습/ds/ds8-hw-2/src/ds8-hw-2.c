#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 11
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct {
				int id; // unique id
				char name[MAX_NAME_SIZE]; //last name
			} element;
element * queue;

int capacity = 2;
int rear = 0;
int front = 0;

element queueEmpty()
{
	printf("EMPTY\n");
	exit(EXIT_FAILURE);
	return queue[rear]; //필요없다
}
element deleteq()
{
	if (front == rear)
		return queueEmpty();
	front = (front+1)%capacity; //++대신 +%c
	return queue[front];
}
void copy(element *a, element *b, element *c)
{
	 int cnt = 0;
	 while(1)
	 {
		 if((*a).id == (*b).id) //a->b쪽으로 가다가 만난다
		 {
			 printf("copy 총 : %d회 \n", cnt);
			 break;
		 }
		 else
		 {
			 printf("copy 1회 \n");
			 (*c).id = (*a).id;
			 strcpy((*c).name, (*a).name);
			 a++; c++;
			 cnt++;
		 }
	 }
}

void queueFull()
{
	int start;
	element *newQueue;
	MALLOC(newQueue, 2*capacity*sizeof(*queue));

	//복사하기
	start = (front+1)%capacity; //++대신 +%c
	rear--;

	if (start < 2) //연속이동필요X start가 0또는 1임
		copy(queue+start, queue+start+capacity-1, newQueue);

	else
	{
		copy(queue+start, queue+capacity, newQueue);
		copy(queue, queue+rear+1, newQueue+capacity-start);
	}
	//변수조정
	front = 2*capacity-1;
	rear = capacity-1;
	capacity *= 2;

	free(queue);
	queue = newQueue;
    printf("NOW capacity : %d\n", capacity);
}

void addq(element item)
{
	rear = (rear+1)%capacity; //empty와 구분 위해서 뒤에서 더했던걸 앞에서 더함으로서 빈자리 한개남겨둔다
	if (rear == front)
		queueFull();
	queue[rear] = item;
}

int main(void)
{
//동적환형큐

	queue = (element*)malloc(capacity*(sizeof(*queue)));

	char input[80];				/// 받아올 인풋
	char * delimiter = " \n";	// delimiter for tokenizing
	char * op = NULL;			// push or pop
	element student;

	setvbuf(stdout, NULL, _IONBF, 0); //콘솔창띄우기-이클립스
	setvbuf(stderr, NULL, _IONBF, 0); //콘솔창띄우기-이클립스

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
		{
			deleteq();
			printf("%d %s deleted\n", queue[front].id, queue[front].name);
		}
		else if (!strcmp(op, "stop"))
			break;
		else
			printf("wrong command! try again!\n");
	}
	return 0;
}
