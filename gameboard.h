#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include <QDebug>
#include "tile.h"

class GameBoard : public QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);

    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();

    Q_PROPERTY(int posX READ readPosX NOTIFY tileChanged)
    int readPosX();
    Q_PROPERTY(int posY READ readPosY NOTIFY tileChanged)
    int readPosY();
    Q_PROPERTY(QString tileNb READ readTileNb NOTIFY tileChanged)
    QString readTileNb();
    Q_PROPERTY(QString tileColor READ readTileColor NOTIFY tileChanged)
    QString readTileColor();


signals:
    void tileChanged();

private:
    Tile tileA, tileB;
    int indX = 0, indY = 0, indNb = 0, indColor = 0;
    int *tileNb[2];
    int *pTilePos[2]; // Indique le vector position
    QString *tileColor[2];

    void verifyTiles();
};

#endif // GAMEBOARD_H
