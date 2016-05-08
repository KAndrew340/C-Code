#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "FEL.h"

using namespace std;


int main()
{
	ifstream names("data.txt");

	string command;
	string Evtype;
	string Evdescription;
	int Evtime;

	FEL test, test2;

	vector <string> myinfo;

	if (names.is_open())
	{
		while (!names.fail())
		{
			getline(names, command, ',');
			myinfo.push_back(command);
			
		}

		/*for (int i = 0; i < myinfo.size(); i++)
		{


			cout << endl << myinfo.at(i) << endl;
		}*/
		//cout << endl << myinfo.size() << endl;

		//cout << myinfo.at(0) << myinfo.at(1) << stoi(myinfo.at(2));

		test.insertPriority(myinfo.at(1), stoi(myinfo.at(2)), myinfo.at(3));
		test.insertPriority(myinfo.at(5), stoi(myinfo.at(6)), myinfo.at(7));
		test.printevent();
		cout << endl;
		//test.deleteRecord(myinfo.at(5), stoi(myinfo.at(6)), myinfo.at(7));
		//test.getnext();
		cout << endl << "length: " << test.length() << endl;
		test.peek();
		test.printevent();
		
	}
	names.close();

	//void insertPriority(string etype, string edecsrip, int etime);

	system("pause");
	return 0;
}