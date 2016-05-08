#include "FEL.h"


FEL::FEL()
{
	head = NULL;
	current = head;
}


FEL::~FEL()
{
}

// Remove record at the top of the list
void FEL::getnext()
{
	current = head;
	head = head->next;
	delete current;
	cout << endl << "Record deleted!" << endl;
}

void FEL::insertPriority(string etype, int etime, string edecsrip)
{
	current = head;
	prev = head;

	while (current != NULL)
	{
		prev = current;
		current = current->next;
	}
	
	if (current == head && head == NULL)
	{
		current = new Event;
		current->Evtype = etype;
		current->Evtime = etime;
		current->Evdescription = edecsrip;
		current->next = NULL;
		head = current;
	}
	else
	{
		prev->next = new Event;
		prev = prev->next;
		prev->Evtype = etype;
		prev->Evtime = etime;
		prev->Evdescription = edecsrip;
		prev->next = NULL;
	}
}

void FEL::deleteRecord(string etype, int etime, string edecsrip)
{
	current = head;
	prev = head;

	if (head == NULL)
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		while (current->Evtype != etype && current->Evdescription != edecsrip && current->Evtime != etime && current->next != NULL)
		{
			prev = current;
			current = current->next;
		}

		if (current == head)
		{
			head = head->next;
			delete current;
		}
		else if (current == NULL)
		{
			cout << endl << "This event is not in the list." << endl;
		}
		else
		{
			prev->next = current->next;
			delete current;
			cout << endl << "item deleted" << endl;
		}
	}
}

int FEL::length()
{
	int length = 0;
	current = head;
	prev = head;

	while (current != NULL)
	{
		current = current->next;
		length++;
	}

	return length;
}

string FEL::peek()
{
	string x;
	x = head->Evtime;
	return head->Evtype, x, head->Evdescription;
}

void FEL::printevent()
{
	current = head;
	prev = head;

	while (current != NULL)
	{
		cout << " " << current->Evtype << " " << current->Evtime << " " << current->Evdescription << endl;
		current = current->next;
	}
	//if (current == NULL)
		//cout << endl << "No items in the list." << endl;
}