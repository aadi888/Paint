#include "pendialog.h"
#include "ui_pendialog.h"
#include "mymainwindow.h"
#include <QMessageBox>

PenDialog::PenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PenDialog)
{
    ui->setupUi(this);
}

PenDialog::~PenDialog()//
{
    delete ui;
}







void PenDialog::on_buttonBox_clicked(QAbstractButton *button)
{


     if(ui->radioButton->isChecked())
    {

       QMessageBox::information(0,"Data Changed  PLEASE DOUBLE CLICK ON SCREEN TO INITIALIZE DEFAULT VALUE AS BEFORE  ","Data Changed  PLEASE DOUBLE CLICK ON SCREEN TO INITIALIZE DEFAULT VALUE AS BEFORE");














    }
    if(ui->radioButton_2->isChecked())
    {
      QMessageBox::information(0,"Data Changed  PLEASE DOUBLE CLICK ON SCREEN TO INITIALIZE DEFAULT VALUE AS BEFORE","Data Changed  PLEASE DOUBLE CLICK ON SCREEN TO INITIALIZE DEFAULT VALUE AS BEFORE");




    }
    if(ui->radioButton_3->isChecked())
    {


        QMessageBox::information(0,"Data Changed  PLEASE DOUBLE CLICK ON SCREEN TO INITIALIZE DEFAULT VALUE AS BEFORE","Data Changed  PLEASE DOUBLE CLICK ON SCREEN TO INITIALIZE DEFAULT VALUE AS BEFORE");

    }
}

void PenDialog::on_horizontalSlider_valueChanged(int value)
{


}
