#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(BitmapModel bitmapModel,QWidget *parent) :
    QDialog(parent),
    bitmapModel(bitmapModel),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_pushButton_2_clicked()
{
    this->close();
}

void SettingsWindow::on_pushButton_clicked()
{
    bitmapModel.setComment(ui->textEdit_4->toPlainText().toStdString());
    this->close();
}

BitmapModel SettingsWindow::getBitMmapModel() {
    return bitmapModel;
}
