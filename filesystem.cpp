#include "filesystem.h"

fileSystem::fileSystem()
{
    mTextFileName = "myTemperature.txt";
}
fileSystem::~fileSystem()
{
    ;
}

void fileSystem::newTextFile()
{   /*
    (1)opens QFileDialog to create new text file
    (2)opens QFile file
    (3)use QTextStream to write "" to file
    */
    /*(1)opens file dialog to create new text file*/
    mTextFileName = QFileDialog::getSaveFileName(0,"Text File","////.//","Text (*.txt)",0,0);
    if (mTextFileName == NULL)
            mTextFileName = "myTemperature.txt";
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

void fileSystem::defaultTextFile()
{   /*
    (1)opens default text file
    (2)reads Temperature and saves to QVector<double> tempTemperature
    */
    /*(1) Opens default text file*/
    QFile file(mTextFileName);
    if (!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::information(0,"File error","Cannot open file!");
    }
    /*(2)Reads Temperature and save to tempTemperature*/
    QString readTemp;
    while (!file.atEnd())         //keep reading line by line
    {                             //until reaching the end of file
        readTemp = file.readLine();
        Temp1.append(readTemp.toDouble());
    }
    file.flush();
    file.close();
}

void fileSystem::openTextFile()
{   /*
    (1)selects text file
    (2)opens text file
    (3)reads Temperature and saves to QVector<double> tempTemperature
    */
    /*(1) Select text file*/
    mTextFileName = QFileDialog::getOpenFileName(
                0,                      //QWidget *parent = 0
                "Open file",            //Set the title of the dialog
                "////.//",              //Go to current directory
                "Text File (*.txt)");   //Show text file only
    if (mTextFileName == NULL)           //check if user click cancel
    {
        mTextFileName = "myTemperature.txt";
        return;
    }
    /*(2) Open text file*/
    QFile file(mTextFileName);
    if (!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::information(0,"File Error","Cannot open file!");
    }
    /*(3)read Temperature and save to tempTemperature*/
    QString readTemp;
    while (!file.atEnd())
    {
        readTemp = file.readLine();
        Temp1.append(readTemp.toDouble());
    }
    file.flush();
    file.close();
}

void fileSystem::saveTextFile()
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
    for (int i=0;i<Temp1.size()-3;i++)
        out << Temp1.at(i) << endl;
    file.flush();
    file.close();
}

void fileSystem::saveAsTextFile()
{   /*
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
    for (int i=0;i<Temp1.size();i++)
        out << Temp1.at(i) << endl;
    file.flush();
    file.close();
}

