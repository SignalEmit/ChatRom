/********************************************************************************
** Form generated from reading UI file 'tianjiafriend.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIANJIAFRIEND_H
#define UI_TIANJIAFRIEND_H

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

class Ui_tianjiafriend
{
public:
    QLabel *label;
    QLineEdit *shuru_zhanghao;
    QPushButton *chaxunbt;
    QLabel *chaxun_touxiang;
    QLabel *label_3;
    QLabel *chaxun_xingbie;
    QLabel *label_5;
    QLabel *chaxun_zhanghao;
    QLabel *label_7;
    QLabel *chaxun_nicheng;
    QLabel *label_4;
    QLabel *chaxun_qianming;
    QPushButton *querentianjiabt;
    QPushButton *guanbibt;
    QPushButton *CheckAgain;

    void setupUi(QWidget *tianjiafriend)
    {
        if (tianjiafriend->objectName().isEmpty())
            tianjiafriend->setObjectName(QStringLiteral("tianjiafriend"));
        tianjiafriend->setWindowModality(Qt::ApplicationModal);
        tianjiafriend->resize(386, 370);
        tianjiafriend->setMinimumSize(QSize(386, 370));
        tianjiafriend->setMaximumSize(QSize(386, 370));
        label = new QLabel(tianjiafriend);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 21));
        shuru_zhanghao = new QLineEdit(tianjiafriend);
        shuru_zhanghao->setObjectName(QStringLiteral("shuru_zhanghao"));
        shuru_zhanghao->setGeometry(QRect(100, 40, 201, 20));
        chaxunbt = new QPushButton(tianjiafriend);
        chaxunbt->setObjectName(QStringLiteral("chaxunbt"));
        chaxunbt->setGeometry(QRect(310, 40, 41, 23));
        chaxun_touxiang = new QLabel(tianjiafriend);
        chaxun_touxiang->setObjectName(QStringLiteral("chaxun_touxiang"));
        chaxun_touxiang->setGeometry(QRect(150, 80, 91, 91));
        chaxun_touxiang->setAutoFillBackground(false);
        chaxun_touxiang->setStyleSheet(QStringLiteral("border:1px solid red;"));
        label_3 = new QLabel(tianjiafriend);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 220, 61, 21));
        chaxun_xingbie = new QLabel(tianjiafriend);
        chaxun_xingbie->setObjectName(QStringLiteral("chaxun_xingbie"));
        chaxun_xingbie->setGeometry(QRect(190, 220, 21, 21));
        label_5 = new QLabel(tianjiafriend);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 190, 61, 21));
        chaxun_zhanghao = new QLabel(tianjiafriend);
        chaxun_zhanghao->setObjectName(QStringLiteral("chaxun_zhanghao"));
        chaxun_zhanghao->setGeometry(QRect(190, 190, 151, 21));
        label_7 = new QLabel(tianjiafriend);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 250, 61, 16));
        chaxun_nicheng = new QLabel(tianjiafriend);
        chaxun_nicheng->setObjectName(QStringLiteral("chaxun_nicheng"));
        chaxun_nicheng->setGeometry(QRect(190, 250, 91, 16));
        label_4 = new QLabel(tianjiafriend);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 280, 54, 12));
        chaxun_qianming = new QLabel(tianjiafriend);
        chaxun_qianming->setObjectName(QStringLiteral("chaxun_qianming"));
        chaxun_qianming->setGeometry(QRect(190, 280, 171, 12));
        querentianjiabt = new QPushButton(tianjiafriend);
        querentianjiabt->setObjectName(QStringLiteral("querentianjiabt"));
        querentianjiabt->setGeometry(QRect(160, 310, 75, 23));
        guanbibt = new QPushButton(tianjiafriend);
        guanbibt->setObjectName(QStringLiteral("guanbibt"));
        guanbibt->setGeometry(QRect(270, 310, 75, 23));
        CheckAgain = new QPushButton(tianjiafriend);
        CheckAgain->setObjectName(QStringLiteral("CheckAgain"));
        CheckAgain->setGeometry(QRect(60, 310, 71, 23));

        retranslateUi(tianjiafriend);

        QMetaObject::connectSlotsByName(tianjiafriend);
    } // setupUi

    void retranslateUi(QWidget *tianjiafriend)
    {
        tianjiafriend->setWindowTitle(QApplication::translate("tianjiafriend", "tianjiafriend", 0));
        label->setText(QApplication::translate("tianjiafriend", "\350\276\223\345\205\245\350\264\246\345\217\267\357\274\232", 0));
        chaxunbt->setText(QApplication::translate("tianjiafriend", "\346\237\245\350\257\242", 0));
        chaxun_touxiang->setText(QString());
        label_3->setText(QApplication::translate("tianjiafriend", "\346\200\247    \345\210\253\357\274\232", 0));
        chaxun_xingbie->setText(QString());
        label_5->setText(QApplication::translate("tianjiafriend", "\350\264\246    \345\217\267\357\274\232", 0));
        chaxun_zhanghao->setText(QString());
        label_7->setText(QApplication::translate("tianjiafriend", "\346\230\265    \347\247\260\357\274\232", 0));
        chaxun_nicheng->setText(QString());
        label_4->setText(QApplication::translate("tianjiafriend", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
        chaxun_qianming->setText(QString());
        querentianjiabt->setText(QApplication::translate("tianjiafriend", "\347\241\256\350\256\244\346\267\273\345\212\240", 0));
        guanbibt->setText(QApplication::translate("tianjiafriend", "\345\205\263\351\227\255", 0));
        CheckAgain->setText(QApplication::translate("tianjiafriend", "\351\207\215\346\226\260\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class tianjiafriend: public Ui_tianjiafriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIANJIAFRIEND_H
