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
#include "SPY3_Driver.h"





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
	
	TCHAR* szErrorDescriptionShort;
	PLIN_DRIVER pd;
	SPY3_DRIVER sd;
	
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

	


	

	void Display(string s);

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
