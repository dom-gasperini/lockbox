#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Dominic Gasperini
// lockbox - main window

// includes
#include <QMainWindow>
#include <QFileDialog>
#include <QTimer>
#include <QDialog>
#include <QStyleFactory>
#include <QPalette>
#include "Encryptor.h"
#include "AboutDlg.h"

// set namespace
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


// Main Window Class
class MainWindow : public QMainWindow
{
    // Required component
    Q_OBJECT

public:
    // Required Componets
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // UI Variables
    Ui::MainWindow *ui;
    QPalette m_currentPalette;

    // Classes
    Encryptor* encryptor;
    AboutDlg* aboutDlg;

    // Dialog
    QFileDialog* fileDialog;

    // Timers
    QTimer* updateTimer;

signals:


private slots:
    // UI slots
    void UpdateDisplay();

    // Element slots
    void on_encryptBrowseBtn_clicked();
    void on_decryptBrowseBtn_clicked();
    void on_encryptBtn_clicked();
    void on_decryptBtn_clicked();
    void on_encryptSetKeyCkbx_toggled(bool checked);
    void on_decryptSetKeyCkbx_toggled(bool checked);
    void on_actionDark_Mode_toggled(bool arg1);
    void on_actionAbout_triggered();
    void on_decryptKeyBrowseBtn_clicked();
};



#endif // MAINWINDOW_H
