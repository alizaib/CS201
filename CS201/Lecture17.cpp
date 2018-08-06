#include "Lecture17.h"
#include <iostream>
#include <ctype.h>
using namespace std;

void EntryPoint17(){
	PrintAllAsciiCharacters();
	//CountCharAndNumbers();
}

void PrintAllAsciiCharacters() {
	for (int i = 0; i < 256; i++) {
		if (i == '\n') cout << "Hey got an enter";
		if (i == ' ')  cout << "Hey got a space";
		if (i == '\t') cout << "Hey got a tab";
		if (i == '@') cout << "Hey got a @";
		cout << i << "\t" << (char)i << endl;
	}
		
}
void CountCharAndNumbers() {
	cout << "Please enter something and then press enter" << endl;
	int numbers = 0, smallLetters = 0 , capitalLetters = 0;
	int c;
	while ((c = getchar()) != '\n') {
		if (isdigit(c))
			numbers++;
		else if (islower(c))
			smallLetters++;
		else if (isupper(c))
			capitalLetters++;
	}
	cout << "You have entered: " << endl
		<< numbers << " numbers " << endl
		<< smallLetters << " small letters " << endl
		<< capitalLetters << " capital letters" << endl;
}
