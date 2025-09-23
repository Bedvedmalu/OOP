#include "students.h"

using namespace std;


Student::Student(int id, wstring& fname, wstring& sname, int age, wstring& grp) : student_id(id), first_name(fname), second_name(sname), age(age), group(grp) {}

Student::~Student() {}

void Student::writeToConsole() const{
	wcout << L"ID: " << student_id << endl
		<< L"First name: " << first_name << endl
		<< L"Second name: " << second_name << endl
		<< L"Age: " << age << endl
		<< L"Group: " << group << endl;
}

void Student::readFromConsole() {
	wcout << L"Enter first name: ";
	wcin >> first_name;
	wcout << L"Enter second name: ";
	wcin >> second_name;
	wcout << L"Enter age: ";
	wcin >> age;
}

void Student::setID(int id) {
	student_id = id;
}

void Student::setGroup(wstring& group_name) {
	group = group_name;
}

const int Student::getID() {
	return student_id;
}
