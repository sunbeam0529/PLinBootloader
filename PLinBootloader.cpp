#include "PLinBootloader.h"
#include <stdlib.h>
#include <windows.h>
#include <QFileDialog>

#define DIDNO_SWVERSION		0x068E
#define DIDNO_HWVERSION		0xF1A3


PLinBootloader::PLinBootloader(QWidget *parent)
	: QMainWindow(parent)
{
	int ret;
	ui.setupUi(this);//初始化界面
	ui.widget->hide();
	Display(u8"加载成功"); 
	timer = new QTimer(this);
	
	customPlot = ui.widget;
	customPlot->addGraph();//添加graph等价于添加新曲线
	customPlot->graph(0)->setPen(QPen(Qt::blue));// 曲线的颜色
	customPlot->addGraph();//添加graph等价于添加新曲线
	customPlot->graph(1)->setPen(QPen(Qt::red));// 曲线的颜色
	HWList = new QList<QString>;
	x.resize(50);
	y0.resize(50);
	y1.resize(50);
	for (int i = 0; i < 50; ++i)
	{
		x[i] = i;
		y0[i] = 0; // 第一条曲线
		y1[i] = 0; // 第二条曲线
	}
	customPlot->graph(0)->setData(x, y0);
	customPlot->graph(1)->setData(x, y1);

	//customPlot->graph(0)->rescaleAxes();//自动缩放
	customPlot->graph(1)->rescaleAxes();
	//
	ui.btnStop->setEnabled(FALSE);//设置停止按钮为禁用
	ret = pd.LoadDLL();
	if (ret == RET_ERR)//加载DLL文件
	{
		MessageBox(NULL, TEXT("Error: \"找不到PLinApi.dll!\""), TEXT("Error!"), MB_ICONERROR);
	}
	else if (ret == RET_OK)
	{
		Display(u8"PLinApi.dll加载成功");
	}
	ret = sd.LoadDLL();
	if (ret == RET_ERR)//加载DLL文件
	{
		MessageBox(NULL, TEXT("Error: \"找不到icsneo40.dll!\""), TEXT("Error!"), MB_ICONERROR);
	}
	else if (ret == RET_OK)
	{
		Display(u8"icsneo40.dll加载成功");
	}
	ui.progressBar->setValue(0);//设置进度条为0
	BootState = 0;//初始化状态
	
	int count = ui.tabWidget->count();
	for (int i = 2; i < count; i++)
	{
		ui.tabWidget->removeTab(2);
	}
	ui.tabWidget->setTabEnabled(1, false);

}

PLinBootloader::~PLinBootloader(void)
{
	pd.DoLINDisconnect();//断开连接
	
}

void PLinBootloader::on_sb_LightBarStart_checkedChanged(bool value)
{
	Display((QString::number((int)value)).toStdString());
	if (value)
	{
		connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut01()));
		timer->start(100);
	}
	else
	{
		timer->stop();
	}
}
void PLinBootloader::on_colorPanelHSB_colorChanged(const QColor& color, double hue, double sat)
{
	ui.colorPanelBar_2->colorChanged(ui.colorPanelBar_2->getColor(), hue, sat);
	//Display(color.name().toStdString());
	
	Display((QString::number(hue) + "," + QString::number(sat)).toStdString());
}



void PLinBootloader::onTimeOut00(void)
{
	BYTE temp[8] = { 0x21,0x02,0x25,0x00,0xff,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		timer->stop();
		ui.btnReadData->setEnabled(TRUE);
		return;
	}
	else
	{
		Display(u8"读取数据");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据

	

}

void PLinBootloader::onTimeOut01(void)
{
	BYTE temp[8] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		timer->stop();
		ui.btnReadData->setEnabled(TRUE);
		return;
	}

	temp[1] = ui.spin_SelectLED->value();//led id
	temp[2] = (BYTE)(ui.colorPanelBar->getValue());//led brightness
	temp[3] = ui.colorPanelBar_2->getColor().red();//red
	temp[4] = ui.colorPanelBar_2->getColor().blue();//green
	temp[5] = ui.colorPanelBar_2->getColor().green();//blue

	TransmitID(1, temp);
	ReadMsg();
}

void PLinBootloader::Display(string s) 
{
	ui.textBrowser->append(QString::fromStdString(s));
	
}


