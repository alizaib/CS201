#include "Lecture19.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void DisplayFileSize(int argc, char** argv);
void WriteInFile();
void CopyFile(int argc, char** argv);
void PlayWithStream();

void EntryPoint19(int argc, char** argv) {
	//DisplayFileSize(argc, argv);
	//WriteInFile();
	//CopyFile(argc, argv);
	PlayWithStream();
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
	if (argc < 2) {
		cout << "incorrect syntax. Try cs201.exe source.txt destination.txt";
		return;
	}
	ifstream source(argv[1]);
	ofstream dest(argv[2]);
	if (!source && !dest) {		
		cout << "either source or destination file cannot be open";
		return;
	}
	source.seekg(0, ios::end);
	long sourceSize = source.tellg();
	source.seekg(0, ios::beg); //reset read pointer to the start of file.

	const int MAX_CHARS = 10000;
	//char* str = (char*)malloc(sizeof(char)*MAX_CHARS);
	char str[MAX_CHARS];
	int i = 0;
	for (; i < sourceSize / MAX_CHARS; i++) {
		source.read(str, MAX_CHARS);
		dest.write(str, MAX_CHARS);
	}
	source.read(str, sourceSize - (i*MAX_CHARS));
	dest.write(str, sourceSize - (i*MAX_CHARS));
	
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