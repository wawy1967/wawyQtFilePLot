#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyACM0");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}
MainWindow::~MainWindow()
{
    serial->close();
    delete ui;
}
void MainWindow::on_pushButtonAcquire_clicked()
{
    serial->open(QIODevice::ReadWrite);
    serial->clear();
    connect(serial,SIGNAL(readyRead()),this,SLOT(usbSerialRead()));
}
void MainWindow::on_pushButtonStop_clicked()
{
    disconnect(serial,SIGNAL(readyRead()),this,SLOT(usbSerialRead()));
}
void MainWindow::on_pushButtonONN_clicked()
{
    QByteArray command = "n";
    if (!serial->isWritable())
        serial->open(QIODevice::ReadWrite);
    serial->write(command);
}
void MainWindow::on_pushButtonOFF_clicked()
{
    QByteArray command = "f";
    if (!serial->isWritable())
        serial->open(QIODevice::ReadWrite);
    serial->write(command);
}
void MainWindow::usbSerialRead(void)
{
    if (serial->bytesAvailable()>64)
    {
        serialData = serial->readLine();
        //remove \r\n characters
        serialData.truncate(serialData.size()-2);
        temp.push_back(serialData.toDouble());
        ui->textBrowser->append(serialData);
    }
}
