#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct human{
					char name[10];
					int age;
					float salary;
		    	}human;

int humanEqual (human *person1, human *person2)
{
	if (strcmp((*person1).name, (*person2).name)) return FALSE; //()쳐줘야한다꼭. 안그럼 그냥 -> 써도 되고
	if ((*person1).age != (*person2).age) return FALSE;
	if ((*person1).salary != (*person2).salary) return FALSE;
	return TRUE;
}

int main(void)
{
//구조체 출력

	human p1;
	human p2;

	setvbuf(stdout, NULL, _IONBF, 0); //콘솔창띄우기-이클립스
	setvbuf(stderr, NULL, _IONBF, 0); //콘솔창띄우기-이클립스

	printf("Input person1 (ex) name age salary :");
	scanf("%s %d %f", p1.name, &p1.age, &p1.salary);
	printf("%s %d %f\n", p1.name, p1.age, p1.salary);

	printf("Input person2 (ex) name age salary :");
	scanf("%s %d %f", p2.name, &p2.age, &p2.salary);
	printf("%s %d %f\n", p2.name, p2.age, p2.salary);

	//struct Person *pp1 = malloc(sizeof(struct Person);??

	human *pp1 = &p1;
	human *pp2 = &p2;

	if (humanEqual(pp1, pp2)==1) printf("same person\n");
	//if (humanEqual(&p1, &p2)==1) printf("same person\n");
	else printf("not same person\n");

	return 0;
}
