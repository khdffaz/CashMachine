#include "CashAddDlg.h"
#include "ui_CashAddDlg.h"

CashAddDlg::CashAddDlg(Manager *manager, LanguageTexts *languageTexts) :
    ui(new Ui::CashAddDlg)
{
    this->manager = manager;
    this->languageTexts = languageTexts;
    ui->setupUi(this);
    ui->addCashLabel->setText(this->languageTexts->getDlgElementText("addCashLabel"));
    ui->addCashPushButton->setText(this->languageTexts->getDlgElementText("addCashPushButton"));
    ui->cancelAddCashPushButton->setText(this->languageTexts->getDlgElementText("cancelAddCashPushButton"));
}

CashAddDlg::~CashAddDlg()
{
    delete ui;
}

void CashAddDlg::on_addCashPushButton_clicked()
{
    int cashValue = 0;
    //считываем сумму денег с формы
    // проверяем что это число и больше 0 и меньше 100000 и остаток на 10 == 0
    QString strCashValue = ui->addCashLineEdit->text();
    if (strCashValue.isEmpty())
        return;

    bool ok = false;
    cashValue = strCashValue.toInt(&ok);
    if (!ok)
    {
        ui->errorCashAddDlgLabel->setText(this->languageTexts->getDlgElementText("errorCashAddDlgWrongSymbolsLabel"));
        return;
    }

    if ((cashValue > 0) && (cashValue <= 100000) && (cashValue % 10 == 0))
    {
        ui->errorCashAddDlgLabel->clear();
        manager->addCash(cashValue);

        QMessageBox* info = new QMessageBox(languageTexts->getDlgElementText("billQuestionTitle"),
                                            languageTexts->getDlgElementText("billQuestion"),
                                            QMessageBox::Question, QMessageBox::Yes,
                                            QMessageBox::No, QMessageBox::NoButton | QMessageBox::Escape);
        int n = info->exec();
        delete info;
        if (n == 3) //QMessageBox::Yes
        {
            manager->printBill();
        }

        ui->addCashLineEdit->clear();
        ui->errorCashAddDlgLabel->clear();
        close();
    }
    else
    {
        ui->errorCashAddDlgLabel->setText(this->languageTexts->getDlgElementText("errorCashAddDlgWrongValueLabel"));
        return;
    }

}

void CashAddDlg::on_cancelAddCashPushButton_clicked()
{
    ui->addCashLineEdit->clear();
    ui->errorCashAddDlgLabel->clear();
    close();
}


