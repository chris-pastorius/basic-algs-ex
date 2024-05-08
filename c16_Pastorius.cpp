/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Chapter 16
* Date: 11/6/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

template <class T>

int binSearch(T* data, T item, int size) {

	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high) {

		mid = (low + high) / 2;

		if (data[mid] == item) {
			return mid;
		} else if (data[mid] < item) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {

	int array[] = { 0, 1, 1, 2, 3, 5, 6, 13, 21, 32, 55 };
	int numSize = 11;
	int index;
	int strSize = 4;

	string strArray[] = { "head", "knees", "shoulders", "toes" };

	cout << "Integer test array contains: " << endl;

	for (int i = 0; i < numSize; i++) {
		cout << array[i] << " ";
	}

	cout << endl;

	for (int i = -1; i < 8; i++) {

		index = binSearch<int>(array, i, numSize);

		cout << i;

		if (index != -1) {
			cout << " is at index " << index << endl;
		} else {
			cout << " is not in the array." << endl;
		}
	}

	cout << endl << "String test array contains: " << endl;

	for (int i = 0; i < strSize; i++) {
		cout << strArray[i] << " ";
	}

	cout << endl;

	index = binSearch<string>(strArray, "elbows", strSize);

	if (index != -1) {
		cout << "elbows is at index " << index << endl;
	} else {
		cout << "elbows is not in the array" << endl;
	}

	index = binSearch<string>(strArray, "knees", strSize);

	if (index != -1) {
		cout << "knees is at index " << index << endl;
	} else {
		cout << "knees is not in the array" << endl;
	}

	return 0;
}