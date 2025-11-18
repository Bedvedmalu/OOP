#ifndef GROUP_H
#define GROUP_H

#pragma once

#include "student.h"
#include "groupleader.h"
#include <fstream>
#include <QString>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/access.hpp>





class Group
{
private:
    std::string groupname;
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
    Group(const std::string& groupname = "");

    ~Group();

    void readStudentsFromFile(std::string& filePath);

    void deleteAllStudents();

    void writeStudentsToFile(std::string& filePath);

    std::vector<std::shared_ptr<Student>>& getStudents();

    void paint(QPainter* painter, const QRect& area) const;

    void deleteStudent(int id);

    void editStudent(int id, std::string fname, std::string sname, int stage, std::string pos, std::string number);

    std::string getName();

    void addStudent(const std::shared_ptr<Student>& newStudent);

    int getNextId();
};

#endif // GROUP_H
