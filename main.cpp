#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include "HuffmanTreeNode.h"
#include "FrequencyCompare.h"
#include "HuffmanTree.h"

int main() {
    std::cout << "����������Ҫѹ�����ַ���:";
    std::string input_str;
    std::getline(std::cin, input_str);

    // ͳ���ַ�Ƶ��
    std::unordered_map<char, int> frequency_table;
    for (const auto& ch : input_str) {
        frequency_table[ch]++;
    }

    // �������ȶ��У��ַ�Ƶ��С������ǰ
    using HuffmanQueue = std::priority_queue<HuffmanTreeNode*, std::vector<HuffmanTreeNode*>, FrequencyCompare>;
    HuffmanQueue huffman_queue;
    for (const auto& pair : frequency_table) {
        huffman_queue.push(new HuffmanTreeNode(pair.first, pair.second));
    }

    // ������Ϣ
    std::cout << "���и����ַ����ֵ�Ƶ��������ʾ(������)" << std::endl;
    HuffmanQueue huffman_queue_temp = huffman_queue;
    while (!huffman_queue_temp.empty()) {
        std::cout << huffman_queue_temp.top()->getCh() << "->" << huffman_queue_temp.top()->getFrequency() << std::endl;
        huffman_queue_temp.pop();
    }

    // ������Ϣ
    std::cout << "���ڹ�����������..." << std::endl;
    HuffmanTree huffman_tree;
    huffman_tree.createHuffmanTree(huffman_queue);
    huffman_tree.print(huffman_tree.getRoot(), "", true);

    // ���ù���������ñ��벢Ӧ�����û�������ı�
    std::cout << "�����Ƕ������ַ����ɵı���" << std::endl;
    std::unordered_map<char, std::string> encoding_map;
    huffman_tree.generateCode(huffman_tree.getRoot(), "", encoding_map);// ����޸��������
    for (const auto& pair : encoding_map) {
        std::cout << pair.first << "->" << pair.second << std::endl;
    }

    // ������Ϣ�����ѹ������ı�
    std::string encoded_str;
    for (const auto& ch : input_str) {
        encoded_str += encoding_map[ch];
    }
    std::cout << "�����Ǳ������ַ���:" << encoded_str << std::endl;

    // ��������ʱע��
    std::cout << "����ѹ��������ݷ��͸��Է�ʱ����Ҫ����ϣ��һͬ����" << std::endl;

    // ��ѹ
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
    std::cout << "�����ǽ�ѹ�������:" << decoded_str << std::endl;

    system("pause");
    return 0;
}
