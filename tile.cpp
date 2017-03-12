#include "tile.h"

Tile::Tile(int x, int y)
{
    tilePosition[0] = x;
    tilePosition[1] = y;
    number = 2;
    setColor();
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

void Tile::setColor()
{
    if (number == 0){
        color = "#00000000";
    }
    if (number == 2){
        color = "#04f211";
    }
    if (number == 4){
        color = "#229468";
    }
    if (number == 8){
        color = "#225594";
    }
    if (number == 16){
        color = "#482294";
    }
    if (number == 32){
        color = "#812294";
    }
}

void Tile::multNumber(int n)
{
    number *= n;
    setColor();
}

void Tile::resetTile()
{
    number = 0;
    setColor();
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

QString *Tile::getRefColor()
{
    QString *pcolor = &color;
    return pcolor;
}
