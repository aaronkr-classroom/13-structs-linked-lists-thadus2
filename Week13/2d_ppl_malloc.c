#include <stdio.h>
#include <malloc.h>

int main(void) {
	int ages, member, temp, sum;
	unsigned char limit_table[3];
	unsigned char* p[3];

	for (ages = 0; ages < 3; ages++) {
		printf("\n%d0´ë ¿¬·ÉÀÇ À­¸ö ÀÏÀ¸Å°±â È½¼ö\n", ages + 2);
		printf("ÀÌ ¿¬·É´ë´Â ¸î ¸íÀÔ´Ï±î? ");

		scanf_s("%d", &temp);
		limit_table[ages] = (unsigned char)temp;

		p[ages] = (unsigned char*)malloc(limit_table[ages]);

		for (member = 0; member < limit_table[ages]; member++) {
			printf("#%d: ", member + 1);

			scanf_s("%d", &temp);
			*(p[ages] + member) = (unsigned char)temp;
		}
	}

	printf("\n\n¿¬·Éº° Æò±Õ À­¸ö ÀÏÀ¸Å°±â È½¼ö\n");

	for (ages = 0; ages < 3; ages++) {
		sum = 0;
		printf("%d0´ë: ", ages + 2);

		for (member = 0; member < limit_table[ages]; member++) {
			sum = sum + *(p[ages] + member);
		}
		printf("%5.2f\n", (double)sum / limit_table[ages]);

		free(p[ages]);
	}

	return 0;
}