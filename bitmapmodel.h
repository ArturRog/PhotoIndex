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
    {
        /*imageWidth = (0.8*width-(column-1)*0.03*width)/5;
        imageHeight = (0.8*height-(row-1)*0.03*height)/5; */
        imageWidth = 130;
        imageHeight = 100;
    }

    int getImageWidth() const;
    int getImageHeight() const;

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    int getRow() const;
    void setRow(int value);

    int getColumn() const;
    void setColumn(int value);

    int getIcons_num() const;
    void setIcons_num(int value);

    std::string getComment() const;
    void setComment(const std::string &value);

private:
    int width;
    int height;
    int row;
    int column;
    int icons_num;
    std::string comment;
    int imageWidth;
    int imageHeight;
};
#endif // BITMAPMODEL_H
