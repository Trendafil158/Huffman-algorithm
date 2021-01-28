#include "Huffman_Decode.h"

void decode(Node* root, int& index, string str)
{
	if (root == nullptr) {
		return;
	}

	if (isLeaf(root)) {
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] == '0') {
		decode(root->left, index, str);
	}
	else {
		decode(root->right, index, str);
	}
}