/******************************************************
* File: data_management.h
*
* This is the header file for contact_management.cpp
*
* Change Log:
* 12/02/2016, By Jun Yuan, created for BCS120
* 01/05/2017, By Jun Yuan, modified for BCS370
* 02/11/2017, By Jun Yuan, modified for BCS370 lab2
* 02/18/2017, By Jun Yuan, modified for BCS370 lab3
* 08/28/2017, By Jun Yuan, modified for BCS370 lab1
* 09/26/2017, By Jun Yuan, modified for BCS370 lab2
******************************************************/
#ifndef DATA_MANAGEMENT_H
#define DATA_MANAGEMENT_H
#include <string>
#include "record.h"
#include "ArrayList.h"
using namespace std;
namespace farmingdale_sargnj {
	class data_management {
	private:
		ArrayList<record> * list;
	public:
		data_management(string);
		data_management(const data_management &);
		data_management & operator=(const data_management & right);
		~data_management();
		void displayAllRecords();
		void addRecord(string name, string cell);
		void updateRecord(string name, string cell);
		void deleteRecord(string name);
		void searchRecord(string name);
		void displayInfo();
		void displayAbout();
		void saveAllPendingRecords(string);
	};
}
#endif
