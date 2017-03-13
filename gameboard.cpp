#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    for (int i=0; i < 4 ; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j] = new Tile(i*60 + 10, j*60 + 10);
            tilesQml[i + j*4] = tiles[i][j];
        }
    }
    refreshRef();
    tiles[0][0]->setNumber();
    tiles[0][0]->multNumber();
    tiles[0][1]->setNumber();

    qDebug() << "Object GameBoard created";
    tileChanged();
}

GameBoard::~GameBoard()
{
    for (int i=0; i < 4 ; i++){
        for (int j=0; j < 4; j++){
            delete tiles[i][j];
        }
    }
    qDebug() << "Objects destroyed";
}

void GameBoard::moveRight()
{
    if (moveVertical == false){
        Tile* temp[4];
        for (int i=0; i < 4; i++){
            temp[i] = tiles[0][i];
            tiles[0][i] = tiles[3][i];
            tiles[3][i] = temp[i];
        }
        refreshRef();
        qDebug() << "moveRight";
        verifyTiles();
        tileChanged();
        moveVertical = true;
    }
}

void GameBoard::moveLeft()
{  
    if (moveVertical == true){
        Tile* temp[4];
        for (int i=0; i < 4; i++){
            temp[i] = tiles[0][i];
            tiles[0][i] = tiles[3][i];
            tiles[3][i] = temp[i];
        }
        refreshRef();
        qDebug() << "moveLeft";
        verifyTiles();
        tileChanged();
        moveVertical = false;
    }
}

void GameBoard::moveUp()
{
    if (moveHorizontal == true){
        Tile* temp[4];
        for (int i=0; i < 4; i++){
            temp[i] = tiles[i][0];
            tiles[i][0] = tiles[i][3];
            tiles[i][3] = temp[i];
        }
        refreshRef();
        qDebug() << "moveUp";
        verifyTiles();
        tileChanged();
        moveHorizontal = false;
    }
}

void GameBoard::moveDown()
{
    if (moveHorizontal == false){
        Tile* temp[4];
        for (int i=0; i < 4; i++){
            temp[i] = tiles[i][0];
            tiles[i][0] = tiles[i][3];
            tiles[i][3] = temp[i];
        }
        refreshRef();
        qDebug() << "moveDown";
        verifyTiles();
        tileChanged();
        moveHorizontal = true;
    }
}


int GameBoard::readPosX()
{
    if (indX == 16){
        indX = 0;
    }
    return tilesQml[indX++]->getPosition(0);
}

int GameBoard::readPosY()
{
    if (indY == 16){
        indY = 0;
    }
    return tilesQml[indY++]->getPosition(1);
}

QString GameBoard::readTileNb()
{
    if (indNb == 16){
        indNb = 0;
    }
    return tilesQml[indNb++]->getNumber();
}

QString GameBoard::readTileColor()
{
    if (indColor == 16){
        indColor = 0;
    }
    return tilesQml[indColor++]->getColor();
}

QString GameBoard::readTileTextColor()
{
    if (indTextColor == 16){
        indTextColor = 0;
    }
    return tilesQml[indTextColor++]->getTextColor();
}

void GameBoard::verifyTiles()
{

    if (tilesQml[0]->getPosition(0) == 190){
        qDebug() << "Ops";
        tilesQml[0]->multNumber();
        tileChanged();
    }
}

void GameBoard::refreshRef()
{
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j]->setPosition(i*60 + 10, j*60 + 10);
            matrixNb[i][j] = tiles[i][j]->getRefNumber();
        }
    }
}

void GameBoard::printInfo()
{
    qDebug() << "matrixNb:";
    for (int j=0; j < 4; j++){
       qDebug() << *matrixNb[0][j] << "," << *matrixNb[1][j] << "," << *matrixNb[2][j] << "," << *matrixNb[3][j];
    }
}
