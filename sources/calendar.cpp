#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QDate>
#include <Qt>


#include <headers/calendar.h>

Calendar::Calendar(QWidget *parent) {
    QDate now = QDate::currentDate();
    int daysInMonth = now.daysInMonth();
    QDate firstMonthDay = now.addDays(now.day() * -1);
    int firstMonthDayWeekIndex = firstMonthDay.dayOfWeek();
    
    QString daysOfWeek[7] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    this->setStyleSheet("background-color: #000000;"
                        "color: #ffffff");

    QGridLayout *layout = new QGridLayout(this);


    for (int i=0; i < 7; i++) {
        QLabel *dayOfWeekLabel = new QLabel(daysOfWeek[i]);
        dayOfWeekLabel->setStyleSheet("font-weight: 700;"
                                      "text-align: center;");
        dayOfWeekLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(dayOfWeekLabel, 0, i);
    }

    for (int i=0; i < daysInMonth+firstMonthDayWeekIndex; i++) {
        QLabel *dayLabel = new QLabel;

        if (i >= firstMonthDayWeekIndex) {
            dayLabel->setText(QString::number(i-firstMonthDayWeekIndex+1));
            dayLabel->setStyleSheet("font-weight: 100;"
                                    "text-align: right;");
            dayLabel->setAlignment(Qt::AlignCenter);
        }
        
        if (i == now.day()+firstMonthDayWeekIndex-1) {
            dayLabel->setStyleSheet("border: 1px solid white;"
                                    "border-radius: 25px;");
        }

        layout->addWidget(dayLabel, (i/7)+1, i%7);
    }

    this->setLayout(layout);
}