#include "group.h"
#include <QDebug>

#include "student.h"
#include "groupleader.h"
#include "mainwindow.h"

using namespace std;

// BOOST_CLASS_EXPORT(Student);
// BOOST_CLASS_EXPORT(GroupLeader);

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

vector<shared_ptr<Student>> Group::getStudents() const {
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
