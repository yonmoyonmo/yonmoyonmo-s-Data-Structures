#include <iostream>
#include <string>
#include "Tree.h"

int main() {
	BinaryTree* root = new BinaryTree("Root");
	BinaryTree* nodes[5];
	for (int i = 0; i < 5; i++) {
		std::string temp = std::to_string(i);
		nodes[i] = root->makeNewNode("Node Number: "+temp);
	}
	root->leftLinker(root, nodes[0]);
	root->rightLinker(root, nodes[1]);
	root->leftLinker(root->left, nodes[2]);
	root->rightLinker(root->left, nodes[3]);
	root->leftLinker(root->right, nodes[4]);
	root->postorder(root);
	root->deleteNodes(root);

	return 0;
	
}