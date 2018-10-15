#include "Lecture18.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void WriteToTextFile();

void EntryPoint18(){
	//Misc18();
	WriteToTextFile();
	//ReadTextFile();
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
