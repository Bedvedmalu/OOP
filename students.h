#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>



class Student {
protected:
	int student_id;
	std::wstring first_name;
	std::wstring second_name;
	int age;
	std::wstring group;
public:
	Student() : student_id(0), age(0), first_name(L""), second_name(L""), group(L"") {}

	Student(int student_id, std::wstring& first_name, std::wstring& second_name, int age, std::wstring& group);

	virtual ~Student();

	virtual void writeToConsole() const;

	virtual void readFromConsole();

	void setID(int id);

	void setGroup(std::wstring& group_name);

	const int getID();

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& student_id;
		ar& first_name;
		ar& second_name;
		ar& age;
		ar& group;
	}
};

BOOST_CLASS_EXPORT_KEY(Student)