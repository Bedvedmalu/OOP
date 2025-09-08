#include <iostream>
#include <sstream>
#include <limits>
#include "students.h"
#include "group.h"

using namespace std;

int intInput(int minValue, int maxValue) {
	int value;
	cout << "Input action: ";
	while (true) {
		if ((cin >> value).good() && value >= minValue && value <= maxValue) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
		else {
			cout << "Incorrect data. Try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void mainMenu() {
	cout << "1. Add student to group" << endl;
	cout << "2. Show all student in group" << endl;
	cout << "3. Save group to file" << endl;
	cout << "4. Load group from file" << endl;
	cout << "5. Delete all students" << endl;
	cout << "6. Change group name" << endl;
	cout << "7. Exit" << endl;
}
int main() {
	Group group("AC-23-05");
	string filename;
	cout << "Current group: " << group.getGroupName() << endl;
	int choice;
	do {
		mainMenu();
		choice = intInput(1, 7);
		switch (choice) {
		case 1:
			cout << "ADD NEW STUDENT" << endl;
			group.addStudent();
			break;
		case 2:
			cout << "SHOW ALL STUDENTS" << endl;
			group.showAllStudents();
			break;
		case 3: {
			cout << "SAVE GROUP TO FILE" << endl;
			cout << "Enter file name: ";
			getline(cin, filename);
			filename += ".txt";
			ofstream inFile;
			inFile.open(filename);
			group.writeStudentsToFile(inFile);
			break;
		}
		case 4: {
			cout << "LOAD GROUP FROM FILE" << endl;
			cout << "Enter file name: ";
			getline(cin, filename);
			filename += ".txt";
			ifstream outFile;
			outFile.open(filename);
			if (!outFile.is_open()) {
				cout << "Cannot open file with name: " << filename << endl;
				outFile.close();
				break;
			}
			group.readStudentsFromFile(outFile);
			break;
		}
		case 5:
			cout << "DELETING ALL STUDENTS" << endl;
			group.deleteAllStudents();
			cout << "Successfully" << endl;
			break;
		case 6:
			cout << "CHANGE GROUP NAME" << endl;
			string newName;
			cout << "Current new group name: " << group.getGroupName() << endl;
			cout << "Enter new group name: ";
			getline(cin, newName);
			group.setGroupName(newName);
			cout << "Successfully" << endl;
			break;
		}
	} while (choice < 7);
	return 0;
}