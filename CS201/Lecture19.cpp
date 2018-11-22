#include "Lecture19.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void DisplayFileSize(int argc, char** argv);
void WriteInFile();
void CopyFile(int argc, char** argv);
void PlayWithStream();
void WriteNumbers();

void EntryPoint19(int argc, char** argv) {
	//DisplayFileSize(argc, argv);
	//WriteInFile();
	//CopyFile(argc, argv);
	//PlayWithStream();
	WriteNumbers();
}

void DisplayFileSize(int argc, char** argv) {
	if (argc < 2) {
		cout << "filename was not passed";
		return;
	}

	ifstream inFile(argv[1]);
	if (!inFile) {
		cout << argv[1] << " cannot be open";
		return;
	}
	inFile.seekg(0, ios::end);
	long inSize = inFile.tellg();
	cout << "size of file " << argv[1] << " is " << inSize;
	inFile.close();
}

void WriteInFile() {
	ofstream file("text.txt");
	if (!file) {
		cout << "text.txt cannot be open for read/write";
		return;
	}
	long pos;
	file.write("This is an apple", 16);
	pos = file.tellp();
	file.seekp(pos - 7);
	file.write(" sam", 4);
	file.close();
}

void CopyFile(int argc, char** argv) {
	/*if (argc < 3) {
		cout << "incorrect syntax. Try cs201.exe source.txt destination.txt";
		return;
	}*/

	ifstream source("salaryinfo1.txt"/*argv[1]*/);
	ofstream dest("copy-salary-info1.txt"/*argv[2]*/);
	if (!(source && dest)) {		
		cout << "either source or destination file cannot be open";
		return;
	}
	source.seekg(0, ios::end);
	long sourceSize = source.tellg();
	source.seekg(0, ios::beg); //reset read pointer to the start of file.

	const int MAX_CHARS = 10000;
	char* str = (char*)malloc(sizeof(char)*MAX_CHARS);
	//char str[MAX_CHARS];
	int i = 0;
	for (; i < sourceSize / MAX_CHARS; i++) {
		source.read(str, MAX_CHARS);
		dest.write(str, MAX_CHARS);
	}
	int remainingChars = sourceSize - (i*MAX_CHARS);
	str = (char*)malloc(sizeof(char)*remainingChars+1);
	
	source.read(str, remainingChars);
	str[remainingChars] = '\0';
	dest.write(str, remainingChars+1);
	
	source.close();
	dest.close();
}

void PlayWithStream() {
	ifstream inFile("code.txt");
	ofstream scrn("CON");
	char inputChar;
	if (!inFile) {
		cout << "Error opening file"; return;
	}
	while (inFile.get(inputChar)) {
		scrn << (inputChar);
	}
	inFile.close();
	scrn.close();
}

void WriteNumbers() {
	ofstream file("numbers.txt");
	for (int i = 0; i < 100; i++)
		file.write((char*)&i, sizeof(int));
	file.close();

	ifstream file1("numbers.txt");
	int j;
	for (int i = 0; i < 100; i++)
	{
		file1.read((char*)&j, sizeof(int));
		cout << j << endl;
	}
	file1.close();
}