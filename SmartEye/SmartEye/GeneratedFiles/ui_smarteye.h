/********************************************************************************
** Form generated from reading UI file 'smarteye.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTEYE_H
#define UI_SMARTEYE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLineEdit *IntegrationtimelineEdit;
    QLineEdit *setAmplineEdit;
    QLabel *label_16;
    QLabel *label_9;
    QLineEdit *IntegrationtimeHDRlineEdit;
    QLabel *label_20;
    QCheckBox *checkBoxHDR;
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
    QCheckBox *DepthImgMultiSave;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *savePcdButton;
    QLabel *savePCDStateLable;
    QCheckBox *PclImgMultiSave;
    QCheckBox *HFlip;
    QCheckBox *VFlip;
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
            SmartEyeClass->setObjectName(QString::fromUtf8("SmartEyeClass"));
        SmartEyeClass->resize(942, 758);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SmartEye/Resource/exe.png"), QSize(), QIcon::Normal, QIcon::Off);
        SmartEyeClass->setWindowIcon(icon);
        centralWidget = new QWidget(SmartEyeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_11 = new QVBoxLayout(groupBox);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        IplineEdit = new QLineEdit(groupBox);
        IplineEdit->setObjectName(QString::fromUtf8("IplineEdit"));

        gridLayout->addWidget(IplineEdit, 0, 1, 1, 1);

        PortlineEdit = new QLineEdit(groupBox);
        PortlineEdit->setObjectName(QString::fromUtf8("PortlineEdit"));

        gridLayout->addWidget(PortlineEdit, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setMinimumSize(QSize(0, 23));

        horizontalLayout_3->addWidget(connectButton);

        statelabel = new QLabel(groupBox);
        statelabel->setObjectName(QString::fromUtf8("statelabel"));
        statelabel->setMinimumSize(QSize(75, 23));
        statelabel->setStyleSheet(QString::fromUtf8("color: rgb(231, 231, 231);text-align: center;"));
        statelabel->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(statelabel);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_11->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 5, 0, 1, 1);

        k1lineEdit = new QLineEdit(groupBox_2);
        k1lineEdit->setObjectName(QString::fromUtf8("k1lineEdit"));

        gridLayout_5->addWidget(k1lineEdit, 4, 1, 1, 1);

        CYlineEdit = new QLineEdit(groupBox_2);
        CYlineEdit->setObjectName(QString::fromUtf8("CYlineEdit"));

        gridLayout_5->addWidget(CYlineEdit, 3, 1, 1, 1);

        FXlineEdit = new QLineEdit(groupBox_2);
        FXlineEdit->setObjectName(QString::fromUtf8("FXlineEdit"));

        gridLayout_5->addWidget(FXlineEdit, 0, 1, 1, 1);

        pointFilterEdit = new QLineEdit(groupBox_2);
        pointFilterEdit->setObjectName(QString::fromUtf8("pointFilterEdit"));

        gridLayout_5->addWidget(pointFilterEdit, 6, 1, 1, 1);

        k2lineEdit = new QLineEdit(groupBox_2);
        k2lineEdit->setObjectName(QString::fromUtf8("k2lineEdit"));

        gridLayout_5->addWidget(k2lineEdit, 5, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 4, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 3, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 6, 0, 1, 1);

        CXlineEdit = new QLineEdit(groupBox_2);
        CXlineEdit->setObjectName(QString::fromUtf8("CXlineEdit"));

        gridLayout_5->addWidget(CXlineEdit, 2, 1, 1, 1);

        FYlineEdit = new QLineEdit(groupBox_2);
        FYlineEdit->setObjectName(QString::fromUtf8("FYlineEdit"));

        gridLayout_5->addWidget(FYlineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        pointSizeSlider = new QSlider(groupBox_2);
        pointSizeSlider->setObjectName(QString::fromUtf8("pointSizeSlider"));
        pointSizeSlider->setMinimum(1);
        pointSizeSlider->setMaximum(10);
        pointSizeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(pointSizeSlider);

        pclBtn = new QPushButton(groupBox_2);
        pclBtn->setObjectName(QString::fromUtf8("pclBtn"));

        verticalLayout_3->addWidget(pclBtn);


        verticalLayout_12->addLayout(verticalLayout_3);


        verticalLayout_10->addWidget(groupBox_2);


        gridLayout_4->addLayout(verticalLayout_10, 0, 0, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_13 = new QVBoxLayout(groupBox_3);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        IntegrationtimelineEdit = new QLineEdit(groupBox_3);
        IntegrationtimelineEdit->setObjectName(QString::fromUtf8("IntegrationtimelineEdit"));

        gridLayout_6->addWidget(IntegrationtimelineEdit, 0, 2, 1, 1);

        setAmplineEdit = new QLineEdit(groupBox_3);
        setAmplineEdit->setObjectName(QString::fromUtf8("setAmplineEdit"));

        gridLayout_6->addWidget(setAmplineEdit, 2, 2, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 2, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        IntegrationtimeHDRlineEdit = new QLineEdit(groupBox_3);
        IntegrationtimeHDRlineEdit->setObjectName(QString::fromUtf8("IntegrationtimeHDRlineEdit"));

        gridLayout_6->addWidget(IntegrationtimeHDRlineEdit, 1, 2, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_6->addWidget(label_20, 1, 0, 1, 1);


        verticalLayout_13->addLayout(gridLayout_6);

        checkBoxHDR = new QCheckBox(groupBox_3);
        checkBoxHDR->setObjectName(QString::fromUtf8("checkBoxHDR"));
        checkBoxHDR->setAutoFillBackground(false);
        checkBoxHDR->setChecked(false);

        verticalLayout_13->addWidget(checkBoxHDR);


        verticalLayout_16->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        maxdepthlineEdit = new QLineEdit(groupBox_4);
        maxdepthlineEdit->setObjectName(QString::fromUtf8("maxdepthlineEdit"));

        horizontalLayout_2->addWidget(maxdepthlineEdit);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);

        mindepthlineEdit = new QLineEdit(groupBox_4);
        mindepthlineEdit->setObjectName(QString::fromUtf8("mindepthlineEdit"));

        horizontalLayout_4->addWidget(mindepthlineEdit);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        colormapPointCheckBox = new QCheckBox(groupBox_4);
        colormapPointCheckBox->setObjectName(QString::fromUtf8("colormapPointCheckBox"));
        colormapPointCheckBox->setChecked(true);
        colormapPointCheckBox->setTristate(false);

        verticalLayout_4->addWidget(colormapPointCheckBox);


        verticalLayout_16->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_15 = new QVBoxLayout(groupBox_5);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 2, 0, 1, 2);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 5, 0, 1, 1);

        ylineEdit = new QLineEdit(groupBox_5);
        ylineEdit->setObjectName(QString::fromUtf8("ylineEdit"));

        gridLayout_3->addWidget(ylineEdit, 1, 2, 1, 1);

        depthlineEdit = new QLineEdit(groupBox_5);
        depthlineEdit->setObjectName(QString::fromUtf8("depthlineEdit"));

        gridLayout_3->addWidget(depthlineEdit, 2, 2, 1, 1);

        offsetSpinBox = new QSpinBox(groupBox_5);
        offsetSpinBox->setObjectName(QString::fromUtf8("offsetSpinBox"));
        offsetSpinBox->setMinimum(-10000);
        offsetSpinBox->setMaximum(30000);
        offsetSpinBox->setSingleStep(10);

        gridLayout_3->addWidget(offsetSpinBox, 4, 2, 1, 1);

        FramelineEdit = new QLineEdit(groupBox_5);
        FramelineEdit->setObjectName(QString::fromUtf8("FramelineEdit"));

        gridLayout_3->addWidget(FramelineEdit, 5, 2, 1, 1);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 4, 0, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        xlineEdit = new QLineEdit(groupBox_5);
        xlineEdit->setObjectName(QString::fromUtf8("xlineEdit"));

        gridLayout_3->addWidget(xlineEdit, 0, 2, 1, 1);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 3, 0, 1, 1);

        disLineEdit = new QLineEdit(groupBox_5);
        disLineEdit->setObjectName(QString::fromUtf8("disLineEdit"));

        gridLayout_3->addWidget(disLineEdit, 3, 2, 1, 1);


        verticalLayout_15->addLayout(gridLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        Savebutton = new QPushButton(groupBox_5);
        Savebutton->setObjectName(QString::fromUtf8("Savebutton"));

        horizontalLayout_10->addWidget(Savebutton);

        savestatelabel = new QLabel(groupBox_5);
        savestatelabel->setObjectName(QString::fromUtf8("savestatelabel"));
        savestatelabel->setMinimumSize(QSize(75, 23));
        savestatelabel->setStyleSheet(QString::fromUtf8("color: rgb(231, 231, 231);"));

        horizontalLayout_10->addWidget(savestatelabel);


        verticalLayout_15->addLayout(horizontalLayout_10);

        DepthImgMultiSave = new QCheckBox(groupBox_5);
        DepthImgMultiSave->setObjectName(QString::fromUtf8("DepthImgMultiSave"));

        verticalLayout_15->addWidget(DepthImgMultiSave);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        verticalLayout_15->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        savePcdButton = new QPushButton(groupBox_5);
        savePcdButton->setObjectName(QString::fromUtf8("savePcdButton"));

        horizontalLayout->addWidget(savePcdButton);

        savePCDStateLable = new QLabel(groupBox_5);
        savePCDStateLable->setObjectName(QString::fromUtf8("savePCDStateLable"));
        savePCDStateLable->setMinimumSize(QSize(75, 23));
        savePCDStateLable->setStyleSheet(QString::fromUtf8("color: rgb(231, 231, 231);"));

        horizontalLayout->addWidget(savePCDStateLable);


        verticalLayout_15->addLayout(horizontalLayout);

        PclImgMultiSave = new QCheckBox(groupBox_5);
        PclImgMultiSave->setObjectName(QString::fromUtf8("PclImgMultiSave"));

        verticalLayout_15->addWidget(PclImgMultiSave);

        HFlip = new QCheckBox(groupBox_5);
        HFlip->setObjectName(QString::fromUtf8("HFlip"));

        verticalLayout_15->addWidget(HFlip);

        VFlip = new QCheckBox(groupBox_5);
        VFlip->setObjectName(QString::fromUtf8("VFlip"));

        verticalLayout_15->addWidget(VFlip);

        HFlip->raise();
        VFlip->raise();
        DepthImgMultiSave->raise();
        PclImgMultiSave->raise();

        verticalLayout_16->addWidget(groupBox_5);


        gridLayout_4->addLayout(verticalLayout_16, 0, 1, 1, 1);

        SmartEyeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SmartEyeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 942, 26));
        SmartEyeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SmartEyeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SmartEyeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SmartEyeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SmartEyeClass->setStatusBar(statusBar);
        pointCloudDock = new QDockWidget(SmartEyeClass);
        pointCloudDock->setObjectName(QString::fromUtf8("pointCloudDock"));
        pointCloudDock->setMinimumSize(QSize(500, 400));
        pointCloudDock->setFloating(true);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        verticalLayout_9 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        screen = new QVTKWidget(dockWidgetContents_7);
        screen->setObjectName(QString::fromUtf8("screen"));

        verticalLayout_9->addWidget(screen);

        pointCloudDock->setWidget(dockWidgetContents_7);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), pointCloudDock);
        imageDock = new QDockWidget(SmartEyeClass);
        imageDock->setObjectName(QString::fromUtf8("imageDock"));
        imageDock->setFloating(true);
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetContents_9->sizePolicy().hasHeightForWidth());
        dockWidgetContents_9->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_9);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Img_label = new QLabel(dockWidgetContents_9);
        Img_label->setObjectName(QString::fromUtf8("Img_label"));
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
        SmartEyeClass->setWindowTitle(QApplication::translate("SmartEyeClass", "SmartEye V1.0.3", nullptr));
        groupBox->setTitle(QApplication::translate("SmartEyeClass", "IP Address", nullptr));
        IplineEdit->setText(QApplication::translate("SmartEyeClass", "192.168.7.75", nullptr));
        PortlineEdit->setText(QApplication::translate("SmartEyeClass", "50660", nullptr));
        label->setText(QApplication::translate("SmartEyeClass", "IP\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SmartEyeClass", "Port:", nullptr));
        connectButton->setText(QApplication::translate("SmartEyeClass", "Connect", nullptr));
        statelabel->setText(QApplication::translate("SmartEyeClass", "NO", nullptr));
        groupBox_2->setTitle(QApplication::translate("SmartEyeClass", "PointCloud Convert", nullptr));
        label_8->setText(QApplication::translate("SmartEyeClass", "k2", nullptr));
        k1lineEdit->setText(QApplication::translate("SmartEyeClass", "0", nullptr));
        CYlineEdit->setText(QApplication::translate("SmartEyeClass", "120", nullptr));
        FXlineEdit->setText(QApplication::translate("SmartEyeClass", "290", nullptr));
        pointFilterEdit->setText(QApplication::translate("SmartEyeClass", "0", nullptr));
        k2lineEdit->setText(QApplication::translate("SmartEyeClass", "0", nullptr));
        label_5->setText(QApplication::translate("SmartEyeClass", "CX", nullptr));
        label_7->setText(QApplication::translate("SmartEyeClass", "k1", nullptr));
        label_4->setText(QApplication::translate("SmartEyeClass", "FY", nullptr));
        label_6->setText(QApplication::translate("SmartEyeClass", "CY", nullptr));
        label_15->setText(QApplication::translate("SmartEyeClass", "Density", nullptr));
        CXlineEdit->setText(QApplication::translate("SmartEyeClass", "160", nullptr));
        FYlineEdit->setText(QApplication::translate("SmartEyeClass", "288", nullptr));
        label_3->setText(QApplication::translate("SmartEyeClass", "FX", nullptr));
        pclBtn->setText(QApplication::translate("SmartEyeClass", "PointCloud Convert", nullptr));
        groupBox_3->setTitle(QApplication::translate("SmartEyeClass", "Set Parametre", nullptr));
        IntegrationtimelineEdit->setText(QApplication::translate("SmartEyeClass", "500", nullptr));
        setAmplineEdit->setText(QApplication::translate("SmartEyeClass", "5", nullptr));
        label_16->setText(QApplication::translate("SmartEyeClass", "MinAmp", nullptr));
        label_9->setText(QApplication::translate("SmartEyeClass", "TOF(us)1rd", nullptr));
        IntegrationtimeHDRlineEdit->setText(QApplication::translate("SmartEyeClass", "2500", nullptr));
        label_20->setText(QApplication::translate("SmartEyeClass", "TOF(us)2rd", nullptr));
        checkBoxHDR->setText(QApplication::translate("SmartEyeClass", "HDR", nullptr));
        groupBox_4->setTitle(QApplication::translate("SmartEyeClass", "Colormap", nullptr));
        label_11->setText(QApplication::translate("SmartEyeClass", "MaxDepth", nullptr));
        maxdepthlineEdit->setText(QApplication::translate("SmartEyeClass", "30000", nullptr));
        label_12->setText(QApplication::translate("SmartEyeClass", "MinDepth", nullptr));
        mindepthlineEdit->setText(QApplication::translate("SmartEyeClass", "0", nullptr));
        colormapPointCheckBox->setText(QApplication::translate("SmartEyeClass", "Clolormap Point", nullptr));
        groupBox_5->setTitle(QApplication::translate("SmartEyeClass", "Depth Information", nullptr));
        label_14->setText(QApplication::translate("SmartEyeClass", "Depth:", nullptr));
        label_10->setText(QApplication::translate("SmartEyeClass", "x:", nullptr));
        label_17->setText(QApplication::translate("SmartEyeClass", "ImgFrame", nullptr));
        label_18->setText(QApplication::translate("SmartEyeClass", "Offset", nullptr));
        label_13->setText(QApplication::translate("SmartEyeClass", "y:", nullptr));
        label_19->setText(QApplication::translate("SmartEyeClass", "Dist(mm):", nullptr));
        Savebutton->setText(QApplication::translate("SmartEyeClass", "Save PNG", nullptr));
        savestatelabel->setText(QApplication::translate("SmartEyeClass", "Saved", nullptr));
        DepthImgMultiSave->setText(QApplication::translate("SmartEyeClass", "multi frame", nullptr));
        savePcdButton->setText(QApplication::translate("SmartEyeClass", "Save PCD", nullptr));
        savePCDStateLable->setText(QApplication::translate("SmartEyeClass", "Saved", nullptr));
        PclImgMultiSave->setText(QApplication::translate("SmartEyeClass", "multi frame", nullptr));
        HFlip->setText(QApplication::translate("SmartEyeClass", "Horizontal Flip", nullptr));
        VFlip->setText(QApplication::translate("SmartEyeClass", "Vertical Flip", nullptr));
        pointCloudDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Point Cloud", nullptr));
        imageDock->setWindowTitle(QApplication::translate("SmartEyeClass", "Depth Image", nullptr));
        Img_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmartEyeClass: public Ui_SmartEyeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTEYE_H
