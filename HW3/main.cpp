/******************************************************
* File: main.cpp
*
* Driver file
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
#include <iomanip>
#include "data_management.h"
using namespace std;
using namespace farmingdale_yuanj;
void get_valid_option(int & n) {
	cin >> n;
	while (cin.fail() || n<1 || n>9) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Please enter a number from 1 to 8: ";
		cin >> n;
	}

}

int main() {
	int option;
	bool ends_loop = false;
	//load the data records from file to the records array.
	try {
		data_management dm("small_records.csv");
		do {
			cout << "+-------------------------------------------+" << endl;
			cout << "|                                           |" << endl;
			cout << "| Welcome to my little data management!     |" << endl;
			cout << "|                                           |" << endl;
			cout << "| 1- Display all data records               |" << endl;
			cout << "| 2- Add a data record                      |" << endl;
			cout << "| 3- Update a data record                   |" << endl;
			cout << "| 4- Delete a data record                   |" << endl;
			cout << "| 5- Search a data record                   |" << endl;
			cout << "| 6- Info                                   |" << endl;
			cout << "| 7- About                                  |" << endl;
			cout << "| 8- Abort                                  |" << endl;
			cout << "| 9- Save & Exit                            |" << endl;
			cout << "+-------------------------------------------+" << endl;

			cout << "\n Please enter your option:";
			get_valid_option(option);
			cin.ignore();

			switch (option) {
			case 1:
				dm.displayAllRecords();
				break;
			case 2: {
				string name, cell;
				cout << "Please enter the user name you want to add:";
				getline(cin, name);
				cout << "Please enter his/her cell:";
				getline(cin, cell);
				dm.addRecord(name, cell);
				break;
			}
			case 3: {
				string name, cell;
				cout << "Please enter the user name you want to edit:";
				getline(cin, name);
				cout << "Please enter the new cell:";
				getline(cin, cell);
				dm.updateRecord(name, cell);
				break;
			}
			case 4: {
				string name;
				cout << "\n Please input the name of the record you want to remove:";
				getline(cin, name);
				dm.deleteRecord(name);
				break;
			}
			case 5: {
				string name;
				cout << "\n Please input the name you want to search:";
				getline(cin, name);
				dm.searchRecord(name);
				break;
			}
			case 6:
				dm.displayInfo();
				break;
			case 7:
				dm.displayAbout();
				break;
			case 8:
				ends_loop = true;
				break;
			case 9:
				dm.saveAllPendingRecords("small_records.dat");
				ends_loop = true;
				break;
			default:
				return 1;//impossible
			}
			if (option != 8) {
				cout << "[press any key to continue]" << endl;
				cin.get();
				system("Cls");
			}
		} while (!ends_loop);
	}
	catch (string str) {
		cerr << str;
		return 1;
	}
}
