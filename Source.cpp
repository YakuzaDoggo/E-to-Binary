#include <iostream> // some header files, dw about them
#include <windows.h>
#include <bitset>
#include <sstream>
#include "header.h"
#include <vector>

// to prevent stuff like std::cin.getline() and shit
using namespace std; 

bool hasConverted = false;

int main() {
	//char Message[MAXSIZE];
	vector<char> vecmessage;
	do { // this loops in the event the user put in a character that isn't an 'e' or fucked up something
		printf("How should we do this?\n (R)ead a file\n (W)rite it myself\n\n");
		char Choice[100];
		cin.getline(Choice, sizeof(Choice));
		cin.clear();

		if (tolower(Choice[0]) == 'r') {

			system("cls");
			printf("Write the name of the file. DO NOT INCLUDE .txt AT THE END!\n\n");
			char FileName[FILESIZENAME];
			cin.getline(FileName, FILESIZENAME);
			system("cls");

			if (LoadFile(vecmessage, FileName)) {
				printf("File Loaded! Will now convert.\n\n");
				system("pause");
				EToBin(vecmessage, hasConverted);
			}
			else {
				printf("File loading failed! Is it in SavedFiles?\n\n");
				system("pause");
			}

		}
		else if (tolower(Choice[0]) == 'w') {
		
				printf("Write some E's for me. \'E\' for 1, and \'e\' for 0. \n");

				
				// temporary char array to help with input since direct input to vector sucks
				char TempMsg[MAXSIZE];

				//gets user input
				cin.getline(TempMsg, sizeof(TempMsg)); 
				cin.clear();

				// copies 
				ArrayToVec(vecmessage, TempMsg);

				// we no longer need TempMsg after running ArrayToVec
				//delete TempMsg;

				EToBin(vecmessage, hasConverted);

		}
	} while (hasConverted == false);

	return 0;

}

