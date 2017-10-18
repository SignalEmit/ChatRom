#ifndef SERVER_H
#define SERVER_H

#include <QtWidgets/QMainWindow>
#include "ui_server.h"
#include<QtNetwork>
#include<QSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QFile>
#include<QDir>
#include<QTime>
#include<QList>
#include<QFile>
# pragma execution_character_set("utf-8")
class Server : public QMainWindow
{
	Q_OBJECT
private slots:
	void monitor();					//监听
	void receive_information();		//接收账号密码
public:
	Server(QWidget *parent = 0);
	~Server();
private:
	QString take_notes;
	void CreatFile();
	void ReceiveOffineMessage();			//接收离线消息
	void closeChatWindow();					//关闭聊天窗口时触发
	void JudgeFriendOpenWindows();			//判断朋友 是否也打开界面
	void AddFriendInDatebase();				//将好友存入数据库
	void confirmAdd();						//确认添加 本账号添加后 返回给服务器服务器处理  返给添加用户
	void DownOnline();						//下线
	//QString FriendAccountnumber;			//朋友的账号
	void addUser();							//添加用户
	void selectaddUser();					//查询待添加用户信息
	void ClickUserInformation();	//修改用户个人信息
	void MePortNumber();			//发送自己的端口
	void ReadLinkman();						//读取联系人个数
	void FindAccountnumberinformation(QString Accountnumber);		//查找信息并发送
	void MasterLoginInterface();	//祝登陆界面信息
	void receive_password();		//接收忘记密码
	void receive_register();		//接收注册
	void receive_entry();			//接收登录
	//void receive_Accountnumber_Password_PhoneNumber();
	quint16 blockSize;
	bool find_Accountnumber_Password(QString Accountnumber, QString Password, QString LocalIp);
	int Record_The_Number;
	QByteArray ByteArray_Judge;						//缓冲判断端口
	QByteArray ByteArray_Password;					//缓冲接收密码
	QByteArray ByteArray_Accountnumber;				//缓冲接收账号
	QByteArray ByteArray_Password_again;			//缓冲接收密码
	QByteArray ByteArray_phone_number;				//缓冲接收手机号
	QByteArray ByteArray_LocalIp;					//缓冲接收Ip
	QByteArray ByteArray_Fenzu;					    //缓冲接收分组
//	int PortNumber;
	//QString LocalIp;								//Ip
//	QString Password;								//账号
//	QString Accountnumber;							//密码
//	QString Password_again;							//确认密码
//	QString phone_number;							//手机号
	void send(QString s);			//发送消息
	QTcpSocket *receiveSocket;			//接收
	bool register_dealwith(QString Accountnumber, QString Password, QString phone_number);			//注册处理（数据库比对）
	bool forget_password(QString Accountnumber, QString Password, QString phone_number);
	void createDatebase();
	void JudgeDatabase();
	QDir fileDB;
	QSqlDatabase db;
	QTcpServer *tcpServer;			//发送
	Ui::ServerClass ui;
struct newsSave
{
	QTcpSocket *UserServerSocket;			//接收
	QString UserAccountNumber;		//用户账号
	QString FriendAccountNumber;		//用户账号
	QString FilePath;					//文件路径
	newsSave(QTcpSocket *UserServerSocket_, QString UserAccountNumber_, QString FriendAccountNumber_, QString FilePath_)
	{
		UserServerSocket = UserServerSocket_;
		UserAccountNumber = UserAccountNumber_;
		FriendAccountNumber = FriendAccountNumber_;
		FilePath = FilePath_;
	}
};
struct onlineUser
{
	QString UserAccountNumber;		//用户账号
	QTcpSocket *UserServerSocket;			//接收
	onlineUser(QString UserAccountNumber_, QTcpSocket *UserServerSocket_)
	{
		UserAccountNumber = UserAccountNumber_;
		UserServerSocket = UserServerSocket_;
	}
};
struct UserInformation
{
	int fenzu_User;
	QString AccountNumber_User;			//用户账号	
	QString NickName_User;				//用户昵称
	QString PersonalizedSignature_User;	//用户个性签名
	QString PortNumber_User;				//端口号
	QString LocalIp_User;				//用户IP
	QString Sex_User;					//用户性别
	QString Display_Picture_User;
	UserInformation(int fenzu_User_,QString AccountNumber_, QString Sex_, QString NickName_, QString PersonalizedSignature_, QString Display_Picture_, QString PortNumber_, QString LocalIp_)
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
};
#ifndef QT_NO_DATASTREAM  
friend QDataStream& operator<<(QDataStream &out, UserInformation& data)
{
	out << data.fenzu_User << data.AccountNumber_User << data.Sex_User << data.NickName_User << data.PersonalizedSignature_User << data.Display_Picture_User << data.PortNumber_User << data.LocalIp_User;
	return out;
}
#endif
private:
	QList<onlineUser> onlineUsers;			//在线用户套接字
	QList<newsSave> newInformation;			//新消息
};
#endif // SERVER_H