void PLinBootloader::on_btnWriteCfg_clicked(void)
{
	BYTE temp[8] = { 0x21,0x04,0x2E,0xF0,0x01,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"写配置");
	}
	temp[5] = ui.spinWriteCfg->value();
	if (temp[5] >= 0 && temp[5] <= 3)
	{
		TransmitID(0);//唤醒
		Sleep(10);
		Write3C(temp);//发送诊断请求
		Sleep(10);
		ReadMsg();
		Read3D();//读取数据
	}
	else
	{
		Display(u8"配置错误");
	}
}

void PLinBootloader::on_btnFresh_clicked(void)
{
	//QList<UINT8> datebuf(256);
	int ret;
	ui.cbbSelectChenal->clear();
	ret = pd.FreshHW(HWList);//刷新硬件
	if (ret == RET_ERR)
	{
		ui.cbbSelectChenal->addItem(u8"未找到硬件");
	}
	for (int i = 0; i < HWList->count(); i++)
	{
		ui.cbbSelectChenal->addItem((*HWList)[i]);
	}
}

void PLinBootloader::on_btnConnect_clicked(void)
{
	int ret;
	ret = pd.DoLINConnect(ui.cbbSelectHW->currentIndex(),ui.cbbSelectBaudrate->currentText().toInt());//连接硬件
	if (ret == RET_OK)
	{
		ui.btnStop->setEnabled(TRUE);
		ui.btnConnect->setEnabled(FALSE);
		ui.tabWidget->setTabEnabled(1, true);
	}
}

void PLinBootloader::on_btnStop_clicked(void)
{
	pd.DoLINDisconnect();//断开连接
	ui.btnConnect->setEnabled(TRUE);
	ui.btnStop->setEnabled(FALSE);
}

void PLinBootloader::on_btnClear_clicked(void)
{
	ui.textBrowser->clear();//清空
}

void PLinBootloader::on_btnDID_ReadSW_clicked(void)
{
	//BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x94,0xff,0xff,0xff };
	BYTE temp[8] = { 0x21,0x03,0x22,DIDNO_SWVERSION>>8,DIDNO_SWVERSION,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取软件版本号");
	}
	ui.lbl_DIDSW->clear();
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btnDID_ReadHW_clicked(void)
{

	//BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x92,0xff,0xff,0xff };
	BYTE temp[8] = { 0x21,0x03,0x22,DIDNO_HWVERSION>>8,DIDNO_HWVERSION,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取硬件版本号");
	}
	ui.lbl_DIDHW->clear();
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btnDID_ReadBoot_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x90,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取Bootloader版本号");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL,16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btnDID_ReadPartnum_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x03,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取零件号");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btnDID_ReadModel_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x10,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取型号");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btn_AppMode_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x10,0x01,0xff,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"进入APP");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btn_BootMode_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x10,0x02,0xff,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"进入BOOT");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btn_ExtMode_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x10,0x03,0xff,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"进入扩展会话");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据
}

void PLinBootloader::on_btn_ReadMode_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xF1,0x86,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取当前会话");
	}
	temp[0] = ui.lineEdit->text().toInt(NULL, 16);
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D(temp[0]);//读取数据

}
void PLinBootloader::on_bnt_Unlock_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x27,0x01,0xff,0xff,0xff,0xff };
	INT16 seed;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"安全访问解锁");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	Transmit3DHead();//发送帧头
	Sleep(10);
	temp[0] = 0;
	ReadMsg(temp);//读取数据

	if (temp[0] == 0x21 && temp[1] == 0x4 && temp[2] == 0x67)//正响应
	{
		//读取种子
		seed = temp[4];
		seed <<= 8;
		seed |= temp[5];

		//计算秘钥
		seed = ~seed + 0x2019;

		//发送秘钥
		temp[2] = 0x27;
		temp[3] = 0x02;
		temp[4] = seed>>8;
		temp[5] = seed & 0xff;
		Write3C(temp);
		Sleep(10);

		//读取响应
		Transmit3DHead();//帧头
		Sleep(10);
		ReadMsg(temp);//读取数据
		if (temp[0] == 0x21 && temp[1] == 0x2 && temp[2] == 0x67 && temp[3] == 0x02)
			Display(u8"解锁成功");
	}

}


void PLinBootloader::on_btnSelectAppFile_clicked(void)
{
	//打开文件
	QString File = QFileDialog::getOpenFileName(NULL, u8"打开", ".", "S19 Files (*.sx;*.s19);;All Files (*.*)");
	ui.line_fileaddress->clear();//清空
	ui.line_fileaddress->setText(File);//填入路径
	ProcessS19File(File);//解析S19文件
}



