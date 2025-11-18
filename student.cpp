#include "student.h"
#include "dialog.h"

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

QString Student::getDisplayName() {
    return QString::fromStdString(first_name + " " + second_name);
}

void Student::paint(QPainter* painter, const QRect& rect, int rowHeight, int totalWidth, int& current_Y) {
    if (!painter) return;

    painter->save();

    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);

    QVector<int> widths = { int(0.1 * totalWidth), int(0.2 * totalWidth), int(0.2 * totalWidth), int(0.1 * totalWidth), int(0.2 * totalWidth), int(0.2 * totalWidth) };
    widths[5] = totalWidth - (widths[0] + widths[1] + widths[2] + widths[3] + widths[4]);

    QRect idRect(rect.left(), current_Y, widths[0], rowHeight);
    QRect nameRect(idRect.left() + widths[0], current_Y, widths[1], rowHeight);
    QRect surnameRect(nameRect.left() + widths[1], current_Y, widths[2], rowHeight);
    QRect ageRect(surnameRect.left() + widths[2], current_Y, widths[3], rowHeight);
    QRect positionRect(ageRect.left() + widths[3], current_Y, widths[4], rowHeight);
    QRect numberRect(positionRect.left() + widths[4], current_Y, widths[5], rowHeight);


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

void Student::fillFields(Dialog* dialog) {
    dialog->ui->posEdit->hide();
    dialog->ui->phoneEdit->hide();
    dialog->ui->posLabel->hide();
    dialog->ui->phoneLabel->hide();
    dialog->ui->fnameEdit->setText(QString::fromStdString(getFName()));
    dialog->ui->snameEdit->setText(QString::fromStdString(getSName()));
    dialog->ui->ageEdit->setText(QString::number(getAge()));
}


const void Student::setFName(QString& fname) {
    first_name = fname.toStdString();
}

void Student::setSName(QString& sname) {
        second_name = sname.toStdString();
}

void Student::setAge(int& stage) {
    age = stage;
}

void Student::changeStudent(string fname, string sname, int stage, string pos, string number) {
    first_name = fname;
    second_name = sname;
    age = stage;
}

BOOST_CLASS_EXPORT_IMPLEMENT(Student)
