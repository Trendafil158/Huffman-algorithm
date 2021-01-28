#include "Huffman_Encode.h"

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr) {
		return;
	}

	if (isLeaf(root)) {
		huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}