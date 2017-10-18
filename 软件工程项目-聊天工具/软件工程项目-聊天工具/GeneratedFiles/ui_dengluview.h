/********************************************************************************
** Form generated from reading UI file 'dengluview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DENGLUVIEW_H
#define UI_DENGLUVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dengluview
{
public:
    QLabel *label;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QTabWidget *tabWidget;
    QWidget *xiaoxi;
    QWidget *lianxiren_tab;
    QToolBox *lianxirenfenzu;
    QWidget *fenzu1;
    QWidget *fenzu2;
    QWidget *fenzu3;
    QWidget *Shengqing_tab;
    QLabel *label_2;
    QLabel *dengluview_qianming;
    QLabel *dengluview_nicheng;
    QPushButton *tianjia;
    QPushButton *touxiangbt;
    QLabel *label_Touxiang;

    void setupUi(QWidget *dengluview)
    {
        if (dengluview->objectName().isEmpty())
            dengluview->setObjectName(QStringLiteral("dengluview"));
        dengluview->resize(297, 520);
        dengluview->setMinimumSize(QSize(297, 520));
        dengluview->setMaximumSize(QSize(297, 520));
        label = new QLabel(dengluview);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 30, 41, 21));
        line = new QFrame(dengluview);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 110, 281, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(dengluview);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 120, 21, 391));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(dengluview);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 500, 281, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(dengluview);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(275, 120, 31, 391));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(dengluview);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 120, 261, 391));
        tabWidget->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        xiaoxi = new QWidget();
        xiaoxi->setObjectName(QStringLiteral("xiaoxi"));
        tabWidget->addTab(xiaoxi, QString());
        lianxiren_tab = new QWidget();
        lianxiren_tab->setObjectName(QStringLiteral("lianxiren_tab"));
        lianxirenfenzu = new QToolBox(lianxiren_tab);
        lianxirenfenzu->setObjectName(QStringLiteral("lianxirenfenzu"));
        lianxirenfenzu->setGeometry(QRect(0, 0, 261, 371));
        lianxirenfenzu->setFrameShadow(QFrame::Plain);
        fenzu1 = new QWidget();
        fenzu1->setObjectName(QStringLiteral("fenzu1"));
        fenzu1->setGeometry(QRect(0, 0, 261, 293));
        lianxirenfenzu->addItem(fenzu1, QString::fromUtf8("\345\210\206\347\273\204\344\270\200"));
        fenzu2 = new QWidget();
        fenzu2->setObjectName(QStringLiteral("fenzu2"));
        fenzu2->setGeometry(QRect(0, 0, 98, 28));
        lianxirenfenzu->addItem(fenzu2, QString::fromUtf8("\345\210\206\347\273\204\344\272\214"));
        fenzu3 = new QWidget();
        fenzu3->setObjectName(QStringLiteral("fenzu3"));
        fenzu3->setGeometry(QRect(0, 0, 98, 28));
        lianxirenfenzu->addItem(fenzu3, QString::fromUtf8("\345\210\206\347\273\204\344\270\211"));
        tabWidget->addTab(lianxiren_tab, QString());
        Shengqing_tab = new QWidget();
        Shengqing_tab->setObjectName(QStringLiteral("Shengqing_tab"));
        tabWidget->addTab(Shengqing_tab, QString());
        label_2 = new QLabel(dengluview);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 70, 61, 16));
        dengluview_qianming = new QLabel(dengluview);
        dengluview_qianming->setObjectName(QStringLiteral("dengluview_qianming"));
        dengluview_qianming->setGeometry(QRect(160, 70, 131, 16));
        dengluview_nicheng = new QLabel(dengluview);
        dengluview_nicheng->setObjectName(QStringLiteral("dengluview_nicheng"));
        dengluview_nicheng->setGeometry(QRect(150, 32, 81, 20));
        tianjia = new QPushButton(dengluview);
        tianjia->setObjectName(QStringLiteral("tianjia"));
        tianjia->setGeometry(QRect(10, 140, 21, 21));
        tianjia->setStyleSheet(QStringLiteral("background-image: url(:/denglu/C:/Users/M/Desktop/tianjia.png);"));
        tianjia->setCheckable(false);
        touxiangbt = new QPushButton(dengluview);
        touxiangbt->setObjectName(QStringLiteral("touxiangbt"));
        touxiangbt->setGeometry(QRect(10, 120, 21, 21));
        touxiangbt->setStyleSheet(QStringLiteral("background-image: url(:/denglu/C:/Users/M/Desktop/anniu.jpg);"));
        label_Touxiang = new QLabel(dengluview);
        label_Touxiang->setObjectName(QStringLiteral("label_Touxiang"));
        label_Touxiang->setGeometry(QRect(10, 20, 75, 75));

        retranslateUi(dengluview);

        tabWidget->setCurrentIndex(0);
        lianxirenfenzu->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dengluview);
    } // setupUi

    void retranslateUi(QWidget *dengluview)
    {
        dengluview->setWindowTitle(QApplication::translate("dengluview", "dengluview", 0));
        label->setText(QApplication::translate("dengluview", "\346\230\265  \347\247\260\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(xiaoxi), QApplication::translate("dengluview", "\346\266\210\346\201\257", 0));
        lianxirenfenzu->setItemText(lianxirenfenzu->indexOf(fenzu1), QApplication::translate("dengluview", "\345\210\206\347\273\204\344\270\200", 0));
        lianxirenfenzu->setItemText(lianxirenfenzu->indexOf(fenzu2), QApplication::translate("dengluview", "\345\210\206\347\273\204\344\272\214", 0));
        lianxirenfenzu->setItemText(lianxirenfenzu->indexOf(fenzu3), QApplication::translate("dengluview", "\345\210\206\347\273\204\344\270\211", 0));
        tabWidget->setTabText(tabWidget->indexOf(lianxiren_tab), QApplication::translate("dengluview", "\350\201\224\347\263\273\344\272\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(Shengqing_tab), QApplication::translate("dengluview", "\347\224\263\350\257\267\345\210\227\350\241\250", 0));
        label_2->setText(QApplication::translate("dengluview", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
        dengluview_qianming->setText(QString());
        dengluview_nicheng->setText(QApplication::translate("dengluview", "<html><head/><body><p><br/></p></body></html>", 0));
        tianjia->setText(QString());
        touxiangbt->setText(QString());
        label_Touxiang->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dengluview: public Ui_dengluview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGLUVIEW_H
