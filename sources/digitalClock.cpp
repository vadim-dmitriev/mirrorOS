#include <QTime>
#include <QTimer>
#include <QString>
#include <QFont>

#include "headers/digitalClock.h"


DigitalClock::DigitalClock(QWidget *parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));

    this->setStyleSheet("font-family: Roboto Mono Thin;"
                        "font-weight: 300;"
                        "font-size: 50px;"
                        "color: #ffffff;");

    timer->start(1000);
    showTime();
}

void DigitalClock::showTime() {
    QTime currentTime = QTime::currentTime();

    QString currentTimeString = currentTime.toString("hh:mm");
    if (currentTime.second() % 2 == 0) {
        currentTimeString[2] = ' ';
    }
    this->setText(currentTimeString);
}
