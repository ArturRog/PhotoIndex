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

    bitmapModel.setWidth(ui->textEdit->toPlainText().toInt());
    bitmapModel.setHeight(ui->textEdit_2->toPlainText().toInt());
    bitmapModel.setColumn(ui->textEdit_3->toPlainText().toInt());
    bitmapModel.setRow(ui->textEdit_5->toPlainText().toInt());
    bitmapModel.setComment(ui->textEdit_4->toPlainText().toStdString());
    this->close();
}

void SettingsWindow::show_number_of_icons(){
    int columns = ui->textEdit_3->toPlainText().toInt();
    int rows = ui->textEdit_5->toPlainText().toInt();
    int iconsNumber = columns*rows;
    ui->label_7->setText(QString::number(iconsNumber));
}

void SettingsWindow::on_textEdit_3_textChanged()
{
    show_number_of_icons();
}

void SettingsWindow::on_textEdit_5_textChanged()
{
    show_number_of_icons();
}

BitmapModel SettingsWindow::getBitMmapModel() {
    return bitmapModel;
}
