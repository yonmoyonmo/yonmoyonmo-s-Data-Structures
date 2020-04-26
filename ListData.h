#pragma once
#include <string>
#include <iostream>
#include <Windows.h>


class ListData {
public:
	std::string title;
	std::string desc;
	ListData();
	ListData(std::string _title, std::string _desc);
	
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


