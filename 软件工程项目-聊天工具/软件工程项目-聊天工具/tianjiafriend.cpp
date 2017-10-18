#include "tianjiafriend.h"
#include<QDebug>
tianjiafriend::tianjiafriend(QWidget * parent) : QWidget(parent) {
	setupUi(this);
	this->setWindowTitle("聊一聊");
	tcpSocket = new QTcpSocket(this);
	connect(guanbibt, SIGNAL(clicked()), this, SLOT(close()));
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}
void tianjiafriend::on_querentianjiabt_clicked()
{
	if (chaxun_zhanghao->text().isEmpty())
		QMessageBox::warning(this, tr("警告"), tr("请先查询账号"), QMessageBox::Yes);
	else
	{ 
		tcpSocket->abort(); //取消已有的连接
		tcpSocket->connectToHost("10.211.26.93", 666);
		Judge_send = false;
	}
}
void tianjiafriend::receiveMessage()
{
	QString Judge;			//记录
	QByteArray message;
	quint16  blockSize = 0;
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (tcpSocket->bytesAvailable() < blockSize) return;
	in >> message;
	Judge = QString::fromLocal8Bit(message);
	tcpSocket->disconnectFromHost();


	if (Judge_send)
	{
		if (Judge == "账号不存在或账号错误")
			QMessageBox::warning(this, tr("警告"), tr("账号不存在或账号错误"), QMessageBox::Yes);
		else
		{
			for (int i = 0; i < 5; i++)
			{
				blockSize = 0; //初始化其为0
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
				if (i == 0)
					Display = QString::fromLocal8Bit(message);
				else if (i == 1)
					AccountNumber = QString::fromLocal8Bit(message);
				else if (i == 2)
					Sex = QString::fromLocal8Bit(message);
				else if (i == 3)
					NickName = QString::fromLocal8Bit(message);
				else if (i == 4)
					PersonalizedSignature = QString::fromLocal8Bit(message);
			}
			tcpSocket->disconnectFromHost();
			QPixmap pixmap(Display);
			chaxun_touxiang->setPixmap(pixmap.scaled(91, 91, Qt::IgnoreAspectRatio));
			chaxun_zhanghao->setText(AccountNumber);
			chaxun_nicheng->setText(NickName);
			chaxun_xingbie->setText(Sex);
			chaxun_qianming->setText(PersonalizedSignature);
		}
	}
	else
	{
		if (Judge == "此账号以添加")
			QMessageBox::warning(this, tr("警告"), tr("此账号以添加请勿重复添加！！！"), QMessageBox::Yes);
		else
		{
			qDebug() << "添加成功信号以发送";
			QMessageBox::about(this, "提示", "程序员爸爸提示你,请求已发送请等待摸摸哒");
			this->close();
		}
	}
}
void tianjiafriend::sendMessage()
{
	if (Judge_send)
	{
		QByteArray ByteArray_judge; //用于暂存我们要发送的数据
		QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
		out_judge << (quint16)0;
		out_judge << tr("待添加人的信息").toLocal8Bit();
		out_judge.device()->seek(0);
		out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_judge);

		/*发送待查询的账号*/
		QByteArray ByteArray_addFriendNumber; //用于暂存我们要发送的数据
		QDataStream out_addFriendNumber(&ByteArray_addFriendNumber, QIODevice::WriteOnly);
		out_addFriendNumber << (quint16)0;
		out_addFriendNumber << shuru_zhanghao->text().toLocal8Bit();
		out_addFriendNumber.device()->seek(0);
		out_addFriendNumber << (quint16)(ByteArray_addFriendNumber.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_addFriendNumber);
		shuru_zhanghao->clear();
	}
	else
	{
		QByteArray ByteArray_judge; //用于暂存我们要发送的数据
		QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
		out_judge << (quint16)0;
		out_judge << tr("添加好友").toLocal8Bit();
		out_judge.device()->seek(0);
		out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_judge);

		/*发送客户端的账号*/
		QByteArray ByteArray_Me; //用于暂存我们要发送的数据
		QDataStream out_Me(&ByteArray_Me, QIODevice::WriteOnly);
		out_Me << (quint16)0;
		out_Me << Me.toLocal8Bit();
		out_Me.device()->seek(0);
		out_Me << (quint16)(ByteArray_Me.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_Me);

		/*发送待查询的账号*/
		QByteArray ByteArray_addFriendNumber; //用于暂存我们要发送的数据
		QDataStream out_addFriendNumber(&ByteArray_addFriendNumber, QIODevice::WriteOnly);
		out_addFriendNumber << (quint16)0;
		out_addFriendNumber << chaxun_zhanghao->text().toLocal8Bit();
		out_addFriendNumber.device()->seek(0);
		out_addFriendNumber << (quint16)(ByteArray_addFriendNumber.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_addFriendNumber);
	}
}
void tianjiafriend::showEvent(QShowEvent *e)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QFile jilu("jilu.txt");
	jilu.open(QIODevice::ReadOnly);
	QTextStream jieshou(&jilu);
	jieshou.setCodec(codec);
	while (!jieshou.atEnd())
		Me = jieshou.readLine();
	jilu.close();
	QFile::remove("jilu.txt");
}
void tianjiafriend::on_chaxunbt_clicked()
{
	if (shuru_zhanghao->text().isEmpty())
		QMessageBox::warning(this, tr("警告"), tr("输入的账号为空，请输入！"), QMessageBox::Yes);
	else
	{
		Judge_send = true;
		chaxunbt->setEnabled(false);
		tcpSocket->abort(); //取消已有的连接
		tcpSocket->connectToHost("10.211.26.93", 666);
		
	}
}
void tianjiafriend::on_CheckAgain_clicked()
{
	shuru_zhanghao->clear();
	chaxun_touxiang->clear();
	chaxun_zhanghao->clear();
	chaxun_nicheng->clear();
	chaxun_xingbie->clear();
	chaxun_qianming->clear();
	chaxunbt->setEnabled(true);
}
void tianjiafriend::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("警告"), tr("请检查您的网络"), QMessageBox::Yes);
}
tianjiafriend::~tianjiafriend() {
	
}
