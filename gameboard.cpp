#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    tileA.setPosition(10,10); tileB.setPosition(70,70);

    tileNb[0] = tileA.getRefNumber();
    tileNb[1] = tileB.getRefNumber();
    tileA.multNumber(2);

    pTilePos[0] = tileA.getRefPosVect();
    pTilePos[1] = tileB.getRefPosVect();
    qDebug() << "Tile A position ("<< *pTilePos[0] << "," << *(pTilePos[0]+1) << ")";
    qDebug() << "Tile B position ("<< *pTilePos[1] << "," << *(pTilePos[1]+1) << ")";

    qDebug() << "Objet GameBoard crée";
    tileChanged();
}

void GameBoard::moveRight()
{
    tileA.setPosition(190,0);
    tileB.setPosition(130,0);
    qDebug() << "moveRight";
    tileChanged();
}

void GameBoard::moveLeft()
{
    tileA.setPosition(10,0);
    tileB.setPosition(70,0);
    qDebug() << "moveLeft";
    tileChanged();
}

void GameBoard::moveUp()
{
    tileA.setPosition(0,10);
    tileB.setPosition(0,70);
    qDebug() << "moveLeft";
    tileChanged();
}

void GameBoard::moveDown()
{
    tileA.setPosition(0,190);
    tileB.setPosition(0,130);
    qDebug() << "moveLeft";
    tileChanged();
}


int GameBoard::readPosX()
{
    if (indX == 2){
        indX = 0;
    }
    return *pTilePos[indX++];

}

int GameBoard::readPosY()
{
    if (indY == 2){
        indY = 0;
    }
    return *(pTilePos[indY++]+1);
}

QString GameBoard::readTileNb()
{
    if (indNb == 2){
        indNb = 0;
    }
    return QString::number(*tileNb[indNb++]);
}
