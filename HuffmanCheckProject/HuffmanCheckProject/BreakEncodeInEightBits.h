#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

//���������� ������ �� �����
const int MAX_SIZE_SEC = 1000;

//���� ������� �������� ��������� ������ �� ������� �� �� 8 ����
string breakStrInEightBits(string str);

//������� �� ���������� �� ����� � ������� ��� � ��������� ���
int convertBinaryToDecimal(int n);

//�������, ���������� string � integer
int fromStringToInt(string str);

//�������, ���������� integer � string
string fromIntToString(int num);

//�������, ������� ������� ��������
string getBinaryStringBrokenInEightBits(string str);
