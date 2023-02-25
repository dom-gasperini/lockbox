#ifndef ABOUTDLG_H
#define ABOUTDLG_H

// Dominic Gasperini
// lockbox - about dialog

// includes
#include <QDialog>
#include <QDesktopServices>
#include <QUrl>

// set namespace
namespace Ui {
class AboutDlg;
}

/**
 * @brief The AboutDlg class
 */
class AboutDlg : public QDialog
{
    Q_OBJECT


public:
    // Constructor & Destructor
    explicit AboutDlg(QWidget *parent = nullptr);
    ~AboutDlg();

    // Getters & Setters
    QString getQtVersion();


private slots:
    void on_exitBtn_clicked();

    void on_lockboxTitleBtn_clicked();

private:
    // UI Variables
    Ui::AboutDlg *ui;
};

#endif // ABOUTDLG_H
