#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(auto p : QSerialPortInfo::availablePorts()){
        ui->comboBox->addItem(p.portName());
    }
    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_conectar_clicked()
{
    serial.setPortName(ui->comboBox->currentText());
    serial.setBaudRate(115200);
    if (serial.open(QIODevice::ReadWrite)){
        ui->label_status->setText("Status: Conectado");
    }
}

void MainWindow::dadosRecebidos()
{
    auto dados = serial.readAll();
    auto json = QJsonDocument::fromJson(dados).object().toVariantMap();

    if( json.contains("LDR") ){
        ui->label_ldr->setText(json["LDR"].toString());
    }

    if( json.contains("LED") ){
        red_led_status = json["LED"].toBool();
        ui->red_led->setEnabled(red_led_status);
        QString btn_text = red_led_status ? "Desligar" : "Ligar";
        ui->btn_led->setText(btn_text);
    }

}

void MainWindow::on_btn_led_clicked()
{
    if( red_led_status ){
        serial.write("{\"LED\":0}");
    }else{
        serial.write("{\"LED\":1}");
    }
}
