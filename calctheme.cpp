#include "calctheme.h"

CalcTheme::CalcTheme(){}

QColor CalcTheme::getPrimaryColor(){return this->primaryColor;}
QColor CalcTheme::getSecondaryColor(){return this->secondaryColor;}
QColor CalcTheme::getTextColor(){return this->textColor;}

void CalcTheme::setPrimaryColor(QColor pri){this->primaryColor = pri;}
void CalcTheme::setSecondaryColor(QColor sec){this->secondaryColor = sec;}
void CalcTheme::setTextColor(QColor tex){this->textColor = tex;}

void CalcTheme::readFromFile(QString path){
    std::printf("TODO readFromFile!!!");
}
void CalcTheme::saveToFile(QString path){
    std::printf("TODO saveToFile!!!");
}
