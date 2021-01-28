#include "BuildHuffmanTree.h"

Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

bool comp::operator()(Node* l, Node* r)
{
	return l->freq > r->freq;
}

bool isLeaf(Node* root)
{
	return root->left == nullptr && root->right == nullptr;
}

unordered_map<char, int> getAndPrintTheFrequencyTable(string text)
{
	unordered_map<char, int> freq;
	for (char ch : text) {
		freq[ch]++;
	}

	//Тук просто се изпечатва получената таблица
	/*for (auto ex : freq)
	{
		cout << ex.first << ": " << ex.second << endl;
	}
	cout << endl;*/

	return freq;
}

priority_queue<Node*, vector<Node*>, comp> buildHuffmanTree(string text)
{
	if (text == EMPTY_STRING) {
		cout << "Empty text!" << endl;
	}

	unordered_map<char, int> freq = getAndPrintTheFrequencyTable(text);

	priority_queue<Node*, vector<Node*>, comp> pq;

	for (auto pair : freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();    pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	return pq;
}