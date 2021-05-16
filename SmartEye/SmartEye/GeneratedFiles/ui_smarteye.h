/********************************************************************************
** Form generated from reading UI file 'smarteye.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTEYE_H
#define UI_SMARTEYE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SmartEyeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QCheckBox *colormapPointCheckBox;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLineEdit *maxdepthlineEdit;
    QLabel *label_12;
    QLineEdit *mindepthlineEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_5;
    QLineEdit *CYlineEdit;
    QLineEdit *k2lineEdit;
    QLineEdit *FXlineEdit;
    QLabel *label_5;
    QLineEdit *pointFilterEdit;
    QLineEdit *k1lineEdit;
    QLabel *label_8;
    QLineEdit *CXlineEdit;
    QLabel *label_15;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *FYlineEdit;
    QSlider *pointSizeSlider;
    QPushButton *pclBtn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QLabel *statelabel;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *IplineEdit;
    QLabel *label_2;
    QLineEdit *PortlineEdit;
    QPushButton *connectButton;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLabel *label_19;
    QSpinBox *offsetSpinBox;
    QLineEdit *FramelineEdit;
    QLabel *label_17;
    QLabel *label_13;
    QLineEdit *xlineEdit;
    QLineEdit *disLineEdit;
    QLabel *label_18;
    QLabel *label_14;
    QLineEdit *ylineEdit;
    QLineEdit *depthlineEdit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *Savebutton;
    QLabel *savestatelabel;
    QCheckBox *DepthImgMultiSave;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *savePcdButton;
    QLabel *savePCDStateLable;
    QCheckBox *PclImgMultiSave;
    QCheckBox *HFlip;
    QCheckBox *VFlip;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QLineEdit *IntegrationtimeHDRlineEdit;
    QCheckBox *checkBoxHDR;
    QLabel *label_16;
    QLineEdit *IntegrationtimelineEdit;
    QCheckBox *checkBoxSetABS;
    QLineEdit *setAmplineEdit;
    QCheckBox *checkBoxAmp;
    QCheckBox *checkBoxDRNU;
    QLabel *label_9;
    QLabel *label_20;
    QLineEdit *setMaxAmplineEdit;
    QLabel *label_21;
    QCheckBox *checkBoxCalibration;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *pointCloudDock;
    QWidget *dockWidgetContents_7;
    QGridLayout *gridLayout_12;
    QVTKWidget *screen;
    QDockWidget *imageDock;
    QWidget *dockWidgetContents_9;
    QVBoxLayout *verticalLayout;
    QLabel *Img_label;
    QDockWidget *ampDock;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_9;
    QLabel *amp_label;

    void setupUi(QMainWindow *SmartEyeClass)
    {
        if (SmartEyeClass->objectName().isEmpty())
            SmartEyeClass->setObjectName(QStringLiteral("SmartEyeClass"));
        SmartEyeClass->resize(886, 1025);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SmartEye/Resource/exe.png"), QSize(), QIcon::Normal, QIcon::Off);
        SmartEyeClass->setWindowIcon(icon);
        centralWidget = new QWidget(SmartEyeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_11 = new QGridLayout(centralWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        colormapPointCheckBox = new QCheckBox(groupBox_4);
        colormapPointCheckBox->setObjectName(QStringLiteral("colormapPointCheckBox"));
        colormapPointCheckBox->setChecked(true);
        colormapPointCheckBox->setTristate(false);

        gridLayout_8->addWidget(colormapPointCheckBox, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        maxdepthlineEdit = new QLineEdit(groupBox_4);
        maxdepthlineEdit->setObjectName(QStringLiteral("maxdepthlineEdit"));

        gridLayout_2->addWidget(maxdepthlineEdit, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        mindepthlineEdit = new QLineEdit(groupBox_4);
        mindepthlineEdit->setObjectName(QStringLiteral("mindepthlineEdit"));

        gridLayout_2->addWidget(mindepthlineEdit, 1, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        CYlineEdit = new QLineEdit(groupBox_2);
        CYlineEdit->setObjectName(QStringLiteral("CYlineEdit"));

        gridLayout_5->addWidget(CYlineEdit, 3, 1, 1, 1);

        k2lineEdit = new QLineEdit(groupBox_2);
        k2lineEdit->setObjectName(QStringLiteral("k2lineEdit"));

        gridLayout_5->addWidget(k2lineEdit, 5, 1, 1, 1);

        FXlineEdit = new QLineEdit(groupBox_2);
        FXlineEdit->setObjectName(QStringLiteral("FXlineEdit"));

        gridLayout_5->addWidget(FXlineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        pointFilterEdit = new QLineEdit(groupBox_2);
        pointFilterEdit->setObjectName(QStringLiteral("pointFilterEdit"));

        gridLayout_5->addWidget(pointFilterEdit, 6, 1, 1, 1);

        k1lineEdit = new QLineEdit(groupBox_2);
        k1lineEdit->setObjectName(QStringLiteral("k1lineEdit"));

        gridLayout_5->addWidget(k1lineEdit, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 5, 0, 1, 1);

        CXlineEdit = new QLineEdit(groupBox_2);
        CXlineEdit->setObjectName(QStringLiteral("CXlineEdit"));

        gridLayout_5->addWidget(CXlineEdit, 2, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 6, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 3, 0, 1, 1);

        FYlineEdit = new QLineEdit(groupBox_2);
        FYlineEdit->setObjectName(QStringLiteral("FYlineEdit"));

        gridLayout_5->addWidget(FYlineEdit, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        pointSizeSlider = new QSlider(groupBox_2);
        pointSizeSlider->setObjectName(QStringLiteral("pointSizeSlider"));
        pointSizeSlider->setMinimum(1);
        pointSizeSlider->setMaximum(10);
        pointSizeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(pointSizeSlider);

        pclBtn = new QPushButton(groupBox_2);
        pclBtn->setObjectName(QStringLiteral("pclBtn"));

        verticalLayout_3->addWidget(pclBtn);


        verticalLayout_12->addLayout(verticalLayout_3);


        gridLayout_10->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        statelabel = new QLabel(groupBox);
        statelabel->setObjectName(QStringLiteral("statelabel"));
        statelabel->setMinimumSize(QSize(75, 23));
        statelabel->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);text-align: center;"));
        statelabel->setTextFormat(Qt::AutoText);

        gridLayout_7->addWidget(statelabel, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        IplineEdit = new QLineEdit(groupBox);
        IplineEdit->setObjectName(QStringLiteral("IplineEdit"));

        gridLayout->addWidget(IplineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        PortlineEdit = new QLineEdit(groupBox);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));

        gridLayout->addWidget(PortlineEdit, 1, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 2);

        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setMinimumSize(QSize(0, 23));

        gridLayout_7->addWidget(connectButton, 1, 0, 1, 1);


        gridLayout_10->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_15 = new QVBoxLayout(groupBox_5);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_3->addWidget(label_19, 3, 0, 1, 1);

        offsetSpinBox = new QSpinBox(groupBox_5);
        offsetSpinBox->setObjectName(QStringLiteral("offsetSpinBox"));
        offsetSpinBox->setMinimum(-10000);
        offsetSpinBox->setMaximum(30000);
        offsetSpinBox->setSingleStep(10);

        gridLayout_3->addWidget(offsetSpinBox, 4, 2, 1, 1);

        FramelineEdit = new QLineEdit(groupBox_5);
        FramelineEdit->setObjectName(QStringLiteral("FramelineEdit"));

        gridLayout_3->addWidget(FramelineEdit, 5, 2, 1, 1);

        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 5, 0, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        xlineEdit = new QLineEdit(groupBox_5);
        xlineEdit->setObjectName(QStringLiteral("xlineEdit"));

        gridLayout_3->addWidget(xlineEdit, 0, 2, 1, 1);

        disLineEdit = new QLineEdit(groupBox_5);
        disLineEdit->setObjectName(QStringLiteral("disLineEdit"));

        gridLayout_3->addWidget(disLineEdit, 3, 2, 1, 1);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 4, 0, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 2, 0, 1, 2);

        ylineEdit = new QLineEdit(groupBox_5);
        ylineEdit->setObjectName(QStringLiteral("ylineEdit"));

        gridLayout_3->addWidget(ylineEdit, 1, 2, 1, 1);

        depthlineEdit = new QLineEdit(groupBox_5);
        depthlineEdit->setObjectName(QStringLiteral("depthlineEdit"));

        gridLayout_3->addWidget(depthlineEdit, 2, 2, 1, 1);


        verticalLayout_15->addLayout(gridLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        Savebutton = new QPushButton(groupBox_5);
        Savebutton->setObjectName(QStringLiteral("Savebutton"));

        horizontalLayout_10->addWidget(Savebutton);

        savestatelabel = new QLabel(groupBox_5);
        savestatelabel->setObjectName(QStringLiteral("savestatelabel"));
        savestatelabel->setMinimumSize(QSize(75, 23));
        savestatelabel->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);"));

        horizontalLayout_10->addWidget(savestatelabel);


        verticalLayout_15->addLayout(horizontalLayout_10);

        DepthImgMultiSave = new QCheckBox(groupBox_5);
        DepthImgMultiSave->setObjectName(QStringLiteral("DepthImgMultiSave"));

        verticalLayout_15->addWidget(DepthImgMultiSave);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_15->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        savePcdButton = new QPushButton(groupBox_5);
        savePcdButton->setObjectName(QStringLiteral("savePcdButton"));

        horizontalLayout->addWidget(savePcdButton);

        savePCDStateLable = new QLabel(groupBox_5);
        savePCDStateLable->setObjectName(QStringLiteral("savePCDStateLable"));
        savePCDStateLable->setMinimumSize(QSize(75, 23));
        savePCDStateLable->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);"));

        horizontalLayout->addWidget(savePCDStateLable);


        verticalLayout_15->addLayout(horizontalLayout);

        PclImgMultiSave = new QCheckBox(groupBox_5);
        PclImgMultiSave->setObjectName(QStringLiteral("PclImgMultiSave"));

        verticalLayout_15->addWidget(PclImgMultiSave);

        HFlip = new QCheckBox(groupBox_5);
        HFlip->setObjectName(QStringLiteral("HFlip"));

        verticalLayout_15->addWidget(HFlip);

        VFlip = new QCheckBox(groupBox_5);
        VFlip->setObjectName(QStringLiteral("VFlip"));

        verticalLayout_15->addWidget(VFlip);

        HFlip->raise();
        VFlip->raise();
        DepthImgMultiSave->raise();
        PclImgMultiSave->raise();

        gridLayout_4->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        IntegrationtimeHDRlineEdit = new QLineEdit(groupBox_3);
        IntegrationtimeHDRlineEdit->setObjectName(QStringLiteral("IntegrationtimeHDRlineEdit"));

        gridLayout_6->addWidget(IntegrationtimeHDRlineEdit, 1, 1, 1, 1);

        checkBoxHDR = new QCheckBox(groupBox_3);
        checkBoxHDR->setObjectName(QStringLiteral("checkBoxHDR"));
        checkBoxHDR->setAutoFillBackground(false);
        checkBoxHDR->setChecked(false);

        gridLayout_6->addWidget(checkBoxHDR, 4, 0, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_6->addWidget(label_16, 2, 0, 1, 1);

        IntegrationtimelineEdit = new QLineEdit(groupBox_3);
        IntegrationtimelineEdit->setObjectName(QStringLiteral("IntegrationtimelineEdit"));

        gridLayout_6->addWidget(IntegrationtimelineEdit, 0, 1, 1, 1);

        checkBoxSetABS = new QCheckBox(groupBox_3);
        checkBoxSetABS->setObjectName(QStringLiteral("checkBoxSetABS"));

        gridLayout_6->addWidget(checkBoxSetABS, 5, 0, 1, 1);

        setAmplineEdit = new QLineEdit(groupBox_3);
        setAmplineEdit->setObjectName(QStringLiteral("setAmplineEdit"));

        gridLayout_6->addWidget(setAmplineEdit, 2, 1, 1, 1);

        checkBoxAmp = new QCheckBox(groupBox_3);
        checkBoxAmp->setObjectName(QStringLiteral("checkBoxAmp"));
        checkBoxAmp->setChecked(false);

        gridLayout_6->addWidget(checkBoxAmp, 5, 1, 1, 1);

        checkBoxDRNU = new QCheckBox(groupBox_3);
        checkBoxDRNU->setObjectName(QStringLiteral("checkBoxDRNU"));

        gridLayout_6->addWidget(checkBoxDRNU, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_6->addWidget(label_20, 1, 0, 1, 1);

        setMaxAmplineEdit = new QLineEdit(groupBox_3);
        setMaxAmplineEdit->setObjectName(QStringLiteral("setMaxAmplineEdit"));

        gridLayout_6->addWidget(setMaxAmplineEdit, 3, 1, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_6->addWidget(label_21, 3, 0, 1, 1);

        checkBoxCalibration = new QCheckBox(groupBox_3);
        checkBoxCalibration->setObjectName(QStringLiteral("checkBoxCalibration"));

        gridLayout_6->addWidget(checkBoxCalibration, 6, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_4, 0, 1, 1, 1);

        SmartEyeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SmartEyeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 23));
        SmartEyeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SmartEyeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SmartEyeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SmartEyeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SmartEyeClass->setStatusBar(statusBar);
        pointCloudDock = new QDockWidget(SmartEyeClass);
        pointCloudDock->setObjectName(QStringLiteral("pointCloudDock"));
        pointCloudDock->setMinimumSize(QSize(500, 400));
        pointCloudDock->setFloating(true);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        gridLayout_12 = new QGridLayout(dockWidgetContents_7);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        screen = new QVTKWidget(dockWidgetContents_7);
        screen->setObjectName(QStringLiteral("screen"));

        gridLayout_12->addWidget(screen, 0, 0, 1, 1);

        pointCloudDock->setWidget(dockWidgetContents_7);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), pointCloudDock);
        imageDock = new QDockWidget(SmartEyeClass);
        imageDock->setObjectName(QStringLiteral("imageDock"));
        imageDock->setFloating(true);
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QStringLiteral("dockWidgetContents_9"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetContents_9->sizePolicy().hasHeightForWidth());
        dockWidgetContents_9->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(dockWidgetContents_9);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Img_label = new QLabel(dockWidgetContents_9);
        Img_label->setObjectName(QStringLiteral("Img_label"));
        Img_label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Img_label->sizePolicy().hasHeightForWidth());
        Img_label->setSizePolicy(sizePolicy1);
        Img_label->setMinimumSize(QSize(320, 240));
        Img_label->setMaximumSize(QSize(1000000, 10000000));
        Img_label->setAutoFillBackground(true);
        Img_label->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        Img_label->setScaledContents(false);
        Img_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Img_label);

        imageDock->setWidget(dockWidgetContents_9);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), imageDock);
        ampDock = new QDockWidget(SmartEyeClass);
        ampDock->setObjectName(QStringLiteral("ampDock"));
        ampDock->setFloating(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_9 = new QGridLayout(dockWidgetContents);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        amp_label = new QLabel(dockWidgetContents);
        amp_label->setObjectName(QStringLiteral("amp_label"));
        sizePolicy1.setHeightForWidth(amp_label->sizePolicy().hasHeightForWidth());
        amp_label->setSizePolicy(sizePolicy1);
        amp_label->setMinimumSize(QSize(320, 240));
        amp_label->setMaximumSize(QSize(100000, 100000));
        amp_label->setAutoFillBackground(true);

        gridLayout_9->addWidget(amp_label, 0, 0, 1, 1);

        ampDock->setWidget(dockWidgetContents);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ampDock);
        pointCloudDock->raise();
        imageDock->raise();
        ampDock->raise();

        retranslateUi(SmartEyeClass);

        QMetaObject::connectSlotsByName(SmartEyeClass);
    } // setupUi

    void retranslateUi(QMainWindow *SmartEyeClass)
    {
        SmartEyeClass->setWindowTitle(QApplication::translate("SmartEyeClass", "SmartEye V1.0.6", 0));
        groupBox_4->setTitle(QApplication::translate("SmartEyeClass", "Colormap", 0));
        colormapPointCheckBox->setText(QApplication::translate("SmartEyeClass", "Clolormap Point", 0));
        label_11->setText(QApplication::translate("SmartEyeClass", "MaxDepth", 0));
        maxdepthlineEdit->setText(QApplication::translate("SmartEyeClass", "25000", 0));
        label_12->setText(QApplication::translate("SmartEyeClass", "MinDepth", 0));
        mindepthlineEdit->setText(QApplication::translate("SmartEyeClass", "100", 0));
        groupBox_2->setTitle(QApplication::translate("SmartEyeClass", "PointCloud Convert", 0));
        CYlineEdit->setText(QApplication::translate("SmartEyeClass", "133.6313985", 0));
        k2lineEdit->setText(QApplication::translate("SmartEyeClass", "0.102422447", 0));
        FXlineEdit->setText(QApplication::translate("SmartEyeClass", "191.8097556", 0));
        label_5->setText(QApplication::translate("SmartEyeClass", "CX", 0));
        pointFilterEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        k1lineEdit->setText(QApplication::translate("SmartEyeClass", "-0.293527263", 0));
        label_8->setText(QApplication::translate("SmartEyeClass", "k2", 0));
        CXlineEdit->setText(QApplication::translate("SmartEyeClass", "162.3485761", 0));
        label_15->setText(QApplication::translate("SmartEyeClass", "Density", 0));
        label_4->setText(QApplication::translate("SmartEyeClass", "FY", 0));
        label_7->setText(QApplication::translate("SmartEyeClass", "k1", 0));
        label_3->setText(QApplication::translate("SmartEyeClass", "FX", 0));
        label_6->setText(QApplication::translate("SmartEyeClass", "CY", 0));
        FYlineEdit->setText(QApplication::translate("SmartEyeClass", "190.5375098", 0));
        pclBtn->setText(QApplication::translate("SmartEyeClass", "PointCloud Convert", 0));
        groupBox->setTitle(QApplication::translate("SmartEyeClass", "IP Address", 0));
        statelabel->setText(QApplication::translate("SmartEyeClass", "NO", 0));
        label->setText(QApplication::translate("SmartEyeClass", "IP\357\274\232", 0));
        IplineEdit->setText(QApplication::translate("SmartEyeClass", "192.168.7.94", 0));
        label_2->setText(QApplication::translate("SmartEyeClass", "Port:", 0));
        PortlineEdit->setText(QApplication::translate("SmartEyeClass", "50660", 0));
        connectButton->setText(QApplication::translate("SmartEyeClass", "Connect", 0));
        groupBox_5->setTitle(QApplication::translate("SmartEyeClass", "Depth Information", 0));
        label_10->setText(QApplication::translate("SmartEyeClass", "x:", 0));
        label_19->setText(QApplication::translate("SmartEyeClass", "Dist(mm):", 0));
        label_17->setText(QApplication::translate("SmartEyeClass", "ImgFrame", 0));
        label_13->setText(QApplication::translate("SmartEyeClass", "y:", 0));
        label_18->setText(QApplication::translate("SmartEyeClass", "Offset", 0));
        label_14->setText(QApplication::translate("SmartEyeClass", "Depth:", 0));
        Savebutton->setText(QApplication::translate("SmartEyeClass", "Save PNG", 0));
        savestatelabel->setText(QApplication::translate("SmartEyeClass", "Saved", 0));
        DepthImgMultiSave->setText(QApplication::translate("SmartEyeClass", "multi frame", 0));
        savePcdButton->setText(QApplication::translate("SmartEyeClass", "Save PCD", 0));
        savePCDStateLable->setText(QApplication::translate("SmartEyeClass", "Saved", 0));
        PclImgMultiSave->setText(QApplication::translate("SmartEyeClass", "multi frame", 0));
        HFlip->setText(QApplication::translate("SmartEyeClass", "Horizontal Flip", 0));
        VFlip->setText(QApplication::translate("SmartEyeClass", "Vertical Flip", 0));
        groupBox_3->setTitle(QApplication::translate("SmartEyeClass", "Set Parametre", 0));
        IntegrationtimeHDRlineEdit->setText(QApplication::translate("SmartEyeClass", "2500", 0));
        checkBoxHDR->setText(QApplication::translate("SmartEyeClass", "HDR", 0));
        label_16->setText(QApplication::translate("SmartEyeClass", "MinAmp", 0));
        IntegrationtimelineEdit->setText(QApplication::translate("SmartEyeClass", "500", 0));
#ifndef QT_NO_TOOLTIP
        checkBoxSetABS->setToolTip(QApplication::translate("SmartEyeClass", "<html><head/><body><p>\347\216\257\345\242\203\345\205\211\346\240\241\345\207\206</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        checkBoxSetABS->setText(QApplication::translate("SmartEyeClass", "SetABS", 0));
#ifndef QT_NO_TOOLTIP
        setAmplineEdit->setToolTip(QApplication::translate("SmartEyeClass", "<html><head/><body><p>\345\260\217\344\272\216\346\255\244\345\274\272\345\272\246\345\215\263\350\256\276\344\270\2720\357\274\214\344\270\215\346\224\271\345\217\230\347\274\251\346\224\276\344\270\213\351\231\220</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        setAmplineEdit->setText(QApplication::translate("SmartEyeClass", "50", 0));
        checkBoxAmp->setText(QApplication::translate("SmartEyeClass", "\345\274\272\345\272\246\345\233\276", 0));
        checkBoxDRNU->setText(QApplication::translate("SmartEyeClass", "DRNU", 0));
        label_9->setText(QApplication::translate("SmartEyeClass", "TOF(us)1rd", 0));
        label_20->setText(QApplication::translate("SmartEyeClass", "TOF(us)2rd", 0));
#ifndef QT_NO_TOOLTIP
        setMaxAmplineEdit->setToolTip(QApplication::translate("SmartEyeClass", "<html><head/><body><p>\346\211\200\346\234\211\345\274\272\345\272\246\344\270\215\350\266\205\350\277\207\346\255\244\351\231\220\345\256\232\345\200\274\357\274\214\345\215\263\347\274\251\346\224\276\344\270\212\351\231\220</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        setMaxAmplineEdit->setText(QApplication::translate("SmartEyeClass", "500", 0));
        label_21->setText(QApplication::translate("SmartEyeClass", "MaxAmp", 0));
        checkBoxCalibration->setText(QApplication::translate("SmartEyeClass", "\347\225\270\345\217\230\346\240\241\346\255\243", 0));
        pointCloudDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Point Cloud", 0));
        imageDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Depth Image", 0));
        Img_label->setText(QString());
        ampDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Amplitude Image", 0));
        amp_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmartEyeClass: public Ui_SmartEyeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTEYE_H
