#ifndef TILE_H
#define TILE_H

#include <QString>
#include <vector>

class Tile
{
public:
    Tile(int x=10, int y=10);

    void setPosition(int x=0, int y=0);
    void setColor(QString c);
    void multNumber(int n=2);

    int getPosition(int a);
    QString getColor();
    QString getNumber();
    int *getRefNumber();
    int *getRefPosVect();


protected:
    int tilePosition[2];
    QString color;
    int number;
};

#endif // TILE_H
