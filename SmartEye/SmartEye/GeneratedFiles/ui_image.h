/********************************************************************************
** Form generated from reading UI file 'image.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_H
#define UI_IMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Image
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *imagelabel;

    void setupUi(QWidget *Image)
    {
        if (Image->objectName().isEmpty())
            Image->setObjectName(QStringLiteral("Image"));
        Image->resize(860, 562);
        Image->setLayoutDirection(Qt::LeftToRight);
        Image->setAutoFillBackground(true);
        horizontalLayout = new QHBoxLayout(Image);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        imagelabel = new QLabel(Image);
        imagelabel->setObjectName(QStringLiteral("imagelabel"));
        imagelabel->setLayoutDirection(Qt::LeftToRight);
        imagelabel->setAutoFillBackground(false);
        imagelabel->setScaledContents(true);

        horizontalLayout->addWidget(imagelabel);


        retranslateUi(Image);

        QMetaObject::connectSlotsByName(Image);
    } // setupUi

    void retranslateUi(QWidget *Image)
    {
        Image->setWindowTitle(QApplication::translate("Image", "Image", 0));
        imagelabel->setText(QApplication::translate("Image", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Image: public Ui_Image {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_H
