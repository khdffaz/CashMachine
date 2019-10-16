#ifndef LANGUAGETEXTS_H
#define LANGUAGETEXTS_H
#include "Language.h"
#include "QString"
#include "fstream"
#include "AutorizationDlg.h"

class LanguageTexts
{
private:
    Language language;

public:
    LanguageTexts();

    void setLanguage(Language language){this->language = language;}
    Language getLanguage(){return language;}

    QString getDlgElementText(QString elementName);//получить текст для label из файла
};

#endif // LANGUAGETEXTS_H
