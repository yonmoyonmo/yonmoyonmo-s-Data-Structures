#pragma once
#include <ctime>
#include <cstdlib>
#include "Airplane.h"

class MyQueue {
	class QNode {
	public:
		QNode* next;
		Airplane airplane;
		QNode() {
			next = nullptr;
		}
		QNode(Airplane _airplane) {
			next = nullptr;
			airplane = _airplane;
		}
	};
	class Iterator {
	public:
		MyQueue::QNode* front; //데이타가 들어오는 구멍
		MyQueue::QNode* rear;//데이타가 나가는 구멍
		Iterator() {
			front = nullptr;
			rear = nullptr;
		}
	};
	Iterator iter;
public:
	MyQueue() {
	}
	void enqueue(Airplane airplane) {
		if (iter.front == nullptr && iter.rear == nullptr) { //비어있음
			iter.front = new QNode(airplane);
			iter.rear = iter.front;
		}
		else {
			iter.front->next = new QNode(airplane);
			iter.front = iter.front->next;
		}
	}
	Airplane dequeue() {
		if (iter.front == nullptr && iter.rear == nullptr) { //비어있음
			std::cout << "EMPTY QUEUE\n";
		}
		else if(iter.rear!=nullptr) {
			QNode* tmp = iter.rear;
			Airplane ttmp = tmp->airplane;
			iter.rear = iter.rear->next;
			delete tmp;
			return ttmp;
		}else std::cout << "EMPTY QUEUE\n";
	}
	Airplane peek() {
		if (iter.front == nullptr && iter.rear == nullptr) { //비어있음
			std::cout << "EMPTY QUEUE\n";
		}
		else if (iter.rear != nullptr) {
			return iter.rear->airplane;
		}
		else std::cout << "EMPTY QUEUE\n";
	}

};