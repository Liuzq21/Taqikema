/********************************************************************************
** Form generated from reading UI file 'taqikema.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAQIKEMA_H
#define UI_TAQIKEMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <labelmenu.h>

QT_BEGIN_NAMESPACE

class Ui_Taqikema
{
public:
    LabelMenu *label;

    void setupUi(QWidget *Taqikema)
    {
        if (Taqikema->objectName().isEmpty())
            Taqikema->setObjectName("Taqikema");
        Taqikema->resize(150, 150);
        label = new LabelMenu(Taqikema);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 150, 150));
        label->setScaledContents(false);

        retranslateUi(Taqikema);

        QMetaObject::connectSlotsByName(Taqikema);
    } // setupUi

    void retranslateUi(QWidget *Taqikema)
    {
        Taqikema->setWindowTitle(QCoreApplication::translate("Taqikema", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Taqikema: public Ui_Taqikema {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAQIKEMA_H
