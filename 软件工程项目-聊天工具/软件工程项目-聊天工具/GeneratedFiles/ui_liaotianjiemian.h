/********************************************************************************
** Form generated from reading UI file 'liaotianjiemian.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIAOTIANJIEMIAN_H
#define UI_LIAOTIANJIEMIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_liaotianjiemian
{
public:
    QLabel *label;
    QLabel *Gexingqianming;
    QPushButton *fasongbt;
    QPushButton *qingkongbt;
    QLabel *Nicheng;
    QTextEdit *shuchu;
    QTextEdit *shuru;
    QLabel *label_DisPlay;
    QLabel *label_2;

    void setupUi(QWidget *liaotianjiemian)
    {
        if (liaotianjiemian->objectName().isEmpty())
            liaotianjiemian->setObjectName(QStringLiteral("liaotianjiemian"));
        liaotianjiemian->setWindowModality(Qt::NonModal);
        liaotianjiemian->resize(600, 514);
        liaotianjiemian->setMinimumSize(QSize(600, 514));
        liaotianjiemian->setMaximumSize(QSize(600, 514));
        label = new QLabel(liaotianjiemian);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 61, 16));
        Gexingqianming = new QLabel(liaotianjiemian);
        Gexingqianming->setObjectName(QStringLiteral("Gexingqianming"));
        Gexingqianming->setGeometry(QRect(180, 70, 301, 20));
        fasongbt = new QPushButton(liaotianjiemian);
        fasongbt->setObjectName(QStringLiteral("fasongbt"));
        fasongbt->setGeometry(QRect(410, 480, 75, 23));
        qingkongbt = new QPushButton(liaotianjiemian);
        qingkongbt->setObjectName(QStringLiteral("qingkongbt"));
        qingkongbt->setGeometry(QRect(500, 480, 75, 23));
        Nicheng = new QLabel(liaotianjiemian);
        Nicheng->setObjectName(QStringLiteral("Nicheng"));
        Nicheng->setGeometry(QRect(190, 30, 161, 16));
        shuchu = new QTextEdit(liaotianjiemian);
        shuchu->setObjectName(QStringLiteral("shuchu"));
        shuchu->setGeometry(QRect(10, 100, 581, 271));
        shuru = new QTextEdit(liaotianjiemian);
        shuru->setObjectName(QStringLiteral("shuru"));
        shuru->setGeometry(QRect(10, 390, 581, 81));
        label_DisPlay = new QLabel(liaotianjiemian);
        label_DisPlay->setObjectName(QStringLiteral("label_DisPlay"));
        label_DisPlay->setGeometry(QRect(20, 10, 75, 75));
        label_2 = new QLabel(liaotianjiemian);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 70, 61, 16));

        retranslateUi(liaotianjiemian);

        QMetaObject::connectSlotsByName(liaotianjiemian);
    } // setupUi

    void retranslateUi(QWidget *liaotianjiemian)
    {
        liaotianjiemian->setWindowTitle(QApplication::translate("liaotianjiemian", "liaotianjiemian", 0));
        label->setText(QApplication::translate("liaotianjiemian", "\346\230\265    \347\247\260\357\274\232", 0));
        Gexingqianming->setText(QApplication::translate("liaotianjiemian", "                         \344\270\252\346\200\247\347\255\276\345\220\215", 0));
        fasongbt->setText(QApplication::translate("liaotianjiemian", "\345\217\221\351\200\201", 0));
        fasongbt->setShortcut(QApplication::translate("liaotianjiemian", "Ctrl+Return", 0));
        qingkongbt->setText(QApplication::translate("liaotianjiemian", "\346\270\205\347\251\272", 0));
        Nicheng->setText(QApplication::translate("liaotianjiemian", "TextLabel", 0));
        label_DisPlay->setText(QApplication::translate("liaotianjiemian", "TextLabel", 0));
        label_2->setText(QApplication::translate("liaotianjiemian", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class liaotianjiemian: public Ui_liaotianjiemian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIAOTIANJIEMIAN_H
