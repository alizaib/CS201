#include "Lecture20.h"
#include <iostream>

using namespace std;

struct Address
{
	char streetAddress[100];
	char city[50];
	char country[50];
};
struct Student
{
	char name[60];
	double gpa;
	Address add;
};

struct Test {
	char* name;
};

void PrintStudentInfo(Student student);

void EntryPoint20(int argc, char** argv) {
	/*Student s1 = { "Ali Zaib", 3.3, { "House 277, street 17", "Islamabad", "Pakistan" } };
	cout << s1.name << '\t' << s1.add.country << endl;*/

	
	// The following cannot be done, could be done only if name was char*
	//s2.name = "Samia Zaib";
	// The following can be done 
	//char* name = "Samia Zaib";
	//cout << name << endl;

	/*Student s2;
	strcpy(s2.name, "Samia Zaib");
	cout << s2.name;*/

	/*int *a = (int*)malloc(sizeof(int));
	*a = 5;
	cout << *a;*/

	//Student *s1 = (Student*)malloc(sizeof(Student)); //  Initializer don't work with pointer = { "Ali Zaib", 3.3, { "House 277, street 17", "Islamabad", "Pakistan" } };
	//strcpy(s1->name, "Ali Zaib");
	//strcpy(s1->add.streetAddress, "House 277, street 17");
	//strcpy(s1->add.country, "Pakistan");
	//cout << s1->name << '\t' << s1->add.country << endl;


	//Student *s1 = (Student*)malloc(sizeof(Student)); //  Initializer don't work with pointer = { "Ali Zaib", 3.3, { "House 277, street 17", "Islamabad", "Pakistan" } };
	//strcpy(s1->name, "Ali Zaib");
	//s1->gpa = 3.3;
	//strcpy(s1->add.streetAddress, "House 277, street 17");
	//strcpy(s1->add.country, "Pakistan");
	//PrintStudentInfo(*s1);
	//cout << (*s1).gpa; //dereference first, to use dot operator.

	/*int x;
	x = 'a';
	cout << x << endl;
	x = x * 256;
	cout << x << endl;
	x = x + 'b';
	cout << x << endl;*/

	Test t1;
	t1.name = "Ali Zaib";
	cout << sizeof(t1) << endl;
	cout << sizeof(char) << "\t" << sizeof(char*) << "\t" << sizeof(int) << "\t" << sizeof(int*);

}

void PrintStudentInfo(Student student) {	
	cout << endl;
	cout << "Name: " << student.name << endl;
	cout << "GPA: " << student.gpa << endl;
	cout << "Country: " << student.add.country << endl;
	cout << "--------------------------------\n";
	//try to change gpa and won't change inthe original
	student.gpa = 0;
}