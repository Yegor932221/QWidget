#include "win.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
win::win()
{
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
codec = QTextCodec::codecForName("Windows-1251");
this->setWindowTitle(QString::fromUtf8("Обработка событий"));
area = new Area( this );
btn = new QPushButton(QString::fromUtf8("Завершить"),this );
QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(area);
layout->addWidget(btn);
connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};
