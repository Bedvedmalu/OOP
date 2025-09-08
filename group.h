#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "students.h""

class Group {
private:
	std::string groupname;
	std::vector<Student*> students;
	int next_id;
public:
	Group(const std::string& groupname = "");

	~Group();

	void addStudent();

	const void showAllStudents();

	void readStudentsFromFile(std::ifstream& inFile);

	void writeStudentsToFile(std::ofstream& outFile);

	void deleteAllStudents();

	void setGroupName(const std::string& name);

	const std::string getGroupName();

};