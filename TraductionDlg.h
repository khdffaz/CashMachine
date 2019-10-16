#ifndef TRADUCTIONDLG_H
#define TRADUCTIONDLG_H

#include <QDialog>
#include "Manager.h"

namespace Ui
{
    class TraductionDlg;
}

class Manager;

class TraductionDlg : public QDialog
{
    Q_OBJECT
    
public:
    TraductionDlg(Manager* manager);
    ~TraductionDlg();
    
private slots:
    void on_traductionOkayPushButton_clicked();

private:
    Ui::TraductionDlg *ui;
    Manager* manager;
};

#endif // TRADUCTIONDLG_H



