#pragma once
#include <QWidget>
#include<QDir>
#include<QTcpSocket>
#include<QUdpSocket>
#include<QCloseEvent>
#include<QMessageBox>
#include "ui_liaotianjiemian.h"
# pragma execution_character_set("utf-8")
class liaotianjiemian : public QWidget, public Ui_liaotianjiemian {
	Q_OBJECT
signals:
	void closeThisWindowAgain();
public:
	liaotianjiemian(QWidget * parent = Q_NULLPTR);
	~liaotianjiemian();
private slots:
	void sendMessage();
	void receiveMessage();
	void displayError(QAbstractSocket::SocketError);

	void SendNews();

	void processPendingDatagram();		//UDP接收消息
	void sendNews();
	void qingkong();
private:
	QString SendTxt;
	bool closeCheck;
	bool  onLine;							//在线发送还是下线发送
	bool FristLoad;						//第一次读取
	void SendReciveNews();
	void newConnect();
	QByteArray message;
	QString Me_PortNumber;
	QTcpSocket *tcpSendReceiveNew;
	QTcpSocket *tcpSocket;				//接收哪个人登录的套接字
	QUdpSocket *receiver;				//接收消息
	QUdpSocket *sender;					//UDP发送消息
	QString Me;
	QString AccountNumber_User;			//用户账号	
	QString NickName_User;				//用户昵称
	QString PersonalizedSignature_User;	//用户个性签名
	QString PortNumber_User;			//端口号
	QString LocalIp_User;				//用户IP
	QString Display_Picture_User;
	void closeEvent(QCloseEvent *e);
	void Load_txt();					//读取文件
	void jianchawenjianshifoucunzai_andCreat();					//检查文件是否存在
	QString Dengluderen;						//登录的人
	QString Dianjideren;						//点击的人
	void Creat_or_jianchawenjianjia();			//检查是否创建文件夹
	void Duqu_xinxi(QString Jieshou_xinxi);
	void showEvent(QShowEvent *e);
	Ui::liaotianjiemian ui;
};
