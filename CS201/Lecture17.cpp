#include "Lecture17.h"
#include <iostream>
//#include <ctype.h>
#include <string>
using namespace std;

void EntryPoint17() {
	Misc17();
	//PlayWithConstPointers();
	//PlayWithIntPointer();
	//ConsoleOutWithCharPointer();
	//CharAsInt();
	//UsingStrToken();
	//PrintAllAsciiCharacters();
	//CountCharAndNumbers();
}

void Misc17() {

	/*char* name = "Ali Zaib";
	cout << name << endl; // *name will display first character only, whereas name will display all the string till nullable 0
	cout << *name << endl;
	name+=1; //move pointer 
	cout << *name << endl << name;*/

	/*
	cout << sizeof(int) << endl;
	unsigned int num = '7' - '0';
	unsigned int num2 = '1' - '5';
	int num3 = '1' - '5';
	cout << num << "\t" << num2 << "\t" << num3;
	*/

	/*
	char zero = '0';
	char toCheck = '!';
	unsigned int difference = toCheck - zero;	
	// an unsigned integer doesn't contain any symbol and the most significant bit is one 
	// which results in a very large number
	int diff = toCheck - zero;
	cout << difference << endl;
	cout << diff << endl;
	if (difference > 9)
		cout << "Not digit";
	else
		cout << "digit";
	*/	

	

	char amount[10] = "46Ali";	
	int am = Myatoi(amount);
	cout << am << "\t" << amount << endl;
	char* number = "253a5";
	cout << Myatoi(number) << "\t" << number;
	
}

void PlayWithConstPointers() {
	const int a = 3;
	const int b = 4;
	int c = 5, d = 9, e = 11;

	int* ptr = &e;

	const int* ptr1 = &d; //read from right to left. ptr1 is a pointer to int const (or const int)
	int const* ptr2 = &b;  //same as above, ptr2 is a pointer to const int
	int* const ptr3 = &c;  //ptr3 is a constant pointer to an integer, it cannot be assigned any new value now, ptr3 = &d; will give compiler error
	const int* const ptr4 = &d; //althoug d is not constant, 
	//but is assignable to ptr4 and ptr4 will not allow changing contents *ptr4 = 0; is not allowed
	//*ptr4 = 0;

	 // *ptr1 = 23; //compiler will complaint because ptr1 is a pointer to a constant int and value of that int cannot be changed now
	//*ptr2 = 23;   //same as above

	cout << *ptr1 << "\t" << *ptr2 << "\t" << *ptr3 << "\t" << *ptr4 << endl;
}

void PlayWithIntPointer() {
	int a = 3;
	int* ptr = &a;

	cout << "&ptr " << &ptr << " is address of the pointer in memory " << endl;
	cout << "&a " << &a << " is address of variable a in memory" << endl;
	cout << "*ptr " << *ptr << " is content of the pointer " << endl;
	cout << "which is equal to a's content " << a << endl;
	cout << endl << endl;
	*ptr = 7;
	cout << "After executing *ptr = 7;" << endl;

	cout << "*ptr " << *ptr << " is content of the pointer " << endl;
	cout << "which is equal to a's content " << a << endl;

	cout << "size of ptr is " << sizeof(ptr);
}

void ConsoleOutWithCharPointer() {

	char* breakWhereNullableStringIs = "Ali\0Zaib";
	cout << breakWhereNullableStringIs << endl;

	char* ptr = "Ali Zaib";
	cout << ptr;
}

void CharAsInt() {
	int a = '9' - '2';
	cout << a << endl;
}

void UsingStrToken() {
	char* statment = "This is a test";
	int len = strlen(statment);
	char* statment2 = (char*)malloc((static_cast<size_t>(len) + 1));
	cout << statment2 << endl;

	//Note if you remove the if check, VS gives warning that statement2 could be zero. means mallooc is gaurenteed to return memory.
	if (statment2 != NULL) {
		strcpy(statment2, statment);
	}


	char* token = strtok(statment2, " ");
	do {
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
	return result * sign;
}

