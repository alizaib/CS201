#include "Lecture17.h"
#include <iostream>
//#include <ctype.h>
#include <string>
using namespace std;

void EntryPoint17(){
	Misc();
	//PrintAllAsciiCharacters();
	//CountCharAndNumbers();
}
void Misc() {
	/*char a = 'Z';
	char* ptr = "Ali Zaib";
	cout << ptr;*/

	/*char* age = "45.22";
	cout << age << " " << atoi(age) << " " << atof(age);*/

	/*int a = '9' - '0';
	cout << a << endl << atoi("-4205AliZaib");*/

	/*int a = 3;
	int* ptr = &a;	
	cout << &ptr << "\t" << *ptr << "\t" << a << endl;
	*ptr = 7;
	cout << &a << "\t" << *ptr << "\t" << a << endl;
	cout << ptr << "\t" << sizeof(ptr);*/

	/*char* name = "Ali Zaib";
	cout << *name << endl;
	name+=4;
	cout << *name << endl << name;*/
	cout << sizeof(int);
	unsigned int num = '7' - '0';
	unsigned int num2 = '0' - '1';
	cout << num << "\t" << num2;

	/*char zero = '0';
	char toCheck = '9';
	unsigned int difference = toCheck - zero;
	if (difference > 9)
		cout << "Not digit";
	else
		cout << "digit";
	*/
	/*cout << Myatoi("253a5");*/
	
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
int Myatoi(const char* strNumber) {
	int result = 0;
	int sign = 1;
	if (*strNumber == '-') {
		sign = -1;
		strNumber++;
	}
	int currentDigit;
	do {
		currentDigit = *strNumber - '0';
		if (currentDigit > 9) {
			break;
		}
		result = result * 10 + currentDigit;
		strNumber++;
	} while (*strNumber != '\0');
	
	return result * sign;
}

