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
    //��������� �� ������������ ���� �������� ������ � ���� (����� ��������, ���) �� �������, ������� ������ �����
    QString number;
    PaymentType paymentType;
    int sum;
    if(!manager->checkPayments(number, paymentType, &sum)){
        //� ������ �������� ����� ��������
    }

    //� Label � ������ ������� sum
}

void PaymentsDlg::on_addPaymentCashPushButton_clicked()
{
    checkPayments();

    //�������
    QString number;
    PaymentType paymentType;

    int cashValue = 0;
    //��������� ����� ����� � �����
    // ��������� ��� ��� ����� � ������ 0 � ������ 100000 � ������� �� 10 == 0
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
            // � ������ ��� ������� ����� �� �����
            return;
        }

        manager->addPaymentCash(number, paymentType, cashValue);

        int sum;
        if(!manager->checkPayments(number, paymentType, &sum)){
            //� ������ �������� ����� ��������
        }

        //� Label � ������ ������� sum
    }
    else
    {
        ui->errorCashAddDlgLabel->setText(this->languageTexts->getDlgElementText("errorCashAddDlgWrongValueLabel"));
        return;
    }
}
