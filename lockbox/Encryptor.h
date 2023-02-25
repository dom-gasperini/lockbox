#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

// Dominic Gasperini
// lockbox - encryptor


// includes
#include <QString>
#include <QFile>
#include <QDebug>
#include <QStandardPaths>
#include <QFileInfo>

/**
 * @brief The Encryptor class
 */
class Encryptor
{
public:
    // Constructor
    Encryptor();

    void encryptFile();
    void decryptFile();

    quint64 generateKey();
    void saveKey();
    void loadKey();

    // Getters & Setters
    int getEncryptionKey();
    void setEncryptionKey(int number);

    QString getEncryptionKeyFilename();
    void setEncryptionKeyFilename(QString string);

    quint64 getDecryptionKey();
    void setDecryptionKey(quint64 number);

    QString getDecryptionKeyFilename();
    void setDecryptionKeyFilename(QString string);

    int getRandomEncryptionKeyLength();
    void setRandomEncryptionKeyLength(int length);

    QString getEncryptTargetFilename();
    void setEncryptTargetFilename(QString string);

    QString getDecryptTargetFilename();
    void setDecryptTargetFilename(QString string);

private:
    // Encryption Variables
    quint64 encryptionKey;
    QString encryptTargetFilename;
    QString encryptionKeyFilename;
    int randomEncryptionKeyLength;

    // Decryption Variables
    quint64 decryptionKey;
    QString decryptTargetFilename;
    QString decryptionKeyFilename;
};

#endif // ENCRYPTOR_H
