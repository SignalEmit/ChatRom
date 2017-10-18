#include "zhuce.h"
#include<QDebug>
zhuce::zhuce(QWidget * parent) : QWidget(parent) {
	setupUi(this);
	this->setWindowTitle("聊一聊");
	tcpSocket = new QTcpSocket(this);
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	zhuce_mima->setEchoMode(QLineEdit::Password);
	zhuce_mimaqueren->setEchoMode(QLineEdit::Password);
	connect(zhuce_guanbibt, SIGNAL(clicked()), this, SLOT(close()));
	//connect(zhuce_quedingbt, SIGNAL(clicked()), this, SLOT(queding()));
}
void zhuce::sendMessage()
{
	/*发送判断*/
	QByteArray ByteArray_judge; //用于暂存我们要发送的数据
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	out_judge << (quint16)0;
	out_judge << tr("注册").toLocal8Bit();
	qDebug() << "注册";
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_judge);

	/*发送账号*/
	QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
	QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
	out_account_number << (quint16)0;
	out_account_number << zhuce_zhanghao->text().toLocal8Bit();
	qDebug() << zhuce_zhanghao->text();
	out_account_number.device()->seek(0);
	out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_account_number);

	/*发送密码*/
	QByteArray ByteArray_password; //用于暂存我们要发送的数据
	QDataStream out_password(&ByteArray_password, QIODevice::WriteOnly);
	out_password << (quint16)0;
	out_password << zhuce_mima->text().toLocal8Bit();
	out_password.device()->seek(0);
	out_password << (quint16)(ByteArray_password.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_password);
	qDebug() << zhuce_mima->text();

	/*发送手机号*/
	QByteArray phone_number; //用于暂存我们要发送的数据
	QDataStream out_phone_number(&phone_number, QIODevice::WriteOnly);
	out_phone_number << (quint16)0;
	out_phone_number << zhuce_shoujihao->text().toLocal8Bit();
	out_phone_number.device()->seek(0);
	out_phone_number << (quint16)(phone_number.size() - sizeof(quint16));
	tcpSocket->write(phone_number);
	qDebug() << zhuce_shoujihao->text();
}
void zhuce::receiveMessage()
{
	blockSize = 0; //初始化其为0
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_5_6);
	//设置数据流版本，这里要和服务器端相同
	if (blockSize == 0) //如果是刚开始接收数据
	{
		//判断接收的数据是否有两字节，也就是文件的大小信息
		//如果有则保存到blockSize变量中，没有则返回，继续接收数据
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (tcpSocket->bytesAvailable() < blockSize) return;
	//如果没有得到全部的数据，则返回，继续接收数据
	in >> message;
	//将接收到的数据存放到变量中
	qDebug() << QString::fromLocal8Bit(message);
	Note_register = QString::fromLocal8Bit(message);
	tcpSocket->disconnectFromHost();
	if (Note_register == "注册成功")
		this->close();
	else
	{
		QMessageBox::warning(this, tr("警告"), tr("此帐号已注册"), QMessageBox::Yes);
		zhuce_zhanghao->setFocus();
	}
}
void zhuce::newConnect()
{
	tcpSocket->abort(); //取消已有的连接
	tcpSocket->connectToHost("10.211.26.93", 666);
	//连接到主机，这里从界面获取主机地址和端口号
}
void zhuce::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("警告"), tr("请检查您的网络"), QMessageBox::Yes);
}
void zhuce::on_zhuce_quedingbt_clicked() //连接按钮
{
	if (zhuce_shoujihao->text().length() == 11)
	{
		if (!zhuce_zhanghao->text().isEmpty() && !zhuce_mima->text().isEmpty())
			if (zhuce_mima->text() != zhuce_mimaqueren->text())
			{
				QMessageBox::warning(this, tr("警告"), tr("输入密码不一致请重新输入"), QMessageBox::Yes);
				zhuce_shoujihao->setFocus();
			}
			else
				newConnect();
		else
			QMessageBox::warning(this, tr("警告"), tr("输入的账号或密码为空请重新输入"), QMessageBox::Yes);
	}
	else
	{

		QMessageBox::warning(this, tr("警告"), tr("输入手机号码错误请重新修改"), QMessageBox::Yes);
		zhuce_shoujihao->setFocus();
	}
}
zhuce::~zhuce() {
	
}
