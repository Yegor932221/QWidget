#ifndef win_h
#define win_h
#include<QWidget>
#include <QPushButton>
#include <QTextCodec>
#include "area.h"

class win : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    win();
};
#endif

