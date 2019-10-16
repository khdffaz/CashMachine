#ifndef MANAGER_H
#define MANAGER_H
#include "Languagedlg.h"
#include "Language.h"
#include "LanguageTexts.h"
#include "AutorizationDlg.h"
#include "CashOperations.h"
#include "Menu.h"
#include "QString"
#include "fstream"
#include "CashManager.h"
#include "PaymentType.h"

class LanguageDlg;
class AutorizationDlg;
class Menu;
class LanguageTexts;
class CashAddDlg;

#include <QMap>

class Manager
{

public:
    Manager();
    ~Manager();

    void startWork();
    void setLanguage(Language language);
    void setAuthorizedCard(QString cardNumber);
    int checkValidAuthorization(QString cardNumber, QString pin);
    void addCash(int value);
    void printBill();
    void printBalance();
    int getBalance(){return cashOperations->getCash();}
    int checkWithdrawSum(int value);
    bool isAvailableDignity(int sum, CashDignity cashDignity);
    void withdrawCash(int sum, CashDignity cashDignity);
    bool isAvailableSum(int sum);
    void addMobileCash(int value, long number);
    bool isCardExist(QString cardNumber);
    void traductSum(QString cardNumber, int sum);
    void returnCard();
    bool checkPayments(QString paymentsNumber, PaymentType paymentType, int* sum);
    void addPaymentCash(QString number,PaymentType paymentType, int cashValue);

private:
    LanguageDlg *languageDlg;
    LanguageTexts *languageTexts;
    AutorizationDlg *autorizationDlg;
    CashOperations *cashOperations;
    CashManager* cashManager;
    Menu *menu;

    void openAutorizationDlg();
    void openLanguageDlg();
};

#endif // MANAGER_H
