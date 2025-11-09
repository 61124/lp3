#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


struct MinHeapNode {
    char data;                
    int freq;                 
    MinHeapNode* left;        
    MinHeapNode* right;       

    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};


struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        if(l->freq == r->freq) {
            return l->data > r->data;
        }
        return l->freq > r->freq; 
    }
};


void storeHuffmanCodes(MinHeapNode* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;
    if (root->data != '$') // Internal node is marked with '$'
        huffmanCode[root->data] = str;

    storeHuffmanCodes(root->left, str + "0", huffmanCode);
    storeHuffmanCodes(root->right, str + "1", huffmanCode);
}


MinHeapNode* buildHuffmanTree(unordered_map<char, int>& freq) {
    
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    
    for (auto pair : freq) {
        minHeap.push(new MinHeapNode(pair.first, pair.second));
    }

    
    while (minHeap.size() != 1) {
        MinHeapNode* left = minHeap.top();
        minHeap.pop();

        MinHeapNode* right = minHeap.top();
        minHeap.pop();

        
        MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    
    return minHeap.top();
}


string encode(const string& text, unordered_map<char, string>& huffmanCode) {
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }
    return encodedString;
}


string decode(MinHeapNode* root, const string& encodedStr) {
    string decodedString = "";
    MinHeapNode* currentNode = root;

    for (char bit : encodedStr) {
        if (bit == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

       
        if (!currentNode->left && !currentNode->right) {
            decodedString += currentNode->data;
            currentNode = root; 
        }
    }

    return decodedString;
}

int main() {
    string text;
    cout<<"Enter string to be encoded: ";
    getline(cin,text);

    
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    
    MinHeapNode* root = buildHuffmanTree(freq);

    
    unordered_map<char, string> huffmanCode;
    storeHuffmanCodes(root, "", huffmanCode);

    
    string encodedStr = encode(text, huffmanCode);
    cout << "Encoded string: " << encodedStr << endl;

    
    string decodedStr = decode(root, encodedStr);
    cout << "Decoded string: " << decodedStr << endl;

    return 0;
}
