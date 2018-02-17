#include <stdio.h>

typedef struct {
	int num1, num2;
	int add;
	int min;
	int mul;
	int div;
}Result;

void Calc(Result*res) {
	res->add = res->num1 + res->num2;
	res->min = res->num1 - res->num2;
	res->mul = res->num1 * res->num2;
	res->div = res->num1 / res->num2;
}

void Print_res(Result*res, int sel) {
	switch(sel) {
	case 1:
		printf("결과 : %d\n", res->add);
		break;
	case 2:
		printf("결과 : %d\n", res->min);
		break;
	case 3:
		printf("결과 : %d\n", res->mul);
		break;
	case 4:
		printf("결과 : %d\n", res->div);
		break;
	default:
		printf("잘못된 입력\n");
		break;
	}
}

void Input(Result*res) {
	printf("첫번쨰 입력:");
	scanf_s("%d", &res->num1);
	printf("두번쨰 입력:");
	scanf_s("%d", &res->num2);
}

int main(void) {
	Result res;
	int sel;
	printf("==계산 프로그램==\n");
	printf("계산에 쓰일 숫자를 입력하십시오\n");
	Input(&res);
	Calc(&res);
	printf("연산선택\n");
	printf("선택:");
	scanf_s("%d", &sel);
	Print_res(&res, sel);
	return 0;
}