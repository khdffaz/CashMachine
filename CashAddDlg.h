#ifndef CASHADDDLG_H
#define CASHADDDLG_H
#include "Manager.h"
#include "LanguageTexts.h"
#include <QDialog>
#include <QMessageBox>
#include <QString>

class Manager;
class LanguageTexts;

namespace Ui {
class CashAddDlg;
}

class CashAddDlg : public QDialog
{
    Q_OBJECT
    
public:
    CashAddDlg(Manager *manager, LanguageTexts *languageTexts);
    ~CashAddDlg();
    
private slots:
    void on_addCashPushButton_clicked();

    void on_cancelAddCashPushButton_clicked();

    void on_CashAddDlg_destroyed();

    void on_CashAddDlg_finished(int result);

    void on_CashAddDlg_rejected();

private:
    Ui::CashAddDlg *ui;
    Manager *manager;
    LanguageTexts *languageTexts;
};

#endif // CASHADDDLG_H
