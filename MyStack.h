#pragma once
#include <string>

template <typename T>
class MyStack
{
	template <typename T>
	class StackNode {
	public:
		StackNode<T>* bottom;
		T data;
		StackNode() {
			bottom = nullptr;
		}
		StackNode(T _data) :data(_data) {
			bottom = nullptr;
		}
	};
	template <typename T>
	class Iterator {
	public:
		MyStack::StackNode<T>* top;
		Iterator() {
			top = nullptr;
		}
	};
	StackNode<T>* lowest;
	Iterator<T> iter;
public:
	MyStack() {
		lowest = new StackNode<T>();
		iter.top = lowest;
	}
	void push(T data) {
		StackNode<T>* tmp = iter.top;
		iter.top = new StackNode<T>(data);
		iter.top->bottom = tmp;
	}
	void peek() {
		std::cout<<"top of this stack: "<<iter.top->data<<"\n";
	}
	T pop() {
		if (iter.top->bottom == nullptr) {
			return iter.top->data;
		}
		T tmp = iter.top->data;
		StackNode<T>* temp = iter.top;
		iter.top = temp->bottom;
		delete temp;
		return tmp;
	}
};