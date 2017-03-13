#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    tileA.setPosition(10,10); tileB.setPosition(70,70);

    tileNb[0] = tileA.getRefNumber();
    tileNb[1] = tileB.getRefNumber();
    tileColor[0] = tileA.getRefColor();
    tileColor[1] = tileB.getRefColor();
    qDebug() << "Color A: " << *tileColor[0] << "Color B: " << *tileColor[1];


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
    tileB.setPosition(190,0);
    qDebug() << "moveRight";
    verifyTiles();
    tileChanged();
}

void GameBoard::moveLeft()
{
    tileA.setPosition(10,0);
    tileB.setPosition(70,0);
    qDebug() << "moveLeft";
    verifyTiles();
    tileChanged();
}

void GameBoard::moveUp()
{
    tileA.setPosition(0,10);
    tileB.setPosition(0,70);
    qDebug() << "moveLeft";
    verifyTiles();
    tileChanged();
}

void GameBoard::moveDown()
{
    tileA.setPosition(0,190);
    tileB.setPosition(0,190);
    qDebug() << "moveLeft";
    verifyTiles();
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

QString GameBoard::readTileColor()
{
    if (indColor == 2){
        indColor = 0;
    }
    return *tileColor[indColor++];
}

void GameBoard::verifyTiles()
{
    if (*pTilePos[0] == *pTilePos[1] && *(pTilePos[0]+1) == *(pTilePos[1]+1)){
        qDebug() << "Ops";
        tileA.multNumber();
        tileB.resetTile();
        tileB.setPosition(10,10);
        tileChanged();
    }
}

void GameBoard::verifyRight(){

    Tile* temp[3];

    bool randomVal = False;

    for (int j = 0; j < 4; j++){              //line loop
        for (int i = 3; i > 0; i--){          //column loop
            if ((*matrixNb[i][j] == 0) && (*matrixNb[i-1][j] != 0)){
                temp[0] = tiles[i][j];
                //move line
                for (int k = i; k > 0; k--){
                    tiles[k][j] = tiles[k-1][j];
                }
                tiles[0][j] = temp[0];
                //True = call random function after 'for' loops
                randomVal = True;
            }
            if (((i == 3)||(i == 2)) && (*matrixNb[i][j] == 0) && (*matrixNb[i-1][j] == 0) && (*matrixNb[i-2][j] != 0)){
                temp[0] = tiles[i][j];
                temp[1] = tiles[i-1][j];
                for (int k = i; k > 1; k--){
                    tiles[k][j] = tiles[k-2][j];
                }
                tiles[0][j] = temp[1];
                tiles[1][j] = temp[0];
                randomVal = True;
            }
            if ((i == 3) && (*matrixNb[i][j] == 0) && (*matrixNb[i-1][j] == 0) && (*matrixNb[i-2][j] == 0) && (*matrixNb[i-3][j] != 0)){
                temp[0] = tiles[i][j];       //in case we make bigger grids...
                temp[1] = tiles[i-1][j];
                temp[2] = tiles[i-2][j];
                for (int k = i; k > 2; k--){
                    tiles[k][j] = tiles[k-3][j];
                }
                tiles[0][j] = temp[2];
                tiles[1][j] = temp[1];
                tiles[2][j] = temp[0];
                randomVal = True;
            }
            if (*matrixNb[i][j] == *matrixNb[i-1][j]){
                temp[0] = tiles[i][j];
                //move line
                for (int k = i; k > 0; k--){
                    tiles[k][j] = tiles[k-1][j];
                }
                tiles[0][j] = temp[0];
                //change values
                tiles[i][j]->multNumber();
                tiles[i][j]->resetTile();
                //True = call random function after 'for' loops
                randomVal = True;
            }
        }
    }

    if (randomVal) {
        //chamar funcao aparecimento_tile_aleatorio
    }

}





