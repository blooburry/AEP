#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"
#include "sleutelSlot.h"
#include "codeSlot.h"
#include "drukbox.h"
#include "herkenningsslot.h"
#include "kaartslot.h"
#include "slotexception.h"

#include <QPaintDevice>
#include <QPainter>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // sensor
    s1=make_unique<Hallsensor>(515,160);

    // inputs
    herkenningsslotInput = make_unique<QLineEdit>(this->ui->herkenningsslotInput);
    herkenningsslotAdminInput = make_unique<QLineEdit>(this->ui->herkenningsslotAdminInput);
    schuifdeurSlotInput_0 = make_unique<QLineEdit>(this->ui->schuifdeurKnopLineEdit);
    schuifdeurSlotInput_1 = make_unique<QLineEdit>(this->ui->schuifdeurKnopLineEdit_2);
    draaideur_0Slot_0Input = make_unique<QLineEdit>(this->ui->draaideur_0_lineEdit);
    draaideur_0Slot_1Input = make_unique<QLineEdit>(this->ui->draaideur_0_lineEdit);
    draaideur_1Slot_0Input = make_unique<QLineEdit>(this->ui->draaideur_1_lineEdit);
        // kaartslot
    idKaartAdminIdInput = this->ui->IdKaartToevoegenAdminIdInput;
    idKaartAdminNaamInput = this->ui->IdKaartToevoegenAdminNaamInput;
    idKaartAdminPlaatsInput = this->ui->IdKaartToevoegenAdminPlaatsInput;
    kaartSlotAdminIdInput = this->ui->kaartSlotAdminIdInput;
    kaartSlotIdInput = this->ui->kaartSlotIdInput;

    // sloten
    schuifdeurSlot_0 = make_shared<SleutelSlot>("abcd");
    schuifdeur = make_unique<Schuifdeur>(500, 182, 60, s1.get());
    herkenningsslotDisplay = make_shared<QTextBrowser>(this->ui->herkenningsslotDisplay);

    shared_ptr<Slot> schuifdeurSlot_1 = make_shared<SleutelSlot>("efgh");
    shared_ptr<Slot> draaideurSlot_0 = make_shared<CodeSlot>("1234");
    shared_ptr<Slot> draaideurSlot_1 = make_shared<CodeSlot>("5678");
    shared_ptr<Slot> draaideurSlot_2 = make_shared<CodeSlot>("9012");
    schuifdeurSlot_kaartSlot = make_shared<KaartSlot>("schuifdeur");

    // herkenningsslot
    unique_ptr<Drukbox> drukbox = make_unique<Drukbox>(herkenningsslotDisplay);
    herkenningsslot = make_shared<Herkenningsslot>(std::move(drukbox));

    // deuren
    schuifdeur->voegSlotToe(schuifdeurSlot_0);
    schuifdeur->voegSlotToe(schuifdeurSlot_1);
    schuifdeur->voegSlotToe(this->schuifdeurSlot_kaartSlot);

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
        this->schuifdeurSlotInput_0->clear();
        this->schuifdeurSlotInput_1->clear();
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
        this->draaideur_0Slot_0Input->clear();
        this->draaideur_0Slot_1Input->clear();
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
        this->draaideur_1Slot_0Input->clear();
    } else {
        draaideuren[1]->open();
        ui->draaideur_1_lineEdit->clear();
        ui->herkenningsslotInput->clear();
    }

    update();
}


void MainWindow::ontgrendel_met_input(QLineEdit* i, shared_ptr<Slot> s) {
    string sleutel = i->text().toStdString();
    try {
        s->ontgrendel(sleutel);
    } catch (const SlotException& e) {
        qWarning() << "Slot kon niet worden ontgrendeld:" << e.what();
    }

    if(s->isVergrendeld()) {
        i->setStyleSheet("QLineEdit {border: 2px solid red;}");
    } else {
        i->setStyleSheet("QLineEdit {border: 2px solid rgb(0,255,0);}");
    }
    update();
}

void MainWindow::on_schuifdeurKnopLineEdit_editingFinished()
{
    ontgrendel_met_input(this->schuifdeurSlotInput_0.get(), this->schuifdeurSlot_0);
}


