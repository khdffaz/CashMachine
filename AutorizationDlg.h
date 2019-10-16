#ifndef AUTORIZATIONDLG_H
#define AUTORIZATIONDLG_H
#include <cstdlib>
#include "Manager.h"
#include "LanguageTexts.h"
#include "Language.h"

#include <QMainWindow>

namespace Ui {
class AutorizationDlg;
}

class Manager;
class LanguageTexts;

class AutorizationDlg : public QMainWindow
{
    Q_OBJECT
    
public:
    AutorizationDlg(Manager *manager, LanguageTexts *languageTexts);
    ~AutorizationDlg();
    
private slots:
    void on_pushButton_clicked();

    void on_autorizationPushButton_clicked();

private:
    Ui::AutorizationDlg *ui;
    Manager *manager;
    LanguageTexts *languageTexts;
    Language language;
};

#endif // AUTORIZATIONDLG_H
