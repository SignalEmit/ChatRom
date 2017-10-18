#include "xiugaixingxi.h"
#include<QDebug>
#include<QFileDialog>
#include<QDir>
#include<QPainter>
#include<QByteArray>
#include<QBuffer>
#include<QTextCodec>
xiugaixingxi::xiugaixingxi(QWidget * parent) : QWidget(parent) {
	setupUi(this);
	this->setWindowTitle("聊一聊");
	man_radioButton->setChecked(true);
	Judge_Sex = "男";
	connect(guanbi, SIGNAL(clicked()), this, SLOT(close()));
	connect(nichengqingchubt, SIGNAL(clicked()), this, SLOT(qingchu()));
	connect(gexingqianmingbt, SIGNAL(clicked()), this, SLOT(qingchu()));
	connect(man_radioButton, SIGNAL(clicked()), this, SLOT(radioChange()));
	connect(woman_radioButton, SIGNAL(clicked()), this, SLOT(radioChange()));
	connect(Xiugai_Displaybt, SIGNAL(clicked()), this, SLOT(Xiugai_Display()));
}
void xiugaixingxi::radioChange()
{
	if (sender() == man_radioButton)
		Judge_Sex = "男";
	else
		Judge_Sex = "女";
}
void xiugaixingxi::on_queding_clicked()
{
	tcpSocket = new QTcpSocket(this);
	tcpSocket->abort(); //取消已有的连接
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	tcpSocket->connectToHost("10.211.26.93", 666);

}
void xiugaixingxi::displayError(QAbstractSocket::SocketError)
{
	QMessageBox::warning(this, tr("警告"), tr("请检查您的网络"), QMessageBox::Yes);
}
void xiugaixingxi::sendMessage()
{
	QByteArray ByteArray_judge; //用于暂存我们要发送的数据
	QDataStream out_judge(&ByteArray_judge, QIODevice::WriteOnly);
	out_judge << (quint16)0;
	out_judge << tr("修改个人信息").toLocal8Bit();
	out_judge.device()->seek(0);
	out_judge << (quint16)(ByteArray_judge.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_judge);

	/*发送账号*/
	QByteArray ByteArray_account_number; //用于暂存我们要发送的数据
	QDataStream out_account_number(&ByteArray_account_number, QIODevice::WriteOnly);
	out_account_number << (quint16)0;
	out_account_number << Denglu_people.toLocal8Bit();
	out_account_number.device()->seek(0);
	out_account_number << (quint16)(ByteArray_account_number.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_account_number);
	//发送性别
	QByteArray ByteArray_Sex; 
	QDataStream out_Sex(&ByteArray_Sex, QIODevice::WriteOnly);
	out_Sex << (quint16)0;
	out_Sex << Judge_Sex.toLocal8Bit();
	out_Sex.device()->seek(0);
	out_Sex << (quint16)(ByteArray_Sex.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_Sex);
	//发送昵称
	QByteArray ByteArray_NickName; 
	QDataStream out_NickName(&ByteArray_NickName, QIODevice::WriteOnly);
	out_NickName << (quint16)0;
	out_NickName << nichengxiugai->text().toLocal8Bit();
	out_NickName.device()->seek(0);
	out_NickName << (quint16)(ByteArray_NickName.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_NickName);
	//发送个性签名
	QByteArray ByteArray_PersonalizedSignature; //用于暂存我们要发送的数据
	QDataStream out_PersonalizedSignature(&ByteArray_PersonalizedSignature, QIODevice::WriteOnly);
	out_PersonalizedSignature << (quint16)0;
	out_PersonalizedSignature << gexingqianming->text().toLocal8Bit();
	out_PersonalizedSignature.device()->seek(0);
	out_PersonalizedSignature << (quint16)(ByteArray_PersonalizedSignature.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_PersonalizedSignature);
	//发送照片
	QString s = "Display_img/" + Denglu_people + ".jpg";
	QByteArray ByteArray_DisplayPicture; //用于暂存我们要发送的数据
	QDataStream out_DisplayPicture(&ByteArray_DisplayPicture, QIODevice::WriteOnly);
	out_DisplayPicture << (quint16)0;
	out_DisplayPicture << s.toLocal8Bit();
	out_DisplayPicture.device()->seek(0);
	out_DisplayPicture << (quint16)(ByteArray_DisplayPicture.size() - sizeof(quint16));
	tcpSocket->write(ByteArray_DisplayPicture);
	this->close();			//关闭界面
}
void xiugaixingxi::Shezhitupian(QString s)
{
	QPixmap pixmap(s);
	touxiang->setPixmap(pixmap.scaled(91, 91, Qt::IgnoreAspectRatio));
}
void xiugaixingxi::Xiugai_Display()
{
	//Shezhitupian(s);
	QString file = QFileDialog::getOpenFileName(this, "选择文件", "/img", ("所有格式(*.jpg;*.jpeg;*.jpe;*.jfif;*.bmp;*.dib;*.png;*.gif)"";;jpg格式(*.jpg)"";;jpeg格式(*jpeg)"";;png格式(*.png)"));
	if (file.isEmpty())
		return;
	QDir *File = new QDir;
	bool exits = File->exists("Display_img/");
	if (exits)
	{
		qDebug() << "存在";
	}
	else
	{
		qDebug() << "不存在";
		bool ok = File->mkdir("Display_img");
		if (ok)
			qDebug() << "创建";
		else
			qDebug() << "为创建";
	}
	s = "Display_img/" + Denglu_people + ".jpg";
	QFile *Fuzhi = new QFile();
	if (File->exists(s))
		File->remove(s);
	Fuzhi->copy(file, s);
	Shezhitupian(s);
}
void xiugaixingxi::closeEvent(QCloseEvent *e)
{
	QString s = "Display_img/" + Denglu_people + ".jpg";
	emit xiugaixinxixinhao(Judge_Sex, nichengxiugai->text(), gexingqianming->text(), s);
}
void xiugaixingxi::showEvent(QShowEvent *e)
{
	int i = 0;
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QFile jilu("jilu.txt");
	jilu.open(QIODevice::ReadOnly);
	QTextStream jieshou(&jilu);
	jieshou.setCodec(codec);
	while (!jieshou.atEnd())
	{
		if (i == 0)
			nichengxiugai->setText(jieshou.readLine());
		else if (i == 1)
			gexingqianming->setText(jieshou.readLine());
		else if (i == 2)
			Shezhitupian(jieshou.readLine());
		else if (i == 3)
			Denglu_people = jieshou.readLine();
		i++;
	}
	jilu.close();
	QFile::remove("jilu.txt");
}
void xiugaixingxi::qingchu()
{
	if (sender() == nichengqingchubt)
		nichengxiugai->clear();
	else
		gexingqianming->clear();
}
xiugaixingxi::~xiugaixingxi() {
	
}
