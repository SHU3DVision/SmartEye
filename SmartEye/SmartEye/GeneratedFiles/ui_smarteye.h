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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout_13;
    QLabel *Img_label;
    QVTKWidget *screen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *IplineEdit;
    QLabel *label_2;
    QLineEdit *PortlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *connectButton;
    QLabel *statelabel;
    QSpacerItem *verticalSpacer;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *FXlineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *FYlineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *CXlineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *CYlineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *k1lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *k2lineEdit;
    QPushButton *pclBtn;
    QSpacerItem *verticalSpacer_2;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *IntegrationtimelineEdit;
    QSpacerItem *verticalSpacer_3;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *maxdepthlineEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *mindepthlineEdit;
    QSpacerItem *verticalSpacer_4;
    QDockWidget *dockWidget_6;
    QWidget *dockWidgetContents_6;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *depthlineEdit;
    QLineEdit *ylineEdit;
    QLineEdit *xlineEdit;
    QDockWidget *dockWidget_7;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *Savebutton;
    QLabel *savestatelabel;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QMainWindow *SmartEyeClass)
    {
        if (SmartEyeClass->objectName().isEmpty())
            SmartEyeClass->setObjectName(QStringLiteral("SmartEyeClass"));
        SmartEyeClass->resize(1482, 830);
        centralWidget = new QWidget(SmartEyeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_13 = new QHBoxLayout(centralWidget);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        Img_label = new QLabel(centralWidget);
        Img_label->setObjectName(QStringLiteral("Img_label"));
        Img_label->setEnabled(true);
        Img_label->setMinimumSize(QSize(320, 240));
        Img_label->setMaximumSize(QSize(320, 240));
        Img_label->setAutoFillBackground(true);
        Img_label->setScaledContents(false);

        horizontalLayout_13->addWidget(Img_label);

        screen = new QVTKWidget(centralWidget);
        screen->setObjectName(QStringLiteral("screen"));

        horizontalLayout_13->addWidget(screen);

        SmartEyeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SmartEyeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1482, 23));
        SmartEyeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SmartEyeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SmartEyeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SmartEyeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SmartEyeClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(SmartEyeClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        IplineEdit = new QLineEdit(dockWidgetContents);
        IplineEdit->setObjectName(QStringLiteral("IplineEdit"));

        gridLayout->addWidget(IplineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        PortlineEdit = new QLineEdit(dockWidgetContents);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));

        gridLayout->addWidget(PortlineEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        connectButton = new QPushButton(dockWidgetContents);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout_3->addWidget(connectButton);

        statelabel = new QLabel(dockWidgetContents);
        statelabel->setObjectName(QStringLiteral("statelabel"));
        statelabel->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);text-align: center;"));
        statelabel->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(statelabel);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        dockWidget->setWidget(dockWidgetContents);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_2 = new QDockWidget(SmartEyeClass);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(dockWidgetContents_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        FXlineEdit = new QLineEdit(dockWidgetContents_2);
        FXlineEdit->setObjectName(QStringLiteral("FXlineEdit"));

        horizontalLayout_4->addWidget(FXlineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(dockWidgetContents_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        FYlineEdit = new QLineEdit(dockWidgetContents_2);
        FYlineEdit->setObjectName(QStringLiteral("FYlineEdit"));

        horizontalLayout_5->addWidget(FYlineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(dockWidgetContents_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        CXlineEdit = new QLineEdit(dockWidgetContents_2);
        CXlineEdit->setObjectName(QStringLiteral("CXlineEdit"));

        horizontalLayout_6->addWidget(CXlineEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(dockWidgetContents_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        CYlineEdit = new QLineEdit(dockWidgetContents_2);
        CYlineEdit->setObjectName(QStringLiteral("CYlineEdit"));

        horizontalLayout_7->addWidget(CYlineEdit);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(dockWidgetContents_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        k1lineEdit = new QLineEdit(dockWidgetContents_2);
        k1lineEdit->setObjectName(QStringLiteral("k1lineEdit"));

        horizontalLayout_8->addWidget(k1lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(dockWidgetContents_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8);

        k2lineEdit = new QLineEdit(dockWidgetContents_2);
        k2lineEdit->setObjectName(QStringLiteral("k2lineEdit"));

        horizontalLayout_9->addWidget(k2lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_9);

        pclBtn = new QPushButton(dockWidgetContents_2);
        pclBtn->setObjectName(QStringLiteral("pclBtn"));

        verticalLayout_3->addWidget(pclBtn);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        dockWidget_2->setWidget(dockWidgetContents_2);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);
        dockWidget_3 = new QDockWidget(SmartEyeClass);
        dockWidget_3->setObjectName(QStringLiteral("dockWidget_3"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_9 = new QLabel(dockWidgetContents_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_11->addWidget(label_9);

        IntegrationtimelineEdit = new QLineEdit(dockWidgetContents_3);
        IntegrationtimelineEdit->setObjectName(QStringLiteral("IntegrationtimelineEdit"));

        horizontalLayout_11->addWidget(IntegrationtimelineEdit);


        verticalLayout_5->addLayout(horizontalLayout_11);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        dockWidget_3->setWidget(dockWidgetContents_3);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_3);
        dockWidget_4 = new QDockWidget(SmartEyeClass);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_11 = new QLabel(dockWidgetContents_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        maxdepthlineEdit = new QLineEdit(dockWidgetContents_4);
        maxdepthlineEdit->setObjectName(QStringLiteral("maxdepthlineEdit"));

        horizontalLayout_2->addWidget(maxdepthlineEdit);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(dockWidgetContents_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_12->addWidget(label_12);

        mindepthlineEdit = new QLineEdit(dockWidgetContents_4);
        mindepthlineEdit->setObjectName(QStringLiteral("mindepthlineEdit"));

        horizontalLayout_12->addWidget(mindepthlineEdit);


        gridLayout_2->addLayout(horizontalLayout_12, 1, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        dockWidget_4->setWidget(dockWidgetContents_4);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_4);
        dockWidget_6 = new QDockWidget(SmartEyeClass);
        dockWidget_6->setObjectName(QStringLiteral("dockWidget_6"));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QStringLiteral("dockWidgetContents_6"));
        verticalLayout_8 = new QVBoxLayout(dockWidgetContents_6);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_10 = new QLabel(dockWidgetContents_6);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_13 = new QLabel(dockWidgetContents_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        label_14 = new QLabel(dockWidgetContents_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 2, 0, 1, 2);

        depthlineEdit = new QLineEdit(dockWidgetContents_6);
        depthlineEdit->setObjectName(QStringLiteral("depthlineEdit"));

        gridLayout_3->addWidget(depthlineEdit, 2, 2, 1, 1);

        ylineEdit = new QLineEdit(dockWidgetContents_6);
        ylineEdit->setObjectName(QStringLiteral("ylineEdit"));

        gridLayout_3->addWidget(ylineEdit, 1, 2, 1, 1);

        xlineEdit = new QLineEdit(dockWidgetContents_6);
        xlineEdit->setObjectName(QStringLiteral("xlineEdit"));

        gridLayout_3->addWidget(xlineEdit, 0, 2, 1, 1);


        verticalLayout_8->addLayout(gridLayout_3);

        dockWidget_7 = new QDockWidget(dockWidgetContents_6);
        dockWidget_7->setObjectName(QStringLiteral("dockWidget_7"));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        verticalLayout_9 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        Savebutton = new QPushButton(dockWidgetContents_7);
        Savebutton->setObjectName(QStringLiteral("Savebutton"));

        horizontalLayout_10->addWidget(Savebutton);

        savestatelabel = new QLabel(dockWidgetContents_7);
        savestatelabel->setObjectName(QStringLiteral("savestatelabel"));

        horizontalLayout_10->addWidget(savestatelabel);


        verticalLayout_9->addLayout(horizontalLayout_10);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        dockWidget_7->setWidget(dockWidgetContents_7);

        verticalLayout_8->addWidget(dockWidget_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        dockWidget_6->setWidget(dockWidgetContents_6);
        SmartEyeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_6);
        dockWidget_6->raise();

        retranslateUi(SmartEyeClass);

        QMetaObject::connectSlotsByName(SmartEyeClass);
    } // setupUi

    void retranslateUi(QMainWindow *SmartEyeClass)
    {
        SmartEyeClass->setWindowTitle(QApplication::translate("SmartEyeClass", "SmartEye", 0));
        Img_label->setText(QString());
        dockWidget->setWindowTitle(QApplication::translate("SmartEyeClass", "Socket", 0));
        label->setText(QApplication::translate("SmartEyeClass", "IP\357\274\232", 0));
        IplineEdit->setText(QApplication::translate("SmartEyeClass", "192.168.7.2", 0));
        label_2->setText(QApplication::translate("SmartEyeClass", "Port:", 0));
        PortlineEdit->setText(QApplication::translate("SmartEyeClass", "50660", 0));
        connectButton->setText(QApplication::translate("SmartEyeClass", "Connect", 0));
        statelabel->setText(QApplication::translate("SmartEyeClass", "NO", 0));
        dockWidget_2->setWindowTitle(QApplication::translate("SmartEyeClass", "PointCloudParaments", 0));
        label_3->setText(QApplication::translate("SmartEyeClass", "FX", 0));
        FXlineEdit->setText(QApplication::translate("SmartEyeClass", "290", 0));
        label_4->setText(QApplication::translate("SmartEyeClass", "FY", 0));
        FYlineEdit->setText(QApplication::translate("SmartEyeClass", "288", 0));
        label_5->setText(QApplication::translate("SmartEyeClass", "CX", 0));
        CXlineEdit->setText(QApplication::translate("SmartEyeClass", "160", 0));
        label_6->setText(QApplication::translate("SmartEyeClass", "CY", 0));
        CYlineEdit->setText(QApplication::translate("SmartEyeClass", "120", 0));
        label_7->setText(QApplication::translate("SmartEyeClass", "k1", 0));
        k1lineEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        label_8->setText(QApplication::translate("SmartEyeClass", "k2", 0));
        k2lineEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        pclBtn->setText(QApplication::translate("SmartEyeClass", "PointCloud Convert", 0));
        dockWidget_3->setWindowTitle(QApplication::translate("SmartEyeClass", "SetIntegrationTime", 0));
        label_9->setText(QApplication::translate("SmartEyeClass", "TOF(us)", 0));
        IntegrationtimelineEdit->setText(QApplication::translate("SmartEyeClass", "1000", 0));
        label_11->setText(QApplication::translate("SmartEyeClass", "MaxDepth", 0));
        maxdepthlineEdit->setText(QApplication::translate("SmartEyeClass", "30000", 0));
        label_12->setText(QApplication::translate("SmartEyeClass", "MinDepth", 0));
        mindepthlineEdit->setText(QApplication::translate("SmartEyeClass", "0", 0));
        dockWidget_6->setWindowTitle(QApplication::translate("SmartEyeClass", "DepthInformation", 0));
        label_10->setText(QApplication::translate("SmartEyeClass", "x:", 0));
        label_13->setText(QApplication::translate("SmartEyeClass", "y:", 0));
        label_14->setText(QApplication::translate("SmartEyeClass", "Depth:", 0));
        dockWidget_7->setWindowTitle(QApplication::translate("SmartEyeClass", "Save", 0));
        Savebutton->setText(QApplication::translate("SmartEyeClass", "Save", 0));
        savestatelabel->setText(QApplication::translate("SmartEyeClass", "Saved", 0));
    } // retranslateUi

};

namespace Ui {
    class SmartEyeClass: public Ui_SmartEyeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTEYE_H
