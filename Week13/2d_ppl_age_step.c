#include <stdio.h>
#include <malloc.h>

int main(void) {
	int age_step, ages, member, temp, sum;
	unsigned char* p_limit_table;
	unsigned char** p;

	printf("20�����(?����) �����ؼ� �������� �� ���Դϱ�? : ");
	scanf_s("%d", &age_step);

	p_limit_table = (unsigned char*)malloc(age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*) * age_step);

	for (ages = 0; ages < age_step; ages++) {

		printf("\n%d0�� ������ ���� ����Ű�� Ƚ��\n", ages + 2);
		printf("�� ���ɴ�� �� ���Դϱ�? ");

		scanf_s("%d", &temp);
		*(p_limit_table + ages) = (unsigned char)temp;

		*(p + ages) = (unsigned char*)malloc(*(p_limit_table + ages));

		for (member = 0; member < *(p_limit_table + ages); member++) {
			printf("#%d: ", member + 1);

			scanf_s("%d", &temp);
			*(*(p + ages) + member) = (unsigned char)temp;
		}
	}

	printf("\n\n���ɺ� ��� ���� ����Ű�� Ƚ��\n");

	for (ages = 0; ages < age_step; ages++) {
		sum = 0;
		printf("%d0��: ", ages + 2);

		for (member = 0; member < *(p_limit_table + ages); member++) {
			sum = sum + *(*(p + ages) + member);
		}
		printf("%5.2f\n", (double)sum / *(p_limit_table + ages));

		free(*(p + ages));
	}
	free(p);
	free(p_limit_table);

	return 0;
}