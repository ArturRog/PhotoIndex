#ifndef BITMAPMODEL_H
#define BITMAPMODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class BitmapModel
{
public:
    BitmapModel();
    BitmapModel(int width, int height): width(width), height(height)
    {
        imageWidth = 130;
        imageHeight = 100;
    }

    int getImageWidth() const;
    int getImageHeight() const;

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    std::string getComment() const;
    void setComment(const std::string &value);

private:
    int width;
    int height;
    std::string comment;
    int imageWidth;
    int imageHeight;
};
#endif // BITMAPMODEL_H
