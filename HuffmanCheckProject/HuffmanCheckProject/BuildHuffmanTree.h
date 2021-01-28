#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

#define EMPTY_STRING ""

struct Node
{
	char ch;
	int freq;
	Node* left, * right;
};

//�������, ������� ������ �� ����������� �� �������������� �� ����� node
Node* getNode(char ch, int freq, Node* left, Node* right);

// ���� � ������� ���������, ���������, �� ��-������ ������������ ������� ��� ��-����� �������
struct comp {
	bool operator()(Node* l, Node* r);
};

// �������, ��������� ���� ����� ����� � �����
bool isLeaf(Node* root);

// ������� �� ��������� � ��������� �� ���������� �������
unordered_map<char, int> getAndPrintTheFrequencyTable(string text);

// ������� �� ��������� �� ������� �� ������
priority_queue<Node*, vector<Node*>, comp> buildHuffmanTree(string text);
