/* 
Author: Chris Pastorius
Class: CIT-245-Z01
Assignment: 1
Chapters 1 & 2
Date: 08/29/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

int main()
{ 
    double guess, r, intitialGuess, input, approx;

    cout << "Enter a number and I will apply the Babylonian square root algorithm\n"
         << "until I am within .001 of the correct answer.\n";
    cin >> input;

    cout << "You entered " << input << endl;

    guess = input / 2;

    do {
        intitialGuess = guess;
        r = input / guess;
        guess = (guess + r) / 2;
        cout << "guessing " << intitialGuess << endl;
    } while (intitialGuess - guess > .001 * intitialGuess);

    approx = intitialGuess * intitialGuess;

    cout << "The Babylonian algorithm gives " << intitialGuess << endl
         << "Checking: " << intitialGuess << " * " << intitialGuess << " = " << approx << endl;
   
    system("pause");
    return 0;
}
