#include "student.h"

using namespace std;

Student::Student(int id, const std::string& fname, const std::string& sname, int age, const std::string& grp)
    : student_id(id), first_name(fname), second_name(sname), age(age), group(grp) {}

Student::~Student() {}

std::string Student::getFName() const {
    return first_name;
}

std::string Student::getSName() const {
    return second_name;
}

int Student::getAge() const {
    return age;
}

int Student::getId() const {
    return student_id;
}

void Student::paint(QPainter* painter, const QRect& rect, int rowHeight, int totalWidth, int& current_Y) {
    if (!painter) return;

    painter->save();

    QFont font = painter->font();
    font.setPointSize(9);
    painter->setFont(font);


    QRect idRect(rect.left(), current_Y, 0.1 * totalWidth, rowHeight);
    QRect nameRect(rect.left() + 0.1 * totalWidth, current_Y, 0.2 * totalWidth, rowHeight);
    QRect surnameRect(rect.left() + 0.3 * totalWidth, current_Y, 0.2 * totalWidth, rowHeight);
    QRect ageRect(rect.left() + 0.5 * totalWidth, current_Y, 0.1 * totalWidth, rowHeight);
    QRect positionRect(rect.left() + 0.6 * totalWidth, current_Y, 0.2 * totalWidth, rowHeight);
    QRect numberRect(rect.left() + 0.8 * totalWidth, current_Y, 0.2 * totalWidth, rowHeight);


    painter->setPen(Qt::white);
    painter->drawRect(idRect);
    painter->drawRect(nameRect);
    painter->drawRect(surnameRect);
    painter->drawRect(ageRect);
    painter->drawRect(positionRect);
    painter ->drawRect(numberRect);

    painter->drawText(idRect, Qt::AlignCenter, QString::number(student_id));
    painter->drawText(nameRect, Qt::AlignCenter, QString::fromStdString(first_name));
    painter->drawText(surnameRect, Qt::AlignCenter, QString::fromStdString(second_name));
    painter->drawText(ageRect, Qt::AlignCenter, QString::number(age));

    painter->restore();
    current_Y += 30;
}
