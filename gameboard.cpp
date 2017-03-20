#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    numberOfTiles = 4;
    createTiles();
    defineSetOfColors(0);
    refreshRef();
    tiles[0][0]->setNumber();
    qDebug() << "Object GameBoard created";
    tileChanged();
}

GameBoard::~GameBoard()
{
    deleteTiles();
    qDebug() << "Objects destroyed";
}

void GameBoard::moveRight()
{
    verifyRight();
    tileChanged();
}

void GameBoard::moveLeft()
{  
    verifyLeft();
    tileChanged();
}

void GameBoard::moveUp()
{
    verifyUp();
    tileChanged();
}

void GameBoard::moveDown()
{
    verifyDown();
    tileChanged();
}

void GameBoard::verifyRight()
{
    bool callRandom = false;
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = (numberOfTiles - 2); i >= 0; i--){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i+1][j] == 0){
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i+1][j] == *matrixNb[i][j]) && tiles[i+1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i+1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                        callRandom =  true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        createNewTile();
        tileChanged();
    }
}

void GameBoard::verifyLeft()
{
    bool callRandom = false;
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = 1; i < numberOfTiles; i++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i-1][j] == 0){
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i-1][j] == *matrixNb[i][j]) && tiles[i-1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i-1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        createNewTile();
        tileChanged();
    }
}

void GameBoard::verifyUp()
{
    bool callRandom = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = 1; j < numberOfTiles; j++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i][j-1] == 0){
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i][j-1] == *matrixNb[i][j]) && tiles[i][j-1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j-1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        createNewTile();
        tileChanged();
    }
}

void GameBoard::verifyDown()
{
    bool callRandom = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = (numberOfTiles-2); j >= 0; j--){
                if (*matrixNb[i][j] != 0){;
                    if (*matrixNb[i][j+1] == 0){
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i][j+1] == *matrixNb[i][j]) && tiles[i][j+1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j+1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                        callRandom = true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        createNewTile();
        tileChanged();
    }
}

void GameBoard::createNewTile()
{
    srand(time(NULL)); // initialize the random
    QVector<int> vecRand;
    for (int i = 0; i < numberOfTiles; i++){
        for (int j = 0; j < numberOfTiles; j++){
            if (*matrixNb[i][j] == 0){
                vecRand << i << j; // Vector with all 0's cases
            }
        }
    }
    qDebug() << vecRand.length();
    if (vecRand.length() == 2){
        qDebug() <<  "YOU LOSE";
        return;
    }
    else{
        int randNumber = rand() % 2 + 1;
        int randIndex = rand() % (vecRand.length()/2 - 1);
        tiles[vecRand.at(randIndex*2)][vecRand.at(randIndex*2+1)]->setNumber(randNumber*2);
        refreshRef();
    }
}

void GameBoard::newGame()
{
    deleteTiles();
    createTiles();
    refreshRef();
    tiles[0][0]->setNumber();
    tiles[1][0]->setNumber();
    tileChanged();
}

void GameBoard::undoGame()
{
    qDebug() << "undo";
}

void GameBoard::setNumberOfTiles(int n)
{
    numberOfTiles = n;
    //tileNbChanged();
    deleteTiles();
    createTiles();
    refreshRef();
    tiles[0][0]->setNumber();
    qDebug() << "Object GameBoard created";
    tileChanged();
}

void GameBoard::defineSetOfColors(int n)
{
    QStringList tempColorOptions;

    if (n == 0){
        tempColorOptions << "#007615" << "#044e08" << "#73d216"
                         << "#044e08" << "#044e08" <<"#73d216" << "#98fb83" ;
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[i + j*numberOfTiles]->defineSetOfTilesColors("Green");
                tilesQml[i + j*numberOfTiles]->setColor();
                tempColorOptions << "#054c0b";
            }
        }
    }
    if (n == 1){
        tempColorOptions << "#baae9d" << "#ffffff" << "#baae9d"
                         << "#746c6b" << "#ffffff" << "#baae9d" << "#faf9f0";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[i + j*numberOfTiles]->defineSetOfTilesColors("Classic");
                tilesQml[i + j*numberOfTiles]->setColor();
                tempColorOptions << "#ccc2b3";
            }
        }
    }
    colorOptions = tempColorOptions;
    tileChanged();
}

int GameBoard::readPosX()
{
    if (indX == numberOfTiles*numberOfTiles){
        indX = 0;
    }
    return tilesQml[indX++]->getPosition(0);
}

int GameBoard::readPosY()
{
    if (indY == numberOfTiles*numberOfTiles){
        indY = 0;
    }
    return tilesQml[indY++]->getPosition(1);
}

QString GameBoard::readTileNb()
{
    if (indNb == numberOfTiles*numberOfTiles){
        indNb = 0;
    }
    return tilesQml[indNb++]->getNumber();
}

QString GameBoard::readTileColor()
{
    if (indColor == numberOfTiles*numberOfTiles){
        indColor = 0;
    }
    return tilesQml[indColor++]->getColor();
}

QString GameBoard::readTileTextColor()
{
    if (indTextColor == numberOfTiles*numberOfTiles){
        indTextColor = 0;
    }
    return tilesQml[indTextColor++]->getTextColor();
}

int GameBoard::readNumberOfTiles()
{
    return numberOfTiles;
}

QString GameBoard::readColorOptions()
{
    if (indColorOptions == numberOfTiles*numberOfTiles + 7){
        indColorOptions = 0;
    }
    return colorOptions.at(indColorOptions++);
}

void GameBoard::refreshRef()
{
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setPosition(i*85 + 10, j*85 + 10);
            matrixNb[i][j] = tiles[i][j]->getRefNumber();
        }
    }
}

void GameBoard::printInfo()
{
    qDebug() << "matrixNb:";
    for (int j=0; j < numberOfTiles; j++){
       qDebug() << *matrixNb[0][j] << "," << *matrixNb[1][j] << "," << *matrixNb[2][j] << "," << *matrixNb[3][j];
    }
}

void GameBoard::changePlaces(int i1, int j1, int i2, int j2)
{
    Tile* temp;
    temp = tiles[i1][j1];
    tiles[i1][j1] = tiles[i2][j2];
    tiles[i2][j2] = temp;
}

void GameBoard::createTiles()
{
    /*
    tiles = new Tile**[numberOfTiles];
    for (int i=0; i < numberOfTiles; i++) tiles[i] = new Tile*[numberOfTiles];

    matrixNb = new int**[numberOfTiles];
    for (int i=0; i < numberOfTiles; i++) matrixNb[i] = new int*[numberOfTiles];

    tilesQml = new Tile*[numberOfTiles];
*/
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j] = new Tile(i*85 + 10, j*85 + 10);
            tilesQml[i + j*numberOfTiles] = tiles[i][j];
        }
    }
}

void GameBoard::deleteTiles()
{
/*
    qDebug() << "tiles * destroyed";
    if (matrixNb != NULL){
        for (int i=0; i < numberOfTiles; i++){
            delete[] matrixNb[i];
        }
        delete[] matrixNb;
    }
    qDebug() << "matrix Nb destroyed";

    if (tilesQml != NULL){
        delete [] tilesQml;
    }
*/
    qDebug() << "tiles QML destroyed";

    for (int i=0; i < numberOfTiles ; i++){
        for (int j=0; j < numberOfTiles; j++){
            delete tiles[i][j];
        }
    }
/*
    qDebug() << "tiles destroyed";
    if (tiles != NULL){
        qDebug() << "tiles != Null";
        for (int i=0; i < numberOfTiles; i++){
            delete[] tiles[i];
        }
        delete[] tiles;
    }
*/

}
