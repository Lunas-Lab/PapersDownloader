#include "papersdownloader.h"
#include "ui_papersdownloader.h"
#include "myfuncs.h"
#include <QFileDialog>
#include <QString>
#include <iostream>

#define IGCSE 0
#define ASALEVEL 1

struct verify {         //struct for cerification data
    bool levelFilled = false;
    bool subjectFilled = false;
    bool paperFilled = false;
    bool sessionFilled = false;
    bool dirFilled = true;
    bool variantFilled = false;
    bool typeFilled = true;
};

struct paperInformation {   //struct for information about the papers required
    QString level;
    QString subject;
    QString year = "19";
    QString paper;
    QString session;
    QString variant;
    QString type;
    QString courseCode;
    QString site;
    QString rootDir = "Downloads";
    QString drive;
    QString folder;
    bool asAddYear;
};

int yearInt;

paperInformation info;

verify verify;

PapersDownloader::PapersDownloader(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PapersDownloader)
{
    ui->setupUi(this);
    ui->levelBox->setPlaceholderText("Select your level here");     //access functions to set placeholder texts, etc
    ui->subjectBox->setPlaceholderText("Select your subject here");
}

PapersDownloader::~PapersDownloader()
{
    delete ui;
}

void PapersDownloader::loadOptions(int index) {
    ui->subjectBox->setCurrentIndex(-1);
    ui->subjectBox->clear();
    switch (index) {
    case IGCSE :
        ui->subjectBox->addItems(MYFUNCS_H::subjects_igcse);
        break;
    case ASALEVEL :
        ui->subjectBox->addItems(MYFUNCS_H::subjects_asalevel);
        break;
    };
}

void PapersDownloader::on_levelBox_currentIndexChanged(int index)
{
    PapersDownloader::loadOptions(index);
    verify.levelFilled = true;
    info.level = ui->levelBox->currentText();

}

void PapersDownloader::on_yearSpin_valueChanged(int arg1)
{
    ui->yearSlider->setSliderPosition(arg1);
    info.year = QString::number(arg1);
    if (arg1 <= 9) {
        info.year.prepend("0");
    }
}

void PapersDownloader::on_yearSlider_sliderMoved(int position)
{
    ui->yearSpin->setValue(position);
    info.year = QString::number(position);
    if (position <= 9) {
        info.year.prepend("0");
    }
}

void PapersDownloader::on_chooseDirButton_clicked()
{
    QFileDialog saveDir(this);
    saveDir.setFileMode(QFileDialog::Directory);
    saveDir.setViewMode(QFileDialog::List);
    if (saveDir.exec()) {
        ui->dirBox->setText(saveDir.selectedFiles()[0]);
        info.rootDir = saveDir.selectedFiles()[0];
        info.drive = info.rootDir.at(0);
        verify.dirFilled = true;
    }


}

void PapersDownloader::on_downloadButton_clicked()
{
    if (ui->qpBox->isChecked() || ui->msBox->isChecked() || ui->gtBox->isChecked() || ui->otherBox->isChecked()) {
        verify.typeFilled = true;
    }
    if (ui->gceguideBox->isChecked()) {
        info.site = "\"https://papers.gceguide.com/";
    }
    else
        info.site = "\"https://papers.xtremepape.rs/CAIE/";
    if (ui->levelBox->currentIndex() == 1 && info.asAddYear == true && ui->gceguideBox->isChecked()) {
        info.subject.append("/20");
        info.subject.append(info.year);
    }
    if (ui->gceguideBox->isChecked() && info.level == "AS and A Level") {
        info.level = "A Levels";
    }
    if (verify.levelFilled && verify.subjectFilled && verify.paperFilled && verify.sessionFilled && verify.dirFilled && verify.typeFilled) {
        if (ui->qpBox->isChecked()) {
            info.type = "qp";
            MYFUNCS_H::curl(MYFUNCS_H::url(info.level, info.subject, info.year, info.paper, info.session, info.variant, info.type, info.courseCode, info.site, false, false, ""), info.drive, info.rootDir, info.folder);
        }
        if (ui->msBox->isChecked()) {
            info.type = "ms";
            MYFUNCS_H::curl(MYFUNCS_H::url(info.level, info.subject, info.year, info.paper, info.session, info.variant, info.type, info.courseCode, info.site, false, false, ""), info.drive, info.rootDir, info.folder);
        }
        if (ui->gtBox->isChecked()) {
            info.type = "gt";
            info.paper = "";
            info.variant = "";
            MYFUNCS_H::curl(MYFUNCS_H::url(info.level, info.subject, info.year, info.paper, info.session, info.variant, info.type, info.courseCode, info.site, true, false, ""), info.drive, info.rootDir, info.folder);
        }
        if (ui->otherBox->isChecked()) {
            info.type = ui->otherLineEdit->text();
            MYFUNCS_H::curl(MYFUNCS_H::url(info.level, info.subject, info.year, info.paper, info.session, info.variant, info.type, info.courseCode, info.site, false, true, ui->fileExtensionLineEdit->text()), info.drive, info.rootDir, info.folder);
        }
    }
    else if (!verify.levelFilled || !verify.subjectFilled || !verify.paperFilled || !verify.sessionFilled || !verify.dirFilled || !verify.typeFilled) {
        ui->errorLabel->setText("Please ensure you have filled out everything");
    }
    info.paper = ui->paperBox->text();
    if (ui->noVariantBox->isChecked() == false) {
            info.variant = ui->variantBox->text();
    }
    else if (ui->noVariantBox->isChecked() == true) {
        info.variant = "";
    }
}



void PapersDownloader::on_sessionBox_currentTextChanged(const QString &arg1)
{
    info.session = arg1;
    if (arg1 != 0) {
        verify.sessionFilled = true;
    }
    else
        verify.sessionFilled = false;
}

void PapersDownloader::on_paperBox_textChanged(const QString &arg1)
{
    info.paper = ui->paperBox->text();
    if (ui->paperBox->text() != "0") {
        verify.paperFilled = true;
    }
    else
        verify.paperFilled = false;
}

void PapersDownloader::on_noVariantBox_stateChanged(int arg1)
{
    if (arg1) {
        ui->variantBox->setEnabled(false);
        info.variant = "";
        verify.variantFilled = true;
    }
    else
        ui->variantBox->setEnabled(true);
        if (ui->variantBox->value() == 0) {
            verify.variantFilled = false;
        }
}

void PapersDownloader::on_variantBox_textChanged(const QString &arg1)
{
    info.variant = arg1;
    verify.variantFilled = true;
}

void PapersDownloader::on_subjectBox_currentTextChanged(const QString &arg1)
{
    verify.subjectFilled = true;
    info.folder = arg1;
    info.subject = arg1;
    info.courseCode = MYFUNCS_H::extractCourse(arg1);
}

void PapersDownloader::on_otherBox_stateChanged(int arg1)
{
    ui->otherLineEdit->setEnabled(arg1);
    ui->fileExtensionLineEdit->setEnabled(arg1);
}

void PapersDownloader::on_gceguideBox_toggled(bool checked)
{
    ui->sessionBox->setCurrentIndex(-1);
    ui->sessionBox->removeItem(2);
    if (checked) {
        ui->sessionBox->addItem("m");
    }
    else
        ui->sessionBox->addItem("y");
}

void PapersDownloader::on_subjectBox_currentIndexChanged(int index)
{
    if (index == 9 || index == 56 || index == 0) {
        info.asAddYear = true;
    }
    else
        info.asAddYear = false;
}
