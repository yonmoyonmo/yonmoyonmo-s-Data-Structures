#pragma once
#include <string>

class MyStack
{
	class StackNode {
	public:
		StackNode* bottom;
		std::string data;
		StackNode() {
			bottom = nullptr;
			data = "null";
		}
		StackNode(std::string _data) :data(_data) {
			bottom = nullptr;
		}
	};
	class Iterator {
	public:
		MyStack::StackNode* top;
		Iterator() {
			top = nullptr;
		}
	};
	StackNode* lowest;
	Iterator iter;
public:
	MyStack() {
		lowest = new StackNode("Bottom of this ground");
		iter.top = lowest;
	}
	void push(std::string data) {
		StackNode* tmp = iter.top;
		iter.top = new StackNode(data);
		iter.top->bottom = tmp;
	}
	void peek() {
		std::cout<<"top of this stack: "<<iter.top->data<<"\n";
	}
	std::string pop() {
		if (iter.top->bottom == nullptr) {
			return iter.top->data;
		}
		std::string tmp = iter.top->data;
		StackNode* temp = iter.top;
		iter.top = temp->bottom;
		delete temp;
		return tmp;
	}
	

};