#include "PLIN_Driver.h"


PLIN_DRIVER::PLIN_DRIVER()
{

}

PLIN_DRIVER::~PLIN_DRIVER(void)
{
	FreeLibrary(m_hDll);//释放DLL
}

int PLIN_DRIVER::LoadDLL(void)
{
	m_hDll = LoadLibrary(TEXT("PLinApi.dll"));
	if (m_hDll != NULL)
	{
		//this->Display(u8"加载DLL成功");
		m_bWasLoaded = 1;
		//return RET_OK;
	}
	else
	{
		//this->Display(u8"找不到DLL文件");
		m_bWasLoaded = 0;
		return RET_ERR;
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
		//Display(u8"加载API成功");
		return RET_OK;
	}
	else
	{
		//Display(u8"加载API失败");
		return RET_ERR;
	}
	

}


int PLIN_DRIVER::FreshHW(QList<QString>* HWList)
{
	HLINHW* pHWbuf = NULL;
	int HWCount;
	TLINError errcode;
	pHWbuf = (HLINHW*)malloc(1 * sizeof(HLINHW));
	GetAvailableHardware(pHWbuf, 0, &HWCount);
	if (HWCount == 0)
		HWCount = 16;
	pHWbuf = (HLINHW*)realloc(pHWbuf, HWCount * sizeof(HLINHW));
	if (pHWbuf == NULL)
	{
		pHWbuf = (HLINHW*)malloc(HWCount * sizeof(HLINHW));
	}
	errcode = GetAvailableHardware(pHWbuf, HWCount * sizeof(HLINHW), &HWCount);
	if (errcode != errOK || HWCount == 0)
	{
		//Display(u8"未找到硬件");
		return RET_ERR;
	}
	else
	{
		int HWType, DevNum, Channel;
		AvailableHW = (AVAILABLE_HW*)malloc(HWCount * sizeof(AVAILABLE_HW));
		HWList->clear();
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
			HWList->append(devstr);
			AvailableHW[HWnum].hLINHW = HWtemp;
		}

		return RET_OK;
	}
}

int PLIN_DRIVER::isConnect(void)
{
	if (m_hClient == NULL)
		return RET_ERR;
	else
		return RET_OK;
}


int PLIN_DRIVER::DoLINConnect(int index,int burdrate)
{
	HLINHW HWtemp;
	DWORD result;
	unsigned long long filter;
	if (AvailableHW == NULL)
	{
		//Display(u8"没有硬件");
		return RET_ERR;
	}
	RegisterClient(u8"PLIN", NULL, &m_hClient);
	HWtemp = AvailableHW[index].hLINHW;

	result = ConnectClient(m_hClient, HWtemp);

	if (result != errOK)
	{
		//Display(u8"连接失败");
		return RET_ERR;
	}
	m_hHW = HWtemp;
	InitializeHardware(m_hClient, HWtemp, modMaster, burdrate);
	filter = 0xFFFFFFFFFFFFFFFF;
	SetClientFilter(m_hClient, m_hHW, filter);
	GetClientFilter(m_hClient, m_hHW, &filter);



	return RET_OK;
}

void PLIN_DRIVER::DoLINDisconnect(void)
{
	if (m_hHW != NULL && m_hClient != NULL)
	{
		DisconnectClient(m_hClient, m_hHW);
		RemoveClient(m_hClient);
		m_hClient = NULL;
		m_hHW = NULL;
	}
	//ui.btnConnect->setEnabled(TRUE);
	//ui.btnStop->setEnabled(FALSE);
}



//	Public API functions
//
TLINError PLIN_DRIVER::RegisterClient(LPSTR strName, DWORD hWnd, HLINCLIENT* hClient)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRegisterClient(strName, hWnd, hClient);
}

TLINError PLIN_DRIVER::RemoveClient(HLINCLIENT hClient)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRemoveClient(hClient);
}

TLINError PLIN_DRIVER::ConnectClient(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pConnectClient(hClient, hHw);
}

TLINError PLIN_DRIVER::DisconnectClient(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pDisconnectClient(hClient, hHw);
}

