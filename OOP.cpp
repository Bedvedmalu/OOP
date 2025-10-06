#include <iostream>
#include <sstream>
#include <limits>
#include "students.h"
#include "group.h"
#include <boost/serialization/access.hpp>

using namespace std;

BOOST_CLASS_EXPORT_IMPLEMENT(Student)
BOOST_CLASS_EXPORT_IMPLEMENT(GroupLeader)

int intInput(int minValue, int maxValue) {
	int value;
	wcout << L"Input action: ";
	while (true) {
		if ((wcin >> value).good() && value >= minValue && value <= maxValue) {
			return value;
		}
		else {
			cout << "Incorrect data. Try again" << endl;
		}
	}
}

void mainMenu() {
	wcout << L"1. Add student to group" << endl;
	wcout << L"2. Add group leader" << endl;
	wcout << L"3. Show all student in group" << endl;
	wcout << L"4. Save group to file" << endl;
	wcout << L"5. Load group from file" << endl;
	wcout << L"6. Delete all students" << endl;
	wcout << L"7. Change group name" << endl;
	wcout << L"8. Exit" << endl;
}
int main() {
	locale ru_locale("rus_rus.866");
	locale::global(ru_locale);
	wcin.imbue(ru_locale);
	wcout.imbue(ru_locale);
	Group group(L"AC-23-05");
	wstring filename;
	wcout << L"Current group: " << group.getGroupName() << endl;
	int choice;
	do {
		mainMenu();
		choice = intInput(1, 7);
		switch (choice) {
		case 1: {
			wcout << L"ADD NEW STUDENT" << endl;
			auto newStudent = make_shared<Student>();
			group.addStudent(newStudent);
			break;
		}
		case 2: {
			wcout << L"ADD GROUP LEADER" << endl;
			auto newStudent = make_shared<Student>();
			group.addStudent(newStudent);
			break;
		}
		case 3:
			wcout << L"SHOW ALL STUDENTS" << endl;
			group.showAllStudents();
			break;
		case 4: {
			wcout << L"SAVE GROUP TO FILE" << endl;
			wcout << L"Enter file name: ";
			wcin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(wcin, filename);
			filename += L".txt";
			ofstream inFile(filename, ios::binary);
			group.writeStudentsToFile(inFile);
			break;
		}
		case 5: {
			wcout << L"LOAD GROUP FROM FILE" << endl;
			wcout << L"Enter file name: ";
			wcin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(wcin, filename);
			filename += L".txt";
			ifstream outFile(filename, ios::binary);
			if (!outFile.is_open()) {
				wcout << L"Cannot open file with name: " << filename << endl;
				outFile.close();
				break;
			}
			group.readStudentsFromFile(outFile);
			break;
		}
		case 6:
			wcout << L"DELETING ALL STUDENTS" << endl;
			group.deleteAllStudents();
			wcout << L"Successfully" << endl;
			break;
		case 7:
			wcout << L"CHANGE GROUP NAME" << endl;
			wstring newName;
			wcout << L"Current new group name: " << group.getGroupName() << endl;
			wcout << L"Enter new group name: ";
			getline(wcin, newName);
			group.setGroupName(newName);
			wcout << L"Successfully" << endl;
			break;
		}
	} while (choice < 8);
	return 0;
}