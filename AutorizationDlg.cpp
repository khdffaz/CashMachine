#include "AutorizationDlg.h"
#include "ui_AutorizationDlg.h"

AutorizationDlg::AutorizationDlg(Manager *manager, LanguageTexts *languageTexts) :
    ui(new Ui::AutorizationDlg)
{
    this->manager = manager;
    this->languageTexts = languageTexts;

    ui->setupUi(this);

    ui->autorizationTitleLabel->setText(this->languageTexts->getDlgElementText("autorizationTitleLabel"));
    ui->cardNumberLabel->setText(this->languageTexts->getDlgElementText("cardNumberLabel"));
    ui->pinLabel->setText(this->languageTexts->getDlgElementText("pinLabel"));
    ui->autorizationPushButton->setText(this->languageTexts->getDlgElementText("autorizationPushButton"));
}

AutorizationDlg::~AutorizationDlg()
{
    delete ui;
}

void AutorizationDlg::on_autorizationPushButton_clicked()
{
    QString cardNumber = ui->cardNumberLineEdit->text();
    QString pin = ui->pinLineEdit->text();

    //считывание номера карты и пина
    //проверка номера карты на длину и цифры
    bool flag = true;
    if ((cardNumber.isEmpty()) && (pin.isEmpty()))
    {
        ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgEmptyNumberEmptyPINLabel"));
        flag = false;
        return;
    }
    else
        if (cardNumber.isEmpty())
        {
            ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgEmptyNumberLabel"));
            flag = false;
            return;
        }
        else
            if (pin.isEmpty())
        {
            ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgEmptyPINLabel"));
            flag = false;
            return;
        }
    if (flag)
    {
        if (cardNumber.length() != 16)
        {
            ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgInputDataWrongLengthLabel"));
            ui->pinLineEdit->clear();
            return;
        }

        for (int i = 0; i < cardNumber.length(); i++)
        {
            if (!cardNumber[i].isDigit())
            {
                ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgWrongSymbolsLabel"));
                ui->pinLineEdit->clear();
                return;
            }
        }

        if (pin.length() != 4)
        {
            ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgInputDataWrongLengthLabel"));
            ui->pinLineEdit->clear();
            return;
        }

        for (int i = 0; i < pin.length(); i++)
        {
            if (!pin[i].isDigit())
            {
                ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgWrongSymbolsLabel"));
                ui->pinLineEdit->clear();
                return;
            }
        }

        int status = 0;//manager->checkValidAuthorization(cardNumber, pin);

        if(status == 0)
        {
            manager->setAuthorizedCard(cardNumber);
        }
        else
        {
            if (status == 1)
            {
                //сообщение нет карты
                ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgWrongCardNumberLabel"));
                ui->pinLineEdit->clear();
                return;
            }
            else
            {
                //сообщение неверный пин
                ui->errorAutorizationDlgLabel->setText(this->languageTexts->getDlgElementText("errorAutorizationDlgWrongPINLabel"));
                ui->pinLineEdit->clear();
                return;
            }
        }
    }
}
