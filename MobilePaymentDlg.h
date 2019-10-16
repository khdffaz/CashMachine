#ifndef MOBILEPAYMENTDLG_H
#define MOBILEPAYMENTDLG_H

#include <QDialog>
#include "LanguageTexts.h"
#include "Manager.h"

class Manager;

namespace Ui
{
    class MobilePaymentDlg;
}

class MobilePaymentDlg : public QDialog
{
    Q_OBJECT
    
public:
    MobilePaymentDlg(Manager *manager);
    ~MobilePaymentDlg();
    
private slots:
    void on_mobileOkayPushButton_clicked();

private:
    Ui::MobilePaymentDlg *ui;
    Manager *manager;

};

#endif // MOBILEPAYMENTDLG_H
