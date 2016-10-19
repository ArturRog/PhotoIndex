#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "settingswindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    bitmapModel(800,600,4,5),
    settingsWindow(bitmapModel),
    ui(new Ui::MainWindow)
{
    settingsWindow.setModal(true);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_directoryButton_clicked()
{
    QString selectedDirectoryPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);


    QDir selectedDirectory(selectedDirectoryPath);
    selectedDirectory.setNameFilters(QStringList() << "*.bmp" << "*.gif" << "*.jpg");
    QStringList imagesToIndex = selectedDirectory.entryList();
}

void MainWindow::on_settingsButton_clicked()
{
//    SettingsWindow w;
//    w.setModal(true);
    settingsWindow.exec();
}
