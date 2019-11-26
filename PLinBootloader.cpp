#include "PLinBootloader.h"
#include <stdlib.h>
#include <windows.h>
#include <QFileDialog>
PLinBootloader::PLinBootloader(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);//初始化界面
	ui.widget->hide();
	Display(u8"加载成功"); 
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut00()));
	connect(ui.switchButton, SIGNAL(checkedChanged(bool)), this, SLOT(onSwitchButton_Clicked()));
	customPlot = ui.widget;
	customPlot->addGraph();//添加graph等价于添加新曲线
	customPlot->graph(0)->setPen(QPen(Qt::blue));// 曲线的颜色
	customPlot->addGraph();//添加graph等价于添加新曲线
	customPlot->graph(1)->setPen(QPen(Qt::red));// 曲线的颜色
	
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
	if (this->LoadDLL() == LOADDLL_ERR)//加载DLL文件
	{
		MessageBox(NULL, TEXT("Error: \"找不到PLinApi.dll!\""), TEXT("Error!"), MB_ICONERROR);
	}
	LoadDLL_spy3();
	ui.progressBar->setValue(0);//设置进度条为0
	/*
	else
	{
		MessageBox(NULL, TEXT("加载DLL成功"), TEXT("Error!"), MB_ICONERROR);
	}
	*/
	BootState = 0;//初始化状态
}

PLinBootloader::~PLinBootloader(void)
{
	DoLINDisconnect();//断开连接
	FreeLibrary(m_hDll);//释放DLL
}

void PLinBootloader::onSwitchButton_Clicked(void)
{
	if (ui.switchButton->getChecked())
	{
		ui.lightButton->setRed();
	}
	else
	{
		ui.lightButton->setLightBlue();
	}
	
}

void PLinBootloader::onTimeOut00(void)
{
	BYTE temp[8] = { 0x21,0x02,0x25,0x00,0xff,0xff,0xff,0xff };
	if (m_hClient == NULL)
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


void PLinBootloader::Display(string s) 
{
	ui.textBrowser->append(QString::fromStdString(s));
	
}


void PLinBootloader::on_btnFresh_clicked(void)
{
	int iResult;
	NeoDevice ndNeoToOpen;
	int iNumberOfDevices;
	//ui.textBrowser->append(QString::number(ui.cbbSelectHW->currentIndex()));//显示当前选择的序号，测试结果从0开始
	/*
	if(ui.cbbSelectHW == 0)	//PCAN
		FreshHW();//刷新硬件
	else if (ui.cbbSelectHW == 0)//SPY3
	{
		iResult = icsneoFindNeoDevices(8,&ndNeoToOpen,&iNumberOfDevices);
	}
		*/
	FreshHW();//刷新硬件
}

void PLinBootloader::on_btnConnect_clicked(void)
{
	DoLINConnect();//连接硬件
}

void PLinBootloader::on_btnStop_clicked(void)
{
	DoLINDisconnect();//断开连接
}

void PLinBootloader::on_btnClear_clicked(void)
{
	ui.textBrowser->clear();//清空
}

void PLinBootloader::on_btnDID_ReadSW_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x94,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取软件版本号");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btnDID_ReadHW_clicked(void)
{

	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x92,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取硬件版本号");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btnDID_ReadBoot_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x90,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取Bootloader版本号");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btnDID_ReadPartnum_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x03,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取零件号");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btnDID_ReadModel_clicked(void)
{
	BYTE temp[8] = { 0x21,0x03,0x22,0xf1,0x10,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取型号");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btn_AppMode_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x10,0x01,0xff,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"进入APP");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_btn_BootMode_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x10,0x02,0xff,0xff,0xff,0xff };
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"进入BOOT");
	}
	TransmitID(0);//唤醒
	Sleep(10);
	Write3C(temp);//发送诊断请求
	Sleep(10);
	ReadMsg();
	Read3D();//读取数据
}

