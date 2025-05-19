#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"
#include "sleutelSlot.h"
#include "codeSlot.h"
#include "drukbox.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // sensor
    s1=make_unique<Hallsensor>(515,160);

    // sloten
    schuifdeurSlot_0 = make_shared<SleutelSlot>("abcd", make_shared<QLineEdit>(ui->schuifdeurKnopLineEdit));
    schuifdeur = make_unique<Schuifdeur>(500, 182, 60, s1.get());
    herkenningsslotDisplay = make_shared<QTextBrowser>(this->ui->herkenningsslotDisplay);
    herkenningsslotInput = make_shared<QLineEdit>(this->ui->herkenningsslotInput);
    herkenningsslotAdminInput = make_shared<QLineEdit>(this->ui->herkenningsslotAdminInput);

    shared_ptr<Slot> schuifdeurSlot_1 = make_shared<SleutelSlot>("efgh", make_shared<QLineEdit>(ui->schuifdeurKnopLineEdit_2));
    shared_ptr<Slot> draaideurSlot_0 = make_shared<CodeSlot>("1234", make_shared<QLineEdit>(ui->draaideur_0_lineEdit));
    shared_ptr<Slot> draaideurSlot_1 = make_shared<CodeSlot>("5678", make_shared<QLineEdit>(ui->draaideur_0_lineEdit_2));
    shared_ptr<Slot> draaideurSlot_2 = make_shared<CodeSlot>("9012", make_shared<QLineEdit>(ui->draaideur_1_lineEdit));

    // herkenningsslot
    unique_ptr<Drukbox> drukbox = make_unique<Drukbox>(herkenningsslotDisplay);
    herkenningsslot = make_shared<Herkenningsslot>(herkenningsslotInput, herkenningsslotAdminInput, std::move(drukbox));

    // deuren
    schuifdeur->voegSlotToe(schuifdeurSlot_0);
    schuifdeur->voegSlotToe(schuifdeurSlot_1);

    draaideuren.push_back(make_unique<Draaideur>(246, 107, 25, false));
    draaideuren[0]->voegSlotToe(draaideurSlot_0);
    draaideuren[0]->voegSlotToe(draaideurSlot_1);

    draaideuren.push_back(make_unique<Draaideur>(271, 294, 17, true));
    draaideuren[1]->voegSlotToe(draaideurSlot_2);
    draaideuren[1]->voegSlotToe(herkenningsslot);

}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    QPen pen;

    QImage image("../../Gebouw.png");

    pen.setColor(Qt::green);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawImage(10,10,image);

    s1->teken(this);
    schuifdeur->teken(this);
    draaideuren[0]->teken(this);
    draaideuren[1]->teken(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_schuifdeurSensorKnop_clicked()
{
    if(schuifdeur->isDeurOpen()) {
        schuifdeur->sluit();
    } else {
        QString s = ui->schuifdeurKnopLineEdit->text();
        ui->schuifdeurKnopLineEdit->clear();
        schuifdeur->open();
    }

    update();
}


void MainWindow::on_schuifdeurSensorKnop_2_clicked()
{
    if(s1->isGeactiveerd()) {
        s1->deactiveer();
    } else{
        s1->activeer();
    }
    update();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(draaideuren[0]->isDeurOpen()) {
        draaideuren[0]->sluit();
    } else {
        draaideuren[0]->open();
        ui->draaideur_0_lineEdit->clear();
    }

    update();
}


void MainWindow::on_pushButton_clicked()
{
    if(draaideuren[1]->isDeurOpen()) {
        draaideuren[1]->sluit();
    } else {
        draaideuren[1]->open();
        ui->draaideur_1_lineEdit->clear();
        ui->herkenningsslotInput->clear();
    }

    update();
}


void MainWindow::on_schuifdeurKnopLineEdit_editingFinished()
{
    schuifdeur->getSloten()[0]->ontgrendel();
}


void MainWindow::on_schuifdeurKnopLineEdit_2_editingFinished()
{
    schuifdeur->getSloten()[1]->ontgrendel();
}


void MainWindow::on_draaideur_0_lineEdit_editingFinished()
{
    draaideuren[0]->getSloten()[0]->ontgrendel();
}


void MainWindow::on_draaideur_0_lineEdit_2_editingFinished()
{
    draaideuren[0]->getSloten()[1]->ontgrendel();
}

void MainWindow::on_herkenningsslotAdminAllow_clicked()
{
    this->herkenningsslot->voegAutorisatieToe(true);
}


void MainWindow::on_herkenningsslotAdminDeny_clicked()
{
    this->herkenningsslot->voegAutorisatieToe(false);
}


void MainWindow::on_herkenningsslotKaartenboxToon_clicked()
{
    this->herkenningsslot->toonKaartenbak();
}


void MainWindow::on_herkenningsslotInput_editingFinished()
{
    this->herkenningsslot->ontgrendel();
}


void MainWindow::on_draaideur_1_lineEdit_editingFinished()
{
    this->draaideuren[1]->getSloten()[0]->ontgrendel();
}

