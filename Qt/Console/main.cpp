#include <iostream>

#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QList>

int main(void)
{
    // output with <iostream>
    std::cout << "Hello Qt console" << std::"\n";

    // QString, I/O stream
    QTextStream out(stdout); // output stream object
    QTextStream in(stdin); // input stream object

    out << "This is a console application" << "\n";
    out.flush();
    out << "Please enter your name" << "\n";
    out.flush();

    // fixing the issue to enter full name with a space
    std::string tempName; // temporary variable
    std::getline(std::cin, tempName); // use getline() function with std::istream

    // convert std::string to QString and print to console
    QString Name = QString::fromStdString(tempName); // convert
    out << "Hello "<< Name << "!" << "\n"; // print
    out.flush();

    // use qDebug() to print to console
    qDebug() << "Using qDebug() to send debugging messages to console in Desktop apps" << "\n";

    // QString, append(), prepend()
    QString a = "is";
    a.append(" awesome");
    a.prepend("Music ");

    out << "Original mesasge: " << a << "\n";
    out << "The a string has " << a.count()
        << " characters" << "\n";

    // toUpper() and toLower()
    out << a.toUpper() << "\n";
    out << a.toLower() << "\n";

    // QList
    QList<int> integerList;
    QList<QString> stringList = QList<QString>() << "Canada" << "U.S.A" << "Mexico";
    for(int i = 0; i < 6; i++)
        integerList.append(i);
    integerList.removeOne(4);

    // output the integer integerList
    foreach(int n, integerList)
        qDebug() << n;
    // output the string in stringList
    foreach(QString str, stringList)
        qDebug() << str;

    return 0;
}
