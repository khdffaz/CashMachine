#include "PaymentsDlg.h"
#include "ui_PaymentsDlg.h"

PaymentsDlg::PaymentsDlg(Manager *manager, LanguageTexts *languageTexts)
    :ui(new Ui::PaymentsDlg)
{
    this->manager = manager;
    this->languageTexts = languageTexts;
    ui->setupUi(this);
}

PaymentsDlg::~PaymentsDlg()
{
    delete ui;
}

void PaymentsDlg::on_paymentCheckPushButton_clicked()
{
    checkPayments();
}

void PaymentsDlg::checkPayments() {
    //проверить на правильность всех вводимых данных в окне (номер договора, тип) не пустные, договор только цифры
    QString number;
    PaymentType paymentType;
    int sum;
    if(!manager->checkPayments(number, paymentType, &sum)){
        //в статус неверный номер договора
    }

    //в Label с суммой вывести sum
}

void PaymentsDlg::on_addPaymentCashPushButton_clicked()
{
    checkPayments();

    //считать
    QString number;
    PaymentType paymentType;

    int cashValue = 0;
    //считываем сумму денег с формы
    // проверяем что это число и больше 0 и меньше 100000 и остаток на 10 == 0
    QString strCashValue = ui->addPaymentCashLineEdit->text();
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
        if(!manager->isAvailableSum(cashValue)){
            // в статус нет столько денег на карте
            return;
        }

        manager->addPaymentCash(number, paymentType, cashValue);

        int sum;
        if(!manager->checkPayments(number, paymentType, &sum)){
            //в статус неверный номер договора
        }

        //в Label с суммой вывести sum
    }
    else
    {
        ui->errorCashAddDlgLabel->setText(this->languageTexts->getDlgElementText("errorCashAddDlgWrongValueLabel"));
        return;
    }
}
