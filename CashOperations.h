#ifndef CASHOPERATIONS_H
#define CASHOPERATIONS_H
#include "QString"
#include "QVector"
#include "Operation.h"
#include "QString"
#include "fstream"
#include "stdlib.h"
#include "OperationType.h"
#include <QMap>

enum CashType
{
    RUS,
    USD,
    NoType
};


class CashOperations
{
private:
    QString cardNumber;
    int cash;
    CashType cashType;
    Operation* lastOperation;

public:
    CashOperations();
    ~CashOperations();
    void setCardNumber(QString cardNumber);
    QString getCardNumber(){return cardNumber;}
    bool isAvailableSum(int sum) {return sum <= cash;}
    void addCash(int value);
    void withdrawCash(int sum);
    void printBill();
    void printBill(QMap<int, int> dignities);
    void printBalance();
    int getCash(){return cash;}
    void closeOperations();
};

#endif // CASHOPERATIONS_H
