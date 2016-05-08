#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;


class FEL
{
private:
	struct Event{
		string Evtype;
		string Evdescription;
		int Evtime;
		Event* next;

		//struct constructor
		/*Event(string etype, int etime, string edecsrip, Event* next1 = NULL)
		{
			Evtype = etype;
			Evdescription = edecsrip;
			Evtime = etime;
			next = next1;
		}*/
	};

	Event* head;
	Event* current;
	Event* prev;

public:
	FEL();
	~FEL();
	void getnext();
	void insertPriority(string etype, int etime, string edecsrip);
	void deleteRecord(string etype, int etime, string edecsrip);
	int length();
	string peek();
	void printevent();
};

