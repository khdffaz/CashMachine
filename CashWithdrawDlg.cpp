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
    // ������� �������� �����
    // �������� ��� �� �����, ��� ������ �����,
    // ��������� ��� ��� ����� � ������ 0 � ������ 100000 � ������� �� 10 == 0
    int flag = manager->checkWithdrawSum(withdrawSum);

    if(flag == 1)
    {
         // ��� ����� � ���������
        return;
    } else if(flag == 2)
    {
        // ��� ����� �� �����
        return;
    }

    CashDignity cashDignity;
    // ���������, ��� ���� ���� ������ ��� ����
    //cashDignity = Large;
    //cashDignity = Small;
    //cashDignity = Different;

    if(!manager->isAvailableDignity(withdrawSum, cashDignity))
    {
        //������ �������� �� ���� ������ �����
        return;
    }

    //������
    manager->withdrawCash(withdrawSum, cashDignity);

    //�������� ���������
}
