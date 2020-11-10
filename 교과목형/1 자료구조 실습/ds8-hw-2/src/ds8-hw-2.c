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
	return queue[rear]; //�ʿ����
}
element deleteq()
{
	if (front == rear)
		return queueEmpty();
	front = (front+1)%capacity; //++��� +%c
	return queue[front];
}
void copy(element *a, element *b, element *c)
{
	 int cnt = 0;
	 while(1)
	 {
		 if((*a).id == (*b).id) //a->b������ ���ٰ� ������
		 {
			 printf("copy �� : %dȸ \n", cnt);
			 break;
		 }
		 else
		 {
			 printf("copy 1ȸ \n");
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

	//�����ϱ�
	start = (front+1)%capacity; //++��� +%c
	rear--;

	if (start < 2) //�����̵��ʿ�X start�� 0�Ǵ� 1��
		copy(queue+start, queue+start+capacity-1, newQueue);

	else
	{
		copy(queue+start, queue+capacity, newQueue);
		copy(queue, queue+rear+1, newQueue+capacity-start);
	}
	//��������
	front = 2*capacity-1;
	rear = capacity-1;
	capacity *= 2;

	free(queue);
	queue = newQueue;
    printf("NOW capacity : %d\n", capacity);
}

void addq(element item)
{
	rear = (rear+1)%capacity; //empty�� ���� ���ؼ� �ڿ��� ���ߴ��� �տ��� �������μ� ���ڸ� �Ѱ����ܵд�
	if (rear == front)
		queueFull();
	queue[rear] = item;
}

int main(void)
{
//����ȯ��ť

	queue = (element*)malloc(capacity*(sizeof(*queue)));

	char input[80];				/// �޾ƿ� ��ǲ
	char * delimiter = " \n";	// delimiter for tokenizing
	char * op = NULL;			// push or pop
	element student;

	setvbuf(stdout, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����
	setvbuf(stderr, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����

	printf("op id name ������ �ۼ�\n");
	printf("*******************\n");

	while (1)
	{
		gets(input); //input ��ĵ�޾Ƽ�
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
