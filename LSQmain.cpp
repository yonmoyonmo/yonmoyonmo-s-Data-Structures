#include <iostream>
#include "ListData.h"
#include "Myqueue.h"
#include "MyStack.h"
#include "LinkedList.h"
#include <ctime>
#include <cstdlib>


/*
뭐하는 후로그램을 만들지
1. 리스트를 만든다
2. 리스트를 스택에 쌓는다
3. 스택을 큐에 쌓는다
귀찮다
*/
std::ostream& operator<<(std::ostream& out, const ListData& ref) {
	out << "title: " << ref.title << "\n" << "description: " << ref.desc << std::endl;
	return out;
}
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
	ListData ret(name, desc);
	return ret;
}

int main() {
	ListData a = inputdata();
	MyStack<ListData> stack;
	stack.push(a);
	MyQueue<MyStack<ListData>> queue;
	queue.enqueue(stack);
	std::cout << queue.dequeue().pop() << std::endl;
	return 0;
}