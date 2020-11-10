#include <stdio.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

void printPerson(struct Person *p)
{
    printf("이름: %s\n", p->name);
    printf("나이: %d\n", p->age);
    printf("주소: %s\n", p->address);
}

int main()
{
    // 일반적으로는
	struct Person p1;
	strcpy(p1.name, "홍길동");
	p1.age = 20;
	strcpy(p1.address, "서울시 남구 한동");
	printPerson(&p1);


	// 복합 리터럴 방식으로 구조체를 넘겨줌
    printPerson(&(struct Person) { .name = "홍길동", .age = 30, .address = "서울시 용산구 한남동" });

    // 복합 리터럴 방식으로 구조체를 넘겨줌 - 멤버 이름 생략
    printPerson(&(struct Person) { "고길동", 40, "서울시 서초구 반포동" });

    return 0;
}
