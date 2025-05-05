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
    shared_ptr<Slot> schuifdeurSlot = make_shared<SleutelSlot>("abcd");
    schuifdeur = make_unique<Schuifdeur>(500, 182, 60, s1.get(), schuifdeurSlot);
    shared_ptr<Slot> draaideurSlot_0 = make_shared<CodeSlot>("1234");
    shared_ptr<Slot> draaideurSlot_1 = make_shared<CodeSlot>("5678");
    draaideuren.push_back(make_unique<Draaideur>(246, 107, 25, false, draaideurSlot_0));
    draaideuren.push_back(make_unique<Draaideur>(271, 294, 17, true, draaideurSlot_1));
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
        schuifdeur->open(s.toStdString());
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
        draaideuren[0]->open(ui->draaideur_0_lineEdit->text().toStdString());
        ui->draaideur_0_lineEdit->clear();
    }

    update();
}


void MainWindow::on_pushButton_clicked()
{
    if(draaideuren[1]->isDeurOpen()) {
        draaideuren[1]->sluit();
    } else {
        draaideuren[1]->open(ui->draaideur_1_lineEdit->text().toStdString());
        ui->draaideur_1_lineEdit->clear();
    }

    update();
}

