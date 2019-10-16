#include "CashOperations.h"

CashOperations::CashOperations()
{
    cash = 0;
}

CashOperations::~CashOperations()
{
    if (lastOperation != NULL)
       delete lastOperation;
}

void CashOperations::closeOperations() {
    cardNumber = "";
    cash = 0;
    cashType = NoType;
    lastOperation = 0;
}

void CashOperations::setCardNumber(QString cardNumber)
{
    this->cardNumber = cardNumber;

    std::ifstream file;
    file.open("CardsCash.txt");
    if (!file.is_open())
        return;

    std::string buf;
    char tmpCardNumber[13];
    int tmpCash;
    char tmpCashType[4];
    while (!file.eof())
    {
        std::getline(file, buf);

        if (sscanf(buf.c_str(), "%s\t%d\t%s", tmpCardNumber, &tmpCash, tmpCashType) == 3)
        {
            QString fCardNumber(tmpCardNumber);
            QString fCashType(tmpCashType);

            if (fCardNumber.compare(cardNumber) == 0)
            {
                this->cash = tmpCash;
                if (fCashType.compare("RUS") == 0)
                {
                    this->cashType = RUS;
                }
                else
                    this->cashType = USD;

            }
        }

    // из файла получить cashType и cash
    }
    file.close();
}

void CashOperations::addCash(int value)
{
    cash += value;
    std::ofstream file_out;
    file_out.open("CardsCash.txt");
    if (!file_out.is_open())
        return;

    file_out << cash << "\t";
    file_out.close();

    lastOperation = new Operation();
    lastOperation->setOperationType(AddCash);
    //lastOperation->setCashSum(value);
    //lastOperation->setOperationDate(new QDate());

    //запись в файл операций
}

void CashOperations::withdrawCash(int sum)
{
    cash -= sum;
    std::ofstream file_out;
    file_out.open("CardsCash.txt");
    if (!file_out.is_open())
        return;

    file_out << cash << "\t";
    file_out.close();

    lastOperation = new Operation();
    lastOperation->setOperationType(WithdrawCash);
    //lastOperation->setCashSum(sum);
    //lastOperation->setOperationDate(new QDate());

    //запись в файл операций
}

void CashOperations::printBill()
{
    if (lastOperation != NULL)
    {
       // в файл пишешь чек по операции
    }
}

void CashOperations::printBill(QMap<int, int> dignities)
{
    //вывести чек в файл о снятии денег
    QMapIterator<int, int> i(dignities);
    while (i.hasNext())
    {
        i.next();
        int dignity = i.key();
        int count = i.value();
    }
}

void CashOperations::printBalance()
{
    //пишем в файл баланс
}
