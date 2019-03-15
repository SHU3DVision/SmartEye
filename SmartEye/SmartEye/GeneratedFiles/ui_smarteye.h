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
    QHBoxLayout *horizontalLayout_10;
    QLabel *Img_label;
    QVTKWidget *screen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IplineEdit;
    QHBoxLayout *horizontalLayout_2;
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

    void setupUi(QMainWindow *SmartEyeClass)
    {
        if (SmartEyeClass->objectName().isEmpty())
            SmartEyeClass->setObjectName(QStringLiteral("SmartEyeClass"));
        SmartEyeClass->resize(1093, 429);
        centralWidget = new QWidget(SmartEyeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        Img_label = new QLabel(centralWidget);
        Img_label->setObjectName(QStringLiteral("Img_label"));
        Img_label->setEnabled(false);

        horizontalLayout_10->addWidget(Img_label);

        screen = new QVTKWidget(centralWidget);
        screen->setObjectName(QStringLiteral("screen"));

        horizontalLayout_10->addWidget(screen);

        SmartEyeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SmartEyeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1093, 23));
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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        IplineEdit = new QLineEdit(dockWidgetContents);
        IplineEdit->setObjectName(QStringLiteral("IplineEdit"));

        horizontalLayout->addWidget(IplineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        PortlineEdit = new QLineEdit(dockWidgetContents);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));

        horizontalLayout_2->addWidget(PortlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

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

        retranslateUi(SmartEyeClass);

        QMetaObject::connectSlotsByName(SmartEyeClass);
    } // setupUi

    void retranslateUi(QMainWindow *SmartEyeClass)
    {
        SmartEyeClass->setWindowTitle(QApplication::translate("SmartEyeClass", "SmartEye", 0));
        Img_label->setText(QApplication::translate("SmartEyeClass", "TextLabel", 0));
        dockWidget->setWindowTitle(QApplication::translate("SmartEyeClass", "Socket", 0));
        label->setText(QApplication::translate("SmartEyeClass", "IP\357\274\232", 0));
        IplineEdit->setText(QApplication::translate("SmartEyeClass", "192.168.7.2", 0));
        label_2->setText(QApplication::translate("SmartEyeClass", "Port:", 0));
        PortlineEdit->setText(QApplication::translate("SmartEyeClass", "50660", 0));
        connectButton->setText(QApplication::translate("SmartEyeClass", "Connect", 0));
        statelabel->setText(QApplication::translate("SmartEyeClass", "NO", 0));
        dockWidget_2->setWindowTitle(QApplication::translate("SmartEyeClass", "Paraments", 0));
        label_3->setText(QApplication::translate("SmartEyeClass", "FX", 0));
        FXlineEdit->setText(QApplication::translate("SmartEyeClass", "287.037753 ", 0));
        label_4->setText(QApplication::translate("SmartEyeClass", "FY", 0));
        FYlineEdit->setText(QApplication::translate("SmartEyeClass", "288.1155963 ", 0));
        label_5->setText(QApplication::translate("SmartEyeClass", "CX", 0));
        CXlineEdit->setText(QApplication::translate("SmartEyeClass", "179.8002737 ", 0));
        label_6->setText(QApplication::translate("SmartEyeClass", "CY", 0));
        CYlineEdit->setText(QApplication::translate("SmartEyeClass", "119.8945818 ", 0));
        label_7->setText(QApplication::translate("SmartEyeClass", "k1", 0));
        k1lineEdit->setText(QApplication::translate("SmartEyeClass", "-0.126345354 ", 0));
        label_8->setText(QApplication::translate("SmartEyeClass", "k2", 0));
        k2lineEdit->setText(QApplication::translate("SmartEyeClass", "0.149484016 ", 0));
        pclBtn->setText(QApplication::translate("SmartEyeClass", "PointCloud Convert", 0));
    } // retranslateUi

};

namespace Ui {
    class SmartEyeClass: public Ui_SmartEyeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTEYE_H
