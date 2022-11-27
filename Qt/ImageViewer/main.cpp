/*****************************************************************//**
 * \file   main.cpp
 * \brief  Use command `qmake -project` to generate the Qt project file
 * The following lines are required in the ImageViewer.pro file:
 * QT += core gui network
 * greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 * 
 * \author Xuhua Huang
 * \date   November 27, 2022
 *********************************************************************/

#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Image Viewer");
    window.show();

    return app.exec();
}
