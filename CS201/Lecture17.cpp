#include "Lecture17.h"
#include <iostream>
//#include <ctype.h>
#include <string>
using namespace std;

void EntryPoint17(){
	Misc17();
	//PrintAllAsciiCharacters();
	//CountCharAndNumbers();
}
void Misc17() {
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
	/*cout << sizeof(int);
	unsigned int num = '7' - '0';
	unsigned int num2 = '0' - '1';
	cout << num << "\t" << num2;*/

	/*char zero = '0';
	char toCheck = '9';
	unsigned int difference = toCheck - zero;
	if (difference > 9)
		cout << "Not digit";
	else
		cout << "digit";
	*/	

	//const int a = 3;
	//int b = 5;
	//const int* ptr = &b;
	//ptr = &a;
	////*ptr = 7;
	//cout << *ptr;

	/*char amount[10] = "46Ali";	
	int am = Myatoi(amount);
	cout << am << "\t" << amount;	
	char* number = "253a5";
	cout << Myatoi(number) << "\t" << number;*/

	char* statment = "This is a test";
	int len = strlen(statment);
	char* statment2 = (char*)malloc((len + 1));
	cout << statment2 << endl;
	strcpy(statment2, statment);
	char* token = strtok(statment2, " ");
	do  {
		cout << token << endl;
	} while ((token = strtok(NULL, " ")) != NULL);
	

	
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
int Myatoi(char* strNumber) {	
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
	strNumber -= 2;
	*strNumber = 'Z';
	strcpy(strNumber, "Hel");
	return result * sign;
}

