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
        //вывод сообщения в статус о пустых данных
        return;
    }

    long mobileNumber;
    if (sscanf(ui->mobileNumberLineEdit->text().toStdString().c_str(), "%ld", &mobileNumber) != 1)
    {
        //вывод сообщения в статус неверно введен номер
        return;
    }
    if (ui->mobileNumberLineEdit->text().length() != 10) {
        //вывод сообщения в статус неверная длина номера
        return;
    }

    int mobileSum = -1;
    if (sscanf(ui->mobileSumLineEdit->text().toStdString().c_str(), "%d", &mobileSum) != 1 || mobileSum < 0)
    {
        //вывод сообщения в статус неверно введена сумма
        return;
    }

    if(manager->isAvailableSum(mobileSum)){
        //вывод сообщения в статус нет средств
         return;
    }

    manager->addMobileCash(mobileSum, mobileNumber);

    ui->mobileNumberLineEdit->clear();
    ui->mobileSumLineEdit->clear();
}
