#include "group.h"

using namespace std;

Group::Group(const std::wstring& name) : groupname(name), next_id(1) {}

Group::~Group() {
	deleteAllStudents();
}

void Group::addStudent(std::shared_ptr<Student>& newStudent) {
	newStudent->readFromConsole();
	newStudent->setID(next_id);
	next_id++;
	newStudent->setGroup(groupname);
	students.push_back(newStudent);
}

void Group::setGroupName(const std::wstring& name) {
	groupname = name;
	for (auto& student : students) {
		student->setGroup(groupname);
	}
}

const void Group::showAllStudents() {
	wcout << L"Group: " << groupname << endl;
	if (students.empty()) {
		wcout << L"Group is empty" << endl;
		return;
	}
	for (const auto& student : students) {
		student->writeToConsole();
		wcout << L"---------------------------" << endl;
	}
}

void Group::deleteAllStudents() {
	students.clear();
	next_id = 1;
	wcout << L"Group is cleared" << endl;
}

void Group::readStudentsFromFile(ifstream& inFile) {
	boost::archive::binary_iarchive ia(inFile);
	ia >> *this;
	wcout << L"Loaded group from file" << endl;		
}

void Group::writeStudentsToFile(ofstream& outFile) {
	boost::archive::binary_oarchive oa(outFile);
	oa << *this;
	wcout << L"Saved group to file" << endl;
}

const wstring Group::getGroupName() {
	return groupname;
}
