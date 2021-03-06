// QuickAndHeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void  quickSort(int* arr, int begining, int end) {
	if (begining < end) {
		for (int i = 0;i < end;i++) {
			int pivotEl = arr[i];
			int indexToSwapTo = i + 1;
			for (int j = i + 1;j <= end;j++) {
				if (arr[j] < arr[i]) {
					swap(arr[j], arr[indexToSwapTo]);
					indexToSwapTo++;
				}
			}
			if (i < indexToSwapTo - 1) {
				swap(arr[i], arr[(indexToSwapTo - 1)]);
				i--;
			}
		}		
	}
}


void heapify(int* arr, int size, int parentIndex) {
	int leftChild = (parentIndex + 1) * 2 - 1;
	int rightChild = (parentIndex + 1) * 2;
	int largest = parentIndex;
	if (leftChild < size && arr[leftChild] > arr[largest]) {
		largest = leftChild;
	}
	if (rightChild < size && arr[rightChild] > arr[largest]) {
		largest = rightChild;
	}
	if (largest != parentIndex) {
		swap(arr[parentIndex], arr[largest]);
		heapify(arr, size, largest);
	}
}

void buildMaxHeap(int* arr, int size) {
	for (int i = size / 2; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

void heapsort(int* arr, int size) {
	buildMaxHeap(arr, size);
	int heapSize = size;
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapSize--; 
		heapify(arr, heapSize, 0);
	}
}

int main(){
	int arr1[] = { 5,123,34,490,23,123,43,0,45,63,23,53,500,499 };
	quickSort(arr1, 0, 13);  
	for (int i = 0; i < 14; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	int arr2[] = {2,4,1,3,6,7};
	heapsort(arr2, 6);
	for (int i = 0; i < 6; i++) {
		cout << arr2[i] << " ";
	}

	system("PAUSE");

    return 0;
}

