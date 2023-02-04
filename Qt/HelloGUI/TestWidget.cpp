/*****************************************************************//**
 * \file   TestWidget.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   February 11, 2021
 *********************************************************************/

#include "TestWidget.h"

// TestWidget class constructor
// pointer parent is passed to parent class constructor
TestWidget::TestWidget(QWidget* parent) : QWidget(parent) {
    // instanciate a vertical box layout manager
    QVBoxLayout* vbox = new QVBoxLayout();

    // instantiate a label with "new" keyword and call QLabel constructor
    label = new QLabel("Hello Qt World");
    label->setFont(QFont("Times New Roman", 11));

    // set the background to green and text to white
    label->setStyleSheet("QLabel { background-color : green; color : white; }");

    // create a new label to implement very first hyperlink
    QLabel* label2 = new QLabel();
    showHyperlink(label2); // call function

    // add the label to the layout manager
    vbox->addWidget(label);
    vbox->addWidget(label2); // label2 still exists since it is a pointer

    // notice that there can only be one setLayout(): at the end of the
    // constructor
    this->setLayout(vbox);
}

// TestWidget class destructor is empty since
// all heap objects are deleted by parent class destructor
TestWidget::~TestWidget() noexcept {}

// content modified by function will stay since it is passed the address
void TestWidget::showHyperlink(QLabel* const label) {
    label->setText("<a href=\"www.qt-project.org/\">Get Started With Qt</a>");
    label->setTextFormat(Qt::RichText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label->setOpenExternalLinks(true);
}
