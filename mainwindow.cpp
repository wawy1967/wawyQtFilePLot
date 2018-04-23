#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM3");
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
    if (ui->pushButtonAcquire->text()=="Acquire")
    {
        ui->pushButtonAcquire->setText("Stop");
        serial->open(QIODevice::ReadWrite);
        serial->clear();
        connect(serial,SIGNAL(readyRead()),
                this,SLOT(usbSerialRead()));
    }
    else
    {
        disconnect(serial,SIGNAL(readyRead()),
                   this,SLOT(usbSerialRead()));
        ui->pushButtonAcquire->setText("Acquire");
    }

}

void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->text()=="ON LED")
    {
        ui->pushButton->setText("OFF LED");
        QByteArray command = "n";
        if (!serial->isWritable())
            serial->open(QIODevice::ReadWrite);
        serial->write(command);
    }
    else
    {
        ui->pushButton->setText("ON LED");
        QByteArray command = "f";
        if (!serial->isWritable())
            serial->open(QIODevice::ReadWrite);
        serial->write(command);
    }
}

void MainWindow::usbSerialRead(void)
{
    if (serial->bytesAvailable()>64)
    {
        serialData = serial->readLine();
        //remove \r\n characters
        serialData.truncate(serialData.size()-2);
        temp.push_back(serialData.toDouble());
        ui->lcdNumber->display(temp.back());
        ui->textBrowser->append(serialData);
    }
}

void MainWindow::on_actionNew_triggered()
{
        /*(1)opens file dialog to get new text file*/
        QString f = QFileDialog::getSaveFileName
                (0,"File","////.//","Text (*.txt)",0,0);
        if (f == NULL) return; //user cancel
        mTextFileName = f;
        /*(2)opens text file*/
        QFile file(mTextFileName);
        if (!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::information(0,"File Error","Cannot open file!");
        }
        /*(3)writes "" to new file*/
        QTextStream out(&file);
        out << "" << endl;
        file.flush();
        file.close();
}

void MainWindow::on_actionOpen_triggered()
{
    /*
        (1)selects text file
        (2)opens text file
        (3)reads Temperature and saves to QVector<double> tempTemperature
        */
        /*(1) Select text file*/
        f = QFileDialog::getOpenFileName(
                    0,                      //QWidget *parent = 0
                    "Open file",            //Set the title of the dialog
                    "////.//",              //Go to current directory
                    "Text File (*.txt)");   //Show text file only
        if (f == NULL)  return;             //User cancels
        mTextFileName = f;
        /*(2) Open text file*/
        QFile file(mTextFileName);
        if (!file.open(QFile::ReadOnly|QFile::Text))
        {
            QMessageBox::information(0,"File Error","Cannot open file!");
        }
        /*(3)read Temperature and save to vector<double> temp */
        QString dataLine;
        while (!file.atEnd())
        {
            dataLine = file.readLine();
            temp.append(dataLine.toDouble());

        }
        file.flush();
        file.close();
}

void MainWindow::on_actionSave_triggered()
{
    /*This function
    (1)opens text file
    (2)writes tempTemperature to text file
    */
     /*(1)opens text file*/
    QFile file(mTextFileName);
    if (!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::information(0,"File Error","Cannot create file!");
        return;
    }
    /*(2)writes tempTemperature to text file*/
    QTextStream out(&file);
    //make file into
    for (int i=0;i<temp.size()-3;i++)
        out << temp.at(i) << endl;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    /*
        (1)creates text file
        (2)opens text file
        (3)writes tempTemperature to text file
        */

        /*(1)creates text file */
        mTextFileName = QFileDialog::getSaveFileName(0,"Save as","////.//","Text File (*.txt)");
        if (mTextFileName == NULL)           //check if user click cancel
                mTextFileName = "myTemprature.txt";
         /*(2)opens text file*/
        QFile file(mTextFileName);
        if (!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::information(0,"File Error","Cannot create file!");
            return;
        }
        /*(3)writes tempTemperature to text file*/
        QTextStream out(&file);
        for (int i=0;i<temp.size();i++)
            out << temp.at(i) << endl;
        file.flush();
        file.close();
}

void MainWindow::on_actionQuit_triggered()
{
    ;
}
