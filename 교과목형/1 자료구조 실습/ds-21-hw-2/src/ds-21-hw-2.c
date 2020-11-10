#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 100

FILE *fpo;

typedef struct element{
						int key;
				} element;

element list[MAX_SIZE];
int link[MAX_SIZE] = {0};

int dig;
int rad = 10;
char c = 'a';

int digit(element e, int d, int r)
{
	int i;
	int y, x=1;
	for(i = 0; i < dig-d; i++) x *= r; //�μ��� �޾ƿ� d��  0���� �����ؼ� d+1��°�ڸ��� ����
	y = x / r;
	return (e.key%x)/y;
}

void printList(element a[], int n, int f)
{
	printf("<<<<%c>>>>\n", c); fprintf(fpo, "<<<<%c>>>>\n", c);
	c++;

	int i;

	for(i=1; i <= n; i++) {printf("%3d ", link[i]); fprintf(fpo, "%3d ", link[i]);}
	printf("\n"); fprintf(fpo, "\n");
	for(i=1; i <= n; i++) {printf("%3d ", a[i].key); fprintf(fpo, "%3d ", a[i].key);}
	printf("\nfirst: %3d\n", f); fprintf(fpo, "\nfirst: %3d\n", f);

	while(f)
	{
		printf("%3d ", a[f].key); fprintf(fpo, "%3d ", a[f].key);
		f = link[f];
	}
	printf("\n\n"); fprintf(fpo, "\n\n");
}

void printQ(int *front, int *rear, int n)
{
	int i;

	for(i=0; i < rad; i++) {printf("%3d ", rear[i]); fprintf(fpo, "%3d ", rear[i]);}
	printf("\n"); fprintf(fpo, "\n");
	for(i=0; i < rad; i++) {printf("%3d ", front[i]); fprintf(fpo, "%3d ", front[i]);}
	printf("\n\n"); fprintf(fpo, "\n\n");
}

int radixSort(element a[], int link[], int d, int r, int n)
{
	int *front, *rear;
	front = malloc(sizeof(int)*r);
	rear = malloc(sizeof(int)*r);

	int i,bin,current,first,last;

	//��ũ �ʱ�ȭ
	first = 1;
	for(i=1; i < n; i++) link[i]= i+1;
	link[n]=0;

	printList(a, n, first); //�ʱ����

	for(i=d-1; i>=0; i--) //digit i ��°�� ����
	{
		//front�� bin�� 0���� �ʱ�ȭ
		for(bin=0; bin < r; bin++) {front[bin] = 0; rear[bin] = 0;}

		for(current = first; current; current = link[current])
		{
			//queue�� ���ֱ�
			bin = digit(a[current],i,r); //1���ڸ� ã�� -> 10���ڸ� ã�� ...
			if (front[bin]==0) front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;
		}

		//ù��° non-empty queue ã��
		for(bin = 0; !front[bin]; bin++);
		first = front[bin]; last = rear[bin];
		//������ queue �̾��ֱ�
		for(bin++; bin<r; bin++)
		{
			if(front[bin])
			{
				link[last] = front[bin];
				last=rear[bin];
			}
		}
		link[last]=0; //�������Ҷ��� ���ؼ� ������ 0 ����
		printList(a, n, first);
		printQ(front, rear, n);
	}
	return first;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	//FILE *fp = fopen("input1.txt", "r");
	fpo = fopen("output.txt", "w");
	//fpo = fopen("output1.txt", "w");

	int n, i=1;
	int f;
	element e;

	fscanf(fp, "%d", &dig);
	fscanf(fp, "%d", &n);

	printf("init :"); fprintf(fpo, "init :");
	while(!feof(fp))
	{
		fscanf(fp, "%d", &e.key);
		printf("%d ", e.key); fprintf(fpo, "%d ", e.key);
		list[i] = e;
		i++;
	}
	printf("\n\n"); fprintf(fpo, "\n\n");

	f = radixSort(list, link, dig, rad, n);

	printf("fini :"); fprintf(fpo, "fini :");
	while(f)
	{
		printf("%3d ", list[f].key); fprintf(fpo, "%3d ", list[f].key);
		f = link[f];
	}
	printf("\n\n"); fprintf(fpo, "\n\n");

	fclose(fp);
	fclose(fpo);

	return 0;
}
