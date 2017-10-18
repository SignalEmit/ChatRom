/********************************************************************************
** Form generated from reading UI file 'zhuce.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCE_H
#define UI_ZHUCE_H

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

class Ui_zhuce
{
public:
    QLabel *label;
    QLineEdit *zhuce_zhanghao;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *zhuce_mima;
    QLineEdit *zhuce_shoujihao;
    QPushButton *zhuce_quedingbt;
    QPushButton *zhuce_guanbibt;
    QLabel *label_4;
    QLineEdit *zhuce_mimaqueren;

    void setupUi(QWidget *zhuce)
    {
        if (zhuce->objectName().isEmpty())
            zhuce->setObjectName(QStringLiteral("zhuce"));
        zhuce->resize(418, 259);
        zhuce->setMinimumSize(QSize(418, 259));
        zhuce->setMaximumSize(QSize(418, 16777215));
        label = new QLabel(zhuce);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 54, 21));
        zhuce_zhanghao = new QLineEdit(zhuce);
        zhuce_zhanghao->setObjectName(QStringLiteral("zhuce_zhanghao"));
        zhuce_zhanghao->setGeometry(QRect(150, 40, 171, 20));
        label_2 = new QLabel(zhuce);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 80, 54, 21));
        label_3 = new QLabel(zhuce);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 160, 54, 21));
        zhuce_mima = new QLineEdit(zhuce);
        zhuce_mima->setObjectName(QStringLiteral("zhuce_mima"));
        zhuce_mima->setGeometry(QRect(150, 80, 171, 20));
        zhuce_shoujihao = new QLineEdit(zhuce);
        zhuce_shoujihao->setObjectName(QStringLiteral("zhuce_shoujihao"));
        zhuce_shoujihao->setGeometry(QRect(150, 160, 171, 20));
        zhuce_quedingbt = new QPushButton(zhuce);
        zhuce_quedingbt->setObjectName(QStringLiteral("zhuce_quedingbt"));
        zhuce_quedingbt->setGeometry(QRect(100, 190, 75, 23));
        zhuce_guanbibt = new QPushButton(zhuce);
        zhuce_guanbibt->setObjectName(QStringLiteral("zhuce_guanbibt"));
        zhuce_guanbibt->setGeometry(QRect(240, 190, 75, 23));
        label_4 = new QLabel(zhuce);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 120, 54, 21));
        zhuce_mimaqueren = new QLineEdit(zhuce);
        zhuce_mimaqueren->setObjectName(QStringLiteral("zhuce_mimaqueren"));
        zhuce_mimaqueren->setGeometry(QRect(150, 120, 171, 20));

        retranslateUi(zhuce);

        QMetaObject::connectSlotsByName(zhuce);
    } // setupUi

    void retranslateUi(QWidget *zhuce)
    {
        zhuce->setWindowTitle(QApplication::translate("zhuce", "zhuce", 0));
        label->setText(QApplication::translate("zhuce", "\350\264\246    \345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("zhuce", "\345\257\206    \347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("zhuce", "\346\211\213 \346\234\272 \345\217\267\357\274\232", 0));
        zhuce_quedingbt->setText(QApplication::translate("zhuce", "\347\241\256      \345\256\232", 0));
        zhuce_guanbibt->setText(QApplication::translate("zhuce", "\345\205\263       \351\227\255", 0));
        label_4->setText(QApplication::translate("zhuce", "<html><head/><body><p>\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class zhuce: public Ui_zhuce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H
