#include "denglu.h"
#include<QDebug>
denglu::denglu(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	mimalineedit->setEchoMode(QLineEdit::Password);
	this->setWindowTitle("聊一聊");
	this->move(900, 52);
	tcpSocket = new QTcpSocket(this);
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	connect(closebt, SIGNAL(clicked()), this, SLOT(close()));
	connect(zhucebt, SIGNAL(clicked()), this, SLOT(showzhuce()));
	connect(wangjimimabt, SIGNAL(clicked()), this, SLOT(showwangjimima()));
}
void denglu::sendMessage()
{
	QByteArray ByteArray_judge; //用于暂存我们要发送的数据
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	//使用数据流写入数据
	//设置数据流的版本，客户端和服务器端使用的版本要相同
	out_judge << (quint16)0;
	out_judge << tr("登录").toLocal8Bit();
	//qDebug() << "登录";
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_judge);

	QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
	QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
	//使用数据流写入数据
	//设置数据流的版本，客户端和服务器端使用的版本要相同
	out_account_number << (quint16)0;
	out_account_number << zhanghaolineedit->text().toLocal8Bit();
	qDebug() << zhanghaolineedit->text();
	out_account_number.device()->seek(0);
	out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_account_number);

	//发送密码
	QByteArray ByteArray_password; //用于暂存我们要发送的数据
	QDataStream out_password(&ByteArray_password, QIODevice::WriteOnly);
	//使用数据流写入数据
	//设置数据流的版本，客户端和服务器端使用的版本要相同
	out_password << (quint16)0;
	out_password << mimalineedit->text().toLocal8Bit();
	out_password.device()->seek(0);
	out_password << (quint16)(ByteArray_password.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_password);
	//发送Ip地址
	receive_LocalIp();
}
void denglu::receiveMessage()
{
	blockSize = 0; //初始化其为0
	QDataStream in_Judge(tcpSocket);
	in_Judge.setVersion(QDataStream::Qt_5_6);
	//设置数据流版本，这里要和服务器端相同
	if (blockSize == 0) //如果是刚开始接收数据
	{
		//判断接收的数据是否有两字节，也就是文件的大小信息
		//如果有则保存到blockSize变量中，没有则返回，继续接收数据
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Judge >> blockSize;
	}
	if (tcpSocket->bytesAvailable() < blockSize) return;
	//如果没有得到全部的数据，则返回，继续接收数据
	in_Judge >> message;
	//将接收到的数据存放到变量中
	//qDebug() << QString::fromLocal8Bit(message);
	Note_register = QString::fromLocal8Bit(message);
	tcpSocket->disconnectFromHost();

	if (Note_register == "账号密码正确")
	{
		blockSize = 0; //初始化其为0
		QDataStream in_Accountnumber(tcpSocket);
		in_Accountnumber.setVersion(QDataStream::Qt_5_6);
		//设置数据流版本，这里要和服务器端相同
		if (blockSize == 0) //如果是刚开始接收数据
		{
			//判断接收的数据是否有两字节，也就是文件的大小信息
			//如果有则保存到blockSize变量中，没有则返回，继续接收数据
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in_Accountnumber >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		//如果没有得到全部的数据，则返回，继续接收数据
		in_Accountnumber >> PortNumber;
		//将接收到的数据存放到变量中
		//qDebug() << QString::fromLocal8Bit(PortNumber);
		Note_Accountnumber = QString::fromLocal8Bit(PortNumber);
		tcpSocket->disconnectFromHost();
		/*建txt文件存储*/
		QFile new_txt("jilu.txt");
		if (new_txt.exists())
		{
			QFile::remove("jilu.txt");
			//QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
			QByteArray str = Note_Accountnumber.toUtf8();
			new_txt.write(str);
			new_txt.close();
		}
		else
		{
			new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
			QByteArray str = Note_Accountnumber.toUtf8();
			new_txt.write(str);
			new_txt.close();
		}
		w.show();
		this->close();
	}
	else
		QMessageBox::warning(this, tr("警告"), tr("输入的账号或密码错误请重新输入"), QMessageBox::Yes);
}
void denglu::newConnect()
{
	tcpSocket->abort(); //取消已有的连接
	tcpSocket->connectToHost("10.211.26.93", 666);
	//连接到主机，这里从界面获取主机地址和端口号
}
void denglu::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("警告"), tr("请检查您的网络"), QMessageBox::Yes);
}
void denglu::on_denglubt_clicked() //连接按钮
{
	if (!zhanghaolineedit->text().isEmpty() && !mimalineedit->text().isEmpty())
		newConnect();
	else
		QMessageBox::warning(this, tr("警告"), tr("输入的账号或密码为空请重新输入"), QMessageBox::Yes);
}
void denglu::showwangjimima()
{
	p.show();
}
void denglu::showzhuce()
{
	newwindows.show();
}
void denglu::receive_LocalIp()
{
	//获取计算机名称
	QString localHostName = QHostInfo::localHostName();
//	qDebug() << "计算机名：" << localHostName;
	QHostInfo info = QHostInfo::fromName(localHostName);
	//遍历地址，只获取IPV4 地址
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			LocalIp = address.toString();
		//	qDebug() << "ipV4 地址：" << address.toString();
		}
	}
	//发送IP
	QByteArray ByteArray_LocalIp; //用于暂存我们要发送的数据
	QDataStream out_LocalIp(&ByteArray_LocalIp, QIODevice::WriteOnly);
	out_LocalIp << (quint16)0;
	out_LocalIp << LocalIp.toLocal8Bit();
	out_LocalIp.device()->seek(0);
	out_LocalIp << (quint16)(ByteArray_LocalIp.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_LocalIp);
}
denglu::~denglu()
{

}
