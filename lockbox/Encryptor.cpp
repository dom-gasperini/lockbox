// Dominic Gasperini
// lockbox - encryptor

// includes
#include <QMessageBox>
#include "Encryptor.h"
#include "simplecrypt.h"


/**
 * @brief Encryptor::Encryptor
 */
Encryptor::Encryptor()
{
    // Init encryption variables
    encryptionKey = 0;
    encryptTargetFilename = "";
    encryptionKeyFilename = "";

    // Init decryption variables
    decryptionKey = 0;
    decryptTargetFilename = "";
    decryptionKeyFilename = "";
}

// functions
/**
 * @brief Encryptor::encrypt
 */
void Encryptor::encryptFile() {
    // get original file contents
    QFile originalFile(encryptTargetFilename);
    QString fileContents;

    // open original file!
    if (originalFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // iterate through contents of the original file
        while (!originalFile.atEnd()) {
            // get line
            QString line = originalFile.readLine();

            // add to file contents
            fileContents.append(line);
        }
    }
    originalFile.close();

    // encrypt contents
    SimpleCrypt crypto;
    qDebug() << "encrypt key: " << encryptionKey;
    crypto.setKey(encryptionKey);
    QString data = crypto.encryptToString(fileContents);

    // create a new file for the encrypted contents
    QFileInfo fileInfo(originalFile.fileName());
    QString filename(fileInfo.baseName());
    QString encryptedFilename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + filename + "-encrypted.txt";
    qDebug() << "new filename: " << encryptedFilename;
    QFile encryptedFile(encryptedFilename);

    // open new file
    if (encryptedFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        // open text stream
        QTextStream encryptedFileData(&encryptedFile);

        // write encrypted content
        encryptedFileData << data;
    }

    encryptedFile.close();

    // Show pop-up in encryption completion
    QMessageBox messageBox;
    messageBox.setText("Successfully encrypted:\n" + encryptTargetFilename);
    messageBox.exec();
}


/**
 * @brief Encryptor::decrypt
 */
void Encryptor::decryptFile() {
    // get encrypted file contents
    QFile encryptedFile(decryptTargetFilename);
    QString fileContents;

    // open original file!
    if (encryptedFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // iterate through contents of the original file
        while (!encryptedFile.atEnd()) {
            // get line
            QString line = encryptedFile.readLine();

            // add to file contents
            fileContents.append(line);
        }
    }
    encryptedFile.close();

    // decrypt file
    SimpleCrypt crypto;
    qDebug() << "decrypt key: " << decryptionKey;
    crypto.setKey(decryptionKey);
    QString data = crypto.decryptToString(fileContents);

    // create a new file for the decrypted contents
    QFileInfo fileInfo(encryptedFile.fileName());
    QString filename(fileInfo.baseName());
    filename.replace("-encrypted", "-decrypted.txt");
    QString decryptedFilename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + filename;
    qDebug() << "new filename: " << decryptedFilename;
    QFile decryptedFile(decryptedFilename);

    // open new file
    if (decryptedFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        // open text stream
        QTextStream decryptedFileData(&decryptedFile);

        // write encrypted content
        decryptedFileData << data;
    }

    // check for an empty file
    QString popupMessage;
    if (decryptedFile.pos() == 0) {
        popupMessage = "Failed to decrypt (possible invalid key):\n" + decryptTargetFilename;
    }
    else {
        popupMessage = "Successfully decrypted:\n" + decryptTargetFilename;
    }

    // close the file!
    decryptedFile.close();

    // Show pop-up in decryption completion
    QMessageBox messageBox;
    messageBox.setText(popupMessage);
    messageBox.exec();
}


/**
 * @brief Encryptor::generateKey
 * @return a new random key
 */
quint64 Encryptor::generateKey() {
    QString possibleChars("0123456789");
    srand(time(NULL));

    QString randomKey;
    for(int i = 0; i < randomEncryptionKeyLength; ++i) {
       int charIndex = rand() % possibleChars.length();
       QChar nextChar = possibleChars.at(charIndex);
       randomKey.append(nextChar);
    }
    qDebug() << "gen key: " << randomKey;
    return randomKey.toULongLong();
}


/**
 * @brief Encryptor::saveKey
 */
void Encryptor::saveKey() {
    // Generate random key
    encryptionKey = generateKey();

    // Create filename
    QFileInfo fileInfo(encryptTargetFilename);
    QString originalFilename(fileInfo.baseName());
    QString filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + originalFilename + "-encryption-key.txt";
    qDebug() << "new filename: " << filename;

    // Open file and setup stream
    QFile keyFile(filename);
    if (keyFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // open text stream
        QTextStream keyData(&keyFile);

        // write key to file
        keyData << encryptionKey;
    }

    // close the file
    keyFile.close();
}


/**
 * @brief Encryptor::loadKey
 */
void Encryptor::loadKey() {
    QFile keyFile(decryptionKeyFilename);
    if (keyFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // read key
        QString line = keyFile.readLine();
        qDebug() << "decrypt key from file: " << line;
        decryptionKey = line.toULongLong();
        qDebug() << "decrypt key from file converted: " << decryptionKey;
    }
}


// Getters & Setters ----------------------------------------------------
int Encryptor::getEncryptionKey() {
    return encryptionKey;
}

void Encryptor::setEncryptionKey(int number) {
    encryptionKey = number;
}

QString Encryptor::getEncryptionKeyFilename() {
    return encryptionKeyFilename;
}

void Encryptor::setEncryptionKeyFilename(QString string) {
    encryptionKeyFilename = string;
}

quint64 Encryptor::getDecryptionKey() {
    return decryptionKey;
}

void Encryptor::setDecryptionKey(quint64 number) {
    decryptionKey = number;
}

QString Encryptor::getDecryptionKeyFilename() {
    return decryptionKeyFilename;
}

void Encryptor::setDecryptionKeyFilename(QString string) {
    decryptionKeyFilename = string;
}

int Encryptor::getRandomEncryptionKeyLength() {
    return randomEncryptionKeyLength;
}

void Encryptor::setRandomEncryptionKeyLength(int length) {
    randomEncryptionKeyLength = length;
}

QString Encryptor::getEncryptTargetFilename() {
    return encryptTargetFilename;
}

void Encryptor::setEncryptTargetFilename(QString string) {
    encryptTargetFilename = string;
}

QString Encryptor::getDecryptTargetFilename() {
    return decryptTargetFilename;
}

void Encryptor::setDecryptTargetFilename(QString string) {
    decryptTargetFilename = string;
}
