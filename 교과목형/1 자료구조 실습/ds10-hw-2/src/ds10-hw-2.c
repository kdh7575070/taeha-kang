#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 3
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct {
				int id; //학번
				int grade; //성적
		} element;

typedef struct stack *stackPointer;
typedef struct stack {
						element data;
						stackPointer link;
				}Node;

stackPointer top[MAX_STACKS];
element student;

void push(int i, element item)
{
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element stackEmpty()
{
	printf("NO SOLUTION\n");
	exit(EXIT_FAILURE);
}

element pop(int i)
{
	stackPointer temp = top[i];
	element item;
	if (!temp)
		return stackEmpty();
	item = temp->data;
	top[i] = temp->link;
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
		push(a, student);
	}

	for(i = 0; i <= 2; i++)
	{
		while(top[i]!=NULL)
			pop(i);
		printf("***************\n");
	}

	fclose(fpIn);

	return 0;
}
