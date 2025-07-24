#include"MySort.h"
#include"MyRandom.h"
#include <stdlib.h>
void MySwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

// ----------------------------------------------------------------------- 힙 정렬 시작
void MyHeapSort(int* arr, int n)
{
	// 배열을 최대 힙구조로 변환 
	for (int i = n / 2 - 1; i >= 0; i--) {
		Myheapify(arr, n, i);
	}

	// 정렬 된 최대 힙구조의 root를 맨 뒤로 보내고  다시 최대 힙구조로 변환 반복
	for (int i = n - 1; i > 0; i--) {
		MySwap(&arr[0], &arr[i]);
		Myheapify(arr, i, 0);
	}


}

void Myheapify(int* arr, int n, int i)
{
	int root = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[root] < arr[left]) {
		root = left;
	}
	if (right < n && arr[root] < arr[right]) {
		root = right;
	}

	if (root != i) {
		MySwap(&arr[i], &arr[root]);
		Myheapify(arr, n, root);
	}

}
int* MyheapPush(int* arrSource, int *n, int i)
{
	(*n)++;
	int* arr = (int*)realloc((void*)arrSource, (*(n)) * sizeof(int));
	if (arr == NULL) {
		printf("Push 실패");
		return 0;
	}
	arr[*n-1] = i;
	
	// 배열을 최대 힙구조로 변환 
	for (int i = (*n-1) / 2 - 1; i >= 0; i--) {
		Myheapify(arr, *n, i);
	}

	return arr;
}
int* MyheapPop(int* arrSource, int *n)
{

	arrSource[0] = arrSource[*(n)-1];
	(*n)--;
	int* arr = (int*)realloc((void*)arrSource, (*n) * sizeof(int));
	
	// 배열을 최대 힙구조로 변환 
	for (int i = *n / 2 - 1; i >= 0; i--) {
		Myheapify(arr, *n, i);
	}
	return arr;
}
// ----------------------------------------------------------------------- 힙 정렬 끝

// ----------------------------------------------------------------------- 쉘 정렬 시작
void MyShellSort(int* arr, int iSize)
{
	int gap;
	int temp;
	int i, j, k;
	for (gap = (iSize / 2); gap > 0; gap /= 2)// 배열을 gap에 맞게 하나의 가상 배열로 나누는 과정
	{
		if (!(gap & 1)) gap++;
		for (j = 0; j < gap; j++) {
			
			for (i = j + gap; i < iSize; i+=gap) {// 삽입정렬을 실행 함
				temp = arr[i];
				for (k = i - gap; k >= j && arr[k] > temp; k -= gap) {
					arr[k + gap] = arr[k];
				}
				arr[k+gap] = temp;
			}
		}
	}


}
// ----------------------------------------------------------------------- 쉘 정렬 시작

// ----------------------------------------------------------------------- 계수 정렬 시작
void MyCountingSort(int* arr, int iSize)
{
	int maxVal = arr[0];
	for (int i = 1; i < iSize; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	int* arrCnt = (int*)calloc((maxVal+1), sizeof(int));
	if (arrCnt == NULL) {
		return;
	}

	for (int i = 0; i < iSize; i++) {
		arrCnt[arr[i]]++;
	}

	int iCnt = 0;
	for (int i = 0; i <= maxVal; i++) {

		while (arrCnt[i] > 0) {

			arr[iCnt++] = i;
			arrCnt[i]--;
		}
		
	}
	free(arrCnt);
}
// ----------------------------------------------------------------------- 계수 정렬 끝

