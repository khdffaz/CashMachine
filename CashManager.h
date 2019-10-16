#ifndef CASHMANAGER_H
#define CASHMANAGER_H

#include <QMap>
#include "CashDignity.h"

class CashManager
{
private:
    int cashValue;
    QMap<int, int> cashMap;
    int addTmpSum(int sum, int* tmpSum, int diginity, int count);
    int getTmpSum(int sum, int* tmpSum, int diginity, int count);
    bool isAvailableLarge(int sum);
    bool isAvailableSmall(int sum);
    QMap<int, int> getLargeCash(int sum);
    QMap<int, int> getSmallCash(int sum);

public:
    CashManager();
    int getCashValue(){return cashValue;}
    bool isAvailableSum(int sum) {return sum <= cashValue;}
    bool isAvailableDignity(int sum, CashDignity cashDignity);
    QMap<int, int> getCash(int sum, CashDignity cashDignity);
};

#endif // CASHMANAGER_H
