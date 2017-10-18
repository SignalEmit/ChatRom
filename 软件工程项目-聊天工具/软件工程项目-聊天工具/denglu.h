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
	void newConnect(); //���ӷ�����
	void displayError(QAbstractSocket::SocketError);
	void on_denglubt_clicked();
private:
	QString LocalIp;					//����IP
	QString Note_Accountnumber;			//�˺�
	void receive_LocalIp();
	QString Note_register;
	QTcpSocket *tcpSocket;
	QByteArray message;  //��Ŵӷ��������յ����ַ���
	QByteArray PortNumber;	//��Ŵӷ��������յĶ˿ں�
	quint16 blockSize;  //����ļ��Ĵ�С��Ϣ
private:
	zhuce newwindows;
	dengluview w;
	wangjimima p;
	Ui::dengluClass ui;
};

#endif // DENGLU_H
