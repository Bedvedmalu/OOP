#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#pragma once
#include"student.h"
#include "group.h"
#include "dialog.h"
#include <QDialog>

namespace Ui {
class createDialog;
}

class createDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createDialog(Group& group, QWidget *parent = nullptr);
    ~createDialog();

private slots:
    void on_choiceBox_currentIndexChanged(int index);

    void on_createStudent_clicked();

    void on_cancel_clicked();

private:
    Ui::createDialog *ui;
    QLineEdit* fnameEdit;
    QLineEdit* snameEdit;
    QLineEdit* ageEdit;
    QLineEdit* posEdit;
    QLineEdit* phoneEdit;

    Group& group;
};

#endif // CREATEDIALOG_H
