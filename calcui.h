#ifndef CALCUI_H
#define CALCUI_H

#include "exprsolver.h"
#include <QLineEdit>
#include <QPushButton>

class CalcUI : public QWidget{
   Q_OBJECT
private:
    QLineEdit *exprView = new QLineEdit(this);
    ExpSolver *solver;
public:
    CalcUI(bool dark,QWidget *parent = 0);
    ~CalcUI();
private:
    QPushButton* flatButton(QChar c,const char *slotFun);
    void keyPressEvent(QKeyEvent *event) override;
    void depend();
    void append(QString text);
private slots:
    void math();
    void clean();
    void clear();
    void numpadClick();
    void opClick();
};

#endif // CALCUI_H
