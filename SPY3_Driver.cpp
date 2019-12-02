#include "SPY3_Driver.h"

SPY3_DRIVER::SPY3_DRIVER(void)
{

}
SPY3_DRIVER::~SPY3_DRIVER(void)
{

}

int SPY3_DRIVER::LoadDLL(void)
{
	m_hDll = LoadLibrary(TEXT("icsneo40.dll"));
	if (m_hDll != NULL)
	{
		//Display(u8"加载icsneo40.dll成功");
	}
	else
	{
		//Display(u8"加载icsneo40.dll失败");
		return RET_ERR;
	}
	//icsneoFindNeoDevices = (FINDNEODEVICES)GetProcAddress(m_hDll, "icsneoFindNeoDevices");

	icsneoFindNeoDevices = (FINDNEODEVICES)GetProcAddress(m_hDll, "icsneoFindNeoDevices");
	icsneoOpenNeoDevice = (OPENNEODEVICE)GetProcAddress(m_hDll, "icsneoOpenNeoDevice");
	icsneoClosePort = (CLOSEPORT)GetProcAddress(m_hDll, "icsneoClosePort");
	icsneoFreeObject = (FREEOBJECT)GetProcAddress(m_hDll, "icsneoFreeObject");
	icsneoOpenPortEx = (OPENPORTEX)GetProcAddress(m_hDll, "icsneoOpenPortEx");
	icsneoEnableNetworkCom = (ENABLENETWORKCOM)GetProcAddress(m_hDll, "icsneoEnableNetworkCom");
	icsneoGetDLLVersion = (GETDLLVERSION)GetProcAddress(m_hDll, "icsneoGetDLLVersion");
	icsneoTxMessages = (TXMESSAGES)GetProcAddress(m_hDll, "icsneoTxMessages");
	icsneoGetMessages = (GETMESSAGES)GetProcAddress(m_hDll, "icsneoGetMessages");
	icsneoWaitForRxMessagesWithTimeOut = (WAITFORRXMSGS)GetProcAddress(m_hDll, "icsneoWaitForRxMessagesWithTimeOut");
	icsneoGetTimeStampForMsg = (GETTSFORMSG)GetProcAddress(m_hDll, "icsneoGetTimeStampForMsg");
	icsneoEnableNetworkRXQueue = (ENABLERXQUEUE)GetProcAddress(m_hDll, "icsneoEnableNetworkRXQueue");
	icsneoGetISO15765Status = (GETISO15765STATUS)GetProcAddress(m_hDll, "icsneoGetISO15765Status");
	icsneoSetISO15765RxParameters = (SETISO15765RXPARMS)GetProcAddress(m_hDll, "icsneoSetISO15765RxParameters");
	icsneoDownloadISO15765_2_TXScript = (DOWNLOADISO15765_2_TXSCRIPT)GetProcAddress(m_hDll, "icsneoDownloadISO15765_2_TXScript");
	icsneoClearISO15765_2_TxScript = (CLEARISO15765_2_TXSCRIPT)GetProcAddress(m_hDll, "icsneoClearISO15765_2_TxScript");


	icsneoGetConfiguration = (GETCONFIG)GetProcAddress(m_hDll, "icsneoGetConfiguration");
	icsneoSendConfiguration = (SENDCONFIG)GetProcAddress(m_hDll, "icsneoSendConfiguration");
	icsneoGetFireSettings = (GETFIRESETTINGS)GetProcAddress(m_hDll, "icsneoGetFireSettings");
	icsneoSetFireSettings = (SETFIRESETTINGS)GetProcAddress(m_hDll, "icsneoSetFireSettings");
	icsneoGetVCAN3Settings = (GETVCAN3SETTINGS)GetProcAddress(m_hDll, "icsneoGetVCAN3Settings");
	icsneoSetVCAN3Settings = (SETVCAN3SETTINGS)GetProcAddress(m_hDll, "icsneoSetVCAN3Settings");
	icsneoSetBitRate = (SETBITRATE)GetProcAddress(m_hDll, "icsneoSetBitRate");
	icsneoGetDeviceParameters = (GETDEVICEPARMS)GetProcAddress(m_hDll, "icsneoGetDeviceParameters");
	icsneoSetDeviceParameters = (SETDEVICEPARMS)GetProcAddress(m_hDll, "icsneoSetDeviceParameters");

	icsneoGetLastAPIError = (GETLASTAPIERROR)GetProcAddress(m_hDll, "icsneoGetLastAPIError");
	icsneoGetErrorMessages = (GETERRMSGS)GetProcAddress(m_hDll, "icsneoGetErrorMessages");
	icsneoGetErrorInfo = (GETERRORINFO)GetProcAddress(m_hDll, "icsneoGetErrorInfo");

	icsneoScriptLoad = (SCRIPTLOAD)GetProcAddress(m_hDll, "icsneoScriptLoad");
	icsneoScriptStart = (SCRIPTSTART)GetProcAddress(m_hDll, "icsneoScriptStart");
	icsneoScriptStop = (SCRIPTSTOP)GetProcAddress(m_hDll, "icsneoScriptStop");
	icsneoScriptClear = (SCRIPTCLEAR)GetProcAddress(m_hDll, "icsneoScriptClear");
	icsneoScriptStartFBlock = (SCRIPTSTARTFBLOCK)GetProcAddress(m_hDll, "icsneoScriptStartFBlock");
	icsneoScriptStopFBlock = (SCRIPTSTOPFBLOCK)GetProcAddress(m_hDll, "icsneoScriptStopFBlock");
	icsneoScriptGetFBlockStatus = (SCRIPTGETFBLOCKSTATUS)GetProcAddress(m_hDll, "icsneoScriptGetFBlockStatus");
	icsneoScriptGetScriptStatus = (SCRIPTGETSCRIPTSTATUS)GetProcAddress(m_hDll, "icsneoScriptGetScriptStatus");
	icsneoScriptReadAppSignal = (SCRIPTREADAPPSIGNAL)GetProcAddress(m_hDll, "icsneoScriptReadAppSignal");
	icsneoScriptWriteAppSignal = (SCRIPTWRITEAPPSIGNAL)GetProcAddress(m_hDll, "icsneoScriptWriteAppSignal");

	icsneoScriptReadRxMessage = (SCRIPTREADRXMESSAGE)GetProcAddress(m_hDll, "icsneoScriptReadRxMessage");
	icsneoScriptReadTxMessage = (SCRIPTREADTXMESSAGE)GetProcAddress(m_hDll, "icsneoScriptReadTxMessage");
	icsneoScriptWriteRxMessage = (SCRIPTWRITERXMESSAGE)GetProcAddress(m_hDll, "icsneoScriptWriteRxMessage");
	icsneoScriptWriteTxMessage = (SCRIPTWRITETXMESSAGE)GetProcAddress(m_hDll, "icsneoScriptWriteTxMessage");



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
		FreeLibrary(m_hDll);
		//Display(u8"加载SPY3_API失败");
		return RET_ERR;
	}
	//Display(u8"加载SPY3_API成功");


	return RET_OK;
}

int SPY3_DRIVER::FreshHW(QList<QString> *HWList)
{
	int iResult;
	NeoDevice ndNeoToOpen;
	int iNumberOfDevices;

	iNumberOfDevices = 1;
	iResult = icsneoFindNeoDevices(65535, &ndNeoToOpen, &iNumberOfDevices);

	if (iResult == false || iNumberOfDevices < 1)
	{
		return RET_ERR;
	}


}