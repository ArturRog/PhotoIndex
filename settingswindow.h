#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include "bitmapmodel.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(BitmapModel bitmapModel,QWidget *parent = 0);
    ~SettingsWindow();
    BitmapModel getBitMmapModel();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_textEdit_3_textChanged();

    void on_textEdit_5_textChanged();

private:

    void show_number_of_icons();

    BitmapModel bitmapModel;

    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
