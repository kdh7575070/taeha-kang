#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 3
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// 2015112806 강태하
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct {
				int id; //학번
				int grade; //성적
		} element;

typedef struct stack *queuePointer;
typedef struct stack {
						element data;
						queuePointer link;
				}Node;

queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];
element poly;

void addq(int i, element item)
{
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	if(front[i])
		rear[i]->link = temp;
	else
		front[i] = temp;
	rear[i] = temp;
}

element queueEmpty()
{
	printf("NO SOLUTION\n");
	exit(EXIT_FAILURE);
}

element deleteq(int i)
{
	queuePointer temp = front[i];
	element item;
	if (!temp)
		return queueEmpty();
	item = temp->data;
	front[i] = temp->link;
	printf("%d %d %d\n", i, temp->data.id, temp->data.grade);
	free(temp);
	return item;
}

int main(void)
{
	int a, b, c, i;
	element student;

	FILE *fpIn = fopen("input.txt","r");

	while( !feof(fpIn) )
	{
		fscanf(fpIn, "%d", &a);
		fscanf(fpIn, "%d", &b);
		fscanf(fpIn, "%d", &c);
		student.id = b;
		student.grade = c;
		addq(a, student);
	}

	for(i = 0; i <= 2; i++)
	{
		while(front[i]!=NULL)
			deleteq(i);
		printf("***************\n");
	}//pop이랑은 반대로 출력되지

	fclose(fpIn);

	return 0;
}
