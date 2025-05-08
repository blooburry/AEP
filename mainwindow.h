#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <memory>

using namespace std;

#include "deur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Sensor;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~MainWindow();

private slots:
    void on_schuifdeurSensorKnop_clicked();

    void on_schuifdeurSensorKnop_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_schuifdeurKnopLineEdit_returnPressed();

    void on_schuifdeurKnopLineEdit_2_returnPressed();

    void on_draaideur_0_lineEdit_returnPressed();

    void on_draaideur_0_lineEdit_2_returnPressed();

    void on_draaideur_1_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    unique_ptr<Sensor> s1;
    unique_ptr<Deur> schuifdeur;
    vector<unique_ptr<Deur>> draaideuren;
    shared_ptr<Slot> schuifdeurSlot_0;
};
#endif // MAINWINDOW_H
