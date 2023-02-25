// Dominic Gasperini
// lockbox - main

// imports
#include "MainWindow.h"
#include <QApplication>


// main!
int main(int argc, char *argv[])
{
    // Start Qt application
    QApplication a(argc, argv);

    // Init main window
    MainWindow w;

    // Display window
    w.show();

    // Exit program when main window is closed
    return a.exec();
}
