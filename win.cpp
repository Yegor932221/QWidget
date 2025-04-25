#include "win.h"
#include <QValidator>

win::win(QWidget *parent) : QWidget(parent)
{
    // Установка кодировки UTF-8
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    setWindowTitle(QString::fromUtf8("Возведение в квадрат"));

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel(QString::fromUtf8("Введите число:"), this);
    inputEdit = new QLineEdit("", this);

    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    outputLabel = new QLabel(QString::fromUtf8("Результат:"), this);
    outputEdit = new QLineEdit("", this);

    nextButton = new QPushButton(QString::fromUtf8("Следующее"), this);
    exitButton = new QPushButton(QString::fromUtf8("Выход"), this);

    // Компоновка приложения
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    // Подключение сигналов и слотов с современным синтаксисом
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
    connect(nextButton, &QPushButton::clicked, this, &win::begin);
    connect(inputEdit, &QLineEdit::returnPressed, this, &win::calc);
}

void win::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
            codec->toUnicode("Возведение в квадрат."),
            codec->toUnicode("Введено неверное значение."),
            QMessageBox::Ok);
            msgBox.exec();
        }
}
