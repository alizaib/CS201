#include "Lecture17.h"
#include <iostream>
using namespace std;

void EntryPoint17(){
	PrintAllAsciiCharacters();
}

void PrintAllAsciiCharacters() {
	for (int i = 0; i < 256; i++)
		cout << i << "\t" << (char)i << endl;
}
