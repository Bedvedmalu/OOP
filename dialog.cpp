#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>
using namespace std;

Dialog::Dialog(Group& group, QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog), group(group)
{
    ui -> setupUi(this);
    setWindowTitle("Изменение");
    vector<shared_ptr<Student>> groupRef = group.getStudents();
    studentsList = ui->studentsList;

    ui->fnameEdit->setReadOnly(true);
    ui->snameEdit->setReadOnly(true);
    ui->ageEdit->setReadOnly(true);
    ui->posEdit->setReadOnly(true);
    ui->phoneEdit->setReadOnly(true);

    Dialog::showAll(groupRef);

    connect(studentsList, &QListWidget::currentItemChanged,
            this, &Dialog::on_studentsList_currentItemChanged);

}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::showAll(const vector<shared_ptr<Student>>& group) {
    int index = 0;
    for_each(group.begin(), group.end(), [this, &index](shared_ptr<Student> student) {
        QListWidgetItem* item = new QListWidgetItem(student->getDisplayName());
        item->setData(Qt::UserRole, index);
        studentsList->addItem(item);
        ++index;
    });
}


void Dialog::on_studentsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    vector<shared_ptr<Student>> groupRef = group.getStudents();
    if (!current) return;
    int index = current->data(Qt::UserRole).toInt();
    if (index < 0 || index >= groupRef.size()) return;
    auto student = groupRef[index];
    student->fillFields(this);
}




void Dialog::on_deleteButton_clicked()
{

    int currentRow = studentsList->currentRow();
    group.deleteStudent(currentRow);
    studentsList->clear();
    ui->fnameEdit->clear();
    ui->snameEdit->clear();
    ui->ageEdit->clear();
    ui->posEdit->clear();
    ui->phoneEdit->clear();
    Dialog::showAll(group.getStudents());
}



void Dialog::on_editButton_clicked()
{
    if (!is_clicked) {
         ui->studentsList->setSelectionMode(QAbstractItemView::NoSelection);
         ui->studentsList->setEnabled(false);
        is_clicked = true;
        ui->editButton->setText("Применить");
        ui->fnameEdit->setReadOnly(false);
        ui->snameEdit->setReadOnly(false);
        ui->ageEdit->setReadOnly(false);
        ui->posEdit->setReadOnly(false);
        ui->phoneEdit->setReadOnly(false);
    }
    else {
        int currentRow = studentsList->currentRow();

        string fnametxt = (ui->fnameEdit->text()).toStdString();
        string snametxt = (ui->snameEdit->text()).toStdString();
        int agetxt = (ui->ageEdit->text()).toInt();
        string postxt = (ui->posEdit->text()).toStdString();
        string phonetxt = (ui->phoneEdit->text()).toStdString();
        group.editStudent(currentRow, fnametxt, snametxt, agetxt, postxt, phonetxt);

        ui->fnameEdit->setReadOnly(true);
        ui->snameEdit->setReadOnly(true);
        ui->ageEdit->setReadOnly(true);
        ui->posEdit->setReadOnly(true);
        ui->phoneEdit->setReadOnly(true);
        ui->editButton->setText("Изменить");
        ui->studentsList->setEnabled(true);
        is_clicked = false;
        studentsList->clear();
        Dialog::showAll(group.getStudents());
        ui->studentsList->setSelectionMode(QAbstractItemView::SingleSelection);
    }
}




void Dialog::on_adddButton_clicked()
{
    createDialog *createdialog = new createDialog(group, this);

    createdialog->setAttribute(Qt::WA_DeleteOnClose);

    connect(createdialog, &createDialog::finished, this, [this]() {
        studentsList->clear();
        Dialog::showAll(group.getStudents());
    });
    createdialog->show();
}

