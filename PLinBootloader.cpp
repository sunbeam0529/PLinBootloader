#include "PLinBootloader.h"
#include <stdlib.h>
#include <windows.h>

PLinBootloader::PLinBootloader(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->Display(u8"加载成功"); 
	if (this->LoadDLL() == LOADDLL_ERR)
	{
		MessageBox(NULL, TEXT("Error: \"找不到PLinApi.dll!\""), TEXT("Error!"), MB_ICONERROR);
	}
	/*
	else
	{
		MessageBox(NULL, TEXT("加载DLL成功"), TEXT("Error!"), MB_ICONERROR);
	}
	*/
}


void PLinBootloader::Display(string s) 
{
	ui.textBrowser->append(QString::fromStdString(s));
	
}

void PLinBootloader::on_btnFresh_clicked(void)
{
	//this->Display(u8"加载成功");
	FreshHW();
}

void PLinBootloader::on_btnConnect_clicked(void)
{
	//this->Display(u8"加载成功");
	DoLINConnect();
}

void PLinBootloader::on_btnDID_ReadSW_clicked(void)
{
	this->Display(u8"加载成功");
}

void PLinBootloader::on_btnDID_ReadHW_clicked(void)
{
	this->Display(u8"加载成功");
}

void PLinBootloader::on_btnDID_ReadBoot_clicked(void)
{
	this->Display(u8"加载成功");
}

void PLinBootloader::on_btnDID_ReadPartnum_clicked(void)
{
	this->Display(u8"加载成功");
}


void PLinBootloader::on_btnSelectAppFile_clicked(void)
{
	this->Display(u8"加载成功");
}

void PLinBootloader::on_btnOneKeyBoot_clicked(void)
{
	this->Display(u8"加载成功");
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
	errcode = GetAvailableHardware(pHWbuf, HWCount * sizeof(HLINHW), &HWCount);
	if (errcode != errOK)
	{
		Display(u8"未找到硬件");
		return ;
	}
	if (HWCount == 0)
	{
		ui.cbbSelectHW->clear();
		ui.cbbSelectHW->addItem(u8"未找到硬件");
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
	InitializeHardware(m_hClient, HWtemp, modMaster, ui.cbbSelectBaudrate->currentText().toInt());
	// TODO: 增加滤波

}

void PLinBootloader::DoLINDisconnect(void)
{

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