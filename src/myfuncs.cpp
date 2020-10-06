#include <string>
#include <QString>
//#include "myfuncs.h"

int curl(QString commandQString, QString drive, QString rootDir, QString subjectDir) {
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

QString url(QString level, QString subject, QString year, QString paper, QString session, QString variant, QString type, QString courseCode, QString urlStart, bool remEnd, bool specExt_bool, QString specExt_QString) {
    QString url = urlStart; //initialises QString with website source
    url.append(parse(level));
    url.append("/");
    url.append(parse(subject));
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
