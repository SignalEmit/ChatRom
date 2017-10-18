#include "dengluview.h"
#include<QDebug>
#include<QBitmap>
dengluview::dengluview(QWidget * parent) : QWidget(parent) {
	setupUi(this);
	this->setWindowTitle("聊一聊");
	Note_closeEvent = true;
	Note_number = 0;
	addPrompt = 0;
	FriendSendMessageNumber = 0;
	QPushButton *people = new QPushButton(xiaoxi);
	tcpSocket = new QTcpSocket(this);
	tcpNoteNumber = new QTcpSocket(this);
	closeTcpSocket = new QTcpSocket(this);

	apply_GDT = new QScrollArea(Shengqing_tab);
	apply_GDT->setGeometry(0, 0, 255, 372);
	apply_GDT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	TJ_apply = new QWidget();
	TJ_apply->setGeometry(0, 0, 236, 365);
	apply_GDT->setWidget(TJ_apply);

	xiaoxi_GDT = new QScrollArea(xiaoxi);
	xiaoxi_GDT->setGeometry(0, 0, 255, 372);
	xiaoxi_GDT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	TJ_xiaoxi = new QWidget();
	TJ_xiaoxi->setGeometry(0, 0, 236, 372);
	/*分组1的所有属性*/
	fenzu1_GDT = new QScrollArea(fenzu1);
	fenzu1_GDT->setGeometry(0, 0, 255, 293);
	fenzu1_GDT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	TJ_fenzu1 = new QWidget();
	TJ_fenzu1->setGeometry(0, 0, 236, 293);

	/*分组2的所有的属性*/
	fenzu2_GDT = new QScrollArea(fenzu2);
	fenzu2_GDT->setGeometry(0, 0, 255, 293);
	fenzu2_GDT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	TJ_fenzu2 = new QWidget();
	TJ_fenzu2->setGeometry(0, 0, 255, 293);

	/*分组3的所有的属性*/
	fenzu3_GDT = new QScrollArea(fenzu3);
	fenzu3_GDT->setGeometry(0, 0, 255, 293);
	fenzu3_GDT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	TJ_fenzu3 = new QWidget();
	TJ_fenzu3->setGeometry(0, 0, 255, 293);
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

	connect(closeTcpSocket, SIGNAL(connected()), this, SLOT(closesendMessage()));
	connect(closeTcpSocket, SIGNAL(readyRead()), this, SLOT(closereceiveMessage()));
	connect(closeTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	
	connect(tcpNoteNumber, SIGNAL(connected()), this, SLOT(sendStatisticsNumber()));
	connect(tcpNoteNumber, SIGNAL(readyRead()), this, SLOT(receiveNoteNumber()));
	connect(tcpNoteNumber, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	
	AddSeccessTcpSocket = new QTcpSocket(this);
	connect(AddSeccessTcpSocket, SIGNAL(connected()), this, SLOT(sendAddSeccess()));
	connect(AddSeccessTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}
void dengluview::sendAddSeccess()
{
	if (Send_RunDateBase_or_Otherclient)
	{
		QByteArray ByteArray_judge; //用于暂存我们要发送的数据
		QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
		out_judge << (quint16)0;
		out_judge << tr("确认添加").toLocal8Bit();
		qDebug() << "确认添加";
		out_judge.device()->seek(0);
		out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_judge);

		/*发送自己的账号*/
		QByteArray ByteArray_AccountNumber; //用于暂存我们要发送的数据
		QDataStream out_AccountNumber(&ByteArray_AccountNumber, QIODevice::WriteOnly);
		out_AccountNumber << (quint16)0;
		out_AccountNumber << Accountnumber.toLocal8Bit();
		out_AccountNumber.device()->seek(0);
		out_AccountNumber << (quint16)(ByteArray_AccountNumber.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_AccountNumber);

		/*发送朋友的账号*/
		QByteArray ByteArray_FriendAccountNumber; //用于暂存我们要发送的数据
		QDataStream out_FriendAccountNumber(&ByteArray_FriendAccountNumber, QIODevice::WriteOnly);
		out_FriendAccountNumber << (quint16)0;
		out_FriendAccountNumber << Friend_AccountnumberFirst.toLocal8Bit();
		out_FriendAccountNumber.device()->seek(0);
		out_FriendAccountNumber << (quint16)(ByteArray_FriendAccountNumber.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_FriendAccountNumber);

		/*发送加入的分组*/
		QByteArray ByteArray_FriendFenzuNumber; //用于暂存我们要发送的数据
		QDataStream out_FriendFenzuNumber(&ByteArray_FriendFenzuNumber, QIODevice::WriteOnly);
		out_FriendFenzuNumber << (quint16)0;
		out_FriendFenzuNumber << QString::number(Fenzu_First).toLocal8Bit();
		out_FriendFenzuNumber.device()->seek(0);
		out_FriendFenzuNumber << (quint16)(ByteArray_FriendFenzuNumber.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_FriendFenzuNumber);
		AddSeccessTcpSocket->disconnectFromHost();
	}
	else
	{
		QByteArray ByteArray_judge; //用于暂存我们要发送的数据
		QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
		out_judge << (quint16)0;
		out_judge << tr("好友存入数据库").toLocal8Bit();
		qDebug() << "好友存入数据库";
		out_judge.device()->seek(0);
		out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_judge);

		/*发送自己的账号*/
		QByteArray ByteArray_AccountNumber; //用于暂存我们要发送的数据
		QDataStream out_AccountNumber(&ByteArray_AccountNumber, QIODevice::WriteOnly);
		out_AccountNumber << (quint16)0;
		out_AccountNumber << Accountnumber.toLocal8Bit();
		out_AccountNumber.device()->seek(0);
		out_AccountNumber << (quint16)(ByteArray_AccountNumber.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_AccountNumber);

		/*发送朋友的账号*/
		QByteArray ByteArray_FriendAccountNumber; //用于暂存我们要发送的数据
		QDataStream out_FriendAccountNumber(&ByteArray_FriendAccountNumber, QIODevice::WriteOnly);
		out_FriendAccountNumber << (quint16)0;
		out_FriendAccountNumber << Friend_AccountNumber.toLocal8Bit();
		out_FriendAccountNumber.device()->seek(0);
		out_FriendAccountNumber << (quint16)(ByteArray_FriendAccountNumber.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_FriendAccountNumber);

		/*发送加入的分组*/
		QByteArray ByteArray_FriendFenzuNumber; //用于暂存我们要发送的数据
		QDataStream out_FriendFenzuNumber(&ByteArray_FriendFenzuNumber, QIODevice::WriteOnly);
		out_FriendFenzuNumber << (quint16)0;
		out_FriendFenzuNumber << QString::number(Fenzu_Second).toLocal8Bit();
		out_FriendFenzuNumber.device()->seek(0);
		out_FriendFenzuNumber << (quint16)(ByteArray_FriendFenzuNumber.size() - sizeof(quint16));
		AddSeccessTcpSocket->write(ByteArray_FriendFenzuNumber);
		AddSeccessTcpSocket->disconnectFromHost();
	}
}
void dengluview::closesendMessage()
{
	QByteArray ByteArray_judge; //用于暂存我们要发送的数据
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	out_judge << (quint16)0;
	out_judge << tr("下线").toLocal8Bit();
	qDebug() << "下线";
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	closeTcpSocket->write(ByteArray_judge);

	/*发送账号*/
	QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
	QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
	out_account_number << (quint16)0;
	out_account_number << Accountnumber.toLocal8Bit();
	qDebug() << Accountnumber;
	out_account_number.device()->seek(0);
	out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
	closeTcpSocket->write(ByteArray_account_number);
}
void dengluview::closereceiveMessage()
{
	blockSize = 0; //初始化其为0
	QDataStream in(closeTcpSocket);
	in.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (closeTcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (closeTcpSocket->bytesAvailable() < blockSize) return;
	in >> message;
	qDebug() << QString::fromLocal8Bit(message);
	Judge = QString::fromLocal8Bit(message);

	if (Judge == "下线")
	{
		Note_closeEvent = false;
		emit CloseSignal();
	}
}
void dengluview::closeNewConnect()
{
	closeTcpSocket->abort();
	closeTcpSocket->connectToHost("10.211.26.93", 666);
}
void dengluview::sendStatisticsNumber()
{
	/*发送判断*/
	QByteArray ByteArray_judge; //用于暂存我们要发送的数据
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	out_judge << (quint16)0;
	out_judge << tr("读取联系人").toLocal8Bit();
	qDebug() << "读取联系人";
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	tcpNoteNumber->write(ByteArray_judge);

	
	QByteArray ByteArray_AccountNumber; //用于暂存我们要发送的数据
	QDataStream out_AccountNumber(&ByteArray_AccountNumber, QIODevice::WriteOnly);
	out_AccountNumber << (quint16)0;
	out_AccountNumber << Accountnumber.toLocal8Bit();
	out_AccountNumber.device()->seek(0);
	out_AccountNumber << (quint16)(ByteArray_AccountNumber.size() - sizeof(quint16));
	tcpNoteNumber->write(ByteArray_AccountNumber);
	
}
void dengluview::receiveNoteNumber()
{
	int NoteNUmber;				//记录个数
	blockSize = 0;
	QDataStream in(tcpNoteNumber);
	in.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (tcpNoteNumber->bytesAvailable() < (int)sizeof(quint16)) return;
		in >> blockSize;
	}
	if (tcpNoteNumber->bytesAvailable() < blockSize) return;
	in >> message;
	qDebug() << QString::fromLocal8Bit(message).toInt();
	NoteNUmber = QString::fromLocal8Bit(message).toInt();
	//tcpNoteNumber->disconnectFromHost();

	UserInformation people(1, "asd", "asd", "asd", "asd", "asd", "asd", "asd");
	for (int i = 0; i < NoteNUmber; i++)
	{
		blockSize = 0; //初始化其为0
		QDataStream in(tcpNoteNumber);
		in.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0) 
		{
			if (tcpNoteNumber->bytesAvailable() < (int)sizeof(quint16)) return;
			in >> blockSize;
		}
		if (tcpNoteNumber->bytesAvailable() < blockSize) return;
		in >> people;
		Users.push_back(people);
		qDebug() << people.fenzu_User << people.AccountNumber_User << people.Sex_User << people.NickName_User << people.PersonalizedSignature_User << people.Display_Picture_User << people.PortNumber_User << people.LocalIp_User;
	}
	
	QString Judge;
	blockSize = 0; //初始化其为0
	QDataStream in_Judge(tcpNoteNumber);
	in_Judge.setVersion(QDataStream::Qt_5_6);
	if (blockSize == 0)
	{
		if (tcpNoteNumber->bytesAvailable() < (int)sizeof(quint16)) return;
		in_Judge >> blockSize;
	}
	if (tcpNoteNumber->bytesAvailable() < blockSize) return;
	in_Judge >> message;
	qDebug() << QString::fromLocal8Bit(message);
	Judge = QString::fromLocal8Bit(message);
	
	if (Judge == "有用户发来的消息")
	{
		QString Friend;
		blockSize = 0; //初始化其为0
		QDataStream in(tcpNoteNumber);
		in.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpNoteNumber->bytesAvailable() < (int)sizeof(quint16)) return;
			in >> blockSize;
		}
		if (tcpNoteNumber->bytesAvailable() < blockSize) return;
		in >> message;
		qDebug() << QString::fromLocal8Bit(message);
		Friend = QString::fromLocal8Bit(message);


		auto checkUsers = Users.begin();
		while (checkUsers!= Users.end())
		{
			if (Friend == checkUsers->AccountNumber_User)
			{
				addNewFriend_xiaoxi_GroupingMember(checkUsers);
			}
			checkUsers++;
		}
	}
	else
	{
		/*用户无消息发来*/
		qDebug() << "用户无消息发来";
	}

	InitializeGroupingFrist();
}
void dengluview::sendMessage()
{
	if (onlineline_yse_or_no)
	{
		QByteArray ByteArray_judge; //用于暂存我们要发送的数据
		QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
		out_judge << (quint16)0;
		out_judge << tr("登录主界面").toLocal8Bit();
		qDebug() << "登录主界面";
		out_judge.device()->seek(0);
		out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_judge);

		/*发送账号*/
		QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
		QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
		out_account_number << (quint16)0;
		out_account_number << Accountnumber.toLocal8Bit();
		qDebug() << Accountnumber;
		out_account_number.device()->seek(0);
		out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
		tcpSocket->write(ByteArray_account_number);
	}
}
void dengluview::receiveMessage()
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
	Judge = QString::fromLocal8Bit(message);

	if (Judge=="上线")
	{
		for (int i = 0; i < 3; i++)
		{
			blockSize = 0;
			QDataStream in(tcpSocket);
			in.setVersion(QDataStream::Qt_5_6);
			if (blockSize == 0)
			{
				if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
				in >> blockSize;
			}
			if (tcpSocket->bytesAvailable() < blockSize) return;
			in >> message;
			if (i == 0)
			{
				qDebug() << QString::fromLocal8Bit(message);
				NickName = QString::fromLocal8Bit(message);
			}
			else if (i == 1)
			{
				qDebug() << QString::fromLocal8Bit(message);
				PersonalizedSignature = QString::fromLocal8Bit(message);
			}
			else if (i == 2)
			{
				qDebug() << QString::fromLocal8Bit(message);
				PicturePath = QString::fromLocal8Bit(message);
				connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater()));
			}
		}
		dengluview_nicheng->setText(NickName);
		dengluview_qianming->setText(PersonalizedSignature);
		readPicture(PicturePath);
		newConnect_NoteNumber();
	}
	else if (Judge == "申请添加")
	{
		UserInformation people(1, "asd", "asd", "asd", "asd", "asd", "asd", "asd");
		blockSize = 0; //初始化其为0
		QDataStream in(tcpSocket);
		in.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		in >> people;
		momoda.push_back(people);
		qDebug() << "我接收到了";
		qDebug() << people.fenzu_User << people.AccountNumber_User << people.Sex_User << people.NickName_User << people.PersonalizedSignature_User << people.Display_Picture_User << people.PortNumber_User << people.LocalIp_User;
		/*显示头像*/
		label_addDisplay = new QLabel(TJ_apply);
		label_addDisplay->setGeometry(5, 60*addPrompt+5, 60, 60);
		QPixmap pixmap(people.Display_Picture_User);
		label_addDisplay->setPixmap(pixmap.scaled(60, 60, Qt::IgnoreAspectRatio));
		label_addDisplay->show();

		label_NickName = new QLabel(TJ_apply);
		label_NickName->setGeometry(75, 60 * addPrompt +20 , 61, 16);
		label_NickName->setText(people.NickName_User);
		label_NickName->show();

		label_PersonalizedSignature = new QLabel(TJ_apply);
		label_PersonalizedSignature->setGeometry(75, 60 * addPrompt + 50, 101, 16);
		label_PersonalizedSignature->setText(people.PersonalizedSignature_User);
		label_PersonalizedSignature->show();

		affirmAdd[addPrompt] = new QPushButton(TJ_apply);
		affirmAdd[addPrompt]->setGeometry(170, 60 * addPrompt + 30, 61, 23);
		affirmAdd[addPrompt]->setText("确认添加");
		affirmAdd[addPrompt]->show();
		connect(affirmAdd[addPrompt], SIGNAL(clicked()), this, SLOT(dealWithAdd()));

		transverseLine_Up = new QFrame(TJ_apply);
		transverseLine_Up->setGeometry(2, 60 * addPrompt + 4, 230, 3);
		transverseLine_Up->setFrameShape(QFrame::HLine);
		transverseLine_Up->setFrameShadow(QFrame::Sunken);
		transverseLine_Up->show();

		transverseLine_Down = new QFrame(TJ_apply);
		transverseLine_Down->setGeometry(2, 60 * (addPrompt+1) + 6, 230, 3);
		transverseLine_Down->setFrameShape(QFrame::HLine);
		transverseLine_Down->setFrameShadow(QFrame::Sunken);
		transverseLine_Down->show();

		uprightLine_Left = new QFrame(TJ_apply);
		uprightLine_Left->setGeometry(2, 60 * addPrompt  + 4, 3, 61);
		uprightLine_Left->setFrameShape(QFrame::VLine);
		uprightLine_Left->setFrameShadow(QFrame::Sunken);
		uprightLine_Left->show();

		uprightLine_Right = new QFrame(TJ_apply);
		uprightLine_Right->setGeometry(232,60* addPrompt+4, 3, 61);
		uprightLine_Right->setFrameShape(QFrame::VLine);
		uprightLine_Right->setFrameShadow(QFrame::Sunken);
		uprightLine_Right->show();
		addPrompt++;
	}
	else if (Judge == "添加成功")
	{
		UserInformation Friend(1, "asd", "asd", "asd", "asd", "asd", "asd", "asd");
		blockSize = 0; //初始化其为0
		QDataStream in(tcpSocket);
		in.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		in >> Friend;
		Friend_AccountNumber = Friend.AccountNumber_User;

		QMessageBox box;
		box.setWindowTitle("儿子选择分组");
		box.setIcon(QMessageBox::Information);
		box.setText(tr("儿呀！爸爸添加的好友：%1  好友同意了,替爸爸选个分组吧！").arg(Friend.AccountNumber_User));
		QPushButton *a = box.addButton("分组1", QMessageBox::RejectRole);
		QPushButton *b = box.addButton("分组2", QMessageBox::RejectRole);
		QPushButton *c = box.addButton("分组3", QMessageBox::RejectRole);
		box.exec();
		if (box.clickedButton() == a)
			Fenzu_Second = 1;
		else if (box.clickedButton() == b)
			Fenzu_Second = 2;
		else
			Fenzu_Second = 3;
		Friend.fenzu_User = Fenzu_Second;
		qDebug() << Friend.fenzu_User;
		addNewMan(Friend);

		Send_RunDateBase_or_Otherclient = false;
		AddSeccessConnect();
	}
	else if (Judge == "在线发来消息")
	{
		QString Friend;
		blockSize = 0; //初始化其为0
		QDataStream in_Friend(tcpSocket);
		in_Friend.setVersion(QDataStream::Qt_5_6);
		if (blockSize == 0)
		{
			if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
			in_Friend >> blockSize;
		}
		if (tcpSocket->bytesAvailable() < blockSize) return;
		in_Friend >> message;
		qDebug() << QString::fromLocal8Bit(message);
		Friend = QString::fromLocal8Bit(message);

		int noteMessage = 0;				//记录重新闪烁
		bool chonngfu = false;
		auto WeatherChongfu = FriendName.begin();
		while (WeatherChongfu != FriendName.end())
		{
			if (Friend == *WeatherChongfu)
			{
				chonngfu = true;
				break;
			}
			WeatherChongfu++;
			noteMessage++;
		}

		auto Check_Friend = Users.begin();
		while (Check_Friend != Users.end())
		{
			if (Check_Friend->AccountNumber_User == Friend)
			{
				if (!chonngfu)
				{
					addNewFriend_xiaoxi_GroupingMember(Check_Friend);
					break;
				}
				else
				{
					timestar[noteMessage]->start();
					timeend[noteMessage]->start();
				}
				}
			Check_Friend++;
		}
	}
	else if (Judge == "账号被人登录")
	{
		QMessageBox box;
		box.setWindowTitle("警告警告！！！");
		box.setIcon(QMessageBox::Warning);
		box.setText("您的账号已在异地登录请退出");
		box.setStandardButtons(QMessageBox::No);
		switch (box.exec())
		{
		case QMessageBox::No:
		{
			exit(0);
			break;
		}
		}
	}
}
void dengluview::AddSeccessConnect()
{
	AddSeccessTcpSocket->abort(); //取消已有的连接
	AddSeccessTcpSocket->connectToHost("10.211.26.93", 666);
}
void dengluview::dealWithAdd()
{
	QMessageBox box;
	box.setWindowTitle("儿子选择分组");
	box.setIcon(QMessageBox::Information);
	box.setText("儿呀！替爸爸选个分组吧！");
	QPushButton *a = box.addButton("分组1", QMessageBox::RejectRole);
	QPushButton *b = box.addButton("分组2", QMessageBox::RejectRole);
	QPushButton *c = box.addButton("分组3", QMessageBox::RejectRole);
	box.exec();
	if (box.clickedButton() == a)
		Fenzu_First = 1;
	else if (box.clickedButton() == b)
		Fenzu_First = 2;
	else
		Fenzu_First = 3;
	qDebug() << Fenzu_First;
	auto Dispose = momoda.begin();
	for(int i=0;i<addPrompt;i++)
		if (sender() == affirmAdd[i])
		{
			affirmAdd[i]->setEnabled(false);
			Dispose->fenzu_User = Fenzu_First;
			Friend_AccountnumberFirst = Dispose->AccountNumber_User;
			addNewMan(*Dispose);
			momoda.erase(Dispose);
			qDebug() << momoda.size();
			break;
		}
	Send_RunDateBase_or_Otherclient = true;
	AddSeccessConnect();
}
void dengluview::readPicture(QString s)
{
	QPixmap pixmap(s);
	label_Touxiang->setPixmap(pixmap.scaled(75, 75, Qt::IgnoreAspectRatio));
}
void dengluview::showEvent(QShowEvent *e)
{
	Frist_GroupingShow = new liaotianjiemian[50];
	Second_GroupingShow = new liaotianjiemian[50];
	Third_GroupingShow = new liaotianjiemian[50];
	xiaoxi_GroupingShow = new liaotianjiemian[50];
	onlineline_yse_or_no = true;
	/*读取端口号移除文件*/
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QFile jilu("jilu.txt");
	jilu.open(QIODevice::ReadOnly);
	QTextStream jieshou(&jilu);
	jieshou.setCodec(codec);
	while (!jieshou.atEnd())
		Accountnumber = jieshou.readAll();
	jilu.close();
	QFile::remove("jilu.txt");

	//获取计算机名称
	QString localHostName = QHostInfo::localHostName();
	qDebug() << "计算机名：" << localHostName;
	QHostInfo info = QHostInfo::fromName(localHostName);
	//遍历地址，只获取IPV4 地址
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			LocalIp = address.toString();
			qDebug() << "ipV4 地址：" << address.toString();
		}
	}
	newConnect();
}
void dengluview::TurnIntoChatInterface()
{
	int s = 0;
	auto MemberIndicator_First = Users_First.begin();
	for (int i = 0; i < Frist_GroupingMemberIndexSumtotal; i++)
		if (sender() == fenzu1_Friend[i])
		{
			while (MemberIndicator_First != Users_First.end())
			{
				if (s == i)
				{
					QFile::remove("jilu.txt");
					QFile new_txt("jilu.txt");
					new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
					QByteArray str = (Accountnumber + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_First->AccountNumber_User+"\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_First->NickName_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_First->PersonalizedSignature_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_First->Display_Picture_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_First->LocalIp_User+"\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_First->PortNumber_User+"\n").toUtf8();
					new_txt.write(str);
					new_txt.close();
					Frist_GroupingShow[i].show();
				}
				MemberIndicator_First++;		//检索到这个人
				s++;
			}
		}

	s = 0;
	auto MemberIndicator_Second = Users_Second.begin();
	for (int i = 0; i < Second_GroupingMemberIndexSumtotal; i++)
		if (sender() == fenzu2_Friend[i])
		{
			while (MemberIndicator_Second != Users_Second.end())
			{
				if (s == i)
				{
					QFile::remove("jilu.txt");
					QFile new_txt("jilu.txt");
					new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
					QByteArray str = (Accountnumber + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Second->AccountNumber_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Second->NickName_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Second->PersonalizedSignature_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Second->Display_Picture_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Second->LocalIp_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Second->PortNumber_User + "\n").toUtf8();
					new_txt.write(str);
					new_txt.close();
					Second_GroupingShow[i].show();
					}
					MemberIndicator_Second++;		//检索到这个人
					s++;
				}
			}

	s = 0;
	auto MemberIndicator_Third = Users_Third.begin();
	for (int i = 0; i < Third_GroupingMemberIndexSumtotal; i++)
		if (sender() == fenzu3_Friend[i])
		{
			while (MemberIndicator_Third != Users_Third.end())
			{
				if (s == i)
				{
					QFile::remove("jilu.txt");
					QFile new_txt("jilu.txt");
					new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
					QByteArray str = (Accountnumber + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Third->AccountNumber_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Third->NickName_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Third->PersonalizedSignature_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Third->Display_Picture_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Third->LocalIp_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_Third->PortNumber_User + "\n").toUtf8();
					new_txt.write(str);
					new_txt.close();
					Third_GroupingShow[i].show();
				}
				MemberIndicator_Third++;		//检索到这个人
				s++;
		}
	}

	//聊天接到提示消息要打开的窗口
	s = 0;
	auto MemberIndicator_xiaoxi = Users_xiaoxi.begin();
	for (int i = 0; i < Users_xiaoxi.size(); i++)
		if (sender() == FriendSendMessage[i])
		{
			while (MemberIndicator_xiaoxi != Users_xiaoxi.end())
			{
				if (s == i)
				{
					timestar[i]->stop();
					timeend[i]->stop();
					FriendSendMessage[i]->setStyleSheet("background-color: rgb(240, 240, 240);" "text-align:left;");
					QFile::remove("jilu.txt");
					QFile new_txt("jilu.txt");
					new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
					QByteArray str = (Accountnumber + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_xiaoxi->AccountNumber_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_xiaoxi->NickName_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_xiaoxi->PersonalizedSignature_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_xiaoxi->Display_Picture_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_xiaoxi->LocalIp_User + "\n").toUtf8();
					new_txt.write(str);
					str = (MemberIndicator_xiaoxi->PortNumber_User + "\n").toUtf8();
					new_txt.write(str);
					new_txt.close();
					xiaoxi_GroupingShow[i].show();
				}
					MemberIndicator_xiaoxi++;		//检索到这个人
					s++;
			}
	}
}
void dengluview::newConnect()
{
	tcpSocket->abort(); //取消已有的连接
	tcpSocket->connectToHost("10.211.26.93", 666);
	//连接到主机，这里从界面获取主机地址和端口号
}
void dengluview::newConnect_NoteNumber()
{
	tcpNoteNumber->abort(); //取消已有的连接
	tcpNoteNumber->connectToHost("10.211.26.93", 666);
	//连接到主机，这里从界面获取主机地址和端口号
}
void dengluview::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("警告"), tr("请检查您的网络"), QMessageBox::Yes);
}
void dengluview::addNewFriend_xiaoxi_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator)
{
	FriendName.push_back(MemberIndicator->AccountNumber_User);
	Users_xiaoxi.push_back(*MemberIndicator);
	FriendSendMessage[FriendSendMessageNumber] = new QPushButton(TJ_xiaoxi);
	QIcon icon;
	QPixmap pixmap(MemberIndicator->Display_Picture_User);
	pixmap.scaled(60, 60, Qt::IgnoreAspectRatio);
	icon.addPixmap(pixmap);
	FriendSendMessage[FriendSendMessageNumber]->setIcon(icon);
	FriendSendMessage[FriendSendMessageNumber]->setIconSize(QSize(60, 60));
	if (50 * (FriendSendMessageNumber + 1) >= 372)
		TJ_xiaoxi->setGeometry(0, 0, 236, 50 * (FriendSendMessageNumber + 1));
	else
		TJ_xiaoxi->setGeometry(0, 0, 236, 372);
	xiaoxi_GDT->setWidget(TJ_xiaoxi);
	QString str = MemberIndicator->NickName_User + "\n\n" + MemberIndicator->PersonalizedSignature_User;
	FriendSendMessage[FriendSendMessageNumber]->setText(str);
	FriendSendMessage[FriendSendMessageNumber]->setStyleSheet(QLatin1String("text-align:left"));
	FriendSendMessage[FriendSendMessageNumber]->setGeometry(0, 50 * FriendSendMessageNumber, 235, 50);
	FriendSendMessage[FriendSendMessageNumber]->show();
	connect(FriendSendMessage[FriendSendMessageNumber], SIGNAL(clicked()), this, SLOT(TurnIntoChatInterface()));
	timestar[FriendSendMessageNumber] = new QTimer(this);
	timeend[FriendSendMessageNumber] = new QTimer(this);
	connect(timestar[FriendSendMessageNumber], SIGNAL(timeout()), this, SLOT(TimeStar()));
	connect(timeend[FriendSendMessageNumber], SIGNAL(timeout()), this, SLOT(TimeEnd()));
	timestar[FriendSendMessageNumber]->start(1000);
	timeend[FriendSendMessageNumber]->start(2001);
	FriendSendMessageNumber++;
}
void dengluview::addNewFriend_Third_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator)
{
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal] = new QPushButton(TJ_fenzu3);
	QIcon icon;
	QPixmap pixmap(MemberIndicator->Display_Picture_User);
	pixmap.scaled(60, 60, Qt::IgnoreAspectRatio);
	icon.addPixmap(pixmap);
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal]->setIcon(icon);
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal]->setIconSize(QSize(60, 60));
	if (50 * (Third_GroupingMemberIndexSumtotal + 1) >= 286)
		TJ_fenzu3->setGeometry(0, 0, 236, 50 * (Third_GroupingMemberIndexSumtotal + 1));
	else
		TJ_fenzu3->setGeometry(0, 0, 236, 286);
	fenzu3_GDT->setWidget(TJ_fenzu3);
	QString str = MemberIndicator->NickName_User + "\n\n" + MemberIndicator->PersonalizedSignature_User;
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal]->setText(str);
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal]->setGeometry(0, 50 * Third_GroupingMemberIndexSumtotal, 235, 50);
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal]->setStyleSheet("text-align:left");
	fenzu3_Friend[Third_GroupingMemberIndexSumtotal]->show();
	connect(fenzu3_Friend[Third_GroupingMemberIndexSumtotal], SIGNAL(clicked()), this, SLOT(TurnIntoChatInterface()));
	Third_GroupingMemberIndexSumtotal++;
}
void dengluview::addNewFriend_Frist_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator)
{
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal] = new QPushButton(TJ_fenzu1);
	QIcon icon;
	QPixmap pixmap(MemberIndicator->Display_Picture_User);
	pixmap.scaled(60, 60, Qt::IgnoreAspectRatio);
	icon.addPixmap(pixmap);
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal]->setIcon(icon);
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal]->setIconSize(QSize(60, 60));
	if (50 * (Frist_GroupingMemberIndexSumtotal + 1) >= 286)
		TJ_fenzu1->setGeometry(0, 0, 236, 50 * (Frist_GroupingMemberIndexSumtotal + 1));
	else
		TJ_fenzu1->setGeometry(0, 0, 236, 286);
	fenzu1_GDT->setWidget(TJ_fenzu1);
	QString str = MemberIndicator->NickName_User + "\n\n" + MemberIndicator->PersonalizedSignature_User;
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal]->setText(str);
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal]->setGeometry(0, 50 * Frist_GroupingMemberIndexSumtotal, 235, 50);
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal]->setStyleSheet("text-align:left");
	fenzu1_Friend[Frist_GroupingMemberIndexSumtotal]->show();
	connect(fenzu1_Friend[Frist_GroupingMemberIndexSumtotal], SIGNAL(clicked()), this, SLOT(TurnIntoChatInterface()));
	Frist_GroupingMemberIndexSumtotal++;
}
void dengluview::addNewFriend_Second_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator)
{
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal] = new QPushButton(TJ_fenzu2);
	QIcon icon;
	QPixmap pixmap(MemberIndicator->Display_Picture_User);
	pixmap.scaled(60, 60, Qt::IgnoreAspectRatio);
	icon.addPixmap(pixmap);
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal]->setIcon(icon);
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal]->setIconSize(QSize(60, 60));
	if (50 * (Second_GroupingMemberIndexSumtotal + 1) >= 286)
		TJ_fenzu2->setGeometry(0, 0, 236, 50 * (Second_GroupingMemberIndexSumtotal + 1));
	else
		TJ_fenzu2->setGeometry(0, 0, 236, 286);
	fenzu2_GDT->setWidget(TJ_fenzu2);
	QString str = MemberIndicator->NickName_User + "\n\n" + MemberIndicator->PersonalizedSignature_User;
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal]->setText(str);
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal]->setGeometry(0, 50 * Second_GroupingMemberIndexSumtotal, 235, 50);
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal]->setStyleSheet("text-align:left");
	fenzu2_Friend[Second_GroupingMemberIndexSumtotal]->show();
	connect(fenzu2_Friend[Second_GroupingMemberIndexSumtotal], SIGNAL(clicked()), this, SLOT(TurnIntoChatInterface()));
	Second_GroupingMemberIndexSumtotal++;
}
void dengluview::InitializeGroupingFrist()
{
	Frist_GroupingMemberIndexSumtotal = 0;
	Second_GroupingMemberIndexSumtotal = 0;
	Third_GroupingMemberIndexSumtotal = 0;
	auto MemberIndicator = Users.begin();
	while (MemberIndicator != Users.end())
	{
		if (MemberIndicator->fenzu_User==1)
		{
			Users_First.push_back(*MemberIndicator);
			addNewFriend_Frist_GroupingMember(MemberIndicator);
			MemberIndicator++;
		}
		else if (MemberIndicator->fenzu_User == 2)
		{
			Users_Second.push_back(*MemberIndicator);
			addNewFriend_Second_GroupingMember(MemberIndicator);
			MemberIndicator++;
		}
		else if (MemberIndicator->fenzu_User == 3)
		{
			Users_Third.push_back(*MemberIndicator);
			addNewFriend_Third_GroupingMember(MemberIndicator);
			MemberIndicator++;
		}
	}
}
void dengluview::on_touxiangbt_clicked()
{
	QFile::remove("jilu.txt");
	QFile new_txt("jilu.txt");
	new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
	QByteArray str = (NickName + "\n").toUtf8();
	new_txt.write(str);
	str = (PersonalizedSignature + "\n").toUtf8();
	new_txt.write(str);
	str = (PicturePath + "\n").toUtf8();
	new_txt.write(str);
	str = (Accountnumber + "\n").toUtf8();
	new_txt.write(str);
	new_txt.close();
	w.show();
	connect(&w, SIGNAL(xiugaixinxixinhao(QString, QString, QString, QString)), this, SLOT(receiveUserInformationSignal(QString, QString, QString, QString)));
}
void dengluview::receiveUserInformationSignal(QString _Sex, QString _NickName, QString _PersonalizedSignature, QString _DisplayPicture)
{
	NickName = _NickName;
	PersonalizedSignature = _PersonalizedSignature;
	PicturePath = _DisplayPicture;
	dengluview_nicheng->setText(NickName);
	dengluview_qianming->setText(PersonalizedSignature);
	readPicture(PicturePath);
}
void dengluview::on_tianjia_clicked()
{
	QFile::remove("jilu.txt");
	QFile new_txt("jilu.txt");
	new_txt.open(QIODevice::ReadWrite | QIODevice::Text);
	new_txt.write(Accountnumber.toUtf8());
	new_txt.close();
	addNewFriend.show();
}
void dengluview::TimeStar()
{
	for (int i = 0; i < FriendSendMessageNumber; i++)
	{
		if (sender() == timestar[i])
		{
			FriendSendMessage[i]->setStyleSheet("background-color: rgb(85, 255, 255);""text-align:left;");
			break;
		}
	}
}
void dengluview::TimeEnd()
{
	for (int i = 0; i < FriendSendMessageNumber; i++)
	{
		if (sender() == timeend[i])
		{
			FriendSendMessage[i]->setStyleSheet("background-color: rgb(255, 255, 255);""text-align:left;");
			break;
		}
	}
}
void dengluview::addNewMan(UserInformation people)
{
	if (people.fenzu_User == 1)
	{
		Users.push_back(people);
		Users_First.push_back(people);
		auto addFriend = Users_First.end() - 1;
		addNewFriend_Frist_GroupingMember(addFriend);
	}
	else if (people.fenzu_User == 2)
	{
		Users.push_back(people);
		Users_Second.push_back(people);
		auto addFriend = Users_Second.end() - 1;
		addNewFriend_Second_GroupingMember(addFriend);
	}
	else if (people.fenzu_User == 3)
	{
		Users.push_back(people);
		Users_Third.push_back(people);
		auto addFriend = Users_Third.end() - 1;
		addNewFriend_Third_GroupingMember(addFriend);
	}
}
void dengluview::closeEvent(QCloseEvent *e)
{
	if (Note_closeEvent)
	{
		connect(this, SIGNAL(CloseSignal()), this, SLOT(close()));
		e->ignore();
		onlineline_yse_or_no = false;
		closeNewConnect();
	}
	else
	{
		e->accept();
		exit(0);
	}
}
dengluview::~dengluview() {
	//delete []Frist_GroupingShow;
	//delete []Second_GroupingShow;
	//delete []Third_GroupingShow;
}
