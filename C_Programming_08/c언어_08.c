// ����ü�� ������ ����

/*
struct ����ü�̸�
{
	����ü ���(����)
};
*/

// ����ü ���� != ���� ����
// ����ü ������ ���� : struct ����ü�±� �����̸�
// ����ü ��� ���� : ��� ������ (.) ���
// ����ü �ȿ� ����ü ����
// �迭�� ���� ����ü ���� ����� ���ÿ� �ʱ�ȭ ����
// ����ü ���� ���� ����, �� �Ұ���(�� ����� ���ؾ���)

// ���� �ڵ� : ���� �� ������ �Ÿ�
/*
#include <stdio.h>
#include <math.h>

struct point
{
	int x, y;
};

int main()
{
	double dist;
	struct point p1, p2;

	p1.x = 10;
	p1.y = 20;
	p2.x = 30;
	p2.y = 40;

	dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

	printf("�Ÿ� : %f\n", dist);

	return 0;
}
*/

// ���� �ڵ� : �ּҷ� ����
/*
#include <stdio.h>

struct contacts
{
	char name[20];
	char addr[20];
	char tel[20];
};

int main()
{
	struct contacts c1;

	printf("�̸� �Է� : ");
	// scanf_s("%s", c1.name);
	gets(c1.name);

	printf("�ּ� �Է� : ");
	// scanf_s("%s", c1.addr); // scanf�� ������ ó������ ���ϴ� ������ ���� ���� ����
	gets(c1.addr);

	printf("��ȣ �Է� : ");
	// scanf_s("%s", c1.tel);
	gets(c1.tel);

	printf("%s %s %s", c1.name, c1.addr, c1.tel);
}
*/

// ����ü �����ϱ�

// ���� �ڵ� : �л� ���� ����
/*
#include <stdio.h>

struct student
{
	char name[20];
	int eng;
	int math;
	int phys;
};

struct student list[3] = {
	{"ȫ�浿",82,72,58},
	{"������",97,82,39},
	{"�̼���",52,62,39}
};

int main()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%s %d %d %d\n", list[i].name, list[i].eng, list[i].math, list[i].phys);
	}

	return 0;
}
*/

// ���� �ڵ� : �л� ���� ó�� (�ְ� ������ ã��)
/*
#include <stdio.h>

struct student
{
	char name[20];
	double gpa;
};

struct student list[] = {
	{"ȫ�浿",2.2},
	{"������",4.2},
	{"�̼���",3.9}
};

int main()
{
	struct student top;
	int i, size;

	size = sizeof(list) / sizeof(list[0]); // ��
	
	top = list[0]; // ��

	for (i = 0; i < size; i++)
	{
		if (list[i].gpa > top.gpa)
			top = list[i];
	}
	printf("%s %f", top.name, top.gpa);

	return 0;
}
*/

// ����Ʈ �е� : �����Ϸ��� �������� ��Ͽ� ���߾� ����Ʈ�� �е����ִ� ����ȭ �۾�

// ����ü�� ������
// ������ ���� ����ü ��� ���� : ���� ���� ������(*) ���, ���� ��� ������(->) ���

// ���� �ڵ� : ����
/*
#include <stdio.h>

struct vec
{
	double x, y;
};

struct vec sum_vec(struct vec a, struct vec b)
{
	return a + b; // ����(?)
}

int main()
{
	struct vec a = { 2.0,3.0 };
	struct vec b = { 5.0,6.0 };
	struct vec sum = sum_vec(a, b);

	printf("%lf %lf", sum.x, sum.y);
	return 0;
}
*/

// ����ü (union)
// �ϳ��� �޸� ������ ���� ���� �������� ������ �� ����(���� ū �޸� ���� �������� ���� ����)

// ������ (enum)
// ������ ���� �� �ִ� ������ �ϳ��� �����س���(��ȣ ������� ����)
// ��ȣ ����� �� ���� ����(�Ϻθ� �����ϴ� �͵� ����)
// �Ϻ� ������ ���, �������� ���� ����� ���� ������� 1 ������ �� ����

// typedef
// typedef unsigned char BYTE = BYTE num

// ���� : ���� �����̵�
/*
#include <stdio.h>

typedef struct point
{
	int x, y;
}POINT;

POINT translate(POINT p, POINT delta) // ���� �ʱ� ��ǥ�� �̵��Ÿ� �����Ͽ� �̵��� ���� ��ǥ ���
{
	POINT temp;
	temp.x = p.x + delta.x;
	temp.y = p.y + delta.y;
	return temp;
}

void main()
{
	POINT p = { 2,3 };
	POINT delta, result;

	scanf("%d %d", &delta.x, &delta.y);
	result = translate(p, delta);
	printf("%d %d", result.x, result.y);
}
*/

// ���� �ڵ� : ��ǥ ��ġ �Ǵ�
/*
#include <stdio.h>

typedef struct point
{
	int x, y;
}POINT;

int equal(POINT* a, POINT* b)
{
	if ((*a).x == (*b).x && (*a).y == (*b).y)
		return 1; // �� �� ��ǥ ��ġ�ϸ� 1 ��ȯ
	return 0; // ��ġ���� ������ 0 ��ȯ
}

void main()
{
	POINT p1 = { 1,2 };
	POINT p2 = { 3,4 };

	if (equal(&p1, &p2) == 1)
		printf("����");
	else
		printf("�ٸ�");
}
*/

// ���� �ڵ� : ���Ҽ� ����
// a+bi : �Ǽ��� �Ǽ�����, ����� ������� ���� ����
/*
#include <stdio.h>

struct complex
{
	double r;
	double i;
};

struct complex add(struct complex c1, struct complex c2)
{
	struct complex temp;
	temp.r = c1.r + c2.r;
	temp.i = c1.i + c2.i;
	return temp;
}
*/

// ���� �ڵ� : �λ����
/*
#include <stdio.h>

typedef enum
{
	SALES, PERSONNEL, RESEARCH, PACKING
}DEPT;

typedef struct
{
	schr name[10];
	int age;
	int salary;
	DEPT department;
}EMPLOYEE;

void print(EMPLOYEE e)
{
	printf("============\n");
	printf("%s : ", e.name);
	printf("%d %d %d\n", e.age, e.salary, e.department);
	printf("============\n");
}

int main()
{
	EMPLOYEE emp[2];
	int i;
	for (i = 0; i < 2; i++)
	{
		printf("============\n");
		printf("�̸� �Է� : ");
		scanf_s("%s", &emp[i].name);
		printf("���� �Է� : ");
		scanf_s("%s", &emp[i].age);
		printf("���� �Է� : ");
		scanf_s("%s", &emp[i].salary);
		printf("�μ� �Է� : ");
		scanf_s("%s", &emp[i].department);
	}

	for (i = 0; i < 2; i++)
		print(emp[i]);
	return 0;
}
*/