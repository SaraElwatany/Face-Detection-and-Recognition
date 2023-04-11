#ifndef NORMALIZEDIALOG_H
#define NORMALIZEDIALOG_H

#include <QDialog>

namespace Ui {
class NormalizeDialog;
}

class NormalizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NormalizeDialog(QWidget *parent = nullptr);
    ~NormalizeDialog();

private:
    Ui::NormalizeDialog *ui;
};

#endif // NORMALIZEDIALOG_H
