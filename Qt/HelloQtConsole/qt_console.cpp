/*****************************************************************//**
 * \file   qt_console.cpp
 * \brief  Qt console application with CMake example.
 * 
 * \author Xuhua Huang
 * \date   January 31, 2021; last updated: December 07, 2022
 *********************************************************************/

#include <iostream>
#include <stdlib.h>

#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QList>

int main(void)
{
    // output with <iostream>
    std::cout << "Hello Qt console" << "\n";

    // QString, I/O stream
    QTextStream out(stdout); // output stream object
    QTextStream in(stdin); // input stream object

    out << "This is a console application" << "\n";
    out.flush();
    out << "Please enter your name: ";
    out.flush();

    // fixing the issue to enter full name with a space
    std::string tempName; // temporary variable
    std::getline(std::cin, tempName); // use getline() function with std::istream

    // convert std::string to QString and print to console
    // with static factory function fromStdString
    QString Name = QString::fromStdString(tempName); // convert
    out << "Hello " << Name << "!" << "\n"; // print
    out.flush();

    // use qDebug() to print to console
    qDebug() << "Using qDebug() to send debugging messages to console in Desktop apps";

    // QString, append(), prepend()
    QString test_str = "is";
    test_str.append(" awesome");
    test_str.prepend("Music ");

    out << "Original mesasge: " << test_str << "\n";
    out << "The test string has " << test_str.length() << " characters" << "\n";

    // toUpper() and toLower()
    out << "toUpper(): " << test_str.toUpper() << "\n";
    out << "toLower(): " << test_str.toLower() << "\n";

    // QList
    QList<int> integerList;
    QList<QString> stringList = QList<QString>() << "Canada" << "U.S.A" << "Mexico";

    for (int i = 0; i < 6; i++)
    {
        integerList.append(i);
    }

    integerList.removeOne(4);

    // output the integer integerList
    foreach(int n, integerList)
    {
        qDebug() << __PRETTY_FUNCTION__ << ": " << n;
    }

    // output the string in stringList
    foreach(QString str, stringList)
    {
        qDebug() << __PRETTY_FUNCTION__ << ": " << str;
    }

    system("pause");
    return EXIT_SUCCESS;
}
