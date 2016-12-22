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
    selectedDirectoryPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
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
    for(QImage img : listOfImages)
    {
        QImage tempImage = img.scaled(bitmapModel.getImageWidth(), bitmapModel.getImageHeight());
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
    QFont dirNameFont;
    dirNameFont.setPointSize(11);
    dirNameFont.setBold(true);

    dirName->setFont(dirNameFont);
    dirName->moveBy(400 - 5 * selectedDirectoryPath.length(), 0);

  //Page Number
    QString pageNumber;
    pageNumber += "\n Page number: ";
    pageNumber += std::to_string(count).c_str();

    QGraphicsTextItem *pNumber = scene->addText(pageNumber);
    QFont pageNumberFont;
    pageNumberFont.setPointSize(11);
    pageNumberFont.setBold(true);

    pNumber->setFont(pageNumberFont);
    pNumber->moveBy(400 - 5 * pageNumber.length() , 0);

   //Comment
    QString comm;
    comm += settingsWindow.getBitMmapModel().getComment().c_str();
    QGraphicsTextItem *comment = scene->addText(comm);
    comment->moveBy(400- 5 * comm.length(), 550);
//
   //Bitmap
    int dx = 25, dy = 40;
    int tdx = 50, tdy = 170;
    int counter = 0;
    QList<QString>::const_iterator nameIter = listOfImagesNames.cbegin() + count * 20;
    QList<QImage>::const_iterator it = listOfImages.cbegin();
    std::advance(it, count * 20);
    int loopCounter = 0;

    do {
        QPixmap image(QPixmap::fromImage(*it));
        QGraphicsPixmapItem *imageItem = scene->addPixmap(image);
        QString imageName = *nameIter;
        if(nameIter->length() > 10) {
            QString temp = "~";
            temp += imageName;
            imageName = temp.mid(0, 6);
        }
        QGraphicsTextItem *text = scene->addText(imageName);
        ++nameIter;
        ++counter;

        if(counter < 6) {
            imageItem->moveBy(dx, dy);
            text->moveBy(tdx, tdy);
            dx += 155;
            tdx += 155;
            if(counter == 5) {
                dx = 25;
                dy += 160;
                tdx = 50;
                tdy += 160;
                counter = 0;
            }
        }
        ++it;
        ++loopCounter;
    } while (loopCounter == 20 || it != listOfImages.cend());

    // C:\Users\jakubs\Desktop\PGK\Projekt\ZdjeciuszkaTestowe
}



void MainWindow::on_generateButton_clicked()
{
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


void  MainWindow::sortNamesList()
{
    std::sort(listOfImagesNames.begin(), listOfImagesNames.end());
}

void MainWindow::on_saveButton_clicked()
{
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

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    drawBitmap(scenes.at(arg1));

}
