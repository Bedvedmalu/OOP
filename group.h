#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "groupleader.h"
#include "students.h"
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

class Group {
private:
	std::wstring groupname;
	std::vector<std::shared_ptr<Student>> students;
	int next_id;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& groupname;
		ar& next_id;
		ar& students;
	}
public:
	Group(const std::wstring& groupname = L"");

	~Group();

	void addStudent();

	const void showAllStudents();

	void readStudentsFromFile(std::ifstream& inFile);

	void writeStudentsToFile(std::ofstream& outFile);

	void addGroupLeader();

	void deleteAllStudents();

	void setGroupName(const std::wstring& name);

	const std::wstring getGroupName();

};