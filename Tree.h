#pragma once
#include <iostream>

class BinaryTree {
private:
	std::string data;
public:
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree() {
		data = "NULL";
		left = nullptr;
		right = nullptr;
	}
	BinaryTree(std::string _data) {
		data = _data;
		left = nullptr;
		right = nullptr;
	}
	std::string getData() {
		return data;
	}
	BinaryTree* makeNewNode(std::string data) {
		return new BinaryTree(data);
	}
	void leftLinker(BinaryTree* parent, BinaryTree* child) {
		parent->left = child;
	}
	void rightLinker(BinaryTree* parent, BinaryTree* child) {
		parent->right = child;
	}
	
	void postorder(BinaryTree* tree) {
		if (tree == nullptr) return;
		postorder(tree->left);
		postorder(tree->right);
		std::cout << tree->data << std::endl;
	}
	void deleteNodes(BinaryTree* tree) {
		if (tree == nullptr) return;
		deleteNodes(tree->left);
		deleteNodes(tree->right);
		delete(tree);
		std::cout << "»èÁ¦µÊ\n";
	}
};