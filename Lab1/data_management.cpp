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
******************************************************/

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <iomanip>
#include "data_management.h"
using namespace std;
using namespace farmingdale_yuanj;

void data_management::displayAllRecords() {
}
void data_management::addRecord(string name, string cell) {
}
void data_management::updateRecord(string name, string cell) {
}
void data_management::deleteRecord(string name) {
}
void data_management::searchRecord(string name) {
}
void data_management::displayInfo() {
	cout << "+-------------------------------------------+" << endl;
	cout << "|                                           |" << endl;
	cout << "| Welcome to my little data management      |" << endl;
	cout << "|                                           |" << endl;
	cout << "| You have used ["
		<< fixed << setprecision(2)
		<< static_cast<double> (m_n_record) * 100 / m_capacity
		<< "%] of the capacity    |"
		<< endl;
	cout << "| You have expanded the array " << m_resize_counter << " times       |"
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
	m_records = new record[INIT_MAX_RECORDS];
	while (getline(fin, temp)) {
		int delim = temp.find(",");
		string name = temp.substr(0, delim);
		string cell = temp.substr(delim + 1);
		if (i == m_capacity) {
			_resizeStorage();
		}
		m_records[i].setName(name);
		m_records[i].setCell(cell);
		i++;
	}
	m_n_record = i;
	fin.close();
}
data_management::~data_management() {
}

void data_management::saveAllPendingRecords(string path) {
	ofstream fout(path);
	if (!fout.is_open()) {
		cerr << "file open failed" << endl;
	}
	for (int i = 0; i < m_n_record; i++) {
		fout << m_records[i].getName() << "," << m_records[i].getCell()<< endl;
	}
	fout.close();
}

void data_management::_resizeStorage() {
}

data_management & data_management::operator=(const data_management & right) {
	return *this;
}

data_management::data_management(const data_management & dm) {

}