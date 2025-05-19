#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <vector>
#include <memory>

#include "herkenningsslot.h"

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
    void paintEvent(QPaintEvent *event) override;
    ~MainWindow();

private slots:
    void on_schuifdeurSensorKnop_clicked();

    void on_schuifdeurSensorKnop_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_schuifdeurKnopLineEdit_editingFinished();

    void on_schuifdeurKnopLineEdit_2_editingFinished();

    void on_draaideur_0_lineEdit_editingFinished();

    void on_draaideur_0_lineEdit_2_editingFinished();

    void on_herkenningsslotAdminAllow_clicked();

    void on_herkenningsslotAdminDeny_clicked();

    void on_herkenningsslotKaartenboxToon_clicked();

    void on_herkenningsslotInput_editingFinished();

    void on_draaideur_1_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    unique_ptr<Sensor> s1;
    unique_ptr<Deur> schuifdeur;
    shared_ptr<Herkenningsslot> herkenningsslot;
    vector<unique_ptr<Deur>> draaideuren;
    shared_ptr<Slot> schuifdeurSlot_0;
    shared_ptr<QTextBrowser> herkenningsslotDisplay;
    shared_ptr<QLineEdit> herkenningsslotInput;
    shared_ptr<QLineEdit> herkenningsslotAdminInput;
};
#endif // MAINWINDOW_H