void PLinBootloader::on_bnt_Unlock_clicked(void)
{
	BYTE temp[8] = { 0x21,0x02,0x27,0x01,0xff,0xff,0xff,0xff };
	INT16 seed;
	if (m_hClient == NULL)
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
	if (m_hClient == NULL)
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

void PLinBootloader::on_btnReadData_clicked(void)
{
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}
	else
	{
		Display(u8"读取数据");
	}
	datatime = 0;
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
	if (m_hClient == NULL)
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
	if (m_hClient == NULL)
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

int PLinBootloader::LoadDLL(void)
{
	m_hDll = LoadLibrary(TEXT("PLinApi.dll"));
	if(m_hDll != NULL)
	{
		this->Display(u8"加载DLL成功");
		m_bWasLoaded = 1;
		//return LOADDLL_OK;
	}	
	else
	{
		this->Display(u8"找不到DLL文件");
		m_bWasLoaded = 0;
		return LOADDLL_ERR;
	}
	// Loads API functions
	//
	m_pRemoveClient = (fpRemoveClient)GetFunction("LIN_RemoveClient");
	m_pResetClient = (fpResetClient)GetFunction("LIN_ResetClient");
	m_pConnectClient = (fpConnectClient)GetFunction("LIN_ConnectClient");
	m_pDisconnectClient = (fpDisconnectClient)GetFunction("LIN_DisconnectClient");
	m_pResetHardware = (fpResetHardware)GetFunction("LIN_ResetHardware");
	m_pSuspendKeepAlive = (fpSuspendKeepAlive)GetFunction("LIN_SuspendKeepAlive");
	m_pResumeKeepAlive = (fpResumeKeepAlive)GetFunction("LIN_ResumeKeepAlive");
	m_pResetHardwareConfig = (fpResetHardwareConfig)GetFunction("LIN_ResetHardwareConfig");
	m_pSuspendSchedule = (fpSuspendSchedule)GetFunction("LIN_SuspendSchedule");
	m_pResumeSchedule = (fpResumeSchedule)GetFunction("LIN_ResumeSchedule");
	m_pXmtWakeUp = (fpXmtWakeUp)GetFunction("LIN_XmtWakeUp");
	m_pDeleteSchedule = (fpDeleteSchedule)GetFunction("LIN_DeleteSchedule");
	m_pStartSchedule = (fpStartSchedule)GetFunction("LIN_StartSchedule");
	m_pRegisterClient = (fpRegisterClient)GetFunction("LIN_RegisterClient");
	m_pIdentifyHardware = (fpIdentifyHardware)GetFunction("LIN_IdentifyHardware");
	m_pSetClientParam = (fpSetClientParam)GetFunction("LIN_SetClientParam");
	m_pGetClientParam = (fpGetClientParam)GetFunction("LIN_GetClientParam");
	m_pSetClientFilter = (fpSetClientFilter)GetFunction("LIN_SetClientFilter");
	m_pGetClientFilter = (fpGetClientFilter)GetFunction("LIN_GetClientFilter");
	m_pRead = (fpRead)GetFunction("LIN_Read");
	m_pReadMulti = (fpReadMulti)GetFunction("LIN_ReadMulti");
	m_pWrite = (fpWrite)GetFunction("LIN_Write");
	m_pInitializeHardware = (fpInitializeHardware)GetFunction("LIN_InitializeHardware");
	m_pGetAvailableHardware = (fpGetAvailableHardware)GetFunction("LIN_GetAvailableHardware");
	m_pSetHardwareParam = (fpSetHardwareParam)GetFunction("LIN_SetHardwareParam");
	m_pGetHardwareParam = (fpGetHardwareParam)GetFunction("LIN_GetHardwareParam");
	m_pRegisterFrameId = (fpRegisterFrameId)GetFunction("LIN_RegisterFrameId");
	m_pSetFrameEntry = (fpSetFrameEntry)GetFunction("LIN_SetFrameEntry");
	m_pGetFrameEntry = (fpGetFrameEntry)GetFunction("LIN_GetFrameEntry");
	m_pUpdateByteArray = (fpUpdateByteArray)GetFunction("LIN_UpdateByteArray");
	m_pStartKeepAlive = (fpStartKeepAlive)GetFunction("LIN_StartKeepAlive");
	m_pSetSchedule = (fpSetSchedule)GetFunction("LIN_SetSchedule");
	m_pGetSchedule = (fpGetSchedule)GetFunction("LIN_GetSchedule");
	m_pSetScheduleBreakPoint = (fpSetScheduleBreakPoint)GetFunction("LIN_SetScheduleBreakPoint");
	m_pStartAutoBaud = (fpStartAutoBaud)GetFunction("LIN_StartAutoBaud");
	m_pGetStatus = (fpGetStatus)GetFunction("LIN_GetStatus");
	m_pCalculateChecksum = (fpCalculateChecksum)GetFunction("LIN_CalculateChecksum");
	m_pGetVersion = (fpGetVersion)GetFunction("LIN_GetVersion");
	m_pGetVersionInfo = (fpGetVersionInfo)GetFunction("LIN_GetVersionInfo");
	m_pGetErrorText = (fpGetErrorText)GetFunction("LIN_GetErrorText");
	m_pGetPID = (fpGetPID)GetFunction("LIN_GetPID");
	m_pGetTargetTime = (fpGetTargetTime)GetFunction("LIN_GetTargetTime");
	m_pSetResponseRemap = (fpSetResponseRemap)GetFunction("LIN_SetResponseRemap");
	m_pGetResponseRemap = (fpGetResponseRemap)GetFunction("LIN_GetResponseRemap");
	m_pGetSystemTime = (fpGetSystemTime)GetFunction("LIN_GetSystemTime");


	m_bWasLoaded = m_pRemoveClient && m_pResetClient && m_pConnectClient && m_pDisconnectClient &&
		m_pResetHardware && m_pSuspendKeepAlive && m_pResumeKeepAlive && m_pResetHardwareConfig &&
		m_pSuspendSchedule && m_pResumeSchedule && m_pXmtWakeUp && m_pDeleteSchedule && m_pStartSchedule &&
		m_pRegisterClient && m_pIdentifyHardware && m_pSetClientParam && m_pGetClientParam && m_pSetClientFilter &&
		m_pGetClientFilter && m_pRead && m_pReadMulti && m_pWrite && m_pInitializeHardware && m_pGetAvailableHardware &&
		m_pSetHardwareParam && m_pGetHardwareParam && m_pRegisterFrameId && m_pSetFrameEntry && m_pGetFrameEntry &&
		m_pUpdateByteArray && m_pStartKeepAlive && m_pSetSchedule && m_pGetSchedule && m_pSetScheduleBreakPoint &&
		m_pStartAutoBaud && m_pGetStatus && m_pCalculateChecksum && m_pGetVersion && m_pGetVersionInfo &&
		m_pGetErrorText && m_pGetPID && m_pGetTargetTime && m_pSetResponseRemap && m_pGetResponseRemap &&
		m_pGetSystemTime;
	if (m_bWasLoaded != NULL)
	{
		Display(u8"加载API成功");
	}
	else
	{
		Display(u8"加载API失败");
	}
	return LOADDLL_OK;

}

int PLinBootloader::LoadDLL_spy3(void)
{
	m_hDll_spy3 = LoadLibrary(TEXT("icsneo40.dll"));
	if (m_hDll_spy3 != NULL)
	{
		Display(u8"加载icsneo40.dll成功");
	}
	else
	{
		Display(u8"加载icsneo40.dll失败");
		return 0;
	}
	//icsneoFindNeoDevices = (FINDNEODEVICES)GetProcAddress(m_hDll_spy3, "icsneoFindNeoDevices");

	icsneoFindNeoDevices = (FINDNEODEVICES)GetProcAddress(m_hDll_spy3, "icsneoFindNeoDevices");
	icsneoOpenNeoDevice = (OPENNEODEVICE)GetProcAddress(m_hDll_spy3, "icsneoOpenNeoDevice");
	icsneoClosePort = (CLOSEPORT)GetProcAddress(m_hDll_spy3, "icsneoClosePort");
	icsneoFreeObject = (FREEOBJECT)GetProcAddress(m_hDll_spy3, "icsneoFreeObject");
	icsneoOpenPortEx = (OPENPORTEX)GetProcAddress(m_hDll_spy3, "icsneoOpenPortEx");
	icsneoEnableNetworkCom = (ENABLENETWORKCOM)GetProcAddress(m_hDll_spy3, "icsneoEnableNetworkCom");
	icsneoGetDLLVersion = (GETDLLVERSION)GetProcAddress(m_hDll_spy3, "icsneoGetDLLVersion");
	icsneoTxMessages = (TXMESSAGES)GetProcAddress(m_hDll_spy3, "icsneoTxMessages");
	icsneoGetMessages = (GETMESSAGES)GetProcAddress(m_hDll_spy3, "icsneoGetMessages");
	icsneoWaitForRxMessagesWithTimeOut = (WAITFORRXMSGS)GetProcAddress(m_hDll_spy3, "icsneoWaitForRxMessagesWithTimeOut");
	icsneoGetTimeStampForMsg = (GETTSFORMSG)GetProcAddress(m_hDll_spy3, "icsneoGetTimeStampForMsg");
	icsneoEnableNetworkRXQueue = (ENABLERXQUEUE)GetProcAddress(m_hDll_spy3, "icsneoEnableNetworkRXQueue");
	icsneoGetISO15765Status = (GETISO15765STATUS)GetProcAddress(m_hDll_spy3, "icsneoGetISO15765Status");
	icsneoSetISO15765RxParameters = (SETISO15765RXPARMS)GetProcAddress(m_hDll_spy3, "icsneoSetISO15765RxParameters");
	icsneoDownloadISO15765_2_TXScript = (DOWNLOADISO15765_2_TXSCRIPT)GetProcAddress(m_hDll_spy3, "icsneoDownloadISO15765_2_TXScript");
	icsneoClearISO15765_2_TxScript = (CLEARISO15765_2_TXSCRIPT)GetProcAddress(m_hDll_spy3, "icsneoClearISO15765_2_TxScript");


	icsneoGetConfiguration = (GETCONFIG)GetProcAddress(m_hDll_spy3, "icsneoGetConfiguration");
	icsneoSendConfiguration = (SENDCONFIG)GetProcAddress(m_hDll_spy3, "icsneoSendConfiguration");
	icsneoGetFireSettings = (GETFIRESETTINGS)GetProcAddress(m_hDll_spy3, "icsneoGetFireSettings");
	icsneoSetFireSettings = (SETFIRESETTINGS)GetProcAddress(m_hDll_spy3, "icsneoSetFireSettings");
	icsneoGetVCAN3Settings = (GETVCAN3SETTINGS)GetProcAddress(m_hDll_spy3, "icsneoGetVCAN3Settings");
	icsneoSetVCAN3Settings = (SETVCAN3SETTINGS)GetProcAddress(m_hDll_spy3, "icsneoSetVCAN3Settings");
	icsneoSetBitRate = (SETBITRATE)GetProcAddress(m_hDll_spy3, "icsneoSetBitRate");
	icsneoGetDeviceParameters = (GETDEVICEPARMS)GetProcAddress(m_hDll_spy3, "icsneoGetDeviceParameters");
	icsneoSetDeviceParameters = (SETDEVICEPARMS)GetProcAddress(m_hDll_spy3, "icsneoSetDeviceParameters");

	icsneoGetLastAPIError = (GETLASTAPIERROR)GetProcAddress(m_hDll_spy3, "icsneoGetLastAPIError");
	icsneoGetErrorMessages = (GETERRMSGS)GetProcAddress(m_hDll_spy3, "icsneoGetErrorMessages");
	icsneoGetErrorInfo = (GETERRORINFO)GetProcAddress(m_hDll_spy3, "icsneoGetErrorInfo");

	icsneoScriptLoad = (SCRIPTLOAD)GetProcAddress(m_hDll_spy3, "icsneoScriptLoad");
	icsneoScriptStart = (SCRIPTSTART)GetProcAddress(m_hDll_spy3, "icsneoScriptStart");
	icsneoScriptStop = (SCRIPTSTOP)GetProcAddress(m_hDll_spy3, "icsneoScriptStop");
	icsneoScriptClear = (SCRIPTCLEAR)GetProcAddress(m_hDll_spy3, "icsneoScriptClear");
	icsneoScriptStartFBlock = (SCRIPTSTARTFBLOCK)GetProcAddress(m_hDll_spy3, "icsneoScriptStartFBlock");
	icsneoScriptStopFBlock = (SCRIPTSTOPFBLOCK)GetProcAddress(m_hDll_spy3, "icsneoScriptStopFBlock");
	icsneoScriptGetFBlockStatus = (SCRIPTGETFBLOCKSTATUS)GetProcAddress(m_hDll_spy3, "icsneoScriptGetFBlockStatus");
	icsneoScriptGetScriptStatus = (SCRIPTGETSCRIPTSTATUS)GetProcAddress(m_hDll_spy3, "icsneoScriptGetScriptStatus");
	icsneoScriptReadAppSignal = (SCRIPTREADAPPSIGNAL)GetProcAddress(m_hDll_spy3, "icsneoScriptReadAppSignal");
	icsneoScriptWriteAppSignal = (SCRIPTWRITEAPPSIGNAL)GetProcAddress(m_hDll_spy3, "icsneoScriptWriteAppSignal");

	icsneoScriptReadRxMessage = (SCRIPTREADRXMESSAGE)GetProcAddress(m_hDll_spy3, "icsneoScriptReadRxMessage");
	icsneoScriptReadTxMessage = (SCRIPTREADTXMESSAGE)GetProcAddress(m_hDll_spy3, "icsneoScriptReadTxMessage");
	icsneoScriptWriteRxMessage = (SCRIPTWRITERXMESSAGE)GetProcAddress(m_hDll_spy3, "icsneoScriptWriteRxMessage");
	icsneoScriptWriteTxMessage = (SCRIPTWRITETXMESSAGE)GetProcAddress(m_hDll_spy3, "icsneoScriptWriteTxMessage");



	if (!icsneoFindNeoDevices || !icsneoOpenNeoDevice || !icsneoClosePort || !icsneoFreeObject || !icsneoOpenPortEx ||
		!icsneoEnableNetworkCom || !icsneoTxMessages || !icsneoGetMessages || !icsneoWaitForRxMessagesWithTimeOut ||
		!icsneoGetTimeStampForMsg || !icsneoEnableNetworkRXQueue || !icsneoGetISO15765Status ||
		!icsneoSetISO15765RxParameters || !icsneoGetConfiguration || !icsneoSendConfiguration ||
		!icsneoGetFireSettings || !icsneoSetFireSettings || !icsneoGetVCAN3Settings ||
		!icsneoSetVCAN3Settings || !icsneoSetBitRate || !icsneoGetDeviceParameters ||
		!icsneoSetDeviceParameters || !icsneoGetLastAPIError || !icsneoGetErrorMessages ||
		!icsneoGetErrorInfo || !icsneoScriptLoad || !icsneoScriptStart || !icsneoScriptStop ||
		!icsneoScriptClear || !icsneoScriptStartFBlock || !icsneoScriptStopFBlock ||
		!icsneoScriptGetFBlockStatus || !icsneoScriptGetScriptStatus || !icsneoScriptReadAppSignal ||
		!icsneoScriptWriteAppSignal || !icsneoScriptReadRxMessage || !icsneoScriptReadTxMessage ||
		!icsneoScriptWriteRxMessage || !icsneoScriptWriteTxMessage ||
		!icsneoGetDLLVersion || !icsneoDownloadISO15765_2_TXScript ||
		!icsneoClearISO15765_2_TxScript)
	{
		FreeLibrary(m_hDll_spy3);
		Display(u8"加载SPY3_API失败");
		return 0;
	}
	Display(u8"加载SPY3_API成功");


	return 1;
}

void PLinBootloader::FreshHW(void)
{
	HLINHW* pHWbuf = NULL;
	int HWCount;
	TLINError errcode;
	pHWbuf = (HLINHW*)malloc(1 * sizeof(HLINHW));
	GetAvailableHardware(pHWbuf, 0, &HWCount);
	if (HWCount == 0)
		HWCount = 16;
	pHWbuf = (HLINHW*)realloc(pHWbuf,HWCount * sizeof(HLINHW));
	if (pHWbuf == NULL)
	{
		pHWbuf = (HLINHW*)malloc(HWCount * sizeof(HLINHW));
	}
	errcode = GetAvailableHardware(pHWbuf, HWCount * sizeof(HLINHW), &HWCount);
	if (errcode != errOK)
	{
		Display(u8"未找到硬件");
		return ;
	}
	if (HWCount == 0)
	{
		ui.cbbSelectChenal->clear();
		ui.cbbSelectChenal->addItem(u8"未找到硬件");
		Display(u8"未找到硬件");
	}
	else
	{
		//void* pBufHWtype = malloc(50);
		int HWType,DevNum,Channel;
		AvailableHW = (AVAILABLE_HW*)malloc(HWCount * sizeof(AVAILABLE_HW));
		ui.cbbSelectChenal->clear();
		for (int HWnum = 0; HWnum < HWCount; HWnum++)
		{
			HLINHW HWtemp;
			QString devstr;
			HWtemp = pHWbuf[HWnum];
			
			GetHardwareParam(HWtemp, hwpType, &HWType, sizeof(int));
			GetHardwareParam(HWtemp, hwpDeviceNumber, &DevNum, sizeof(int));
			GetHardwareParam(HWtemp, hwpChannelNumber, &Channel, sizeof(int));

			switch (HWType)
			{
			case LIN_HW_TYPE_USB_PRO:
				devstr.append("PCAN-USB Pro");
				break;
			case LIN_HW_TYPE_USB_PRO_FD:
				devstr.append("PCAN-USB Pro FD");
				break;
			case LIN_HW_TYPE_PLIN_USB:
				devstr.append("PLIN-USB");
				break;
			default:
				devstr.append("Unknown");
				break;
			}
			devstr.append(" - dev.");
			devstr.append(QString::number(DevNum));
			devstr.append(", chan.");
			devstr.append(QString::number(Channel));
			ui.cbbSelectChenal->addItem(devstr);
			AvailableHW[HWnum].hLINHW = HWtemp;
		}
	}
}


void PLinBootloader::DoLINConnect(void)
{
	HLINHW HWtemp;
	DWORD result;
	unsigned long long filter;
	if (AvailableHW == NULL)
	{
		Display(u8"没有硬件");
		return;
	}
	RegisterClient(u8"PLIN", NULL, &m_hClient);
	if(ui.cbbSelectChenal->currentIndex() >= 0)
		HWtemp = AvailableHW[ui.cbbSelectChenal->currentIndex()].hLINHW;
	else
	{
		Display(u8"没有硬件");
		return;
	}
	result = ConnectClient(m_hClient, HWtemp);
	
	if (result != errOK)
	{
		Display(u8"连接失败");
		return;
	}
	m_hHW = HWtemp;
	InitializeHardware(m_hClient, HWtemp, modMaster, ui.cbbSelectBaudrate->currentText().toInt());
	filter = 0xFFFFFFFFFFFFFFFF;
	SetClientFilter(m_hClient, m_hHW, filter);
	GetClientFilter(m_hClient, m_hHW, &filter);
	//ui.textBrowser->append(QString::number(filter, 16));
	ui.btnStop->setEnabled(TRUE);
	ui.btnConnect->setEnabled(FALSE);
	Display(u8"连接成功");
}

void PLinBootloader::DoLINDisconnect(void)
{
	if (m_hHW != NULL && m_hClient != NULL)
	{
		DisconnectClient(m_hClient, m_hHW);
		RemoveClient(m_hClient);
		m_hClient = NULL;
		m_hHW = NULL;
	}
	ui.btnConnect->setEnabled(TRUE);
	ui.btnStop->setEnabled(FALSE);
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
	if (m_hClient == NULL)
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
	CalculateChecksum(&msg);
	Write(m_hClient, m_hHW, &msg);
}

void PLinBootloader::TransmitID(int id)
{
	TLINMsg msg;
	if (m_hClient == NULL)
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
	CalculateChecksum(&msg);
	Write(m_hClient, m_hHW, &msg);
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
	if (m_hClient == NULL)
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
	CalculateChecksum(&msg);
	Write(m_hClient, m_hHW, &msg);
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
		if (DID == 0xF194)
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
		else if (DID == 0xF192)
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
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}

	while (!(IsEmpty & errRcvQueueEmpty))
	{
		IsEmpty = Read(m_hClient, &RcvMsg);
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
	if (m_hClient == NULL)
	{
		Display(u8"硬件未连接");
		return;
	}

	while (!(IsEmpty & errRcvQueueEmpty))
	{
		IsEmpty = Read(m_hClient, &RcvMsg);
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

FARPROC PLinBootloader::GetFunction(LPSTR szName)
{
	// There is no DLL loaded
	//
	if (m_hDll == NULL)
		return NULL;

	// Gets the address of the given function in the loeaded DLL
	//
	return GetProcAddress(m_hDll, szName);
}

//	Public API functions
//
TLINError PLinBootloader::RegisterClient(LPSTR strName, DWORD hWnd, HLINCLIENT* hClient)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRegisterClient(strName, hWnd, hClient);
}

TLINError PLinBootloader::RemoveClient(HLINCLIENT hClient)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRemoveClient(hClient);
}

TLINError PLinBootloader::ConnectClient(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pConnectClient(hClient, hHw);
}

TLINError PLinBootloader::DisconnectClient(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pDisconnectClient(hClient, hHw);
}

TLINError PLinBootloader::ResetClient(HLINCLIENT hClient)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResetClient(hClient);
}

