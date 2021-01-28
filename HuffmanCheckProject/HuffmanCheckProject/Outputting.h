#pragma once

#include "Huffman_Encode.h"
#include "Huffman_Decode.h"
#include "BreakEncodeInEightBits.h"
#include <fstream>
#include <set>
#include <algorithm>
#include <cctype>

// Функция, чрез която въвеждаме текст в текстов файл
void writeToFile(const string& fileName, const string& expression);

//Функция, чрез която четем текст от текстов файл
string readTextFromFile(string filename);

//Функция за извършване на компресия
string writeEncodedTextIntoFile(const string& inFileName, const string& outFileName);

//Функция за извършване на декомпресия
void writeDecodedString(const string& inFileName);

//Функция, изкарваща на стандартния изход компресираната информация на блокове от по 8 бита и превръщането им в числа между 0 и 255
string debugeWayInEightBitsBreak(string encodedResult);

//Функция, изкарваща каква е степента(отношението) на компресия
void countDegreeCompression(string nameOfInputFile, string nameOfOutputFile);