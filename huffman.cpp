#include <iostream>
#include <list>
#include <string>
using namespace std;

// Define a structure for Huffman tree nodes.
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
};

// A comparator for Huffman nodes based on frequency.
bool CompareHuffmanNodes(const HuffmanNode* a, const HuffmanNode* b) {
    return a->freq < b->freq;
}

// A function to print character code words using the Huffman tree.
void PrintHuffmanCodes(HuffmanNode* root, string code = "") {
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right) {
        // Print the character, its frequency, and the code.
        cout << root->data << "\t\t" << code << "\n";
    }
    // Recursively process the left and right subtrees, appending '0' or '1' to the code.
    PrintHuffmanCodes(root->left, code + "0");
    PrintHuffmanCodes(root->right, code + "1");
}

// Build the Huffman tree and return the root node.
HuffmanNode* BuildHuffmanTree(char arr[], int freq[], int n) {
    list<HuffmanNode*> nodes;

    // Create initial leaf nodes and add them to the list.
    for (int i = 0; i < n; i++) {
        nodes.push_back(new HuffmanNode{arr[i], freq[i], nullptr, nullptr});
    }

    while (nodes.size() > 1) {
        // Sort nodes based on frequency.
        nodes.sort(CompareHuffmanNodes);

        // Take the two nodes with the lowest frequencies.
        HuffmanNode* t1 = nodes.front();
        nodes.pop_front();
        HuffmanNode* t2 = nodes.front();
        nodes.pop_front();

        // Create a new node with a null character, sum of frequencies, and the two nodes as children.
        HuffmanNode* newNode = new HuffmanNode{'\0', t1->freq + t2->freq, t1, t2};
        nodes.push_back(newNode);
    }

    // Return the root of the Huffman tree.
    return nodes.front();
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {50, 10, 30, 5, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanNode* root = BuildHuffmanTree(arr, freq, size);

    cout << "Character\tCode\n";
    // Print Huffman codes for characters.
    PrintHuffmanCodes(root);

    // Clean up dynamically allocated nodes.
    delete root;

    return 0;
}
