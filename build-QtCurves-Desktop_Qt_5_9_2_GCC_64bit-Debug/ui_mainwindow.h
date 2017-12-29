/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "renderarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    RenderArea *renderArea;
    QPushButton *btnLine;
    QPushButton *btnAstroid;
    QPushButton *btnCycloid;
    QPushButton *btnHuygens;
    QPushButton *btnHypo;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *spinScale;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *spinInterval;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinCount;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(492, 375);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        renderArea = new RenderArea(centralWidget);
        renderArea->setObjectName(QStringLiteral("renderArea"));
        renderArea->setGeometry(QRect(20, 10, 251, 197));
        btnLine = new QPushButton(centralWidget);
        btnLine->setObjectName(QStringLiteral("btnLine"));
        btnLine->setGeometry(QRect(391, 135, 80, 25));
        btnAstroid = new QPushButton(centralWidget);
        btnAstroid->setObjectName(QStringLiteral("btnAstroid"));
        btnAstroid->setGeometry(QRect(391, 11, 80, 25));
        btnCycloid = new QPushButton(centralWidget);
        btnCycloid->setObjectName(QStringLiteral("btnCycloid"));
        btnCycloid->setGeometry(QRect(391, 42, 80, 25));
        btnHuygens = new QPushButton(centralWidget);
        btnHuygens->setObjectName(QStringLiteral("btnHuygens"));
        btnHuygens->setGeometry(QRect(391, 73, 80, 25));
        btnHypo = new QPushButton(centralWidget);
        btnHypo->setObjectName(QStringLiteral("btnHypo"));
        btnHypo->setGeometry(QRect(391, 104, 81, 25));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(370, 170, 99, 28));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinScale = new QDoubleSpinBox(widget);
        spinScale->setObjectName(QStringLiteral("spinScale"));
        spinScale->setDecimals(1);
        spinScale->setSingleStep(0.1);

        horizontalLayout->addWidget(spinScale);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(310, 210, 164, 28));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinInterval = new QDoubleSpinBox(widget1);
        spinInterval->setObjectName(QStringLiteral("spinInterval"));
        spinInterval->setMaximum(100);

        horizontalLayout_2->addWidget(spinInterval);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(343, 250, 124, 28));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinCount = new QSpinBox(widget2);
        spinCount->setObjectName(QStringLiteral("spinCount"));
        spinCount->setMaximum(512);

        horizontalLayout_3->addWidget(spinCount);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnLine->setText(QApplication::translate("MainWindow", "Line", Q_NULLPTR));
        btnAstroid->setText(QApplication::translate("MainWindow", "Astroid", Q_NULLPTR));
        btnCycloid->setText(QApplication::translate("MainWindow", "Cycloid", Q_NULLPTR));
        btnHuygens->setText(QApplication::translate("MainWindow", "Huygens", Q_NULLPTR));
        btnHypo->setText(QApplication::translate("MainWindow", "Hypo Cycloid", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Scale", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Interval Length", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Step Count", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
