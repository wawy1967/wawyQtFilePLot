#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSerialPort>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void usbSerialRead(void);
    void on_pushButtonAcquire_clicked();
    void on_pushButtonStop_clicked();
    void on_pushButtonONN_clicked();
    void on_pushButtonOFF_clicked();
private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QVector<double> temp;
    QByteArray serialData;
};
#endif // MAINWINDOW_H
