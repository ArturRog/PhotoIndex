#ifndef BITMAPMODEL_H
#define BITMAPMODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class BitmapModel
{
public:
    BitmapModel();

private:
    double height;
    double width;
    double icons_num;
    std::string comment;
};

#endif // BITMAPMODEL_H
