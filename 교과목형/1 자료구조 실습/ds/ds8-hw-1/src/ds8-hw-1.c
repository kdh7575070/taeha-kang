#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 16
#define MAX_ROW_SIZE 10
#define MAX_COL_SIZE 10
#define TRUE 1
#define FALSE 0

//전역변수설정

int EXIT_ROW, EXIT_COL;
int top = -1;

typedef struct {
				int ver;
				int hor;
			}offsets;
offsets move[8]; //{{.ver = -1, .hor = 0}, {.ver = ... }}; 식으로 초기화 가능

typedef struct {
				short int row;
				short int col;
				short int dir;
				} element;
element stack[MAX_STACK_SIZE];

//함수설정
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
		stackFull(); //return stackFUll(); 이라면
	stack[++top] = item;
}

int main(void)
{
// 미로찾기

	int a;
	int m,p;
	int i,j;

	FILE *fpIn = fopen("inputp.txt", "r");

	fscanf(fpIn, "%d %d", &m, &p);

	int maze[MAX_ROW_SIZE][MAX_COL_SIZE]={0,};
	int mark[MAX_ROW_SIZE][MAX_COL_SIZE]={0,};

	//테두리세팅
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

	//안쪽세팅
	for(i=1; i<=m; i++){
		for(j=1; j<=p; j++){
			fscanf(fpIn, "%d", &a);
			maze[i][j]=	a;
		}
	}

	//출력
	for(i=0; i<=m+1; i++){
		for(j=0; j<=p+1; j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}

	//기본설정
	int found = 0;
	int row, col, dir;
	int nextRow;
	int nextCol;
	EXIT_ROW = m;
	EXIT_COL = p;

	move[0].ver = -1;	move[0].hor = 0; //x축부호조심 위로가면 -1
	move[1].ver = -1;	move[1].hor = 1;
	move[2].ver = 0;	move[2].hor = 1;
	move[3].ver = 1;	move[3].hor = 1;
	move[4].ver = 1;	move[4].hor = 0;
	move[5].ver = 1;	move[5].hor = -1;
	move[6].ver = 0;	move[6].hor = -1;
	move[7].ver = -1;	move[7].hor = -1;

	//출발
	element position = {.row = 1, .col =1, .dir =1}; //출발포지션
	mark[1][1] = 1; //출발마크
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1; top = 0; //출발스택

	while (top >=-1 && !found)
	{ //스택이 차있고, 출구를 찾을때까지 <-Empty 계산을 위해 top을 -1도 허용!!!!!

		position = pop(); // 저장 안해주면 문제생긴다 2줄 아래서 확인
		row = position.row;	col = position.col;	dir = position.dir; //포지션 받아오기
		//printf("%d %d\n", position.row, position.col);

		while (dir < 8 && !found)
		{ //8방향에 대해서, 출구를 찾을때까지

			nextRow = row + move[dir].ver; //수직이동
			nextCol = col + move[dir].hor; //수평이동

			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
			{ //출구 찾았다 - 반복문나가자
				printf("ARRIVED\n");
				found = TRUE;
			}
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{ //막힌길 아니고 왔던길 아니면
				mark[nextRow][nextCol] =1; //마크해주자
				position.row = row; position.col = col; position.dir = ++dir; //다음의 값을 미리 저장해서
				push(position); //스택에넣어주자
				row=nextRow; col=nextCol; dir=0; //이동하자
//				printf("%d %d\n", stack[top].row, stack[top].col);//나갈때 출력해도 되는데 Empty처리위해 밖에서하자
			}
			else ++dir; //막힌길 이거나 왔던길이면 다음방향
		}//한바퀴 다돌았는데 갈데가 없으면 나가서 pop()해야지
	}

	for(i =0 ; i<=top ; i++)
		printf("%d %d\n", stack[i].row, stack[i].col);
	printf("%d %d\n", stack[top].row+move[dir].ver, stack[top].col+move[dir].hor); //나가서출력
	printf("%d %d\n", EXIT_ROW, EXIT_COL);

	fclose(fpIn);
	return 0;
}
