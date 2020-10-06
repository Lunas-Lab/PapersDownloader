#ifndef PAPERSDOWNLOADER_H
#define PAPERSDOWNLOADER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PapersDownloader; }
QT_END_NAMESPACE

class PapersDownloader : public QWidget
{
    Q_OBJECT

public:
    PapersDownloader(QWidget *parent = nullptr);
    ~PapersDownloader();

private slots:
    void on_levelBox_currentIndexChanged(int index);

    void on_yearSpin_valueChanged(int arg1);

    void on_yearSlider_sliderMoved(int position);

    void on_chooseDirButton_clicked();
    
    void on_downloadButton_clicked();

    void on_sessionBox_currentTextChanged(const QString &arg1);

    void on_paperBox_textChanged(const QString &arg1);

    void on_noVariantBox_stateChanged(int arg1);

    void on_variantBox_textChanged(const QString &arg1);

    void on_subjectBox_currentTextChanged(const QString &arg1);

    void on_otherBox_stateChanged(int arg1);

    void on_gceguideBox_toggled(bool checked);

    void on_subjectBox_currentIndexChanged(int index);

private:
    Ui::PapersDownloader *ui;
    void loadOptions(int index);
};
#endif //PAPERSDOWNLOADER_H
