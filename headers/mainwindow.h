#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    int changeTime();

private:
    QTimer *timer;
};

#endif // MAINWINDOW_H
