#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <string>
#include <QSize>

#include <headers/calendar.h>

Calendar::Calendar(QWidget *parent) {
    QLabel *items[30];

    QString daysOfWeek[7] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    this->setStyleSheet("background-color: #000000;"
                        "color: #ffffff");

    QGridLayout *mainLayout = new QGridLayout(this);
    QGridLayout *calLayout = new QGridLayout(this);
    QHBoxLayout *calHeaderLayout = new QHBoxLayout(this);


    for (int i=0; i < 7; i++) {
        calHeaderLayout->addWidget(new QLabel(daysOfWeek[i]));
    }

    for (int i=0; i < 30; i++) {
        items[i] = new QLabel(QString::number(i));
        calLayout->addWidget(items[i], i/7, i%7);
    }
    
    mainLayout->addLayout(calHeaderLayout, 0, 0);
    mainLayout->addLayout(calLayout, 1, 0);

    this->setLayout(mainLayout);
}