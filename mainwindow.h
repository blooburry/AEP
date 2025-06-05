#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <vector>
#include <memory>
#include "idkaart.h"

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

    void on_idKaartAdminKnop_clicked();

    void on_kaartSlotVoegKaartToeKnop_clicked();

    void on_idKaartAdminVerwijderKnop_clicked();

    void on_kaartSlotVerwijderKaartKnop_clicked();

    void on_kaartSlotIdInput_editingFinished();

private:
    Ui::MainWindow *ui;
    unique_ptr<Sensor> s1;
    unique_ptr<Deur> schuifdeur;
    shared_ptr<Slot> herkenningsslot;
    vector<unique_ptr<Deur>> draaideuren;
    shared_ptr<Slot> schuifdeurSlot_0;
    shared_ptr<QTextBrowser> herkenningsslotDisplay;
    shared_ptr<Slot> schuifdeurSlot_kaartSlot;
    // inputs
    unique_ptr<QLineEdit> schuifdeurSlotInput_0;
    unique_ptr<QLineEdit> schuifdeurSlotInput_1;
    unique_ptr<QLineEdit> draaideur_0Slot_0Input;
    unique_ptr<QLineEdit> draaideur_0Slot_1Input;
    unique_ptr<QLineEdit> draaideur_1Slot_0Input;
    unique_ptr<QLineEdit> herkenningsslotInput;
    unique_ptr<QLineEdit> herkenningsslotAdminInput;
        // kaartslot
    QLineEdit* idKaartAdminIdInput;
    QLineEdit* idKaartAdminNaamInput;
    QLineEdit* idKaartAdminPlaatsInput;
    QLineEdit* kaartSlotAdminIdInput;
    QLineEdit* kaartSlotIdInput;
    vector<IdKaart> idKaarten;
    // helper
    void ontgrendel_met_input(QLineEdit*, shared_ptr<Slot>);
};
#endif // MAINWINDOW_H
