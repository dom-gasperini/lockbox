// Dominic Gasperini
// lockbox - main window

// imports
#include "MainWindow.h"
#include "ui_MainWindow.h"

// defines
#define PROGRESS_BAR_UPDATE_INTERVAL        5   // in milliseconds


// Main Window Class
/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Setup UI
    ui->setupUi(this);
    m_currentPalette = qApp->palette();
    this->setWindowIcon(QIcon(":/icons/lockbox.ico"));
    ui->encryptBtn->setEnabled(false);
    ui->decryptBtn->setEnabled(false);

    // Setup Timers
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(UpdateDisplay()));
    updateTimer->start(15);     // in milliseconds

    // Encryption object
    encryptor = new Encryptor();
    aboutDlg = new AboutDlg();

    // File Dialog
    fileDialog = new QFileDialog();
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    fileDialog->setNameFilter("*.txt");

    // Update GUI
    UpdateDisplay();
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}


// Private Slots
/**
 * @brief MainWindow::UpdateDisplay
 */
void MainWindow::UpdateDisplay()
{
    // Encryption -----------------------------------------------------------
    // Update Encryption Options
    if (ui->encryptCustomKeyRdo->isChecked()) {
        // disable elements
        ui->encryptLevelSbx->setDisabled(true);

        // enable elements
        ui->encryptCustomKeySbx->setEnabled(true);
        ui->encryptSetKeyCkbx->setDisabled(false);
    }

    if (ui->encryptRandomKeyRdo->isChecked()) {
        // enable elements
        ui->encryptLevelSbx->setDisabled(false);
        ui->encryptBtn->setEnabled(true);

        // disable elements
        ui->encryptCustomKeySbx->setEnabled(false);
        ui->encryptSetKeyCkbx->setDisabled(true);
    }

    // Update random key length
    switch (ui->encryptLevelSbx->currentIndex()) {
    // 128 bit
    case 0:
        encryptor->setRandomEncryptionKeyLength(10);
        break;
    // 196 bit
    case 1:
        encryptor->setRandomEncryptionKeyLength(14);
        break;
    // 256 bit
    case 2:
        encryptor->setRandomEncryptionKeyLength(18);
        break;
    // default to 16 bit
    default:
        encryptor->setRandomEncryptionKeyLength(10);
        break;
    }

    // Update text box
    ui->encryptSelectedFileTbx->setText(encryptor->getEncryptTargetFilename());

    // If there is no target file, disable encrypt button
    if (encryptor->getEncryptTargetFilename() == "") {
        ui->encryptBtn->setEnabled(false);
    }
    else {
        ui->encryptBtn->setEnabled(true);
    }


    // Decryption -----------------------------------------------------------
    // Update valid decryption options
    if (ui->decryptEnterKeyRdo->isChecked()) {
        // enable elements
        ui->decryptCustomKeySbx->setDisabled(false);
        ui->decryptSetKeyCkbx->setDisabled(false);

        // disable elements
        ui->decryptKeyBrowseBtn->setEnabled(false);
        ui->decryptKeyFileTbx->setEnabled(false);
    }

    if (ui->decryptLoadKeyFromFileRdo->isChecked()) {
        // enable elements
        ui->decryptKeyBrowseBtn->setEnabled(true);
        ui->decryptKeyFileTbx->setEnabled(true);

        // disable elements
        ui->decryptCustomKeySbx->setDisabled(true);
        ui->decryptSetKeyCkbx->setDisabled(true);
    }

    // Update textbox
    ui->decryptSelectedFileTbx->setText(encryptor->getDecryptTargetFilename());
    ui->decryptKeyFileTbx->setText(encryptor->getDecryptionKeyFilename());

    // If there is no target file, disable decrypt button
    if (encryptor->getDecryptTargetFilename() == "") {
        ui->decryptBtn->setEnabled(false);
    }
    else {
        ui->decryptBtn->setEnabled(true);
    }
}


/**
 * @brief MainWindow::on_encryptBrowseBtn_clicked
 */
void MainWindow::on_encryptBrowseBtn_clicked()
{
    // inits
    QStringList fileList;

    // open file dialog
    if (fileDialog->exec())
    {
        // get selected file
        fileList = fileDialog->selectedFiles();

        // Get the file from the directory and save
        encryptor->setEncryptTargetFilename(fileList[0]);
    }
}


/**
 * @brief MainWindow::on_decryptBrowseBtn_clicked
 */
void MainWindow::on_decryptBrowseBtn_clicked()
{
    // inits
    QStringList fileList;

    // open file dialog
    if (fileDialog->exec())
    {
        // get selected file
        fileList = fileDialog->selectedFiles();

        // Get the file from the directory and save
        encryptor->setDecryptTargetFilename(fileList[0]);
    }
}


/**
 * @brief MainWindow::on_decryptKeyBrowseBtn_clicked
 */
