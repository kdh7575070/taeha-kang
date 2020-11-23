#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

#define MAX_STACK_SIZE 100
#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
   if( !( (p) = malloc( s ) ) ){   \
      fprintf(stderr, "Insufficient memory");\
      exit(EXIT_FAILURE);\
   }

typedef struct node* treePointer;
typedef struct node
{
    char data;
    short int value;
    treePointer leftChild, rightChild;
}node;

treePointer root = NULL;

// stack
treePointer stack[MAX_STACK_SIZE];
int top = -1;
void push(treePointer item);
void stackFull();
treePointer pop();
treePointer stackEmpty();

// postfix expression
char expr[81];

FILE* fp;

// binary tree of an arithmetic expression
typedef enum { and, or , not, eos, variable } logical;

int i, type;
char variables[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

logical getToken(char* symbol, int* n);
treePointer createBinTree(FILE* fp);
void replace(treePointer ptr, int n);
void postOrderEval(treePointer node);

//int* combinations;
int combinations[10] = {0, };

/*
방법1

void nextCombination(int iter, int n) {
    // 배열 0으로 초기화
    //for (int i = 0; i < n; i++)
    //    combinations[i] = 0;
    while (iter > 0) {
        iter--;
        combinations[n - 1]++;
        for (int i = n - 1; i >= 0; i--) {
            if (combinations[i] > 1) {
                combinations[i] -= 2;
                combinations[i - 1]++;
            }
        }
    }
}
*/

//방법2

void nextCombination(int n)
{
	int position = 0;
	int j = i;

	while (1)
	{
		combinations[position] = j % 2;  // 2로 나누었을 때 나머지를 배열에 저장
		j = j / 2;             			 // 2로 나눈 몫을 저장
		position++;    				  	 // 자릿수 변경
		if (j == 0) break;  			 // 몫이 0이 되면 반복을 끝냄
	 }
}

int main(void)
{
    int n;

    if ((fp = fopen("input.txt", "r")) == NULL)
    {
        fprintf(stderr, "cannot open the file");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d\n", &n);
    //MALLOC(combinations, sizeof(int) * n);

    fgets(expr, 80, fp);
    printf("input string (postfix expression) : %s\n", expr);

    root = createBinTree(fp);
    printf("\nresult : \n");

    int j;

    for (i = 0; i < 8; i++) // math함수가 없어서 이렇게 씁니다 -> 8대신  pow(2, n)
    {
        nextCombination(n); //2진수화
        replace(root, n);
        postOrderEval(root); //평가
        //if (root->value) // 마지막 값이 걸린다
        //{
        for (j = 0; j < n; j++) printf("%d", combinations[j]);
        printf(" [answer]%d ", root->value);
        printf("\n");
        //}
    }
    return 0;
}

treePointer createBinTree(FILE* fp)
{
    treePointer treeRoot = NULL;

    logical token;
    char symbol;
    int n = 0;

    fscanf(fp, "%s", expr);

    token = getToken(&symbol, &n);

    while (token != eos) {

        treePointer temp;
        MALLOC(temp, sizeof(*temp));
        temp->data = symbol;
        temp->leftChild = temp->rightChild = NULL;

        if (token == variable)
        {
            treeRoot = temp;
            push(treeRoot);
        }
        else if (token == not)
        {
            treeRoot = temp;
            treeRoot->rightChild = pop();
            push(treeRoot);
        }
        else
        {
            treeRoot = temp;
            treeRoot->rightChild = pop();
            treeRoot->leftChild = pop();
            push(treeRoot);
        }
        token = getToken(&symbol, &n);
    }
    return treeRoot;
}

// Program 3.14: Function to get a token from the input string
logical getToken(char* symbol, int* n)
{
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
    case '&': return and;
    case '|': return or ;
    case '~': return not;
    case '\0': return eos;
    default: return variable;
    }
}
void replace(treePointer ptr, int n) //inorder함수 변형
{
    if (ptr) {
        replace(ptr->leftChild, n);
        for (type = 0; type < n; type++)
        {
            if (ptr->data == variables[type]) { // data가  variable중 하나라면
                ptr->value = combinations[type]; // value 치환
                break;
            }
        }
        replace(ptr->rightChild, n);
    }
}
void postOrderEval(treePointer node)
{
    if (node) {
        postOrderEval(node->leftChild);
        postOrderEval(node->rightChild);
        switch (node->data) {
        case '~':
            node->value = !node->rightChild->value;
            break;
        case '&':
            node->value = node->rightChild->value && node->leftChild->value;
            break;
        case '|':
            node->value = node->rightChild->value || node->leftChild->value;
        }
    }
}

/////////////////////// stack operations ///////////////////////////////////
treePointer pop()
{/* delete and return the top int from the stack */
    if (top == -1)
        return stackEmpty();   /* returns an error key */
    return stack[top--];
}

treePointer stackEmpty()
{
    treePointer item;
    item = NULL;  // error key value - null pointer
    return item;
}

void push(treePointer item)
{/* add an item to the global stack */
    if (top >= MAX_STACK_SIZE - 1)
        stackFull();
    stack[++top] = item;
}

void stackFull()
{
    fprintf(stderr, "stack is full, cannot add item\n");
    exit(EXIT_FAILURE);
}
