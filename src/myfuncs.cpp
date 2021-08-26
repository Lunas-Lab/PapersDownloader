#include <string>
#include <QString>
#include <fstream>
#include <iostream>
#include <QDebug>
//#include "myfuncs.h"

bool addYearArray[84];

int curl(QString commandQString, QString drive, QString rootDir, QString subjectDir, bool openAfter, QString paperName) {
    commandQString.prepend("run.bat "); //prepends the call to the batch file
    commandQString.append(" ");
    commandQString.append(drive);
    commandQString.append(":");
    commandQString.append(" \"");
    commandQString.append(rootDir);
    commandQString.append("\" ");
    commandQString.append("\"");
    commandQString.append(subjectDir);
    commandQString.append("\"");
    if (openAfter == true) {
        commandQString.append(" -o ");
        commandQString.append(paperName);
    }

    std::string commandString = commandQString.toStdString();   //converts the QString to a std::string
    char commandChar[300];  //declares the command char array as 300 long
    for (int i = 0; i <= commandString.length(); i++) { //copies contents of command sting to command char array
           commandChar[i] = commandString[i];
    }
    system(commandChar);    //calls the command char array as a system command
    return 0;
}

QString parse(QString in) {     //helper function to replace spaces with %20's
    in.replace(" ", "%20", Qt::CaseInsensitive);
    return in;
}

QString url(QString level, QString subject, QString year, QString paper, QString session, QString variant, QString type, QString courseCode, QString urlStart, bool remEnd, bool specExt_bool, QString specExt_QString, bool addYear) {
    QString url = urlStart; //initialises QString with website source
    url.append(parse(level));
    url.append("/");
    url.append(parse(subject));
    if (addYear == true) {
        url.append("/20");
        url.append(year);
    }
    url.append("/");
    url.append(parse(courseCode));
    url.append("_");
    url.append(parse(session));
    url.append(parse(year));
    url.append("_");
    url.append(parse(type));
    if (remEnd == false) {
    url.append("_");
    url.append(parse(paper));
    url.append(parse(variant));
    }
    if (specExt_bool == false) {
    url.append(".pdf\"");
    }
    else if (specExt_bool) {
        url.append(".");
        url.append(specExt_QString);
        url.append("\"");
    }
    return url;
}

QString extractCourse(QString in) {
    QString out;
    int pos = in.length() - 5;  //sets position in string for for loop to just after bracket of course code
    for (; pos <= in.length() - 2; pos++) { //copies just course code as a QString to output
        out.append(in.at(pos));
    }
    return out;
}

QString paperName(QString year, QString paper, QString session, QString variant, QString type, QString courseCode, bool remEnd, bool specExt_bool, QString specExt_QString) {
    QString name;
    name.append(parse(courseCode));
    name.append("_");
    name.append(parse(session));
    name.append(parse(year));
    name.append("_");
    name.append(parse(type));
    if (remEnd == false) {
    name.append("_");
    name.append(parse(paper));
    name.append(parse(variant));
    }
    if (specExt_bool == false) {
    name.append(".pdf");
    }
    else if (specExt_bool) {
        name.append(".");
        name.append(specExt_QString);
        name.append("\"");
    }
    return name;
}

bool loadAddYear(){
    char c;
#ifdef _DEBUG
    std::ifstream file("D:\\Repos\\build-PapersDownloader-Desktop_Qt_5_15_0_MSVC2019_64bit-Debug\\debug\\years.paper");
#endif
#ifndef _DEBUG
    std::ifstream file("years.paper");
#endif
    if (file.good()) {qDebug() << "22";}
    for (int i = 0; i <= 83; i++){
        file.get(c);
        if (c == '1'){
            addYearArray[i] = true;
        }
        else if (c == '0'){
            addYearArray[i] = false;
        }
        else if (c != 0 && c != 1) {
            qDebug() << "Invalid character in years.paper file";
            return false;
        }
    }
    file.close();
    return true;
}

