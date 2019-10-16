#ifndef MENU_H
#define MENU_H

#include "Manager.h"
#include "CashAddDlg.h"
#include "CashWithdrawDlg.h"
#include <QDialog>
#include "LanguageTexts.h"
#include "QMessageBox"
#include "MobilePaymentDlg.h"
#include "TraductionDlg.h"
#include "PaymentsDlg.h"

class Manager;
class CashAddDlg;
class CashWithdrawDlg;
class MobilePaymentDlg;
class TraductionDlg;
class PaymentsDlg;

namespace Ui
{
    class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT
    
public:
    Menu(Manager *manager,LanguageTexts *languageTexts);
    ~Menu();
    
private slots:
    void on_addCashMenuPushButton_clicked();

    void on_showBalanceMenuPushButton_clicked();

    void on_withdrawCashMenuPushButton_clicked();

    void on_mobilePaymentsMenuPushButton_clicked();

    void on_traductionMenuPushButton_clicked();

    void on_returnCardPushButton_clicked();

    void on_paymentsMenuPushButton_clicked();

private:
    Ui::Menu *ui;
    Manager *manager;
    CashAddDlg *cashAddDlg;
    LanguageTexts *languageTexts;
    CashWithdrawDlg* cashWithdrawDlg;
    MobilePaymentDlg* mobilePaymentDlg;
    TraductionDlg* traductionDlg;
    PaymentsDlg* paymentsDlg;
};

#endif // MENU_H
