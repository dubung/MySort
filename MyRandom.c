#include<stdio.h>
#include<stdlib.h>
#include "MyRandom.h"

void DeleteRandom(int* arr) {

	free(arr);

}
int* CreateRandom() {

	int* arr = (int*)malloc(sizeof(int) * RANDOMSIZE);
	if (arr == NULL) {
		printf("할당 실패");
		return NULL;
	}
	srand(0);

	for (int i = 0; i < RANDOMSIZE; i++) { 
		//arr[i] = rand() % (SIZE + 1); // rand()=> 32768 16bit까지만 표현
		arr[i] = ((rand() << 15) | rand()) % (RANDOMSIZE + 1);
	}

	return arr;
}