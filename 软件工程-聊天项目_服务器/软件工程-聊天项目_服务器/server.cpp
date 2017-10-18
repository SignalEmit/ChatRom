#include "server.h"
#include<QDebug>
Server::Server(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	blockSize = 0;
	Record_The_Number = 0;
	JudgeDatabase();
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("shujuku.db");
	tcpServer = new QTcpServer(this);
	receiveSocket = new QTcpSocket(this);
	if (!tcpServer->listen(QHostAddress::AnyIPv4, 666))
	{
		qDebug() << tcpServer->errorString();
		this->close();
	}
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(monitor()));
}
void Server::monitor()
{
	receiveSocket = tcpServer->nextPendingConnection();
	connect(receiveSocket, SIGNAL(readyRead()), this, SLOT(receive_information()));
}
void Server::send(QString s)
{
	QByteArray data;			//��ʱҪ���͵�����
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_6);						//�����������汾
	out << (quint16)0;
	out << s.toLocal8Bit();
	out.device()->seek(0);
	out << (quint16)(data.size() - sizeof(quint16));
	receiveSocket->write(data);				
}
void Server::receive_information()
{
	QString Judge;
	/*�����жϵĶ���*/
	blockSize = 0;
	QDataStream in_Judge(receiveSocket);
	in_Judge.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Judge >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Judge >> ByteArray_Judge;
	Judge = QString::fromLocal8Bit(ByteArray_Judge);
	if (Judge == "��¼")
		receive_entry();
	else if (Judge == "ע��")
		receive_register();
	else if (Judge == "��������")
		receive_password();
	else if (Judge == "��¼������")
		MasterLoginInterface();
	else if (Judge == "��ȡ��ϵ��")
		ReadLinkman();
	else if (Judge == "�����Լ��Ķ˿��Լ������Ƿ���")
		MePortNumber();
	else if (Judge == "�޸ĸ�����Ϣ")
		ClickUserInformation();
	else if (Judge == "������˵���Ϣ")
		selectaddUser();
	else if (Judge == "��Ӻ���")
		addUser();
	else if (Judge == "����")
		DownOnline();
	else if (Judge == "ȷ�����")
		confirmAdd();
	else if (Judge == "���Ѵ������ݿ�")
		AddFriendInDatebase();
	else if (Judge == "�ж������Ƿ�Ҳ�򿪴���")
		JudgeFriendOpenWindows();
	else if (Judge == "�ر�����˵Ķ˿�")
		closeChatWindow();
	else if (Judge == "����������Ϣ")
		ReceiveOffineMessage();
}
void Server::ReceiveOffineMessage()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	QByteArray ByteArray_News;
	QString News;
	blockSize = 0;
	QDataStream in_News(receiveSocket);
	in_News.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_News >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_News >> ByteArray_News;
	News = QString::fromLocal8Bit(ByteArray_News);

	QDir *File = new QDir;
	bool exits = File->exists("Liaotian_Jilu");
	if (exits)
	{
		qDebug() << "����";
	}
	else
	{
		qDebug() << "������";
		bool ok = File->mkdir("Liaotian_Jilu");
		if (ok)
			qDebug() << "����";
		else
			qDebug() << "Ϊ����";
	}
	take_notes = Accountnumber + "_" + FriendAccountnumber;
	QFile jilu(tr("Liaotian_Jilu/%1.txt").arg(take_notes));
	if (!jilu.exists())
	{
		jilu.open(QIODevice::ReadWrite | QIODevice::Text);
		jilu.close();
	}
	QString a = News + "\n";			//�Ӹ�б�ܻ���
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	QFile jilu1(tr("Liaotian_Jilu/%1.txt").arg(take_notes));
	jilu1.open(QIODevice::ReadWrite | QIODevice::Text|QIODevice::Append);
	QByteArray str = a.toUtf8();
	jilu1.write(str);
	jilu1.close();

	take_notes = "Liaotian_Jilu/" + take_notes+".txt";

	bool Judge_Whether_add=false;
	auto detection = newInformation.begin();
	while (detection != newInformation.end())
	{
		if (detection->UserAccountNumber == Accountnumber && detection->FriendAccountNumber == FriendAccountnumber)
		{
			Judge_Whether_add = true;
			break;
		}
		detection++;
	}
	if (!Judge_Whether_add)
	{
		newsSave news_send(receiveSocket, Accountnumber, FriendAccountnumber, take_notes);
		newInformation.push_back(news_send);
		qDebug() << news_send.FilePath;
	}
	/*�����ߵĿͻ��˷���Ϣ �ý�����Ϣ�Թ���ʾ*/
	auto CheckSendGiveOnline = onlineUsers.begin();			//���������û�
	while (CheckSendGiveOnline != onlineUsers.end())
	{
		if (CheckSendGiveOnline->UserAccountNumber == FriendAccountnumber)		//���������û�
		{
			QByteArray data_Judge;			//��ʱҪ���͵�����
			QDataStream out_Judge(&data_Judge, QIODevice::WriteOnly);
			out_Judge.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out_Judge << (quint16)0;
			out_Judge << tr("���߷�����Ϣ").toLocal8Bit();
			out_Judge.device()->seek(0);
			out_Judge << (quint16)(data_Judge.size() - sizeof(quint16));
			CheckSendGiveOnline->UserServerSocket->write(data_Judge);


			QByteArray data_Send_Friend;			//��ʱҪ���͵�����
			QDataStream out_Send_Friend(&data_Send_Friend, QIODevice::WriteOnly);
			out_Send_Friend.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out_Send_Friend << (quint16)0;
			out_Send_Friend << Accountnumber.toLocal8Bit();
			out_Send_Friend.device()->seek(0);
			out_Send_Friend << (quint16)(data_Send_Friend.size() - sizeof(quint16));
			CheckSendGiveOnline->UserServerSocket->write(data_Send_Friend);			//����������ѵ������Թ��������������ҳ�����˵���Ϣ
			break;
		}
		CheckSendGiveOnline++;
	}
}
void Server::closeChatWindow()
{

	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*���µ��״̬*/
	db.open();
	QSqlQuery UpdateWhetherClicked;					//�����Ƿ���
	UpdateWhetherClicked.prepare("update Friend_Table set Panduan_dianji='��' where Me=? and Friend_Zhanghao=?");
	UpdateWhetherClicked.addBindValue(Accountnumber);
	UpdateWhetherClicked.addBindValue(FriendAccountnumber);
	UpdateWhetherClicked.exec();
	db.close();

	QByteArray data;			//��ʱҪ���͵�����
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_6);						//�����������汾
	out << (quint16)0;
	out <<tr("���촰�ڹر�").toLocal8Bit();
	out.device()->seek(0);
	out << (quint16)(data.size() - sizeof(quint16));
	receiveSocket->write(data);
}
void Server::JudgeFriendOpenWindows()
{

	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);


	db.open();
	QSqlQuery JudgeWhetherClicked;
	JudgeWhetherClicked.prepare("select Panduan_dianji from Friend_Table where Me=? and Friend_Zhanghao=?");
	JudgeWhetherClicked.addBindValue(Accountnumber);
	JudgeWhetherClicked.addBindValue(FriendAccountnumber);
	JudgeWhetherClicked.exec();
	JudgeWhetherClicked.next();

	QByteArray data;			//��ʱҪ���͵�����
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_6);						//�����������汾
	out << (quint16)0;
	out << JudgeWhetherClicked.value(0).toString().toLocal8Bit();
	out.device()->seek(0);
	out << (quint16)(data.size() - sizeof(quint16));
	receiveSocket->write(data);
}
void Server::AddFriendInDatebase()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѷ�����˺�*/
	blockSize = 0;
	QDataStream in_FenzuNUmber(receiveSocket);
	in_FenzuNUmber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FenzuNUmber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FenzuNUmber >> ByteArray_Fenzu;
	int Friend_Fenzu = QString::fromLocal8Bit(ByteArray_Fenzu).toInt();
	receiveSocket->disconnectFromHost();

	db.open();

	QSqlQuery depositDateBase;				//�������ݿ�
	depositDateBase.prepare("insert into Friend_Table(Me,Friend_Zhanghao,Fenzuhao) values(:Me,:Friend_Zhanghao,:Fenzuhao)");
	depositDateBase.bindValue(":Me", Accountnumber);
	depositDateBase.bindValue(":Friend_Zhanghao", FriendAccountnumber);
	depositDateBase.bindValue(":Fenzuhao", Friend_Fenzu);
	depositDateBase.exec();
	db.close();
}
void Server::confirmAdd()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѷ�����˺�*/
	blockSize = 0;
	QDataStream in_FenzuNUmber(receiveSocket);
	in_FenzuNUmber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FenzuNUmber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FenzuNUmber >> ByteArray_Fenzu;
	int Friend_Fenzu = QString::fromLocal8Bit(ByteArray_Fenzu).toInt();
	receiveSocket->disconnectFromHost();


	if (FriendAccountnumber == Accountnumber)
	{
		qDebug() << "��ӵ���ͬһ����";
		return;
	}

	auto check = onlineUsers.begin();
	while (check != onlineUsers.end())
	{
		if (check->UserAccountNumber == FriendAccountnumber)
		{
			db.open();	

			QSqlQuery depositDateBase;				//�������ݿ�
			depositDateBase.prepare("insert into Friend_Table(Me,Friend_Zhanghao,Fenzuhao) values(:Me,:Friend_Zhanghao,:Fenzuhao)");
			depositDateBase.bindValue(":Me", Accountnumber);
			depositDateBase.bindValue(":Friend_Zhanghao", FriendAccountnumber);
			depositDateBase.bindValue(":Fenzuhao", Friend_Fenzu);
			depositDateBase.exec();
			db.close();

			db.open();
			QSqlQuery inquireFriendInformation;
			inquireFriendInformation.prepare("select Sex,Nicheng,Gexingqianming,Display_Picture,PortNumber,LocalIp from YongHu_Xinxi where Zhanghao=?");
			inquireFriendInformation.addBindValue(Accountnumber);
			inquireFriendInformation.exec();
			inquireFriendInformation.next();
			db.close();
		
			QByteArray data_Judge;			//��ʱҪ���͵�����
			QDataStream out_Judge(&data_Judge, QIODevice::WriteOnly);
			out_Judge.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out_Judge << (quint16)0;
			out_Judge << tr("��ӳɹ�").toLocal8Bit();
			out_Judge.device()->seek(0);
			out_Judge << (quint16)(data_Judge.size() - sizeof(quint16));
			check->UserServerSocket->write(data_Judge);

			UserInformation people(999, Accountnumber, inquireFriendInformation.value(0).toString(), inquireFriendInformation.value(1).toString(), inquireFriendInformation.value(2).toString(), inquireFriendInformation.value(3).toString(), inquireFriendInformation.value(4).toString(), inquireFriendInformation.value(5).toString());
			qDebug() << people.fenzu_User << people.AccountNumber_User << people.Sex_User << people.NickName_User << people.PersonalizedSignature_User << people.Display_Picture_User << people.PortNumber_User << people.LocalIp_User;
			QByteArray data;			//��ʱҪ���͵�����
			QDataStream out(&data, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out << (quint16)0;
			out << people;
			out.device()->seek(0);
			out << (quint16)(data.size() - sizeof(quint16));
			check->UserServerSocket->write(data);
		}
		check++;
	}
}
void Server::DownOnline()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);
	qDebug() << Accountnumber;

	db.open();
	QSqlQuery UpdateUserOlineline;
	UpdateUserOlineline.prepare("update YongHu_Xinxi set Panduan_zaixian='������' where Zhanghao=?");
	UpdateUserOlineline.exec();
	db.close();

	auto detectionOnline = onlineUsers.begin();			//��Ⲣ����
	while (detectionOnline != onlineUsers.end())
	{
		if (detectionOnline->UserAccountNumber == Accountnumber)
		{
			onlineUsers.erase(detectionOnline);
			ui.label->setText(tr("��ǰ��������%0��").arg(onlineUsers.size()));
			break;
		}
		else
			detectionOnline++;
	}
	send("����");
}
void Server::addUser()
{
	/*�����Լ����˺�*/
	blockSize = 0;
	QDataStream in_MeAccountnumber(receiveSocket);
	in_MeAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_MeAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_MeAccountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	db.open();
	QSqlQuery addFriend;
	addFriend.prepare("select * from Friend_Table where Me=? and Friend_Zhanghao=?");
	addFriend.addBindValue(Accountnumber);
	addFriend.addBindValue(FriendAccountnumber);
	addFriend.exec();
	if (addFriend.next())
		send("���˺������");
	else
	{

		auto checkUsers = onlineUsers.begin();
		while (checkUsers != onlineUsers.end())
		{
			if (checkUsers->UserAccountNumber == FriendAccountnumber)
			{
				db.open();
				QSqlQuery checkFriend;
				checkFriend.prepare("select Zhanghao,Sex,Gexingqianming,Nicheng,Display_Picture,PortNumber,LocalIp from YongHu_Xinxi where Zhanghao=?");
				checkFriend.addBindValue(Accountnumber);
				checkFriend.exec();
				checkFriend.next();
				/*QString AccountNumber_, QString Sex_, QString NickName_, QString PersonalizedSignature_, QString Display_Picture_, QString PortNumber_, QString LocalIp_*/
				UserInformation User(1, checkFriend.value(0).toString(), checkFriend.value(1).toString(), checkFriend.value(3).toString(), checkFriend.value(2).toString(), checkFriend.value(4).toString(), checkFriend.value(5).toString(), checkFriend.value(6).toString());
				qDebug() << checkFriend.value(0).toString() << checkFriend.value(1).toString() << checkFriend.value(3).toString() << checkFriend.value(2).toString() << checkFriend.value(4).toString() << checkFriend.value(5).toString() << checkFriend.value(6).toString();

				send("�����Է���");			//���͸���������Ŀͻ���

				/*����Ҫ�Ŀͻ��˷�������*/
				QByteArray ByteArray_request;			//��ʱҪ���͵�����
				QDataStream out_request(&ByteArray_request, QIODevice::WriteOnly);
				out_request.setVersion(QDataStream::Qt_5_6);						//�����������汾
				out_request << (quint16)0;
				out_request << tr("�������").toLocal8Bit();
				out_request.device()->seek(0);
				out_request << (quint16)(ByteArray_request.size() - sizeof(quint16));
				checkUsers->UserServerSocket->write(ByteArray_request);
				//checkUsers->UserServerSocket->disconnectFromHost();

				QByteArray data;			//��ʱҪ���͵�����
				QDataStream out(&data, QIODevice::WriteOnly);
				out.setVersion(QDataStream::Qt_5_6);						//�����������汾
				out << (quint16)0;
				out << User;
				out.device()->seek(0);
				out << (quint16)(data.size() - sizeof(quint16));
				checkUsers->UserServerSocket->write(data);
				//checkUsers->UserServerSocket->disconnectFromHost();
				qDebug() << "���ͳɹ�";
				break;
			}
			checkUsers++;
		}
	}
}
void Server::selectaddUser()
{
	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	QString FriendAccountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	
	db.open();
	QSqlQuery inquireFriendInformation;
	inquireFriendInformation.prepare("select Display_Picture,Zhanghao,Sex,Nicheng,Gexingqianming from YongHu_Xinxi where Zhanghao=?");
	inquireFriendInformation.addBindValue(FriendAccountnumber);
	inquireFriendInformation.exec();
	if (inquireFriendInformation.next())
	{
		send("�˺Ŵ���");
		send(inquireFriendInformation.value(0).toString());
		send(inquireFriendInformation.value(1).toString());
		send(inquireFriendInformation.value(2).toString());
		send(inquireFriendInformation.value(3).toString());
		send(inquireFriendInformation.value(4).toString());
	}
	else
		send("�˺Ų����ڻ��˺Ŵ���");
}
void Server::ClickUserInformation()
{
	QString information[5];
	QByteArray ByteArray_Information;
	for (int i = 0; i < 5; i++)
	{
		blockSize = 0;
		QDataStream in_information(receiveSocket);
		in_information.setVersion(QDataStream::Qt_5_6);
		//�����������汾������Ҫ�ͷ���������ͬ
		if (blockSize == 0) //����Ǹտ�ʼ��������
		{
			if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in_information >> blockSize;
		}
		if (receiveSocket->bytesAvailable() < blockSize) return;
		//���û�еõ�ȫ�������ݣ��򷵻أ�������������
		in_information >> ByteArray_Information;
		information[i] = QString::fromLocal8Bit(ByteArray_Information);
	}

	db.open();
	QSqlQuery clickinformation;
	clickinformation.prepare("update YongHu_Xinxi set Sex=?,Nicheng=?,Gexingqianming=?,Display_Picture=? where Zhanghao=?");
	clickinformation.addBindValue(information[1]);
	clickinformation.addBindValue(information[2]);
	clickinformation.addBindValue(information[3]);
	clickinformation.addBindValue(information[4]);
	clickinformation.addBindValue(information[0]);
	clickinformation.exec();
}
void Server::MePortNumber()
{
	QString Accountnumber_Send;
	bool JudgeOnline = false;							//�ж��Ƿ�����
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	Accountnumber_Send = QString::fromLocal8Bit(ByteArray_Accountnumber);

	QString FriendAccountnumber_Send;
	/*�������ѵ��˺�*/
	blockSize = 0;
	QDataStream in_FriendAccountnumber(receiveSocket);
	in_FriendAccountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_FriendAccountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_FriendAccountnumber >> ByteArray_Accountnumber;
	FriendAccountnumber_Send = QString::fromLocal8Bit(ByteArray_Accountnumber);

	db.open();
	QSqlQuery FindMePortNumber;
	FindMePortNumber.prepare("select PortNumber from YongHu_Xinxi where Zhanghao=?");
	FindMePortNumber.addBindValue(Accountnumber_Send);
	FindMePortNumber.exec();
	FindMePortNumber.next();
	db.close();

	QByteArray data_MePortNumber;			//��ʱҪ���͵�����
	QDataStream out_MePortNumber(&data_MePortNumber, QIODevice::WriteOnly);
	out_MePortNumber.setVersion(QDataStream::Qt_5_6);						//�����������汾
	out_MePortNumber << (quint16)0;
	out_MePortNumber << FindMePortNumber.value(0).toString().toLocal8Bit();
	out_MePortNumber.device()->seek(0);
	out_MePortNumber << (quint16)(data_MePortNumber.size() - sizeof(quint16));
	receiveSocket->write(data_MePortNumber);

	/*���µ��״̬*/
	db.open();
	QSqlQuery UpdateWhetherClicked;					//�����Ƿ���
	UpdateWhetherClicked.prepare("update Friend_Table set Panduan_dianji='��' where Me=? and Friend_Zhanghao=?");
	UpdateWhetherClicked.addBindValue(Accountnumber_Send);
	UpdateWhetherClicked.addBindValue(FriendAccountnumber_Send);
	UpdateWhetherClicked.exec();
	db.close();

	QString readall;
	auto FindReceiveNews = newInformation.begin();
	if(FindReceiveNews!= newInformation.end())
	qDebug() << FindReceiveNews->UserAccountNumber << FindReceiveNews->FriendAccountNumber;
	while (FindReceiveNews != newInformation.end())
	{
		if (FindReceiveNews->FriendAccountNumber == Accountnumber_Send&& FindReceiveNews->UserAccountNumber == FriendAccountnumber_Send)
		{
			JudgeOnline = true;
			QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			QFile File_send(FindReceiveNews->FilePath);
			File_send.open(QIODevice::ReadOnly);
			QTextStream jieshou(&File_send);
			jieshou.setCodec(codec);
			while (!jieshou.atEnd())
			{
				readall = jieshou.readAll();
			}
			File_send.close();

			
			QFile::remove(FindReceiveNews->FilePath);
			/*���͵�ָ���Ķ˿�*/

			QByteArray Send_Judge;			//��ʱҪ���͵�����
			QDataStream out_Judge(&Send_Judge, QIODevice::WriteOnly);
			out_Judge.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out_Judge << (quint16)0;
			out_Judge << tr("��������Ϣ").toLocal8Bit();
			out_Judge.device()->seek(0);
			out_Judge << (quint16)(Send_Judge.size() - sizeof(quint16));
			receiveSocket->write(Send_Judge);

			QByteArray data;			//��ʱҪ���͵�����
			QDataStream out(&data, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out << (quint16)0;
			out << readall.toLocal8Bit();
			out.device()->seek(0);
			out << (quint16)(data.size() - sizeof(quint16));
			receiveSocket->write(data);
			newInformation.erase(FindReceiveNews);
			break;
		}
		FindReceiveNews++;
	}
	if (!JudgeOnline)
	{
		QByteArray Send_Judge;			//��ʱҪ���͵�����
		QDataStream out_Judge(&Send_Judge, QIODevice::WriteOnly);
		out_Judge.setVersion(QDataStream::Qt_5_6);						//�����������汾
		out_Judge << (quint16)0;
		out_Judge << tr("����Ϣ").toLocal8Bit();
		out_Judge.device()->seek(0);
		out_Judge << (quint16)(Send_Judge.size() - sizeof(quint16));
		receiveSocket->write(Send_Judge);
	}
}
void Server::ReadLinkman()
{
	int i = 0;			//��ʼ��Ϊ0������
						/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);


	db.open();
	QSqlQuery NoteNumber;		//ͳ�Ƹ���
	NoteNumber.prepare("select * from Friend_Table where Me=?");
	NoteNumber.addBindValue(Accountnumber);
	NoteNumber.exec();
	while (NoteNumber.next())
		i++;
	db.close();

	qDebug() << i;
	send(QString::number(i));
	db.open();
	QSqlQuery Linkman;
	Linkman.prepare("select Friend_Zhanghao,Fenzuhao from Friend_Table where Me=?");
	Linkman.addBindValue(Accountnumber);
	Linkman.exec();
	while (Linkman.next())
	{
		QSqlQuery inquireFriendInformation;
		inquireFriendInformation.prepare("select Sex,Nicheng,Gexingqianming,Display_Picture,PortNumber,LocalIp from YongHu_Xinxi where Zhanghao=?");
		inquireFriendInformation.addBindValue(Linkman.value(0).toString());
		inquireFriendInformation.exec();
		inquireFriendInformation.next();
		qDebug() << Linkman.value(1).toString().toInt();
		UserInformation people(Linkman.value(1).toString().toInt(),Linkman.value(0).toString(),inquireFriendInformation.value(0).toString(), inquireFriendInformation.value(1).toString(), inquireFriendInformation.value(2).toString(), inquireFriendInformation.value(3).toString(), inquireFriendInformation.value(4).toString(), inquireFriendInformation.value(5).toString());
		qDebug()<< people.fenzu_User << people.AccountNumber_User << people.Sex_User << people.NickName_User << people.PersonalizedSignature_User << people.Display_Picture_User << people.PortNumber_User << people.LocalIp_User;
		QByteArray data;			//��ʱҪ���͵�����
		QDataStream out(&data, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_5_6);						//�����������汾
		out << (quint16)0;
		out << people;
		out.device()->seek(0);
		out << (quint16)(data.size() - sizeof(quint16));
		receiveSocket->write(data);
	}
	db.close();

	bool JudgmentMessage = false;
	auto CheckUser = newInformation.begin();
	while (CheckUser != newInformation.end())
	{
		if (CheckUser->FriendAccountNumber == Accountnumber)
		{
			JudgmentMessage = true;
			send("���û���������Ϣ");
			send(CheckUser->UserAccountNumber);
		}
		CheckUser++;
	}
	if (!JudgmentMessage)
		send("ƨ��û��");
}
void Server::MasterLoginInterface()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0) 
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	auto Check = onlineUsers.begin();
	while (Check != onlineUsers.end())
	{
		if (Check->UserAccountNumber == Accountnumber)
		{
			QByteArray data;			//��ʱҪ���͵�����
			QDataStream out(&data, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_5_6);						//�����������汾
			out << (quint16)0;
			out << tr("�˺ű��˵�¼").toLocal8Bit();
			out.device()->seek(0);
			out << (quint16)(data.size() - sizeof(quint16));
			Check->UserServerSocket->write(data);
			onlineUsers.erase(Check);
			break;
		}
		Check++;
	}

	onlineUser OnePeople(Accountnumber, receiveSocket);
	onlineUsers.push_back(OnePeople);
	ui.label->setText(tr("��ǰ��������%0��").arg(onlineUsers.size()));

	db.open();
	QSqlQuery Update;
	Update.prepare("update Friend_Table set Panduan_dianji='��' where Me=?");
	Update.addBindValue(Accountnumber);
	Update.exec();

	db.open();
	QSqlQuery UpdateUserOlineline;
	UpdateUserOlineline.prepare("update YongHu_Xinxi set Panduan_zaixian='����' where Zhanghao=?");
	UpdateUserOlineline.exec();
	db.close();
	FindAccountnumberinformation(Accountnumber);
}
void Server::FindAccountnumberinformation(QString Accountnumber)
{
	QString PicturePath;				//ͼƬ·��
	QString NickName;					//�ǳ�
	QString PersonalizedSignature;		//����ǩ��
	db.open();
	QSqlQuery FindInformation;
	FindInformation.prepare("select Nicheng,Gexingqianming,Display_Picture from YongHu_Xinxi where Zhanghao=?");
	FindInformation.addBindValue(Accountnumber);
	FindInformation.exec();
	if (FindInformation.next())
	{
		NickName = FindInformation.value(0).toString();
		PersonalizedSignature = FindInformation.value(1).toString();
		PicturePath = FindInformation.value(2).toString();
	}
	db.close();
	send("����");

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			send(NickName);
		else if (i == 1)
			send(PersonalizedSignature);
		else if (i == 2)
			send(PicturePath);
	}


}
void Server::receive_password()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*��������*/
	blockSize = 0;
	QDataStream in(receiveSocket);
	in.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in >> ByteArray_Password;
	QString Password = QString::fromLocal8Bit(ByteArray_Password);
	blockSize = 0;

	/*�����ֻ��˺�*/
	blockSize = 0;
	QDataStream in_phone_number(receiveSocket);
	in_phone_number.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_phone_number >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in_phone_number >> ByteArray_phone_number;
	QString phone_number = QString::fromLocal8Bit(ByteArray_phone_number);

	if (forget_password(Accountnumber,Password,phone_number))
		send("�޸ĳɹ�");
	else
		send("�˺Ų����ڻ��˺��ֻ��Ŵ���");
}
bool Server::forget_password(QString Accountnumber, QString Password, QString phone_number)
{
	db.open();
	QSqlQuery seek_Accountnumber;
	seek_Accountnumber.prepare("select * from YongHu_Xinxi where Zhanghao=? and PhoneNumber=?");
	seek_Accountnumber.addBindValue(Accountnumber);
	seek_Accountnumber.addBindValue(phone_number);
	seek_Accountnumber.exec();
	if (seek_Accountnumber.next())
	{
		QSqlQuery modification_password;				//�޸�����
		modification_password.prepare("update YongHu_Xinxi set Mima=? where Zhanghao=? and PhoneNumber=?");
		modification_password.addBindValue(Password);
		modification_password.addBindValue(Accountnumber);
		modification_password.addBindValue(phone_number);
		modification_password.exec();
		db.close();
		return true;
	}
	else
	{
		db.close();
		return false;
	}
}
void Server::receive_register()
{
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	//�����������汾������Ҫ�ͷ���������ͬ
	if (blockSize == 0) //����Ǹտ�ʼ��������
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	//���û�еõ�ȫ�������ݣ��򷵻أ�������������
	in_Accountnumber >> ByteArray_Accountnumber;
	QString Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*��������*/
	blockSize = 0;
	QDataStream in(receiveSocket);
	in.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in >> ByteArray_Password;
	QString Password = QString::fromLocal8Bit(ByteArray_Password);
	blockSize = 0;

	/*�����ֻ��˺�*/
	blockSize = 0;
	QDataStream in_phone_number(receiveSocket);
	in_phone_number.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_phone_number >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in_phone_number >> ByteArray_phone_number;
	QString phone_number = QString::fromLocal8Bit(ByteArray_phone_number);

	if (register_dealwith(Accountnumber,Password,phone_number))
		send("ע��ɹ�");
	else
		send("ע��δ�ɹ�");
}
bool Server::register_dealwith(QString Accountnumber, QString Password, QString phone_number)
{
	db.open();
	QSqlQuery find_Accountnumber;
	find_Accountnumber.prepare("select * from YongHu_Xinxi where Zhanghao=?");
	find_Accountnumber.addBindValue(Accountnumber);
	find_Accountnumber.exec();
	if (find_Accountnumber.next())
		return false;
	else
	{
		QSqlQuery Insert_Accountnumber;
		Insert_Accountnumber.prepare("insert into YongHu_Xinxi(Zhanghao,Mima,PhoneNumber,Panduan_zaixian,Display_Picture,PortNumber) values(:Zhanghao,:Mima,:PhoneNumber,:Panduan_zaixian,:Display_Picture,:PortNumber)");
		Insert_Accountnumber.bindValue(":Zhanghao", Accountnumber);
		Insert_Accountnumber.bindValue(":Mima", Password);
		Insert_Accountnumber.bindValue(":PhoneNumber", phone_number);
		Insert_Accountnumber.bindValue(":Panduan_zaixian", "��");
		Insert_Accountnumber.bindValue(":Display_Picture", "Display_img/Moren/Ĭ��.jpg");
		Insert_Accountnumber.bindValue(":PortNumber", 0);
		Insert_Accountnumber.exec();
		db.close();
		return true;
	}
}
void Server::receive_entry()
{
	QString Accountnumber;
	/*�����˺�*/
	blockSize = 0;
	QDataStream in_Accountnumber(receiveSocket);
	in_Accountnumber.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0) 
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Accountnumber >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in_Accountnumber >> ByteArray_Accountnumber;
	Accountnumber = QString::fromLocal8Bit(ByteArray_Accountnumber);

	/*��������*/
	blockSize = 0;
	QDataStream in(receiveSocket);
	in.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in >> ByteArray_Password;
	QString Password = QString::fromLocal8Bit(ByteArray_Password);
	
	blockSize = 0;

	/*������IP*/
	blockSize = 0;
	QDataStream in_LocalIp(receiveSocket);
	in_LocalIp.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (receiveSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in_LocalIp >> blockSize;
	}
	if (receiveSocket->bytesAvailable() < blockSize) return;
	in_LocalIp >> ByteArray_LocalIp;
	QString LocalIp = QString::fromLocal8Bit(ByteArray_LocalIp);
	
	

	if (find_Accountnumber_Password(Accountnumber, Password, LocalIp))
	{
		qDebug() << "������ȷ";
		send("�˺�������ȷ");
		send(Accountnumber);
	}
	else
	{
		qDebug() << "���Ͳ���ȷ";
		send("�˺����벻��ȷ");
	}
}
bool Server::find_Accountnumber_Password(QString Accountnumber,QString Password,QString LocalIp)
{
	db.open();
	QSqlQuery seek_information;
	seek_information.prepare("select * from YongHu_Xinxi where Zhanghao=? and Mima=?");
	seek_information.addBindValue(Accountnumber);
	seek_information.addBindValue(Password);
	seek_information.exec();
	if (seek_information.next())
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
		int PortNumber = qrand() % 64510 + 1000;

		QSqlQuery Produce_Rand;
		Produce_Rand.exec("select PortNumber from YongHu_Xinxi");
		while (Produce_Rand.next()) 
		{
			if (PortNumber == Produce_Rand.value(0).toInt())
				do { PortNumber = qrand() % 64510 + 1000; } while (PortNumber != Produce_Rand.value(0).toInt());
		}


		QSqlQuery Find_PortNumber;
		Find_PortNumber.prepare("select PortNumber from YongHu_Xinxi where Zhanghao=?");
		Find_PortNumber.addBindValue(Accountnumber);
		Find_PortNumber.exec();
		Find_PortNumber.next();
		qDebug() << Find_PortNumber.value(0).toInt();
		if (Find_PortNumber.value(0) == 0)
		{
			QSqlQuery deposit_IP;
			deposit_IP.prepare("update YongHu_Xinxi set LocalIp=?,PortNumber=? where Zhanghao=?");
			deposit_IP.addBindValue(LocalIp);
			deposit_IP.addBindValue(PortNumber);
			deposit_IP.addBindValue(Accountnumber);
			deposit_IP.exec();
			db.close();
		}
		else
		{
			QSqlQuery IPIP;					//ÿһ�θ���IP
			IPIP.prepare("update YongHu_Xinxi set LocalIp=? where Zhanghao=?");
			IPIP.addBindValue(LocalIp);
			IPIP.addBindValue(Accountnumber);
			IPIP.exec();
			db.close();
		}
	return true;
	}
	else 
	{
		db.close();
		return false;
	}
	
}
void Server::JudgeDatabase()
{
	bool Judge = fileDB.exists("shujuku.db");
	if (Judge)
	{
		qDebug() << "���ݿ����";
	}
	else
	{

	}
}
void Server::createDatebase()
{

}
Server::~Server()
{

}
