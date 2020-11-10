#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define COMPARE(x,y) (((x)<(y))? -1:((x)>(y))? 1 : 0)


typedef struct polyNode *polyPointer;
typedef struct polyNode {
						int coef;
						int expon;
						polyPointer link;
				}polyNode;

//polyPointer a, b, first대신 lastA, lastB, last를 사용할 것이다
polyPointer lastA, lastB, avail = NULL; //last지만 실제로는 맨앞을 가리키고 있다

FILE *fpIn1;
FILE *fpIn2;

void insertFront2(polyPointer* last, int p, int q);
void insertLast(polyPointer* last, int p, int q);
polyPointer getNode(void);
void inputPolyCL(FILE* fp, char name, polyPointer* last);
void attach(float coefficient, int exponent, polyPointer *ptr);
polyPointer cpadd(polyPointer a, polyPointer b);
polyPointer getNode(void);
void retNode(polyPointer node);
void cerase(polyPointer *ptr);
void erase(polyPointer *ptr);
void printCList(polyPointer last);

void insertFront2(polyPointer *last, int p, int q)
{
	polyPointer node = getNode();
	node->coef = p;
	node->expon = q;

	if(!(*last)) //last가 NULL인지 체크
	{
		*last = node;
		node->link = node; //자기자신을 가르키는 링크
	}
	else
	{
		node->link = (*last)->link;
		(*last)->link = node;
	}
	//a = node;     // 굳이 맨앞 포인터를 사용해야한다면 밑에서 재지정
}

void insertLast(polyPointer *last, int p, int q)
{
	polyPointer node = getNode();
	node->coef = p;
	node->expon = q;

	if(!(*last)) //last가 NULL인지 체크(초기)
	{
		*last = node;
		node->link = node; //자기자신을 가르키는 링크
	}
	else
	{
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node; //맨마지막으로 삽입하기 위한 것 - 이 문장만 있으면 된다
	}
	//a = node->link; // 굳이 맨앞 포인터를 사용해야한다면 밑에서 재지정
}

void inputPolyCL(FILE *fp, char name, polyPointer *last) //타입주의...!
{
	int p, q;

	if(name=='a')
	{
		printf("ascend ");
		while(!feof(fp))
		{
			fscanf(fp, "%d %d \n", &p, &q);

			insertFront2(last, p, q); //계속 맨앞에서 노드 생성
		}
		insertFront2(last, NULL, -1); //맨앞에 빈 헤더노드 만들기
	}
	else if(name=='d')
	{
		printf("descend ");

		insertLast(last, NULL, -1); //맨앞에 빈 헤더노드 만들기 (Front/Last 함수무관)
		while(!feof(fp))
		{
			fscanf(fp, "%d %d \n", &p, &q);

			insertLast(last, p, q); //맨뒤로 보내서 노드 생성
		}
	}
	else
		exit(EXIT_FAILURE);
}

void attach(float coefficient, int exponent, polyPointer *ptr) //ptr이 가르키는 주소값(링크)에 접근
{
	polyPointer temp;
	temp = getNode(); // MALLOC 대신 avail 연결

	temp->coef = coefficient;
	temp->expon = exponent;

	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer cpadd(polyPointer a, polyPointer b)
{
	polyPointer c; //맨앞에 빈 헤더노드를 가진다 - 더미노드 역할하면서 zero poly처리 쉽게
	polyPointer startA, lastC;

	startA = a; //A시작 표시해주기

	a = a->link; // a,b 헤더노드 스킵하고 그다음부터 비교할 거니까
	b = b->link;

	c = getNode(); //getNode로 c에 헤더노드 부여
	c->expon = -1; //헤더니까 계수 -1로

	lastC = c; //C끝 표시

	int coefsum, done = FALSE;

	do{ // 처음에는 당연히 startA == a 이니까 일단 do로 옮겨 줘야한다
		switch (COMPARE(a->expon,b->expon))
		{
			case -1:
				attach(b->coef, b->expon, &lastC);
				b=b->link;
				break;
			case 0:
				if (startA == a) done = TRUE; //종료조건!! 중요!! 1.양쪽 다 끝까지 돌았으며 2.연결에 의해 맨 앞에 왔다 를 만족해야함
				                              //두 개가 같으면서 startA == a 이면 둘다 다 돌아서 맨앞에 와 있다는 뜻
				else						  //그렇지 않으면 두 항의  계수가 같다는 뜻
				{
					coefsum = a->coef + b->coef;
					if(coefsum) attach(coefsum, a->expon, &lastC);
					a = a->link; b = b->link;
				}
				break;
			case 1:
				attach(a->coef, a->expon, &lastC);
				a=a->link;
		}
	}while (!done); //반복문 안에서 양쪽 끝까지 처리한다
	// 앞서서 두 다항식의 헤더노드를 -1로 설정한 효과를 여기서 볼 수 있다
	// 한쪽이 끝까지 훑고  나면  그 계수는 -1이 되면서 다음 노드도 끝까지 훑게 한다

	//c 헤더 연결
	lastC->link = c;
	return lastC;
}

polyPointer getNode(void)
{
	//avail이 있으면 가져오고 없으면 하나 만들어서 넘긴다

	polyPointer node;
	if (avail)
	{
		node = avail;
		avail = avail->link;
	}
	else
		MALLOC(node, sizeof(*node));
	return node;
}

void retNode(polyPointer node)
{
	//avail에 연결

	node->link =avail;
	avail = node;
}

void cerase(polyPointer *ptr)
{
	//free 대신 끊어서 avail에 연결하는 것

	polyPointer temp;

	if (*ptr) //while아니고 if다
	{
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

void erase(polyPointer *ptr)
{

	//최종적으로 free 하는  것

	polyPointer temp;

	while (*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

void printCList(polyPointer last)
{
	polyPointer temp;

	if(last) //empty list 아닌경우
	{
		temp = last->link;//헤더로
		do{ //먼저 한번 안하면 while문에 못들어간다
			temp = temp->link; //헤더먼저 스킵
			printf("%dx^%d+ ", temp->coef, temp->expon);
		}while(temp != last);
	}
	printf("\b\b\n");
}

int main(void)
{
	char name;

	fpIn1 = fopen("a.txt","r");
	printf(" a = ");

	fscanf(fpIn1, "%c", &name);
	inputPolyCL(fpIn1, name, &lastA);

	printCList(lastA); //last기준으로 하고 있으니까 last를 넣어줘야겠지

	//

	fpIn2 = fopen("b.txt","r");
	printf(" b = ");

	fscanf(fpIn2, "%c", &name);
	inputPolyCL(fpIn2, name, &lastB);

	printCList(lastB);

	//cpadding

	polyPointer lastC;
	lastC = cpadd((lastA->link),(lastB->link));
	printf("final answer c = ");
	printCList(lastC);

	//cerasing

	cerase(&(lastA->link)); //cerase가 앞에서 삭제하는거니까
	erase(&avail); // avail을 각각해줘야한다
	cerase(&(lastB->link));
	erase(&avail);
	cerase(&(lastC->link));
	erase(&avail);

	fclose(fpIn1);
	fclose(fpIn2);

	return 0;
}
