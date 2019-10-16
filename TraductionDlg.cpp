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
    //статус очистить
    if (ui->traductionCardNumberLineEdit->text().isEmpty() || ui->traductionSumLineEdit->text().isEmpty())
    {
        //вывод сообщения в статус о пустых данных
        return;
    }

    QString cardNumber = ui->traductionCardNumberLineEdit->text();

    if (cardNumber.length() != 16)
    {
        //вывод сообщения в статус о неверных длинна
        return;
    }

    for (int i = 0; i < cardNumber.length(); i++)
    {
        if (!cardNumber[i].isDigit())
        {
            //вывод сообщения в статус о неверных данных карты
            return;
        }
   }

    if(!manager->isCardExist(cardNumber)) {
        //вывод сообщения в статус карты не существует
        return;
    }

    int traductionSum = -1;
    if (sscanf(ui->traductionSumLineEdit->text().toStdString().c_str(), "%d", &traductionSum) != 1 || traductionSum < 0)
    {
        //вывод сообщения в статус неверно введена сумма
        return;
    }

    if(manager->isAvailableSum(traductionSum)){
        //вывод сообщения в статус нет средств
         return;
    }

    manager->traductSum(cardNumber, traductionSum);

    ui->traductionCardNumberLineEdit->clear();
    ui->traductionSumLineEdit->clear();
}
