/*****************************************************************//**
 * \file   TestWidget.h
 * \brief
 *
 * \author Xuhua Huang
 * \date   February 11, 2021
 *********************************************************************/

#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class TestWidget : public QWidget {
    Q_OBJECT

public:
    // constructor includes a null pointer
    TestWidget(QWidget* parent = nullptr);

    // destructor
    ~TestWidget() noexcept;

private:
    // label
    QLabel* label;

    // layout manager
    QVBoxLayout* vbox;

    void showHyperlink(QLabel* const label);
};

#endif // TESTWIDGET_H
