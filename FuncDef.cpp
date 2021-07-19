#include <iostream>
#include <windows.h>
#include <bitset>
#include <sstream>
#include "header.h"
#include <fstream>
#include <vector>
using namespace std;

void RemoveSpaces(vector<char>& message) {
	for (int x = 0; x <= message.size() - 1; ++x) {
		// is the current character a space?
		if (message.at(x) == ' ') {
			// if so, remove it
			message.erase(message.begin() + x);
		}
	}	

}

void VecToArray(vector<char> message, char array[]) {
	for (int x = 0; x < message.size(); ++x) {
		array[x] = message.at(x);

	}

}

void EToBin(vector<char> message, bool& converted) {
	//char BinMessage[MAXSIZE];

	/* possible new method to remove spaces
	* vectors allow remove, while still dynamically allocating
	* memory. Which should be good in most cases.*/
	vector<char> VecBinMessage;

	int VecSize = message.size();

	for (int x = 0; x < VecSize; x++) {
		switch (message[x]) {
		// e = 0
		case 'e': 
			VecBinMessage.push_back('0');
			//BinMessage[x] = '0';
			break;

		// E = 1
		case 'E': 
			VecBinMessage.push_back('1');

			//BinMessage[x] = '1';
			break;

		// enter key or the default empty array value is set to a null character
		case '\0': 
		case -52:
			VecBinMessage.push_back('\0');
			break;

		default: // if anything other than an 'e' or enter is used (e.g. 'j')
			printf("There's a character that isn\'t an \'e\', try again. \n \n");
			system("pause");
			system("cls");
			return;
		}

	}

	// tells the user the binary (with no spaces)
	printf("The message in binary is: ");
	VecOutput(VecBinMessage);
	system("pause");
	system("cls");
	converted = true;

	// passes the binary text into the binary to text function
	BinToText(VecBinMessage); 

}

void BinToText(vector<char> message) {

	// 8 bits is to one character
	const int MessageSize = MAXSIZE / 8;

	// Our actual message in human-readable text
	char TextMessage[MessageSize];

	char BinArray[MAXSIZE];

	// Converts what's in the vector to an array
	VecToArray(message, BinArray);

	stringstream sstream(BinArray);

	/*	basically checks each set of 8 characters and converts it to the decimal value of that character
		for example, 01100001 is the value 97 in decimal
		in ascii, a character with the decimal value 97 is 'a' */

	for (int x = 0; x < MessageSize; x++) {
		bitset<8> bits;
		sstream >> bits;
		char c = char(bits.to_ulong());
		TextMessage[x] = c;
	}

	printf("The message in a human-readable form is: %s \n \n", TextMessage); // tells the user the message in letters
	system("pause");
	system("cls");

}

bool LoadFile(vector<char>& message, char filename[]) {
	char FileDirect[FILESIZENAME];
	snprintf(FileDirect, FILESIZENAME, ".\\SavedFiles\\%s.txt", filename);

	ifstream inFile;
	inFile.open(FileDirect);
	if (!inFile) {
		return false;
	}

	char c = inFile.get();

	for (int x = 0; x < MAXSIZE; ++x) {
		// get character so long it isn't a newline or end of file
		if (c != '\n' && !inFile.eof()) {
			message.push_back(c);
			//message[x] = c;
			c = inFile.get();
		}


	}

	RemoveSpaces(message);

	return true;
}

void ArrayToVec(vector<char>& message, char temp[]) {
	int x = 0;

	// Is the character currently selected null terminated?
	while (temp[x] != '\0') {

		// If not, put it in vector
		message.push_back(temp[x]);
		x++;
	}

	return;
}

void VecOutput(vector<char>& message) {
	// simple for loop that just prints out each individual "bit"
	for (int x = 0; x < message.size(); ++x) {
		cout << message.at(x);

	}

	printf("\n \n");
}