/********************************************************************************
** Form generated from reading UI file 'xiugaixingxi.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XIUGAIXINGXI_H
#define UI_XIUGAIXINGXI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xiugaixingxi
{
public:
    QLabel *touxiang;
    QPushButton *Xiugai_Displaybt;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nichengxiugai;
    QLineEdit *gexingqianming;
    QPushButton *queding;
    QPushButton *nichengqingchubt;
    QPushButton *gexingqianmingbt;
    QPushButton *guanbi;
    QRadioButton *man_radioButton;
    QLabel *label_4;
    QRadioButton *woman_radioButton;

    void setupUi(QWidget *xiugaixingxi)
    {
        if (xiugaixingxi->objectName().isEmpty())
            xiugaixingxi->setObjectName(QStringLiteral("xiugaixingxi"));
        xiugaixingxi->setWindowModality(Qt::ApplicationModal);
        xiugaixingxi->resize(389, 318);
        xiugaixingxi->setMinimumSize(QSize(389, 318));
        xiugaixingxi->setMaximumSize(QSize(389, 318));
        xiugaixingxi->setStyleSheet(QStringLiteral(""));
        touxiang = new QLabel(xiugaixingxi);
        touxiang->setObjectName(QStringLiteral("touxiang"));
        touxiang->setGeometry(QRect(130, 40, 91, 91));
        touxiang->setAutoFillBackground(false);
        touxiang->setStyleSheet(QStringLiteral("border:1px solid red;"));
        Xiugai_Displaybt = new QPushButton(xiugaixingxi);
        Xiugai_Displaybt->setObjectName(QStringLiteral("Xiugai_Displaybt"));
        Xiugai_Displaybt->setGeometry(QRect(230, 110, 61, 23));
        label_2 = new QLabel(xiugaixingxi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 170, 81, 21));
        label_3 = new QLabel(xiugaixingxi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 200, 81, 21));
        nichengxiugai = new QLineEdit(xiugaixingxi);
        nichengxiugai->setObjectName(QStringLiteral("nichengxiugai"));
        nichengxiugai->setGeometry(QRect(120, 170, 181, 20));
        gexingqianming = new QLineEdit(xiugaixingxi);
        gexingqianming->setObjectName(QStringLiteral("gexingqianming"));
        gexingqianming->setGeometry(QRect(120, 200, 181, 20));
        queding = new QPushButton(xiugaixingxi);
        queding->setObjectName(QStringLiteral("queding"));
        queding->setGeometry(QRect(100, 240, 41, 23));
        nichengqingchubt = new QPushButton(xiugaixingxi);
        nichengqingchubt->setObjectName(QStringLiteral("nichengqingchubt"));
        nichengqingchubt->setGeometry(QRect(310, 170, 41, 21));
        gexingqianmingbt = new QPushButton(xiugaixingxi);
        gexingqianmingbt->setObjectName(QStringLiteral("gexingqianmingbt"));
        gexingqianmingbt->setGeometry(QRect(310, 200, 41, 21));
        guanbi = new QPushButton(xiugaixingxi);
        guanbi->setObjectName(QStringLiteral("guanbi"));
        guanbi->setGeometry(QRect(230, 240, 41, 23));
        man_radioButton = new QRadioButton(xiugaixingxi);
        man_radioButton->setObjectName(QStringLiteral("man_radioButton"));
        man_radioButton->setGeometry(QRect(160, 150, 31, 16));
        label_4 = new QLabel(xiugaixingxi);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 145, 81, 21));
        woman_radioButton = new QRadioButton(xiugaixingxi);
        woman_radioButton->setObjectName(QStringLiteral("woman_radioButton"));
        woman_radioButton->setGeometry(QRect(220, 150, 41, 16));

        retranslateUi(xiugaixingxi);

        QMetaObject::connectSlotsByName(xiugaixingxi);
    } // setupUi

    void retranslateUi(QWidget *xiugaixingxi)
    {
        xiugaixingxi->setWindowTitle(QApplication::translate("xiugaixingxi", "xiugaixingxi", 0));
        touxiang->setText(QString());
        Xiugai_Displaybt->setText(QApplication::translate("xiugaixingxi", "\344\277\256\346\224\271\345\244\264\345\203\217", 0));
        label_2->setText(QApplication::translate("xiugaixingxi", "\344\277\256  \346\224\271 \346\230\265 \347\247\260\357\274\232", 0));
        label_3->setText(QApplication::translate("xiugaixingxi", "\344\277\256\346\224\271\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
        queding->setText(QApplication::translate("xiugaixingxi", "\347\241\256\345\256\232", 0));
        nichengqingchubt->setText(QApplication::translate("xiugaixingxi", "\346\270\205\351\231\244", 0));
        gexingqianmingbt->setText(QApplication::translate("xiugaixingxi", "\346\270\205\351\231\244", 0));
        guanbi->setText(QApplication::translate("xiugaixingxi", "\345\205\263\351\227\255", 0));
        man_radioButton->setText(QApplication::translate("xiugaixingxi", "\347\224\267", 0));
        label_4->setText(QApplication::translate("xiugaixingxi", "\346\200\247        \345\210\253\357\274\232", 0));
        woman_radioButton->setText(QApplication::translate("xiugaixingxi", "\345\245\263", 0));
    } // retranslateUi

};

namespace Ui {
    class xiugaixingxi: public Ui_xiugaixingxi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XIUGAIXINGXI_H