TLINError PLinBootloader::SetClientParam(HLINCLIENT hClient, WORD wParam, DWORD dwValue)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetClientParam(hClient, wParam, dwValue);
}

TLINError PLinBootloader::GetClientParam(HLINCLIENT hClient, WORD wParam, void* pBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetClientParam(hClient, wParam, pBuff, wBuffSize);
}

TLINError PLinBootloader::SetClientFilter(HLINCLIENT hClient, HLINHW hHw, unsigned __int64 iRcvMask)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetClientFilter(hClient, hHw, iRcvMask);
}

TLINError PLinBootloader::GetClientFilter(HLINCLIENT hClient, HLINHW hHw, unsigned __int64* pRcvMask)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetClientFilter(hClient, hHw, pRcvMask);
}

TLINError PLinBootloader::Read(HLINCLIENT hClient, TLINRcvMsg * pMsg)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRead(hClient, pMsg);
}

TLINError PLinBootloader::ReadMulti(HLINCLIENT hClient, TLINRcvMsg * pMsgBuff, int iMaxCount, int* pCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pReadMulti(hClient, pMsgBuff, iMaxCount, pCount);
}

TLINError PLinBootloader::Write(HLINCLIENT hClient, HLINHW hHw, TLINMsg * pMsg)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pWrite(hClient, hHw, pMsg);
}

