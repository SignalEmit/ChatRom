#pragma once
#include <QWidget>
#include<QMessageBox>
#include<QtNetWork>
#include "ui_zhuce.h"
# pragma execution_character_set("utf-8")
class zhuce : public QWidget,public Ui_zhuce {
	Q_OBJECT

public:
	zhuce(QWidget * parent = Q_NULLPTR);
	~zhuce();
private slots:
	void sendMessage();
	void receiveMessage();
	void newConnect(); //连接服务器
	void displayError(QAbstractSocket::SocketError);
	void on_zhuce_quedingbt_clicked();
private:
	QString Note_register;				//收到的信号
	QTcpSocket *tcpSocket;
	QByteArray message;  //存放从服务器接收到的字符串
	quint16 blockSize;  //存放文件的大小信息
private:
	Ui::zhuce ui;
};
