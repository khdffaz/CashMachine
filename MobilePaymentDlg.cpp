#include "MobilePaymentDlg.h"
#include "ui_MobilePaymentDlg.h"

MobilePaymentDlg::MobilePaymentDlg(Manager *manager) :
    ui(new Ui::MobilePaymentDlg)
{
    ui->setupUi(this);
    this->manager = manager;
}

MobilePaymentDlg::~MobilePaymentDlg()
{
    delete ui;
}

void MobilePaymentDlg::on_mobileOkayPushButton_clicked()
{
    ui->mobilePaymentTextBrowser->clear();
    if (ui->mobileNumberLineEdit->text().isEmpty() || ui->mobileSumLineEdit->text().isEmpty())
    {
        //����� ��������� � ������ � ������ ������
        return;
    }

    long mobileNumber;
    if (sscanf(ui->mobileNumberLineEdit->text().toStdString().c_str(), "%ld", &mobileNumber) != 1)
    {
        //����� ��������� � ������ ������� ������ �����
        return;
    }
    if (ui->mobileNumberLineEdit->text().length() != 10) {
        //����� ��������� � ������ �������� ����� ������
        return;
    }

    int mobileSum = -1;
    if (sscanf(ui->mobileSumLineEdit->text().toStdString().c_str(), "%d", &mobileSum) != 1 || mobileSum < 0)
    {
        //����� ��������� � ������ ������� ������� �����
        return;
    }

    if(manager->isAvailableSum(mobileSum)){
        //����� ��������� � ������ ��� �������
         return;
    }

    manager->addMobileCash(mobileSum, mobileNumber);

    ui->mobileNumberLineEdit->clear();
    ui->mobileSumLineEdit->clear();
}
