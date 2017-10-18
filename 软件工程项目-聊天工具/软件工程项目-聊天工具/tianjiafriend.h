#pragma once
#include <QWidget>
#include<QTcpSocket>
#include<QTextCodec>
#include<QFile>
#include<QMessageBox>
#include "ui_tianjiafriend.h"
# pragma execution_character_set("utf-8")
class tianjiafriend : public QWidget,public Ui_tianjiafriend {
	Q_OBJECT
private slots:
	void displayError(QAbstractSocket::SocketError);
	void on_querentianjiabt_clicked();
	void sendMessage();
	void receiveMessage();
	void on_chaxunbt_clicked();
	void on_CheckAgain_clicked();
	//void UserInformation();					//点击确认添加按钮后添加好友
public:
	tianjiafriend(QWidget * parent = Q_NULLPTR);
	~tianjiafriend();
private:
	bool Judge_send;							//判断发送
	QString AccountNumber;
	QString Sex;
	QString fenzu;
	QString NickName;
	QString PersonalizedSignature;
	QString PortNumber;
	QString LocalIp;
	QString Display;

	void showEvent(QShowEvent *e);
	QString Me;
	QTcpSocket *tcpSocket;				//接收信息的套接字
	void closeEvent(QShowEvent *e);
};