void PLinBootloader::on_btnOneKeyBoot_clicked(void)
{
	int errortimes;
	if (ui.line_fileaddress->text() == NULL)
	{
		Display(u8"请选择烧写文件");
		return;
	}
	ProcessS19File(ui.line_fileaddress->text());//重新读取文件
	if (AppStack.isEmpty())
	{
		Display(u8"烧写文件不正确");
		return;
	}
	BootState = 1;
	on_btnDID_ReadSW_clicked();//软件版本
	Sleep(10);
	on_btnDID_ReadHW_clicked();//硬件版本
	Sleep(10);
	on_btnDID_ReadBoot_clicked();//BOOT版本
	Sleep(50);
	on_btn_BootMode_clicked();//进入boot
	Sleep(500);
	on_btn_BootMode_clicked();//确认进入
	Sleep(10);
	on_bnt_Unlock_clicked();//解锁
	Sleep(10);
	while (!AppStack.isEmpty())
	{
		INT32 address;
		int len,startpos=0,ret;
		QByteArray Data = *(AppStack.dequeue());//读取一部分数据
		address = AddressStack.dequeue();//读取地址
		len = LenStack.dequeue();//长度
		if (address > 0xff8000 || address < 0xff0000)
		{
			//地址错误
			continue;
		}
		//请求下载
		BYTE temp[8] = {0x21,0x10,0x07,0x34,0x01,address>>16,address >> 8,address};
		BYTE temp2[8] = { 0x21,0x21,len >> 8, len ,0,0,0,0};
		Write3C(temp);
		Sleep(10);
		Write3C(temp2);
		Sleep(100);

		ret = Wait3D(temp, 100);//等待响应
		if (ret == 0)//超时退出
		{
			Display(u8"超时");
			BootState = 0;
			return;
		}

		//初始化临时变量
		temp[0] = 0;
		int blocknum=1,frameid=0x21;
		BYTE txbuf[64];
		
		while (len > 64)//每次读取64个字节数据，直到完成
		{
			//显示当前块
			QString strtemp(u8"block ");
			strtemp.append(QString::number(blocknum));
			Display(strtemp.toStdString());

			//发送64字节数据
			putdata(Data, startpos, txbuf, 64);//转移数据
			TransmitBlock((char*)txbuf, 64, blocknum);//发送
			
			//等待响应
			ret = Wait3D(temp, 100);
			if (ret == 0)
			{
				Display(u8"超时");
				BootState = 0;
				return;
			}
			
			//刷新GUI
			QCoreApplication::processEvents();

			//判断响应
			if (temp[0] == 0x21 && temp[1] == 0x2 && temp[2] == 0x76 && temp[3] == blocknum)
			{
				//传送成功，相应变量增加
				blocknum++;
				if (blocknum >= 256)blocknum = 0;
				startpos += 64;
				len -= 64;
				position += 64;
				errortimes = 0;
				ui.progressBar->setValue(position * 100 / total);//更新进度条
			}
			else
			{
				errortimes++;
				if (errortimes >= 3)//错误超过3次，退出
				{
					Display(u8"失败");
					BootState = 0;
					return;
				}
			}
			//Sleep(50);
		}
		//发送最后一个块
		QString strtemp(u8"block ");
		strtemp.append(QString::number(blocknum));
		Display(strtemp.toStdString());//显示块序列
		putdata(Data, startpos, txbuf, len);//转移数据
		while (1)
		{
			TransmitBlock((char*)txbuf, len, blocknum);
			//Transmit3DHead();
			Sleep(10);
			temp[0] = 0;
			ret = Wait3D(temp, 100);
			if (ret == 0)
			{
				Display(u8"超时");
				BootState = 0;
				return;
			}
			if (temp[0] == 0x21 && temp[1] == 0x2 && temp[2] == 0x76 && temp[3] == blocknum)
			{
				//传送成功
				break;
			}
			else
			{
				errortimes++;
				if (errortimes >= 3)
				{
					Display(u8"失败");
					BootState = 0;
					return;
				}
			}
		}
	}
	ui.progressBar->setValue(100);
	Display(u8"刷写完成");
	QCoreApplication::processEvents();
	BootState = 2;
	Sleep(10);
	on_btnDID_ReadSW_clicked();
	Sleep(10);
}

