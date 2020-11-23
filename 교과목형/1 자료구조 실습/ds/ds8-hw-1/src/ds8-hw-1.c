#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 16
#define MAX_ROW_SIZE 10
#define MAX_COL_SIZE 10
#define TRUE 1
#define FALSE 0

//������������

int EXIT_ROW, EXIT_COL;
int top = -1;

typedef struct {
				int ver;
				int hor;
			}offsets;
offsets move[8]; //{{.ver = -1, .hor = 0}, {.ver = ... }}; ������ �ʱ�ȭ ����

typedef struct {
				short int row;
				short int col;
				short int dir;
				} element;
element stack[MAX_STACK_SIZE];

//�Լ�����
void stackEmpty()
{
	printf("NO SOLUTION\n");
	exit(EXIT_FAILURE);
}

element pop()
{
	if (top == -1)
		stackEmpty();
	return stack[top--];
}

void stackFull()
{
	printf("FULL\n");
	exit(EXIT_FAILURE);
}

void push(element item)
{
	if (top == MAX_STACK_SIZE-1)
		stackFull(); //return stackFUll(); �̶��
	stack[++top] = item;
}

int main(void)
{
// �̷�ã��

	int a;
	int m,p;
	int i,j;

	FILE *fpIn = fopen("inputp.txt", "r");

	fscanf(fpIn, "%d %d", &m, &p);

	int maze[MAX_ROW_SIZE][MAX_COL_SIZE]={0,};
	int mark[MAX_ROW_SIZE][MAX_COL_SIZE]={0,};

	//�׵θ�����
	for(j=0; j<=p+1; j++) maze[0][j]= 1;
	for(i=1; i<=m; i++)
	{
		for(j=0; j<=p+1;j++)
		{
			maze[i][j]= 1;
			j+=p;
		}
	}
	for(j=0; j<=p+1; j++) maze[m+1][j]= 1;

	//���ʼ���
	for(i=1; i<=m; i++){
		for(j=1; j<=p; j++){
			fscanf(fpIn, "%d", &a);
			maze[i][j]=	a;
		}
	}

	//���
	for(i=0; i<=m+1; i++){
		for(j=0; j<=p+1; j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}

	//�⺻����
	int found = 0;
	int row, col, dir;
	int nextRow;
	int nextCol;
	EXIT_ROW = m;
	EXIT_COL = p;

	move[0].ver = -1;	move[0].hor = 0; //x���ȣ���� ���ΰ��� -1
	move[1].ver = -1;	move[1].hor = 1;
	move[2].ver = 0;	move[2].hor = 1;
	move[3].ver = 1;	move[3].hor = 1;
	move[4].ver = 1;	move[4].hor = 0;
	move[5].ver = 1;	move[5].hor = -1;
	move[6].ver = 0;	move[6].hor = -1;
	move[7].ver = -1;	move[7].hor = -1;

	//���
	element position = {.row = 1, .col =1, .dir =1}; //���������
	mark[1][1] = 1; //��߸�ũ
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1; top = 0; //��߽���

	while (top >=-1 && !found)
	{ //������ ���ְ�, �ⱸ�� ã�������� <-Empty ����� ���� top�� -1�� ���!!!!!

		position = pop(); // ���� �����ָ� ��������� 2�� �Ʒ��� Ȯ��
		row = position.row;	col = position.col;	dir = position.dir; //������ �޾ƿ���
		//printf("%d %d\n", position.row, position.col);

		while (dir < 8 && !found)
		{ //8���⿡ ���ؼ�, �ⱸ�� ã��������

			nextRow = row + move[dir].ver; //�����̵�
			nextCol = col + move[dir].hor; //�����̵�

			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
			{ //�ⱸ ã�Ҵ� - �ݺ���������
				printf("ARRIVED\n");
				found = TRUE;
			}
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{ //������ �ƴϰ� �Դ��� �ƴϸ�
				mark[nextRow][nextCol] =1; //��ũ������
				position.row = row; position.col = col; position.dir = ++dir; //������ ���� �̸� �����ؼ�
				push(position); //���ÿ��־�����
				row=nextRow; col=nextCol; dir=0; //�̵�����
//				printf("%d %d\n", stack[top].row, stack[top].col);//������ ����ص� �Ǵµ� Emptyó������ �ۿ�������
			}
			else ++dir; //������ �̰ų� �Դ����̸� ��������
		}//�ѹ��� �ٵ��Ҵµ� ������ ������ ������ pop()�ؾ���
	}

	for(i =0 ; i<=top ; i++)
		printf("%d %d\n", stack[i].row, stack[i].col);
	printf("%d %d\n", stack[top].row+move[dir].ver, stack[top].col+move[dir].hor); //���������
	printf("%d %d\n", EXIT_ROW, EXIT_COL);

	fclose(fpIn);
	return 0;
}
