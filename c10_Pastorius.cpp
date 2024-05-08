/*
* Author: Chris Pastorius
* Class : CIT - 245 - Z01
* Chapter: 9=10
* Date : 10 / 8 / 2022
*/


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

class WrapArrayDeep {
	public:
		WrapArrayDeep();
		WrapArrayDeep(const WrapArrayDeep& wad);
		~WrapArrayDeep();

		void printArray();
		void alterArray();

		int getCapacity() const { return capacity; }

		WrapArrayDeep& operator =(const WrapArrayDeep& wad);
	private:
		char* pch;
		int capacity;
};

class WrapArrayShallow {
	public:
		WrapArrayShallow();
		WrapArrayShallow(const WrapArrayShallow& was);
		~WrapArrayShallow();

		void printArray();
		void alterArray();

		int getCapacity() { return capacity; }
	private:
		char* pca;
		int capacity;
};

// Member functions for WrapArrayDeep

WrapArrayDeep::WrapArrayDeep() {
	capacity = 5;
	pch = new char[capacity];

	for (int i = 0; i < capacity; i++)
		*(pch + i) = (97 + i);
} 

WrapArrayDeep::WrapArrayDeep(const WrapArrayDeep& wad) :capacity(wad.getCapacity()) {
	pch = new char[capacity];

	for (int i = 0; i < capacity; i++) {
		*(pch + i) = wad.pch[i];
	}
}

WrapArrayDeep::~WrapArrayDeep() {
	cout << "calling destructor for WrapArrayDeep\n";
	delete[] pch;
}

void WrapArrayDeep::printArray() {
	for (int i = 0; i < capacity; i++)
		cout << pch[i] << " ";

	cout << endl;
}

void WrapArrayDeep::alterArray() {
	for (int i = 0; i < capacity; i++)
		*(pch + i) = (123 + i);
}

WrapArrayDeep& WrapArrayDeep::operator =(const WrapArrayDeep& wad) {
	if (capacity != wad.capacity) {
		delete[] pch;
		pch = new char[wad.capacity];
	}

	capacity = wad.capacity;
	for (int i = 0; i < capacity; i++)
		pch[i] = wad.pch[i];

	return *this;
}

// Member functions for WrapArrayShallow

WrapArrayShallow::WrapArrayShallow() {
	capacity = 5;
	pca = new char[capacity];

	for (int i = 0; i < capacity; i++)
		pca[i] = (97 + i);
} 

WrapArrayShallow::WrapArrayShallow(const WrapArrayShallow& was) {
	capacity = 5;
	pca = was.pca;
}

WrapArrayShallow::~WrapArrayShallow() {
	cout << "calling destructor for WrapArrayShallow\n";
	delete[] pca;
} 

void WrapArrayShallow::printArray() {
	for (int i = 0; i < capacity; i++)
		cout << *(pca + i) << " ";

	cout << endl;
} 

void WrapArrayShallow::alterArray() {
	for (int i = 0; i < capacity; i++)
		pca[i] = (123 + i);
}

int main() {

	// Part 1

	int i = 7;
	int* pi;
	pi = &i;

	cout << "This program section uses three variables" << endl
		<< "i = " << i << ", pi a pointer to i and ppi a pointer to pi" << endl
		<< "\npi = " << pi << endl << "dereference pi = " << *pi << endl
		<< "address of pi = " << &pi << endl << "address of i = " << &i << endl;

	int** ppi;
	ppi = &pi;

	cout << "\nppi = " << ppi << endl << "deference of ppi = " << *ppi << endl
		 << "address of ppi = " << &ppi << endl << "double dereference of ppi = "
		 << **ppi << endl << endl;

	// Part 2 

	cout << "This section instantiates a wrapper class for a dynamic array of 5 elements" << endl;

	WrapArrayDeep wad1, *wad2;

	cout << "WrapArrayDeep 1" << endl;

	wad1.printArray();
	wad2 = new WrapArrayDeep(wad1);

	cout << "WrapArrayDeep 2 created using the copy constructor on 1" << endl;

	wad2->printArray();
	wad1.alterArray();

	cout << "after changing the contents of WrapArrayDeep1, 1 and 3 = " << endl;

	wad1.printArray();
	wad2->printArray();

	WrapArrayShallow was1, *was2;

	cout << endl << "Now doing the same thing with WrapArrayShallow" << endl << endl
		 << "WrapArrayShallow 1" << endl;
	was1.printArray();
	was2 = new WrapArrayShallow(was1);

	cout << "WrapArrayShallow 2 created using the copy constructor on 1" << endl;
	was2->printArray();
	was1.alterArray();

	cout << "after changing the contents of WrapArrayShallow 1, 1 and 3 = " << endl;
	was1.printArray();

	was2->printArray();

	cout << endl;

	delete wad2;

	return 0;
}