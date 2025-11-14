#ifndef GROUPLEADER_H
#define GROUPLEADER_H

#pragma once

#include <string>
#include <QPainter>
#include <QRect>
#include "student.h"

class GroupLeader : public Student
{
private:
    std::string position;
    std::string phone_number;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & boost::serialization::base_object<Student>(*this);
        ar & position;
        ar & phone_number;
    }

public:
    GroupLeader();
    GroupLeader(int student_id, const std::string& first_name, const std::string& second_name,
                int age, const std::string& group, const std::string& position, const std::string& phone_number);

    std::string getPosition() const;
    std::string getPhoneNumber() const;

    void paint(QPainter* painter, const QRect& rect, int rowHeight, int totalWidth, int& current_Y) override;
};

BOOST_SERIALIZATION_SHARED_PTR(GroupLeader)
BOOST_CLASS_EXPORT_KEY(GroupLeader)
#endif // GROUPLEADER_H
