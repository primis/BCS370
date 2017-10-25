/******************************************************
* File: ArrayList.h
*
* This is the header file (record.h) for record.cpp
*
* Change Log:
* 12/02/2016, By Jun Yuan, created for BCS120
* 01/05/2017, By Jun Yuan, modified for BCS370
* 02/11/2017, By Jun Yuan, modified for BCS370 lab2
* 02/18/2017, By Jun Yuan, modified for BCS370 lab3
* 09/26/2017, By Jun Yuan, modified for BCS370 lab2
******************************************************/
//This is the header guide.
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "record.h"
#include <string>
using namespace std;
namespace farmingdale_yuanj{
	const int MAX_LENGTH = 20000;
	class ArrayList {
	private:
		int capacity;
		int length;
		record * data;
		int currentPos;

	public:
		~ArrayList();
		ArrayList(int n = MAX_LENGTH);
		ArrayList(const ArrayList &);
		ArrayList & operator=(const ArrayList &);
		void MakeEmpty();
		bool IsFull() const;
		int  LengthIs() const;
		int  CapacityIs() const;
		void RetrieveItem(record &, bool&);
		void InsertItem(record);
		void DeleteItem(record);
		void ResetList();
		bool IsLastItem();
		void GetNextItem(record&);
	};
}
#endif