void PLinBootloader::on_btnErgodic_clicked(void)
{
	int IDfrom, IDto;
	QString temp;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"开始遍历");
	}
	temp = ui.lineID1->text();//起始ID
	IDfrom = temp.toInt();
	temp = ui.lineID2->text();//结束ID
	IDto = temp.toInt();
	temp.clear();
	for (int id = IDfrom; id <= IDto; id++)
	{
		TransmitID(id); //发送ID帧头
		Sleep(10);		//等待10mS
		ReadMsg();		//读取数据
	}
	Display(u8"结束遍历");
}

void PLinBootloader::on_btnErgodicNAD_clicked(void)
{
	int IDfrom, IDto;
	QString temp;
	BYTE BUF[8] = { 0x21,0x03,0x22,0xF1,0x89,0x00,0x00,0x00 };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"开始遍历");
	}
	temp = ui.lineID3->text();//起始ID
	IDfrom = temp.toInt();
	temp = ui.lineID4->text();//结束ID
	IDto = temp.toInt();
	temp.clear();
	for (int id = IDfrom; id <= IDto; id++)
	{
		BUF[0] = id;
		Write3C(BUF); //发送ID帧头
		Sleep(10);		//等待10mS
		Read3D(id);		//读取数据
	}
	Display(u8"结束遍历");
}


void PLinBootloader::on_btnErgodicSID_clicked(void)
{
	int IDfrom, IDto;
	QString temp;
	BYTE BUF[8] = { 0x0A,0x03,0x22,0xF1,0x89,0x00,0x00,0x00 };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"开始遍历");
	}
	temp = ui.lineID5->text();//起始ID
	IDfrom = temp.toInt();
	temp = ui.lineID6->text();//结束ID
	IDto = temp.toInt();
	temp.clear();
	for (int SID = IDfrom; SID <= IDto; SID++)
	{
		BUF[2] = SID;
		Write3C(BUF); //发送ID帧头
		Sleep(10);		//等待10mS
		Read3D(0x0A);		//读取数据
	}
	Display(u8"结束遍历");
}

void PLinBootloader::on_btnErgodicDID_clicked(void)
{
	int IDfrom, IDto;
	QString temp;
	BYTE BUF[8] = { 0x0A,0x04,0x2e,0xF1,0x89,0x00,0x00,0x00 };
	unsigned int didlist[24] = { 0xF187, 0xF189, 0xF191, 0xF1A3, 0x062E, 0x065E, 0x068E, 0x06BE, 0x06EE, 0x071E, 0x074E, 0x6031,
								 0x6231, 0x6431, 0x6631, 0x6831, 0x6A31, 0x6C31, 0xF15B, 0xF186, 0xF198, 0xF19E, 0xF1A2, 0xF1DF };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"开始遍历");
	}
	temp = ui.lineID7->text();//起始ID
	IDfrom = temp.toInt();
	temp = ui.lineID8->text();//结束ID
	IDto = temp.toInt();
	temp.clear(); 
	/*
	for (int DID = IDfrom; DID <= IDto; DID++)
	{
		BUF[3] = DID >> 8;
		BUF[4] = DID;
		Write3C(BUF); //发送ID帧头
		Sleep(10);		//等待10mS
		Read3D(0x0A);		//读取数据
	}
	*/
	for (int DID = 0; DID < 24; DID++)
	{
		BUF[3] = didlist[DID] >> 8;
		BUF[4] = didlist[DID];
		Write3C(BUF); //发送ID帧头
		Sleep(10);		//等待10mS
		Read3D(0x0A);		//读取数据
	}
	Display(u8"结束遍历");
}
//btnTest
void PLinBootloader::on_btnTest_clicked(void)
{
	int IDfrom, IDto;
	QString temp;
	BYTE BUF[8] = { 0x0A,0x06,0xB0,0x00,0x00,0x00,0x00,0x21 };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"开始自定义测试");
	}
	
	BUF[0] = ui.lETest_B0->text().toInt(NULL, 16);
	BUF[1] = ui.lETest_B1->text().toInt(NULL, 16);
	BUF[2] = ui.lETest_B2->text().toInt(NULL, 16);
	BUF[3] = ui.lETest_B3->text().toInt(NULL, 16);
	BUF[4] = ui.lETest_B4->text().toInt(NULL, 16);
	BUF[5] = ui.lETest_B5->text().toInt(NULL, 16);
	BUF[6] = ui.lETest_B6->text().toInt(NULL, 16);
	BUF[7] = ui.lETest_B7->text().toInt(NULL, 16);

		Write3C(BUF); //发送ID帧头
		Sleep(10);		//等待10mS
		Read3D(BUF[0]);		//读取数据

}
void PLinBootloader::on_btnReadData_clicked(void)
{
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取数据");
	}
	datatime = 0;
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut00()));
	ui.widget->show();
	timer->start(50);
	ui.btnReadData->setEnabled(FALSE);
}

