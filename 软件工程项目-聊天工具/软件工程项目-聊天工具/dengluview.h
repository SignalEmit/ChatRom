#pragma once
#include <QWidget>
#include<QLineEdit>
#include<QPushButton>
#include<QScrollArea>
#include<QtNetWork>
#include<QList>
#include<QFrame>
#include<QTimer>
#include<QMessageBox>
#include "ui_dengluview.h"
#include"liaotianjiemian.h"
#include"xiugaixingxi.h"
#include"tianjiafriend.h"
# pragma execution_character_set("utf-8")
class dengluview : public QWidget,public Ui_dengluview {
	Q_OBJECT
		signals : void CloseSignal();
public:
	dengluview(QWidget * parent = Q_NULLPTR);
	~dengluview();
private slots:
	void TimeStar();		//闪烁开始
	void TimeEnd();			//闪烁结束
	/*关闭按钮事件*/
	void closesendMessage();
	void closereceiveMessage();
	void closeNewConnect(); //连接服务器
	/*接收好友的事件*/
	void receiveUserInformationSignal(QString,QString, QString, QString);	//接收用户信息修改信号
	void sendStatisticsNumber();		//统计个数
	void receiveNoteNumber();			//个数赋值
	/*接收个人的信息*/
	void sendMessage();
	void receiveMessage();
	void newConnect(); //连接服务器
	void displayError(QAbstractSocket::SocketError);
private:
	/*添加好友列表*/
	/*单向添加后待发送的消息*/
	int Fenzu_Second;									//接收回来选择的分组号
	int Fenzu_First;									//带发送的分组号
	QString Friend_AccountnumberFirst;					//待发送的朋友账号

	QTimer *timestar[50];
	QTimer *timeend[50];
	bool Note_closeEvent;
	bool onlineline_yse_or_no;					//用于判断是上线发送接收还是下线发送接收
	int Second_GroupingMemberIndexSumtotal;		//记录第二个分组的成员个数
	int Third_GroupingMemberIndexSumtotal;		//记录第三个分组的成员的个数
	int Note_number;					//记录需发送的那一个人
	void InitializeGroupingFrist();		//初始化分组1
	void newConnect_NoteNumber();		//发出统计个数请求
	QString PicturePath;				//图片路径
	QString NickName;					//昵称
	QString PersonalizedSignature;		//个性签名
	QString Accountnumber;				//用户账号
	QString LocalIp;					//用户Ip地址
	QString Note_register;				//收到的信号
	QTcpSocket *tcpSocket;				//接收哪个人登录的套接字
	QTcpSocket *tcpNoteNumber;			//读取分组成员的套接字
	QTcpSocket *closeTcpSocket;			//关闭的套接字
	QTcpSocket *AddSeccessTcpSocket;
	QByteArray message;					//存放从服务器接收到的字符串
	quint16 blockSize;					//存放文件的大小信息

private slots:
	void sendAddSeccess();					//发送添加成功
	void dealWithAdd();								//处理添加
	void on_tianjia_clicked();					//添加进入好友
	void on_touxiangbt_clicked();
	void TurnIntoChatInterface();				//进入聊天界面
private:
	int FriendSendMessageNumber;				//接收消息下标
	QPushButton *FriendSendMessage[100];		//有朋友发来的消息
	QString Friend_AccountNumber;				//记录出待向数据库发送的好友的账号
	bool Send_RunDateBase_or_Otherclient;		// AddSeccessConnect 发送到数据库还是客户端
	void AddSeccessConnect();			//添加成功连接
	QFrame *transverseLine_Up;			//横线
	QFrame *transverseLine_Down;			//横线
	QFrame *uprightLine_Left;
	QFrame *uprightLine_Right;
	QLabel *label_addDisplay;
	QLabel *label_NickName;
	QLabel *label_PersonalizedSignature;
	QPushButton *affirmAdd[30];					//确定按钮
	int addPrompt;								//添加的提示
	QString Judge;
	int Frist_GroupingMemberIndexSumtotal;				//分组1成员总数
	int FriendAmount;
	void readPicture(QString s);
	int Last_fenzu1_geshu;					//分组1的最后一个人的下一个人的号码个数
	void closeEvent(QCloseEvent *e);
	void showEvent(QShowEvent *e);
	QPushButton *fenzu1_Friend[50];
	QPushButton *fenzu2_Friend[50];
	QPushButton *fenzu3_Friend[50];
	QPushButton *applyPeople[50];
	QWidget *TJ_apply;
	QWidget *TJ_xiaoxi;			//添加消息界面
	QWidget *TJ_fenzu1;
	QWidget *TJ_fenzu2;
	QWidget *TJ_fenzu3;
	QScrollArea *apply_GDT;
	QScrollArea *xiaoxi_GDT;
	QScrollArea *fenzu1_GDT;
	QScrollArea *fenzu2_GDT;
	QScrollArea *fenzu3_GDT;
	tianjiafriend addNewFriend;//添加朋友界面
	xiugaixingxi w;				//修改信息界面
	liaotianjiemian *Frist_GroupingShow;			//聊天分组1界面
	liaotianjiemian *Second_GroupingShow;			//聊天分组2界面
	liaotianjiemian *Third_GroupingShow;			//聊天分组3界面
	liaotianjiemian *xiaoxi_GroupingShow;			//聊天消息界面
	Ui::dengluview ui;
	struct UserInformation
	{
		int fenzu_User;
		QString AccountNumber_User;			//用户账号	
		QString NickName_User;				//用户昵称
		QString PersonalizedSignature_User;	//用户个性签名
		QString PortNumber_User;			//端口号
		QString LocalIp_User;				//用户IP
		QString Sex_User;					//用户性别
		QString Display_Picture_User;		//用户图片位置
		UserInformation(int fenzu_User_, QString AccountNumber_, QString Sex_, QString NickName_, QString PersonalizedSignature_, QString Display_Picture_, QString PortNumber_, QString LocalIp_)
		{
			AccountNumber_User = AccountNumber_;
			Sex_User = Sex_;
			fenzu_User = fenzu_User_;
			NickName_User = NickName_;
			PersonalizedSignature_User = PersonalizedSignature_;
			PortNumber_User = PortNumber_;
			LocalIp_User = LocalIp_;
			Display_Picture_User = Display_Picture_;
		}
		UserInformation(){}
	};
	#ifndef QT_NO_DATASTREAM  
	friend QDataStream& operator>>(QDataStream &in, UserInformation& data)
	{
		in >> data.fenzu_User >>  data.AccountNumber_User >> data.Sex_User >> data.NickName_User >> data.PersonalizedSignature_User >> data.Display_Picture_User >> data.PortNumber_User >> data.LocalIp_User;
		return in;
	}
	#endif
	private:
	void addNewMan(UserInformation);
	private:
		QList<QString> FriendName;							//添加用户账号 检测此账号是否已被实例
		QList<UserInformation> momoda;						//添加信息的用户
		QList<UserInformation> Users;						//所有的用户			
		QList<UserInformation> Users_First;					//分组1的用户
		QList<UserInformation> Users_Second;				//分组2的用户
		QList<UserInformation> Users_Third;					//分组3的用户
		QList<UserInformation> Users_xiaoxi;				//消息分组的用户
	private:
		void addNewFriend_Second_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator);		//分组2添加朋友
		void addNewFriend_Frist_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator);		//分组1添加朋友
		void addNewFriend_Third_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator);		//分组3添加朋友
		void addNewFriend_xiaoxi_GroupingMember(QList<dengluview::UserInformation>::iterator MemberIndicator);		//消息分组添加好友
};
