#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QVector>


class calculator : public QWidget
{
public:
    calculator(QWidget * parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent * event);

   private slots:
    void onClick();

private:
    double displayValue();
    QList<QString> values;
    QLineEdit * display;
    QVector<QPushButton*> btn;

    double result = 0;
    double value1 = 0;
    double value2 = 0;

    QString decision = "";
    QString displayText = "";

    bool hasPoint = false;
    bool numberAfterPoint = true;
};

#endif // CALCULATOR_H
