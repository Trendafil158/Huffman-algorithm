#include "BreakEncodeInEightBits.h"

string breakStrInEightBits(string str)
{
	string helpResult = "";
	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		helpResult += str[i];
		count++;

		if (count == 8)
		{
			helpResult += " ";
			count = 0;
		}
	}

	cout << helpResult << endl;

	return helpResult;
}

int convertBinaryToDecimal(int n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}

int fromStringToInt(string str)
{
	stringstream toInt(str);
	int number = 0;
	toInt >> number;

	return number;
}

string fromIntToString(int num)
{
	stringstream ss;
	ss << num;
	string toStr = ss.str();

	return toStr;
}

string getBinaryStringBrokenInEightBits(string str)
{
	string array[MAX_SIZE_SEC];

	string useStr = breakStrInEightBits(str);

	int i = 0;

	int border = (useStr.size() / 8) - 1;

	while (i < border)
	{
		for (int j = 0; j < useStr.size(); j++)
		{
			array[i] += useStr[j];

			if (useStr[j] == ' ')
			{
				i++;
			}
		}
	}

	for (int i = 0; i < useStr.size(); i++)
	{
		if (array[i][0] == '0')
		{
			array[i].erase(array[i].begin());
		}
	}

	int toIntArray[MAX_SIZE_SEC];
	int index = 0;

	for (int i = 0; i < useStr.size(); i++)
	{
		toIntArray[index++] = fromStringToInt(array[i]);
	}

	int countEmpty = 0;

	for (int i = 0; i < useStr.size(); i++)
	{
		if (!array[i].empty())
		{
			countEmpty++;
		}
	}

	int helpToIntArray[MAX_SIZE_SEC];
	int hIndex = 0;

	for (int i = 0; i < countEmpty; i++)
	{
		helpToIntArray[hIndex++] = convertBinaryToDecimal(toIntArray[i]);
	}

	string finalResultInEightBits = "";

	for (int i = 0; i < countEmpty; i++)
	{
		finalResultInEightBits += fromIntToString(helpToIntArray[i]);
		finalResultInEightBits += " ";
	}

	return finalResultInEightBits;
}