#include <stdio.h>

typedef unsigned short int us;
typedef struct {
	char name[12];
	us age;
	float height;
	float weight;
} Person;

int main(void) {
	Person data;

	printf("������� ������ �Է��ϼ���\n");
	printf("�̸�:");
	scanf_s("%s", data.name, sizeof(data.name));

	printf("����:");
	scanf_s("%hu", &data.age);

	printf("Ű:");
	scanf_s("%f", &data.height);

	printf("������:");
	scanf_s("%f", &data.weight);

	printf("\n�Է��� ������ ������ �����ϴ�\n");

	printf("%s : %d�� :%.1fcm : %.1fkg", data.name, data.age, data.height, data.weight);

	return 0;
}