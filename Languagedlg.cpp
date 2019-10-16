#include "Languagedlg.h"
#include "ui_Languagedlg.h"

LanguageDlg::LanguageDlg(Manager *manager) :
    ui(new Ui::LanguageDlg)
{
    this->manager = manager;

    ui->setupUi(this);
    ui->rusRadioButton->setChecked(true);
}

LanguageDlg::~LanguageDlg()
{
    delete ui;
}

void LanguageDlg::on_NextPushButton_clicked()
{
    if (ui->rusRadioButton->isChecked())
        manager->setLanguage(Russian);
    else
        manager->setLanguage(English);
}
