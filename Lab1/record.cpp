/******************************************************
* File: record.cpp
*
* Implementation of record class
*
* Change Log:
* 12/02/2016, By Jun Yuan, created for BCS120
* 01/05/2017, By Jun Yuan, modified for BCS370
* 02/11/2017, By Jun Yuan, modified for BCS370 lab2
* 02/18/2017, By Jun Yuan, modified for BCS370 lab3
* 08/28/2017, By Jun Yuan, modified for BCS370 lab1
******************************************************/
#include "record.h";
using namespace std;
using namespace farmingdale_yuanj;
record::record(string name, string cell) {
	m_name = name;
	m_cell = cell;
}
record::record() {
	m_name = "";
	m_cell = "";
}
string record::getName() {
	return m_name;
}

string record::getCell() {
	return m_cell;
}

void record::setName(string name) {
	//verify if the name conforms to the format
	m_name = name;
}

void record::setCell(string cell) {
	//verify if the name conforms to the format
	m_cell = cell;
}