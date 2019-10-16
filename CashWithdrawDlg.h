#ifndef CASHWITHDRAWDLG_H
#define CASHWITHDRAWDLG_H

#include <QDialog>
#include "Manager.h"
#include "LanguageTexts.h"

class Manager;
class LanguageTexts;

namespace Ui
{
    class CashWithdrawDlg;
}

class CashWithdrawDlg : public QDialog
{
    Q_OBJECT
    
public:
    CashWithdrawDlg(Manager *manager, LanguageTexts *languageTexts);
    ~CashWithdrawDlg();
    
private slots:
    void on_cancelWithdrawCashPushButton_clicked();

    void on_withdrawCashPushButton_clicked();

private:
    Ui::CashWithdrawDlg *ui;
    Manager *manager;
    LanguageTexts *languageTexts;
};

#endif // CASHWITHDRAWDLG_H
