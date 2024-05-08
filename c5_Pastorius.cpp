/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Assignment: 3
* Chapter 5
* Date: 9/24/2022
*/

#pragma warning(disable: 4996)
#include<iostream>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {

  int choice, arr[20], random;
  int occurrences[10] = { 0,0,0,0,0,0,0,0,0,0 };
  srand((unsigned) time(NULL));

  do {

    for (int i = 0; i < 20; i++) {
      random = 1 + (rand() % 10);
      arr[i] = random;
    }

    sort(arr, arr+20);

    for (int i = 0; i < 20; i++) {
      cout << "a[" << i << "] = "<< arr[i] <<endl;
    }

    for (int i = 0; i < 20; i++) {
      occurrences[arr[i] - 1]++;
    }

    cout << "N count: \n";
    for(int i = 0;i < 10; i++) {
      cout << i + 1 << " : "<< occurrences[i] << endl;
    }

    cout << "Try Again ? (1 = yes, 0 = exit)\n";
    cin >> choice;

  } while (choice == 1);
  return 0;
}
		