void MainWindow::on_decryptKeyBrowseBtn_clicked()
{
    // inits
    QStringList fileList;

    // open file dialog
    if (fileDialog->exec())
    {
        // get selected file
        fileList = fileDialog->selectedFiles();

        // Get the file from the directory and save
        encryptor->setDecryptionKeyFilename(fileList[0]);
    }
}



/**
 * @brief MainWindow::on_encryptBtn_clicked
 */
void MainWindow::on_encryptBtn_clicked()
{
    // if using a randomly generated key
    if (ui->encryptRandomKeyRdo->isChecked()) {
        // save randomly generated key to file
        encryptor->saveKey();
    }

    // encrypt that file!
    encryptor->encryptFile();
}


/**
 * @brief MainWindow::on_decryptBtn_clicked
 */
void MainWindow::on_decryptBtn_clicked()
{
    if (ui->decryptLoadKeyFromFileRdo->isChecked()) {
        encryptor->loadKey();
    }

    // decrypt that file!
    encryptor->decryptFile();
}


/**
 * @brief MainWindow::on_encryptSetKeyCkbx_toggled
 * @param checked
 */
void MainWindow::on_encryptSetKeyCkbx_toggled(bool checked)
{
    if (checked) {
        // save key
        encryptor->setEncryptionKey(ui->encryptCustomKeySbx->value());

        // disable textbox
        ui->encryptCustomKeySbx->setReadOnly(true);

        // enable encryption
        ui->encryptBtn->setEnabled(true);
    }

    else {
        // enable textbox
        ui->encryptCustomKeySbx->setReadOnly(false);

        // disable encryption
        ui->encryptBtn->setEnabled(false);
    }
}


/**
 * @brief MainWindow::on_decryptSetKeyCkbx_toggled
 * @param checked
 */
void MainWindow::on_decryptSetKeyCkbx_toggled(bool checked)
{
    if (checked) {
        // save key
        encryptor->setDecryptionKey(ui->decryptCustomKeySbx->value());

        // disable textbox
        ui->decryptCustomKeySbx->setReadOnly(true);

        // enable decryption
        ui->decryptBtn->setEnabled(true);
    }

    else {
        // enable textbox
        ui->decryptCustomKeySbx->setReadOnly(false);

        // disable decryption
        ui->decryptBtn->setEnabled(false);
    }
}


/**
 * @brief MainWindow::on_actionDark_Mode_toggled
 * @param checked
 */
void MainWindow::on_actionDark_Mode_toggled(bool checked)
{
    if (checked)
    {
        // Set Style
        qApp->setStyle(QStyleFactory::create("Fusion"));
        // Init a Dark Mode Palette
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window,QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
        darkPalette.setColor(QPalette::Base,QColor(42,42,42));
        darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
        darkPalette.setColor(QPalette::ToolTipBase,Qt::white);
        darkPalette.setColor(QPalette::ToolTipText,Qt::white);
        darkPalette.setColor(QPalette::Text,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
        darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
        darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
        darkPalette.setColor(QPalette::Button,QColor(53,53,53));
        darkPalette.setColor(QPalette::ButtonText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
        darkPalette.setColor(QPalette::BrightText,Qt::red);
        darkPalette.setColor(QPalette::Link,QColor(42,130,218));
        darkPalette.setColor(QPalette::Highlight, QColor(142,45,197));
        darkPalette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
        darkPalette.setColor(QPalette::HighlightedText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));

        // Set to Dark Mode
        qApp->setPalette(darkPalette);

        // Change Progress Bar Color to Green
        QPalette progressBarPalette;
        progressBarPalette.setColor(QPalette::Highlight, Qt::green);
    }

    else
    {
        // Reset Style to Windows Vista
        qApp->setStyle(QStyleFactory::create("windowsvista"));

        // Reset to Light Mode
        m_currentPalette.setColor(QPalette::Text, Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::black);
        m_currentPalette.setColor(QPalette::ButtonText,Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::Disabled, QPalette::Text, Qt::black);
        m_currentPalette.setColor(QPalette::WindowText, Qt::black);
        m_currentPalette.setColor(QPalette::Disabled, QPalette::WindowText, Qt::black);
        m_currentPalette.setColor(QPalette::ToolTipBase,Qt::black);
        m_currentPalette.setColor(QPalette::ToolTipText,Qt::black);
        m_currentPalette.setColor(QPalette::Disabled,QPalette::Highlight, Qt::black);
        m_currentPalette.setColor(QPalette::HighlightedText,Qt::black);
        m_currentPalette.setColor(QPalette::Disabled,QPalette::HighlightedText, Qt::black);
        m_currentPalette.setColor(QPalette::All, QPalette::ButtonText, Qt::black);
        m_currentPalette.setColor(QPalette::All, QPalette::Text, Qt::black);
        qApp->setPalette(m_currentPalette);
    }
}


/**
 * @brief MainWindow::on_actionAbout_triggered
 */
void MainWindow::on_actionAbout_triggered()
{
    aboutDlg->show();
}
