#include <stdio.h>
#include <time.h>
#include "MyRandom.h" // 랜덤한 숫자배열생성을 도와줄
#include "MySort.h"   // 정렬을 도와줄


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


    // arr = MyheapPush(arr,&iSize,RANDOMSIZE+1); // 내부에서 realloc을 해주는데 안에서 선언한 지역변수였음으로 밖으로 빼주어야 됨
    // DataOutput(arr);
    // arr = MyheapPop(arr, &iSize);
    // DataOutput(arr); 




	DeleteRandom(arr);
	return 0;
}


void DataOutput(int* arr) {
	printf("#---------------------------------------------\n");
    // 앞 10개만 출력
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