#pragma once
template <typename T>
class MyQueue {

	template <typename T>
	class QNode {
	public:
		QNode<T>* next;
		T data;
		QNode() {
			next = nullptr;
		}
		QNode(T _data) {
			next = nullptr;
			data = _data;
		}
	};

	template <typename T>
	class Iterator {
	public:
		MyQueue::QNode<T>* front; //����Ÿ�� ������ ����
		MyQueue::QNode<T>* rear;//����Ÿ�� ������ ����
		Iterator() {
			front = nullptr;
			rear = nullptr;
		}
	};
	Iterator<T> iter;
public:
	MyQueue() {
	}
	void enqueue(T data) {
		if (iter.front == nullptr && iter.rear == nullptr) { //�������
			iter.front = new QNode<T>(data);
			iter.rear = iter.front;
		}
		else {
			iter.front->next = new QNode<T>(data);
			iter.front = iter.front->next;
		}
	}
	T dequeue() {
		if (iter.front == nullptr && iter.rear == nullptr) { //�������
			std::cout << "EMPTY QUEUE\n";
		}
		else if(iter.rear!=nullptr) {
			QNode<T>* tmp = iter.rear;
			T ttmp = tmp->data;
			iter.rear = iter.rear->next;
			delete tmp;
			return ttmp;
		}else std::cout << "EMPTY QUEUE\n";
	}
	T peek() {
		if (iter.front == nullptr && iter.rear == nullptr) { //�������
			std::cout << "EMPTY QUEUE\n";
		}
		else if (iter.rear != nullptr) {
			return iter.rear->data;
		}
		else std::cout << "EMPTY QUEUE\n";
	}

};