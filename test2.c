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
		printf("��� : %d\n", res->add);
		break;
	case 2:
		printf("��� : %d\n", res->min);
		break;
	case 3:
		printf("��� : %d\n", res->mul);
		break;
	case 4:
		printf("��� : %d\n", res->div);
		break;
	default:
		printf("�߸��� �Է�\n");
		break;
	}
}

void Input(Result*res) {
	printf("ù���� �Է�:");
	scanf_s("%d", &res->num1);
	printf("�ι��� �Է�:");
	scanf_s("%d", &res->num2);
}

int main(void) {
	Result res;
	int sel;
	printf("==��� ���α׷�==\n");
	printf("��꿡 ���� ���ڸ� �Է��Ͻʽÿ�\n");
	Input(&res);
	Calc(&res);
	printf("���꼱��\n");
	printf("����:");
	scanf_s("%d", &sel);
	Print_res(&res, sel);
	return 0;
}