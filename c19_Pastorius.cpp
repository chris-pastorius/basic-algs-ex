/*
* Author: Chris Pastorius
* CIT-245-Z01
* Chapter 19
* Date: 11/28/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main() {

	map<string, int> ssns;

	ssns["Paul Brown"] = 123456790;
	ssns["Mary Smith"] = 123456791;
	ssns["John Smith"] = 123456789;
	ssns["Lisa Brown"] = 123456792;

	map<string, int>::iterator itr;

	cout << "iterating through list... " << endl;

	for (itr = ssns.begin(); itr != ssns.end(); ++itr) {
		cout << itr->second << ':' << itr->first << endl;
	}

	int i = 0;
	string name;

	while (i < 2) {

		cout << "\nEnter a name:";

		getline(cin, name);

		if (ssns[name]) {
			cout << name << " found " << ssns[name] << endl;
		} else {
			cout << name << " not found" << endl;
		}

		i++;
	}

	cout << "Press any key to continue....\n";

	return 0;
}
