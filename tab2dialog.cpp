#include "tab2dialog.h"
#include "ui_tab2dialog.h"

Tab2Dialog::Tab2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tab2Dialog)
{
    ui->setupUi(this);
}


Tab2Dialog::~Tab2Dialog()
{
    delete ui;
}


void Tab2Dialog::on_pushButton_clicked()
{
    Get_Norm_Number= ui->Norm_Number->text();
    close();
}





