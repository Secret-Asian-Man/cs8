#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shortestdistance.h"
#include <QGeoCoordinate>
#include <QQmlEngine>
#include <QQmlProperty>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>
#include <QQuickItem>
#include <QVariant>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void callAddMarkerInQML(double lat, double lon);

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    bool from, to;
    QString f, t;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
