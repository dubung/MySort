#pragma once
void MySwap(int* a, int* b);

// ���� ����
void MyBubbleSort(int* arr, int iSize); // �Ϲ� 
void MyNewBubbleSort(int* arr, int iSize);// ����ȭ ���� ���Ŀ��� ���������� ���ĵ� �ε��������� ���� 
// ���� ����

// ���� ����
void MyInsertionSort(int* arr, int iSize);
// ���� ����

// ���� ����
void MyMergeSort(int* arr, int iStart, int iEnd);		// ���� �ܰ�
void MyMerge(int* arr, int iStart, int iMid, int iEnd); // ���� �ܰ�
// ���� ����

// �� ����
void MyHeapSort(int *arr, int n);
void Myheapify(int *arr, int n, int i); 
int* MyheapPop(int* arrSource, int* n);
int* MyheapPush(int* arrSource, int* n, int i);
// �� ����