TLINError PLinBootloader::InitializeHardware(HLINCLIENT hClient, HLINHW hHw, BYTE bMode, WORD wBaudrate)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pInitializeHardware(hClient, hHw, bMode, wBaudrate);
}

TLINError PLinBootloader::GetAvailableHardware(HLINHW * pBuff, WORD wBuffSize, int* pCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetAvailableHardware(pBuff, wBuffSize, pCount);
}

TLINError PLinBootloader::SetHardwareParam(HLINCLIENT hClient, HLINHW hHw, WORD wParam, void* pBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetHardwareParam(hClient, hHw, wParam, pBuff, wBuffSize);
}

TLINError PLinBootloader::GetHardwareParam(HLINHW hHw, WORD wParam, void* pBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetHardwareParam(hHw, wParam, pBuff, wBuffSize);
}

TLINError PLinBootloader::ResetHardware(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResetHardware(hClient, hHw);
}

TLINError PLinBootloader::ResetHardwareConfig(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResetHardwareConfig(hClient, hHw);
}

TLINError PLinBootloader::IdentifyHardware(HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pIdentifyHardware(hHw);
}

TLINError PLinBootloader::RegisterFrameId(HLINCLIENT hClient, HLINHW hHw, BYTE bFromFrameId, BYTE bToFrameId)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRegisterFrameId(hClient, hHw, bFromFrameId, bToFrameId);
}

