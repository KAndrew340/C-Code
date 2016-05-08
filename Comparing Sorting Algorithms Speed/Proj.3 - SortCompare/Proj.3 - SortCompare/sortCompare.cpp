//***************************************************************
//				  Kem Andrew
//			     Sort Compare
//		CMPS 3013 - Program 3: Sort Compare
//				4/7/2015
//***************************************************************
#include "sortCompare.h"

sortCompare::sortCompare()
{
	B_compares = 0;
	I_compares = 0;
	M_compares = 0;
	Q_compares = 0;
}


sortCompare::~sortCompare()
{
}


// The BubbleSort method accepts the array and its size as arguments
// sorts the array using the bubble sort algorithm.
/////////////////////////////////////////////////////////////////
void sortCompare::BubbleSort(int A[], int size)
{
	B_compares;
	int temp;
	for (int j = size - 1; j>0; j--)
	{
		for (int i = 0; i<size; i++)
		{
			if (++B_compares && A[i] > A[i + 1])
			{
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}
		size--;
	}
}

// The quickSort method accepts the array and its left and right most 
// indexes as arguments, it then sorts the array using the 
// Quick Sort algorithm.
/////////////////////////////////////////////////////////////////
void sortCompare::quickSort(int arr[], int left, int right)
{
		int i = left, j = right;
		int tmp;
		int pivot = arr[(left + right) / 2];

		/* partition */
		while (++Q_compares && i <= j) {

			while (++Q_compares && arr[i] < pivot)
				i++;

			while (++Q_compares && arr[j] > pivot)
				j--;

			if (++Q_compares && i <= j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

				i++;
				j--;
			}
		};

		/* recursion */
		if (++Q_compares && left < j)
			quickSort(arr, left, j);

		if (++Q_compares && i < right)
			quickSort(arr, i, right);
}

// The InsertionSort method accepts the array and its size as arguments,
// it then sorts the array using the Insertion Sort algorithm.
/////////////////////////////////////////////////////////////////
void sortCompare::InsertionSort(int A[], int n)
{
	int temp;
	int value;
	for (int i = 1; i<n; i++)
	{
		value = A[i];
		temp = i;
		while (++I_compares && temp>0 && A[temp - 1]>value)
		{
			A[temp] = A[temp - 1];
			temp = temp - 1;
		}
		A[temp] = value;
	}
}



// The MergeSort method accepts the array and its size as arguments,
// it then sorts the array using the Merge Sort algorithm.
/////////////////////////////////////////////////////////////////

// Recursive function to sort an array of integers.
void sortCompare::MergeSort(int *A, int n) {
	int mid, i, *L, *R;
	if (++M_compares && n < 2) return; // base condition. If the array has less than two element, do nothing.

	mid = n / 2; // find the mid index.

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n - mid)*sizeof(int));
	for (i = 0; i<mid; i++) L[i] = A[i]; // creating left subarray
	for (i = mid; i<n; i++) R[i - mid] = A[i]; // creating right subarray

	MergeSort(L, mid); // sorting the left subarray
	MergeSort(R, n - mid); // sorting the right subarray
	Merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
	free(L);
	free(R);
}


// The Merge function merges and sorts the individual arrays broken 
// down in the MergeSort method into a single array
// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void sortCompare::Merge(int *A, int *L, int leftCount, int *R, int rightCount) {
	int i, j, k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k = 0;

	while (++M_compares && i<leftCount && j< rightCount) {
		if (++M_compares && L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while (++M_compares && i < leftCount) A[k++] = L[i++];
	while (++M_compares && j < rightCount) A[k++] = R[j++];
}