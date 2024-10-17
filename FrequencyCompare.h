#ifndef FREQUENCYCOMPARE_H
#define FREQUENCYCOMPARE_H

#include "HuffmanTreeNode.h"

class FrequencyCompare {
public:
    bool operator()(HuffmanTreeNode* node1, HuffmanTreeNode* node2);
};

#endif // FREQUENCYCOMPARE_H
