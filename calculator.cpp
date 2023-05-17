#include "calculator.h"

calculator::calculator(QWidget * parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);

    grid->setSpacing(1);

    values = { "7", "8", "9", "C",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "/", "+", "="
    };

    int pos = 0;

    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setFixedHeight(50);
    QFont font = display->font();
    font.setPointSize(18);
    display->setFont(font);
    display->setStyleSheet("QLineEdit { border: none;"
                           "background: #e6e6e6; "
                           "color: black; }"
                           );

    grid->addWidget(display, 0, 0, 1, 4);



    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
         btn.append(new QPushButton(values[pos], this));
         btn[pos]->setFixedSize(65, 65);
         font.setPointSize(14);
         btn[pos]->setFont(font);
         btn[pos]->setStyleSheet("QPushButton {"
                            "background-color: #e6e6e6;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-color: #262626;"
                            "border-radius: 10px;}"
                            "QPushButton:pressed {"
                            "background-color: #b3b3b3;"
                            "border-style: inset;}");


         connect(btn[pos], &QPushButton::clicked, this, &calculator::onClick);
         grid->addWidget(btn[pos], i, j);
         pos++;
        }

    }
    btn.append(new QPushButton (values[pos], this));
    btn[pos]->setFixedSize(280, 60);
    font.setPointSize(14);
    btn[pos]->setFont(font);
    btn[pos]->setStyleSheet("QPushButton {"
                            "background-color: #e6e6e6;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-color: #262626;"
                            "border-radius: 10px;}"
                            "QPushButton:pressed {"
                            "background-color: #b3b3b3;"
                            "border-style: inset;}");
    connect(btn[pos], &QPushButton::clicked, this, &calculator::onClick);
    grid->addWidget(btn[pos], 5, 0, 1, 4);

    setLayout(grid);
    setFixedSize(300, 460);
}

void calculator::keyPressEvent(QKeyEvent* event) {
    qDebug() << "event";
    if (event->key() == Qt::Key_Return) {
        qDebug() << "enter";
        if (!decision.isEmpty()) {
         if (numberAfterPoint) {
             if (decision == "+") {
                 result += value2;
             }
             if (decision == "-") {
                 result -= value2;
             }
             if (decision == "*") {
                 result *= value2;
             }
             if (decision == "/") {
                 result /= value2;
             }
             qDebug() << "numberAfterPoint";
             qDebug() << "value2: " << value2;
             qDebug() << "value1: " << value1;
             qDebug() << "result: " << result;
             decision.clear();
            }
        }

        qDebug() << "resultat";
        qDebug() << "value2: " << value2;
        qDebug() << "value1: " << value1;
        qDebug() << "result: " << result;
        display->setText(QString::number(result));
        value1 = result;
        hasPoint = false;

        qDebug() << "value1 = result";
    }
    if (event->key() == Qt::Key_Escape) {
        displayText.clear();
        result = 0;
        hasPoint = false;
        numberAfterPoint = false;
        decision.clear();
        display->setText(displayText);
        qDebug() << "text C";
    }
}

void calculator::onClick() {

    QPushButton *button = (QPushButton *)sender();

    QString text = button->text();

    qDebug() << "button: " << text;

    if (text != "C" && text != "+" && text != "-" && text != "*" && text != "/" && text != "=") {

        if (text != "." && text != decision) {
         displayText += text;
         display->setText(displayText);
         value2 = displayText.toDouble();
         numberAfterPoint =  true;

        }
        if (text == ".") {
         if (!hasPoint) {
             hasPoint = true;
             displayText += ".";
             numberAfterPoint = false;
            }
        }
        qDebug() << "text != C";
        qDebug() << "value2: " << value2;
        qDebug() << "value1: " << value1;
        qDebug() << "result: " << result;

    }



    if (text == "+" || text == "-" || text == "*" || text == "/") {

        if (!decision.isEmpty()) {
            if (numberAfterPoint) {
             if (decision == "+") {
                 result += value2;
             }
             if (decision == "-") {
                 result -= value2;
             }
             if (decision == "*") {
                 result *= value2;
             }
             if (decision == "/") {
                 result /= value2;
             }
             qDebug() << "numberAfterPoint";
             qDebug() << "value2: " << value2;
             qDebug() << "value1: " << value1;
             qDebug() << "result: " << result;
             decision.clear();
            }
        }


        decision = text;

        if (result == 0) {
            result += value2;
            value1 = result;
            qDebug() << "value1: " << value1;
            qDebug() << "result: " << result;

        }

        displayText.clear();
        display->setText(displayText);
        hasPoint = false;
        qDebug() << "decision";
        qDebug() << "value2: " << value2;
        qDebug() << "value1: " << value1;
        qDebug() << "result: " << result;
    }




    if (text == "C") {
        displayText.clear();
        result = 0;
        hasPoint = false;
        numberAfterPoint = false;
        decision.clear();
        display->setText(displayText);
        qDebug() << "text C";
    }

    if (text == "=") {
        if (!decision.isEmpty()) {
            if (numberAfterPoint) {
             if (decision == "+") {
                 result += value2;
             }
             if (decision == "-") {
                 result -= value2;
             }
             if (decision == "*") {
                 result *= value2;
             }
             if (decision == "/") {
                 result /= value2;
             }
             qDebug() << "numberAfterPoint";
             qDebug() << "value2: " << value2;
             qDebug() << "value1: " << value1;
             qDebug() << "result: " << result;
             decision.clear();
            }
        }

        qDebug() << "resultat";
        qDebug() << "value2: " << value2;
        qDebug() << "value1: " << value1;
        qDebug() << "result: " << result;
        display->setText(QString::number(result));
        value1 = result;
        hasPoint = false;

        qDebug() << "value1 = result";
    }
}















