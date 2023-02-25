/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDark_Mode;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGroupBox *encryptGroupbox;
    QLabel *encryptLevelLbl;
    QComboBox *encryptLevelSbx;
    QLabel *encryptMethodLbl;
    QRadioButton *encryptRandomKeyRdo;
    QRadioButton *encryptCustomKeyRdo;
    QLabel *encryptCustomKeyLbl;
    QPushButton *encryptBrowseBtn;
    QTextEdit *encryptSelectedFileTbx;
    QLabel *encryptFileSelectLbl;
    QPushButton *encryptBtn;
    QCheckBox *encryptSetKeyCkbx;
    QSpinBox *encryptCustomKeySbx;
    QGroupBox *decryptGroupbox;
    QPushButton *decryptBrowseBtn;
    QLabel *decryptFileSelectLbl;
    QTextEdit *decryptSelectedFileTbx;
    QLabel *decryptMethodLbl;
    QRadioButton *decryptEnterKeyRdo;
    QRadioButton *decryptLoadKeyFromFileRdo;
    QPushButton *decryptBtn;
    QLabel *decryptKeyFileLbl;
    QTextEdit *decryptKeyFileTbx;
    QPushButton *decryptKeyBrowseBtn;
    QLabel *decryptEnterCustomKeyLbl;
    QSpinBox *decryptCustomKeySbx;
    QCheckBox *decryptSetKeyCkbx;
    QMenuBar *menubar;
    QMenu *menuApplication;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(790, 560);
        MainWindow->setMinimumSize(QSize(790, 560));
        MainWindow->setMaximumSize(QSize(790, 560));
        actionDark_Mode = new QAction(MainWindow);
        actionDark_Mode->setObjectName(QString::fromUtf8("actionDark_Mode"));
        actionDark_Mode->setCheckable(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        encryptGroupbox = new QGroupBox(centralwidget);
        encryptGroupbox->setObjectName(QString::fromUtf8("encryptGroupbox"));
        encryptGroupbox->setGeometry(QRect(10, 10, 381, 501));
        encryptLevelLbl = new QLabel(encryptGroupbox);
        encryptLevelLbl->setObjectName(QString::fromUtf8("encryptLevelLbl"));
        encryptLevelLbl->setGeometry(QRect(10, 120, 161, 16));
        encryptLevelSbx = new QComboBox(encryptGroupbox);
        encryptLevelSbx->addItem(QString());
        encryptLevelSbx->addItem(QString());
        encryptLevelSbx->addItem(QString());
        encryptLevelSbx->setObjectName(QString::fromUtf8("encryptLevelSbx"));
        encryptLevelSbx->setGeometry(QRect(10, 140, 361, 31));
        encryptMethodLbl = new QLabel(encryptGroupbox);
        encryptMethodLbl->setObjectName(QString::fromUtf8("encryptMethodLbl"));
        encryptMethodLbl->setGeometry(QRect(10, 30, 181, 16));
        encryptRandomKeyRdo = new QRadioButton(encryptGroupbox);
        encryptRandomKeyRdo->setObjectName(QString::fromUtf8("encryptRandomKeyRdo"));
        encryptRandomKeyRdo->setGeometry(QRect(20, 50, 106, 22));
        encryptRandomKeyRdo->setChecked(true);
        encryptCustomKeyRdo = new QRadioButton(encryptGroupbox);
        encryptCustomKeyRdo->setObjectName(QString::fromUtf8("encryptCustomKeyRdo"));
        encryptCustomKeyRdo->setGeometry(QRect(20, 80, 106, 22));
        encryptCustomKeyLbl = new QLabel(encryptGroupbox);
        encryptCustomKeyLbl->setObjectName(QString::fromUtf8("encryptCustomKeyLbl"));
        encryptCustomKeyLbl->setGeometry(QRect(10, 220, 131, 16));
        encryptBrowseBtn = new QPushButton(encryptGroupbox);
        encryptBrowseBtn->setObjectName(QString::fromUtf8("encryptBrowseBtn"));
        encryptBrowseBtn->setGeometry(QRect(270, 310, 101, 31));
        encryptSelectedFileTbx = new QTextEdit(encryptGroupbox);
        encryptSelectedFileTbx->setObjectName(QString::fromUtf8("encryptSelectedFileTbx"));
        encryptSelectedFileTbx->setGeometry(QRect(10, 350, 361, 51));
        encryptSelectedFileTbx->setReadOnly(true);
        encryptFileSelectLbl = new QLabel(encryptGroupbox);
        encryptFileSelectLbl->setObjectName(QString::fromUtf8("encryptFileSelectLbl"));
        encryptFileSelectLbl->setGeometry(QRect(10, 330, 151, 16));
        encryptBtn = new QPushButton(encryptGroupbox);
        encryptBtn->setObjectName(QString::fromUtf8("encryptBtn"));
        encryptBtn->setGeometry(QRect(50, 430, 281, 51));
        encryptBtn->setCheckable(false);
        encryptSetKeyCkbx = new QCheckBox(encryptGroupbox);
        encryptSetKeyCkbx->setObjectName(QString::fromUtf8("encryptSetKeyCkbx"));
        encryptSetKeyCkbx->setGeometry(QRect(20, 280, 90, 22));
        encryptCustomKeySbx = new QSpinBox(encryptGroupbox);
        encryptCustomKeySbx->setObjectName(QString::fromUtf8("encryptCustomKeySbx"));
        encryptCustomKeySbx->setGeometry(QRect(10, 240, 361, 31));
        encryptCustomKeySbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        encryptCustomKeySbx->setMaximum(1000000000);
        decryptGroupbox = new QGroupBox(centralwidget);
        decryptGroupbox->setObjectName(QString::fromUtf8("decryptGroupbox"));
        decryptGroupbox->setGeometry(QRect(400, 10, 381, 501));
        decryptBrowseBtn = new QPushButton(decryptGroupbox);
        decryptBrowseBtn->setObjectName(QString::fromUtf8("decryptBrowseBtn"));
        decryptBrowseBtn->setGeometry(QRect(270, 310, 101, 31));
        decryptFileSelectLbl = new QLabel(decryptGroupbox);
        decryptFileSelectLbl->setObjectName(QString::fromUtf8("decryptFileSelectLbl"));
        decryptFileSelectLbl->setGeometry(QRect(10, 330, 161, 16));
        decryptSelectedFileTbx = new QTextEdit(decryptGroupbox);
        decryptSelectedFileTbx->setObjectName(QString::fromUtf8("decryptSelectedFileTbx"));
        decryptSelectedFileTbx->setGeometry(QRect(10, 350, 361, 51));
        decryptSelectedFileTbx->setReadOnly(true);
        decryptMethodLbl = new QLabel(decryptGroupbox);
        decryptMethodLbl->setObjectName(QString::fromUtf8("decryptMethodLbl"));
        decryptMethodLbl->setGeometry(QRect(10, 30, 181, 16));
        decryptEnterKeyRdo = new QRadioButton(decryptGroupbox);
        decryptEnterKeyRdo->setObjectName(QString::fromUtf8("decryptEnterKeyRdo"));
        decryptEnterKeyRdo->setGeometry(QRect(20, 80, 106, 22));
        decryptEnterKeyRdo->setChecked(false);
        decryptLoadKeyFromFileRdo = new QRadioButton(decryptGroupbox);
        decryptLoadKeyFromFileRdo->setObjectName(QString::fromUtf8("decryptLoadKeyFromFileRdo"));
        decryptLoadKeyFromFileRdo->setGeometry(QRect(20, 50, 151, 22));
        decryptLoadKeyFromFileRdo->setChecked(true);
        decryptBtn = new QPushButton(decryptGroupbox);
        decryptBtn->setObjectName(QString::fromUtf8("decryptBtn"));
        decryptBtn->setGeometry(QRect(50, 430, 281, 51));
        decryptBtn->setCheckable(false);
        decryptKeyFileLbl = new QLabel(decryptGroupbox);
        decryptKeyFileLbl->setObjectName(QString::fromUtf8("decryptKeyFileLbl"));
        decryptKeyFileLbl->setGeometry(QRect(10, 120, 62, 16));
        decryptKeyFileTbx = new QTextEdit(decryptGroupbox);
        decryptKeyFileTbx->setObjectName(QString::fromUtf8("decryptKeyFileTbx"));
        decryptKeyFileTbx->setGeometry(QRect(10, 140, 361, 51));
        decryptKeyBrowseBtn = new QPushButton(decryptGroupbox);
        decryptKeyBrowseBtn->setObjectName(QString::fromUtf8("decryptKeyBrowseBtn"));
        decryptKeyBrowseBtn->setGeometry(QRect(270, 100, 101, 31));
        decryptEnterCustomKeyLbl = new QLabel(decryptGroupbox);
        decryptEnterCustomKeyLbl->setObjectName(QString::fromUtf8("decryptEnterCustomKeyLbl"));
        decryptEnterCustomKeyLbl->setGeometry(QRect(10, 220, 81, 16));
        decryptCustomKeySbx = new QSpinBox(decryptGroupbox);
        decryptCustomKeySbx->setObjectName(QString::fromUtf8("decryptCustomKeySbx"));
        decryptCustomKeySbx->setGeometry(QRect(10, 240, 361, 31));
        decryptCustomKeySbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        decryptCustomKeySbx->setMaximum(1000000000);
        decryptSetKeyCkbx = new QCheckBox(decryptGroupbox);
        decryptSetKeyCkbx->setObjectName(QString::fromUtf8("decryptSetKeyCkbx"));
        decryptSetKeyCkbx->setGeometry(QRect(20, 280, 90, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 790, 21));
        menuApplication = new QMenu(menubar);
        menuApplication->setObjectName(QString::fromUtf8("menuApplication"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuApplication->menuAction());
        menuApplication->addAction(actionDark_Mode);
        menuApplication->addSeparator();
        menuApplication->addAction(actionAbout);

        retranslateUi(MainWindow);

        encryptLevelSbx->setCurrentIndex(0);
        encryptBtn->setDefault(false);
        decryptBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lockbox", nullptr));
        actionDark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
#if QT_CONFIG(tooltip)
        actionDark_Mode->setToolTip(QCoreApplication::translate("MainWindow", "Enable Dark Mode!", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "Some information about the application :)", nullptr));
#endif // QT_CONFIG(tooltip)
        encryptGroupbox->setTitle(QCoreApplication::translate("MainWindow", "Encrypt", nullptr));
        encryptLevelLbl->setText(QCoreApplication::translate("MainWindow", "Select Encryption Level:", nullptr));
        encryptLevelSbx->setItemText(0, QCoreApplication::translate("MainWindow", "Probably good enough", nullptr));
        encryptLevelSbx->setItemText(1, QCoreApplication::translate("MainWindow", "Solid choice", nullptr));
        encryptLevelSbx->setItemText(2, QCoreApplication::translate("MainWindow", "This will be preserved for all time", nullptr));

        encryptMethodLbl->setText(QCoreApplication::translate("MainWindow", "Select Encryption Method:", nullptr));
        encryptRandomKeyRdo->setText(QCoreApplication::translate("MainWindow", "Random Key", nullptr));
        encryptCustomKeyRdo->setText(QCoreApplication::translate("MainWindow", "Custom Key", nullptr));
        encryptCustomKeyLbl->setText(QCoreApplication::translate("MainWindow", "Enter Custom Key:", nullptr));
        encryptBrowseBtn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        encryptFileSelectLbl->setText(QCoreApplication::translate("MainWindow", "File to Encrypt:", nullptr));
        encryptBtn->setText(QCoreApplication::translate("MainWindow", "Encrypt", nullptr));
        encryptSetKeyCkbx->setText(QCoreApplication::translate("MainWindow", "Set Key", nullptr));
        decryptGroupbox->setTitle(QCoreApplication::translate("MainWindow", "Decrypt", nullptr));
        decryptBrowseBtn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        decryptFileSelectLbl->setText(QCoreApplication::translate("MainWindow", "File to Decrypt:", nullptr));
        decryptMethodLbl->setText(QCoreApplication::translate("MainWindow", "Select Decryption Method:", nullptr));
        decryptEnterKeyRdo->setText(QCoreApplication::translate("MainWindow", "Enter Key", nullptr));
        decryptLoadKeyFromFileRdo->setText(QCoreApplication::translate("MainWindow", "Load Key from File", nullptr));
        decryptBtn->setText(QCoreApplication::translate("MainWindow", "Decrypt", nullptr));
        decryptKeyFileLbl->setText(QCoreApplication::translate("MainWindow", "Key File:", nullptr));
        decryptKeyBrowseBtn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        decryptEnterCustomKeyLbl->setText(QCoreApplication::translate("MainWindow", "Enter Key:", nullptr));
        decryptSetKeyCkbx->setText(QCoreApplication::translate("MainWindow", "Set Key", nullptr));
        menuApplication->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
