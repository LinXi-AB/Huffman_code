#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <unordered_map>
#include <queue>
#include <string>
#include "HuffmanTreeNode.h"
#include "FrequencyCompare.h"

class HuffmanTree {
private:
    HuffmanTreeNode* root;

public:
    HuffmanTree();
    ~HuffmanTree();
    void deleteTree(HuffmanTreeNode* root);
    void createHuffmanTree(std::priority_queue<HuffmanTreeNode*, std::vector<HuffmanTreeNode*>, FrequencyCompare>& huffman_queue);
    void generateCode(HuffmanTreeNode* root, std::string current_code, std::unordered_map<char, std::string>& code_sheet);
    void print(HuffmanTreeNode* root, std::string prefix, bool isLeft);
    HuffmanTreeNode* getRoot() const;
};

#endif // HUFFMANTREE_H


