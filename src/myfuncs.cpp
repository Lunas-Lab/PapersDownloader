#include <string>
#include <QString>
#include <fstream>
#include <iostream>
#include <QDebug>
//#include "myfuncs.h"

bool addYearArray[84];

QStringList subjects_igcse = {
    "Accounting (0452)",
    "Accounting (9-1) (0985)",
    "Afrikaans - Second Language (0548)",
    "Agriculture (0600)",
    "Arabic - First Language (0508)",
    "Arabic - First Language (9-1) (7184)",
    "Arabic - Foreign Language (0544)",
    "Art & Design (0400)",
    "Art & Design (9-1) (0989)",
    "Bahasa Indonesia (0538)",
    "Biology (0610)",
    "Biology (9-1) (0970)",
    "Business Studies (0450)",
    "Business Studies (9-1) (0986)",
    "Chemistry (0620)",
    "Chemistry (9-1) (0971)",
    "Chinese (Mandarin) - Foreign Language (0547)",
    "Chinese - First Language (0509)",
    "Chinese - Second Language (0523)",
    "Computer Science (0478)",
    "Computer Science (9-1) (0984)",
    "Computer Studies (0420)",
    "Design & Technology (0445)",
    "Design & Technology (9-1) (0979)",
    "Development Studies (0453)",
    "Drama (0411)",
    "Drama (9-1) (0994)",
    "Dutch - Foreign Language (0515)",
    "Economics (0455)",
    "Economics (9-1) (0987)",
    "English - First Language (0500)",
    "English - First Language (9-1) (0990)",
    "English - First Language (9-1) (UK only) (0627)",
    "English - First Language (UK) (0522)",
    "English - First Language (US) (0524)",
    "English - Literature (0486)",
    "English - Literature (9-1) (UK only) (0477)",
    "English - Literature (US) (0427)",
    "English - Literature in English (0475)",
    "English - Literature in English (9-1) (0992)",
    "English - Second Language (9-1) (0991)",
    "English as a Second Language (Count-in speaking) (0511)",
    "English as a Second Language (Speaking endorsement) (0510)",
    "English as a Second Language (Speaking endorsement) (9-1) (0993)",
    "Enterprise (0454)",
    "Environmental Management (0680)",
    "Food & Nutrition (0648)",
    "French (9-1) (7156)",
    "French - First Language (0501)",
    "French - Foreign Language (0520)",
    "Geography (0460)",
    "Geography (9-1) (0976)",
    "German (9-1) (7159)",
    "German - First Language (0505)",
    "German - Foreign Language (0525)",
    "Global Perspectives (0457)",
    "Hindi as a Second Language (0549)",
    "History (0470)",
    "History (9-1) (0977)",
    "History - American (US) (0409)",
    "India Studies (0447)",
    "Information and Communication Technology (0417)",
    "Information and Communication Technology (9-1) (0983)",
    "IsiZulu as a Second Language (0531)",
    "Islamiyat (0493)",
    "Italian (9-1) (7164)",
    "Italian - Foreign Language (0535)",
    "Latin (0480)",
    "Malay - First Language (0696)",
    "Malay - Foreign Language (0546)",
    "Marine Science (Maldives only) (0697)",
    "Mathematics (0580)",
    "Mathematics (9-1) (0980)",
    "Mathematics (US) (0444)",
    "Mathematics - Additional (0606)",
    "Mathematics - International (0607)",
    "Music (0410)",
    "Music (9-1) (0978)",
    "Pakistan Studies (0448)",
    "Physical Education (0413)",
    "Physical Education (9-1) (0995)",
    "Physical Science (0652)",
    "Physics (0625)",
    "Physics (9-1) (0972)",
    "Portuguese - First Language (0504)",
    "Religious Studies (0490)",
    "Sanskrit (0499)",
    "Science - Combined (0653)",
    "Sciences - Co-ordinated (9-1) (0973)",
    "Sciences - Co-ordinated (Double) (0654)",
    "Sociology (0495)",
    "Spanish (9-1) (7160)",
    "Spanish - First Language (0502)",
    "Spanish - Foreign Language (0530)",
    "Spanish - Literature (0488)",
    "Swahili (0262)",
    "Thai - First Language (0518)",
    "Travel & Tourism (0471)",
    "Turkish - First Language (0513)",
    "Urdu as a Second Language (0539)",
    "World Literature (0408)"
};

