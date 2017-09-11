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

void findSeq(uint32_t* mas, uint8_t size) {
	uint16_t sum = 0;
	uint8_t num = 0;

	uint16_t maxSum = 0;
	uint8_t maxNum = 0;

	for (uint8_t i = 0; i < size; i++) {
		while (mas[i] % 2 == 0 && i < size) {
			sum += mas[i];
			num++;
			i++;
		}

		if (sum > maxSum) {
			maxSum = sum;
		}
		if (num > maxNum) {
			maxNum = num;
		}

		sum = 0;
		num = 0;
	}

	printf("Max sequence: %hhi.\n", maxNum);
	printf("Max sum: %hi.\n", maxSum);
}

int main(void) {
	uint32_t A[100] = { 0 };
	uint8_t sizeA = 0;

	printf("Input size of mas A: ");
	scanf_s("%hhi", &sizeA);

	srand((unsigned int)time(NULL));
	initMas(A, sizeA);
	printf("Mas A: ");
	printMas(A, sizeA);

	findSeq(A, sizeA);

	return 0;
}