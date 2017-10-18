/********************************************************************************
** Form generated from reading UI file 'wangjimima.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WANGJIMIMA_H
#define UI_WANGJIMIMA_H

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

class Ui_wangjimima
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *zhaohui_zhanghao;
    QLineEdit *zhaohui_shoujihao;
    QPushButton *quedingbt;
    QPushButton *guanbibt;
    QLabel *label_5;
    QLineEdit *zhaohui_mima;
    QLabel *label_6;
    QLineEdit *zhaohui_querenmima;

    void setupUi(QWidget *wangjimima)
    {
        if (wangjimima->objectName().isEmpty())
            wangjimima->setObjectName(QStringLiteral("wangjimima"));
        wangjimima->resize(406, 367);
        wangjimima->setMinimumSize(QSize(406, 367));
        wangjimima->setMaximumSize(QSize(406, 367));
        label = new QLabel(wangjimima);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 30, 131, 41));
        label_2 = new QLabel(wangjimima);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 70, 211, 31));
        label_3 = new QLabel(wangjimima);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 120, 61, 21));
        label_4 = new QLabel(wangjimima);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 240, 61, 21));
        zhaohui_zhanghao = new QLineEdit(wangjimima);
        zhaohui_zhanghao->setObjectName(QStringLiteral("zhaohui_zhanghao"));
        zhaohui_zhanghao->setGeometry(QRect(130, 120, 191, 20));
        zhaohui_shoujihao = new QLineEdit(wangjimima);
        zhaohui_shoujihao->setObjectName(QStringLiteral("zhaohui_shoujihao"));
        zhaohui_shoujihao->setGeometry(QRect(130, 240, 191, 20));
        quedingbt = new QPushButton(wangjimima);
        quedingbt->setObjectName(QStringLiteral("quedingbt"));
        quedingbt->setGeometry(QRect(100, 280, 75, 23));
        guanbibt = new QPushButton(wangjimima);
        guanbibt->setObjectName(QStringLiteral("guanbibt"));
        guanbibt->setGeometry(QRect(230, 280, 75, 23));
        label_5 = new QLabel(wangjimima);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(73, 160, 61, 21));
        zhaohui_mima = new QLineEdit(wangjimima);
        zhaohui_mima->setObjectName(QStringLiteral("zhaohui_mima"));
        zhaohui_mima->setGeometry(QRect(130, 160, 191, 20));
        label_6 = new QLabel(wangjimima);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 200, 61, 20));
        zhaohui_querenmima = new QLineEdit(wangjimima);
        zhaohui_querenmima->setObjectName(QStringLiteral("zhaohui_querenmima"));
        zhaohui_querenmima->setGeometry(QRect(130, 199, 191, 21));

        retranslateUi(wangjimima);

        QMetaObject::connectSlotsByName(wangjimima);
    } // setupUi

    void retranslateUi(QWidget *wangjimima)
    {
        wangjimima->setWindowTitle(QApplication::translate("wangjimima", "wangjimima", 0));
        label->setText(QApplication::translate("wangjimima", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("wangjimima", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\350\264\246\345\217\267\350\277\233\350\241\214\345\257\206\347\240\201\346\211\276\345\233\236</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("wangjimima", "\350\264\246    \345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("wangjimima", "\346\211\213 \346\234\272 \345\217\267\357\274\232", 0));
        quedingbt->setText(QApplication::translate("wangjimima", "\347\241\256    \345\256\232", 0));
        guanbibt->setText(QApplication::translate("wangjimima", "\345\205\263    \351\227\255", 0));
        label_5->setText(QApplication::translate("wangjimima", "\345\257\206   \347\240\201\357\274\232", 0));
        label_6->setText(QApplication::translate("wangjimima", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class wangjimima: public Ui_wangjimima {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WANGJIMIMA_H
