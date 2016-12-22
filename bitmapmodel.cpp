#include "bitmapmodel.h"

BitmapModel::BitmapModel()
{

}

int BitmapModel::getImageWidth() const
{
    return imageHeight;
}

int BitmapModel::getImageHeight() const
{
    return imageWidth;
}

int BitmapModel::getWidth() const
{
    return width;
}

void BitmapModel::setWidth(int value)
{
    width = value;
}

int BitmapModel::getHeight() const
{
    return height;
}

void BitmapModel::setHeight(int value)
{
    height = value;
}

std::string BitmapModel::getComment() const
{
    return comment;
}

void BitmapModel::setComment(const std::string &value)
{
    comment = value;
}
