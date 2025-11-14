#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include "group.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

private slots:

    void on_loadButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    Group group;
    QWidget *studentTable = nullptr;

};
#endif // MAINWINDOW_H
