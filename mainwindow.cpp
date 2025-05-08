#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"
#include "sleutelSlot.h"
#include "codeSlot.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s1=make_unique<Hallsensor>(515,160);
    schuifdeurSlot_0 = make_shared<SleutelSlot>("abcd", make_shared<QLineEdit>(ui->schuifdeurKnopLineEdit));
    shared_ptr<Slot> schuifdeurSlot_1 = make_shared<SleutelSlot>("efgh", make_shared<QLineEdit>(ui->schuifdeurKnopLineEdit_2));
    schuifdeur = make_unique<Schuifdeur>(500, 182, 60, s1.get());
    schuifdeur->voegSlotToe(schuifdeurSlot_0);
    schuifdeur->voegSlotToe(schuifdeurSlot_1);
    shared_ptr<Slot> draaideurSlot_0 = make_shared<CodeSlot>("1234", make_shared<QLineEdit>(ui->draaideur_0_lineEdit));
    shared_ptr<Slot> draaideurSlot_1 = make_shared<CodeSlot>("5678", make_shared<QLineEdit>(ui->draaideur_0_lineEdit_2));
    shared_ptr<Slot> draaideurSlot_2 = make_shared<CodeSlot>("9012", make_shared<QLineEdit>(ui->draaideur_1_lineEdit));
    draaideuren.push_back(make_unique<Draaideur>(246, 107, 25, false));
    draaideuren[0]->voegSlotToe(draaideurSlot_0);
    draaideuren[0]->voegSlotToe(draaideurSlot_1);
    draaideuren.push_back(make_unique<Draaideur>(271, 294, 17, true));
    draaideuren[1]->voegSlotToe(draaideurSlot_2);
}

void MainWindow::paintEvent(QPaintEvent *event){

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
    }

    update();
}


void MainWindow::on_schuifdeurKnopLineEdit_returnPressed()
{
    schuifdeur->getSloten()[0]->ontgrendel();
}


void MainWindow::on_schuifdeurKnopLineEdit_2_returnPressed()
{
    schuifdeur->getSloten()[1]->ontgrendel();
}


void MainWindow::on_draaideur_0_lineEdit_returnPressed()
{
    draaideuren[0]->getSloten()[0]->ontgrendel();
}


void MainWindow::on_draaideur_0_lineEdit_2_returnPressed()
{
    draaideuren[0]->getSloten()[1]->ontgrendel();
}


void MainWindow::on_draaideur_1_lineEdit_returnPressed()
{
    draaideuren[1]->getSloten()[0]->ontgrendel();
}

