#pragma once

#include <iostream>

class IntPriorityQueue { //크면 우선순위 높은거임
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

public: //깔끔하게 손잡이는 인큐와 디큐 뿐이다
	IntPriorityQueue() {
		for (int i = 0; i < 100; i++) {
			heap[i] = 0;
		}
		Qsize = 0;
	}
	//더큰게 우선순위 높은거임
	void enqueue(int priority) {
		if (Qsize <= 0) {
			heap[1] = priority;
			Qsize++;
			return;
		}//queue 가 비어있으면 걍 넣음
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
		}//queue가 안비어있으면 추가된놈 자리를 찾아줌
	}
	int dequeue() {
		int retData = heap[1];// root의 데이터를 일단 빼놓음.
		heap[1] = heap[Qsize]; // 제일 밑에있는 놈을 root에 앉힘
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