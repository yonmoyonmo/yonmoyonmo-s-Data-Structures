#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctime>
#include <cstdlib>

int enterInt() {
	int a;
	std::cin >> a;
	std::cin.clear();
	return a;
}
std::string dirtOrGold(int r) {
	std::string arr[3] = { "dirt", "gold", "dirt" };
	return arr[r];
}
void set(MyStack<std::string>& ground) {
	for (int i = 0; i < 100; i++) {
		int r = rand() % 3;
		ground.push(dirtOrGold(r));
	}
	std::cout << "stacked 100 layers\n\n---------------------\n";
}
int main() {
	srand((unsigned int)time(NULL));
	MyStack<std::string> ground;
	int choice = 0;
	int goldCnt = 0;
	std::string bucket = "null";
	std::cout << "Gold Digging____________________________\n";
	while (1) {
		std::cout <<"1. set a stack\n2. peek\n3. dig\n0. quit\n\n===================================";
		choice = enterInt();
		switch (choice) {
		case 1:
			set(ground);
			break;
		case 2:
			ground.peek();
			break;
		case 3:
			system("cls");
			bucket = ground.pop();
			if (bucket == "gold") {
				goldCnt++;
			}
			std::cout << "digged: " << bucket<< "\nGold: "<<goldCnt<<"\n\n------------------";
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