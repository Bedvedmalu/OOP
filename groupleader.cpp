#include "groupleader.h"

using namespace std;

GroupLeader::GroupLeader() : Student() {}

GroupLeader::GroupLeader(int id, std::wstring& fname, std::wstring& sname, int age, std::wstring& grp, std::wstring& pos, std::wstring& phone) : Student(id, fname, sname, age, grp), position(pos), phone_number(phone){}

void GroupLeader::readFromConsole() {
	Student::readFromConsole();
	wcout << L"Enter position: ";
	wcin >> position;
	wcout << L"Enter phone number: ";
	wcin >> phone_number;
}

void GroupLeader::writeToConsole() const {
	Student::writeToConsole();
	wcout << L"Position: " << position << endl;
	wcout << L"Phone number: " << phone_number << endl;
}


