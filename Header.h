#pragma once

// Max size for our message at 512 "bits"
const int MAXSIZE = 512;

// Max size for a windows file name and directory
const int FILESIZENAME = 255;

// Converts E's to binary (e.g eeeEEeeE -> 00011001)
void EToBin(char message[], bool& converted);

// Converts binary to standard human text
void BinToText(char message[]);

// Loads file from given folder to be read
bool LoadFile(char message[], char filename[]);

