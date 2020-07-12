#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class HashTable {
	class Node {
	public:
		int key;
		std::string value;
		Node* next;
		Node() { key = 0; value = "NULL"; next = nullptr; }
		Node(int _key, std::string _value) :key(_key), value(_value) {
			next = nullptr;
		}
	};
	Node* myHashTable[100];
	Node* iter;
	int hashFunc(int key) {
		return key % 100;
	}
public:
	HashTable() {
		for (int i = 0; i < 100; i++) {
			myHashTable[i] = nullptr;
		}
		iter = nullptr;
	}
	void insertData(int _key, std::string _value) {
		int idx = hashFunc(_key);
		if (myHashTable[idx] == nullptr) { //충돌없음
			myHashTable[idx] = new Node(_key, _value);
		}
		else {
			iter = myHashTable[idx];
			while (iter->next != nullptr) {
				iter = iter->next;
			}
			iter->next = new Node(_key, _value);
		}
	}
	void printTable() {
		for (int i = 0; i < 100; i++) {
			if (myHashTable[i] != nullptr) {
				iter = myHashTable[i];
				while(iter != nullptr) {
					std::cout << "\n=========================================\n";
					std::cout << "index [" << i << "] " << "student number : " << iter->key << " value: " << iter->value << std::endl;
					std::cout << "\n=========================================\n";
					iter = iter->next;
				}
			}
		}
	}

};