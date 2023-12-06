#include <iostream>
#include <iomanip>
#include <queue>
#include <unordered_map>

using namespace std;

class HuffmanNode {
public:
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
    ~HuffmanNode() {
        delete left;
        delete right;
    }
};

class Compare {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

class HuffmanCoding {
private:
    HuffmanNode* root;

    HuffmanNode* buildHuffmanTree(const string& text) {
        unordered_map<char, unsigned> freq;
        for (char ch : text) {
            freq[ch]++;
        }

        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

        for (auto& entry : freq) {
            pq.push(new HuffmanNode(entry.first, entry.second));
        }

        while (pq.size() > 1) {
            HuffmanNode* left = pq.top(); pq.pop();
            HuffmanNode* right = pq.top(); pq.pop();

            HuffmanNode* internalNode = new HuffmanNode('-', left->frequency + right->frequency);

            internalNode->left = left;
            internalNode->right = right;

            pq.push(internalNode);
        }

        return pq.top();
    }

    void encode(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCode) {
        if (root == nullptr) {
            return;
        }

        if (!root->left && !root->right) {
            huffmanCode[root->data] = code;
        }

        encode(root->left, code + "0", huffmanCode);
        encode(root->right, code + "1", huffmanCode);
    }

    void printTree(HuffmanNode* root, int indent = 0) {
        if (root != nullptr) {
            printTree(root->right, indent + 4);
            cout << setw(indent) << root->data << endl;
            printTree(root->left, indent + 4);
        }
    }

public:
    HuffmanCoding(const string& text) {
        root = buildHuffmanTree(text);
    }

    ~HuffmanCoding() {
        delete root;
    }

    string huffmanEncode(const string& text) {
        unordered_map<char, string> huffmanCode;
        encode(root, "", huffmanCode);

        string encodedText;
        for (char ch : text) {
            encodedText += huffmanCode[ch];
        }

        return encodedText;
    }

    void printHuffmanTree() {
        cout << "Huffman Tree (Vertical):\n";
        printTree(root);
        cout << endl;
    }
};

int main() {
    string text = "beep boop beer";

    HuffmanCoding huffman(text);

    // Print Huffman tree
    huffman.printHuffmanTree();

    return 0;
}
