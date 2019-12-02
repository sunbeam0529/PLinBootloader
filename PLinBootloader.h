#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PLinBootloader.h"
#include "PLinApi.h"
#include "icsnVC40.h"
#include <string>
#include <QQueue>
#include <QDateTime>
#include "qcustomplot.h"
#include "PLIN_Driver.h"


//spy3
//Basic Functions
typedef int(__stdcall* FINDNEODEVICES)(unsigned long DeviceTypes, NeoDevice* pNeoDevice, int* pNumDevices);
typedef int(__stdcall* OPENNEODEVICE)(NeoDevice* pNeoDevice, int* hObject, unsigned char* bNetworkIDs, int bConfigRead, int bSyncToPC);
typedef int(__stdcall* CLOSEPORT)(int hObject, int* pNumberOfErrors);
typedef void(__stdcall* FREEOBJECT)(int hObject);
typedef int(__stdcall* OPENPORTEX)(int lPortNumber, int lPortType, int lDriverType, int lIPAddressMSB, int lIPAddressLSBOrBaudRate,int bConfigRead, unsigned char* bNetworkID, int* hObject);

//Message Functions
typedef int(__stdcall* GETMESSAGES)(int hObject, icsSpyMessage* pMsg, int* pNumberOfMessages, int* pNumberOfErrors);
typedef int(__stdcall* TXMESSAGES)(int hObject, icsSpyMessage* pMsg, int lNetworkID, int lNumMessages);
typedef int(__stdcall* WAITFORRXMSGS)(int hObject, unsigned int iTimeOut);
typedef int(__stdcall* ENABLERXQUEUE)(int hObject, int iEnable);
typedef int(__stdcall* GETTSFORMSG)(int hObject, icsSpyMessage* pMsg, double* pTimeStamp);
typedef void(__stdcall* GETISO15765STATUS)(int hObject, int lNetwork, int lClearTxStatus,int lClearRxStatus, int* lTxStatus, int* lRxStatus);
typedef void(__stdcall* SETISO15765RXPARMS)(int hObject, int lNetwork, int lEnable,spyFilterLong* pFF_CFMsgFilter, icsSpyMessage* pTxMsg,int lCFTimeOutMs, int lFlowCBlockSize,int lUsesExtendedAddressing, int lUseHardwareIfPresent);
typedef int(__stdcall* DOWNLOADISO15765_2_TXSCRIPT)(int hObject, unsigned int NetworkID);
typedef int(__stdcall* CLEARISO15765_2_TXSCRIPT)(int hObject);
typedef int(__stdcall* TXISO15765_2_MESSAGE)(int hObject, stCM_ISO157652_TxMessage* pTxMessage);

//Device Functions
typedef int(__stdcall* GETCONFIG)(int hObject, unsigned char* pData, int* lNumBytes);
typedef int(__stdcall* SENDCONFIG)(int hObject, unsigned char* pData, int lNumBytes);
typedef int(__stdcall* GETFIRESETTINGS)(int hObject, SFireSettings* pSettings, int iNumBytes);
typedef int(__stdcall* SETFIRESETTINGS)(int hObject, SFireSettings* pSettings, int iNumBytes, int bSaveToEEPROM);
typedef int(__stdcall* GETVCAN3SETTINGS)(int hObject, SVCAN3Settings* pSettings, int iNumBytes);
typedef int(__stdcall* SETVCAN3SETTINGS)(int hObject, SVCAN3Settings* pSettings, int iNumBytes, int bSaveToEEPROM);
typedef int(__stdcall* SETBITRATE)(int hObject, int BitRate, int NetworkID);
typedef int(__stdcall* GETDEVICEPARMS)(int hObject, char* pParameter, char* pValues, short ValuesLength);
typedef int(__stdcall* SETDEVICEPARMS)(int hObject, char* pParmValue, int* pErrorIndex, int bSaveToEEPROM);

//Error Functions
typedef int(__stdcall* GETLASTAPIERROR)(int hObject, unsigned long* pErrorNumber);
typedef int(__stdcall* GETERRMSGS)(int hObject, int* pErrorMsgs, int* pNumberOfErrors);
typedef int(__stdcall* GETERRORINFO)(int lErrorNumber, TCHAR* szErrorDescriptionShort,TCHAR* szErrorDescriptionLong, int* lMaxLengthShort,int* lMaxLengthLong, int* lErrorSeverity, int* lRestartNeeded);

