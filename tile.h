#ifndef TILE_H
#define TILE_H

#include <QString>
#include <QDebug>
#include <vector>

class Tile
{
public:
    Tile(int x=10, int y=10);

    void setPosition(int x=0, int y=0);
    void setColor();
    void setFusion(bool f = false);
    void multNumber(int n=2);
    void setNumber(int a=2);
    void resetTile();

    int getPosition(int a);
    QString getColor();
    QString getTextColor();
    QString getNumber();
    bool getFusion();
    int *getRefPosVect();
    QString *getRefColor();
    int *getRefNumber();


protected:
    int tilePosition[2];
    QString tileColor, textColor;
    int number;
    bool fusion;
};

#endif // TILE_H
