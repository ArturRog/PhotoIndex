#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitmapmodel.h"
#include "settingswindow.h"
#include <QGraphicsRectItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_directoryButton_clicked();

    void on_settingsButton_clicked();

    void on_generateButton_clicked();

    void on_saveButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    BitmapModel bitmapModel;
    SettingsWindow settingsWindow;
    QStringList listOfImagesNames;
    QStringList listOfImagesPaths;
    QList<QImage> listOfImages;
    QGraphicsRectItem *rectangle;
    Ui::MainWindow *ui;
    QString selectedDirectoryPath;
    QList<QGraphicsScene*> scenes;

    void resizeImages();
    void drawBitmap(QGraphicsScene* scene);
    void sortNamesList();
    void prepareBitmap(QGraphicsScene* scene, int count);

};

#endif // MAINWINDOW_H
