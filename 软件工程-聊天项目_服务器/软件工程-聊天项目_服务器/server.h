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
	void monitor();					//����
	void receive_information();		//�����˺�����
public:
	Server(QWidget *parent = 0);
	~Server();
private:
	QString take_notes;
	void CreatFile();
	void ReceiveOffineMessage();			//����������Ϣ
	void closeChatWindow();					//�ر����촰��ʱ����
	void JudgeFriendOpenWindows();			//�ж����� �Ƿ�Ҳ�򿪽���
	void AddFriendInDatebase();				//�����Ѵ������ݿ�
	void confirmAdd();						//ȷ����� ���˺���Ӻ� ���ظ�����������������  ��������û�
	void DownOnline();						//����
	//QString FriendAccountnumber;			//���ѵ��˺�
	void addUser();							//����û�
	void selectaddUser();					//��ѯ������û���Ϣ
	void ClickUserInformation();	//�޸��û�������Ϣ
	void MePortNumber();			//�����Լ��Ķ˿�
	void ReadLinkman();						//��ȡ��ϵ�˸���
	void FindAccountnumberinformation(QString Accountnumber);		//������Ϣ������
	void MasterLoginInterface();	//ף��½������Ϣ
	void receive_password();		//������������
	void receive_register();		//����ע��
	void receive_entry();			//���յ�¼
	//void receive_Accountnumber_Password_PhoneNumber();
	quint16 blockSize;
	bool find_Accountnumber_Password(QString Accountnumber, QString Password, QString LocalIp);
	int Record_The_Number;
	QByteArray ByteArray_Judge;						//�����ж϶˿�
	QByteArray ByteArray_Password;					//�����������
	QByteArray ByteArray_Accountnumber;				//��������˺�
	QByteArray ByteArray_Password_again;			//�����������
	QByteArray ByteArray_phone_number;				//��������ֻ���
	QByteArray ByteArray_LocalIp;					//�������Ip
	QByteArray ByteArray_Fenzu;					    //������շ���
//	int PortNumber;
	//QString LocalIp;								//Ip
//	QString Password;								//�˺�
//	QString Accountnumber;							//����
//	QString Password_again;							//ȷ������
//	QString phone_number;							//�ֻ���
	void send(QString s);			//������Ϣ
	QTcpSocket *receiveSocket;			//����
	bool register_dealwith(QString Accountnumber, QString Password, QString phone_number);			//ע�ᴦ�����ݿ�ȶԣ�
	bool forget_password(QString Accountnumber, QString Password, QString phone_number);
	void createDatebase();
	void JudgeDatabase();
	QDir fileDB;
	QSqlDatabase db;
	QTcpServer *tcpServer;			//����
	Ui::ServerClass ui;
struct newsSave
{
	QTcpSocket *UserServerSocket;			//����
	QString UserAccountNumber;		//�û��˺�
	QString FriendAccountNumber;		//�û��˺�
	QString FilePath;					//�ļ�·��
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
	QString UserAccountNumber;		//�û��˺�
	QTcpSocket *UserServerSocket;			//����
	onlineUser(QString UserAccountNumber_, QTcpSocket *UserServerSocket_)
	{
		UserAccountNumber = UserAccountNumber_;
		UserServerSocket = UserServerSocket_;
	}
};
struct UserInformation
{
	int fenzu_User;
	QString AccountNumber_User;			//�û��˺�	
	QString NickName_User;				//�û��ǳ�
	QString PersonalizedSignature_User;	//�û�����ǩ��
	QString PortNumber_User;				//�˿ں�
	QString LocalIp_User;				//�û�IP
	QString Sex_User;					//�û��Ա�
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
	QList<onlineUser> onlineUsers;			//�����û��׽���
	QList<newsSave> newInformation;			//����Ϣ
};
#endif // SERVER_H
