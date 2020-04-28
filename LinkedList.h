#pragma once
#include "ListData.h"

class LinkedList
{
private:
	class ListDataNode {
	public:
		ListDataNode* next;
		ListDataNode* prev;
		ListData data;
		ListDataNode() {
			next = nullptr;
			prev = nullptr;
		}
		ListDataNode(ListData _data):data(_data) {
			next = nullptr;
			prev = nullptr;
		}
	};
	class Iterator {
	public:
		LinkedList::ListDataNode* first;
		LinkedList::ListDataNode* current;
		Iterator() {
			first = nullptr;
			current = nullptr;
		}
		ListData& getData() {
			if (current == nullptr) {
				std::cout << "null" << std::endl;
			}else return current->data;
		}
		void mvNext() {
			if (current == nullptr) {
				std::cout << "null" << std::endl;
			}
			else {
				current = current->next;
			}
		}
		void mvPrev() {
			if (current == nullptr) {
				std::cout << "null" << std::endl;
			}
			else {
				current = current->prev;
			}
		}

	};
	ListDataNode* head;
	Iterator iter;

public:
	LinkedList() {
		head = new ListDataNode(ListData("head","start/end"));
		iter.first = head;
		iter.current = head;
	}
	~LinkedList() {
		delete head;
	}
//============================
	void insert(ListData _data);
	void read();
	void del();
};

