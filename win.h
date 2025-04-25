#ifndef WIN_H
#define WIN_H

#include <QtWidgets>  // Вместо устаревшего <QtGui>
#include <QWidget>
#include <QTextCodec>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

class win : public QWidget
{
    Q_OBJECT

protected:
    QTextCodec *codec;
    QFrame *frame;
    QLabel *inputLabel;
    QLineEdit *inputEdit;
    QLabel *outputLabel;
    QLineEdit *outputEdit;
    QPushButton *nextButton;
    QPushButton *exitButton;

public:
    explicit win(QWidget *parent = nullptr);  // explicit только для конструктора
    virtual ~win() = default;

public slots:
    void begin();
    void calc();
};

class StrValidator : public QValidator
{
public:
    explicit StrValidator(QObject *parent = nullptr):QValidator(parent){}  // Добавлен explicit и nullptr
    virtual QValidator::State validate(QString &str, int &pos) const override
    {
        Q_UNUSED(pos);
        bool ok;
        str.toDouble(&ok);  // Используем str вместо input
        return ok ? QValidator::Acceptable : QValidator::Invalid;
    }
};

#endif // WIN_H
