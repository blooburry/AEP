#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s1=make_unique<Hallsensor>(515,160);
    schuifdeur = make_unique<Schuifdeur>(500, 182, 60, s1.get());
    draaideuren.push_back(make_unique<Draaideur>(246, 107, 25, false));
    draaideuren.push_back(make_unique<Draaideur>(271, 294, 17, true));
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QPen pen;
    QImage image("C:\\Users\\altac\\Downloads\\gebouw\\Gebouw.png");

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
    }

    update();
}


void MainWindow::on_pushButton_clicked()
{
    if(draaideuren[1]->isDeurOpen()) {
        draaideuren[1]->sluit();
    } else {
        draaideuren[1]->open();
    }

    update();
}

