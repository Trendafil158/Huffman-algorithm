#include "Outputting.h"

void writeToFile(const string& fileName, const string& expression)
{
	ofstream outFile;
	outFile.open(fileName);

	if (!outFile.is_open())
	{
		cout << "Unable to open file.\n";
		return;
	}

	outFile << expression;

	outFile.close();
}

string readTextFromFile(string filename)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Unable to open file!" << std::endl;
	}

	string expression;
	getline(file, expression, '\n');

	file.close();
	return expression;
}

string writeEncodedTextIntoFile(const string& inFileName, const string& outFileName)
{
	ifstream inFile(inFileName);

	if (!inFile.is_open())
	{
		cout << "Unable to open " << inFileName << " file.\n";
	}

	string textToBeEncoded;

	getline(inFile, textToBeEncoded, '\n');

	inFile.close();

	priority_queue<Node*, vector<Node*>, comp> pq = buildHuffmanTree(textToBeEncoded);

	Node* root = pq.top();

	unordered_map<char, string> huffmanCode;
	encode(root, EMPTY_STRING, huffmanCode);

	string str;
	for (char ch : textToBeEncoded) {
		str += huffmanCode[ch];
	}

	cout << "Huffman Codes are:\n" << '\n';
	for (auto pair : huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}

	ofstream outFile(outFileName);

	if (!outFile.is_open())
	{
		cout << "Unable to open " << outFileName << " file.\n";
	}

	outFile << str;

	outFile.close();

	return str;
}

void writeDecodedString(const string& inFileName)
{
	string textOriginal = readTextFromFile("OriginalString.txt");

	ifstream inFile(inFileName);

	if (!inFile.is_open())
	{
		cout << "Unable to open " << inFileName << " file.\n";
		return;
	}

	string textToBeDecoded;

	inFile >> textToBeDecoded;

	inFile.close();

	priority_queue<Node*, vector<Node*>, comp> pq = buildHuffmanTree(textOriginal);

	Node* root = pq.top();

	if (isLeaf(root))
	{
		while (root->freq--) {
			cout << root->ch;
		}
	}
	else
	{
		int index = -1;
		while (index < (int)textToBeDecoded.size() - 1) {
			decode(root, index, textToBeDecoded);
		}
	}
}

string debugeWayInEightBitsBreak(string encodeResult)
{
	return getBinaryStringBrokenInEightBits(encodeResult);
}

void countDegreeCompression(string nameOfInputFile, string nameOfOutputFile)
{
	string originalText = readTextFromFile(nameOfInputFile);
	string encodedText = debugeWayInEightBitsBreak(readTextFromFile(nameOfOutputFile));
	cout << encodedText << endl;

	int countSymbolOriginalText = originalText.size();
	int compressCountOriginalSymbol = countSymbolOriginalText * 8;

	int countSymbolEncodedText = encodedText.size();
	int compressCountEncodedSymbol = countSymbolEncodedText * 8;

	cout << "Count original: " << countSymbolOriginalText << endl;
	cout << "Encoded original: " << countSymbolEncodedText << endl;

	cout << "The degree of compression is: " << compressCountEncodedSymbol << "/" << compressCountOriginalSymbol << endl;
}