QStringList subjects_asalevel = {
    "Accounting (9706)",
    "Afrikaans (9679)",
    "Afrikaans - First Language (AS Level only) (8779)",
    "Afrikaans - Language (AS Level only) (8679)",
    "Applied Information and Communication Technology (9713)",
    "Arabic (9680)",
    "Arabic - Language (AS Level only) (8680)",
    "Art & Design (9479)",
    "Art & Design (9704)",
    "Biology (9700)",
    "Business (9609)",
    "Business Studies (9707)",
    "Cambridge International Project Qualification (9980)",
    "Chemistry (9701)",
    "Chinese (A Level only) (9715)",
    "Chinese - Language (AS Level only) (8681)",
    "Classical Studies (9274)",
    "Computer Science (9608)",
    "Computer Science (for final examination in 2021) (9608)",
    "Computer Science (for first examination in 2021) (9618)",
    "Computing (9691)",
    "Design & Textiles (9631)",
    "Design and Technology (9705)",
    "Digital Media & Design (9481)",
    "Divinity (9011)",
    "Divinity (AS Level only) (8041)",
    "Drama (9482)",
    "Economics (9708)",
    "English - Language AS and A Level (9093)",
    "English - Language and Literature (AS Level only) (8695)",
    "English - Literature (9695)",
    "English General Paper (AS Level only) (8021)",
    "Environmental Management (AS only) (8291)",
    "Food Studies (9336)",
    "French (A Level only) (9716)",
    "French - Language (AS Level only) (8682)",
    "French - Literature (AS Level only) (8670)",
    "General Paper 8001 (AS Level only) (8001)",
    "General Paper 8004 (AS Level only) (8004)",
    "Geography (9696)",
    "German (A Level only) (9717)",
    "German - Language (AS Level only) (8683)",
    "Global Perspectives & Research (9239)",
    "Hindi (A Level only) (9687)",
    "Hindi - Language (AS Level only) (8687)",
    "Hindi - Literature (AS Level only) (8675)",
    "Hinduism (9014)",
    "Hinduism (9487)",
    "Hinduism (AS level only) (8058)",
    "History (9489)",
    "History (for final examination in 2021) (9389)",
    "Information Technology (9626)",
    "Islamic Studies (9013 & 8053)",
    "Islamic Studies (9488)",
    "Japanese Language (AS Level only) (8281)",
    "Law (9084)",
    "Marine Science (9693)",
    "Mathematics (9709)",
    "Mathematics - Further (9231)",
    "Media Studies (9607)",
    "Music (9483)",
    "Music (9703)",
    "Music (AS Level only) (8663)",
    "Nepal Studies (AS Level only) (8024)",
    "Physical Education (9396)",
    "Physics (9702)",
    "Portuguese (A Level only) (9718)",
    "Portuguese - Language (AS Level only) (8684)",
    "Portuguese - Literature (AS Level only) (8672)",
    "Psychology (9698)",
    "Psychology (9990)",
    "Sociology (9699)",
    "Spanish (A Level only) (9719)",
    "Spanish - First Language (AS Level only) (8665)",
    "Spanish - Language (AS Level only) (8685)",
    "Spanish - Literature (AS Level only) (8673)",
    "Tamil (9689)",
    "Tamil - Language (AS Level only) (8689)",
    "Thinking Skills (9694)",
    "Travel & Tourism (9395)",
    "Travel and Tourism (9395)",
    "Urdu (A Level only) (9676)",
    "Urdu - Language (AS Level only) (8686)",
    "Urdu - Pakistan only (A Level only) (9686)"

};

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

