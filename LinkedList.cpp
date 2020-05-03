#pragma once
#include "LinkedList.h"

void LinkedList::insert(ListData _data)
{
	if (head->next == nullptr) {//�����Ͱ� 1���� ����
		head->next = new ListDataNode(_data);
		head->next->prev = head; 
		head->next->next = head;
		head->prev = head->next;
		iter.first = head->next;
		iter.current = head->next;
	}
	else {//�����Ͱ� 1���̻�����
		head->next = new ListDataNode(_data);
		iter.first->prev = head->next;
		head->next->next = iter.first;
		head->next->prev = head;
		iter.first = head->next;
		iter.current = iter.first;
	}
	
}

void LinkedList::read()
{
	system("cls");
	while (1) {
		char choice = ' ';
		std::cout << "read mode\n\n==============\ns: current data\td: next data\ta:previous data\tq: quit\n\n";
		std::cin >> choice;
		std::cin.clear();
		switch (choice) {
		case 's':
			std::cout << "name: " << iter.current->data.title << "\n";
			std::cout << "description: " << iter.current->data.desc << "\n\n========================================";
			break;
		case 'd':
			iter.mvNext();
			std::cout << "name: " << iter.current->data.title << "\n";
			std::cout << "description: " << iter.current->data.desc << "\n\n========================================";
			break;
		case 'a':
			iter.mvPrev();
			std::cout << "name: " << iter.current->data.title << "\n";
			std::cout << "description: " << iter.current->data.desc << "\n\n========================================";
			break;
		case 'q':
			return;
		default:
			break;
		}
	}

}

void LinkedList::del()
{
	if (head->next == nullptr) {//�����Ͱ� 1���� ����
		return;
	}
	else {
		iter.current = iter.first;
		head->next = iter.first->next;
		iter.first->next->prev = head;
		iter.first = head->next;
		delete iter.current;
		iter.current = iter.first;
	}
}
