#include <iostream>
#include <windows.h>
#include <bitset>
#include <sstream>
#include "header.h"
#include <fstream>

using namespace std;

void EToBin(char message[], bool& converted) {
	char BinMessage[MAXSIZE];

	for (int x = 0; x < MAXSIZE; x++) {
		switch (message[x]) {
		case 'e': // e = 0
			BinMessage[x] = '0';
			break;

		case 'E': // E = 1
			BinMessage[x] = '1';
			break;

		case '\0': // enter key or the default empty array value is set to a null character
		case -52:
			BinMessage[x] = '\0';
			break;

		default: // if anything other than an 'e' or enter is used (e.g. 'j')
			printf("There's a character that isn\'t an \'e\', try again. \n \n");
			system("pause");
			system("cls");
			return;
		}

	}


	printf("The message in binary is: %s \n \n", BinMessage); // tells the user the binary (with no spaces)
	system("pause");
	system("cls");
	converted = true;

	BinToText(BinMessage); // passes the binary text into the binary to text function

}

void BinToText(char message[]) {
	char TextMessage[MAXSIZE];
	stringstream sstream(message);

	/*	basically checks each set of 8 characters and converts it to the decimal value of that character
		for example, 01100001 is the value 97 in decimal
		in ascii, a character with the decimal value 97 is 'a' */
	
	for (int x = 0; x < MAXSIZE; x++) {
		bitset<8> bits;
		sstream >> bits;
		char c = char(bits.to_ulong());
		TextMessage[x] = c;
	}

	printf("The message in a human-readable form is: %s \n \n", TextMessage); // tells the user the message in letters
	system("pause");
	system("cls");

}

bool LoadFile(char message[], char filename[]) {
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
			// is the current character a space?
			if (c != ' ') {
				message[x] = c;
				c = inFile.get();
			}
			
		}
		else {
			return true;
		}

	}

	return true;
}