#include "Lecture18.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void WriteToTextFile();
void ReadTextFile2();

void EntryPoint18(int argc, char** argv){
	DisplayCommandLineArgs(argc, argv);

	//Misc18();
	//WriteToTextFile();
	//ReadTextFile();
	//ReadTextFile2();
}

void DisplayCommandLineArgs(int argc, char** argv)
{	
	if (argc < 2) {
		cout << "no arguments passed\n";
		cout << *argv; //program name (full path) is treated as 
	}
	else {
		for (int count = 1; count < argc; count++)
			cout << *(argv + count) << "\t";
	}
}

void Misc18() {
	
}

void ReadTextFile() {
	ifstream myFile;
	myFile.open("SalaryInfo1.txt");
	if (!myFile) {
		cout << "File cannot be open";
		return;
	}
	//char* name = (char*)malloc(sizeof(char)*20); 
	char name[20];
	float salary;
	do {
		myFile >> name >> salary;
		cout << name << "\t" << salary << endl;
	} while (!myFile.eof());
	myFile.close();
}

void ReadTextFile2() {
	ifstream myFile;
	myFile.open("SalaryInfo1.txt");
	if (!myFile) {
		cout << "File cannot be open";
		return;
	}
	char line[100];
	
	do {
		myFile.getline(line, 100);
		cout << line << endl;
	} while (!myFile.eof());
	myFile.close();
}
void WriteToTextFile() {
	ofstream myFile;
	myFile.open("SalaryInfo1.txt", ios::out);
	if (!myFile) {
		cout << "File cannot be open";
		return;
	}
	char choice;
	char name[20];
	float salary;
	do {
		cout << "\nEnter Name: "; cin >> name;
		cout<<"\nEnter Salary: "; cin >> salary;
		myFile << name << "\t" << salary << endl;

		cout << "Enter y if you want to repeat: ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
	myFile.close();
}
