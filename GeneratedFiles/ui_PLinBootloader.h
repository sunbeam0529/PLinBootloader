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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
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
    QPushButton *btnConnect;
    QComboBox *cbbSelectChenal;
    QComboBox *cbbSelectBaudrate;
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
    QWidget *tab_3;
    QLineEdit *lineEdit;
    QLabel *lbl_DIDSW_6;
    QPushButton *btnSelectAppFile;
    QPushButton *btnOneKeyBoot;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *lbl_DIDSW_2;
    QLabel *lbl_DIDBOOT_2;
    QLabel *lbl_DIDSW_11;
    QLabel *lbl_DIDSW_7;
    QLabel *lbl_DIDHW_2;
    QLabel *lbl_DIDSW_9;
    QLabel *lbl_DIDSW_8;
    QLabel *lbl_DIDSW_3;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *PLinBootloaderClass)
    {
        if (PLinBootloaderClass->objectName().isEmpty())
            PLinBootloaderClass->setObjectName(QString::fromUtf8("PLinBootloaderClass"));
        PLinBootloaderClass->resize(764, 378);
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

        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        gridLayout->addWidget(btnConnect, 2, 4, 1, 1);

        cbbSelectChenal = new QComboBox(layoutWidget);
        cbbSelectChenal->setObjectName(QString::fromUtf8("cbbSelectChenal"));

        gridLayout->addWidget(cbbSelectChenal, 1, 1, 1, 4);

        cbbSelectBaudrate = new QComboBox(layoutWidget);
        cbbSelectBaudrate->addItem(QString());
        cbbSelectBaudrate->setObjectName(QString::fromUtf8("cbbSelectBaudrate"));

        gridLayout->addWidget(cbbSelectBaudrate, 2, 1, 1, 2);

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
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 331, 20));
        lbl_DIDSW_6 = new QLabel(tab_3);
        lbl_DIDSW_6->setObjectName(QString::fromUtf8("lbl_DIDSW_6"));
        lbl_DIDSW_6->setGeometry(QRect(10, 10, 171, 21));
        sizePolicy.setHeightForWidth(lbl_DIDSW_6->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_6->setSizePolicy(sizePolicy);
        lbl_DIDSW_6->setFont(font);
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

        lbl_DIDSW_11 = new QLabel(layoutWidget1);
        lbl_DIDSW_11->setObjectName(QString::fromUtf8("lbl_DIDSW_11"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_11->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_11->setSizePolicy(sizePolicy);
        lbl_DIDSW_11->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_11, 2, 0, 1, 1);

        lbl_DIDSW_7 = new QLabel(layoutWidget1);
        lbl_DIDSW_7->setObjectName(QString::fromUtf8("lbl_DIDSW_7"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_7->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_7->setSizePolicy(sizePolicy);
        lbl_DIDSW_7->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_7, 1, 0, 1, 1);

        lbl_DIDHW_2 = new QLabel(layoutWidget1);
        lbl_DIDHW_2->setObjectName(QString::fromUtf8("lbl_DIDHW_2"));
        sizePolicy.setHeightForWidth(lbl_DIDHW_2->sizePolicy().hasHeightForWidth());
        lbl_DIDHW_2->setSizePolicy(sizePolicy);
        lbl_DIDHW_2->setFont(font);

        gridLayout_2->addWidget(lbl_DIDHW_2, 1, 1, 1, 1);

        lbl_DIDSW_9 = new QLabel(layoutWidget1);
        lbl_DIDSW_9->setObjectName(QString::fromUtf8("lbl_DIDSW_9"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_9->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_9->setSizePolicy(sizePolicy);
        lbl_DIDSW_9->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_9, 3, 0, 1, 1);

        lbl_DIDSW_8 = new QLabel(layoutWidget1);
        lbl_DIDSW_8->setObjectName(QString::fromUtf8("lbl_DIDSW_8"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_8->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_8->setSizePolicy(sizePolicy);
        lbl_DIDSW_8->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_8, 0, 0, 1, 1);

        lbl_DIDSW_3 = new QLabel(layoutWidget1);
        lbl_DIDSW_3->setObjectName(QString::fromUtf8("lbl_DIDSW_3"));
        sizePolicy.setHeightForWidth(lbl_DIDSW_3->sizePolicy().hasHeightForWidth());
        lbl_DIDSW_3->setSizePolicy(sizePolicy);
        lbl_DIDSW_3->setFont(font);

        gridLayout_2->addWidget(lbl_DIDSW_3, 3, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(380, 30, 371, 331));
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
        btnConnect->setText(QApplication::translate("PLinBootloaderClass", "\350\277\236\346\216\245", nullptr));
        cbbSelectBaudrate->setItemText(0, QApplication::translate("PLinBootloaderClass", "19200", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266", nullptr));
        btnDID_ReadSW->setText(QApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        btnDID_ReadHW->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        btnDID_ReadModel->setText(QApplication::translate("PLinBootloaderClass", "\345\236\213\345\217\267", nullptr));
        btnDID_ReadPartnum->setText(QApplication::translate("PLinBootloaderClass", "\345\256\242\346\210\267\344\273\266\345\217\267", nullptr));
        lbl_DIDSW->setText(QApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267-------------", nullptr));
        lbl_DIDHW->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267-------------", nullptr));
        lbl_DIDMODEL->setText(QApplication::translate("PLinBootloaderClass", "\345\236\213\345\217\267-------------", nullptr));
        lbl_DIDPART->setText(QApplication::translate("PLinBootloaderClass", "\345\256\242\346\210\267\344\273\266\345\217\267-------------", nullptr));
        btnDID_ReadBoot->setText(QApplication::translate("PLinBootloaderClass", "Boot\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDBOOT->setText(QApplication::translate("PLinBootloaderClass", "boot\347\211\210\346\234\254\345\217\267-------------", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PLinBootloaderClass", "\350\257\212\346\226\255", nullptr));
        lbl_DIDSW_6->setText(QApplication::translate("PLinBootloaderClass", "\351\200\211\346\213\251app\346\226\207\344\273\266", nullptr));
        btnSelectAppFile->setText(QApplication::translate("PLinBootloaderClass", "...", nullptr));
        btnOneKeyBoot->setText(QApplication::translate("PLinBootloaderClass", "\344\270\200\351\224\256bootloader", nullptr));
        lbl_DIDSW_2->setText(QApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267-------------", nullptr));
        lbl_DIDBOOT_2->setText(QApplication::translate("PLinBootloaderClass", "boot\347\211\210\346\234\254\345\217\267-------------", nullptr));
        lbl_DIDSW_11->setText(QApplication::translate("PLinBootloaderClass", "boot\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDSW_7->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDHW_2->setText(QApplication::translate("PLinBootloaderClass", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267-------------", nullptr));
        lbl_DIDSW_9->setText(QApplication::translate("PLinBootloaderClass", "\346\233\264\346\226\260\345\220\216\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDSW_8->setText(QApplication::translate("PLinBootloaderClass", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267", nullptr));
        lbl_DIDSW_3->setText(QApplication::translate("PLinBootloaderClass", "\345\256\242\346\210\267\344\273\266\345\217\267-------------", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("PLinBootloaderClass", "bootloader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PLinBootloaderClass: public Ui_PLinBootloaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLINBOOTLOADER_H
