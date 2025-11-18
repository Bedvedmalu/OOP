#include "createdialog.h"
#include "ui_createdialog.h"

using namespace std;

createDialog::createDialog(Group& group, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createDialog), group(group)
{
    ui->setupUi(this);
    setWindowTitle("Добавление");

    fnameEdit = ui->fnameEdit;
    snameEdit = ui->snameEdit;
    ageEdit = ui->ageEdit;
    posEdit = ui->posEdit;
    phoneEdit = ui->phoneEdit;

    posEdit->hide();
    phoneEdit->hide();
    ui->posLabel->hide();
    ui->phoneLabel->hide();
}

createDialog::~createDialog()
{
    delete ui;
}


void createDialog::on_choiceBox_currentIndexChanged(int index)
{
    QString selectedText = ui->choiceBox->itemText(index);
    if (selectedText == "Student") {
        posEdit->hide();
        phoneEdit->hide();
        ui->posLabel->hide();
        ui->phoneLabel->hide();
    }
    else {
        posEdit->show();
        phoneEdit->show();
        ui->posLabel->show();
        ui->phoneLabel->show();
    }
}


void createDialog::on_createStudent_clicked()
{
    string fnametxt = (fnameEdit->text()).toStdString();
    string snametxt = (snameEdit->text()).toStdString();
    int agetxt = (ageEdit->text()).toInt();
    if (posEdit->isHidden()) {
        if ((fnametxt == "") || (snametxt == "") || (agetxt == 0)) {
            return;
        }
        auto newStudent = make_shared<Student>(group.getNextId(), fnametxt, snametxt, agetxt, group.getName());
        group.addStudent(newStudent);
        accept();
    }
    else {
        string postxt = (posEdit->text()).toStdString();
        string phonetxt = (phoneEdit->text()).toStdString();
        if ((fnametxt == "") || (snametxt == "") || (agetxt == 0) || (postxt == "") || (phonetxt == "")) {
            return;
        }
        auto newStudent = make_shared<GroupLeader>(group.getNextId(), fnametxt, snametxt, agetxt, group.getName(), postxt, phonetxt);
        group.addStudent(newStudent);
        accept();
    }
}


void createDialog::on_cancel_clicked()
{
    accept();
}

