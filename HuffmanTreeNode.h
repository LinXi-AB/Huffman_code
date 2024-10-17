#ifndef HUFFMANTREENODE_H
#define HUFFMANTREENODE_H

class HuffmanTreeNode {
private:
    char ch;
    int frequency;
    HuffmanTreeNode* left_child;
    HuffmanTreeNode* right_child;

public:
    HuffmanTreeNode(char ch, int freq);
    ~HuffmanTreeNode();
    int getFrequency() const;
    HuffmanTreeNode* getLeftChild() const;
    HuffmanTreeNode* getRightChild() const;
    char getCh() const;
    void setLeftChild(HuffmanTreeNode* node);
    void setRightChild(HuffmanTreeNode* node);
};

#endif // HUFFMANTREENODE_H
