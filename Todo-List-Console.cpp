#include <iostream>
#include <ctime>
#include <list>
using namespace std;


class TodoList
{
private:
	int id;
	string todo;
	bool isComplete;
public:
	TodoList() : id(0), todo(""), isComplete(false) {
		// generateing a  random number between 1 to 100;
		id = rand() % 100 + 1;
	}
	~TodoList() = default;

	void createTodo(string description) { todo = description; }
	int getId() { return id; }
	string getTodo() { return todo; }
	bool getIsComplete() { return isComplete; }
	void setComplete() { isComplete = true; }
};

int main() {
	srand((unsigned)time(NULL));
	// variables
	bool exit = false;
	string option = "";
	string description = "";
	int id;
	// List
	list<TodoList> todoItems;
	list<TodoList>::iterator i;
	todoItems.clear();

	//TodoList demo;
	//demo.createTodo("Drink-Water");
	//todoItems.push_back(demo);

	while (exit != true) {
		TodoList items;
		system("cls");

		cout << "\t TODO LIST MAKER" << endl;
		cout << endl;

		for (i = todoItems.begin(); i != todoItems.end(); i++) {
			cout << i->getId() << " | " << i->getTodo() << " | ";
			if (i->getIsComplete() == 1) {
				cout << "done";
			}
			else {
				cout << "not done";
			}
			cout << endl;
		}
		cout << endl;

		cout << "[a]dd todo\n[c]omplete todo\n[e]xit\noption: ";
		cin >> option;

		if (option == "a" || option == "A") {
			cout << "enter input without using space character\neg: drink-water\n";
			cout << "description of todo: ";
			cin >> description;
			items.createTodo(description);
			todoItems.push_back(items);
		}
		else if(option == "c" || option == "C") {
			cout << "Enter the id of todo: ";
			cin >> id;
			for (i = todoItems.begin(); i != todoItems.end(); i++) {
				if (i->getId() == id) {
					i->setComplete();
				}
			}
		}
		else if (option == "e" || option == "E") {
			exit = true;
		}
	}
	cout << "exited succesfully";
	return 0;
}
