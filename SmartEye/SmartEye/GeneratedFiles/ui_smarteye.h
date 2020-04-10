/********************************************************************************
** Form generated from reading UI file 'smarteye.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTEYE_H
#define UI_SMARTEYE_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *IplineEdit;
    QLineEdit *PortlineEdit;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *connectButton;
    QLabel *statelabel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QLabel *label_20;
    QGridLayout *gridLayout_8;
    QLineEdit *lineEditPcIp;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEditPcPort;
    QPushButton *btnSendPcConfig;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QLineEdit *k1lineEdit;
    QLineEdit *CYlineEdit;
    QLineEdit *FXlineEdit;
    QLineEdit *pointFilterEdit;
    QLineEdit *k2lineEdit;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_15;
    QLineEdit *CXlineEdit;
    QLineEdit *FYlineEdit;
    QLabel *label_3;
    QSlider *pointSizeSlider;
    QPushButton *pclBtn;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *gridLayout_6;
    QLabel *label_16;
    QLineEdit *IntegrationtimelineEdit;
    QLabel *label_9;
    QLineEdit *setAmplineEdit;
    QRadioButton *radioButtonMaster;
    QRadioButton *radioButtonSlave;
    QCheckBox *checkBoxTemperatureCalibration;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *maxdepthlineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLineEdit *mindepthlineEdit;
    QCheckBox *colormapPointCheckBox;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *gridLayout_3;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_17;
    QLineEdit *ylineEdit;
    QLineEdit *depthlineEdit;
    QSpinBox *offsetSpinBox;
    QLineEdit *FramelineEdit;
    QLabel *label_18;
    QLabel *label_13;
    QLineEdit *xlineEdit;
    QLabel *label_19;
    QLineEdit *disLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *Savebutton;
    QLabel *savestatelabel;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *savePcdButton;
    QLabel *savePCDStateLable;
    QCheckBox *HFlip;
    QCheckBox *VFlip;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *pointCloudDock;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_9;
    QVTKWidget *screen;
    QDockWidget *imageDock;
    QWidget *dockWidgetContents_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *Img_label;

    void setupUi(QMainWindow *SmartEyeClass)
    {
        if (SmartEyeClass->objectName().isEmpty())
            SmartEyeClass->setObjectName(QStringLiteral("SmartEyeClass"));
        SmartEyeClass->resize(890, 741);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SmartEye/Resource/exe.png"), QSize(), QIcon::Normal, QIcon::Off);
        SmartEyeClass->setWindowIcon(icon);
        centralWidget = new QWidget(SmartEyeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_11 = new QVBoxLayout(groupBox);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        IplineEdit = new QLineEdit(groupBox);
        IplineEdit->setObjectName(QStringLiteral("IplineEdit"));

        gridLayout->addWidget(IplineEdit, 0, 1, 1, 1);

        PortlineEdit = new QLineEdit(groupBox);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));

        gridLayout->addWidget(PortlineEdit, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setMinimumSize(QSize(0, 23));

        horizontalLayout_3->addWidget(connectButton);

        statelabel = new QLabel(groupBox);
        statelabel->setObjectName(QStringLiteral("statelabel"));
        statelabel->setMinimumSize(QSize(75, 23));
        statelabel->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);text-align: center;"));
        statelabel->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(statelabel);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        btnStart = new QPushButton(groupBox);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        horizontalLayout_5->addWidget(btnStart);

        btnStop = new QPushButton(groupBox);
        btnStop->setObjectName(QStringLiteral("btnStop"));

        horizontalLayout_5->addWidget(btnStop);


        verticalLayout->addLayout(horizontalLayout_5);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout->addWidget(label_20);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, -1, -1, 0);
        lineEditPcIp = new QLineEdit(groupBox);
        lineEditPcIp->setObjectName(QStringLiteral("lineEditPcIp"));

        gridLayout_8->addWidget(lineEditPcIp, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_8->addWidget(label_21, 0, 0, 1, 1);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_8->addWidget(label_22, 1, 0, 1, 1);

        lineEditPcPort = new QLineEdit(groupBox);
        lineEditPcPort->setObjectName(QStringLiteral("lineEditPcPort"));

        gridLayout_8->addWidget(lineEditPcPort, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_8);

        btnSendPcConfig = new QPushButton(groupBox);
        btnSendPcConfig->setObjectName(QStringLiteral("btnSendPcConfig"));

        verticalLayout->addWidget(btnSendPcConfig);


        verticalLayout_11->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        verticalLayout_10->addWidget(groupBox);

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
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 5, 0, 1, 1);

        k1lineEdit = new QLineEdit(groupBox_2);
        k1lineEdit->setObjectName(QStringLiteral("k1lineEdit"));

        gridLayout_5->addWidget(k1lineEdit, 4, 1, 1, 1);

        CYlineEdit = new QLineEdit(groupBox_2);
        CYlineEdit->setObjectName(QStringLiteral("CYlineEdit"));

        gridLayout_5->addWidget(CYlineEdit, 3, 1, 1, 1);

        FXlineEdit = new QLineEdit(groupBox_2);
        FXlineEdit->setObjectName(QStringLiteral("FXlineEdit"));

        gridLayout_5->addWidget(FXlineEdit, 0, 1, 1, 1);

        pointFilterEdit = new QLineEdit(groupBox_2);
        pointFilterEdit->setObjectName(QStringLiteral("pointFilterEdit"));

        gridLayout_5->addWidget(pointFilterEdit, 6, 1, 1, 1);

        k2lineEdit = new QLineEdit(groupBox_2);
        k2lineEdit->setObjectName(QStringLiteral("k2lineEdit"));

        gridLayout_5->addWidget(k2lineEdit, 5, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 4, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 3, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 6, 0, 1, 1);

        CXlineEdit = new QLineEdit(groupBox_2);
        CXlineEdit->setObjectName(QStringLiteral("CXlineEdit"));

        gridLayout_5->addWidget(CXlineEdit, 2, 1, 1, 1);

        FYlineEdit = new QLineEdit(groupBox_2);
        FYlineEdit->setObjectName(QStringLiteral("FYlineEdit"));

        gridLayout_5->addWidget(FYlineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);


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


        verticalLayout_10->addWidget(groupBox_2);


        gridLayout_4->addLayout(verticalLayout_10, 0, 0, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_13 = new QVBoxLayout(groupBox_3);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_6->addWidget(label_16, 1, 0, 1, 1);

        IntegrationtimelineEdit = new QLineEdit(groupBox_3);
        IntegrationtimelineEdit->setObjectName(QStringLiteral("IntegrationtimelineEdit"));

        gridLayout_6->addWidget(IntegrationtimelineEdit, 0, 2, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        setAmplineEdit = new QLineEdit(groupBox_3);
        setAmplineEdit->setObjectName(QStringLiteral("setAmplineEdit"));

        gridLayout_6->addWidget(setAmplineEdit, 1, 2, 1, 1);

        radioButtonMaster = new QRadioButton(groupBox_3);
        radioButtonMaster->setObjectName(QStringLiteral("radioButtonMaster"));
        radioButtonMaster->setChecked(true);

        gridLayout_6->addWidget(radioButtonMaster, 2, 0, 1, 1);

        radioButtonSlave = new QRadioButton(groupBox_3);
        radioButtonSlave->setObjectName(QStringLiteral("radioButtonSlave"));

        gridLayout_6->addWidget(radioButtonSlave, 2, 2, 1, 1);


        verticalLayout_13->addLayout(gridLayout_6);

        checkBoxTemperatureCalibration = new QCheckBox(groupBox_3);
        checkBoxTemperatureCalibration->setObjectName(QStringLiteral("checkBoxTemperatureCalibration"));

        verticalLayout_13->addWidget(checkBoxTemperatureCalibration);


        verticalLayout_16->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        maxdepthlineEdit = new QLineEdit(groupBox_4);
        maxdepthlineEdit->setObjectName(QStringLiteral("maxdepthlineEdit"));

        horizontalLayout_2->addWidget(maxdepthlineEdit);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        mindepthlineEdit = new QLineEdit(groupBox_4);
        mindepthlineEdit->setObjectName(QStringLiteral("mindepthlineEdit"));

        horizontalLayout_4->addWidget(mindepthlineEdit);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        colormapPointCheckBox = new QCheckBox(groupBox_4);
        colormapPointCheckBox->setObjectName(QStringLiteral("colormapPointCheckBox"));
        colormapPointCheckBox->setChecked(true);
        colormapPointCheckBox->setTristate(false);

        verticalLayout_4->addWidget(colormapPointCheckBox);


        verticalLayout_16->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_15 = new QVBoxLayout(groupBox_5);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 2, 0, 1, 2);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 5, 0, 1, 1);

        ylineEdit = new QLineEdit(groupBox_5);
        ylineEdit->setObjectName(QStringLiteral("ylineEdit"));

        gridLayout_3->addWidget(ylineEdit, 1, 2, 1, 1);

        depthlineEdit = new QLineEdit(groupBox_5);
        depthlineEdit->setObjectName(QStringLiteral("depthlineEdit"));

        gridLayout_3->addWidget(depthlineEdit, 2, 2, 1, 1);

        offsetSpinBox = new QSpinBox(groupBox_5);
        offsetSpinBox->setObjectName(QStringLiteral("offsetSpinBox"));
        offsetSpinBox->setMinimum(-10000);
        offsetSpinBox->setMaximum(30000);
        offsetSpinBox->setSingleStep(10);

        gridLayout_3->addWidget(offsetSpinBox, 4, 2, 1, 1);

        FramelineEdit = new QLineEdit(groupBox_5);
        FramelineEdit->setObjectName(QStringLiteral("FramelineEdit"));

        gridLayout_3->addWidget(FramelineEdit, 5, 2, 1, 1);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 4, 0, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        xlineEdit = new QLineEdit(groupBox_5);
        xlineEdit->setObjectName(QStringLiteral("xlineEdit"));

        gridLayout_3->addWidget(xlineEdit, 0, 2, 1, 1);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_3->addWidget(label_19, 3, 0, 1, 1);

        disLineEdit = new QLineEdit(groupBox_5);
        disLineEdit->setObjectName(QStringLiteral("disLineEdit"));

        gridLayout_3->addWidget(disLineEdit, 3, 2, 1, 1);


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

        HFlip = new QCheckBox(groupBox_5);
        HFlip->setObjectName(QStringLiteral("HFlip"));

        verticalLayout_15->addWidget(HFlip);

        VFlip = new QCheckBox(groupBox_5);
        VFlip->setObjectName(QStringLiteral("VFlip"));

        verticalLayout_15->addWidget(VFlip);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_2);

        HFlip->raise();
        VFlip->raise();

        verticalLayout_16->addWidget(groupBox_5);


        gridLayout_4->addLayout(verticalLayout_16, 0, 1, 1, 1);

        SmartEyeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SmartEyeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 890, 23));
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
        verticalLayout_9 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        screen = new QVTKWidget(dockWidgetContents_7);
        screen->setObjectName(QStringLiteral("screen"));

        verticalLayout_9->addWidget(screen);

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
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_9);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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
        Img_label->setScaledContents(false);
        Img_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Img_label);

        imageDock->setWidget(dockWidgetContents_9);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), imageDock);
        pointCloudDock->raise();
        imageDock->raise();

        retranslateUi(SmartEyeClass);

        QMetaObject::connectSlotsByName(SmartEyeClass);
    } // setupUi

    void retranslateUi(QMainWindow *SmartEyeClass)
    {
        SmartEyeClass->setWindowTitle(QApplication::translate("SmartEyeClass", "SmartEye V1.0.3", 0));
        groupBox->setTitle(QApplication::translate("SmartEyeClass", "IP Address", 0));
        IplineEdit->setText(QApplication::translate("SmartEyeClass", "192.168.7.2", 0));
        PortlineEdit->setText(QApplication::translate("SmartEyeClass", "50660", 0));
        label->setText(QApplication::translate("SmartEyeClass", "IP\357\274\232", 0));
        label_2->setText(QApplication::translate("SmartEyeClass", "Port:", 0));
        connectButton->setText(QApplication::translate("SmartEyeClass", "Connect", 0));
        statelabel->setText(QApplication::translate("SmartEyeClass", "NO", 0));
        btnStart->setText(QApplication::translate("SmartEyeClass", "Start", 0));
        btnStop->setText(QApplication::translate("SmartEyeClass", "Stop", 0));
        label_20->setText(QApplication::translate("SmartEyeClass", "PC Config:", 0));
        lineEditPcIp->setText(QApplication::translate("SmartEyeClass", "192.168.7.111", 0));
        label_21->setText(QApplication::translate("SmartEyeClass", "IP:", 0));
        label_22->setText(QApplication::translate("SmartEyeClass", "Port:", 0));
        lineEditPcPort->setText(QApplication::translate("SmartEyeClass", "8080", 0));
        btnSendPcConfig->setText(QApplication::translate("SmartEyeClass", "Send", 0));
        groupBox_2->setTitle(QApplication::translate("SmartEyeClass", "PointCloud Convert", 0));
        label_8->setText(QApplication::translate("SmartEyeClass", "k2", 0));
        k1lineEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        CYlineEdit->setText(QApplication::translate("SmartEyeClass", "120", 0));
        FXlineEdit->setText(QApplication::translate("SmartEyeClass", "290", 0));
        pointFilterEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        k2lineEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        label_5->setText(QApplication::translate("SmartEyeClass", "CX", 0));
        label_7->setText(QApplication::translate("SmartEyeClass", "k1", 0));
        label_4->setText(QApplication::translate("SmartEyeClass", "FY", 0));
        label_6->setText(QApplication::translate("SmartEyeClass", "CY", 0));
        label_15->setText(QApplication::translate("SmartEyeClass", "Density", 0));
        CXlineEdit->setText(QApplication::translate("SmartEyeClass", "160", 0));
        FYlineEdit->setText(QApplication::translate("SmartEyeClass", "288", 0));
        label_3->setText(QApplication::translate("SmartEyeClass", "FX", 0));
        pclBtn->setText(QApplication::translate("SmartEyeClass", "PointCloud Convert", 0));
        groupBox_3->setTitle(QApplication::translate("SmartEyeClass", "Set Parametre", 0));
        label_16->setText(QApplication::translate("SmartEyeClass", "MinAmp", 0));
        IntegrationtimelineEdit->setText(QApplication::translate("SmartEyeClass", "1000", 0));
        label_9->setText(QApplication::translate("SmartEyeClass", "TOF(us)", 0));
        setAmplineEdit->setText(QApplication::translate("SmartEyeClass", "10", 0));
        radioButtonMaster->setText(QApplication::translate("SmartEyeClass", "Master", 0));
        radioButtonSlave->setText(QApplication::translate("SmartEyeClass", "Slave", 0));
        checkBoxTemperatureCalibration->setText(QApplication::translate("SmartEyeClass", "TemperatureCalibration", 0));
        groupBox_4->setTitle(QApplication::translate("SmartEyeClass", "Colormap", 0));
        label_11->setText(QApplication::translate("SmartEyeClass", "MaxDepth", 0));
        maxdepthlineEdit->setText(QApplication::translate("SmartEyeClass", "30000", 0));
        label_12->setText(QApplication::translate("SmartEyeClass", "MinDepth", 0));
        mindepthlineEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        colormapPointCheckBox->setText(QApplication::translate("SmartEyeClass", "Clolormap Point", 0));
        groupBox_5->setTitle(QApplication::translate("SmartEyeClass", "Depth Information", 0));
        label_14->setText(QApplication::translate("SmartEyeClass", "Depth:", 0));
        label_10->setText(QApplication::translate("SmartEyeClass", "x:", 0));
        label_17->setText(QApplication::translate("SmartEyeClass", "ImgFrame", 0));
        label_18->setText(QApplication::translate("SmartEyeClass", "Offset", 0));
        label_13->setText(QApplication::translate("SmartEyeClass", "y:", 0));
        label_19->setText(QApplication::translate("SmartEyeClass", "Dist(mm):", 0));
        Savebutton->setText(QApplication::translate("SmartEyeClass", "Save PNG", 0));
        savestatelabel->setText(QApplication::translate("SmartEyeClass", "Saved", 0));
        savePcdButton->setText(QApplication::translate("SmartEyeClass", "Save PCD", 0));
        savePCDStateLable->setText(QApplication::translate("SmartEyeClass", "Saved", 0));
        HFlip->setText(QApplication::translate("SmartEyeClass", "Horizontal Flip", 0));
        VFlip->setText(QApplication::translate("SmartEyeClass", "Vertical Flip", 0));
        pointCloudDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Point Cloud", 0));
        imageDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Depth Image", 0));
        Img_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmartEyeClass: public Ui_SmartEyeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTEYE_H
