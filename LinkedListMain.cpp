#include <iostream>
#include "LinkedList.h"
#include "ListData.h"


int enterInt() {
	int a;
	std::cin >> a;
	std::cin.clear();
	return a;
}
std::string enterString() {
	std::string s;
	std::getline(std::cin, s);
	std::cin.clear();
	return s;
}
ListData inputdata() {
	std::cout << "name: ";
	std::string name = enterString();
	std::cout << "desc: ";
	std::string desc = enterString();
	ListData ret(name,desc);
	return ret;
}

int main() {
	ListData plate("","");
	LinkedList* mylist = new LinkedList();
	int choice = 0;
	while (1) {
		std::cout << "\tVIP List\nchoose one\n\n\t1. add\t2.read\t3. delete first data\t\t0.quit\n\n=====================================\n\n";
		choice = enterInt();
		switch (choice)
		{
		case 1:
			getchar();
			plate = inputdata();
			mylist->insert(plate);
			break;
		case 2:
			mylist->read();
			break;
		case 3:
			mylist->del();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}