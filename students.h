#pragma once
#include <string>
#include <iostream>
#include <fstream>



class Student {
private:
	int student_id;
	std::string first_name;
	std::string second_name;
	int age;
	std::string group;
public:
	Student() : student_id(0), age(0), first_name(""), second_name(""), group("") {}

	Student(int student_id, std::string& first_name, std::string& second_name, int age, std::string& group);

	const void writeToConsole();

	void readFromConsole();

	void writeToFile(std::ofstream& outFile);

	void readFromFile(std::ifstream& inFile);

	void setID(int& id);

	void setGroup(std::string& group_name);

	const int getID();
};