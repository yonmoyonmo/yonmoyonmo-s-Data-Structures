#include <iostream>
#include "ListData.h"
#include "Myqueue.h"
#include "MyStack.h"
#include "LinkedList.h"
#include <ctime>
#include <cstdlib>


/*
���ϴ� �ķα׷��� ������
1. ����Ʈ�� �����
2. ����Ʈ�� ���ÿ� �״´�
3. ������ ť�� �״´�
������
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