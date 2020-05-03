#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
class ListData {
public:
	std::string title;
	std::string desc;
	ListData() { title = "null"; desc = "null"; }
	ListData(std::string _title, std::string _desc) :title(_title), desc(_desc) {}
	
	friend std::ostream& operator<<(std::ostream& os, const ListData& ref);
	ListData& operator=(const ListData& right) {
		try {
			title = right.title;
			desc = right.desc;
		}
		catch (...) {
			std::cout << "last data over the limit of your list program shutdown";
			Sleep(5000);
			exit(1);
		}
		return *this;
	}
};


