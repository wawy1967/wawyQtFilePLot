#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSerialPort>
#include <dialogabout.h>

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
    void on_pushButton_clicked();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionQuit_triggered();
    void on_pushButtonPlot_clicked();

    void on_pushButtonClear_clicked();

    void on_actionTempReader_triggered();

private:
    Ui::MainWindow *ui;
    QString mTextFileName = "defaultFile.txt";
    QSerialPort *serial;
    QVector<double> temp;
    QByteArray serialData;
    DialogAbout *myAbout;
};
#endif // MAINWINDOW_H
