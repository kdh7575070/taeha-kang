#include <stdio.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

void printPerson(struct Person *p)
{
    printf("�̸�: %s\n", p->name);
    printf("����: %d\n", p->age);
    printf("�ּ�: %s\n", p->address);
}

int main()
{
    // �Ϲ������δ�
	struct Person p1;
	strcpy(p1.name, "ȫ�浿");
	p1.age = 20;
	strcpy(p1.address, "����� ���� �ѵ�");
	printPerson(&p1);


	// ���� ���ͷ� ������� ����ü�� �Ѱ���
    printPerson(&(struct Person) { .name = "ȫ�浿", .age = 30, .address = "����� ��걸 �ѳ���" });

    // ���� ���ͷ� ������� ����ü�� �Ѱ��� - ��� �̸� ����
    printPerson(&(struct Person) { "��浿", 40, "����� ���ʱ� ������" });

    return 0;
}
