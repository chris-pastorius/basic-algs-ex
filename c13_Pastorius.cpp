/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Chapter 13
* Date: 10/26/2022
*/

#pragma warning(disable: 4996)
#include<iostream>
#include<cmath>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

static int count = 0;

void hanoi(int p, char from, char to, char a) {

	if (p == 0) {
		return;
	}
	if (p == 1) {
		cout << "from " << from << " to " << to << endl;
		::count++;
		return;
	}
	hanoi(p - 1, from, a, to);
	cout << "from " << from << " to " << to << endl;
	::count++;
	hanoi(p - 1, a, to, from);
}

int main() {

	int number, choice;

	do {
		cout << "Enter no of disks: ";
		cin >> number;
		cout << "source 1 target 2 temporary 3" << endl;
		hanoi(number, '1', '2', '3');
		cout << "2 to the power " << number << " = " << pow(2, number) << endl;
		cout << "Number of moves: " << :: count << endl;
		cout << "Continue? (1=yes 0=no)" << endl;
		cin >> choice;
	} while (choice == 1);

	return 0;
}