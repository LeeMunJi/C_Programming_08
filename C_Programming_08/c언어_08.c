// 구조체로 데이터 묶기

/*
struct 구조체이름
{
	구조체 멤버(변수)
};
*/

// 구조체 선언 != 변수 선언
// 구조체 변수의 선언 : struct 구조체태그 변수이름
// 구조체 멤버 접근 : 멤버 연산자 (.) 사용
// 구조체 안에 구조체 가능
// 배열과 같이 구조체 변수 선언과 동시에 초기화 가능
// 구조체 간의 대입 가능, 비교 불가능(각 멤버를 비교해야함)

// 예제 코드 : 점과 점 사이의 거리
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

	printf("거리 : %f\n", dist);

	return 0;
}
*/

// 예제 코드 : 주소록 관리
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

	printf("이름 입력 : ");
	// scanf_s("%s", c1.name);
	gets(c1.name);

	printf("주소 입력 : ");
	// scanf_s("%s", c1.addr); // scanf가 공백을 처리하지 못하는 문제로 인해 오류 생김
	gets(c1.addr);

	printf("번호 입력 : ");
	// scanf_s("%s", c1.tel);
	gets(c1.tel);

	printf("%s %s %s", c1.name, c1.addr, c1.tel);
}
*/

// 구조체 응용하기

// 예제 코드 : 학생 성적 저장
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
	{"홍길동",82,72,58},
	{"강감찬",97,82,39},
	{"이순신",52,62,39}
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

// 예제 코드 : 학생 성적 처리 (최고 득점자 찾기)
/*
#include <stdio.h>

struct student
{
	char name[20];
	double gpa;
};

struct student list[] = {
	{"홍길동",2.2},
	{"강감찬",4.2},
	{"이순신",3.9}
};

int main()
{
	struct student top;
	int i, size;

	size = sizeof(list) / sizeof(list[0]); // ★
	
	top = list[0]; // ★

	for (i = 0; i < size; i++)
	{
		if (list[i].gpa > top.gpa)
			top = list[i];
	}
	printf("%s %f", top.name, top.gpa);

	return 0;
}
*/

// 바이트 패딩 : 컴파일러가 레지스터 블록에 맞추어 바이트를 패딩해주는 최적화 작업

// 구조체의 포인터
// 포인터 통해 구조체 멤버 접근 : 간접 참조 연산자(*) 사용, 간접 멤버 연산자(->) 사용

// 예제 코드 : 벡터
/*
#include <stdio.h>

struct vec
{
	double x, y;
};

struct vec sum_vec(struct vec a, struct vec b)
{
	return a + b; // 오류(?)
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

// 공용체 (union)
// 하나의 메모리 공간을 여러 개의 변수들이 공유할 수 있음(가장 큰 메모리 변수 기준으로 공간 공유)

// 열거형 (enum)
// 변수가 가질 수 있는 값들을 하나씩 나열해놓음(기호 상수만을 가짐)
// 기호 상수에 값 지정 가능(일부만 지정하는 것도 가능)
// 일부 지정한 경우, 지정되지 않은 상수는 앞의 상수보다 1 증가된 값 가짐

// typedef
// typedef unsigned char BYTE = BYTE num

// 예제 : 점의 평행이동
/*
#include <stdio.h>

typedef struct point
{
	int x, y;
}POINT;

POINT translate(POINT p, POINT delta) // 점의 초기 좌표와 이동거리 전달하여 이동된 점의 좌표 계산
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

// 예제 코드 : 좌표 일치 판단
/*
#include <stdio.h>

typedef struct point
{
	int x, y;
}POINT;

int equal(POINT* a, POINT* b)
{
	if ((*a).x == (*b).x && (*a).y == (*b).y)
		return 1; // 두 점 좌표 일치하면 1 반환
	return 0; // 일치하지 않으면 0 반환
}

void main()
{
	POINT p1 = { 1,2 };
	POINT p2 = { 3,4 };

	if (equal(&p1, &p2) == 1)
		printf("같음");
	else
		printf("다름");
}
*/

// 예제 코드 : 복소수 덧셈
// a+bi : 실수는 실수끼리, 허수는 허수끼리 연산 수행
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

// 예제 코드 : 인사관리
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
		printf("이름 입력 : ");
		scanf_s("%s", &emp[i].name);
		printf("나이 입력 : ");
		scanf_s("%s", &emp[i].age);
		printf("월급 입력 : ");
		scanf_s("%s", &emp[i].salary);
		printf("부서 입력 : ");
		scanf_s("%s", &emp[i].department);
	}

	for (i = 0; i < 2; i++)
		print(emp[i]);
	return 0;
}
*/