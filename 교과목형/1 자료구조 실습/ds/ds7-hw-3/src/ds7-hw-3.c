//��������

#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 11

typedef struct {
				int id; // unique id
				char name[MAX_NAME_SIZE]; // last name
			} element;

int capacity = 1;
element *stack;
int top = -1;

element stackEmpty()
{
	printf("EMPTY\n");
	stack[++top].id = -1;
	return stack[top];
} // �Լ� ���� ����..! pop�� ���� ������ empty �νĸ��ؼ� ����Ұ�

element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

void push(element item)
{
	if (top == capacity-1)
	{
		printf("reallocing...\n");
		capacity *= 2;
		stack = (element*)realloc(stack, capacity*(sizeof(*stack)));
	}
	stack[++top] = item;
}

void stackStop()
{
	printf("STOP\n");
	while (top >= 0)
	{
		printf("%d %s\n", stack[top].id, stack[top].name);
		pop();
	}
	exit(EXIT_FAILURE);
}

int main(void)
{
	stack = (element*)malloc(capacity*(sizeof(*stack)));

	char input[80];				// �޾ƿ� ��ǲ
	char * delimiter = " \n";	// delimiter for tokenizing
	char * op = NULL;			// push or pop

	element student;

	//setvbuf(stdout, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����
	//setvbuf(stderr, NULL, _IONBF, 0); //�ܼ�â����-��Ŭ����

	printf("op id name(�ִ�11��) ������ �ۼ�\n");
	printf("*******************\n");

	while (1)
	{
		gets(input); //input ��ĵ�޾Ƽ�
		op = strtok(input, delimiter); // del ���� �ڸ���
		if (!strcmp(op, "push"))
		{
			student.id = atoi(strtok(NULL, delimiter)); //atoi�� ��Ʈ���� int��
			strcpy(student.name, strtok(NULL, delimiter));
			push(student);
			//�ƴϸ�
			//sscanf(input + strlen(op) + 1, "%d %s", &student.id, student.name);
			//input(�ּ�) + strlen(op) + 1�� scan�������� �����ͷ� ��Ÿ���ִ� ��
			//������ġ(input)+4(op����)�ϸ� Ŀ����  push(���)4 Kang
			//������������ 1�� ���ؾ� 4�� ����Ű�� �Ǹ鼭 4���� ���´�!!
		}
		else if (!strcmp(op, "pop"))
			pop();
		else if (!strcmp(op, "stop"))
			stackStop();
		else
			printf("wrong command! try again!\n");
	}
	return 0;
}