void PLinBootloader::on_btnReadDataStop_clicked(void)
{
	timer->stop();
	ui.btnReadData->setEnabled(TRUE);
	ui.widget->hide();
}


void PLinBootloader::on_btnWritePara_clicked(void)
{
	BYTE temp[8] = { 0x21,0x10,0x0A,0x26,0x02,0x00,0x00,0x00 };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"写参数");
	}
	temp[5] = ui.spinBox->value();
	temp[6] = 1 << (ui.cnnFrequency->currentIndex() + 2);
	temp[7] = ui.spnResolution->value();
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	temp[1] = 0x21;
	temp[2] = ui.spnMIDAC->value();
	temp[3] = ui.spnCIDAC->value();
	temp[4] = ui.spnFingerTH->value();
	temp[5] = ui.spnNoiseTH->value();
	temp[6] = ui.spnHysteresis->value();
	temp[7] = 0xff;
	Sleep(10);
	ReadMsg();
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btnReadPara_clicked(void)
{	
	BYTE temp[8] = { 0x21,0x03,0x26,0x01,0x00,0xff,0xff,0xff };
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取参数");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}











void PLinBootloader::ProcessS19File(QString FileAddress)
{
	QByteArray * tempstack;
	char readbuf[120];
	char databuf[120];
	QString temp,Qreadbuf;
	int linelen,i,datalen,stacklen,datalenlast;
	INT32 Address,AddressLast;
	QFileInfo info(FileAddress);
	if (!info.exists())
	{
		AppStack.clear();
		return;
	}
	else
	{
		//初始化局部变量
		AddressLast = 0;
		Address = 0;
		stacklen = 0;
		AppStack.clear();
		AddressStack.clear();
		LenStack.clear();
		total = 0;
		position = 0;

		//输出文件信息
		QString fileinfo = u8"文件名：";
		fileinfo += info.fileName();
		Display(fileinfo.toStdString());
		fileinfo.clear();
		fileinfo += u8"修改时间：";
		fileinfo += info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
		Display(fileinfo.toStdString());
	}
	QFile File(FileAddress);
	
	File.open(QIODevice::ReadOnly | QIODevice::Text);
	linelen = File.readLine(readbuf,120);
	while (linelen != -1)
	{
		if (linelen == 0)
		{
			linelen = File.readLine(readbuf, 120);
			continue;
		}

		if (readbuf[0] != 'S' && readbuf[0] != 's')//格式不对，读取下一行
		{
			linelen = File.readLine(readbuf, 120);
			continue;
		}
		Qreadbuf.clear();
		Qreadbuf.append(readbuf + 2);
		temp = Qreadbuf.left(2);
		datalen = temp.toInt(NULL, 16);
		Qreadbuf.clear();
		Qreadbuf.append(readbuf + 4);
		if (readbuf[1] == '3')	//S3格式
		{
			temp = Qreadbuf.left(8);
			Address = temp.toInt(NULL, 16);
			Qreadbuf.clear();
			Qreadbuf.append(readbuf + 12);
			datalen -= 5;
		}
		else if (readbuf[1] == '2')//S2格式
		{
			temp = Qreadbuf.left(6);
			Address = temp.toInt(NULL, 16);
			Qreadbuf.clear();
			Qreadbuf.append(readbuf + 10);
			datalen -= 4;
		}
		else if (readbuf[1] == '1')//S1格式
		{
			temp = Qreadbuf.left(4);
			Address = temp.toInt(NULL, 16);
			Qreadbuf.clear();
			Qreadbuf.append(readbuf + 8);
			datalen -= 3;
		}
		else if (readbuf[1] == '0')//S0格式
		{
			//S0没什么用
			linelen = File.readLine(readbuf, 120);
			continue;
		}
		else
		{
			linelen = File.readLine(readbuf, 120);
			continue;
		}
		
		if (Address != (AddressLast + datalenlast))
		{
			//地址不连续
			tempstack = new QByteArray;
			AppStack.enqueue(tempstack);
			AddressStack.enqueue(Address);
			if (stacklen != 0)
			{
				LenStack.enqueue(stacklen);
				stacklen = 0;
			}
		}
		AddressLast = Address;
		datalenlast = datalen;
		stacklen += datalen;
		if (Address >= 0xff0000 && Address < 0xff8000)
		{
			total += datalen;

		}
		for (i = 0; i < datalen; i++)
		{
			temp = Qreadbuf.mid(i*2, 2);
			tempstack->append((char)temp.toInt(NULL, 16));
		}
		linelen = File.readLine(readbuf, 120);
	}
	if(stacklen != 0)
	{
		LenStack.enqueue(stacklen);
		stacklen = 0;
	}
	File.close();
}

void PLinBootloader::TransmitBlock(char * data, int len,int blockid)
{
	BYTE temp[8] = { 0x21,0x10,len+2,0x36,blockid,0,0,0 };
	int frameid,i=0;
	temp[5] = data[i++];
	temp[6] = data[i++];
	temp[7] = data[i++];
	Write3C(temp);
	Sleep(10);
	len -= 3;
	frameid = 0x21;
	while (len > 6)
	{
		temp[1] = frameid;
		temp[2] = data[i++];
		temp[3] = data[i++];
		temp[4] = data[i++];
		temp[5] = data[i++];
		temp[6] = data[i++];
		temp[7] = data[i++];
		Write3C(temp);
		Sleep(10);
		if (frameid < 0x2F)frameid++;
		else frameid = 0x20;
		len -= 6;
	}

	temp[1] = frameid;
	int j;
	for (j = 2; len > 0; len--,j++)
	{
		temp[j] = data[i++];
	}
	for (; j < 8; j++)
	{
		temp[j] = 0xff;
	}
	Write3C(temp);
	Sleep(10);
}

void PLinBootloader::Write3C(BYTE *buf)
{
	TLINMsg msg;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	msg.FrameId = 0x3C;
	msg.Direction = dirPublisher;
	msg.Length = 8;
	msg.ChecksumType = cstClassic;
	for (int i = 0; i < 8; i++)
		msg.Data[i] = buf[i];
	pd.CalculateChecksum(&msg);
	pd.Write(pd.m_hClient, pd.m_hHW, &msg);
}

void PLinBootloader::TransmitID(int id)
{
	TLINMsg msg;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	msg.FrameId = CalculatePID(id);
	msg.Direction = dirSubscriberAutoLength;//dirPublisher;// 
	msg.Length = 8;
	msg.ChecksumType = cstEnhanced;
	for (int i = 0; i < 8; i++)
		msg.Data[i] = 0;
	pd.CalculateChecksum(&msg);
	pd.Write(pd.m_hClient, pd.m_hHW, &msg);
}

void PLinBootloader::TransmitID(int id,BYTE * data)
{
	TLINMsg msg;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	msg.FrameId = CalculatePID(id);
	msg.Direction = dirPublisher;// 
	msg.Length = 8;
	msg.ChecksumType = cstEnhanced;
	for (int i = 0; i < 8; i++)
		msg.Data[i] = data[i];
	pd.CalculateChecksum(&msg);
	pd.Write(pd.m_hClient, pd.m_hHW, &msg);
}

int PLinBootloader::CalculatePID(int ID)
{
	int P0, P1;
	P0 = (ID & 0x01) ^ ((ID & 0x02) >> 1) ^ ((ID & 0x04) >> 2) ^ ((ID & 0x10) >> 4);
	P1 = (((ID & 0x02) >> 1) ^ ((ID & 0x08) >> 3) ^ ((ID & 0x10) >> 4) ^ ((ID & 0x20) >> 5));
	P1 = P1 ^ 0x01;
	ID = ID | (P0 << 6) | (P1 << 7);

	return ID;
}

void PLinBootloader::Transmit3DHead(void)
{
	TLINMsg msg;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}
	msg.FrameId = 0x7D;
	msg.Direction = dirSubscriber;
	msg.Length = 8;
	msg.ChecksumType = cstClassic;
	for (int i = 0; i < 8; i++)
		msg.Data[i] = 0;
	pd.CalculateChecksum(&msg);
	pd.Write(pd.m_hClient, pd.m_hHW, &msg);
}

