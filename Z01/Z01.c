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

uint8_t newMas(uint32_t* A, uint32_t* B, uint32_t* C, uint8_t sizeA, uint8_t sizeB) {
	uint8_t indC = 0;

	for (uint8_t indA = 0; indA < sizeA; indA++) {
		bool flag = true;
		for (uint8_t indB = 0; indB < sizeB; indB++) {
			if (A[indA] == B[indB]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (uint8_t ind = 0; ind < indC; ind++) {
				if (C[ind] == A[indA]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				C[indC++] = A[indA];
			}
		}
	}

	return indC;
}

int main(void) {
	uint32_t A[100] = { 0 };
	uint32_t B[100] = { 0 };
	uint32_t C[100] = { 0 };

	uint8_t sizeA = 0;
	uint8_t sizeB = 0;

	printf("Input size of mas A: ");
	scanf_s("%hhi", &sizeA);

	printf("Input size of mas B: ");
	scanf_s("%hhi", &sizeB);

	srand((unsigned int)time(NULL));
	initMas(A, sizeA);
	printf("Mas A: ");
	printMas(A, sizeA);

	initMas(B, sizeB);
	printf("Mas B: ");
	printMas(B, sizeB);

	uint8_t sizeC = newMas(A, B, C, sizeA, sizeB);

	printf("Mas C: ");
	printMas(C, sizeC);

	return 0;
}