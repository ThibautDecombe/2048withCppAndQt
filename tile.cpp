#include "tile.h"

Tile::Tile(int x, int y)
{
    tilePosition[0] = x;
    tilePosition[1] = y;
    color = "f5bb72";
    number = 2;
}

void Tile::setPosition(int x, int y)
{
    if (x != 0){
        tilePosition[0] = x;
    }
    if (y != 0){
        tilePosition[1] = y;
    }
}

void Tile::setColor(QString c)
{
    color = c;
}

void Tile::multNumber(int n)
{
    number *= n;
}

int Tile::getPosition(int a)
{
    return tilePosition[a];
}

QString Tile::getColor()
{
    return color;
}

QString Tile::getNumber()
{
    return QString::number(number);
}

int *Tile::getRefNumber()
{
    int *n = &number;
    return n;
}

int *Tile::getRefPosVect()
{
    int *pvec = &tilePosition[0];
    return pvec;
}