TLINError PLinBootloader::SetFrameEntry(HLINCLIENT hClient, HLINHW hHw, TLINFrameEntry * pFrameEntry)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetFrameEntry(hClient, hHw, pFrameEntry);
}

TLINError PLinBootloader::GetFrameEntry(HLINHW hHw, TLINFrameEntry * pFrameEntry)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetFrameEntry(hHw, pFrameEntry);
}

TLINError PLinBootloader::UpdateByteArray(HLINCLIENT hClient, HLINHW hHw, BYTE bFrameId, BYTE bIndex, BYTE bLen, BYTE * pData)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pUpdateByteArray(hClient, hHw, bFrameId, bIndex, bLen, pData);
}

TLINError PLinBootloader::StartKeepAlive(HLINCLIENT hClient, HLINHW hHw, BYTE bFrameId, WORD wPeriod)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pStartKeepAlive(hClient, hHw, bFrameId, wPeriod);
}

TLINError PLinBootloader::SuspendKeepAlive(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSuspendKeepAlive(hClient, hHw);
}

TLINError PLinBootloader::ResumeKeepAlive(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResumeKeepAlive(hClient, hHw);
}

TLINError PLinBootloader::SetSchedule(HLINCLIENT hClient, HLINHW hHw, int iScheduleNumber, TLINScheduleSlot * pSchedule, int iSlotCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetSchedule(hClient, hHw, iScheduleNumber, pSchedule, iSlotCount);
}

