/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Assignment: Chapter 7
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <iostream>

using namespace std;

class Counter {
	private: 
		int count;
	public: 
		static int total;
		Counter();
		Counter(int c);

		void setCount(int c);
		int getCount() const;

		void inc();
		void dec();
		void display();
};

Counter::Counter() {
	count = 0;
}

Counter::Counter(int c) {
	count = c;
}

void Counter::setCount(int c) {
	count = c;
}
int Counter::getCount() const {
	return count;
}

void Counter::inc() {
	count++;
	total++;
}
void Counter::dec() {
	count--;
	total++;
}
void Counter::display() {
	cout << "Current count: " << count << endl;
}

int Counter::total = 0;

int main() {

	Counter c1;
	Counter c2(200);

	cout << "Current state of C1 (created with the default constructor)" << endl;
	c1.display();

	cout << "total increments and decrements " << Counter::total << endl;

	cout << "Current state of C2 (created as C2(200))" << endl;
	c2.display();

	cout << "total increments and decrements " << Counter::total << endl;

	cout << "Current state of C1 after 85 inc()" << endl;

	for (int i = 0; i < 85; i++) {
		c1.inc();
	}
	c1.display();

	cout << "total increments and decrements " << Counter::total << endl;

	cout << "Current state of C2 after 242 dec()" << endl;

	for (int i = 0; i < 242; i++) {
		c2.dec();
	}
	c2.display();

	cout << "total increments and decrements " << Counter::total << endl;

	return 0;
}