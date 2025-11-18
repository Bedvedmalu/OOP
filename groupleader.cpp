#include "groupleader.h"
#include "dialog.h"

using namespace std;


GroupLeader::GroupLeader() : Student(), position(""), phone_number("") {}

GroupLeader::GroupLeader(int id, const std::string& fname, const std::string& sname, int age,
                         const std::string& grp, const std::string& pos, const std::string& phone)
    : Student(id, fname, sname, age, grp), position(pos), phone_number(phone) {}

std::string GroupLeader::getPosition() const {
    return position;
}

std::string GroupLeader::getPhoneNumber() const {
    return phone_number;
}

QString GroupLeader::getDisplayName() {
    return Student::getDisplayName() + QString::fromStdString(" " + position);
}

void GroupLeader::paint(QPainter* painter, const QRect& rect, int rowHeight, int totalWidth, int& current_Y) {
    int before_Y = current_Y;
    Student::paint(painter, rect, rowHeight,  totalWidth, current_Y);
    painter -> save();

    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);

    painter->setPen(Qt::white);
    QRect positionRect(rect.left() + 0.6 * totalWidth, before_Y, 0.2 * totalWidth, rowHeight);
    QRect numberRect(rect.left() + 0.8 * totalWidth, before_Y, 0.2 * totalWidth, rowHeight);


    painter->drawText(positionRect, Qt::AlignCenter, QString::fromStdString(position));
    painter->drawText(numberRect, Qt::AlignCenter, QString::fromStdString(phone_number));
    painter->restore();
}

void GroupLeader::fillFields(Dialog* dialog) {
    Student::fillFields(dialog);
    dialog->ui->posEdit->show();
    dialog->ui->phoneEdit->show();
    dialog->ui->posLabel->show();
    dialog->ui->phoneLabel->show();
    dialog->ui->posEdit->setText(QString::fromStdString(getPosition()));
    dialog->ui->phoneEdit->setText(QString::fromStdString(getPhoneNumber()));
}

void GroupLeader::setPos(QString& pos) {
    position = pos.toStdString();
}

void GroupLeader::setPhone(QString& number) {
    phone_number = number.toStdString();
}

void GroupLeader::changeStudent(std::string fname, std::string sname, int stage, std::string pos, std::string number) {
    Student::changeStudent(fname, sname, stage, pos, number);
    position = pos;
    phone_number = number;
}

BOOST_CLASS_EXPORT_IMPLEMENT(GroupLeader)

