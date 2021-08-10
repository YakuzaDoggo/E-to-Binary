#pragma once
#include <vector>

using namespace std;

// Max size for our message at 512 "bits"
const int MAXSIZE = 1024;

// Max size for a windows file name and directory
const int FILESIZENAME = 255;

// Removes spaces from vector
void RemoveSpaces(vector<char>& message);

// Converts vector into array, used in BinToText
void VecToArray(vector<char> message, char array[]);

// Converts E's to binary (e.g eeeEEeeE -> 00011001)
void EToBin(vector<char> message, bool& converted);

// Converts binary to standard human text
void BinToText(vector<char> message);

// Loads file from given folder to be read
bool LoadFile(vector<char>& message, char filename[]);

// Converts a char array into a vector as this helps with manually input
void ArrayToVec(vector<char>& message, char temp[]);

// Helps output whatever is contained in the binary vector. Is called within EtoBin.
void VecOutput(vector<char>& message);

// Experimental: Directly copies input into vector
//void VecInput(vector<char>& message, input);