#pragma once
#include "ListData.h"

class ArrayList
{
	ListData* arraylist;
	int listLength;
	int count =0;
public:
	ArrayList() {
		listLength = 200;
		arraylist = new ListData[listLength];
	}
	ArrayList(int _length, ListData data) {
		if (_length > 0) {
			listLength = _length;
			arraylist = new ListData[listLength];
			arraylist[0] = data;
			count++;
		}
		else {
			std::cout << "negative length -> shutdown";
			exit(1);
		}
	}
	ArrayList(int _length) {
		listLength = _length;
		arraylist = new ListData[listLength];
	}
	~ArrayList() {
		delete[] arraylist;
	}
	int getCount() {
		return count;
	}
	std::string getTitle(int i) { return arraylist[i].title; }
	std::string getDesc(int i) { return arraylist[i].desc; }
	int getLength() { return listLength; }
//-------------------------------------------------------
	void insert(ListData data);
	void read(int index);
	void printAll(void);
	void update(int index);
	void del(int index);
};

