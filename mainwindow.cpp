#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , group("AC-23-05")
    , studentTable(nullptr)
{
    ui->setupUi(this);
    studentTable = ui->studentTable;
    // group.writeStudentsToFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect widgetPosition = studentTable->geometry();
    int start_x = widgetPosition.x();
    int start_y = widgetPosition.y();
    int width =widgetPosition.width();

    int cellHeight = 40;
    QVector<double> widths = {0.1 * width, 0.2 * width, 0.2 * width, 0.1 * width, 0.2 * width, 0.2 * width};

    int current_x = start_x;
    QStringList headers = {"ID", "Имя", "Фамилия", "Возраст", "Должность", "Номер телефона"};
    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("Times New Roman", 10, QFont::Bold));

    for (int col = 0; col < 6; ++col) {
        QRect headerRect(current_x, start_y, widths[col], cellHeight);
        painter.fillRect(headerRect, QColor(30, 30, 30));
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter, headers[col]);
        current_x += widths[col];
    }
    QRect studentsArea(start_x, start_y, width, widgetPosition.height() - cellHeight);
    group.paint(&painter, studentsArea);
}

void MainWindow::on_loadButton_clicked()
{
    string filePath = (QFileDialog::getOpenFileName(nullptr, "Выберите файл", "")).toStdString();
    group.readStudentsFromFile(filePath);
    update();
 }


void MainWindow::on_deleteButton_clicked()
{
    group.deleteAllStudents();
    update();
}
