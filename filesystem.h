#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>
#include <QFile>

class fileSystem
{
public:
    fileSystem();
    ~fileSystem();
    void newTextFile();
    void defaultTextFile();
    void openTextFile();
    void saveTextFile();
    void saveAsTextFile();
private:
    QString mTextFileName;
    QVector<double> Temp1;
};

#endif // FILESYSTEM_H
