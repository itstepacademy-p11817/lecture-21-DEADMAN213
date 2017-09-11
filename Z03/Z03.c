#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void initMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		*(val + i) = rand() % 11;
	}
}

void printMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		printf("%3i", *(val + i));
	}
	printf("\n");
}

uint8_t deleteElem(uint32_t* mas, uint8_t size, bool flag) {
	for (uint8_t i = 0; i < size; i++) {
		if (mas[i] % 2 == 0 && flag) {
			for (uint8_t j = i; j < size-1; j++) {
				mas[j] = mas[j + 1];
			}
			size--;
			i--;
		}

		if (mas[i] % 2 != 0 && !flag) {
			for (uint8_t j = i; j < size - 1; j++) {
				mas[j] = mas[j + 1];
			}
			size--;
			i--;
		}

	}

	return size;
}

int main(void) {
	uint32_t A[100] = { 0 };
	uint8_t sizeA = 0;
	uint8_t newSize = 0;

	printf("Input size of mas A: ");
	scanf_s("%hhi", &sizeA);

	srand((unsigned int)time(NULL));
	initMas(A, sizeA);
	printf("Mas A: ");
	printMas(A, sizeA);

	uint8_t ch = 0;
	printf("Menu:\n");
	printf("1 - to delete even elements.\n");
	printf("2 - to delete odd elements.\n");
	printf("Input choce: ");
	scanf_s("%hhi", &ch);

	switch (ch)	{
	case 1:
		newSize = deleteElem(A, sizeA, true);
		break;

	case 2:
		newSize = deleteElem(A, sizeA, false);
		break;

	default:
		printf("Wrong input.\n");
		break;
	}

	printf("Mas A: ");
	printMas(A, newSize);

	return 0;
}