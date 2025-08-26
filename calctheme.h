#ifndef CALCTHEME_H
#define CALCTHEME_H

#include <QColor>
#include <QString>

class CalcTheme
{
public:
    CalcTheme();

    QColor getPrimaryColor();
    QColor getSecondaryColor();
    QColor getTextColor();

    void setPrimaryColor(QColor);
    void setSecondaryColor(QColor);
    void setTextColor(QColor);

    void readFromFile(QString path);
    void saveToFile(QString path);

private:
    QColor primaryColor;
    QColor secondaryColor;
    QColor textColor;
};

#endif // CALCTHEME_H
