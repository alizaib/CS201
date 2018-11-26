#include "Lecture21.h"
#include <iostream>
using namespace std;

void EntryPoint21(int argc, char** argv) {
	cout << "12 & 8 = " << (12 & 8) << endl;
	cout << "12 | 8 = " << (12 | 0x8) << endl;

	cout << "8 ^ 1 = " << (8 ^ 1) << endl;
	cout << "8 ^ 1 ^ 1 = " << ((8 ^ 1) ^ 1) << endl;
	//RAID Redundant Array of inexpensive disks

	//Swap two values without introducing a new variable
	int a = 9, b = 4;
	a = a ^ b; // a is now 13
	b = b ^ a; // b will now get a's value which is 4 = 13 ^ 9
	a = b ^ a; // a will get 9 = 4 ^ 13
	cout << "a = " << a << " b = " << b << endl;

	cout << (-8 >> 1);
}