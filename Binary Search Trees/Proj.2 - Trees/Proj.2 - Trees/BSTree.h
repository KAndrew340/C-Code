#pragma once
#include<fstream>
#include<iostream>

using namespace std;

class BSTree
{
private:
	struct Node
	{
		char data;
		int count;
		Node *left, *right;
	};
	Node *root;		//Pointer to root of tree
	int LetterCount;		// holds number of distinct letters (# of nodes in tree)
	int TotCount;			// holds total number of characters in text
	void InsertNode(Node *&ptr, char x); //Creates each node of BSTree
	void Del(Node *&ptr);				 //Deletes nodes with values less than the average
	void PruneTreeNodes(Node *&ptr, int avg); //Searches the tree for values less than the average 
	void displayPostOrder(Node *root);  //Prints a Post Order traversal of BSTree
	char findSmallestInRightSubTree(Node *subroot); //Finds the smallest value in right sub tree of a specific node 
	

public:
	BSTree();		//Constructor
	~BSTree();		//Destructor
	void Insert(char x); //Passes data of nodes to be inserted to InsertNode function
	void PruneTree();	//Passes data of nodes to be pruned to PruneTreeNodes function
	void GraphVizGetIds(Node *nodePtr, ofstream &VizOut);  //Gets info of BSTree for Graph Viz
	void GraphVizMakeConnections(Node *nodePtr, ofstream &VizOut); //Makes node connections
	void GraphVizOut(string filename); //Output file for graphviz
	void count();	//Displays the total count and letter count
	void showPostOrder();	//Passes the pointer of root of tree to displayPostOrder function
	
	

};

