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
void MyHeapSort(int *arr, int iSize);
void Myheapify(int *arr, int iSize, int i);
int* MyheapPop(int* arrSource, int* iSize);
int* MyheapPush(int* arrSource, int* iSize, int i);
// �� ����

// �� ����
void MyShellSort(int* arr, int iSize);
// �� ����

// ��� ����
void MyCountingSort(int* arr,int iSize);
// ��� ����

