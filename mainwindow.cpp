#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QStringList>
#include <list>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::list<int> numbers;

    QString text = ui->lineEdit->text();

    QStringList values = text.split(" ", Qt::SkipEmptyParts);

    for (const QString &value : values)
    {
        numbers.push_back(value.toInt());
    }

    numbers.reverse();

    QString result;

    for (int number : numbers)
    {
        result += QString::number(number) + " ";
    }

    ui->textEdit->setText(result);
}