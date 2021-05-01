#include <iostream> // some header files, dw about them
#include <windows.h>
#include <bitset>
#include <sstream>

using namespace std; // to prevent stuff like std::cin.getline() and shit

const int MAXSIZE = 512;

void EToBin(char message[], bool &converted);

void BinToText(char message[]);

int main() {

	bool hasConverted = false;

	do { //this loops in the event the user put in a character that isn't an 'e'
		printf("Write some E's for me. \'E\' for 1, and \'e\' for 0. \n");
		char Message[MAXSIZE];

		cin.getline(Message, MAXSIZE); //gets user input
		cin.clear();

		EToBin(Message, hasConverted);

	} while (hasConverted == false);


	return 0;

}

void EToBin(char message[], bool &converted) {
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
			printf("There's a character that is an \'e\', try again. \n \n"); 
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
		in ascii, a character with the decimal value 97 is 'a'
	*/
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
