#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->statusBar->showMessage(mTextFileName);
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyACM0");//Linux "/dev/ttyACM0"
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
        if (!serial->open(QIODevice::ReadWrite))
        {
            QMessageBox::information(0,"Error",
                                     "Cannot open port!");
            return;
        }
        ui->pushButtonAcquire->setText("Stop");
        serial->clear();
        connect(serial,SIGNAL(readyRead()),
                this,SLOT(usbSerialRead()));
    }
    else
    {
        disconnect(serial,SIGNAL(readyRead()),
                   this,SLOT(usbSerialRead()));
        ui->pushButtonAcquire->setText("Acquire");
        serial->close();
    }

}

void MainWindow::usbSerialRead(void)
{
    if (serial->bytesAvailable())
    {
        serialData = serial->readLine();
        //remove \r\n characters
        serialData.truncate(serialData.size()-2);
        double d = serialData.toDouble();
        if (d != 0.0)
        {
            temp.push_back(serialData.toDouble());
            ui->lcdNumber->display(temp.back());
            ui->textBrowser->append(serialData);
        }
        QThread::msleep(500);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->text()=="ON LED")
    {
        ui->pushButton->setText("OFF LED");
        QByteArray command = "n";
        if (serial->isWritable())
            serial->write(command);
        else if (serial->open(QIODevice::ReadWrite))
            serial->write(command);
        else
        {
            QMessageBox::information(0,"Error",
                     "Cannot open port!");
            return;
        }
    }
    else
    {
        ui->pushButton->setText("ON LED");
        QByteArray command = "f";
        if (serial->isWritable())
            serial->write(command);
        else if (serial->open(QIODevice::ReadWrite))
            serial->write(command);
        else
        {
            QMessageBox::information(0,"Error",
                     "Cannot open port!");
            return;
        }
    }
}

void MainWindow::on_actionNew_triggered()
{
        QString f = QFileDialog::getSaveFileName(
                    0,"File","////.//",
                    "Text (*.txt)",0,0);
        if (f == NULL) return;
        mTextFileName = f;
        QFile file(mTextFileName);
        if (!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::information(0,"Error",
                         "Cannot open file!");
            return;
        }
        ui->statusBar->showMessage(mTextFileName);
        QTextStream outWrite(&file);
        outWrite << "" << endl;
        file.flush();
        file.close();
}

void MainWindow::on_actionOpen_triggered()
{
        QString f = QFileDialog::getOpenFileName(
                    0,"Open file","////.//",
                    "Text File (*.txt)");
        if (f == NULL)  return;
        mTextFileName = f;
        QFile file(mTextFileName);
        if (!file.open(QFile::ReadOnly|QFile::Text))
        {
            QMessageBox::information(0,"Error",
                         "Cannot open file!");
            return;
        }
        ui->statusBar->showMessage(mTextFileName);
        QByteArray dataLine;
        temp.clear();
        ui->textBrowser->clear();
        while (!file.atEnd())
        {
            dataLine = file.readLine();
            dataLine.truncate(dataLine.size()-2);
            temp.push_back(dataLine.toDouble());
            ui->textBrowser->append(dataLine);
        }
        file.flush();
        file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(mTextFileName);
    if (!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::information(0,"Error",
                     "Cannot open file!");
        return;
    }
    QTextStream outWrite(&file);
    for (int i=0;i<temp.size();i++)
        outWrite << temp.at(i) << endl;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
        QString f = QFileDialog::getSaveFileName(
                    0,"Save as","////.//",
                    "Text File (*.txt)");
        if (f == NULL) return;
        mTextFileName = f;
        QFile file(mTextFileName);
        if (!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::information(0,"Error",
                         "Cannot create file!");
            return;
        }
        ui->statusBar->showMessage(mTextFileName);
        QTextStream outWrite(&file);
        for (int i=0;i<temp.size();i++)
            outWrite << temp.at(i) << endl;
        file.flush();
        file.close();
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void MainWindow::on_pushButtonPlot_clicked()
{
    QVector<double> x, y;
    x.resize(temp.size());
    y.resize(temp.size());
    for (int i=0; i<temp.size(); ++i)
    {
      x[i] = i;
      y[i] = temp.at(i);
    }
    ui->widgetPlot->addGraph();
    ui->widgetPlot->graph(0)->setData(x, y);
    ui->widgetPlot->xAxis->setLabel("x");
    ui->widgetPlot->yAxis->setLabel("Temperature Celcuis");
    ui->widgetPlot->setWindowTitle("Room Temperature");
    ui->widgetPlot->xAxis->setRange(0, temp.size());
    ui->widgetPlot->yAxis->setRange(0, 50);
    ui->widgetPlot->replot();
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->textBrowser->clear();
    temp.clear();
    ui->lcdNumber->display(0.0);
}

void MainWindow::on_actionTempReader_triggered()
{
    myAbout = new DialogAbout(this);
    myAbout->show();
}
