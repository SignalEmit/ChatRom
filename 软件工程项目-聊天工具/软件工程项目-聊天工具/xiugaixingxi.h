#pragma once
#include <QWidget>
#include "ui_xiugaixingxi.h"
#include<QTcpSocket>
#include<QShowEvent>
#include<QCloseEvent>
#include<QMessageBox>
//#include"dengluview.h"
# pragma execution_character_set("utf-8")
class xiugaixingxi : public QWidget, public Ui_xiugaixingxi {
	Q_OBJECT
signals:
	void xiugaixinxixinhao(QString Sex,QString NickName,QString PersonalizedSignature,QString Display_picture);
public:
	xiugaixingxi(QWidget * parent = Q_NULLPTR);
	~xiugaixingxi();
private slots:
	void displayError(QAbstractSocket::SocketError);
	void sendMessage();
	void on_queding_clicked();
	void Xiugai_Display();
	void qingchu();
	void radioChange();
private:
	QString Judge_Sex;
	QString s;				//记录登录人的图片位置
	QTcpSocket *tcpSocket;
	void Shezhitupian(QString s);
	void closeEvent(QCloseEvent *e);
	void showEvent(QShowEvent *e);
	QString Denglu_people;
	Ui::xiugaixingxi ui;
};
