#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <string>
#include <QPainter>
#include <QRect>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/shared_ptr.hpp>

class Student
{
private:
    int student_id;
    std::string first_name;
    std::string second_name;
    int age;
    std::string group;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & student_id;
        ar & first_name;
        ar & second_name;
        ar & age;
        ar & group;
    }

public:
    Student() : student_id(0), first_name(), second_name(), age(0) , group() {}
    Student(int student_id, const std::string& first_name, const std::string& second_name, int age, const std::string& group);
    virtual ~Student();

    std::string getFName() const;
    std::string getSName() const;
    int getAge() const;
    int getId() const;

    virtual void paint(QPainter* painter, const QRect& rect, int rowHeight, int totalWidth, int& current_Y);
};

BOOST_SERIALIZATION_SHARED_PTR(Student)
BOOST_CLASS_EXPORT_KEY(Student)
#endif // STUDENT_H
