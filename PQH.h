#pragma once

#include <iostream>

class IntPriorityQueue { //ũ�� �켱���� ��������
	int heap[100];
	int Qsize;
	int getLeftChildIndex(int parentIndex) { return parentIndex * 2; }
	int getRightChildIndex(int parentIndex) { return parentIndex * 2 + 1; }
	int getParentIndex(int childIndex) { return (int)childIndex / 2; }
	int whichIsHigherChildIndex(int parentIndex) {
		int L = heap[getLeftChildIndex(parentIndex)];
		int R = heap[getRightChildIndex(parentIndex)];
		int Ldex = getLeftChildIndex(parentIndex);
		int Rdex = getRightChildIndex(parentIndex);
		return L > R ? Ldex : Rdex;
	}

public: //����ϰ� �����̴� ��ť�� ��ť ���̴�
	IntPriorityQueue() {
		for (int i = 0; i < 100; i++) {
			heap[i] = 0;
		}
		Qsize = 0;
	}
	//��ū�� �켱���� ��������
	void enqueue(int priority) {
		if (Qsize <= 0) {
			heap[1] = priority;
			Qsize++;
			return;
		}//queue �� ��������� �� ����
		Qsize++;
		heap[Qsize] = priority;
		int parentIndex = 0;
		int newItemIndex = Qsize;
		while (newItemIndex != 1) {
			parentIndex = getParentIndex(newItemIndex);
			if (heap[newItemIndex] > heap[parentIndex]) {
				heap[newItemIndex] = heap[parentIndex];
				heap[parentIndex] = priority;
				newItemIndex = parentIndex;
			}
			else break;
		}//queue�� �Ⱥ�������� �߰��ȳ� �ڸ��� ã����
	}
	int dequeue() {
		int retData = heap[1];// root�� �����͸� �ϴ� ������.
		heap[1] = heap[Qsize]; // ���� �ؿ��ִ� ���� root�� ����
		Qsize--;
		int augmentedItem = heap[1];
		int augmentedIndex = 1;
		while (augmentedIndex != Qsize) {
			int higherChild = whichIsHigherChildIndex(augmentedIndex);
			if (heap[augmentedIndex] < heap[higherChild]) {
				heap[augmentedIndex] = heap[higherChild];
				heap[higherChild] = augmentedItem;
				augmentedIndex = higherChild;
			}
			else break;
		}
		return retData;
	}
};