#include "group.h"
#include <QDebug>

#include "student.h"
#include "groupleader.h"
#include "mainwindow.h"

using namespace std;




Group::Group(const string& name) : groupname(name), next_id(1) {}

Group::~Group() {}
void Group::deleteAllStudents() {
    students.clear();
    next_id = 1;
}

void Group::readStudentsFromFile(string& filePath) {
    deleteAllStudents();
    ifstream inFile(filePath, ios::binary);
    boost::archive::binary_iarchive ia(inFile);
    ia.register_type<Student>();
    ia.register_type<GroupLeader>();

    ia >> *this;
}

void Group::writeStudentsToFile(string& filePath) {
    ofstream outFile(filePath, ios::binary);
    boost::archive::binary_oarchive oa(outFile);
    oa.register_type<Student>();
    oa.register_type<GroupLeader>();
    oa << *this;
}

vector<shared_ptr<Student>>& Group::getStudents() {
    return students;
}

void Group::paint(QPainter* painter, const QRect& area) const {
    if (!painter || students.empty()) return;

    painter->save();

    const int rowHeight = 30;
    const int headerHeight = 40;

    QFont headerFont = painter->font();
    headerFont.setPointSize(12);
    headerFont.setBold(true);
    painter->setFont(headerFont);

    int currentY = area.top() + headerHeight;

    using namespace placeholders;

    for_each(students.begin(), students.end(),
             bind(&Student::paint, _1, painter, area, rowHeight, area.width(), ref(currentY)));

    painter->restore();
}

void Group::deleteStudent(int id) {
    if (id >= 0 && id < students.size()) {
        students.erase(students.begin() + id);
    }
}

void Group::editStudent(int id, string fname, string sname, int stage, string pos, string number) {
    students[id]->changeStudent(fname, sname, stage, pos, number);
}

string Group::getName() {
    return groupname;
}

void Group::addStudent(const shared_ptr<Student>& newStudent) {
    students.push_back(newStudent);
    next_id++;
}

int Group::getNextId() {
    return next_id;
}
