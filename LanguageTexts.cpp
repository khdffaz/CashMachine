#include "LanguageTexts.h"

LanguageTexts::LanguageTexts()
{
}

QString LanguageTexts::getDlgElementText(QString elementName)
{
    std::ifstream file;

    if(language == Russian)
    {
        file.open("RussianText.txt");
    }
    else
        if (language == English)
        {
            file.open("EnglishText.txt");
        }

    if(!file.is_open())
        return NULL;

    std::string buf;
    char tmpTitleLabel[128];
    char tmpLabelText[128];

    while (!file.eof())
    {
        std::getline(file, buf);

        if (2 == sscanf(buf.c_str(), "%s\t%s", tmpTitleLabel, tmpLabelText))
        {
            QString titleLabel(tmpTitleLabel);
            QString labelText(tmpLabelText);

            if (titleLabel.compare(elementName) == 0)
            {
                if(labelText.contains("_")) {
                    labelText.replace("_", " ");
                }

                return labelText;
            }
        }
    }
    file.close();
    return "";
}
