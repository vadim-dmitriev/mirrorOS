#include <QLabel>
#include <QWidget>
#include <QDateTime>

class DigitalClock: public QLabel {
    Q_OBJECT

    public:
        DigitalClock(QWidget *parent = 0);
    
    private slots:
        void showTime();
};