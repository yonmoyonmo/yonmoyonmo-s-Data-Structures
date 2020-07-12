#include <iostream>
#include "HashTable.h"

int stdnumGenerator(int year) {
	return year + rand() % 1000;
}

int main() {
	srand((unsigned int)time(NULL));
	int choice = 0;
	int key = 0;
	std::string value;
	HashTable* myHashTable = new HashTable();
	while (1) {
		std::cout << "=========================================\n";
		std::cout << "1. Insert Data\t2. Print Table\t3. exit\n";
		std::cout << "choose one : ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "enter admission year : ";
			std::cin >> key;
			std::cout << "enter description of anything : ";
			std::cin >> value;
			myHashTable->insertData(stdnumGenerator(key), value);
			break;
		case 2:
			myHashTable->printTable();
			break;
		case 3:
			exit(0);
			break;
		}
	}
}