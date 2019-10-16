#ifndef OPERATION_H
#define OPERATION_H
#include "QDate"
#include "OperationType.h"

class Operation
{
private:
    OperationType operationType;
    int cashSum;
    QDate *operationDate;

public:
    void setOperationType(OperationType operationType) {this->operationType = operationType;}
    OperationType getOperationType() {return operationType;}
    void setCashSum (int cashSum) {this->cashSum = cashSum;}
    int getCashSum(){return cashSum;}
    void setOperationDate(QDate *operationDate){this->operationDate = operationDate;}
    QDate* getOperationDate() {return operationDate;}
    //get and set for cashSum, operationDate
};

#endif // OPERATION_H
