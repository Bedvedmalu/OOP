#include "group.h"

using namespace std;

Group::Group(const std::string& name) : groupname(name), next_id(1) {}

Group::~Group() {
	deleteAllStudents();
}

void Group::setGroupName(const std::string& name) {
	groupname = name;
	for (Student* student : students) {
		student->setGroup(groupname);
	}
}

void Group::addStudent() {
	Student* newStudent = new Student();
	newStudent->readFromConsole();
	newStudent->setID(next_id);
	next_id++;
	newStudent->setGroup(groupname);
	students.push_back(newStudent);
}

const void Group::showAllStudents() {
	cout << "Group: " << groupname << endl;
	if (students.size() == 0) {
		cout << "Group is empty" << endl;
	}
	for (Student* student : students) {
		student->writeToConsole();
		cout << "---------------------------" << endl;
	}
}

void Group::deleteAllStudents() {
	for (Student* student : students) {
		delete student;
	}
	students.clear();
	next_id = 1;
	cout << "Group is cleared" << endl;
}

void Group::readStudentsFromFile(ifstream& inFile) {
	getline(inFile, groupname);
	int max_id = 0;
	int studentCount;
	inFile >> studentCount;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < studentCount; ++i) {
		Student* student = new Student();
		student->readFromFile(inFile);
		student->setGroup(groupname);

		if (!inFile.fail()) {
			students.push_back(student);
			if (student->getID() > max_id) {
				max_id = student->getID();
			}
		}
		else {
			delete student;
			cout << "Error reading student data from file" << endl;
			break;
		}
	}
	next_id = max_id + 1;
	inFile.close();
	cout << "Successfully readed data from file" << endl;
}

void Group::writeStudentsToFile(ofstream& outFile) {
	outFile << groupname << endl;
	outFile << students.size() << endl;
	for (Student* student : students) {
		student->writeToFile(outFile);
	}
	outFile.close();
	cout << "Successfully writed data to file" << endl;
}

const string Group::getGroupName() {
	return groupname;
}