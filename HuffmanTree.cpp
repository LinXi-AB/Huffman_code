#include "HuffmanTree.h"
#include <iostream>

HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::~HuffmanTree()
{
	deleteTree(root);
}

void HuffmanTree::deleteTree(HuffmanTreeNode* root)
{
	if (root != nullptr) {
		deleteTree(root->getLeftChild());
		deleteTree(root->getRightChild());
		delete root;
	}
}

void HuffmanTree::createHuffmanTree(std::priority_queue<HuffmanTreeNode*, std::vector<HuffmanTreeNode*>, FrequencyCompare>& huffman_queue) {
	if (huffman_queue.empty())
		throw std::runtime_error("传入了空队列");

	// 如果字符串中只有一种字符
	if (huffman_queue.size() == 1) {
		root = new HuffmanTreeNode('\0', huffman_queue.top()->getFrequency());
		root->setLeftChild(huffman_queue.top());
		return;
	}

	while (huffman_queue.size() > 1) {
		HuffmanTreeNode* left_child = huffman_queue.top();
		huffman_queue.pop();
		HuffmanTreeNode* right_child = huffman_queue.top();
		huffman_queue.pop();
		HuffmanTreeNode* new_root = new HuffmanTreeNode('\0', left_child->getFrequency() + right_child->getFrequency());
		new_root->setLeftChild(left_child);
		new_root->setRightChild(right_child);
		huffman_queue.push(new_root);
	}
	root = huffman_queue.top();
}

void HuffmanTree::generateCode(HuffmanTreeNode* root, std::string current_code, std::unordered_map<char, std::string>& code_sheet) {
	if (root == nullptr)
		return;

	if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
		code_sheet[root->getCh()] = current_code;
	}
	generateCode(root->getLeftChild(), current_code + "0", code_sheet);
	generateCode(root->getRightChild(), current_code + "1", code_sheet);
}

void HuffmanTree::print(HuffmanTreeNode* root, std::string prefix = "", bool isLeft = true) {
	if (root == nullptr) {
		return;
	}

	std::cout << prefix;
	std::cout << (isLeft ? "|-- " : "`-- ");

	if (root->getCh() != '\0') {
		std::cout << root->getCh() << " (" << root->getFrequency() << ")\n";
	}
	else {
		std::cout << "* (" << root->getFrequency() << ")\n"; // 代表内部节点
	}

	print(root->getLeftChild(), prefix + (isLeft ? "|   " : "    "), true);
	print(root->getRightChild(), prefix + (isLeft ? "|   " : "    "), false);
}


HuffmanTreeNode* HuffmanTree::getRoot() const {
	return root;
}
