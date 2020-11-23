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

//polyPointer a, b, first��� lastA, lastB, last�� ����� ���̴�
polyPointer lastA, lastB, avail = NULL; //last���� �����δ� �Ǿ��� ����Ű�� �ִ�

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

	if(!(*last)) //last�� NULL���� üũ
	{
		*last = node;
		node->link = node; //�ڱ��ڽ��� ����Ű�� ��ũ
	}
	else
	{
		node->link = (*last)->link;
		(*last)->link = node;
	}
	//a = node;     // ���� �Ǿ� �����͸� ����ؾ��Ѵٸ� �ؿ��� ������
}

void insertLast(polyPointer *last, int p, int q)
{
	polyPointer node = getNode();
	node->coef = p;
	node->expon = q;

	if(!(*last)) //last�� NULL���� üũ(�ʱ�)
	{
		*last = node;
		node->link = node; //�ڱ��ڽ��� ����Ű�� ��ũ
	}
	else
	{
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node; //�Ǹ��������� �����ϱ� ���� �� - �� ���常 ������ �ȴ�
	}
	//a = node->link; // ���� �Ǿ� �����͸� ����ؾ��Ѵٸ� �ؿ��� ������
}

void inputPolyCL(FILE *fp, char name, polyPointer *last) //Ÿ������...!
{
	int p, q;

	if(name=='a')
	{
		printf("ascend ");
		while(!feof(fp))
		{
			fscanf(fp, "%d %d \n", &p, &q);

			insertFront2(last, p, q); //��� �Ǿտ��� ��� ����
		}
		insertFront2(last, NULL, -1); //�Ǿտ� �� ������ �����
	}
	else if(name=='d')
	{
		printf("descend ");

		insertLast(last, NULL, -1); //�Ǿտ� �� ������ ����� (Front/Last �Լ�����)
		while(!feof(fp))
		{
			fscanf(fp, "%d %d \n", &p, &q);

			insertLast(last, p, q); //�ǵڷ� ������ ��� ����
		}
	}
	else
		exit(EXIT_FAILURE);
}

void attach(float coefficient, int exponent, polyPointer *ptr) //ptr�� ����Ű�� �ּҰ�(��ũ)�� ����
{
	polyPointer temp;
	temp = getNode(); // MALLOC ��� avail ����

	temp->coef = coefficient;
	temp->expon = exponent;

	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer cpadd(polyPointer a, polyPointer b)
{
	polyPointer c; //�Ǿտ� �� �����带 ������ - ���̳�� �����ϸ鼭 zero polyó�� ����
	polyPointer startA, lastC;

	startA = a; //A���� ǥ�����ֱ�

	a = a->link; // a,b ������ ��ŵ�ϰ� �״������� ���� �Ŵϱ�
	b = b->link;

	c = getNode(); //getNode�� c�� ������ �ο�
	c->expon = -1; //����ϱ� ��� -1��

	lastC = c; //C�� ǥ��

	int coefsum, done = FALSE;

	do{ // ó������ �翬�� startA == a �̴ϱ� �ϴ� do�� �Ű� ����Ѵ�
		switch (COMPARE(a->expon,b->expon))
		{
			case -1:
				attach(b->coef, b->expon, &lastC);
				b=b->link;
				break;
			case 0:
				if (startA == a) done = TRUE; //��������!! �߿�!! 1.���� �� ������ �������� 2.���ῡ ���� �� �տ� �Դ� �� �����ؾ���
				                              //�� ���� �����鼭 startA == a �̸� �Ѵ� �� ���Ƽ� �Ǿտ� �� �ִٴ� ��
				else						  //�׷��� ������ �� ����  ����� ���ٴ� ��
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
	}while (!done); //�ݺ��� �ȿ��� ���� ������ ó���Ѵ�
	// �ռ��� �� ���׽��� �����带 -1�� ������ ȿ���� ���⼭ �� �� �ִ�
	// ������ ������ �Ȱ�  ����  �� ����� -1�� �Ǹ鼭 ���� ��嵵 ������ �Ȱ� �Ѵ�

	//c ��� ����
	lastC->link = c;
	return lastC;
}

polyPointer getNode(void)
{
	//avail�� ������ �������� ������ �ϳ� ���� �ѱ��

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
	//avail�� ����

	node->link =avail;
	avail = node;
}

void cerase(polyPointer *ptr)
{
	//free ��� ��� avail�� �����ϴ� ��

	polyPointer temp;

	if (*ptr) //while�ƴϰ� if��
	{
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

void erase(polyPointer *ptr)
{

	//���������� free �ϴ�  ��

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

	if(last) //empty list �ƴѰ��
	{
		temp = last->link;//�����
		do{ //���� �ѹ� ���ϸ� while���� ������
			temp = temp->link; //������� ��ŵ
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

	printCList(lastA); //last�������� �ϰ� �����ϱ� last�� �־���߰���

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

	cerase(&(lastA->link)); //cerase�� �տ��� �����ϴ°Ŵϱ�
	erase(&avail); // avail�� ����������Ѵ�
	cerase(&(lastB->link));
	erase(&avail);
	cerase(&(lastC->link));
	erase(&avail);

	fclose(fpIn1);
	fclose(fpIn2);

	return 0;
}
