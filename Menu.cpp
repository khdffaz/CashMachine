#include "Menu.h"
#include "ui_Menu.h"

Menu::Menu(Manager *manager, LanguageTexts *languageTexts) :
    ui(new Ui::Menu)
{
    this->manager = manager;
    this->languageTexts = languageTexts;
    cashAddDlg = NULL;
    cashWithdrawDlg = NULL;
    mobilePaymentDlg = NULL;
    traductionDlg = NULL;
    paymentsDlg = NULL;
    ui->setupUi(this);
    ui->addCashMenuLabel->setText(this->languageTexts->getDlgElementText("addCashMenuLabel"));
    ui->addCashMenuPushButton->setText(this->languageTexts->getDlgElementText("addCashMenuPushButton"));
    ui->withdrawCashMenuLabel->setText(this->languageTexts->getDlgElementText("withdrawCashMenuLabel"));
    ui->withdrawCashMenuPushButton->setText(this->languageTexts->getDlgElementText("withdrawCashMenuPushButton"));
    ui->showBalanceMenuLabel->setText(this->languageTexts->getDlgElementText("showBalanceMenuLabel"));
    ui->showBalanceMenuPushButton->setText(this->languageTexts->getDlgElementText("showBalanceMenuPushButton"));
    ui->paymentsMenuLabel->setText(this->languageTexts->getDlgElementText("paymentsMenuLabel"));
    ui->mobilePaymentsMenuPushButton->setText(this->languageTexts->getDlgElementText("paymentsMenuPushButton"));
}

Menu::~Menu()
{
    delete ui;
    if(cashAddDlg != NULL)
    {
         delete cashAddDlg;
    }
    if(cashWithdrawDlg != NULL)
    {
         delete cashWithdrawDlg;
    }
    if(mobilePaymentDlg != NULL)
    {
         delete mobilePaymentDlg;
    }
    if(traductionDlg == NULL)
    {
        delete traductionDlg;
    }
    if(paymentsDlg == NULL)
    {
        delete paymentsDlg;
    }
}

void Menu::on_addCashMenuPushButton_clicked()
{
    if(cashAddDlg == NULL)
    {
        cashAddDlg = new CashAddDlg(manager, languageTexts);
    }
    cashAddDlg->show();
}

void Menu::on_showBalanceMenuPushButton_clicked()
{
    QMessageBox* info = new QMessageBox(languageTexts->getDlgElementText("showBalanceMenuLabel"),
                                        languageTexts->getDlgElementText("balanceQuestion"),
                                        QMessageBox::Question, QMessageBox::Yes,
                                        QMessageBox::No, QMessageBox::NoButton | QMessageBox::Escape);
    int n = info->exec();
    delete info;

    if (n == 3)
    {
        manager->printBalance();
    }
    else
    {
         int balance = manager->getBalance();
         info = new QMessageBox(languageTexts->getDlgElementText("balanceTitle"),
                                             languageTexts->getDlgElementText("balanceValue") + " : " + QString::number(balance),
                                             QMessageBox::NoIcon, QMessageBox::Ok,
                                             QMessageBox::NoButton, QMessageBox::NoButton | QMessageBox::Escape);
         info->exec();
         delete info;
    }
}

void Menu::on_withdrawCashMenuPushButton_clicked()
{
    if(cashWithdrawDlg == NULL)
    {
        cashWithdrawDlg = new CashWithdrawDlg(manager, languageTexts);
    }
    cashWithdrawDlg->show();
}

void Menu::on_mobilePaymentsMenuPushButton_clicked()
{
    if(mobilePaymentDlg == NULL)
    {
        mobilePaymentDlg = new MobilePaymentDlg(manager);
    }
    mobilePaymentDlg->show();
}

void Menu::on_traductionMenuPushButton_clicked()
{
    if(traductionDlg == NULL)
    {
        traductionDlg = new TraductionDlg(manager);
    }
    traductionDlg->show();


}

void Menu::on_returnCardPushButton_clicked()
{
    manager->returnCard();
}

void Menu::on_paymentsMenuPushButton_clicked()
{
    if(paymentsDlg == NULL)
    {
        paymentsDlg = new PaymentsDlg(manager, languageTexts);
    }
    paymentsDlg->show();
}
