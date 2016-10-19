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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    BitmapModel bitmapModel;

    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
