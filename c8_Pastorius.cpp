/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Assignment: Chapter 8	
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<cmath>
#include<iostream>

using namespace std;

class Money {
	private:
		double money;
	public:
		Money() {};
		Money(double a) {
			money = a;
		}
		friend ostream& operator << (ostream& out, const Money& m);
		friend istream& operator >> (istream& in, Money& m);
		friend Money operator %(const Money& m1, const Money& m2);
		friend Money operator +(const Money& m1, const Money& m2);
		friend Money operator -(const Money& m1, const Money& m2);
		friend bool operator <(const Money& m1, const Money& m2);
		friend bool operator >(const Money& m1, const Money& m2);
		double getMoney() const { return money; }
};

ostream& operator <<(ostream& out, const Money& m) {
	out << m.getMoney();
	return out;
}

istream& operator >> (istream& in, Money& m) {
	in >> m.money;
	return in;
}

Money operator+(const Money& m1, const Money& m2) {
	return Money(m1.money + m2.money);
}

Money operator-(const Money& m1, const Money& m2) {
	return Money(m1.money - m2.money);
}

Money operator%(const Money& m1, const Money& k) {
	return Money(m1.money * k.money / 100);
}

bool operator<(const Money& m1, const Money& m2) {
	if (m1.money < m2.money) return true;
	else return false;
}

bool operator>(const Money& m1, const Money& m2) {
	if (m1.money > m2.money) return true;
	else return false;
}

int main() {

	Money yourmoney, mymoney;
	cout << "Enter amount of your money: ";
	cin >> yourmoney;
	cout << "Enter amount of my money: ";
	cin >> mymoney;

	cout << "One of us is richer." << endl;
	Money m1(yourmoney), m2(mymoney);
	if (m1 > m2) {
		cout << "You have more money than me" << endl;
	} else {
		cout << "You have less money than me" << endl;
	}

	Money k(10);
	cout << k.getMoney() << "% of your money is $$" << (m1 % k).getMoney() << endl;
	
	Money sum = m1 + m2;
	cout << "$" << m1.getMoney() << " + " << "$" << m2.getMoney() << " equals "
		<< sum.getMoney() << "$" << endl;
	
	Money difference = m1 - m2;
	cout << "$" << m1.getMoney() << " - " << "$" << m2.getMoney() << " equals " 
		<< difference.getMoney() << "$" << endl;

	return 0;
}