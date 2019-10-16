#include "Manager.h"

Manager::Manager()
{
    languageTexts = new LanguageTexts();
    cashOperations = new CashOperations();
    cashManager = new CashManager();
}

Manager::~Manager()
{
    delete languageTexts;
    delete cashOperations;
    delete cashManager;
}

void Manager::startWork()
{
    openLanguageDlg();
}
void Manager::openAutorizationDlg()
{
    autorizationDlg = new AutorizationDlg(this, languageTexts);
    autorizationDlg->show();
}
void Manager::openLanguageDlg()
{
    languageDlg = new LanguageDlg(this);
    languageDlg->show();
}

void Manager::setLanguage(Language language)
{
    languageTexts->setLanguage(language);
    languageDlg->close();
    delete languageDlg;

    openAutorizationDlg();
}



void Manager::setAuthorizedCard(QString cardNumber)
{
    autorizationDlg->close();
    delete autorizationDlg;

    //cashOperations->setCardNumber(cardNumber);

    menu = new Menu(this, languageTexts);
    menu->show();
}

void Manager::addCash(int value)
{
    cashOperations->addCash(value);
}

void Manager::printBill()
{
    cashOperations->printBill();
}

void Manager::printBalance()
{
    cashOperations->printBalance();

}

int Manager::checkWithdrawSum(int value)
{
    if (!cashManager->isAvailableSum(value)) {
        return 1;
    }

    if (!cashOperations->isAvailableSum(value)) {
        return 2;
    }

    return 0;
    // 0 все хорошо
    // 1 нет денег в банкомате
    // 2 нет денег на счете
}


bool Manager::isAvailableSum(int sum) {
    return cashOperations->isAvailableSum(sum);
}

void Manager::addMobileCash(int value, long number) {
    cashOperations->withdrawCash(value);

    //запись в файл о пополнении счета телефона
}

bool Manager::isAvailableDignity(int sum, CashDignity cashDignity)
{
    return cashManager->isAvailableDignity(sum, cashDignity);
}

bool Manager::isCardExist(QString cardNumber)
{
    std::ifstream file;
    file.open("CardsStorage.txt");
    if (!file.is_open())
        return false;

    QString fCardNumber;
    while (!file.eof())
    {
        if (fCardNumber.compare(cardNumber) == 0)
            return true;
        else
            return false;
    }
}

int Manager::checkValidAuthorization(QString cardNumber, QString pin)
{
    int status = 1;
    std::ifstream file;
    file.open("CardsStorage.txt");
    if (!file.is_open())
        return status;

    std::string buf;
    char tmpCardNumber[17];
    char tmpPin[5];
    while (!file.eof())
    {
        std::getline(file, buf);

        if (sscanf(buf.c_str(), "%s\t%s", tmpCardNumber, tmpPin) == 2)
        {
            QString fCardNumber(tmpCardNumber);
            QString fPin(tmpPin);

            if (fCardNumber.compare(cardNumber) == 0)
            {
                if(fPin.compare(pin) == 0)
                {
                    status = 0;
                }
                else
                {
                    status = 2;
                }
            }
        }
    }

    file.close();
    return status;


    // 0 - все верно
    // 1 - нет карты
    // 2 - неверный пин
}

void Manager::traductSum(QString cardNumber, int sum)
{
    cashOperations->withdrawCash(sum);

    //в файле найти карту и увеличить сумму
    //записать в файл о переводе средств
}

void Manager::withdrawCash(int sum, CashDignity cashDignity)
{
    QMap<int, int> dignities = cashManager->getCash(sum, cashDignity);
    cashOperations->withdrawCash(sum);
    cashOperations->printBill(dignities);
}

void Manager::returnCard()
{
    cashOperations->closeOperations();
    menu->close();
    delete menu;
    startWork();
}

bool Manager::checkPayments(QString paymentsNumber, PaymentType paymentType, int *sum)
{
    //чтение из файла комм платежей (номер, тип, сумма на счету)
    //найти в этом файле запись с предоставлеными данными
    //если есть то *sum присвоить значение и return true else return false
    return true;
}

 void Manager::addPaymentCash(QString number,PaymentType paymentType, int cashValue){
     cashOperations->withdrawCash(cashValue);

     std::ofstream file_out;
     file_out.open("Payments.txt");
     if (!file_out.is_open())
         return;

     file_out << cashValue << "\t";
     file_out.close();

     cashOperations->printBill();

     //запись в файл операций
 }
