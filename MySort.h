#pragma once
void MySwap(int* a, int* b);

// 버블 정렬
void MyBubbleSort(int* arr, int iSize); // 일반 
void MyNewBubbleSort(int* arr, int iSize);// 최적화 직전 정렬에서 마지막으로 정렬된 인덱스까지만 정렬 
// 버블 정렬

// 삽입 정렬
void MyInsertionSort(int* arr, int iSize);
// 삽입 정렬

// 병합 정렬
void MyMergeSort(int* arr, int iStart, int iEnd);		// 분할 단계
void MyMerge(int* arr, int iStart, int iMid, int iEnd); // 병합 단계
// 병합 정렬

// 힙 정렬
void MyHeapSort(int *arr, int n);
void Myheapify(int *arr, int n, int i); 
int* MyheapPop(int* arrSource, int* n);
int* MyheapPush(int* arrSource, int* n, int i);
// 힙 정렬