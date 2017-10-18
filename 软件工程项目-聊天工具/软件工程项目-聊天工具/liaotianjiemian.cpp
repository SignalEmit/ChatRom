#include "liaotianjiemian.h"
#include<QString>
#include<QDebug>
#include<QByteArray>
#include<QTextCodec>
#include<QTextCursor>
#include<QScrollBar>
liaotianjiemian::liaotianjiemian(QWidget * parent) : QWidget(parent) {
	setupUi(this);
	this->setWindowTitle("聊一聊");
	tcpSendReceiveNew = new QTcpSocket(this);
	tcpSocket = new QTcpSocket(this);
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	
	connect(tcpSendReceiveNew, SIGNAL(connected()), this, SLOT(SendNews()));
	connect(tcpSendReceiveNew, SIGNAL(readyRead()), this, SLOT(displayError(QAbstractSocket::SocketError)));

	connect(fasongbt, SIGNAL(clicked()), this, SLOT(sendNews()));
	connect(qingkongbt, SIGNAL(clicked()), this, SLOT(qingkong()));
}
void liaotianjiemian::SendReciveNews()
{
	tcpSendReceiveNew->abort(); //取消已有的连接
	tcpSendReceiveNew->connectToHost("10.211.26.93", 666);
}
void liaotianjiemian::SendNews()
{
	QByteArray ByteArray_judge; //用于暂存我们要发送的数据
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	out_judge << (quint16)0;
	out_judge << tr("发送离线消息").toLocal8Bit();
	qDebug() << "发送离线消息";
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	tcpSendReceiveNew->write(ByteArray_judge);

	/*发送账号*/
	QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
	QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
	out_account_number << (quint16)0;
	out_account_number << Me.toLocal8Bit();
	qDebug() << Me;
	out_account_number.device()->seek(0);
	out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
	tcpSendReceiveNew->write(ByteArray_account_number);


	/*发送朋友的账号*/
	QByteArray ByteArray_FriendAccountNumber; //用于暂存我们要发送的数据
	QDataStream out_FriendAccountNumber(&ByteArray_FriendAccountNumber, QIODevice::WriteOnly);
	out_FriendAccountNumber << (quint16)0;
	out_FriendAccountNumber << AccountNumber_User.toLocal8Bit();
	out_FriendAccountNumber.device()->seek(0);
	out_FriendAccountNumber << (quint16)(ByteArray_FriendAccountNumber.size() - sizeof(quint16));
	tcpSendReceiveNew->write(ByteArray_FriendAccountNumber);

	/*发送朋友的账号*/
	QByteArray ByteArray_News; //用于暂存我们要发送的数据
	QDataStream out_News(&ByteArray_News, QIODevice::WriteOnly);
	out_News << (quint16)0;
	out_News << SendTxt.toLocal8Bit();
	out_News.device()->seek(0);
	out_News << (quint16)(ByteArray_News.size() - sizeof(quint16));
	tcpSendReceiveNew->write(ByteArray_News);
}
void liaotianjiemian::Creat_or_jianchawenjianjia()
{
	QDir *File = new QDir;
	bool exits = File->exists("Liaotian_Jilu");
	if (exits)
	{
		qDebug() << "存在";
	}
	else
	{
		qDebug() << "不存在";
		bool ok = File->mkdir("Liaotian_Jilu");
		if (ok)
			qDebug() << "创建";
		else
			qDebug() << "为创建";
	}
}
void liaotianjiemian::jianchawenjianshifoucunzai_andCreat()
{
	QString Hebing = Me + "_" + AccountNumber_User;
	QFile jilu(tr("Liaotian_Jilu/%1.txt").arg(Hebing));
	if (!jilu.exists())
	{
		jilu.open(QIODevice::ReadWrite | QIODevice::Text);
		jilu.close();
	}
}
void liaotianjiemian::showEvent(QShowEvent *e)
{
	closeCheck = true;
	int i = 0;
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QFile jilu("jilu.txt");
	jilu.open(QIODevice::ReadOnly);
	QTextStream jieshou(&jilu);
	jieshou.setCodec(codec);
	while (!jieshou.atEnd())
	{
		if (i == 0)
			Me = jieshou.readLine();
		else if (i == 1)
			AccountNumber_User = jieshou.readLine();
		else if (i == 2)
			NickName_User = jieshou.readLine();
		else if (i == 3)
			PersonalizedSignature_User = jieshou.readLine();
		else if (i == 4)
			Display_Picture_User = jieshou.readLine();
		else if (i == 5)
			LocalIp_User = jieshou.readLine();
		else if(i==6)
			PortNumber_User = jieshou.readLine();
		i++;
	}
	jilu.close();
	QFile::remove("jilu.txt");

	
	Nicheng->setText(NickName_User);
	Gexingqianming->setText(PersonalizedSignature_User);
	QPixmap pixmap(Display_Picture_User);
	label_DisPlay->setPixmap(pixmap.scaled(75, 75, Qt::IgnoreAspectRatio));
	Creat_or_jianchawenjianjia();
	jianchawenjianshifoucunzai_andCreat();
	Load_txt();
	FristLoad = true;
	onLine = true;
	newConnect();

}
void liaotianjiemian::newConnect()
{
	tcpSocket->abort(); //取消已有的连接
	tcpSocket->connectToHost("10.211.26.93", 666);
}
void liaotianjiemian::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("警告"), tr("请检查您的网络"), QMessageBox::Yes);
}
void liaotianjiemian::sendMessage()
{
	if (FristLoad)
	{
		if (onLine)
		{
			QByteArray ByteArray_judge; //用于暂存我们要发送的数据
			QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
			out_judge << (quint16)0;
			out_judge << tr("接收自己的端口以及更新是否点击").toLocal8Bit();
			qDebug() << "接收自己的端口以及更新是否点击";
			out_judge.device()->seek(0);
			out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
			tcpSocket->write(ByteArray_judge);

			/*发送账号*/
			QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
			QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
			out_account_number << (quint16)0;
			out_account_number << Me.toLocal8Bit();
			qDebug() << Me;
			out_account_number.device()->seek(0);
			out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
			tcpSocket->write(ByteArray_account_number);

			/*发送朋友的账号*/
			QByteArray ByteArray_FriendAccountNumber; //用于暂存我们要发送的数据
			QDataStream out_FriendAccountNumber(&ByteArray_FriendAccountNumber, QIODevice::WriteOnly);
			out_FriendAccountNumber << (quint16)0;
			out_FriendAccountNumber << AccountNumber_User.toLocal8Bit();
			out_FriendAccountNumber.device()->seek(0);
			out_FriendAccountNumber << (quint16)(ByteArray_FriendAccountNumber.size() - sizeof(quint16));
			tcpSocket->write(ByteArray_FriendAccountNumber);
		}
		else
		{
			QByteArray ByteArray_judge; //用于暂存我们要发送的数据
			QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
			out_judge << (quint16)0;
			out_judge << tr("关闭聊天端的端口").toLocal8Bit();
			qDebug() << "关闭聊天端的端口";
			out_judge.device()->seek(0);
			out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
			tcpSocket->write(ByteArray_judge);

			/*发送账号*/
			QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
			QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
			out_account_number << (quint16)0;
			out_account_number << Me.toLocal8Bit();
			qDebug() << Me;
			out_account_number.device()->seek(0);
			out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
			tcpSocket->write(ByteArray_account_number);

			/*发送朋友的账号*/
			QByteArray ByteArray_FriendAccountNumber; //用于暂存我们要发送的数据
			QDataStream out_FriendAccountNumber(&ByteArray_FriendAccountNumber, QIODevice::WriteOnly);
			out_FriendAccountNumber << (quint16)0;
			out_FriendAccountNumber << AccountNumber_User.toLocal8Bit();
			out_FriendAccountNumber.device()->seek(0);
			out_FriendAccountNumber << (quint16)(ByteArray_FriendAccountNumber.size() - sizeof(quint16));
			tcpSocket->write(ByteArray_FriendAccountNumber);
		}
	}
	else
	{
		QByteArray ByteArray_judge; //用于暂存我们要发送的数据
		QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
		out_judge << (quint16)0;
		out_judge << tr("判断朋友是否也打开窗口").toLocal8Bit();
		qDebug() << "判断朋友是否也打开窗口";
		out_judge.device()->seek(0);
		out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_judge);

		/*发送账号*/
		QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
		QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
		out_account_number << (quint16)0;
		out_account_number << Me.toLocal8Bit();
		qDebug() << Me;
		out_account_number.device()->seek(0);
		out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_account_number);

		/*发送朋友的账号*/
		QByteArray ByteArray_FriendAccountNumber; //用于暂存我们要发送的数据
		QDataStream out_FriendAccountNumber(&ByteArray_FriendAccountNumber, QIODevice::WriteOnly);
		out_FriendAccountNumber << (quint16)0;
		out_FriendAccountNumber << AccountNumber_User.toLocal8Bit();
		out_FriendAccountNumber.device()->seek(0);
		out_FriendAccountNumber << (quint16)(ByteArray_FriendAccountNumber.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_FriendAccountNumber);
	}
}
void liaotianjiemian::receiveMessage()
{
	if (FristLoad)
	{
		if (onLine)
		{
		quint16 blockSize = 0; //初始化其为0
		QDataStream in(tcpSocket);
		in.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		in >> message;
		qDebug() << QString::fromLocal8Bit(message);
		Me_PortNumber = QString::fromLocal8Bit(message);
		//tcpSocket->disconnectFromHost();

		QString JudgeOnline;
		blockSize = 0; //初始化其为0
		QDataStream in_JudgeOnline(tcpSocket);
		in_JudgeOnline.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in_JudgeOnline >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		in_JudgeOnline >> message;
		JudgeOnline = QString::fromLocal8Bit(message);
		qDebug() << JudgeOnline;

		if (JudgeOnline == "有离线消息")
		{
			QString New_Recive;
			quint16 blockSize = 0; //初始化其为0
			QDataStream in(tcpSocket);
			in.setVersion(QDataStream::Qt_5_6);
			if (blockSize == 0)
			{
				if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
				in >> blockSize;
			}
			if (tcpSocket->bytesAvailable() < blockSize) return;
			in >> message;
			qDebug() << QString::fromLocal8Bit(message);
			New_Recive = QString::fromLocal8Bit(message);

			QString str = AccountNumber_User + ":" + New_Recive;
			shuchu->append(str);
		}

		receiver->bind(Me_PortNumber.toInt(), QUdpSocket::ShareAddress);
		connect(receiver, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
		}
		else
		{
			quint16 blockSize = 0; //初始化其为0
			QDataStream in(tcpSocket);
			in.setVersion(QDataStream::Qt_5_6);
			if (blockSize == 0)
			{
				if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
				in >> blockSize;
			}
			if (tcpSocket->bytesAvailable() < blockSize) return;
			in >> message;
			qDebug() << QString::fromLocal8Bit(message);
			tcpSocket->disconnectFromHost();
			closeCheck = false;
			emit closeThisWindowAgain();
		}
		
	}
	else
	{
		QString Judge;
		quint16 blockSize = 0; //初始化其为0
		QDataStream in(tcpSocket);
		in.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		in >> message;
		QString panduan= QString::fromLocal8Bit(message);			//判断是否打开客户端

		if (panduan == "是")
		{
			QHostAddress adr = QHostAddress(tr("%1").arg(LocalIp_User));
			sender->writeDatagram(SendTxt.toUtf8(), SendTxt.toUtf8().size(), adr, PortNumber_User.toInt());
		}
		else
		{
			SendReciveNews();
		}
	}
}
void liaotianjiemian::processPendingDatagram()
{
	/*接收数据报*/
	while (receiver->hasPendingDatagrams())  //拥有等待的数据报
	{
		QByteArray datagram; //拥于存放接收的数据报
		datagram.resize(receiver->pendingDatagramSize());
		//让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
		receiver->readDatagram(datagram.data(), datagram.size());
		//接收数据报，将其存放到datagram中
		qDebug() << AccountNumber_User;
		QString str = AccountNumber_User + "：" + datagram;
		shuchu->append(str);
		//将数据报内容显示出来
	}
}
void liaotianjiemian::Load_txt()
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QString Hebing = Me + "_" + AccountNumber_User;
	QFile jilu(tr("Liaotian_Jilu/%1.txt").arg(Hebing));
	jilu.open(QIODevice::ReadOnly);
	QTextStream jieshou(&jilu);
	jieshou.setCodec(codec);
	while (!jieshou.atEnd())
	{
		QString linestr;
		linestr = jieshou.readAll();
		shuchu->setPlainText(linestr);
	}
	shuchu->setReadOnly(true);
	QScrollBar *scrollBar = shuchu->verticalScrollBar();
	scrollBar->setSliderPosition(scrollBar->maximum());
	jilu.close();
}
void liaotianjiemian::closeEvent(QCloseEvent *e)
{
	if (closeCheck)
	{
		FristLoad = true;
		onLine = false;
		newConnect();
		connect(this, SIGNAL(closeThisWindowAgain()), this, SLOT(close()));
		e->ignore();
	}
	else
	{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	QString Hebing = Me + "_" + AccountNumber_User;
	QFile jilu(tr("Liaotian_Jilu/%1.txt").arg(Hebing));
	jilu.open(QIODevice::ReadWrite | QIODevice::Text);
	QByteArray str = shuchu->toPlainText().toUtf8();
	jilu.write(str);
	jilu.close();
	receiver->disconnectFromHost();
	e->accept();
	}
}
void liaotianjiemian::sendNews()
{
	QString str = "\t\t\t\t\t我：" + shuru->toPlainText();
	SendTxt = shuru->toPlainText();
	shuchu->append(str);
	/*发送数据报*/
	FristLoad = false;
	shuru->clear();
	newConnect();
}
void liaotianjiemian::qingkong()
{
	shuru->clear();
}
liaotianjiemian::~liaotianjiemian() {
	
}
