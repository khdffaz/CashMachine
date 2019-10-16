#include "CashManager.h"

CashManager::CashManager()
{
    cashMap.insert(5000, 10);
    cashMap.insert(1000, 50);
    cashMap.insert(500, 100);
    cashMap.insert(100, 150);
    cashMap.insert(50, 200);
    cashMap.insert(10, 250);

    cashValue = 0;
    QMapIterator<int, int> i(cashMap);
    while (i.hasNext()) {
        i.next();
        cashValue += i.key() * i.value();
    }

}

int CashManager::addTmpSum(int sum, int* tmpSum, int diginity, int count) {
    for(int i = 1; i <= count; i++) {
        *tmpSum += diginity;
        if(*tmpSum > sum) {
            *tmpSum -= diginity;
            return 1;
        } else {
            if(*tmpSum == sum) {
                return 0;
            }
        }
    }
    return 2;
}

bool CashManager::isAvailableLarge(int sum)
{
    int* tmpSum = 0;
    int result = addTmpSum(sum, tmpSum, 5000, cashMap.value(5000));
    if(result == 0)
    {
        return true;
    }
    else
    {
        result = addTmpSum(sum, tmpSum, 1000, cashMap.value(1000));
        if(result == 0)
        {
            return true;
        }
        else
        {
            result = addTmpSum(sum, tmpSum, 500, cashMap.value(500));
            if(result == 0)
            {
                return true;
            }
            else
            {
                result = addTmpSum(sum, tmpSum, 100, cashMap.value(100));
                if(result == 0)
                {
                    return true;
                }
                else
                {
                    result = addTmpSum(sum, tmpSum, 50, cashMap.value(50));
                    if(result == 0)
                    {
                        return true;
                    }
                    else
                    {
                        result = addTmpSum(sum, tmpSum, 10, cashMap.value(10));
                        if(result != 0)
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
}

bool CashManager::isAvailableSmall(int sum)
{
    int* tmpSum = 0;
    int result = addTmpSum(sum, tmpSum, 10, cashMap.value(10));
    if(result == 0)
    {
        return true;
    }
    else
    {
        result = addTmpSum(sum, tmpSum, 50, cashMap.value(50));
        if(result == 0)
        {
            return true;
        }
        else
        {
            result = addTmpSum(sum, tmpSum, 100, cashMap.value(100));
            if(result == 0)
            {
                return true;
            }
            else
            {
                result = addTmpSum(sum, tmpSum, 500, cashMap.value(500));
                if(result == 0)
                {
                    return true;
                }
                else
                {
                    result = addTmpSum(sum, tmpSum, 1000, cashMap.value(1000));
                    if(result == 0)
                    {
                        return true;
                    }
                    else
                    {
                        result = addTmpSum(sum, tmpSum, 5000, cashMap.value(5000));
                        if(result != 0)
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
}

 bool CashManager::isAvailableDignity(int sum, CashDignity cashDignity)
 {
     switch (cashDignity)
     {
         case Large:
         {
             return isAvailableLarge(sum);
         }

         case Small:
         {
            return isAvailableSmall(sum);
         }

         case Different:
         {
            int tmp = sum / 100;
            int tmpOst = sum % 100;
            int sum1 = tmp / 2;
            int sum2 = tmp / 2 + tmpOst;
            if(isAvailableLarge(sum1) && isAvailableSmall(sum2)) {
                return true;
            } else {
                return false;
            }
         }
    }
 }

 int CashManager::getTmpSum(int sum, int* tmpSum, int diginity, int count) {
     int resultCount = 0;
     for(int i = 1; i <= count; i++) {
         *tmpSum += diginity;
         if(*tmpSum > sum) {
             *tmpSum -= diginity;
             return resultCount;
         } else {
             cashValue -= diginity;
             resultCount++;
             if(*tmpSum == sum) {
                 return resultCount;
             }
         }
     }
     return 2;
 }

 QMap<int, int> CashManager::getLargeCash(int sum)
 {
     QMap<int, int> resultMap;
     int* tmpSum = 0;
     int count = getTmpSum(sum, tmpSum, 5000, cashMap.value(5000));
     if(count != 0) {
         resultMap.insert(5000, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 1000, cashMap.value(1000));
     if(count != 0) {
         resultMap.insert(1000, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 500, cashMap.value(500));
     if(count != 0) {
         resultMap.insert(500, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 100, cashMap.value(100));
     if(count != 0) {
         resultMap.insert(100, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 50, cashMap.value(50));
     if(count != 0) {
         resultMap.insert(50, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 10, cashMap.value(10));
     if(count != 0) {
         resultMap.insert(10, count);
     }

     return resultMap;
 }

 QMap<int, int> CashManager::getSmallCash(int sum)
 {
     QMap<int, int> resultMap;
     int* tmpSum = 0;
     int count = getTmpSum(sum, tmpSum, 10, cashMap.value(10));
     if(count != 0) {
         resultMap.insert(10, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 50, cashMap.value(50));
     if(count != 0) {
         resultMap.insert(50, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 100, cashMap.value(100));
     if(count != 0) {
         resultMap.insert(100, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 500, cashMap.value(500));
     if(count != 0) {
         resultMap.insert(500, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 1000, cashMap.value(1000));
     if(count != 0) {
         resultMap.insert(1000, count);
     }

     if (sum == *tmpSum) {
         return resultMap;
     }

     count = getTmpSum(sum, tmpSum, 5000, cashMap.value(5000));
     if(count != 0) {
         resultMap.insert(5000, count);
     }

     return resultMap;
 }

 QMap<int, int> CashManager::getCash(int sum, CashDignity cashDignity)
 {
     switch (cashDignity)
     {
         case Large:
         {
             return getLargeCash(sum);
         }

         case Small:
         {
            return getSmallCash(sum);
         }

         case Different:
         {
           //return NULL;
         }
    }
 }