TLINError PLinBootloader::GetSchedule(HLINHW hHw, int iScheduleNumber, TLINScheduleSlot * pScheduleBuff, int iMaxSlotCount, int* pSlotCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetSchedule(hHw, iScheduleNumber, pScheduleBuff, iMaxSlotCount, pSlotCount);
}

TLINError PLinBootloader::DeleteSchedule(HLINCLIENT hClient, HLINHW hHw, int iScheduleNumber)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pDeleteSchedule(hClient, hHw, iScheduleNumber);
}

TLINError PLinBootloader::SetScheduleBreakPoint(HLINCLIENT hClient, HLINHW hHw, int iBreakPointNumber, DWORD dwHandle)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetScheduleBreakPoint(hClient, hHw, iBreakPointNumber, dwHandle);
}

TLINError PLinBootloader::StartSchedule(HLINCLIENT hClient, HLINHW hHw, int iScheduleNumber)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pStartSchedule(hClient, hHw, iScheduleNumber);
}

TLINError PLinBootloader::SuspendSchedule(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSuspendSchedule(hClient, hHw);
}
TLINError PLinBootloader::ResumeSchedule(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResumeSchedule(hClient, hHw);
}

TLINError PLinBootloader::XmtWakeUp(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pXmtWakeUp(hClient, hHw);
}