void PLinBootloader::Read3D(void)
{
	TLINRcvMsg RcvMsg;
	BYTE temp[8], buffer[60] = {0}, * pbuffer;
	Transmit3DHead();
	Sleep(10);
	temp[0] = 0x00;
	ReadMsg(temp);
	pbuffer = buffer;
	while (temp[0] == 0x21)
	{
		if (temp[1] == 0x10)
		{
			putdata(temp + 2, pbuffer, 6);
			pbuffer += 6;
		}
		else if (temp[1] >= 0x20)
		{
			putdata(temp + 2, pbuffer, 6);
			pbuffer += 6;
		}
		else if (temp[1] < 7)
		{
			putdata(temp + 1, buffer, temp[1]+1);

			break;
		}


		Transmit3DHead();
		Sleep(10);
		temp[0] = 0x00;
		ReadMsg(temp);
	}
	ProcessDiag(buffer);
}
void PLinBootloader::Read3D(BYTE NAD)
{
	TLINRcvMsg RcvMsg;
	BYTE temp[8], buffer[60] = { 0 }, * pbuffer;
	Transmit3DHead();
	Sleep(10);
	temp[0] = 0x00;
	ReadMsg(temp);
	pbuffer = buffer;
	while (temp[0] == NAD && NAD!=0)
	{
		if (temp[1] == 0x10)
		{
			putdata(temp + 2, pbuffer, 6);
			pbuffer += 6;
		}
		else if (temp[1] >= 0x20)
		{
			putdata(temp + 2, pbuffer, 6);
			pbuffer += 6;
		}
		else if (temp[1] < 7)
		{
			putdata(temp + 1, buffer, temp[1] + 1);

			break;
		}


		Transmit3DHead();
		Sleep(10);
		temp[0] = 0x00;
		ReadMsg(temp);
	}
	ProcessDiag(buffer);
}

