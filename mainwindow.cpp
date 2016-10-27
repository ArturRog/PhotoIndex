#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "settingswindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    bitmapModel(800,600,4,5),
    settingsWindow(bitmapModel),
    ui(new Ui::MainWindow)
{
    settingsWindow.setModal(true);
    ui->setupUi(this);

    //listOfImagesNames.append();
    //listOfImagesPaths.append();
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
   // bitmapModel.
    listOfImagesNames =  selectedDirectory.entryList();
    for(QString imagesNames : listOfImagesNames)
    {
        QString path = selectedDirectoryPath+"/"+imagesNames;
        listOfImagesPaths.append(path);
        listOfImages.append(QImage(path));
    }

    std::cout << "asd";
}

void MainWindow::on_settingsButton_clicked()
{
//    SettingsWindow w;
//    w.setModal(true);
    settingsWindow.exec();
}

void  MainWindow::resizeImages()
{
    QList<QImage> temp;
    for(QImage img : listOfImages)
    {
        QImage tempImage = img.scaled(bitmapModel.getImageWidth(), bitmapModel.getImageHeight());
        temp.append(tempImage);
    }
    listOfImages.clear();
    listOfImages = temp;
    std::cout << "a";
}

void  MainWindow::drawBitmap()
{

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene, this);
    ui->graphicsView->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(listOfImages.at(1)));
    QGraphicsPixmapItem* item2 = new QGraphicsPixmapItem(QPixmap::fromImage(listOfImages.at(1)));
    //rectangle = scene->addRect(10,10,bitmapModel.getImageWidth(), bitmapModel.getHeight());
    //rectangle->
    scene->addItem(item);
    scene->addItem(item2);

    QString fileName= QFileDialog::getSaveFileName(this, "Save image", QCoreApplication::applicationDirPath(), "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)" );
        if (!fileName.isNull())
        {
            QPixmap pixMap = this->ui->graphicsView->grab();
            pixMap.save(fileName);
        }
//http://stackoverflow.com/questions/21987818/show-two-images-in-one-qgraphicsview
}

void MainWindow::on_generateButton_clicked()
{
    resizeImages();
    drawBitmap();
}
