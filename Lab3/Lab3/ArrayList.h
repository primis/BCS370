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
* 10/25/2017, By Nicholas Sargente, Modified for BCS lab 3
******************************************************/
//This is the header guide.
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <string>
using namespace std;
namespace farmingdale_sargnj{
	const int MAX_LENGTH = 20000;

	template <class ItemType>
	class ArrayList {
	private:
		int capacity;
		int length;
		ItemType * data;
		int currentPos;

	public:
		~ArrayList();
		ArrayList(int n = MAX_LENGTH);
		ArrayList(const ArrayList<ItemType> &);
		ArrayList & operator=(const ArrayList<ItemType> &);
		void MakeEmpty();
		bool IsFull() const;
		int  LengthIs() const;
		int  CapacityIs() const;
		void RetrieveItem(ItemType &, bool&);
		void InsertItem(ItemType);
		void DeleteItem(ItemType);
		void ResetList();
		bool IsLastItem();
		void GetNextItem(ItemType&);
	};

	template<class ItemType>
	void ArrayList<ItemType>::MakeEmpty() {
		length = 0;
	}
	
	template<class ItemType>
	bool ArrayList<ItemType>::IsFull() const {
		return length == capacity;
	}
	
	template<class ItemType>
	int ArrayList<ItemType>::LengthIs() const {
		return length;
	}

	template<class ItemType>
	int ArrayList<ItemType>::CapacityIs() const {
		return capacity;
	}
	
	template<class ItemType>
	void ArrayList<ItemType>::RetrieveItem(ItemType & item, bool& found) {
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
	
	template<class ItemType>
	void ArrayList<ItemType>::InsertItem(ItemType item) {
		//this is not right. Who is responsible for checking
		//if the list is full?
		//if (length == capacity) {
		//	cerr << "adding new record failed! too many records!";
		//	return;
		//}
		data[length++] = item;
	}

	template<class ItemType>
	void ArrayList<ItemType>::DeleteItem(ItemType item) {
		int location = 0;
		while (!(item == data[location]))
			location++;
		data[location] = data[length - 1];
		length--;

	}

	template<class ItemType>
	void ArrayList<ItemType>::ResetList() {
		currentPos = -1;
	}
	
	template<class ItemType>
	bool ArrayList<ItemType>::IsLastItem() {
		return (currentPos == length - 1);
	}
	
	template<class ItemType>
	void ArrayList<ItemType>::GetNextItem(ItemType& item) {
		currentPos++;
		item = data[currentPos];
	}

	template<class ItemType>
	ArrayList<ItemType>::~ArrayList() {
		delete[] data;
	}

	template<class ItemType>
	ArrayList<ItemType>::ArrayList(int n) {
		capacity = n;
		length = 0;
		data = new ItemType[n];
		assert(data != NULL);
	}

	template<class ItemType>
	ArrayList<ItemType>::ArrayList(const ArrayList<ItemType> & list) {
		capacity = list.capacity;
		length = list.length;
		currentPos = list.currentPos;
		if (capacity)
			data = new ItemType[capacity];
		for (int i = 0; i < length; i++)
			data[i] = list.data[i];
		return;
	}

	template<class ItemType>
	ArrayList<ItemType> & ArrayList<ItemType>::operator=(const ArrayList<ItemType> & right) {
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
			data = new ItemType[capacity];
		for (int i = 0; i < length; i++)
			data[i] = right.data[i];
		return *this;
	}

}
#endif
