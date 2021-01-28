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

//Функция, играеща ролята на конструктор за инициализиране на всеки node
Node* getNode(char ch, int freq, Node* left, Node* right);

// Това е помощна структура, показваща, че по-високо приоритетния елемент има по-малка честота
struct comp {
	bool operator()(Node* l, Node* r);
};

// Функция, проверяща дали даден възел е листо
bool isLeaf(Node* root);

// Функция за създаване и извеждане на честотната таблица
unordered_map<char, int> getAndPrintTheFrequencyTable(string text);

// Функция за създаване на дървото на Хъфман
priority_queue<Node*, vector<Node*>, comp> buildHuffmanTree(string text);
