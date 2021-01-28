#pragma once

#include "Huffman_Encode.h"
#include "Huffman_Decode.h"
#include "BreakEncodeInEightBits.h"
#include <fstream>
#include <set>
#include <algorithm>
#include <cctype>

// �������, ���� ����� ��������� ����� � ������� ����
void writeToFile(const string& fileName, const string& expression);

//�������, ���� ����� ����� ����� �� ������� ����
string readTextFromFile(string filename);

//������� �� ���������� �� ���������
string writeEncodedTextIntoFile(const string& inFileName, const string& outFileName);

//������� �� ���������� �� �����������
void writeDecodedString(const string& inFileName);

//�������, ��������� �� ����������� ����� �������������� ���������� �� ������� �� �� 8 ���� � ������������ �� � ����� ����� 0 � 255
string debugeWayInEightBitsBreak(string encodedResult);

//�������, ��������� ����� � ��������(�����������) �� ���������
void countDegreeCompression(string nameOfInputFile, string nameOfOutputFile);