#include "calcui.h"

#include <QFont>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <calctheme.h>

QFont mFont("Source Code Pro",30);
CalcTheme theme;

CalcUI::CalcUI(bool dark,QWidget *parent) : QWidget(parent){

    if (dark == false){
        theme.setTextColor(QColor(QLatin1String("#000000")));
        theme.setPrimaryColor(QColor(QLatin1String("#FFFFFF")));
    }else{
        theme.setTextColor(QColor(QLatin1String("#FFFFFF")));
        theme.setPrimaryColor(QColor(QLatin1String("#000000")));
    }

    solver = new ExpSolver();
    QVBoxLayout *root = new QVBoxLayout(this);
    QGridLayout *padView = new QGridLayout(this);
    padView->addWidget(flatButton('A',SLOT(clean())) ,0,0);
    padView->addWidget(flatButton('C',SLOT(clear())) ,0,1);
    padView->addWidget(flatButton('^',SLOT(opClick())),0,2);
    padView->addWidget(flatButton('/',SLOT(opClick())),0,3);

    padView->addWidget(flatButton('7',SLOT(numpadClick())),1,0);
    padView->addWidget(flatButton('8',SLOT(numpadClick())),1,1);
    padView->addWidget(flatButton('9',SLOT(numpadClick())),1,2);
    padView->addWidget(flatButton('*',SLOT(opClick())),1,3);

    padView->addWidget(flatButton('4',SLOT(numpadClick())),2,0);
    padView->addWidget(flatButton('5',SLOT(numpadClick())),2,1);
    padView->addWidget(flatButton('6',SLOT(numpadClick())),2,2);
    padView->addWidget(flatButton('-',SLOT(opClick()))    ,2,3);

    padView->addWidget(flatButton('1',SLOT(numpadClick())),3,0);
    padView->addWidget(flatButton('2',SLOT(numpadClick())),3,1);
    padView->addWidget(flatButton('3',SLOT(numpadClick())),3,2);
    padView->addWidget(flatButton('+',SLOT(opClick()))    ,3,3);

    padView->addWidget(flatButton('0',SLOT(numpadClick())),4,0,1,2);
    padView->addWidget(flatButton('.',SLOT(opClick()))    ,4,2);
    padView->addWidget(flatButton('=',SLOT(math()))       ,4,3);

    exprView->setReadOnly(true);
    exprView->setAlignment(Qt::AlignRight);
    exprView->setMaxLength(15);
    exprView->setTabletTracking(false);
    QString style = "background : " + theme.getPrimaryColor().name(QColor::HexArgb) + ";" +
                    "color : " + theme.getTextColor().name(QColor::HexArgb) + ";";
    exprView->setStyleSheet(style);
    exprView->setFont(mFont);

    root->addWidget(exprView);
    root->addLayout(padView);
    setLayout(root);
    setFixedSize(300,400);
    this->setStyleSheet("background : " + theme.getPrimaryColor().name(QColor::HexArgb) + ";");

}

CalcUI::~CalcUI(){}

QPushButton* CalcUI::flatButton(QChar c,const char *slotFun){
    QPushButton *btn = new QPushButton(c,this);
    btn->setFont(mFont);
    btn->setFlat(true);
    QString style = "background : " + theme.getPrimaryColor().name(QColor::HexArgb) + ";" +
                        "color : " + theme.getTextColor().name(QColor::HexArgb) + ";";
    btn->setStyleSheet(style);
    btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(btn, SIGNAL(clicked()), this, slotFun);
    return btn;
}

void CalcUI::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Enter: math(); break;
        case Qt::Key_C: clear(); break;
        case Qt::Key_Q: exit(0); break;
        case Qt::Key_A: clean(); break;
        case Qt::Key_0 : append("0"); break;
        case Qt::Key_1 : append("1"); break;
        case Qt::Key_2 : append("2"); break;
        case Qt::Key_3 : append("3"); break;
        case Qt::Key_4 : append("4"); break;
        case Qt::Key_5 : append("5"); break;
        case Qt::Key_6 : append("6"); break;
        case Qt::Key_7 : append("7"); break;
        case Qt::Key_8 : append("8"); break;
        case Qt::Key_9 : append("9"); break;
        case Qt::Key_Period : append("."); break;
        case Qt::Key_Plus :  append("+"); break;
        case Qt::Key_Minus : append("-"); break;
        case Qt::Key_Slash : append("/"); break;
        case Qt::Key_Asterisk : append("*"); break;
    }
}
void CalcUI::depend(){
    QString tmp = exprView->text();
    int s = tmp.size();
    exprView->setText(tmp.left(s - 1));
}

void CalcUI::append(QString text){
    QString tmp = exprView->text();
    exprView->setText(tmp + text);
}

void CalcUI::math(){
    QString expr = exprView->text();
    QString exp = QString::fromStdString(solver->solveExp(expr.toStdString()));
    exprView->setText(exp);
}

void CalcUI::clean(){
    exprView->setText(nullptr);
}

void CalcUI::clear(){
    depend();
}

void CalcUI::numpadClick(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
       if (exprView->text() == "0")
           return;

    append(clickedButton->text());
}

void CalcUI::opClick(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString tmp = exprView->text();
    if(!tmp.at(tmp.length()-1).isDigit()) return;
    else append(clickedButton->text());
}
