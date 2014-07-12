/********************************************************************************
** Form generated from reading UI file 'MatchWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHWINDOW_H
#define UI_MATCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatchWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *File1Button;
    QLabel *File1label;
    QPushButton *StartButton;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *File2Button;
    QLabel *File2label;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Result1label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *Result1lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Result2label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *Result2lineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MatchWindow)
    {
        if (MatchWindow->objectName().isEmpty())
            MatchWindow->setObjectName(QStringLiteral("MatchWindow"));
        MatchWindow->resize(559, 461);
        centralwidget = new QWidget(MatchWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        File1Button = new QToolButton(centralwidget);
        File1Button->setObjectName(QStringLiteral("File1Button"));

        horizontalLayout->addWidget(File1Button);

        File1label = new QLabel(centralwidget);
        File1label->setObjectName(QStringLiteral("File1label"));

        horizontalLayout->addWidget(File1label);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setDefault(true);

        gridLayout->addWidget(StartButton, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        File2Button = new QToolButton(centralwidget);
        File2Button->setObjectName(QStringLiteral("File2Button"));

        horizontalLayout_2->addWidget(File2Button);

        File2label = new QLabel(centralwidget);
        File2label->setObjectName(QStringLiteral("File2label"));

        horizontalLayout_2->addWidget(File2label);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 3, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Result1label = new QLabel(centralwidget);
        Result1label->setObjectName(QStringLiteral("Result1label"));

        horizontalLayout_3->addWidget(Result1label);

        horizontalSpacer_3 = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        Result1lineEdit = new QLineEdit(centralwidget);
        Result1lineEdit->setObjectName(QStringLiteral("Result1lineEdit"));
        Result1lineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(Result1lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Result2label = new QLabel(centralwidget);
        Result2label->setObjectName(QStringLiteral("Result2label"));

        horizontalLayout_4->addWidget(Result2label);

        horizontalSpacer_4 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        Result2lineEdit = new QLineEdit(centralwidget);
        Result2lineEdit->setObjectName(QStringLiteral("Result2lineEdit"));
        Result2lineEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(Result2lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 4, 0, 1, 2);

        MatchWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MatchWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MatchWindow->setStatusBar(statusbar);

        retranslateUi(MatchWindow);

        QMetaObject::connectSlotsByName(MatchWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MatchWindow)
    {
        MatchWindow->setWindowTitle(QApplication::translate("MatchWindow", "MainWindow", 0));
        File1Button->setText(QApplication::translate("MatchWindow", "File1", 0));
        File1label->setText(QApplication::translate("MatchWindow", "None", 0));
        StartButton->setText(QApplication::translate("MatchWindow", "Start", 0));
        File2Button->setText(QApplication::translate("MatchWindow", "File2", 0));
        File2label->setText(QApplication::translate("MatchWindow", "None", 0));
        Result1label->setText(QApplication::translate("MatchWindow", "\347\233\270\347\254\246\347\216\207", 0));
        Result2label->setText(QApplication::translate("MatchWindow", "\345\210\244\345\256\232\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class MatchWindow: public Ui_MatchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHWINDOW_H
