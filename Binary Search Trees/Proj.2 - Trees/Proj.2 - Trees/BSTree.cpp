#include "BSTree.h"
#include<iostream>
#include<fstream>

using namespace std;

BSTree::BSTree()
{
	root = NULL;
	TotCount = 0;
	LetterCount = 0;
}


BSTree::~BSTree()
{
}

// The count method cna be called to display the totalnumber of 
// distinct letters inthe tree and total number of overall letters in tree
//////////////////////////////////////////////////////////////////////////
void BSTree::count()
{
	int tot = TotCount;      // holds number of distinct letters (# of nodes in tree)
	int let = LetterCount;   // holds total number of characters in text

	cout << "Letter count = " << let << " Total count = " << tot << endl;
}

// The InsertNode method is a recursive private method that will be passed
// a pointer (root initially) and a character to be added to the tree.  If the 
// character already exists in the tree, counts are updated, but no new node is 
// inserted.  If the character does not already exist in the tree, a new node is 
//  created and appropriately linked in to the correct position.
///////////////////////////////////////////////////////////////////////////////
void BSTree::InsertNode(Node * &ptr, char x)
{
	if (ptr != NULL && ptr->data == x)
	{
		ptr->count++;
		TotCount++;
	}
	else if (ptr == NULL)  // ptr points to NULL insertion position
	{
		ptr = new Node;
		ptr->data = x;
		ptr->count = 1;
		ptr->left = NULL;
		ptr->right = NULL;
		LetterCount++;
		TotCount++;
	}
	else if (x <= ptr->data)			// node should be inserted in left subtree
		InsertNode(ptr->left, x);
	else								// node should be inserted in right subtree
		InsertNode(ptr->right, x);
}


// The Insert method is a public method that calls InsertNode.
////////////////////////////////////////////////////////////////
void BSTree::Insert(char x)
{
	InsertNode(root, x);

}

// The Del method is a non-recursive private method that is passed the
// parent pointer of the node to be deleted.  This method must determine
// how many children the node has and make the proper deletion accordingly.
///////////////////////////////////////////////////////////////////////////
void BSTree::Del(Node * &ptr)
{
	if (ptr != NULL) //If the tree is not empty
	{
		Node *temp = ptr;
		char smallestInRightSubTree = ptr->data;

		//CASE 1: The node has no children
		if (ptr->left == NULL && ptr->right == NULL)
		{
			ptr = NULL;
			delete temp;
		}
		//CASE 2: The node has 1 child 
			//node with only a left child
		else if (ptr->left != NULL && ptr->right == NULL)
		{
			ptr = ptr->left;
			delete temp;
		}
			//node with only a right child
		else if (ptr->right != NULL && ptr->left == NULL)
		{
			ptr = ptr->right;
			delete temp;
		}
		//CASE 3: The node has 2 children
		else //(ptr->right != NULL && ptr->left != NULL)
		{
			smallestInRightSubTree = findSmallestInRightSubTree(ptr->right);
			ptr->data = smallestInRightSubTree;
			//Del()
			//delete the node that was swapped
		}
	}
	else
		cout << "The tree is empty \n";
}

// The findSmallestInRightSubTree method is called when the node being
// deleted has two children, it finds the smallest value in the right
// subtree of that node
//////////////////////////////////////////////////////////////////////
char BSTree::findSmallestInRightSubTree(Node* subroot)
{
	char smallest = subroot->data;
	Node* temp = subroot;
	while (temp->left != NULL)
	{
		if (temp->data < smallest)
		{
			smallest = temp->data;
		}
		findSmallestInRightSubTree(temp->left);
	}
	//Del(temp);     //<---------<<
	return smallest;
}


// The PruneTreeNodes method is a recursive private method that is passed a
// pointer (root initially) and traverses the tree to find the node to be 
// deleted.  If the node is found, the pointer to the node (parent's pointer)
// is passed to the Del method above.
/////////////////////////////////////////////////////////////////////////////
void BSTree::PruneTreeNodes(Node *&ptr, int avg)
{
	if (ptr)
	{
		PruneTreeNodes(ptr->left, avg);
		PruneTreeNodes(ptr->right, avg);
		if (ptr->count < avg)
		{
			cout << "\n Deleting: " << ptr->data;
			Del(ptr);
		}
	}
	/*else
		cout << "\n The tree is empty \n";*/
}

// The PruneTree method is a non-recursive public method that calculates
// the average character count.  It then calls the private method
// PruneTreeNodes above, passing it the root and the average.
////////////////////////////////////////////////////////////////////////////
void BSTree::PruneTree()
{
	int average = TotCount / LetterCount;
	//cout << "\n The average is " << average;
	PruneTreeNodes(root, average);
}

// The showPostOrder method is a non-recursive public method that passes
// the root point to the displayPostOrder method
/////////////////////////////////////////////////////////////////////////
void BSTree::showPostOrder()
{
	displayPostOrder(root);
}

// The displayPostOrder method is a recursive private mothod that 
// displays the post order traversal of the tree
/////////////////////////////////////////////////////////////////
void BSTree::displayPostOrder(Node *root)
{
	if (root)
	{
		displayPostOrder(root->left);
		displayPostOrder(root->right);
		cout << root->data << " ";
	}
}

// Credit to:  Terry Griffin
// Method to help create GraphViz code so the expression tree can 
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Receives a node pointer to root and performs a simple recursive 
// tree traversal.
//////////////////////////////////////////////////////////////////////
void BSTree::GraphVizGetIds(Node *nodePtr, ofstream &VizOut){
	if (nodePtr){
		GraphVizGetIds(nodePtr->left, VizOut);
		VizOut << "node" << nodePtr->data << "[label=\"" << nodePtr->data;
		VizOut << " (" << nodePtr->count << ")\"]" << endl;
		GraphVizGetIds(nodePtr->right, VizOut);
	}
}

// Credit to:  Terry Griffin
// This method is partnered with the above method, but on this pass it 
// writes out the actual data from each node.
//////////////////////////////////////////////////////////////////////
void BSTree::GraphVizMakeConnections(Node *nodePtr, ofstream &VizOut){
	if (nodePtr){
		if (nodePtr->left)
			VizOut << "node" << nodePtr->data << "->" << "node" << nodePtr->left->data << endl;
		if (nodePtr->right)
			VizOut << "node" << nodePtr->data << "->" << "node" << nodePtr->right->data << endl;
		GraphVizMakeConnections(nodePtr->left, VizOut);
		GraphVizMakeConnections(nodePtr->right, VizOut);
	}
}

// Credit to:  Terry Griffin
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//////////////////////////////////////////////////////////////////////
void BSTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename.c_str());
	VizOut << "// Kem Andrew \n";
	VizOut << "// File created by C++ BST Project \n";
	VizOut << "digraph { \n";
	VizOut << "name[shape = box, label = \"Kem Andrew \\nBST Project \\nSpring 2015\"]; \n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "} \n";
	VizOut.close();
}


