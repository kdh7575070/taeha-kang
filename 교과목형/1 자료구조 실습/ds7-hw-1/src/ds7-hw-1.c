#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 11

typedef struct {
				int id; // unique id
				char name[MAX_NAME_SIZE]; // last name
			} element;

element stack[MAX_STACK_SIZE];
int top = -1;

element stackEmpty()
{
	printf("EMPTY\n");
	stack[++top].id = -1;
	return stack[top];
} // 함수 순서 주의..! pop이 위에 있으면 empty 인식못해서 실행불가

element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

void stackFull()
{
	printf("FULL\n");
	while (top >= 0)
	{
		printf("%d %s\n", stack[top].id, stack[top].name);
		pop();
		// element타입으로 선언해서 while대신 재귀함수 return stackFull(); 가능
	}
	exit(EXIT_FAILURE);
}

void push(element item)
{
	if (top == MAX_STACK_SIZE-1)
		stackFull(); //return stackFUll(); 이라면
	stack[++top] = item;
}

int main(void)
{
//정적스택

	char input[80];				// 받아올 인풋
	char * delimiter = " \n";	// delimiter for tokenizing
	char * op = NULL;			// push or pop

	element student;

	//setvbuf(stdout, NULL, _IONBF, 0); //콘솔창띄우기-이클립스
	//setvbuf(stderr, NULL, _IONBF, 0); //콘솔창띄우기-이클립스

	printf("MAX SIZE IS 5\n");
	printf("op id name(최대11자) 순서로 작성\n");
	printf("*******************\n");

	while (1)
	{
		gets(input); //input 스캔받아서
		op = strtok(input, delimiter); // del 기준 자르기
		if (!strcmp(op, "push"))
		{
			student.id = atoi(strtok(NULL, delimiter)); //atoi는 스트링을 int로
			strcpy(student.name, strtok(NULL, delimiter));
			push(student);
			//아니면
			//sscanf(input + strlen(op) + 1, "%d %s", &student.id, student.name);
			//input(주소) + strlen(op) + 1이 scan시작점을 포인터로 나타내주는 것
			//시작위치(input)+4(op길이)하면 커서가  push(요기)4 Kang
			//띄워쓰기공간인 1을 더해야 4를 가르키게 되면서 4부터 들어온다!!
		}
		else if (!strcmp(op, "pop"))
			pop();
		else if (!strcmp(op, "stop"))
			break;
		else
			printf("wrong command! try again!\n");
	}
	return 0;
}
