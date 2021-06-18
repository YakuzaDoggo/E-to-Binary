#include <iostream> // some header files, dw about them
#include <windows.h>
#include <bitset>
#include <sstream>
#include "header.h"
/* TODO:
	fix how input is read from a file. it needs to allow spaces
	but will only read the first byte.
*/


using namespace std; // to prevent stuff like std::cin.getline() and shit

bool hasConverted = false;

int main() {
	char Message[MAXSIZE];
	do { //this loops in the event the user put in a character that isn't an 'e' or fucked up something
		printf("How should we do this?\n (R)ead a file\n (W)rite it myself\n\n");
		char Choice[100];
		cin.getline(Choice, sizeof(Choice));
	
		if (tolower(Choice[0]) == 'r') {

			system("cls");
			printf("Write the name of the file. DO NOT INCLUDE .txt AT THE END!\n\n");
			char FileName[FILESIZENAME];
			cin.getline(FileName, FILESIZENAME);
			system("cls");

			if (LoadFile(Message, FileName)) {
				printf("File Loaded! Will now convert.\n\n");
				system("pause");
				EToBin(Message, hasConverted);
			}
			else {
				printf("File loading failed! Is it in SavedFiles?\n\n");
				system("pause");
			}

		}
		else if (tolower(Choice[0]) == 'w') {
		
				printf("Write some E's for me. \'E\' for 1, and \'e\' for 0. \n");

				cin.getline(Message, MAXSIZE); //gets user input
				cin.clear();

				EToBin(Message, hasConverted);

		}
	} while (hasConverted == false);

	return 0;

}

