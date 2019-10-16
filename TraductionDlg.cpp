#include "TraductionDlg.h"
#include "ui_TraductionDlg.h"

TraductionDlg::TraductionDlg(Manager* manager) :
    ui(new Ui::TraductionDlg)
{
    ui->setupUi(this);
    this->manager = manager;
}

TraductionDlg::~TraductionDlg()
{
    delete ui;
}

void TraductionDlg::on_traductionOkayPushButton_clicked()
{
    //������ ��������
    if (ui->traductionCardNumberLineEdit->text().isEmpty() || ui->traductionSumLineEdit->text().isEmpty())
    {
        //����� ��������� � ������ � ������ ������
        return;
    }

    QString cardNumber = ui->traductionCardNumberLineEdit->text();

    if (cardNumber.length() != 16)
    {
        //����� ��������� � ������ � �������� ������
        return;
    }

    for (int i = 0; i < cardNumber.length(); i++)
    {
        if (!cardNumber[i].isDigit())
        {
            //����� ��������� � ������ � �������� ������ �����
            return;
        }
   }

    if(!manager->isCardExist(cardNumber)) {
        //����� ��������� � ������ ����� �� ����������
        return;
    }

    int traductionSum = -1;
    if (sscanf(ui->traductionSumLineEdit->text().toStdString().c_str(), "%d", &traductionSum) != 1 || traductionSum < 0)
    {
        //����� ��������� � ������ ������� ������� �����
        return;
    }

    if(manager->isAvailableSum(traductionSum)){
        //����� ��������� � ������ ��� �������
         return;
    }

    manager->traductSum(cardNumber, traductionSum);

    ui->traductionCardNumberLineEdit->clear();
    ui->traductionSumLineEdit->clear();
}
