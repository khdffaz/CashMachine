#ifndef PAYMENTSDLG_H
#define PAYMENTSDLG_H

#include <QDialog>
#include "Manager.h"
#include "LanguageTexts.h"
#include "PaymentType.h"

namespace Ui {
class PaymentsDlg;
}

class PaymentsDlg : public QDialog
{
    Q_OBJECT
    
public:
    PaymentsDlg(Manager *manager, LanguageTexts *languageTexts);
    ~PaymentsDlg();
    
private slots:
    void on_paymentCheckPushButton_clicked();
    void on_addPaymentCashPushButton_clicked();
    void checkPayments();

private:
    Ui::PaymentsDlg *ui;
    Manager *manager;
    LanguageTexts *languageTexts;
};

#endif // PAYMENTSDLG_H
