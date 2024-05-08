/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Assignment: 3
* Chapter 6
* Date: 9/18/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

class player {
public:
	player(string n, string pass, int xp, pair<int, int> pos) {
		name = n;
		password = pass;
		experience = xp;
		position = pos;
	}
	void setName(string name) { this->name = name; }
	string getName() { return name; }

	void setPassword(string pass) { password = pass; }
	string getPassword() { return password; }

	void setExperience(int xp) { experience = xp; }
	int getExperience() { return experience; }

	void setPosition(pair<int, int> p) { position = p; }
	pair<int, int> getPosition() { return position; }

	void setInventory(string* inventory);
	string* getInventory() { return inventory; }

	void display();

private:
	string name;
	string password;
	int experience;
	string inventory[4];
	pair<int, int> position;
};

void player::setInventory(string* inventory) {
	for (int i = 0; i < 4; ++i) {
		this->inventory[i] = inventory[i];
	}
}

void player::display() {
	cout << "\nPlayer Info -" << endl;
	cout << "Name: " << name << endl;
	cout << "Password: " << password << endl;
	cout << "Experience: " << experience << endl;
	cout << "Inventory:" << endl;
	cout << "Position: " << position.first << " , " << position.second << endl;
	for (auto x : inventory) {
		cout << x << endl;
	}
}

int main() {

	cout << "This program generates three player objects and displays them.";

	player p1("Nematocyst", "obfuscator", 1098, { 55689, 76453 });
	string inventory[4];
	inventory[0] = " sword";
	inventory[1] = " shield";
	inventory[2] = " food";
	inventory[3] = " potion";
	cout << endl;
	p1.setInventory(inventory);

	player p2("Omphaloskeps", "obstreperous", 11456, { 12, 5108 });
	inventory[0] = " sword of magic";
	inventory[1] = " shield of power";
	inventory[2] = " mana potion";
	inventory[3] = " anti-fire potion";
	cout << endl;
	p2.setInventory(inventory);

	player p3("Tokamakfusion", "toroid", 15678, { 99, 108 });
	inventory[0] = " axe of damage";
	inventory[1] = " shield of warding";
	inventory[2] = " strength potion";
	inventory[3] = " healing potion";
	cout << endl;
	p3.setInventory(inventory);

	p1.display();
	p2.display();
	p3.display();

	cout << "Press any key to continue.. " << endl;
	return 0;
}

