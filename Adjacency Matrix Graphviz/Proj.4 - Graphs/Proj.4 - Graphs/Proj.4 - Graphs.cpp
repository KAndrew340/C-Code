//***************************************************************
//						Kem Andrew
//						  Graphs
//				CMPS 3013 - Program 4: Graphs
//						4/27/2015
//
// This program retrieves an adjacency matrix from a file along
// its size. The program then checks for the graph for symmetry
// and creates a dot file that can be read by GraphViz to create
// a visual representation of the graph
// To run the program, change the infile.open parameter to the
// appropriate file name.
// The array will be displayed in the terminal but GraphViz file
// will be created in the 'projects' folder.
//***************************************************************
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//function prototype
bool checkSymmetric(int *[], int size);
bool Euler(int myArray[], int size);


int _tmain(int argc, _TCHAR* argv[])
{
	cout << " Kem Andrew\n Graphs\n CMPS 3013 - Program 4: Graphs \n 4/27/2015 \n\n";
	
	int value;			//holds the value returned by the symmetric function
	int size;			//holds the size of the 2d array
	int **matrix;		//dynamic 2d array that holds the matrix
	int *values;		//dynamic 1d array that holds values of the edges
	ifstream infile;	//creates a file object to handle the input file

	infile.open("data2.txt");

	//This code prints the contents of the input file to the terminal
	/*while (infile.good())
		cout << (char)infile.get();
	infile.close();*/
	
	//assigns a value to 'size' variable
	infile >> size;
	
	// This block of code creates an array to check for Euler circuit
	// Each edge in the graph corresponds to an array index and is initialized 
	// to zero.
	values = new int[size];
	for (int i = 0; i<size; i++)
	{
		values[i] = 0;
	}

	//Dynamically allocate the 2d array
	matrix = new int*[size];
	for (int count = 0; count < size; count++)
	{
		matrix[count] = new int[size];
	}

	for (int i = 0; i < size; i++) // loop through the 1st dimension of the array
	{
		for (int j = 0; j < size; j++)
		{	// loop through the 2nd dimension of the array
			(infile >> matrix[i][j]); // read to each element of the array 
		}
	}

	for (int i = 0; i < size; i++) // loop through the 1st dimension of the array
	{
		for (int j = 0; j < size; j++) // loop through the 2nd dimension of the array
			(cout << matrix[i][j]);
		cout << endl; 
	}
	infile.close();

	// this object handles the outputfile manipulation
	ofstream VizOut;
	
	// assigns the boolean value of the array checked to 'value' variable
	value = checkSymmetric(matrix, size);

	// This block of code creates a directed graph if the maatrix is symmetric
	if (value == 0)
	{
		// Directed Graph
		cout << "\n directed graph \n";
		VizOut.open("digraph.dot");		// creates GraphViz dot file
		VizOut << "// Kem Andrew \n";
		VizOut << "// File created by C++ Proj.4 - Graphs \n";
		VizOut << "digraph { \n";
		VizOut << "name[shape = box, label = \"Kem Andrew \\nGraphs Project \\nSpring 2015 \\nDirected Graph\"]; \n";

		for (int i = 0; i < size; i++)
		{
			VizOut << i << "[label=\"" << i;
			VizOut << "\"]" << endl;
		}


		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (matrix[i][j] == 1 /*&& (i < j)*/)
				{
					VizOut << i << "->" << j << ";" << endl;
				}
				//cout << endl;
			}
		}
		VizOut << "} \n";
		VizOut.close();
	}

	// This block of code creates an undirected graph if the maatrix is not symmetric
	else
	{
		// Undirected Graph
		cout << "\n undirected graph \n";
		VizOut.open("graph.dot");			// creates GraphViz dot file
		VizOut << "// Kem Andrew \n";
		VizOut << "// File created by C++ Proj.4 - Graphs \n";
		VizOut << "graph { \n";
		VizOut << "name[shape = box, label = \"Kem Andrew \\nGraphs Project \\nSpring 2015 \\nUndirected Graph\"]; \n";

		for (int i = 0; i < size; i++)
		{
			VizOut << i << "[label=\"" << i;
			VizOut << "\"]" << endl;
		}

		
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (matrix[i][j] == 1 && (i < j))
				{
					values[i] += 1; // This line increments the values corresponding to array index
									// to check for Euler's circuit. index# = edge#.
					VizOut << i << "--" << j << ";" << endl;
				}
			}
		}
		VizOut << "} \n";
		VizOut.close();
	}
	infile.close();

	Euler(values, size);

	// free dynamically allocated memory
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	
	system("pause");
	return 0;
}

// This function checks whether the graph is symmetric
// returns true if it is and false if the graph is not
// symmetric
///////////////////////////////////////////////////////
bool checkSymmetric(int **array, int size)
{
	//Checks if there are any 1's  along the diagonal
	for (int i = 0; i < size; i++)
	{
		if (array[i][i] == 1)
			return false;
	}
	//Checks for other symmetry
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i][j] != array[j][i])
			{
				return false;
			}
		}
	}
	//only returns true if both conditions are false
	return true;
}


// This function checks for Euler's circuit by finding
// odd numbered edges in the graph and returns result.
//////////////////////////////////////////////////////
bool Euler(int myArray[], int size)
{
	for (int i = 0; i<size; i++)
	{
		//checks if there's an odd edge in graph
		if (myArray[i] % 2 == 1)
			cout << "\n This graph does not contain a Euler circuit \n";
			return true;
	}
	cout << "\nGraph contains a Euler circuit. \n";
	return false;
}