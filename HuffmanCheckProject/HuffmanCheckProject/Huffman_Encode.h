#pragma once

#include "BuildHuffmanTree.h"

// Функция, извършваща компресия
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);
