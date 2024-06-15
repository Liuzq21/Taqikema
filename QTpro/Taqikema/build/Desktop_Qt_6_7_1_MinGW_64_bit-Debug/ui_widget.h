/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(350, 225);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 2, 346, 80));
        label->setPixmap(QPixmap(QString::fromUtf8(":/login/lib/bg1.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 81, 346, 140));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/login/lib/bg3.jpg")));
        label_2->setScaledContents(true);
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, 50, 91, 61));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/login/lib/head3.png")));
        label_4->setScaledContents(true);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 130, 113, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
"border-width:1px;\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-right-color: rgba(255, 255, 255, 0);\n"
"border-left-color: rgba(255, 255, 255, 0);\n"
"border-bottom-color: rgb(129, 129, 129);\n"
""));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 160, 113, 20));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
"border-width:1px;\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-right-color: rgba(255, 255, 255, 0);\n"
"border-left-color: rgba(255, 255, 255, 0);\n"
"border-bottom-color: rgb(129, 129, 129);\n"
""));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        horizontalLayoutWidget_2 = new QWidget(Widget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(40, 190, 271, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(horizontalLayoutWidget_2);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_3->addWidget(checkBox_2);

        checkBox = new QCheckBox(horizontalLayoutWidget_2);
        checkBox->setObjectName("checkBox");

        horizontalLayout_3->addWidget(checkBox);

        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"background-color: rgb(99, 188, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"font-size:14px;\n"
"}\n"
"#pushButton:hover{\n"
"background-color: rgb(99, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"#pushButton:pressed{\n"
"background-color: rgb(99, 188, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"padding-left:2px;\n"
"padding-top:2px;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton);

        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 331, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(horizontalLayoutWidget);
        toolButton_2->setObjectName("toolButton_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/login/lib/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);

        horizontalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(horizontalLayoutWidget);
        toolButton->setObjectName("toolButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/login/lib/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);

        horizontalLayout->addWidget(toolButton);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 350, 225));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/login/lib/WhiteBackground.jpg")));
        label_3->setScaledContents(true);
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 350, 225));
        label_3->raise();
        label->raise();
        label_2->raise();
        label_4->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        horizontalLayoutWidget_2->raise();
        horizontalLayoutWidget->raise();
        label_5->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\347\274\226\345\217\267id", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "...", nullptr));
        label_3->setText(QString());
        label_5->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
