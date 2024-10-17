#include "HuffmanTreeNode.h"

HuffmanTreeNode::HuffmanTreeNode(char ch, int freq)
    : ch(ch), frequency(freq), left_child(nullptr), right_child(nullptr) {}

HuffmanTreeNode::~HuffmanTreeNode()
{
    
}

int HuffmanTreeNode::getFrequency() const {
    return frequency;
}

HuffmanTreeNode* HuffmanTreeNode::getLeftChild() const {
    return left_child;
}

HuffmanTreeNode* HuffmanTreeNode::getRightChild() const {
    return right_child;
}

char HuffmanTreeNode::getCh() const {
    return ch;
}

void HuffmanTreeNode::setLeftChild(HuffmanTreeNode* node) {
    left_child = node;
}

void HuffmanTreeNode::setRightChild(HuffmanTreeNode* node) {
    right_child = node;
}
