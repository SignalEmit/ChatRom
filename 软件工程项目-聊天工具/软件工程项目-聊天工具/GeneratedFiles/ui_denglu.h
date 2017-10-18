/********************************************************************************
** Form generated from reading UI file 'denglu.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DENGLU_H
#define UI_DENGLU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dengluClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *zhanghaolineedit;
    QLineEdit *mimalineedit;
    QPushButton *denglubt;
    QPushButton *closebt;
    QPushButton *zhucebt;
    QPushButton *wangjimimabt;

    void setupUi(QWidget *dengluClass)
    {
        if (dengluClass->objectName().isEmpty())
            dengluClass->setObjectName(QStringLiteral("dengluClass"));
        dengluClass->resize(306, 588);
        dengluClass->setMinimumSize(QSize(306, 588));
        dengluClass->setMaximumSize(QSize(306, 588));
        label = new QLabel(dengluClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 110, 191, 71));
        label->setStyleSheet(QString::fromUtf8("color:red;\n"
"font: 75 36pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_2 = new QLabel(dengluClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 300, 54, 21));
        label_3 = new QLabel(dengluClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 240, 54, 21));
        zhanghaolineedit = new QLineEdit(dengluClass);
        zhanghaolineedit->setObjectName(QStringLiteral("zhanghaolineedit"));
        zhanghaolineedit->setGeometry(QRect(90, 240, 191, 20));
        mimalineedit = new QLineEdit(dengluClass);
        mimalineedit->setObjectName(QStringLiteral("mimalineedit"));
        mimalineedit->setGeometry(QRect(90, 300, 191, 20));
        denglubt = new QPushButton(dengluClass);
        denglubt->setObjectName(QStringLiteral("denglubt"));
        denglubt->setGeometry(QRect(60, 370, 75, 23));
        closebt = new QPushButton(dengluClass);
        closebt->setObjectName(QStringLiteral("closebt"));
        closebt->setGeometry(QRect(200, 370, 75, 23));
        zhucebt = new QPushButton(dengluClass);
        zhucebt->setObjectName(QStringLiteral("zhucebt"));
        zhucebt->setGeometry(QRect(220, 450, 75, 23));
        wangjimimabt = new QPushButton(dengluClass);
        wangjimimabt->setObjectName(QStringLiteral("wangjimimabt"));
        wangjimimabt->setGeometry(QRect(220, 490, 75, 23));

        retranslateUi(dengluClass);

        QMetaObject::connectSlotsByName(dengluClass);
    } // setupUi

    void retranslateUi(QWidget *dengluClass)
    {
        dengluClass->setWindowTitle(QApplication::translate("dengluClass", "denglu", 0));
        label->setText(QApplication::translate("dengluClass", "\346\254\242\350\277\216\347\231\273\345\275\225", 0));
        label_2->setText(QApplication::translate("dengluClass", "\345\257\206   \347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("dengluClass", "\350\264\246   \345\217\267\357\274\232", 0));
        denglubt->setText(QApplication::translate("dengluClass", "\347\231\273      \345\275\225", 0));
        denglubt->setShortcut(QApplication::translate("dengluClass", "Return", 0));
        closebt->setText(QApplication::translate("dengluClass", "\351\200\200       \345\207\272", 0));
        zhucebt->setText(QApplication::translate("dengluClass", "\346\263\250       \345\206\214", 0));
        wangjimimabt->setText(QApplication::translate("dengluClass", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class dengluClass: public Ui_dengluClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGLU_H
