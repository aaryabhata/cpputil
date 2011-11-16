//============================================================================
// Name        : CPPUtil.cpp
// Author      : Vishnu Konda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int* arr, size_t size)
{
	cout<<"\n[";
	for(unsigned int i=0; i< size; ++i)
	{
			cout<<" "<<arr[i];
	}
	cout<<"]";
}

int partition2(int* input, unsigned int l, unsigned int h){

	return 0;
}
/**
 * Partitions the array and returns the pivot
 */
int partition(int* input, unsigned int l, unsigned int h ){

	int pivot = *(input + h-1); //last element

	int lessElements = 0;
	for(unsigned int i=l; i<h; ++i)
	{
		if(*(input+i) < pivot)
		{
			swap(input+i, input+l+lessElements);
			lessElements++;
		}
	}

	swap(input+l+lessElements, input+h-1);

	return l+lessElements;
}

/**
 *  indices are from lIndex <= i < hIndex
 */
void quicksort(int* input, unsigned int lIndex, unsigned int hIndex){

	if(lIndex+1 >= hIndex)
		return;

	unsigned int pivotIndex = partition(input, lIndex, hIndex);

	quicksort(input, lIndex, pivotIndex);
	quicksort(input, pivotIndex+1, hIndex);

}

int bSearch(int* input, unsigned int size, int target){

	int ret = -1;
	int l = 0;
	int h = size-1;
	int m = (l+h)/2;

	while(l <= h){

		if(input[m] == target)
		{
			if(input[m-1] < target)
			{
				ret = m;
				break;
			}else if(input[m-1] == target)
			{
				ret = m;
				h = m-1;
			}
		}else if(input[m] < target)
		{
			l = m+1;
		}else
		{
			h = m-1;
		}
		m = (l+h)/2;
	}

	return ret;
}

/**
 *
 */
void siftUp(int* a, unsigned int size){

	int i = size;

	//pre:a[1..size-1] is a heap
	//post:a[1..size] is a heap

	while( i > 0 )
	{
		int parent = i/2;

		if(a[parent] < a[i])
		{
			swap(a+parent, a+i);
			i = parent;
		}
		else
			break;
	}

	return;
}


/**
 *
 */
void siftDown(int* a, unsigned int size){

	// element to be moved down is now at a[0]

	unsigned int i = 0;

	int greater;

	while(2*i+1 < size){

		greater = i;
		if(a[2*i+1] > a[i])
			greater = 2*i+1;

		if(2*i+2 < size && a[2*i+2] > a[greater])
			greater = 2*i+2;

		if (i != greater)
		{
			swap(a+i, a+greater);
			i = greater;

		}
		else
			break;
	}

	return;
}
/**
 * Heap property: parent is greater than both children
 * if a[i] is the parent then a[2*i] and a[2*i+1] are the children
 * a[i] >= a[2*i] a[i] > a[2*i+1]
 * Build max heap
 */
void buildMaxHeap(int* a, unsigned int size){

	//Precondition
	//A[1..i] is a heap
	// After each iteration
	//A[1...i+1] is also a heap
	for(unsigned int i=1; i< size; i++)
	{
		siftUp(a, i);
	}

	return;
}

/**
 * heap sort
 */

void heapSort(int* a, unsigned int size){

	buildMaxHeap(a, size);

	for(unsigned int i=0; i < size; i++)
	{
		swap(a, a+size-i-1);
		siftDown(a, size-i-1);
	}

}


int sortAlgosDriver() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int arr[5] = {5,41,3,2,1};

	quicksort(arr, 0, 5);
	printArray(arr,5);

	int sortArray[5] = {1,1,2,2,5};

	cout<<"\nbsearch output:";
	cout<<bSearch(sortArray, 5, 2)<<endl;

	int heapArrayInput[5] = {5,4,1,1,1};

	heapSort(heapArrayInput, 5);
	cout<<"\nbuildMaxHeapOutput:";
	printArray(heapArrayInput, 5);

	return 0;
}
