#include "students.h"

using namespace std;


const void Student::writeToConsole() {
	cout << "ID: " << student_id << endl
		<< "First name: " << first_name << endl
		<< "Second name: " << second_name << endl
		<< "Age: " << age << endl
		<< "Group: " << group << endl;
}

void Student::readFromConsole() {
	cout << "Enter first name: ";
	cin >> first_name;
	cout << "Enter second name: ";
	cin >> second_name;
	cout << "Enter age: ";
	cin >> age;
}

void Student::writeToFile(ofstream& outFile) {
	outFile << student_id << endl
		<< first_name << endl
		<< second_name << endl
		<< age << endl
		<< group << endl;
}

void Student::readFromFile(ifstream& inFile) {
	inFile >> student_id;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(inFile, first_name);
	getline(inFile, second_name);
	inFile >> age;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(inFile, group);
}

void Student::setID(int& id) {
	student_id = id;
}

void Student::setGroup(string& group_name) {
	group = group_name;
}

const int Student::getID() {
	return student_id;
}