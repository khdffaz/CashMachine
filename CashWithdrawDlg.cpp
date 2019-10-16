#include "CashWithdrawDlg.h"
#include "ui_CashWithdrawDlg.h"

CashWithdrawDlg::CashWithdrawDlg(Manager *manager, LanguageTexts *languageTexts) :
    ui(new Ui::CashWithdrawDlg)
{
    this->manager = manager;
    this->languageTexts = languageTexts;
    ui->largeRadioButton->setChecked(true);
    ui->setupUi(this);
}

CashWithdrawDlg::~CashWithdrawDlg()
{
    delete ui;
}


void CashWithdrawDlg::on_withdrawCashPushButton_clicked()
{
    int withdrawSum = 0;
    QString strCashValue = ui->withdrawCashLineEdit->text();
    if (strCashValue.isEmpty())
        return;

    bool ok = false;
    int cashValue = strCashValue.toInt(&ok);
    if (!ok)
    {
        ui->errorWithdrawCashTextBrowser->setText(this->languageTexts->getDlgElementText("errorCashAddDlgWrongSymbolsLabel"));
        return;
    }
    // считать значение денег
    // проверка что не пусто, что только цифры,
    // проверяем что это число и больше 0 и меньше 100000 и остаток на 10 == 0
    int flag = manager->checkWithdrawSum(withdrawSum);

    if(flag == 1)
    {
         // нет денег в банкомате
        return;
    } else if(flag == 2)
    {
        // нет денег на счете
        return;
    }

    CashDignity cashDignity;
    // проверить, что хоть один выбран чек бокс
    //cashDignity = Large;
    //cashDignity = Small;
    //cashDignity = Different;

    if(!manager->isAvailableDignity(withdrawSum, cashDignity))
    {
        //такими купюрами не могу выдать денег
        return;
    }

    //выдать
    manager->withdrawCash(withdrawSum, cashDignity);

    //операция выполнена
}
