/******************************************************
* File: record.h
*
* This is the header file (record.h) for record.cpp
*
* Change Log:
* 12/02/2016, By Jun Yuan, created for BCS120
* 01/05/2017, By Jun Yuan, modified for BCS370
* 02/11/2017, By Jun Yuan, modified for BCS370 lab2
* 02/18/2017, By Jun Yuan, modified for BCS370 lab3
* 08/28/2017, By Jun Yuan, modified for BCS370 lab1
* 09/26/2017, By Jun Yuan, modified for BCS370 lab2
******************************************************/
//This is the header guide.
#ifndef RECORD_H
#define RECORD_H
#include <string>
using namespace std;
namespace farmingdale_yuanj {
	class record {
	private:
		//storing the name of the user
		string m_name;
		//storing the cell phone number of the user
		string m_cell;
	public:
		record(string, string);
		record();
		//setters
		void setName(string name);
		void setCell(string cell);
		//getters
		string getName(void);
		string getCell(void);
		//overload ==
		bool operator== (const record & right);

		//overload = 
		record & operator= (const record & right);

	};
}
#endif
