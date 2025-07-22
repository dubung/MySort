#include<stdio.h>
#include<stdlib.h>
#include "MyRandom.h"

void DeleteRandom(int* arr) {

	free(arr);

}
int* CreateRandom() {

	int* arr = (int*)malloc(sizeof(int) * RANDOMSIZE);
	if (arr == NULL) {
		printf("�Ҵ� ����");
		return NULL;
	}
	srand(0);

	for (int i = 0; i < RANDOMSIZE; i++) { 
		//arr[i] = rand() % (SIZE + 1); // rand()=> 32768 16bit������ ǥ��
		arr[i] = ((rand() << 15) | rand()) % (RANDOMSIZE + 1);
	}

	return arr;
}