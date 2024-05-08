/*
* Author: Chris Pastorius
* Class : CIT - 245 - Z01
* Chapter: 9
* Date : 10 / 4 / 2022
*/


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<stack>

using namespace std;

int main() {

	stack<char> stack;
	int go = 1, i = 0;

	cout << "This program reverses a string using the STL stack." << endl;
	char* string = (char*)malloc(80);

	while (go == 1) {

		cout << "Enter your string of less than 80 characters followed by an ENTER" << endl;
		cin.getline(string, 81, '\n');
		i = 0;

		while (string[i] != '\0') {

			stack.push(string[i]);
			i++;

		}

		i = 0;

		while (!stack.empty()) {

			string[i] = stack.top();
			stack.pop();
			i++;

		}

		cout << string << endl;                                            
		cout << "Enter another? 1 = continue. Anything else to stop" << endl;
		cin >> go;
		getchar();

	}
	free(string);             
	return 0;


}