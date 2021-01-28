#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

//Максимален размер за масив
const int MAX_SIZE_SEC = 1000;

//Тази функция разцепва подадения стринг на блокове от по 8 бита
string breakStrInEightBits(string str);

//Функция за превръщане на число в двоичен вид в десетичен вид
int convertBinaryToDecimal(int n);

//Функция, превръщаща string в integer
int fromStringToInt(string str);

//Функция, превръщаща integer в string
string fromIntToString(int num);

//Функция, връщаща крайния резултат
string getBinaryStringBrokenInEightBits(string str);
