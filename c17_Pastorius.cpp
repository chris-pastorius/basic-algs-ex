/*
* Author: Chris Pastorius
* Class: CIT-245-Z01
* Chapter 17
* Date: 11/13/2022
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <iostream>

using namespace std;

class node {

public:

	string name;
	node* next;
	node* prev;

};

class linkedList {

public:

	linkedList() : top(NULL), end(NULL) {}

	bool empty(){
		return top == NULL;
	}

	node* getTop() {
		return top;
	}

	void setTop(node* n) {
		top = n;
	}

	node* getEnd() {
		return end;
	}

	void setEnd(node* n) {
		end = n;
	}

	void add(string);

	int menu();

	void remove(string);

	~linkedList();

	void reversePrint();

	friend ostream& operator << (ostream&, const linkedList&);

private:

	node* top;
	node* end;

};

int main() {

	linkedList l;

	cout << l.empty() << endl;

	int option = 0;

	string s;

	bool go = true;

	while (go) {

		option = l.menu();

		switch (option) {

		case 1:
			cout << "enter a name: ";
			cin >> s;

			l.add(s);

			break;
		case 2:
			cout << "enter name to be deleted: ";
			cin >> s;

			l.remove(s);

			break;
		case 3:
			cout << l;

			break;
		case 4:
			l.reversePrint();

			break;
		case 5:
			cout << "exiting" << endl;
			go = false;

			break;
		}
	}

	return 0;
}

void linkedList::remove(string s) {

	bool found = false;

	node* curr = getTop();

	while (curr != NULL) {

		if (curr->name == s) {

			found = true;

			if (getTop() == getEnd()) {

				setTop(NULL);
				setEnd(NULL);

			} else if (curr->prev == NULL) {

				setTop(curr->next);

				curr->next->prev = NULL;

			} else {

				if (curr->next == NULL) {

					setEnd(curr->prev);

					curr->prev->next = curr->next;
				} else {

					curr->prev->next = curr->next;

					curr->next->prev = curr->prev;
				}
			}

			delete(curr);
		}

		if (!found) {
			curr = curr->next;
		} else {
			curr = NULL;
		}
	}

	if (found) {
		cout << "Deleted " << s << endl;
	} else {
		cout << s << " Not Found " << endl;
	}
}

void linkedList::add(string s) {

	node* n = new node();

	n->name = s;

	n->next = NULL;

	n->prev = NULL;

	if (empty()) {

		setTop(n);

		setEnd(n);

	} else if (getTop()->name > s) {

		n->next = getTop();

		getTop()->prev = n;

		setTop(n);
	} else {

		node* curr = getTop();

		while (curr != NULL) {

			if (curr->name > s) {
				break;
			}

			curr = curr->next;
		}

		if (curr != NULL) {

			n->next = curr;

			curr->prev->next = n;

			n->prev = curr->prev;

			curr->prev = n;
		} else if (curr == NULL) {

			getEnd()->next = n;

			n->prev = getEnd();

			setEnd(getEnd()->next);
		}
	}
}

ostream& operator << (ostream& os, const linkedList& ll) {

	node* n = ll.top;

	if (n == NULL) {

		cout << "List is empty." << endl;

	} else {

		while (n != NULL) {

			os << n->name << endl;

			n = n->next;
		}
	}
	return os;
}

linkedList::~linkedList() {

	cout << "~linkedList called." << endl;

	node* curr = getTop(), * del;

	while (curr != NULL) {

		del = curr;

		curr = curr->next;

		delete(del);

	}
}

int linkedList::menu() {

	int choice = 0;

	while (choice < 1 || choice > 5) {

		cout << "\nEnter your choice" << endl;

		cout << " 1. Add a name." << endl;

		cout << " 2. Delete a name." << endl;

		cout << " 3. Show list." << endl;

		cout << " 4. Show reverse list. " << endl;

		cout << " 5. EXIT " << endl;

		cin >> choice;

	}

	return choice;
}

void linkedList::reversePrint() {

	node* n = getEnd();

	if (n == NULL) {
		cout << "List is empty." << endl;
	} else {

		while (n != NULL) {

			cout << n->name << endl;

			n = n->prev;

		}
	}
}