/**
 * @file main.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-03-23
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <QApplication>
#include <QMainWindow>

#include "TestWidget.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  TestWidget window;
  window.setFixedSize(400, 300);
  window.setWindowTitle("Hello Qt GUI");
  window.show();

  return app.exec();
}
