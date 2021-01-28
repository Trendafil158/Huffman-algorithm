#include "Outputting.h"

int main()
{
	string i, o;

	// Това са тестове са основните действия на програмата, реализирани чрез команди - компресия и декомпресия
	string regimeProgram;
	/*cout << "Enter command: ";
	cin >> regimeProgram;

	if (regimeProgram == "c[ompress]")
	{
		cout << "Enter the name of input file: ";
		cin >> i;

		writeToFile(i, "Today is a good day. The sky is blue and the grass is green.");

		cout << "Enter the name of output file: ";
		cin >> o;

		string encodeResult = writeEncodedTextIntoFile(i, o);
		cout << encodeResult;
	}
	else if (regimeProgram == "d[ecompress]")
	{
		cout << "Enter the name of the file in which is the encoded text: ";
		cin >> i;
		writeDecodedString(i);
	}
	else
	{
		cout << "Invalid command!" << endl;
		exit(1);
	}*/

	//Това е тест за извеждане на стандартния изход двоичната последователност, разбита на блокове от по 8 бита и превърнати в числа от 0 до 255

	/*cout << "Enter the output file: ";
	cin >> o;
	string encoded = readTextFromFile(o);

	cout << "Normal encode: " << encoded << endl;
	cout << "In eight bits: " << debugeWayInEightBitsBreak(encoded) << endl;*/

	//Това е тест за изкарване на стойността на компресия

	cout << "Enter the name of input file: ";
	cin >> i;
	cout << "Enter the name of output file: ";
	cin >> o;

	countDegreeCompression(i, o);

	return 0;
}
