#include "tile.h"

Tile::Tile(int x, int y)
{
    tilePosition[0] = x;
    tilePosition[1] = y;
    number = 0;
    fusion = false;
    setColor();
    //qDebug() << "Objet Tile created! Pos: (" << tilePosition[0] << "," << tilePosition[1] << ") number :" << number;
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
        tileColor = "#00000000";
    }
    if (number == 2){
        tileColor = "#04f211";
    }
    if (number == 4){
        tileColor = "#229468";
    }
    if (number == 8){
        tileColor = "#225594";
    }
    if (number == 16){
        tileColor = "#482294";
    }
    if (number == 32){
        tileColor = "#812294";
    }
}

void Tile::setFusion(bool f)
{
    fusion = f;
}

void Tile::multNumber(int n)
{
    number *= n;
    setColor();
}

void Tile::setNumber(int a)
{
    number = a;
    setColor();
}

void Tile::resetTile()
{
    fusion = false;
    number = 0;
    setColor();
}

int Tile::getPosition(int a)
{
    return tilePosition[a];
}

QString Tile::getColor()
{
    return tileColor;
}

QString Tile::getTextColor()
{
    if (number == 0){
        return "#00000000";
    }
    else
        return "#0a4403";

}

QString Tile::getNumber()
{
    return QString::number(number);
}

bool Tile::getFusion()
{
    return fusion;
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
    QString *pcolor = &tileColor;
    return pcolor;
}
