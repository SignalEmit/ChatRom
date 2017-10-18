#ifndef DENGLU_H
#define DENGLU_H

#include <QtWidgets/QWidget>
#include<QMessageBox>
#include<QtNetWork>
#include<QDir>
#include "ui_denglu.h"
#include"dengluview.h"
#include"wangjimima.h"
#include"zhuce.h"
using namespace std;
# pragma execution_character_set("utf-8")
class denglu : public QWidget,public Ui_dengluClass
{
	Q_OBJECT

public:
	denglu(QWidget *parent = 0);
	~denglu();
private slots:
	void showzhuce();
	void showwangjimima();
	void sendMessage();
	void receiveMessage();
	void newConnect(); //连接服务器
	void displayError(QAbstractSocket::SocketError);
	void on_denglubt_clicked();
private:
	QString LocalIp;					//本机IP
	QString Note_Accountnumber;			//账号
	void receive_LocalIp();
	QString Note_register;
	QTcpSocket *tcpSocket;
	QByteArray message;  //存放从服务器接收到的字符串
	QByteArray PortNumber;	//存放从服务器接收的端口号
	quint16 blockSize;  //存放文件的大小信息
private:
	zhuce newwindows;
	dengluview w;
	wangjimima p;
	Ui::dengluClass ui;
};

#endif // DENGLU_H