void MainWindow::on_schuifdeurKnopLineEdit_2_editingFinished()
{
    ontgrendel_met_input(this->schuifdeurSlotInput_1.get(), this->schuifdeurSlot_0);
}


void MainWindow::on_draaideur_0_lineEdit_editingFinished()
{
    ontgrendel_met_input(this->draaideur_0Slot_0Input.get(), draaideuren[0]->getSloten()[0]);
}


void MainWindow::on_draaideur_0_lineEdit_2_editingFinished()
{
    ontgrendel_met_input(this->draaideur_0Slot_1Input.get(), draaideuren[0]->getSloten()[1]);
}

void MainWindow::on_draaideur_1_lineEdit_editingFinished()
{
    ontgrendel_met_input(this->draaideur_1Slot_0Input.get(), draaideuren[1]->getSloten()[0]);
}


void MainWindow::on_herkenningsslotAdminAllow_clicked()
{
    if(auto s = dynamic_cast<Herkenningsslot*>(this->herkenningsslot.get())){
        string naam = this->herkenningsslotAdminInput->text().toStdString();
        s->voegAutorisatieToe(naam, true);
    }
}


void MainWindow::on_herkenningsslotAdminDeny_clicked()
{
    if(auto s = dynamic_cast<Herkenningsslot*>(this->herkenningsslot.get())){
        string naam = this->herkenningsslotAdminInput->text().toStdString();
        s->voegAutorisatieToe(naam, false);
    }
}


void MainWindow::on_herkenningsslotKaartenboxToon_clicked()
{
    if(auto s = dynamic_cast<Herkenningsslot*>(this->herkenningsslot.get())){
        s->toonKaartenbak();
    }
}


void MainWindow::on_herkenningsslotInput_editingFinished()
{
    ontgrendel_met_input(this->herkenningsslotInput.get(), this->herkenningsslot);
}


void MainWindow::on_idKaartAdminKnop_clicked()
{
    string id = this->idKaartAdminIdInput->text().toStdString();
    string naam = this->idKaartAdminNaamInput->text().toStdString();
    string plaats = this->idKaartAdminPlaatsInput->text().toStdString();
    IdKaart k(id, naam, plaats);
    idKaarten.push_back(k);
    KaartSlot::voegIdKaartToe(&idKaarten.back());
}

void MainWindow::on_idKaartAdminVerwijderKnop_clicked()
{
    string id = this->idKaartAdminIdInput->text().toStdString();
    KaartSlot::verwijderIdKaart(id);
}

void MainWindow::on_kaartSlotVoegKaartToeKnop_clicked()
{
    auto slot = this->schuifdeurSlot_kaartSlot.get();
    if(auto s = dynamic_cast<KaartSlot*>(slot)){
        string id = this->kaartSlotAdminIdInput->text().toStdString();
        auto kaart = std::find_if(idKaarten.begin(), idKaarten.end(), [id](const IdKaart& k) {
            return k.userId() == id;
        });
            if (kaart == idKaarten.end()) {
                qWarning() << "IdKaart met id <" << id << "> bestaat niet!";
                return;
            }
        kaart->geefToegang(s);
    } else {
        qWarning() << "Dynamic cast failed!";
    }
}

void MainWindow::on_kaartSlotVerwijderKaartKnop_clicked()
{
    auto s = dynamic_cast<KaartSlot*>(this->schuifdeurSlot_kaartSlot.get());
    if(s){
        string id = this->kaartSlotAdminIdInput->text().toStdString();
        auto kaart = std::find_if(idKaarten.begin(), idKaarten.end(), [id](const IdKaart& k) {
            return k.userId() == id;
        });
        if (kaart == idKaarten.end()) {
            qWarning() << "IdKaart met id <" << id << "> bestaat niet!";
            return;
        }
        kaart->verwijderToegang(s);
    } else {
        qWarning() << "Dynamic cast failed!";
    }
}


void MainWindow::on_kaartSlotIdInput_editingFinished()
{
    auto s = this->schuifdeurSlot_kaartSlot;
    ontgrendel_met_input(this->kaartSlotIdInput, this->schuifdeurSlot_kaartSlot);
}
