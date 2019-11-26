/********************************************************************************
** Form generated from reading UI file 'PLinBootloader.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLINBOOTLOADER_H
#define UI_PLINBOOTLOADER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "lightbutton.h"
#include "qcustomplot.h"
#include "switchbutton.h"

QT_BEGIN_NAMESPACE

class Ui_PLinBootloaderClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cbbSelectHW;
    QPushButton *btnFresh;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *cbbSelectChenal;
    QComboBox *cbbSelectBaudrate;
    QPushButton *btnConnect;
    QPushButton *btnStop;
    QWidget *tab_2;
    QPushButton *btn_BootMode;
    QPushButton *btn_AppMode;
    QPushButton *bnt_Unlock;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QPushButton *btnDID_ReadSW;
    QPushButton *btnDID_ReadBoot;
    QPushButton *btnDID_ReadHW;
    QLabel *lbl_DIDHW;
    QLabel *lbl_DIDPART;
    QLabel *lbl_DIDSW;
    QLabel *lbl_DIDBOOT;
    QPushButton *btnDID_ReadModel;
    QPushButton *btnDID_ReadPartnum;
    QLabel *lbl_DIDMODEL;
    QWidget *tab_3;
    QLineEdit *line_fileaddress;
    QLabel *lbl_lable_5;
    QPushButton *btnSelectAppFile;
    QPushButton *btnOneKeyBoot;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *lbl_DIDSW_2;
    QLabel *lbl_DIDBOOT_2;
    QLabel *lbl_lable_3;
    QLabel *lbl_lable_2;
    QLabel *lbl_DIDHW_2;
    QLabel *lbl_lable_4;
    QLabel *lbl_lable_1;
    QLabel *lbl_DIDSW_3;
    QProgressBar *progressBar;
    QWidget *tab_4;
    QLabel *label_6;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineID1;
    QLabel *label_5;
    QLineEdit *lineID2;
    QPushButton *btnErgodic;
    SwitchButton *switchButton;
    LightButton *lightButton;
    QWidget *tab_5;
    QLabel *label_7;
    QPushButton *btnReadData;
    QSpinBox *spinBox;
    QPushButton *btnReadPara;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QComboBox *cnnFrequency;
    QLabel *label_9;
    QSpinBox *spnResolution;
    QLabel *label_10;
    QSpinBox *spnMIDAC;
    QLabel *label_11;
    QSpinBox *spnCIDAC;
    QLabel *label_12;
    QSpinBox *spnFingerTH;
    QLabel *label_13;
    QSpinBox *spnNoiseTH;
    QLabel *label_14;
    QSpinBox *spnHysteresis;
    QPushButton *btnReadDataStop;
    QPushButton *btnWritePara;
    QLCDNumber *lcdNumber;
    QTextBrowser *textBrowser;
    QPushButton *btnClear;
    QCustomPlot *widget;

    void setupUi(QMainWindow *PLinBootloaderClass)
    {
        if (PLinBootloaderClass->objectName().isEmpty())
            PLinBootloaderClass->setObjectName(QString::fromUtf8("PLinBootloaderClass"));
        PLinBootloaderClass->resize(750, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PLinBootloaderClass->sizePolicy().hasHeightForWidth());
        PLinBootloaderClass->setSizePolicy(sizePolicy);
        PLinBootloaderClass->setMinimumSize(QSize(750, 350));
        PLinBootloaderClass->setMaximumSize(QSize(750, 350));
        QIcon icon;
        icon.addFile(QString::fromUtf8("E:/\346\226\207\346\241\243/\345\205\266\345\256\203\346\226\207\346\241\243/image/201820323009650610.png"), QSize(), QIcon::Normal, QIcon::Off);
        PLinBootloaderClass->setWindowIcon(icon);
        centralWidget = new QWidget(PLinBootloaderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 361, 331));
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 341, 121));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbbSelectHW = new QComboBox(layoutWidget);
        cbbSelectHW->addItem(QString());
        cbbSelectHW->addItem(QString());
        cbbSelectHW->setObjectName(QString::fromUtf8("cbbSelectHW"));

        gridLayout->addWidget(cbbSelectHW, 0, 1, 1, 3);

        btnFresh = new QPushButton(layoutWidget);
        btnFresh->setObjectName(QString::fromUtf8("btnFresh"));

        gridLayout->addWidget(btnFresh, 0, 4, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cbbSelectChenal = new QComboBox(layoutWidget);
        cbbSelectChenal->setObjectName(QString::fromUtf8("cbbSelectChenal"));

        gridLayout->addWidget(cbbSelectChenal, 1, 1, 1, 4);

        cbbSelectBaudrate = new QComboBox(layoutWidget);
        cbbSelectBaudrate->addItem(QString());
        cbbSelectBaudrate->setObjectName(QString::fromUtf8("cbbSelectBaudrate"));

        gridLayout->addWidget(cbbSelectBaudrate, 2, 1, 1, 2);

        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        gridLayout->addWidget(btnConnect, 2, 3, 1, 1);

        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        gridLayout->addWidget(btnStop, 2, 4, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        btn_BootMode = new QPushButton(tab_2);
        btn_BootMode->setObjectName(QString::fromUtf8("btn_BootMode"));
        btn_BootMode->setGeometry(QRect(100, 230, 75, 23));
        btn_AppMode = new QPushButton(tab_2);
        btn_AppMode->setObjectName(QString::fromUtf8("btn_AppMode"));
        btn_AppMode->setGeometry(QRect(10, 230, 75, 23));
        bnt_Unlock = new QPushButton(tab_2);
        bnt_Unlock->setObjectName(QString::fromUtf8("bnt_Unlock"));
        bnt_Unlock->setGeometry(QRect(190, 230, 75, 23));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 331, 197));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(20);
        gridLayout_3->setVerticalSpacing(10);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        btnDID_ReadSW = new QPushButton(layoutWidget1);
        btnDID_ReadSW->setObjectName(QString::fromUtf8("btnDID_ReadSW"));

        gridLayout_3->addWidget(btnDID_ReadSW, 0, 0, 1, 1);

        btnDID_ReadBoot = new QPushButton(layoutWidget1);
        btnDID_ReadBoot->setObjectName(QString::fromUtf8("btnDID_ReadBoot"));

        gridLayout_3->addWidget(btnDID_ReadBoot, 2, 0, 1, 1);

        btnDID_ReadHW = new QPushButton(layoutWidget1);
        btnDID_ReadHW->setObjectName(QString::fromUtf8("btnDID_ReadHW"));

        gridLayout_3->addWidget(btnDID_ReadHW, 1, 0, 1, 1);

        lbl_DIDHW = new QLabel(layoutWidget1);
        lbl_DIDHW->setObjectName(QString::fromUtf8("lbl_DIDHW"));
        sizePolicy1.setHeightForWidth(lbl_DIDHW->sizePolicy().hasHeightForWidth());
        lbl_DIDHW->setSizePolicy(sizePolicy1);
        lbl_DIDHW->setFont(font);
        lbl_DIDHW->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(lbl_DIDHW, 1, 1, 1, 1);

        lbl_DIDPART = new QLabel(layoutWidget1);
        lbl_DIDPART->setObjectName(QString::fromUtf8("lbl_DIDPART"));
        sizePolicy1.setHeightForWidth(lbl_DIDPART->sizePolicy().hasHeightForWidth());
        lbl_DIDPART->setSizePolicy(sizePolicy1);
        lbl_DIDPART->setFont(font);
        lbl_DIDPART->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(lbl_DIDPART, 3, 1, 1, 1);

        lbl_DIDSW = new QLabel(layoutWidget1);
        lbl_DIDSW->setObjectName(QString::fromUtf8("lbl_DIDSW"));
        sizePolicy1.setHeightForWidth(lbl_DIDSW->sizePolicy().hasHeightForWidth());
        lbl_DIDSW->setSizePolicy(sizePolicy1);
        lbl_DIDSW->setFont(font);
        lbl_DIDSW->setStyleSheet(QString::fromUtf8("border-color: rgb(111, 111, 111);"));
        lbl_DIDSW->setFrameShape(QFrame::StyledPanel);
        lbl_DIDSW->setFrameShadow(QFrame::Plain);

        gridLayout_3->addWidget(lbl_DIDSW, 0, 1, 1, 1);

        lbl_DIDBOOT = new QLabel(layoutWidget1);
        lbl_DIDBOOT->setObjectName(QString::fromUtf8("lbl_DIDBOOT"));
        sizePolicy1.setHeightForWidth(lbl_DIDBOOT->sizePolicy().hasHeightForWidth());
        lbl_DIDBOOT->setSizePolicy(sizePolicy1);
        lbl_DIDBOOT->setFont(font);
        lbl_DIDBOOT->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(lbl_DIDBOOT, 2, 1, 1, 1);

        btnDID_ReadModel = new QPushButton(layoutWidget1);
        btnDID_ReadModel->setObjectName(QString::fromUtf8("btnDID_ReadModel"));

        gridLayout_3->addWidget(btnDID_ReadModel, 4, 0, 1, 1);

        btnDID_ReadPartnum = new QPushButton(layoutWidget1);
        btnDID_ReadPartnum->setObjectName(QString::fromUtf8("btnDID_ReadPartnum"));

        gridLayout_3->addWidget(btnDID_ReadPartnum, 3, 0, 1, 1);

        lbl_DIDMODEL = new QLabel(layoutWidget1);
        lbl_DIDMODEL->setObjectName(QString::fromUtf8("lbl_DIDMODEL"));
        sizePolicy1.setHeightForWidth(lbl_DIDMODEL->sizePolicy().hasHeightForWidth());
        lbl_DIDMODEL->setSizePolicy(sizePolicy1);
        lbl_DIDMODEL->setFont(font);
        lbl_DIDMODEL->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(lbl_DIDMODEL, 4, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 5);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        line_fileaddress = new QLineEdit(tab_3);
        line_fileaddress->setObjectName(QString::fromUtf8("line_fileaddress"));
        line_fileaddress->setGeometry(QRect(10, 40, 331, 20));
        lbl_lable_5 = new QLabel(tab_3);
        lbl_lable_5->setObjectName(QString::fromUtf8("lbl_lable_5"));
        lbl_lable_5->setGeometry(QRect(10, 10, 171, 21));
        sizePolicy1.setHeightForWidth(lbl_lable_5->sizePolicy().hasHeightForWidth());
        lbl_lable_5->setSizePolicy(sizePolicy1);
        lbl_lable_5->setFont(font);
        btnSelectAppFile = new QPushButton(tab_3);
        btnSelectAppFile->setObjectName(QString::fromUtf8("btnSelectAppFile"));
        btnSelectAppFile->setGeometry(QRect(250, 10, 75, 23));
        btnOneKeyBoot = new QPushButton(tab_3);
        btnOneKeyBoot->setObjectName(QString::fromUtf8("btnOneKeyBoot"));
        btnOneKeyBoot->setGeometry(QRect(80, 270, 191, 23));
        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 70, 311, 131));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_DIDSW_2 = new QLabel(layoutWidget2);
        lbl_DIDSW_2->setObjectName(QString::fromUtf8("lbl_DIDSW_2"));
        sizePolicy1.setHeightForWidth(lbl_DIDSW_2->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_2->setSizePolicy(sizePolicy1);
        lbl_DIDSW_2->setFont(font);
        lbl_DIDSW_2->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(lbl_DIDSW_2, 0, 1, 1, 1);

        lbl_DIDBOOT_2 = new QLabel(layoutWidget2);
        lbl_DIDBOOT_2->setObjectName(QString::fromUtf8("lbl_DIDBOOT_2"));
        sizePolicy1.setHeightForWidth(lbl_DIDBOOT_2->sizePolicy().hasHeightForWidth());
        lbl_DIDBOOT_2->setSizePolicy(sizePolicy1);
        lbl_DIDBOOT_2->setFont(font);
        lbl_DIDBOOT_2->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(lbl_DIDBOOT_2, 2, 1, 1, 1);

        lbl_lable_3 = new QLabel(layoutWidget2);
        lbl_lable_3->setObjectName(QString::fromUtf8("lbl_lable_3"));
        sizePolicy1.setHeightForWidth(lbl_lable_3->sizePolicy().hasHeightForWidth());
        lbl_lable_3->setSizePolicy(sizePolicy1);
        lbl_lable_3->setFont(font);

        gridLayout_2->addWidget(lbl_lable_3, 2, 0, 1, 1);

        lbl_lable_2 = new QLabel(layoutWidget2);
        lbl_lable_2->setObjectName(QString::fromUtf8("lbl_lable_2"));
        sizePolicy1.setHeightForWidth(lbl_lable_2->sizePolicy().hasHeightForWidth());
        lbl_lable_2->setSizePolicy(sizePolicy1);
        lbl_lable_2->setFont(font);

        gridLayout_2->addWidget(lbl_lable_2, 1, 0, 1, 1);

        lbl_DIDHW_2 = new QLabel(layoutWidget2);
        lbl_DIDHW_2->setObjectName(QString::fromUtf8("lbl_DIDHW_2"));
        sizePolicy1.setHeightForWidth(lbl_DIDHW_2->sizePolicy().hasHeightForWidth());
        lbl_DIDHW_2->setSizePolicy(sizePolicy1);
        lbl_DIDHW_2->setFont(font);
        lbl_DIDHW_2->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(lbl_DIDHW_2, 1, 1, 1, 1);

        lbl_lable_4 = new QLabel(layoutWidget2);
        lbl_lable_4->setObjectName(QString::fromUtf8("lbl_lable_4"));
        sizePolicy1.setHeightForWidth(lbl_lable_4->sizePolicy().hasHeightForWidth());
        lbl_lable_4->setSizePolicy(sizePolicy1);
        lbl_lable_4->setFont(font);

        gridLayout_2->addWidget(lbl_lable_4, 3, 0, 1, 1);

        lbl_lable_1 = new QLabel(layoutWidget2);
        lbl_lable_1->setObjectName(QString::fromUtf8("lbl_lable_1"));
        sizePolicy1.setHeightForWidth(lbl_lable_1->sizePolicy().hasHeightForWidth());
        lbl_lable_1->setSizePolicy(sizePolicy1);
        lbl_lable_1->setFont(font);

        gridLayout_2->addWidget(lbl_lable_1, 0, 0, 1, 1);

        lbl_DIDSW_3 = new QLabel(layoutWidget2);
        lbl_DIDSW_3->setObjectName(QString::fromUtf8("lbl_DIDSW_3"));
        sizePolicy1.setHeightForWidth(lbl_DIDSW_3->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_3->setSizePolicy(sizePolicy1);
        lbl_DIDSW_3->setFont(font);
        lbl_DIDSW_3->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(lbl_DIDSW_3, 3, 1, 1, 1);

        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 220, 311, 23));
        progressBar->setValue(0);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 30, 31, 21));
        layoutWidget3 = new QWidget(tab_4);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(80, 30, 261, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineID1 = new QLineEdit(layoutWidget3);
        lineID1->setObjectName(QString::fromUtf8("lineID1"));

        horizontalLayout->addWidget(lineID1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        lineID2 = new QLineEdit(layoutWidget3);
        lineID2->setObjectName(QString::fromUtf8("lineID2"));

        horizontalLayout->addWidget(lineID2);

        btnErgodic = new QPushButton(layoutWidget3);
        btnErgodic->setObjectName(QString::fromUtf8("btnErgodic"));

        horizontalLayout->addWidget(btnErgodic);

        switchButton = new SwitchButton(tab_4);
        switchButton->setObjectName(QString::fromUtf8("switchButton"));
        switchButton->setGeometry(QRect(90, 120, 60, 30));
        switchButton->setChecked(false);
        lightButton = new LightButton(tab_4);
        lightButton->setObjectName(QString::fromUtf8("lightButton"));
        lightButton->setGeometry(QRect(20, 110, 51, 41));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 71, 21));
        btnReadData = new QPushButton(tab_5);
        btnReadData->setObjectName(QString::fromUtf8("btnReadData"));
        btnReadData->setGeometry(QRect(180, 20, 75, 23));
        spinBox = new QSpinBox(tab_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(90, 20, 71, 21));
        btnReadPara = new QPushButton(tab_5);
        btnReadPara->setObjectName(QString::fromUtf8("btnReadPara"));
        btnReadPara->setGeometry(QRect(180, 50, 75, 23));
        layoutWidget4 = new QWidget(tab_5);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 90, 211, 178));
        gridLayout_4 = new QGridLayout(layoutWidget4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        cnnFrequency = new QComboBox(layoutWidget4);
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->addItem(QString());
        cnnFrequency->setObjectName(QString::fromUtf8("cnnFrequency"));

        gridLayout_4->addWidget(cnnFrequency, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 0, 1, 1);

        spnResolution = new QSpinBox(layoutWidget4);
        spnResolution->setObjectName(QString::fromUtf8("spnResolution"));
        spnResolution->setMinimum(6);
        spnResolution->setMaximum(12);

        gridLayout_4->addWidget(spnResolution, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 2, 0, 1, 1);

        spnMIDAC = new QSpinBox(layoutWidget4);
        spnMIDAC->setObjectName(QString::fromUtf8("spnMIDAC"));
        spnMIDAC->setMaximum(255);

        gridLayout_4->addWidget(spnMIDAC, 2, 1, 1, 1);

        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 3, 0, 1, 1);

        spnCIDAC = new QSpinBox(layoutWidget4);
        spnCIDAC->setObjectName(QString::fromUtf8("spnCIDAC"));
        spnCIDAC->setMaximum(255);

        gridLayout_4->addWidget(spnCIDAC, 3, 1, 1, 1);

        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 4, 0, 1, 1);

        spnFingerTH = new QSpinBox(layoutWidget4);
        spnFingerTH->setObjectName(QString::fromUtf8("spnFingerTH"));

        gridLayout_4->addWidget(spnFingerTH, 4, 1, 1, 1);

        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 5, 0, 1, 1);

        spnNoiseTH = new QSpinBox(layoutWidget4);
        spnNoiseTH->setObjectName(QString::fromUtf8("spnNoiseTH"));
        spnNoiseTH->setMaximum(99);

        gridLayout_4->addWidget(spnNoiseTH, 5, 1, 1, 1);

        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 6, 0, 1, 1);

        spnHysteresis = new QSpinBox(layoutWidget4);
        spnHysteresis->setObjectName(QString::fromUtf8("spnHysteresis"));

        gridLayout_4->addWidget(spnHysteresis, 6, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 2);
        btnReadDataStop = new QPushButton(tab_5);
        btnReadDataStop->setObjectName(QString::fromUtf8("btnReadDataStop"));
        btnReadDataStop->setGeometry(QRect(260, 20, 75, 23));
        btnWritePara = new QPushButton(tab_5);
        btnWritePara->setObjectName(QString::fromUtf8("btnWritePara"));
        btnWritePara->setGeometry(QRect(250, 250, 75, 23));
        lcdNumber = new QLCDNumber(tab_5);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(280, 100, 64, 23));
        lcdNumber->setFrameShape(QFrame::Box);
        tabWidget->addTab(tab_5, QString());
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(380, 30, 361, 281));
        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(660, 320, 75, 23));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(380, 30, 361, 121));
        PLinBootloaderClass->setCentralWidget(centralWidget);

        retranslateUi(PLinBootloaderClass);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(PLinBootloaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *PLinBootloaderClass)
    {
        PLinBootloaderClass->setWindowTitle(QCoreApplication::translate("PLinBootloaderClass", "PLinBootloader", nullptr));
        label->setText(QCoreApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266", nullptr));
        cbbSelectHW->setItemText(0, QCoreApplication::translate("PLinBootloaderClass", "PEAK-PLIN", nullptr));
        cbbSelectHW->setItemText(1, QCoreApplication::translate("PLinBootloaderClass", "SPY3", nullptr));

        btnFresh->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\210\267\346\226\260", nullptr));
        label_2->setText(QCoreApplication::translate("PLinBootloaderClass", "\351\200\232\351\201\223", nullptr));
        label_3->setText(QCoreApplication::translate("PLinBootloaderClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        cbbSelectBaudrate->setItemText(0, QCoreApplication::translate("PLinBootloaderClass", "19200", nullptr));

        btnConnect->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\277\236\346\216\245", nullptr));
        btnStop->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\201\234\346\255\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266", nullptr));
        btn_BootMode->setText(QCoreApplication::translate("PLinBootloaderClass", "BootMode", nullptr));
        btn_AppMode->setText(QCoreApplication::translate("PLinBootloaderClass", "AppMode", nullptr));
        bnt_Unlock->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\247\243\351\224\201", nullptr));
        btnDID_ReadSW->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        btnDID_ReadBoot->setText(QCoreApplication::translate("PLinBootloaderClass", "Boot\347\211\210\346\234\254\345\217\267", nullptr));
        btnDID_ReadHW->setText(QCoreApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDHW->setText(QString());
        lbl_DIDPART->setText(QString());
        lbl_DIDSW->setText(QString());
        lbl_DIDBOOT->setText(QString());
        btnDID_ReadModel->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\236\213\345\217\267", nullptr));
        btnDID_ReadPartnum->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\256\242\346\210\267\344\273\266\345\217\267", nullptr));
        lbl_DIDMODEL->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("PLinBootloaderClass", "\350\257\212\346\226\255", nullptr));
        lbl_lable_5->setText(QCoreApplication::translate("PLinBootloaderClass", "\351\200\211\346\213\251app\346\226\207\344\273\266", nullptr));
        btnSelectAppFile->setText(QCoreApplication::translate("PLinBootloaderClass", "...", nullptr));
        btnOneKeyBoot->setText(QCoreApplication::translate("PLinBootloaderClass", "\344\270\200\351\224\256bootloader", nullptr));
        lbl_DIDSW_2->setText(QString());
        lbl_DIDBOOT_2->setText(QString());
        lbl_lable_3->setText(QCoreApplication::translate("PLinBootloaderClass", "boot\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_lable_2->setText(QCoreApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDHW_2->setText(QString());
        lbl_lable_4->setText(QCoreApplication::translate("PLinBootloaderClass", "\346\233\264\346\226\260\345\220\216\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_lable_1->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDSW_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("PLinBootloaderClass", "bootloader", nullptr));
        label_6->setText(QCoreApplication::translate("PLinBootloaderClass", "\351\201\215\345\216\206", nullptr));
        label_4->setText(QCoreApplication::translate("PLinBootloaderClass", "\344\273\216", nullptr));
        lineID1->setText(QString());
        label_5->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\210\260", nullptr));
        btnErgodic->setText(QCoreApplication::translate("PLinBootloaderClass", "\351\201\215\345\216\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("PLinBootloaderClass", "\346\265\213\350\257\225", nullptr));
        label_7->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\247\246\346\221\270\346\214\211\351\224\256ID", nullptr));
        btnReadData->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        btnReadPara->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\257\273\345\217\202\346\225\260", nullptr));
        label_8->setText(QCoreApplication::translate("PLinBootloaderClass", "\351\242\221\347\216\207", nullptr));
        cnnFrequency->setItemText(0, QCoreApplication::translate("PLinBootloaderClass", "6000", nullptr));
        cnnFrequency->setItemText(1, QCoreApplication::translate("PLinBootloaderClass", "3000", nullptr));
        cnnFrequency->setItemText(2, QCoreApplication::translate("PLinBootloaderClass", "1500", nullptr));
        cnnFrequency->setItemText(3, QCoreApplication::translate("PLinBootloaderClass", "750", nullptr));
        cnnFrequency->setItemText(4, QCoreApplication::translate("PLinBootloaderClass", "375", nullptr));
        cnnFrequency->setItemText(5, QCoreApplication::translate("PLinBootloaderClass", "187.5", nullptr));
        cnnFrequency->setItemText(6, QCoreApplication::translate("PLinBootloaderClass", "93.75", nullptr));
        cnnFrequency->setItemText(7, QCoreApplication::translate("PLinBootloaderClass", "46.88", nullptr));

        label_9->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\210\206\350\276\250\347\216\207", nullptr));
        label_10->setText(QCoreApplication::translate("PLinBootloaderClass", "M_IDAC", nullptr));
        label_11->setText(QCoreApplication::translate("PLinBootloaderClass", "C_IDAC", nullptr));
        label_12->setText(QCoreApplication::translate("PLinBootloaderClass", "\346\211\213\346\214\207\351\230\210\345\200\274", nullptr));
        label_13->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\231\252\345\243\260\351\230\210\345\200\274", nullptr));
        label_14->setText(QCoreApplication::translate("PLinBootloaderClass", "\350\277\237\346\273\236", nullptr));
        btnReadDataStop->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\201\234\346\255\242", nullptr));
        btnWritePara->setText(QCoreApplication::translate("PLinBootloaderClass", "\345\206\231\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("PLinBootloaderClass", "\350\247\246\346\221\270\345\217\202\346\225\260", nullptr));
        btnClear->setText(QCoreApplication::translate("PLinBootloaderClass", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PLinBootloaderClass: public Ui_PLinBootloaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLINBOOTLOADER_H