int PLinBootloader::Wait3D(BYTE* data,int times)
{
	while (times-- > 0)
	{
		Transmit3DHead();
		Sleep(10);
		data[0] = 0;
		ReadMsg(data);
		if (data[0] == 0x21)
			return 1;
	}
	return 0;//超时

}

void PLinBootloader::ProcessDiag(BYTE* buffer)
{
	int len = buffer[0];
	int DID = 0;
	if (len == 0)return;
	if (buffer[1] == 0x62)
	{
		DID = buffer[2];
		DID <<= 8;
		DID |= buffer[3];
		if (DID == DIDNO_SWVERSION)
		{
			buffer[len+1] = '\0';
			//Display((char *)(&buffer[4]));
			if(BootState == 0)
				ui.lbl_DIDSW->setText(QString::fromStdString((char*)(&buffer[4])));
			else if(BootState == 1)
				ui.lbl_DIDSW_2->setText(QString::fromStdString((char*)(&buffer[4])));
			else if(BootState == 2)
				ui.lbl_DIDSW_3->setText(QString::fromStdString((char*)(&buffer[4])));
		}
		else if (DID == DIDNO_HWVERSION)
		{
			buffer[len + 1] = '\0';
			if (BootState == 0)
				ui.lbl_DIDHW->setText(QString::fromStdString((char*)(&buffer[4])));
			else if (BootState == 1)
				ui.lbl_DIDHW_2->setText(QString::fromStdString((char*)(&buffer[4])));
		}
		else if (DID == 0xF190)
		{
			buffer[len + 1] = '\0';
			if (BootState == 0)
			ui.lbl_DIDBOOT->setText(QString::fromStdString((char*)(&buffer[4])));
			else if (BootState == 1)
			ui.lbl_DIDBOOT_2->setText(QString::fromStdString((char*)(&buffer[4])));
		}
		else if (DID == 0xF110)
		{
			buffer[len + 1] = '\0';
			ui.lbl_DIDMODEL->setText(QString::fromStdString((char*)(&buffer[4])));
		}
		else if (DID == 0xF103)
		{
			buffer[len + 1] = '\0';
			ui.lbl_DIDPART->setText(QString::fromStdString((char*)(&buffer[4])));
		}
		else
		{
			buffer[len + 1] = '\0';
			Display(QString::fromStdString((char*)(&buffer[4])).toStdString());
		}
	}
	else if (buffer[1] == 0x65)
	{
		int baseline, raw,i;
		baseline = (buffer[3] << 8) | buffer[4];
		raw = (buffer[5] << 8) | buffer[6];
		
		if (baselinedata.count() < 50)
		{
			baselinedata.append(baseline);
			rawdata.append(raw);
			for (i = 0; i < baselinedata.count(); i++)
			{
				y0[i] = baselinedata[i];
				y1[i] = rawdata[i];
			}
		}
		else
		{
			baselinedata.removeFirst();
			rawdata.removeFirst();
			baselinedata.append(baseline);
			rawdata.append(raw);
			for (i = 0; i < 50; i++)
			{
				y0[i] = baselinedata[i];
				y1[i] = rawdata[i];
			}
		}
		
		//customPlot->graph(0)->addData((double)datatime, (double)baseline);
		//customPlot->graph(1)->addData(datatime, raw);

		customPlot->graph(0)->setData(x, y0);
		customPlot->graph(1)->setData(x, y1);

		
		customPlot->graph(0)->rescaleAxes();
		customPlot->graph(1)->rescaleAxes(true);//自动缩放

		customPlot->replot();
		datatime++;
		ui.lcdNumber->display(raw-baseline);
	}
	else if (buffer[1] == 0x66 && buffer[2] == 0x01) //读参数
	{
		for (int i = 2; i < 8; i++)
		{
			if (buffer[4] == (0x01 << i))
			{
				ui.cnnFrequency->currentIndexChanged(i - 2);
			}
		}
		ui.spnResolution->setValue(buffer[5]);
		ui.spnMIDAC->setValue(buffer[6]);
		ui.spnCIDAC->setValue(buffer[7]);
		ui.spnFingerTH->setValue(buffer[8]);
		ui.spnNoiseTH->setValue(buffer[9]);
		ui.spnHysteresis->setValue(buffer[10]);
	}
	buffer[1] = 0;
}

