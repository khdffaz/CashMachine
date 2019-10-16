#ifndef LANGUAGEDLG_H
#define LANGUAGEDLG_H

#include <QMainWindow>
#include "Manager.h"
#include "Language.h"

namespace Ui
{
    class LanguageDlg;
}

class Manager;

class LanguageDlg : public QMainWindow
{
    Q_OBJECT
    
public:
    LanguageDlg(Manager* manager);
    ~LanguageDlg();

    
private slots:
    void on_NextPushButton_clicked();



private:
    Ui::LanguageDlg *ui;
    Manager *manager;
};

#endif // LANGUAGEDLG_H
