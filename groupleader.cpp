#include "groupleader.h"

using namespace std;

GroupLeader::GroupLeader() : Student() {}

GroupLeader::GroupLeader(int id, const std::string& fname, const std::string& sname, int age,
                         const std::string& grp, const std::string& pos, const std::string& phone)
    : Student(id, fname, sname, age, grp), position(pos), phone_number(phone) {}

std::string GroupLeader::getPosition() const {
    return position;
}

std::string GroupLeader::getPhoneNumber() const {
    return phone_number;
}

void GroupLeader::paint(QPainter* painter, const QRect& rect, int rowHeight, int totalWidth, int& current_Y) {
    int before_Y = current_Y;
    Student::paint(painter, rect, rowHeight,  totalWidth, current_Y);
    painter -> save();

    QFont font = painter->font();
    font.setPointSize(9);
    painter->setFont(font);

    painter->setPen(Qt::white);
    QRect positionRect(rect.left() + 0.6 * totalWidth, before_Y, 0.2 * totalWidth, rowHeight);
    QRect numberRect(rect.left() + 0.8 * totalWidth, before_Y, 0.2 * totalWidth, rowHeight);


    painter->drawText(positionRect, Qt::AlignCenter, QString::fromStdString(position));
    painter->drawText(numberRect, Qt::AlignCenter, QString::fromStdString(phone_number));
    painter->restore();
}
