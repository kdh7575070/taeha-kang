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
polyPointer a, b; //������ ���

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
{/* ü���� x ��� �ٷ� �ڿ� data ���� ������ �� ��带 �߰� */

	/* �� ��� �Ҵ� �� ������ ���� */
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->coef = poly.coef;
	temp->expon = poly.expon;

	if( *first == NULL )
	{ /* (a) �ֺ� ����Ʈ�� ��� �߰� */
		temp->link = NULL;
		*first = temp;
		printf("a");
	}
	else
	{ /* ��� ���� ���� ����Ʈ�� �߰� */

		if ( x == NULL )
		{ // (b) ù ���� �߰�
			temp->link = *first;
			*first = temp;
			printf("b");
		}
		else
		{ // (c) �� ��° �̻� ��ġ�� �߰�
			temp->link = x->link;
			x->link = temp;
			printf("c");
		}
	}
}

void inputPoly(FILE *fp, char name, polyPointer *aorb) //Ÿ������...!
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

			insert(aorb, NULL, poly); //�о�ö� *aorb�� �о���⶧���� &�� ������ߵȴ�
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

			x = findLast(*aorb, poly); //�о�ö� *aorb�� �о���⶧���� *����ߵȴ�
			insert(aorb, x, poly); //�о�ö� *aorb�� �о���⶧���� &������ߵȴ�
		}
	}
	else
		exit(EXIT_FAILURE);
}

void attach(float coefficient, int exponent, polyPointer *ptr) //ptr�� ���� ������ �����ϴ� �κ��̾  �ּ�ȣ��
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
	//��� ���� ���̳��(rear) ����  c�� rear�� ����Ŵ - queueó�� c�� �Ǿտ� ����Ű��  rear�� �ö󰣴�
	polyPointer c, rear;
	MALLOC(rear, sizeof(*rear));
	c = rear;

	//���̳�� ������ ����
	polyPointer temp;

	int coefsum;

	//���̳�忡�� �ƹ��͵� ���� ä�� rear�� �ö󰣴�
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
	//������ ���̱�
	for (; a; a=a->link) attach(a->coef, a->expon, &rear);
	for (; b; b=b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;

	// ���̳�� ����
	temp = c; //�Ǿ� ��ġ�� temp�� �޾ƿ���
	c = c->link; //c�� ���̳�� ���� (�������� �Ǿ�) ��ġ��  ������
	free(temp); //���̳��� ���ش�
	return c; //�Ǿ� ����
}

void erase(polyPointer *ptr){
	polyPointer temp;
	//���̳�� ������ ���� ��������
	while (*ptr)
	{
		temp = *ptr; //temp�� ��������Ű������ ����Ŵ
		*ptr = (*ptr)->link; //��������Ű�� ���� temp������ ������ ��ĭ ������
		free(temp); //temp�� ���ش�
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
