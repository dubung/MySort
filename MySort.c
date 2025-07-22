#include"MySort.h"
#include"MyRandom.h"
#include <stdlib.h>
void MySwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = *a;
}
// ----------------------------------------------------------------------- 버블 정렬 시작
void MyBubbleSort(int* arr, int iSize)
{
	if (iSize == 1)
		return;

	int isSwap = 0;

	for (int i = 0; i < iSize - 1; i++) {
		isSwap = 0;
		for (int j = 0; j < iSize - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				MySwap(&arr[j], &arr[j + 1]);
				isSwap = 1;
			}
		}
		if (!isSwap)
			break;
	}

}

void MyNewBubbleSort(int* arr, int iSize)
{

	int iLastSwapIndex = 0;
	int iNewSize = iSize;

	while (iNewSize > 0) {

		iLastSwapIndex = 0;

		for (int i = 0; i < iNewSize - 1; i++) {

			if (arr[i] > arr[i + 1]) {
				MySwap(&arr[i], &arr[i + 1]);
				iLastSwapIndex = i + 1;// 마지막 교환된 인덱스 저장
			}

		}

		iNewSize = iLastSwapIndex;

	}
}
// ----------------------------------------------------------------------- 버블 정렬 끝

// ----------------------------------------------------------------------- 삽입 정렬 시작

void MyInsertionSort(int* arr, int iSize)
{

	int j, i;
	for (i = 1; i < iSize; i++) {

		int temp = arr[i];

		for (j = i; j > 0 && arr[j - 1] > temp; j--) {
			arr[j] = arr[j - 1];
		}

		//for (j = i; j > 0; j--) {
		//	if(arr[j - 1] <= temp){
		//		break;
		//	}
		//	else
		//		arr[j] = arr[j - 1];
		//}

		arr[j] = temp;
	}
}
// ----------------------------------------------------------------------- 삽입 정렬 끝

// ----------------------------------------------------------------------- 병합 정렬 시작

void MyMergeSort(int* arr, int iStart, int iEnd)
{
	if (iStart < iEnd) {
		int iMid = (iEnd + iStart) / 2;

		// 분할 해주는 곳
		MyMergeSort(arr, iStart, iMid);
		MyMergeSort(arr, iMid + 1, iEnd);

		// 병합해주는 곳
		MyMerge(arr, iStart, iMid, iEnd);

	}
}

void MyMerge(int* arr, int iStart, int iMid, int iEnd)
{// 사실 보니깐 동적할당은 하나만 해서 정렬하면서 넣고 복사하는게 편함

	int iIndex = iStart;

	int iL = (iMid - iStart) + 1;
	int iR = (iEnd - iMid);
	
	int* pL = (int*)malloc(sizeof(int) * iL);
	int* pR = (int*)malloc(sizeof(int) * iR);

	if (pL == NULL || pR == NULL)
		return;

	for (int i = 0; i < iL; i++) 
		pL[i] = arr[iStart + i];
	for (int i = 0; i < iR; i++) 
		pR[i] = arr[iMid + i + 1];

	int i = 0, j = 0;

	while(i < iL && j < iR){

		if (pL[i] < pR[j]) {//오름 차순
			arr[iIndex++] = pL[i++];
		}
		else {
			arr[iIndex++] = pR[j++];
		}
				
	}

	while (i < iL)arr[iIndex++] = pL[i++];
	while (j < iR)arr[iIndex++] = pR[j++];
	
	free(pL);
	free(pR);
}

// ----------------------------------------------------------------------- 병합 정렬 끝



