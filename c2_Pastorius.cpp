/*
Author: Chris Pastorius
Class: CIT-245-Z01
Assignment: 2
Chapters 1 & 2
Date: 08/29/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<math.h>
using namespace std;

int main() {

	const double PI = 3.141592;
	const double WATER_WEIGHT = 62.4;
	double radius, weight, bforce, volume;
	int choice;

	cout << "This program computes Buoyant Force in water given sphere radius.\n"
		 << "Based on the weight of the sphere, it determines whether the sphere floats or sinks.\n\n";

	do {
		cout << "Enter the radius of the sphere.\n";
		cin >> radius;
		cout << "You entered " << radius << "\n\n";

		cout << "Enter the weight of the sphere.\n";
		cin >> weight;
		cout << "You entered " << weight << endl;

		volume = (4.0 / 3.0) * PI * pow(radius, 3);
		bforce = volume * WATER_WEIGHT;

		cout << "Buoyant Force : " << bforce << endl;

		if (bforce >= weight) {
			cout << "Egads, it floats!\n";
		}
		else {
			cout << "It sinks ...\n";
		}

		cout << "Recalculate? (1 = yes, 0 = exit)\n";
		cin >> choice;

	} while (choice == 1);

	system("pause");
	return 0;
}