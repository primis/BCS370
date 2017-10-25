/******************************************************
* File: data_management.cpp
*
* We are redesigning and rewriting this application based
* on object-oriented principles.
*
* Change Log:
* 12/02/2016, By Jun Yuan, created for BCS120
* 01/05/2017, By Jun Yuan, modified for BCS370
* 02/11/2017, By Jun Yuan, modified for BCS370 lab2
* 02/18/2017, By Jun Yuan, modified for BCS370 lab3
* 08/28/2017, By Jun Yuan, modified for BCS370 lab1
* 09/26/2017, By Jun Yuan, modified for BCS370 lab2
******************************************************/

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <iomanip>
#include "data_management.h"
using namespace std;
using namespace farmingdale_sargnj;

void data_management::displayAllRecords() {
	//we are going to traverse the list
	//through its iterator interface
	//to reset the cursor to -1
	list->ResetList();
	int i = 0;
	while (!list->IsLastItem()) {
		i++;
		record temp;
		list->GetNextItem(temp);
		cout << temp.getName() <<":" << temp.getCell()<< endl;
		if ((i + 1) % 10 == 0) {
			cout << "[press any key to continue, or press q/Q to quit]" << endl;
			char ch = cin.get();
			if (ch == 'q' || ch == 'Q') {
				return;
			}
		}
	}
	cout << "========the end of the records ==============" << endl;
}

void data_management::addRecord(string name, string cell) {
	if (list->IsFull()) {
		cerr << "Insert failed: array is full";
		return;
	}
	record target = { name, "" };
	bool found;
	list->RetrieveItem(target, found);
	if (found) {
		cerr << "Insert failed: the record is already there"
			<< endl;
	} else {
		list->InsertItem({ name, cell });

	}
}
void data_management::updateRecord(string name, string cell) {
	//To be implemented: how do you implement update using
	//the interface of the arraylist?
}
void data_management::deleteRecord(string name) {
	//run the search first
	record target = { name, "" };
	bool found;
	list->RetrieveItem(target, found);
	if (found) {
		list->DeleteItem(target);
	} else {
		cerr << "search failed: the record is not found"
			<< endl;
	}
}
void data_management::searchRecord(string name) {
	record target = { name, "" };
	bool found;
	list->RetrieveItem(target, found);
	if (found) {
		cout <<target.getName() << ":" << target.getCell() << endl;
	}
	else {
		cerr << "search failed: the record is not found"
			<< endl;
	}
}
void data_management::displayInfo() {
	cout << "+-------------------------------------------+" << endl;
	cout << "|                                           |" << endl;
	cout << "| Welcome to my little data management      |" << endl;
	cout << "|                                           |" << endl;
	cout << "| You have used ["
		<< fixed << setprecision(2)
		<< static_cast<double> (list->LengthIs()) * 100 / list->CapacityIs()
		<< "%] of the capacity    |"
		<< endl;
	cout << "|  BCS370 Farmingdale State College         |" << endl;
	cout << "+-------------------------------------------+" << endl;

}
void data_management::displayAbout() {
	cout << "+-------------------------------------------+" << endl;
	cout << "|                                           |" << endl;
	cout << "| Welcome to my little data management!     |" << endl;
	cout << "|                                           |" << endl;
	cout << "|  Author:                                  |" << endl;
	cout << "|  BCS370 Farmingdale State College         |" << endl;
	cout << "+-------------------------------------------+" << endl;
}

data_management::data_management(string path) {
	ifstream fin(path);

	if (!fin.is_open()) {
		cerr << "data file error\n";
		throw "File open failed";
	}
	string temp;
	int i = 0;
	list = new ArrayList<record>();
	while (getline(fin, temp)) {
		if (list->IsFull()) {
		//yes the caller is responsible for checking
		//if the list is full
			cerr << "The list is full!" << endl;
			break ;
		}
		int delim = temp.find(",");
		string name = temp.substr(0, delim);
		string cell = temp.substr(delim + 1);
		list->InsertItem({name, cell});
	}
	fin.close();
}
data_management::~data_management() {
	delete list;
}

void data_management::saveAllPendingRecords(string path) {
	ofstream fout(path);
	if (!fout.is_open()) {
		cerr << "file open failed" << endl;
	}
	list->ResetList();
	while (list->IsLastItem()) {
		record record;
		list->GetNextItem(record);
		fout << record.getName() << "," << record.getCell() << endl;
	}
	fout.close();
}

data_management & data_management::operator=(const data_management & right) {
	return *this;
}

data_management::data_management(const data_management & dm) {
	list = new ArrayList<record>(*dm.list);
	//is this right?
}