//General Utility Functions
typedef int(__stdcall* VALIDATEHOBJECT)(int hObject);
typedef int(__stdcall* GETDLLVERSION)(void);
typedef int(__stdcall* GETSERIALNUMBER)(int hObject, unsigned int* iSerialNumber);
typedef int(__stdcall* STARTSOCKSERVER)(int hObject, int iPort);
typedef int(__stdcall* STOPSOCKSERVER)(int hObject);

//CoreMini Script functions
typedef int(__stdcall* SCRIPTSTART)(int hObject, int iLocation);
typedef int(__stdcall* SCRIPTSTOP)(int hObject);
typedef int(__stdcall* SCRIPTLOAD)(int hObject, const unsigned char* bin, unsigned long len_bytes, int iLocation);
typedef int(__stdcall* SCRIPTCLEAR)(int hObject, int iLocation);
typedef int(__stdcall* SCRIPTSTARTFBLOCK)(int hObject, unsigned int fb_index);
typedef int(__stdcall* SCRIPTGETFBLOCKSTATUS)(int hObject, unsigned int fb_index, int* piRunStatus);
typedef int(__stdcall* SCRIPTSTOPFBLOCK)(int hObject, unsigned int fb_index);
typedef int(__stdcall* SCRIPTGETSCRIPTSTATUS)(int hObject, int* piStatus);
typedef int(__stdcall* SCRIPTREADAPPSIGNAL)(int hObject, unsigned int iIndex, double* dValue);
typedef int(__stdcall* SCRIPTWRITEAPPSIGNAL)(int hObject, unsigned int iIndex, double dValue);
typedef int(__stdcall* SCRIPTREADRXMESSAGE)(int hObject, unsigned int iIndex,icsSpyMessage* pRxMessageMask, icsSpyMessage* pRxMessageValue);
typedef int(__stdcall* SCRIPTREADTXMESSAGE)(int hObject, unsigned int iIndex, icsSpyMessage* pTxMessage);
typedef int(__stdcall* SCRIPTWRITERXMESSAGE)(int hObject, unsigned int iIndex,const icsSpyMessage* pRxMessageMask, const icsSpyMessage* pRxMessageValue);
typedef int(__stdcall* SCRIPTWRITETXMESSAGE)(int hObject, unsigned int iIndex, const icsSpyMessage* pTxMessage);
typedef int(__stdcall* SCRIPTREADISO15765TXMESSAGE)(int hObject, unsigned int iIndex, stCM_ISO157652_TxMessage* pTxMessage);
typedef int(__stdcall* SCRIPTWRITEISO15765TXMESSAGE)(int hObject, unsigned int iIndex, const stCM_ISO157652_TxMessage* pTxMessage);


//Deprecated (but still suppored in the DLL)
typedef int(__stdcall* OPENPORTEX)(int lPortSerialNumber, int lPortType, int lDriverType,int lIPAddressMSB, int lIPAddressLSBOrBaudRate, int bConfigRead,unsigned char* bNetworkID, int* hObject);
typedef int(__stdcall* OPENPORT)(int lPortNumber, int lPortType, int lDriverType,unsigned char* bNetworkID, unsigned char* bSCPIDs, int* hObject);
typedef int(__stdcall* ENABLENETWORKCOM)(int hObject, int Enable);
typedef int(__stdcall* FINDCOMDEVICES)(int lDriverType, int lGetSerialNumbers, int lStopAtFirst, int lUSBCommOnly,int* p_lDeviceTypes, int* p_lComPorts, int* p_lSerialNumbers, int* lNumDevices);





using namespace std;

#define LOADDLL_OK	1
#define LOADDLL_ERR 0



class PLinBootloader : public QMainWindow
{
	Q_OBJECT

public:
	PLinBootloader(QWidget *parent = Q_NULLPTR);
	~PLinBootloader(void);
	QList<QString>*HWList;

	

private slots:
	void on_btnFresh_clicked(void);
	void on_btnConnect_clicked(void);
	void on_btnStop_clicked(void);
	void on_btnClear_clicked(void);
	void on_btnDID_ReadSW_clicked(void);
	void on_btnDID_ReadHW_clicked(void);
	void on_btnDID_ReadBoot_clicked(void);
	void on_btnDID_ReadPartnum_clicked(void);
	void on_btnDID_ReadModel_clicked(void);
	void on_btn_AppMode_clicked(void);
	void on_btn_BootMode_clicked(void);
	void on_bnt_Unlock_clicked(void);
	void on_btnSelectAppFile_clicked(void);
	void on_btnOneKeyBoot_clicked(void);
	void on_btnReadData_clicked(void);
	void on_btnReadDataStop_clicked(void);
	void on_btnReadPara_clicked(void);
	void on_btnWritePara_clicked(void);
	void on_btnErgodic_clicked(void);
	void onTimeOut00(void);
	void onSwitchButton_Clicked(void);

private:
	