TLINError PLIN_DRIVER::ResetClient(HLINCLIENT hClient)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResetClient(hClient);
}

TLINError PLIN_DRIVER::SetClientParam(HLINCLIENT hClient, WORD wParam, DWORD dwValue)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetClientParam(hClient, wParam, dwValue);
}

TLINError PLIN_DRIVER::GetClientParam(HLINCLIENT hClient, WORD wParam, void* pBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetClientParam(hClient, wParam, pBuff, wBuffSize);
}

TLINError PLIN_DRIVER::SetClientFilter(HLINCLIENT hClient, HLINHW hHw, unsigned __int64 iRcvMask)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetClientFilter(hClient, hHw, iRcvMask);
}

TLINError PLIN_DRIVER::GetClientFilter(HLINCLIENT hClient, HLINHW hHw, unsigned __int64* pRcvMask)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetClientFilter(hClient, hHw, pRcvMask);
}

TLINError PLIN_DRIVER::Read(HLINCLIENT hClient, TLINRcvMsg* pMsg)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRead(hClient, pMsg);
}

TLINError PLIN_DRIVER::ReadMulti(HLINCLIENT hClient, TLINRcvMsg* pMsgBuff, int iMaxCount, int* pCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pReadMulti(hClient, pMsgBuff, iMaxCount, pCount);
}

TLINError PLIN_DRIVER::Write(HLINCLIENT hClient, HLINHW hHw, TLINMsg* pMsg)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pWrite(hClient, hHw, pMsg);
}

TLINError PLIN_DRIVER::InitializeHardware(HLINCLIENT hClient, HLINHW hHw, BYTE bMode, WORD wBaudrate)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pInitializeHardware(hClient, hHw, bMode, wBaudrate);
}

TLINError PLIN_DRIVER::GetAvailableHardware(HLINHW* pBuff, WORD wBuffSize, int* pCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetAvailableHardware(pBuff, wBuffSize, pCount);
}

TLINError PLIN_DRIVER::SetHardwareParam(HLINCLIENT hClient, HLINHW hHw, WORD wParam, void* pBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetHardwareParam(hClient, hHw, wParam, pBuff, wBuffSize);
}

TLINError PLIN_DRIVER::GetHardwareParam(HLINHW hHw, WORD wParam, void* pBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetHardwareParam(hHw, wParam, pBuff, wBuffSize);
}

TLINError PLIN_DRIVER::ResetHardware(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResetHardware(hClient, hHw);
}

TLINError PLIN_DRIVER::ResetHardwareConfig(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResetHardwareConfig(hClient, hHw);
}

TLINError PLIN_DRIVER::IdentifyHardware(HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pIdentifyHardware(hHw);
}

TLINError PLIN_DRIVER::RegisterFrameId(HLINCLIENT hClient, HLINHW hHw, BYTE bFromFrameId, BYTE bToFrameId)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pRegisterFrameId(hClient, hHw, bFromFrameId, bToFrameId);
}

TLINError PLIN_DRIVER::SetFrameEntry(HLINCLIENT hClient, HLINHW hHw, TLINFrameEntry* pFrameEntry)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetFrameEntry(hClient, hHw, pFrameEntry);
}

TLINError PLIN_DRIVER::GetFrameEntry(HLINHW hHw, TLINFrameEntry* pFrameEntry)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetFrameEntry(hHw, pFrameEntry);
}

TLINError PLIN_DRIVER::UpdateByteArray(HLINCLIENT hClient, HLINHW hHw, BYTE bFrameId, BYTE bIndex, BYTE bLen, BYTE* pData)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pUpdateByteArray(hClient, hHw, bFrameId, bIndex, bLen, pData);
}

TLINError PLIN_DRIVER::StartKeepAlive(HLINCLIENT hClient, HLINHW hHw, BYTE bFrameId, WORD wPeriod)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pStartKeepAlive(hClient, hHw, bFrameId, wPeriod);
}

TLINError PLIN_DRIVER::SuspendKeepAlive(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSuspendKeepAlive(hClient, hHw);
}

