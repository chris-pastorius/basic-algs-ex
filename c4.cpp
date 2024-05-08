/*
Author: Chris Pastorius
Class: CIT-245-Z01
Assignment: 2
Chapters 3 & 4
Date: 08/30/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int gcd(int a, int b);
// Gets the lowest common denominator
void reduce(int& num, int& den);
// Reduces fraction to lowest terms

int main() {

	int numerator, denominator, choice;

	cout << "This program takes a numerator and denominator and reduces to lowest terms\n";

	do {
		cout << "\nEnter the numerator\n";
		cin >> numerator;

		cout << "Enter the denominator\n";
		cin >> denominator;

		int g = gcd(numerator, denominator);
		cout << "	greatest common denominator is " << g << endl;

		reduce(numerator, denominator);
		cout << "	your fraction reduced is " << numerator << "/" << denominator << endl;

		cout << "Try again? (1 = yes, 0 = exit)\n";
		cin >> choice;
	} while (choice == 1);

	system("pause");
	return(0);
}

int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void reduce(int& num, int& den) {
	int q = gcd(num, den);
	num /= q;
	den /= q;
}