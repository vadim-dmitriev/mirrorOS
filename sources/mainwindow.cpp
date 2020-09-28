#include <iostream>
#include <QTimer>
#include <QVBoxLayout>

#include "../headers/digitalClock.h"
#include "../headers/calendar.h"
#include "../headers/mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
{   
    this->setStyleSheet("background-color: #000000;");
    this->resize(450, 800);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new DigitalClock);
    layout->addWidget(new Calendar);

    this->setLayout(layout);
}


int MainWindow::changeTime()
{
    std::cout << "tick" << std::endl;
    return 0;
}
