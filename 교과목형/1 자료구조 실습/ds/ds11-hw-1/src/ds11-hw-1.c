#include <stdio.h>
#include <stdlib.h>

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
polyPointer a, b; //각각의 헤드

FILE *fpIn1;
FILE *fpIn2;

polyPointer findLast(polyPointer p, polyNode poly)
{
	polyPointer x = p;

	if (x == NULL)
	    return NULL;

	while(x->link)
		x = x->link;
	return x;
}

void insert(polyPointer *first, polyPointer x, polyNode poly)
{/* 체인의 x 노드 바로 뒤에 data 값을 가지는 새 노드를 추가 */

	/* 새 노드 할당 및 데이터 저장 */
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->coef = poly.coef;
	temp->expon = poly.expon;

	if( *first == NULL )
	{ /* (a) 텅빈 리스트에 노드 추가 */
		temp->link = NULL;
		*first = temp;
		printf("a");
	}
	else
	{ /* 비어 있지 않은 리스트에 추가 */

		if ( x == NULL )
		{ // (b) 첫 노드로 추가
			temp->link = *first;
			*first = temp;
			printf("b");
		}
		else
		{ // (c) 두 번째 이상 위치에 추가
			temp->link = x->link;
			x->link = temp;
			printf("c");
		}
	}
}

void inputPoly(FILE *fp, char name, polyPointer *aorb) //타입주의...!
{
	int p, q;
	polyNode poly;
	polyPointer x;

	if(name=='a')
	{
		printf("ascend ");
		while( !feof(fp) )
		{
			fscanf(fp, "%d %d \n", &p, &q);
			poly.coef = p;
			poly.expon = q;

			insert(aorb, NULL, poly); //읽어올때 *aorb를 읽어오기때문에 &는 안해줘야된다
		}
	}
	else if(name=='d')
	{
		printf("descend ");
		while( !feof(fp) )
		{
			fscanf(fp, "%d %d \n", &p, &q);
			poly.coef = p;
			poly.expon = q;

			x = findLast(*aorb, poly); //읽어올때 *aorb를 읽어오기때문에 *해줘야된다
			insert(aorb, x, poly); //읽어올때 *aorb를 읽어오기때문에 &안해줘야된다
		}
	}
	else
		exit(EXIT_FAILURE);
}

void attach(float coefficient, int exponent, polyPointer *ptr) //ptr에 값을 실제로 대입하는 부분이어서  주소호출
{
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->coef = coefficient;
	temp->expon = exponent;

	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer padd(polyPointer a, polyPointer b)
{
	//계산 쉽게 더미노드(rear) 만들어서  c와 rear가 가르킴 - queue처럼 c는 맨앞에 가리키고  rear가 올라간다
	polyPointer c, rear;
	MALLOC(rear, sizeof(*rear));
	c = rear;

	//더미노드 해제할 때용
	polyPointer temp;

	int coefsum;

	//더미노드에는 아무것도 없는 채로 rear가 올라간다
	while (a && b)
	{
		switch (COMPARE(a->expon,b->expon))
		{
			case -1:
				attach(b->coef, b->expon, &rear);
				b=b->link;
				break;
			case 0:
				coefsum = a->coef + b->coef;
				if(coefsum) attach(coefsum, a->expon, &rear);
				a=a->link;
				b=b->link;
				break;
			case 1:
				attach(a->coef, a->expon, &rear);
				a=a->link;
		}
	}
	//남은거 붙이기
	for (; a; a=a->link) attach(a->coef, a->expon, &rear);
	for (; b; b=b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;

	// 더미노드 해제
	temp = c; //맨앞 위치를 temp가 받아오고
	c = c->link; //c는 더미노드 다음 (실질적인 맨앞) 위치로  보내고
	free(temp); //더미노드는 없앤다
	return c; //맨앞 리턴
}

void erase(polyPointer *ptr){
	polyPointer temp;
	//더미노드 삭제할 때와 마찬가지
	while (*ptr)
	{
		temp = *ptr; //temp가 원래가리키던것을 가리킴
		*ptr = (*ptr)->link; //원래가리키던 것은 temp줬으니 포인터 한칸 앞으로
		free(temp); //temp를 없앤다
	}
}

void printList(polyPointer p)
{
	for(; p; p = p->link)
		printf("%dx^%d+ ", p->coef, p->expon);
	printf("\b\b\n");
}

int main(void)
{
	char name;

	fpIn1 = fopen("a.txt","r");
	printf(" a = ");

	fscanf(fpIn1, "%c", &name);
	inputPoly(fpIn1, name, &a);

	printList(a);

	fpIn2 = fopen("b.txt","r");
	printf(" b = ");

	fscanf(fpIn2, "%c", &name);
	inputPoly(fpIn2, name, &b);

	printList(b);

	//padding

	polyPointer c;
	c = padd(a, b);
	printf("final answer c = ");
	printList(c);

	//erasing

	erase(&a);
	erase(&b);
	erase(&c);

	fclose(fpIn1);
	fclose(fpIn2);

	return 0;
}