TLINError PLIN_DRIVER::ResumeKeepAlive(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResumeKeepAlive(hClient, hHw);
}

TLINError PLIN_DRIVER::SetSchedule(HLINCLIENT hClient, HLINHW hHw, int iScheduleNumber, TLINScheduleSlot* pSchedule, int iSlotCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetSchedule(hClient, hHw, iScheduleNumber, pSchedule, iSlotCount);
}

TLINError PLIN_DRIVER::GetSchedule(HLINHW hHw, int iScheduleNumber, TLINScheduleSlot* pScheduleBuff, int iMaxSlotCount, int* pSlotCount)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetSchedule(hHw, iScheduleNumber, pScheduleBuff, iMaxSlotCount, pSlotCount);
}

TLINError PLIN_DRIVER::DeleteSchedule(HLINCLIENT hClient, HLINHW hHw, int iScheduleNumber)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pDeleteSchedule(hClient, hHw, iScheduleNumber);
}

TLINError PLIN_DRIVER::SetScheduleBreakPoint(HLINCLIENT hClient, HLINHW hHw, int iBreakPointNumber, DWORD dwHandle)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetScheduleBreakPoint(hClient, hHw, iBreakPointNumber, dwHandle);
}

TLINError PLIN_DRIVER::StartSchedule(HLINCLIENT hClient, HLINHW hHw, int iScheduleNumber)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pStartSchedule(hClient, hHw, iScheduleNumber);
}

TLINError PLIN_DRIVER::SuspendSchedule(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSuspendSchedule(hClient, hHw);
}
TLINError PLIN_DRIVER::ResumeSchedule(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pResumeSchedule(hClient, hHw);
}

TLINError PLIN_DRIVER::XmtWakeUp(HLINCLIENT hClient, HLINHW hHw)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pXmtWakeUp(hClient, hHw);
}

TLINError PLIN_DRIVER::StartAutoBaud(HLINCLIENT hClient, HLINHW hHw, WORD wTimeOut)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pStartAutoBaud(hClient, hHw, wTimeOut);
}

TLINError PLIN_DRIVER::GetStatus(HLINHW hHw, TLINHardwareStatus* pStatusBuff)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetStatus(hHw, pStatusBuff);
}

TLINError PLIN_DRIVER::CalculateChecksum(TLINMsg* pMsg)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pCalculateChecksum(pMsg);
}

TLINError PLIN_DRIVER::GetVersion(TLINVersion* pVerBuff)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetVersion(pVerBuff);
}

TLINError PLIN_DRIVER::GetVersionInfo(LPSTR strTextBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetVersionInfo(strTextBuff, wBuffSize);
}

TLINError PLIN_DRIVER::GetErrorText(DWORD dwError, BYTE bLanguage, LPSTR strTextBuff, WORD wBuffSize)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetErrorText(dwError, bLanguage, strTextBuff, wBuffSize);
}

TLINError PLIN_DRIVER::GetPID(BYTE* pFrameId)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetPID(pFrameId);
}

TLINError PLIN_DRIVER::GetTargetTime(HLINHW hHw, unsigned __int64* pTargetTime)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetTargetTime(hHw, pTargetTime);
}

TLINError PLIN_DRIVER::SetResponseRemap(HLINCLIENT hClient, HLINHW hHw, BYTE* pRemapTab)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pSetResponseRemap(hClient, hHw, pRemapTab);
}


TLINError PLIN_DRIVER::GetResponseRemap(HLINHW hHw, BYTE* pRemapTab)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetResponseRemap(hHw, pRemapTab);
}

TLINError PLIN_DRIVER::GetSystemTime(unsigned __int64* pSystemTime)
{
	if (!m_bWasLoaded)
		return errUnknown;

	return m_pGetSystemTime(pSystemTime);
}

FARPROC PLIN_DRIVER::GetFunction(LPSTR szName)
{
	// There is no DLL loaded
	//
	if (m_hDll == NULL)
		return NULL;

	// Gets the address of the given function in the loeaded DLL
	//
	return GetProcAddress(m_hDll, szName);
}

