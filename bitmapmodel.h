#ifndef BITMAPMODEL_H
#define BITMAPMODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class BitmapModel
{
public:
    BitmapModel();
    BitmapModel(int width, int height, int row, int column)
        : width(width), height(height), row(row), column(column), icons_num(row*column)
    {}

private:
    int width;
    int height;
    int row;
    int column;
    int icons_num;
    std::string comment;

};

#endif // BITMAPMODEL_H
