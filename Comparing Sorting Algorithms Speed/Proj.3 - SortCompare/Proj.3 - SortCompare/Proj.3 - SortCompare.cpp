//***************************************************************
//						Kem Andrew
//					   Sort Compare
//			  CMPS 3013 - Program 3: Sort Compare
//					    4/7/2015
//
// This program sorts an array of random intergers using four different 
// sorting algorithms, each algorithm is timed and the number of
// comparisons are counted. The size of the array is increased 
// and the process is repeated over ten runs. The data for both time 
// and comparisons is saved to a csv file.
//***************************************************************
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include "sortCompare.h"
#include<time.h>
#include <iomanip>

using namespace std;

void fillarray(int a[], int size, int seed);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Kem Andrew \n CMPS 3013 - Program 3: Sort Compare \n 4/7/2015 \n\n";
	sortCompare x;
	int* alist;
	int seed, size = 2000, start, stop;

	// These varialbes store the average over 10 runs
	double Q_average = 0, I_average = 0, B_average = 0, M_average = 0;
	//Theses variables store the time after each run
	double Q_total = 0, I_total = 0, B_total = 0, M_total = 0;
	
	//These arrays stores the values of the 10 runs to be averaged
	int results_Q[10];
	int results_M[10];
	int results_I[10];
	int results_B[10];

	//Output Files
	ofstream outfile;		//Timing output
	ofstream outfile2;		//Comparison output
	cout << "Creating files... \n";
	outfile.open("results.csv");
	outfile2.open("results2.csv");
	outfile << "QuickSort, MergeSort, InsertionSort, BubbleSort \n";
	outfile2 << "QuickSort, MergeSort, InsertionSort, BubbleSort \n";
	
	
	for (size = 1000; size <= 10000; size += 1000)		//This is the size of the array that is sorted
	{
		for (int i = 0; i < 10; i++) //This loop times 10 runs
		{
			// Declare a new seed for the random function each time through the loop
			seed = rand();
			// Dynamically create array
			alist = new int[size];

			//QUICK SORT
			fillarray(alist, size, seed);
			start = clock();
			x.quickSort(alist, 0, size);
			stop = clock();
			Q_total = double(stop - start) / CLOCKS_PER_SEC;
			cout << Q_total;
			cout << endl << x.Q_compares << endl << endl;

			//MERGE SORT
			fillarray(alist, size, seed);
			start = clock();
			x.MergeSort(alist, size);
			stop = clock();
			M_total = double(stop - start) / CLOCKS_PER_SEC;
			cout << endl << M_total;
			cout << endl << x.M_compares << endl << endl;

			//INSERTION SORT
			fillarray(alist, size, seed);
			start = clock();
			x.InsertionSort(alist, size);
			stop = clock();
			I_total = double(stop - start) / CLOCKS_PER_SEC;
			cout << endl << I_total;
			cout << endl << x.I_compares << endl << endl;

			//BUBBLE SORT
			fillarray(alist, size, seed);
			start = clock();
			x.BubbleSort(alist, size);
			stop = clock();
			B_total = double(stop - start) / CLOCKS_PER_SEC;
			cout << endl << B_total;
			cout << endl << x.B_compares << endl << endl;

			// These arrays store the values over 10 runs 
			results_Q[i] = Q_total;
			results_M[i] = M_total;
			results_I[i] = I_total;
			results_B[i] = B_total;
		}
		// This loop calculates the total times of the ten runs of each algorithm
		for (int i = 0; i < 10; i++)
		{
			Q_total += results_Q[i];
			I_total += results_I[i];
			B_total += results_B[i];
			M_total += results_M[i];
		}

		// Averages
		Q_average = Q_total / 10;
		I_average = I_total / 10;
		B_average = B_total / 10;
		M_average = M_total / 10;

		// Output
		outfile << Q_average << ", " << M_average << ", " << I_average << ", " << B_average << "\n";
		outfile2 << x.Q_compares << ", " << x.M_compares << ", " << x.I_compares << ", " << x.B_compares << "\n";
		
		// Don't forget  to take out the garbage
		//delete[] alist;
	}
	
	/*outfile.close();
	cout << "Finished! \n";*/
	/*system("pause");
	return 0;*/
	
	system("pause>0");
}


// Fills the array with random numbers
void fillarray(int a[], int size, int seed)
{
	srand(seed);
	for (int i = 0; i < size; i++)
		a[i] = rand();
}