TLINError PLinBootloader::StartAutoBaud(HLINCLIENT hClient, HLINHW hHw, WORD wTimeOut)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pStartAutoBaud(hClient, hHw, wTimeOut);
}

TLINError PLinBootloader::GetStatus(HLINHW hHw, TLINHardwareStatus * pStatusBuff)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetStatus(hHw, pStatusBuff);
}

TLINError PLinBootloader::CalculateChecksum(TLINMsg * pMsg)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pCalculateChecksum(pMsg);
}

TLINError PLinBootloader::GetVersion(TLINVersion * pVerBuff)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetVersion(pVerBuff);
}

TLINError PLinBootloader::GetVersionInfo(LPSTR strTextBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetVersionInfo(strTextBuff, wBuffSize);
}

TLINError PLinBootloader::GetErrorText(DWORD dwError, BYTE bLanguage, LPSTR strTextBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetErrorText(dwError, bLanguage, strTextBuff, wBuffSize);
}

TLINError PLinBootloader::GetPID(BYTE * pFrameId)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetPID(pFrameId);
}

TLINError PLinBootloader::GetTargetTime(HLINHW hHw, unsigned __int64* pTargetTime)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetTargetTime(hHw, pTargetTime);
}

TLINError PLinBootloader::SetResponseRemap(HLINCLIENT hClient, HLINHW hHw, BYTE * pRemapTab)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetResponseRemap(hClient, hHw, pRemapTab);
}


TLINError PLinBootloader::GetResponseRemap(HLINHW hHw, BYTE * pRemapTab)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetResponseRemap(hHw, pRemapTab);
}

TLINError PLinBootloader::GetSystemTime(unsigned __int64* pSystemTime)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetSystemTime(pSystemTime);
}