/******************************************************
* File: ArrayList.cpp
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

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <iomanip>
#include "ArrayList.h"
using namespace std;
using namespace farmingdale_yuanj;
void ArrayList::MakeEmpty() {
	length = 0;
}
bool ArrayList::IsFull() const{
	return length == capacity;
}
int ArrayList::LengthIs() const {
	return length;
}
int ArrayList::CapacityIs() const {
	return capacity;
}
void ArrayList::RetrieveItem(record & item, bool& found) {
	int location = 0;
	found = false;
	while (location < length && !found) {
		if (item == data[location]) {
			item = data[location];
			found = true;
		}
		location++;
	}
}
void ArrayList::InsertItem(record item) {
	//this is not right. Who is responsible for checking
	//if the list is full?
	//if (length == capacity) {
	//	cerr << "adding new record failed! too many records!";
	//	return;
	//}
	data[length++] = item;
}

void ArrayList::DeleteItem(record item) {
	int location = 0;
	while (!(item == data[location]))
		location++;
	data[location] = data[length - 1];
	length--;

}

void ArrayList::ResetList() {
	currentPos = -1;
}
bool ArrayList::IsLastItem() {
	return (currentPos == length - 1);
}
void ArrayList::GetNextItem(record& item) {
	currentPos ++;
	item = data[currentPos];
}

ArrayList::~ArrayList(){
	delete [] data;
}

ArrayList::ArrayList(int n) {
	capacity = n;
	length = 0;
	data = new record[n];
	assert(data != NULL);
}

ArrayList::ArrayList(const ArrayList & list) {
	capacity = list.capacity;
	length = list.length;
	currentPos = list.currentPos;
	if (capacity)
		data = new record[capacity];
	for (int i = 0; i < length; i++)
		data[i] = list.data[i];
	return;
}

ArrayList & ArrayList::operator=(const ArrayList & right) {
	if (this == &right)
		return *this;
	
	if (capacity > 0) {
		assert(data != NULL);
		delete[] data;
	}

	capacity = right.capacity;
	length = right.length;
	currentPos = right.currentPos;
	if (capacity)
		data = new record[capacity];
	for (int i = 0; i < length; i++)
		data[i] = right.data[i];
	return *this;
}
