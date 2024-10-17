#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include "HuffmanTreeNode.h"
#include "FrequencyCompare.h"
#include "HuffmanTree.h"

int main() {
    std::cout << "请输入您需要压缩的字符串:";
    std::string input_str;
    std::getline(std::cin, input_str);

    // 统计字符频率
    std::unordered_map<char, int> frequency_table;
    for (const auto& ch : input_str) {
        frequency_table[ch]++;
    }

    // 创建优先队列，字符频率小的排在前
    using HuffmanQueue = std::priority_queue<HuffmanTreeNode*, std::vector<HuffmanTreeNode*>, FrequencyCompare>;
    HuffmanQueue huffman_queue;
    for (const auto& pair : frequency_table) {
        huffman_queue.push(new HuffmanTreeNode(pair.first, pair.second));
    }

    // 调试信息
    std::cout << "其中各个字符出现的频率如下所示(已排序)" << std::endl;
    HuffmanQueue huffman_queue_temp = huffman_queue;
    while (!huffman_queue_temp.empty()) {
        std::cout << huffman_queue_temp.top()->getCh() << "->" << huffman_queue_temp.top()->getFrequency() << std::endl;
        huffman_queue_temp.pop();
    }

    // 调试信息
    std::cout << "正在构建哈夫曼树..." << std::endl;
    HuffmanTree huffman_tree;
    huffman_tree.createHuffmanTree(huffman_queue);
    huffman_tree.print(huffman_tree.getRoot(), "", true);

    // 利用哈夫曼树获得编码并应用于用户输入的文本
    std::cout << "以下是对您的字符生成的编码" << std::endl;
    std::unordered_map<char, std::string> encoding_map;
    huffman_tree.generateCode(huffman_tree.getRoot(), "", encoding_map);// 如何修改这个函数
    for (const auto& pair : encoding_map) {
        std::cout << pair.first << "->" << pair.second << std::endl;
    }

    // 调试信息，输出压缩后的文本
    std::string encoded_str;
    for (const auto& ch : input_str) {
        encoded_str += encoding_map[ch];
    }
    std::cout << "以下是编码后的字符串:" << encoded_str << std::endl;

    // 发送数据时注意
    std::cout << "当将压缩后的数据发送给对方时，需要将哈希表一同发送" << std::endl;

    // 解压
    std::string decoded_str;
    std::unordered_map<std::string, char> decoding_map;
    for (const auto& pair : encoding_map) {
        decoding_map[pair.second] = pair.first;
    }
    std::string compare_code;
    for (const auto& ch : encoded_str) {
        compare_code += ch;
        const auto& it = decoding_map.find(compare_code);
        if (it != decoding_map.end()) {
            decoded_str += it->second;
            compare_code.clear();
        }
    }
    std::cout << "以下是解压后的数据:" << decoded_str << std::endl;

    system("pause");
    return 0;
}
