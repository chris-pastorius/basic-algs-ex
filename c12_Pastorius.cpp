/*
* Author: Chris Pastorius
* Class : CIT - 245 - Z01
* Chapter: 12
* Date : 10 / 14 / 2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>

using namespace std;

int main() {

	string string;

	fstream inStream("advice.txt");

	if (!inStream.fail()) {
		cout << "Found advice file." << endl;
		cout << "Old advice:" << endl;

		while (getline(inStream, string)) {
			cout << string << endl;
		}

		inStream.close();
		inStream.open("advice.txt", fstream::out);

		cout << "Enter your phrase for the next user: " << endl;

		while (getline(cin, string)) {
			inStream << string << endl;
			break;
		}

		inStream.close();
	
	} else {
		cout << "Could not open advice file" << endl;
		cout << "Assumption: first run - creating a new file ..." << endl;

		inStream.open("advice.txt", fstream::out);
		cout << "Enter your phrase for the next user: " << endl;

		while (getline(cin, string)) {
			inStream << string << endl;
			break;
		}
		inStream.close();
	}
	return 0;
}