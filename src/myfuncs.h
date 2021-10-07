#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <QStringList>

int curl(QString commandQString, QString drive, QString rootDir, QString subjectDir, bool openAfter, QString paperName);   //url given to pass to batch file
QString parse(QString in);  //simply removes spaces and replaces with %20
QString url(QString level, QString subject, QString year, QString paper, QString session, QString variant, QString type, QString courseCode, QString urlStart, bool remEnd, bool specExt_bool, QString specExt_QString, bool addYear);    //forms url
QString extractCourse(QString in);  //gets the course code from the string in the string list
QString paperName(QString year, QString paper, QString session, QString variant, QString type, QString courseCode, bool remEnd, bool specExt_bool, QString specExt_QString);
bool loadAddYear();



//the two string lists for the level and subject boxes
extern QStringList subjects_igcse;
extern QStringList subjects_asalevel;

extern bool addYearArray[84];

#endif //MYFUNCS_H
