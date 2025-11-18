#ifndef DIALOG_H
#define DIALOG_H

#pragma once

#include "group.h"
#include "student.h"
#include "groupleader.h"
#include "student.h"
#include "createdialog.h"
#include <vector>
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(Group& group, QWidget *parent =  nullptr);
    ~Dialog();

    // QLineEdit* fnameEdit;
    // QLineEdit* snameEdit;
    // QLineEdit* ageEdit;
    // QLineEdit* posEdit;
    // QLineEdit* phoneEdit;
    // QLabel* posLabel;
    // QLabel* phoneLabel;

    Ui::Dialog *ui;
    void showAll(const std::vector<std::shared_ptr<Student>>& group);

private:

    QListWidget *studentsList= nullptr;

    bool is_clicked = false;
    Group& group;

private slots:
    void on_studentsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_deleteButton_clicked();
    void on_editButton_clicked();
    void on_adddButton_clicked();
};

#endif // DIALOG_H
