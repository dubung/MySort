#include <stdio.h>
#include <time.h>
#include "MyRandom.h" // ������ ���ڹ迭������ ������
#include "MySort.h"   // ������ ������


void DataOutput(int* arr);

int main() {

    int iSize = RANDOMSIZE;
	int* arr = CreateRandom();
	if (arr == NULL)
		return 1;


    clock_t start, end;

    DataOutput(arr);
    start = clock();

    // MyInsertionSort(arr, RANDOMSIZE); // 4.4661 / 4.6470
    // MyMergeSort(arr, 0, RANDOMSIZE-1);
    MyHeapSort(arr, iSize);

    end = clock();
	DataOutput(arr);
    double duration = (double)(end - start) / CLOCKS_PER_SEC;


    // arr = MyheapPush(arr,&iSize,RANDOMSIZE+1); // ���ο��� realloc�� ���ִµ� �ȿ��� ������ ���������������� ������ ���־�� ��
    // DataOutput(arr);
    // arr = MyheapPop(arr, &iSize);
    // DataOutput(arr); 




	DeleteRandom(arr);
	return 0;
}


void DataOutput(int* arr) {
	printf("#---------------------------------------------\n");
    // �� 10���� ���
    printf("1~10 : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("%d~%d : ", RANDOMSIZE - 10, RANDOMSIZE);
    for (int i = RANDOMSIZE - 10; i < RANDOMSIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}