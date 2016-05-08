//***************************************************************
//				Kem Andrew
//			Binary Search Trees
//		CMPS 3013 - Program 2: Letter Count
//				3/10/2015
//
// This program retrieves the letters from a file and creates a
// BSTree from the data. The program keeps count of each distinct
// letter in the tree and creates a node for each letter. The 
// program also keeps track of how many times each distinct letter
// has been added to the tree. The program then computes the 
// average of the letters and prunes the tree by deleting all
// letters with counts smaller than the average. The program also 
// creates a Graphviz file for tree display
//***************************************************************

#include<iostream>
#include "BSTree.h"

using namespace std;

int main()
{
	BSTree b;
	char ch;
	ifstream infile;
	// open file for reading
	infile.open("input.txt");
	// test for input file
	if (infile.fail())
	{
		cout << "Could not open file. \n\n";
		system("pause");
		return 0;
	}
	while (!infile.eof())
	{
		infile >> ch;
		ch = tolower(ch);
		if (ch >96 && ch < 123)
			b.Insert(ch);
	}
	infile.close();
	
	cout << "\n Kem Andrew \n CMPS 3013 - Program 2: Letter Count \n 3/10/2015 \n\n";
	b.showPostOrder();				//Displays the post orddr traversal of the BSTree
	//b.count();						//Displays the total count and letter count
	//b.GraphVizOut("original.dot");		//GraphViz .dot file
	b.PruneTree();						//Prunes the tree
	cout << endl;
	b.showPostOrder();
	//b.GraphVizOut("pruned.dot");
	system("pause");
	return 0;
}