	HINSTANCE m_hDll_spy3 = NULL;
	
	NeoDevice * m_hspy3_Client = NULL;
	PLIN_DRIVER pd;

	
	QQueue<QByteArray *> AppStack;
	QQueue<INT32> AddressStack;
	QQueue<int> LenStack;
	QTimer* timer;
	int total, position;
	char BootState;
	QCustomPlot* customPlot;
	int datatime;
	Ui::PLinBootloaderClass ui;
	QVector<double> x, y0, y1;
	QList<double>baselinedata, rawdata;

	

	//Basic Functions
	FINDNEODEVICES icsneoFindNeoDevices;
	OPENNEODEVICE icsneoOpenNeoDevice;
	CLOSEPORT icsneoClosePort;
	FREEOBJECT icsneoFreeObject;
	OPENPORTEX icsneoOpenPortEx;

	//Message Functions
	GETMESSAGES icsneoGetMessages;
	TXMESSAGES icsneoTxMessages;
	WAITFORRXMSGS icsneoWaitForRxMessagesWithTimeOut;
	GETTSFORMSG icsneoGetTimeStampForMsg;
	ENABLERXQUEUE icsneoEnableNetworkRXQueue;
	GETISO15765STATUS icsneoGetISO15765Status;
	SETISO15765RXPARMS icsneoSetISO15765RxParameters;
	ENABLENETWORKCOM icsneoEnableNetworkCom;
	DOWNLOADISO15765_2_TXSCRIPT icsneoDownloadISO15765_2_TXScript;
	CLEARISO15765_2_TXSCRIPT icsneoClearISO15765_2_TxScript;


	//Device Functions
	GETCONFIG icsneoGetConfiguration;
	SENDCONFIG icsneoSendConfiguration;
	GETFIRESETTINGS icsneoGetFireSettings;
	SETFIRESETTINGS icsneoSetFireSettings;
	GETVCAN3SETTINGS icsneoGetVCAN3Settings;
	SETVCAN3SETTINGS icsneoSetVCAN3Settings;
	SETBITRATE icsneoSetBitRate;
	GETDEVICEPARMS icsneoGetDeviceParameters;
	SETDEVICEPARMS icsneoSetDeviceParameters;

	//Error Functions
	GETLASTAPIERROR icsneoGetLastAPIError;
	GETERRMSGS icsneoGetErrorMessages;
	GETERRORINFO icsneoGetErrorInfo;

	//General Utility Functions
	VALIDATEHOBJECT icsneoValidateHObject;
	GETDLLVERSION icsneoGetDLLVersion;
	GETSERIALNUMBER icsneoGetSerialNumber;
	STARTSOCKSERVER icsneoStartSockServer;
	STOPSOCKSERVER icsneoStopSockServer;

	//CoreMini Functions
	SCRIPTLOAD icsneoScriptLoad;
	SCRIPTSTART icsneoScriptStart;
	SCRIPTSTOP icsneoScriptStop;
	SCRIPTCLEAR icsneoScriptClear;
	SCRIPTSTARTFBLOCK icsneoScriptStartFBlock;
	SCRIPTSTOPFBLOCK icsneoScriptStopFBlock;
	SCRIPTGETFBLOCKSTATUS icsneoScriptGetFBlockStatus;
	SCRIPTGETSCRIPTSTATUS icsneoScriptGetScriptStatus;
	SCRIPTREADAPPSIGNAL icsneoScriptReadAppSignal;
	SCRIPTWRITEAPPSIGNAL icsneoScriptWriteAppSignal;
	SCRIPTREADRXMESSAGE icsneoScriptReadRxMessage;
	SCRIPTREADTXMESSAGE icsneoScriptReadTxMessage;
	SCRIPTWRITERXMESSAGE icsneoScriptWriteRxMessage;
	SCRIPTWRITETXMESSAGE icsneoScriptWriteTxMessage;

	

	void Display(string s);

	

	int LoadDLL_spy3(void);

	void ProcessS19File(QString File);

	void TransmitBlock(char* data, int len, int blockid);

	void Write3C(BYTE* buf);

	void TransmitID(int id);

	int CalculatePID(int id);

	void Transmit3DHead(void);

	void Read3D(void);

	int Wait3D(BYTE* data, int times);

	void ProcessDiag(BYTE* buffer);

	void putdata(BYTE* src, BYTE* dst, int len);

	void putdata(QByteArray src, int start, BYTE* dst, int len);

	void ReadMsg(void);

	void ReadMsg(BYTE* data);

	

	

};