void PLinBootloader::putdata(BYTE* src, BYTE* dst, int len)
{
	while (len--)
	{
		*dst++ = *src++;
	}
}

void PLinBootloader::putdata(QByteArray src, int start,BYTE* dst, int len)
{
	while (len--)
	{
		*dst++ = src[start++];
	}
}


void PLinBootloader::ReadMsg(void)
{
	TLINRcvMsg RcvMsg;
	TLINError IsEmpty = errOK;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}

	while (!(IsEmpty & errRcvQueueEmpty))
	{
		IsEmpty = pd.Read(pd.m_hClient, &RcvMsg);
		if (IsEmpty != errOK)
			continue;
		if (RcvMsg.Type != mstStandard)
			continue;
		if (RcvMsg.ErrorFlags != MSG_ERR_OK)
			continue;
		//if (RcvMsg.FrameId != 0x3C && RcvMsg.FrameId != 0x7D)
			//continue;
		QString str = "0x";
		str.append(QString::number(RcvMsg.FrameId & 0x3f, 16));
		str.append(":");
		for (int i = 0; i < RcvMsg.Length; i++)
		{
			//str.append(QString::number(RcvMsg.Data[i], 16));
			str.append("0x");
			str.append(QString("%1").arg(RcvMsg.Data[i], 2, 16, QChar('0')).toUpper());
			str.append(" ");
		}
		//QString strtemp(str.toUpper());
		ui.textBrowser->append(str);
		
	}
}

void PLinBootloader::ReadMsg(BYTE* data)
{
	TLINRcvMsg RcvMsg;
	TLINError IsEmpty = errOK;
	if (pd.isConnect() == RET_ERR)
	{
		Display(u8"硬件未连接");
		return;
	}

	while (!(IsEmpty & errRcvQueueEmpty))
	{
		IsEmpty = pd.Read(pd.m_hClient, &RcvMsg);
		if (IsEmpty != errOK)
			continue;
		if (RcvMsg.Type != mstStandard)
			continue;
		if (RcvMsg.ErrorFlags != MSG_ERR_OK)
			continue;
		//if (RcvMsg.FrameId != 0x3C && RcvMsg.FrameId != 0x7D)
			//continue;
		QString str = "0x";
		str.append(QString::number(RcvMsg.FrameId & 0x3f, 16).toUpper());
		str.append(":");
		for (int i = 0; i < RcvMsg.Length; i++)
		{
			//str.append(QString::number(RcvMsg.Data[i], 16));
			str.append("0x");
			str.append(QString("%1").arg(RcvMsg.Data[i], 2, 16, QChar('0')).toUpper());
			
			str.append(" ");
			if (RcvMsg.FrameId == 0x7D)
				data[i] = RcvMsg.Data[i];
		}
		//QString strtemp(str.toUpper());
		ui.textBrowser->append(str);

	}
}



