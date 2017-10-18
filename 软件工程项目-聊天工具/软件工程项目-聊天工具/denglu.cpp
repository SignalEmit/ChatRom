#include "denglu.h"
#include<QDebug>
denglu::denglu(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	mimalineedit->setEchoMode(QLineEdit::Password);
	this->setWindowTitle("��һ��");
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
	QByteArray ByteArray_judge; //�����ݴ�����Ҫ���͵�����
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	//ʹ��������д������
	//�����������İ汾���ͻ��˺ͷ�������ʹ�õİ汾Ҫ��ͬ
	out_judge << (quint16)0;
	out_judge << tr("��¼").toLocal8Bit();
	//qDebug() << "��¼";
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_judge);

	QByteArray ByteArray_account_number; //�����ݴ�����Ҫ���͵�����
	QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
	//ʹ��������д������
	//�����������İ汾���ͻ��˺ͷ�������ʹ�õİ汾Ҫ��ͬ
	out_account_number << (quint16)0;
	out_account_number << zhanghaolineedit->text().toLocal8Bit();
	qDebug() << zhanghaolineedit->text();
	out_account_number.device()->seek(0);
	out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_account_number);

	//��������
	QByteArray ByteArray_password; //�����ݴ�����Ҫ���͵�����
	QDataStream out_password(&ByteArray_password, QIODevice::WriteOnly);
	//ʹ��������д������
	//�����������İ汾���ͻ��˺ͷ�������ʹ�õİ汾Ҫ��ͬ
	out_password << (quint16)0;
	out_password << mimalineedit->text().toLocal8Bit();
	out_password.device()->seek(0);
	out_password << (quint16)(ByteArray_password.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_password);
	//����Ip��ַ
	receive_LocalIp();
}
void denglu::receiveMessage()
{
	blockSize = 0; //��ʼ����Ϊ0
	QDataStream in_Judge(tcpSocket);
	in_Judge.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		//�жϽ��յ������Ƿ������ֽڣ�Ҳ�����ļ��Ĵ�С��Ϣ
		//������򱣴浽blockSize�����У�û���򷵻أ�������������
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Judge >> blockSize;
	}
	if (tcpSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Judge >> message;
	//�����յ������ݴ�ŵ�������
	//qDebug() << QString::fromLocal8Bit(message);
	Note_register = QString::fromLocal8Bit(message);
	tcpSocket->disconnectFromHost();

	if (Note_register == "�˺�������ȷ")
	{
		blockSize = 0; //��ʼ����Ϊ0
		QDataStream in_Accountnumber(tcpSocket);
		in_Accountnumber.setVersion(QDataStream::Qt_5_6);
		//�����������汾������Ҫ�ͷ���������ͬ
		if (blockSize == 0) //����Ǹտ�ʼ��������
		{
			//�жϽ��յ������Ƿ������ֽڣ�Ҳ�����ļ��Ĵ�С��Ϣ
			//������򱣴浽blockSize�����У�û���򷵻أ�������������
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in_Accountnumber >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		//���û�еõ�ȫ�������ݣ��򷵻أ�������������
		in_Accountnumber >> PortNumber;
		//�����յ������ݴ�ŵ�������
		//qDebug() << QString::fromLocal8Bit(PortNumber);
		Note_Accountnumber = QString::fromLocal8Bit(PortNumber);
		tcpSocket->disconnectFromHost();
		/*��txt�ļ��洢*/
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
		QMessageBox::warning(this, tr("����"), tr("������˺Ż������������������"), QMessageBox::Yes);
}
void denglu::newConnect()
{
	tcpSocket->abort(); //ȡ�����е�����
	tcpSocket->connectToHost("10.211.26.93", 666);
	//���ӵ�����������ӽ����ȡ������ַ�Ͷ˿ں�
}
void denglu::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("����"), tr("������������"), QMessageBox::Yes);
}
void denglu::on_denglubt_clicked() //���Ӱ�ť
{
	if (!zhanghaolineedit->text().isEmpty() && !mimalineedit->text().isEmpty())
		newConnect();
	else
		QMessageBox::warning(this, tr("����"), tr("������˺Ż�����Ϊ������������"), QMessageBox::Yes);
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
	//��ȡ���������
	QString localHostName = QHostInfo::localHostName();
//	qDebug() << "���������" << localHostName;
	QHostInfo info = QHostInfo::fromName(localHostName);
	//������ַ��ֻ��ȡIPV4 ��ַ
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			LocalIp = address.toString();
		//	qDebug() << "ipV4 ��ַ��" << address.toString();
		}
	}
	//����IP
	QByteArray ByteArray_LocalIp; //�����ݴ�����Ҫ���͵�����
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
