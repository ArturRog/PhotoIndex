#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
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
    QString width = ui->textEdit->toPlainText();
    QString height = ui->textEdit_2->toPlainText();
    QString icons_num = ui->textEdit_3->toPlainText();
//    QString comment = ui->textEdit_4->toPlainText();

    ui->textEdit_4->setText(width + height + icons_num);
}
