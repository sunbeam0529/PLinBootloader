/********************************************************************************
** Form generated from reading UI file 'PLinBootloader.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

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
    QPushButton *btnDID_ReadSW;
    QPushButton *btnDID_ReadHW;
    QPushButton *btnDID_ReadModel;
    QPushButton *btnDID_ReadPartnum;
    QLabel *lbl_DIDSW;
    QLabel *lbl_DIDHW;
    QLabel *lbl_DIDMODEL;
    QLabel *lbl_DIDPART;
    QPushButton *btnDID_ReadBoot;
    QLabel *lbl_DIDBOOT;
    QPushButton *btn_BootMode;
    QPushButton *btn_AppMode;
    QPushButton *bnt_Unlock;
    QWidget *tab_3;
    QLineEdit *line_fileaddress;
    QLabel *lbl_lable_5;
    QPushButton *btnSelectAppFile;
    QPushButton *btnOneKeyBoot;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *lbl_DIDSW_2;
    QLabel *lbl_DIDBOOT_2;
    QLabel *lbl_lable_3;
    QLabel *lbl_lable_2;
    QLabel *lbl_DIDHW_2;
    QLabel *lbl_lable_4;
    QLabel *lbl_lable_1;
    QLabel *lbl_DIDSW_3;
    QWidget *tab_4;
    QLabel *label_6;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineID1;
    QLabel *label_5;
    QLineEdit *lineID2;
    QPushButton *btnErgodic;
    QTextBrowser *textBrowser;
    QPushButton *btnClear;

    void setupUi(QMainWindow *PLinBootloaderClass)
    {
        if (PLinBootloaderClass->objectName().isEmpty())
            PLinBootloaderClass->setObjectName(QString::fromUtf8("PLinBootloaderClass"));
        PLinBootloaderClass->resize(764, 378);
        QIcon icon;
        icon.addFile(QString::fromUtf8("E:/\346\226\207\346\241\243/\345\205\266\345\256\203\346\226\207\346\241\243/image/201820323009650610.png"), QSize(), QIcon::Normal, QIcon::Off);
        PLinBootloaderClass->setWindowIcon(icon);
        centralWidget = new QWidget(PLinBootloaderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 361, 351));
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbbSelectHW = new QComboBox(layoutWidget);
        cbbSelectHW->addItem(QString());
        cbbSelectHW->setObjectName(QString::fromUtf8("cbbSelectHW"));

        gridLayout->addWidget(cbbSelectHW, 0, 1, 1, 3);

        btnFresh = new QPushButton(layoutWidget);
        btnFresh->setObjectName(QString::fromUtf8("btnFresh"));

        gridLayout->addWidget(btnFresh, 0, 4, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
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
        btnDID_ReadSW = new QPushButton(tab_2);
        btnDID_ReadSW->setObjectName(QString::fromUtf8("btnDID_ReadSW"));
        btnDID_ReadSW->setGeometry(QRect(11, 21, 75, 23));
        btnDID_ReadHW = new QPushButton(tab_2);
        btnDID_ReadHW->setObjectName(QString::fromUtf8("btnDID_ReadHW"));
        btnDID_ReadHW->setGeometry(QRect(11, 60, 75, 23));
        btnDID_ReadModel = new QPushButton(tab_2);
        btnDID_ReadModel->setObjectName(QString::fromUtf8("btnDID_ReadModel"));
        btnDID_ReadModel->setGeometry(QRect(11, 177, 75, 23));
        btnDID_ReadPartnum = new QPushButton(tab_2);
        btnDID_ReadPartnum->setObjectName(QString::fromUtf8("btnDID_ReadPartnum"));
        btnDID_ReadPartnum->setGeometry(QRect(11, 138, 75, 23));
        lbl_DIDSW = new QLabel(tab_2);
        lbl_DIDSW->setObjectName(QString::fromUtf8("lbl_DIDSW"));
        lbl_DIDSW->setGeometry(QRect(92, 21, 171, 21));
        sizePolicy.setHeightForWidth(lbl_DIDSW->sizePolicy().hasHeightForWidth());
        lbl_DIDSW->setSizePolicy(sizePolicy);
        lbl_DIDSW->setFont(font);
        lbl_DIDSW->setStyleSheet(QString::fromUtf8("border-color: rgb(111, 111, 111);"));
        lbl_DIDHW = new QLabel(tab_2);
        lbl_DIDHW->setObjectName(QString::fromUtf8("lbl_DIDHW"));
        lbl_DIDHW->setGeometry(QRect(92, 60, 171, 21));
        sizePolicy.setHeightForWidth(lbl_DIDHW->sizePolicy().hasHeightForWidth());
        lbl_DIDHW->setSizePolicy(sizePolicy);
        lbl_DIDHW->setFont(font);
        lbl_DIDMODEL = new QLabel(tab_2);
        lbl_DIDMODEL->setObjectName(QString::fromUtf8("lbl_DIDMODEL"));
        lbl_DIDMODEL->setGeometry(QRect(92, 177, 171, 21));
        sizePolicy.setHeightForWidth(lbl_DIDMODEL->sizePolicy().hasHeightForWidth());
        lbl_DIDMODEL->setSizePolicy(sizePolicy);
        lbl_DIDMODEL->setFont(font);
        lbl_DIDPART = new QLabel(tab_2);
        lbl_DIDPART->setObjectName(QString::fromUtf8("lbl_DIDPART"));
        lbl_DIDPART->setGeometry(QRect(92, 138, 171, 21));
        sizePolicy.setHeightForWidth(lbl_DIDPART->sizePolicy().hasHeightForWidth());
        lbl_DIDPART->setSizePolicy(sizePolicy);
        lbl_DIDPART->setFont(font);
        btnDID_ReadBoot = new QPushButton(tab_2);
        btnDID_ReadBoot->setObjectName(QString::fromUtf8("btnDID_ReadBoot"));
        btnDID_ReadBoot->setGeometry(QRect(11, 99, 75, 23));
        lbl_DIDBOOT = new QLabel(tab_2);
        lbl_DIDBOOT->setObjectName(QString::fromUtf8("lbl_DIDBOOT"));
        lbl_DIDBOOT->setGeometry(QRect(92, 99, 171, 21));
        sizePolicy.setHeightForWidth(lbl_DIDBOOT->sizePolicy().hasHeightForWidth());
        lbl_DIDBOOT->setSizePolicy(sizePolicy);
        lbl_DIDBOOT->setFont(font);
        btn_BootMode = new QPushButton(tab_2);
        btn_BootMode->setObjectName(QString::fromUtf8("btn_BootMode"));
        btn_BootMode->setGeometry(QRect(100, 230, 75, 23));
        btn_AppMode = new QPushButton(tab_2);
        btn_AppMode->setObjectName(QString::fromUtf8("btn_AppMode"));
        btn_AppMode->setGeometry(QRect(10, 230, 75, 23));
        bnt_Unlock = new QPushButton(tab_2);
        bnt_Unlock->setObjectName(QString::fromUtf8("bnt_Unlock"));
        bnt_Unlock->setGeometry(QRect(190, 230, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        line_fileaddress = new QLineEdit(tab_3);
        line_fileaddress->setObjectName(QString::fromUtf8("line_fileaddress"));
        line_fileaddress->setGeometry(QRect(10, 40, 331, 20));
        lbl_lable_5 = new QLabel(tab_3);
        lbl_lable_5->setObjectName(QString::fromUtf8("lbl_lable_5"));
        lbl_lable_5->setGeometry(QRect(10, 10, 171, 21));
        sizePolicy.setHeightForWidth(lbl_lable_5->sizePolicy().hasHeightForWidth());
        lbl_lable_5->setSizePolicy(sizePolicy);
        lbl_lable_5->setFont(font);
        btnSelectAppFile = new QPushButton(tab_3);
        btnSelectAppFile->setObjectName(QString::fromUtf8("btnSelectAppFile"));
        btnSelectAppFile->setGeometry(QRect(250, 10, 75, 23));
        btnOneKeyBoot = new QPushButton(tab_3);
        btnOneKeyBoot->setObjectName(QString::fromUtf8("btnOneKeyBoot"));
        btnOneKeyBoot->setGeometry(QRect(80, 290, 191, 23));
        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 311, 131));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_DIDSW_2 = new QLabel(layoutWidget1);
        lbl_DIDSW_2->setObjectName(QString::fromUtf8("lbl_DIDSW_2"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_2->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_2->setSizePolicy(sizePolicy);
        lbl_DIDSW_2->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_2, 0, 1, 1, 1);

        lbl_DIDBOOT_2 = new QLabel(layoutWidget1);
        lbl_DIDBOOT_2->setObjectName(QString::fromUtf8("lbl_DIDBOOT_2"));
        sizePolicy.setHeightForWidth(lbl_DIDBOOT_2->sizePolicy().hasHeightForWidth());
        lbl_DIDBOOT_2->setSizePolicy(sizePolicy);
        lbl_DIDBOOT_2->setFont(font);

        gridLayout_2->addWidget(lbl_DIDBOOT_2, 2, 1, 1, 1);

        lbl_lable_3 = new QLabel(layoutWidget1);
        lbl_lable_3->setObjectName(QString::fromUtf8("lbl_lable_3"));
        sizePolicy.setHeightForWidth(lbl_lable_3->sizePolicy().hasHeightForWidth());
        lbl_lable_3->setSizePolicy(sizePolicy);
        lbl_lable_3->setFont(font);

        gridLayout_2->addWidget(lbl_lable_3, 2, 0, 1, 1);

        lbl_lable_2 = new QLabel(layoutWidget1);
        lbl_lable_2->setObjectName(QString::fromUtf8("lbl_lable_2"));
        sizePolicy.setHeightForWidth(lbl_lable_2->sizePolicy().hasHeightForWidth());
        lbl_lable_2->setSizePolicy(sizePolicy);
        lbl_lable_2->setFont(font);

        gridLayout_2->addWidget(lbl_lable_2, 1, 0, 1, 1);

        lbl_DIDHW_2 = new QLabel(layoutWidget1);
        lbl_DIDHW_2->setObjectName(QString::fromUtf8("lbl_DIDHW_2"));
        sizePolicy.setHeightForWidth(lbl_DIDHW_2->sizePolicy().hasHeightForWidth());
        lbl_DIDHW_2->setSizePolicy(sizePolicy);
        lbl_DIDHW_2->setFont(font);

        gridLayout_2->addWidget(lbl_DIDHW_2, 1, 1, 1, 1);

        lbl_lable_4 = new QLabel(layoutWidget1);
        lbl_lable_4->setObjectName(QString::fromUtf8("lbl_lable_4"));
        sizePolicy.setHeightForWidth(lbl_lable_4->sizePolicy().hasHeightForWidth());
        lbl_lable_4->setSizePolicy(sizePolicy);
        lbl_lable_4->setFont(font);

        gridLayout_2->addWidget(lbl_lable_4, 3, 0, 1, 1);

        lbl_lable_1 = new QLabel(layoutWidget1);
        lbl_lable_1->setObjectName(QString::fromUtf8("lbl_lable_1"));
        sizePolicy.setHeightForWidth(lbl_lable_1->sizePolicy().hasHeightForWidth());
        lbl_lable_1->setSizePolicy(sizePolicy);
        lbl_lable_1->setFont(font);

        gridLayout_2->addWidget(lbl_lable_1, 0, 0, 1, 1);

        lbl_DIDSW_3 = new QLabel(layoutWidget1);
        lbl_DIDSW_3->setObjectName(QString::fromUtf8("lbl_DIDSW_3"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_3->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_3->setSizePolicy(sizePolicy);
        lbl_DIDSW_3->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_3, 3, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 30, 31, 21));
        layoutWidget2 = new QWidget(tab_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 30, 261, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineID1 = new QLineEdit(layoutWidget2);
        lineID1->setObjectName(QString::fromUtf8("lineID1"));

        horizontalLayout->addWidget(lineID1);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        lineID2 = new QLineEdit(layoutWidget2);
        lineID2->setObjectName(QString::fromUtf8("lineID2"));

        horizontalLayout->addWidget(lineID2);

        btnErgodic = new QPushButton(layoutWidget2);
        btnErgodic->setObjectName(QString::fromUtf8("btnErgodic"));

        horizontalLayout->addWidget(btnErgodic);

        tabWidget->addTab(tab_4, QString());
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(380, 30, 371, 311));
        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(680, 340, 75, 23));
        PLinBootloaderClass->setCentralWidget(centralWidget);

        retranslateUi(PLinBootloaderClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PLinBootloaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *PLinBootloaderClass)
    {
        PLinBootloaderClass->setWindowTitle(QApplication::translate("PLinBootloaderClass", "PLinBootloader", nullptr));
        label->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266", nullptr));
        cbbSelectHW->setItemText(0, QApplication::translate("PLinBootloaderClass", "PEAK-PLIN", nullptr));

        btnFresh->setText(QApplication::translate("PLinBootloaderClass", "\345\210\267\346\226\260", nullptr));
        label_2->setText(QApplication::translate("PLinBootloaderClass", "\351\200\232\351\201\223", nullptr));
        label_3->setText(QApplication::translate("PLinBootloaderClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        cbbSelectBaudrate->setItemText(0, QApplication::translate("PLinBootloaderClass", "19200", nullptr));

        btnConnect->setText(QApplication::translate("PLinBootloaderClass", "\350\277\236\346\216\245", nullptr));
        btnStop->setText(QApplication::translate("PLinBootloaderClass", "\345\201\234\346\255\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266", nullptr));
        btnDID_ReadSW->setText(QApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        btnDID_ReadHW->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        btnDID_ReadModel->setText(QApplication::translate("PLinBootloaderClass", "\345\236\213\345\217\267", nullptr));
        btnDID_ReadPartnum->setText(QApplication::translate("PLinBootloaderClass", "\345\256\242\346\210\267\344\273\266\345\217\267", nullptr));
        lbl_DIDSW->setText(QString());
        lbl_DIDHW->setText(QString());
        lbl_DIDMODEL->setText(QString());
        lbl_DIDPART->setText(QString());
        btnDID_ReadBoot->setText(QApplication::translate("PLinBootloaderClass", "Boot\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDBOOT->setText(QString());
        btn_BootMode->setText(QApplication::translate("PLinBootloaderClass", "BootMode", nullptr));
        btn_AppMode->setText(QApplication::translate("PLinBootloaderClass", "AppMode", nullptr));
        bnt_Unlock->setText(QApplication::translate("PLinBootloaderClass", "\350\247\243\351\224\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PLinBootloaderClass", "\350\257\212\346\226\255", nullptr));
        lbl_lable_5->setText(QApplication::translate("PLinBootloaderClass", "\351\200\211\346\213\251app\346\226\207\344\273\266", nullptr));
        btnSelectAppFile->setText(QApplication::translate("PLinBootloaderClass", "...", nullptr));
        btnOneKeyBoot->setText(QApplication::translate("PLinBootloaderClass", "\344\270\200\351\224\256bootloader", nullptr));
        lbl_DIDSW_2->setText(QString());
        lbl_DIDBOOT_2->setText(QString());
        lbl_lable_3->setText(QApplication::translate("PLinBootloaderClass", "boot\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_lable_2->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDHW_2->setText(QString());
        lbl_lable_4->setText(QApplication::translate("PLinBootloaderClass", "\346\233\264\346\226\260\345\220\216\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_lable_1->setText(QApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDSW_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("PLinBootloaderClass", "bootloader", nullptr));
        label_6->setText(QApplication::translate("PLinBootloaderClass", "\351\201\215\345\216\206", nullptr));
        label_4->setText(QApplication::translate("PLinBootloaderClass", "\344\273\216", nullptr));
        lineID1->setText(QString());
        label_5->setText(QApplication::translate("PLinBootloaderClass", "\345\210\260", nullptr));
        btnErgodic->setText(QApplication::translate("PLinBootloaderClass", "\351\201\215\345\216\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("PLinBootloaderClass", "\346\265\213\350\257\225", nullptr));
        btnClear->setText(QApplication::translate("PLinBootloaderClass", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PLinBootloaderClass: public Ui_PLinBootloaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLINBOOTLOADER_H
