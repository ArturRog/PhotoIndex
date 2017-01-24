#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "settingswindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QPrinter>
#include <QPrintDialog>
#include <algorithm>
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    bitmapModel(800,600),
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
    selectedDirectoryPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);


    QDir selectedDirectory(selectedDirectoryPath);
    selectedDirectory.setNameFilters(QStringList() << "*.bmp" << "*.gif" << "*.jpg");
    listOfImagesNames =  selectedDirectory.entryList();
    for(QString imagesNames : listOfImagesNames)
    {
        QString path = selectedDirectoryPath + "/" + imagesNames;
        listOfImagesPaths.append(path);
        listOfImages.append(QImage(path));
    }

    resizeImages();
    sortNamesList();
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
    for(QImage img : listOfImages) {
        QImage tempImage = img.scaled(bitmapModel.getImageHeight(), bitmapModel.getImageWidth());
        temp.append(tempImage);
    }
    listOfImages.clear();
    listOfImages = temp;
}

void  MainWindow::drawBitmap(QGraphicsScene* scene)
{
    ui->graphicsView->setScene(scene);
}


void  MainWindow::prepareBitmap(QGraphicsScene* scene, int count)
{
  //Directory Name
    QGraphicsTextItem *dirName = scene->addText(selectedDirectoryPath);
    QFont dirNameAndPageNumberFont;
    dirNameAndPageNumberFont.setPointSize(10);
    dirNameAndPageNumberFont.setBold(true);

    dirName->setFont(dirNameAndPageNumberFont);
    dirName->moveBy(400 - 4 * selectedDirectoryPath.length(), -10);

  //Page Number
    QString pageNumber;
    pageNumber += "\n Page number: ";
    pageNumber += std::to_string(count).c_str();

    QGraphicsTextItem *pNumber = scene->addText(pageNumber);
    pNumber->setFont(dirNameAndPageNumberFont);
    pNumber->moveBy(400 - 4.5 * pageNumber.length() , -5);

   //Comment
    QString comm;
    comm += settingsWindow.getBitMmapModel().getComment().c_str();
    QGraphicsTextItem *comment = scene->addText(comm);
    comment->setTextWidth(750);
    comment->moveBy(25, 580);

   //Bitmap
    int dx = 25, dy = 40;
    int tdx = 25, tdy = 140;
    int counter = 0;
    QList<QString>::const_iterator nameIter = listOfImagesNames.cbegin() + count * 20;
    QList<QImage>::const_iterator it = listOfImages.cbegin();
    std::advance(it, count * 20);
    int loopCounter = 0;

    do {
        QPixmap image(QPixmap::fromImage(*it));
        QGraphicsPixmapItem *imageItem = scene->addPixmap(image);
        QString imageName = *nameIter;
        if(nameIter->length() > 23) {
            QString temp = "~";
            temp += imageName;
            imageName = temp.mid(0, 23);
        }
        QGraphicsTextItem *text = scene->addText(imageName);

        ++counter;

        if(counter < 6) {
            imageItem->moveBy(dx, dy);
            text->moveBy(tdx, tdy);
            dx += 155;
            tdx += 155;
            if(counter == 5) {
                dx = 25;
                dy += 140;
                tdx = 25;
                tdy += 140;
                counter = 0;
            }
        }
        ++nameIter;
        ++it;


        ++loopCounter;
    } while ( loopCounter < 20 && it != listOfImages.cend());
}

void MainWindow::on_generateButton_clicked()
{

    if (listOfImages.size() == 0){
        MainWindow::on_directoryButton_clicked();
    }
    else{
        int max = std::ceil(listOfImages.size() / 20) + 1;
        int counter = 1;
        do {
            QGraphicsScene* scene = new QGraphicsScene(QRect(QPoint(0,0), QPoint(800,600)));
            scenes.append(scene);
            prepareBitmap(scene, counter - 1);
            ++counter;
        } while( counter == max );

        drawBitmap(scenes.first());
    }

}

void  MainWindow::sortNamesList()
{
    std::sort(listOfImagesNames.begin(), listOfImagesNames.end());
}

void MainWindow::on_saveButton_clicked()
{
    if (listOfImages.size() == 0){
        MainWindow::on_directoryButton_clicked();

    }
    else{
        QString fileName= QFileDialog::getSaveFileName(this, "Save image", QCoreApplication::applicationDirPath(), "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)" );
            if (!fileName.isNull()) {
                QPixmap pixMap = this->ui->graphicsView->grab();
                pixMap.save(fileName);
            }

        QPrinter printer;
        QPrintDialog *dlg = new QPrintDialog(&printer,0);
        if(dlg->exec() == QDialog::Accepted) {
               QImage img(fileName);
               QPainter painter(&printer);
               painter.drawImage(QPoint(0,0),img);
               painter.end();
        }

        delete dlg;
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if (listOfImages.size() == 0){
        MainWindow::on_directoryButton_clicked();

    }
    else if (arg1 >= scenes.length()){
        MainWindow::on_spinBox_valueChanged(arg1-1);
    }
    else drawBitmap(scenes.at(arg1));
}
