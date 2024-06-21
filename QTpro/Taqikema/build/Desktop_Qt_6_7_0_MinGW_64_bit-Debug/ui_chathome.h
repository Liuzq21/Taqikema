/********************************************************************************
** Form generated from reading UI file 'chathome.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATHOME_H
#define UI_CHATHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatHome
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *msgBrowser;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_3;
    QTextEdit *msgText;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendButton;

    void setupUi(QWidget *ChatHome)
    {
        if (ChatHome->objectName().isEmpty())
            ChatHome->setObjectName("ChatHome");
        ChatHome->resize(678, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatHome->sizePolicy().hasHeightForWidth());
        ChatHome->setSizePolicy(sizePolicy);
        ChatHome->setMinimumSize(QSize(0, 0));
        ChatHome->setMaximumSize(QSize(5000, 3000));
        widget = new QWidget(ChatHome);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 9, 661, 581));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QTextBrowser(widget);
        msgBrowser->setObjectName("msgBrowser");

        verticalLayout_2->addWidget(msgBrowser);

        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        toolButton = new QToolButton(frame);
        toolButton->setObjectName("toolButton");

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName("toolButton_2");

        horizontalLayout->addWidget(toolButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName("toolButton_3");

        horizontalLayout->addWidget(toolButton_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(frame);

        msgText = new QTextEdit(widget);
        msgText->setObjectName("msgText");

        verticalLayout_2->addWidget(msgText);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(300, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sendButton = new QPushButton(widget_2);
        sendButton->setObjectName("sendButton");

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_2->addWidget(widget_2);


        retranslateUi(ChatHome);

        QMetaObject::connectSlotsByName(ChatHome);
    } // setupUi

    void retranslateUi(QWidget *ChatHome)
    {
        toolButton->setText(QCoreApplication::translate("ChatHome", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("ChatHome", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("ChatHome", "...", nullptr));
        label->setText(QCoreApplication::translate("ChatHome", "\345\234\250\347\272\277\344\272\272\346\225\260\357\274\232", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatHome", "Send", nullptr));
        (void)ChatHome;
    } // retranslateUi

};

namespace Ui {
    class ChatHome: public Ui_ChatHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATHOME_H
