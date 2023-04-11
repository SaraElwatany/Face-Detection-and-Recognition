#include "normalizedialog.h"
#include "ui_normalizedialog.h"

NormalizeDialog::NormalizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormalizeDialog)
{
    ui->setupUi(this);
}

NormalizeDialog::~NormalizeDialog()
{
    delete ui;
}



