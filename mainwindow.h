#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitmapmodel.h"
#include "settingswindow.h"


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

private:
    BitmapModel bitmapModel;
    SettingsWindow settingsWindow;
    QStringList listOfImagesNames;
    QStringList listOfImagesPaths;
    QList<QImage> listOfImages;

    Ui::MainWindow *ui;

    void resizeImages();
    void drawBitmap();

};

#endif // MAINWINDOW_H
