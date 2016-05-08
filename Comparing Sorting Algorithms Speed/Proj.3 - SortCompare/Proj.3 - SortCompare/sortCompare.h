//***************************************************************
//						Kem Andrew
//					   Sort Compare
//			  CMPS 3013 - Program 3: Sort Compare
//					    4/7/2015
//***************************************************************
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#pragma once
class sortCompare
{
	
public:
	sortCompare();
	~sortCompare();

	//These intergers store the # of compares for each algorithm
	int B_compares, I_compares, M_compares, Q_compares;

	//O(n log n) sorts:
	void quickSort(int arr[], int left, int right);
	void MergeSort(int *A, int n);
	void Merge(int *A, int *L, int leftCount, int *R, int rightCount);

	//O(n^2):
	void BubbleSort(int A[], int size);
	void InsertionSort(int A[], int n);
};

