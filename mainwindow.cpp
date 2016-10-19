#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "settingswindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_directoryButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
}

void MainWindow::on_settingsButton_clicked()
{
    SettingsWindow w;
    w.setModal(true);
    w.exec();
}
