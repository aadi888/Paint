#ifndef PENDIALOG_H
#define PENDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include<mymainwindow.h>

namespace Ui {
class PenDialog;
}

class PenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PenDialog(QWidget *parent = 0);
    ~PenDialog();

private slots:
    //void on_groupBox_clicked();

    //void on_radioButton_3_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::PenDialog *ui;

public:

};

#endif // PENDIALOG_H
