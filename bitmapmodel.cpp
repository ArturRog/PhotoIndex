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

int BitmapModel::getRow() const
{
    return row;
}

void BitmapModel::setRow(int value)
{
    row = value;
}

int BitmapModel::getColumn() const
{
    return column;
}

void BitmapModel::setColumn(int value)
{
    column = value;
}

int BitmapModel::getIcons_num() const
{
    return icons_num;
}

void BitmapModel::setIcons_num(int value)
{
    icons_num = value;
}

std::string BitmapModel::getComment() const
{
    return comment;
}

void BitmapModel::setComment(const std::string &value)
{
    comment = value;
}
