#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    numberOfTiles = 4;
    indColorOptions = 0;
    createTiles();
    defineSetOfColors(indColorOptions);
    refreshRef();
    createNewTile();
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
    createNewTile();
    tileChanged();

}

void GameBoard::moveLeft()
{  
    verifyLeft();
    tileChanged();
    createNewTile();
    tileChanged();
}

void GameBoard::moveUp()
{
    verifyUp();
    tileChanged();
    createNewTile();
    tileChanged();
}

void GameBoard::moveDown()
{
    verifyDown();
    tileChanged();
    createNewTile();
    tileChanged();
}

void GameBoard::verifyRight()
{
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = (numberOfTiles - 2); i >= 0; i--){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i+1][j] == 0){
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i+1][j] == *matrixNb[i][j]) && tiles[i+1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i+1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i+1, j, i, j);
                        refreshRef();
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
}

void GameBoard::verifyLeft()
{
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = 1; i < numberOfTiles; i++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i-1][j] == 0){
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i-1][j] == *matrixNb[i][j]) && tiles[i-1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i-1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i-1, j, i, j);
                        refreshRef();
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
}

void GameBoard::verifyUp()
{
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = 1; j < numberOfTiles; j++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i][j-1] == 0){
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i][j-1] == *matrixNb[i][j]) && tiles[i][j-1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j-1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j-1, i, j);
                        refreshRef();
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
}

void GameBoard::verifyDown()
{
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = (numberOfTiles-2); j >= 0; j--){
                if (*matrixNb[i][j] != 0){;
                    if (*matrixNb[i][j+1] == 0){
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i][j+1] == *matrixNb[i][j]) && tiles[i][j+1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j+1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j+1, i, j);
                        refreshRef();
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
    defineSetOfColors(indColorOptions);
    refreshRef();
    createNewTile();
    refreshRef();
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
    QList<QString> tempColors;

    if (n == 0){
        tempColors << "#007615" << "#044e08" << "#73d216" << "#98fb83" << "#054c0b" << "#054c0b" << "#bbffa9" << "#73d216";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[i + j*numberOfTiles]->defineSetOfTilesColors("Green");
                tilesQml[i + j*numberOfTiles]->setColor();
            }
        }
    }
    if (n == 1){
        tempColors << "#baae9d" << "#ccc2b3" << "#ccc2b3" << "#faf9f0"<< "#ffffff" << "#746c6b" << "#f6f2c9" << "#8f7a66";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[i + j*numberOfTiles]->defineSetOfTilesColors("Classic");
                tilesQml[i + j*numberOfTiles]->setColor();
            }
        }
    }
    if (n == 2){
        tempColors << "#ffcc29" << "#fff773" << "#3E4095" << "#0fa31f"<< "#ffffff" << "#ffffff" << "#3be54f" << "#3E4095";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[i + j*numberOfTiles]->defineSetOfTilesColors("Brazil");
                tilesQml[i + j*numberOfTiles]->setColor();
            }
        }
    }
    if (n == 3){
        tempColors << "#051440" << "#030f2f" << "#ec1920" << "#020c29"<< "#ffffff" << "#ffffff" << "#0f3ba9" << "#ec1920";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[i + j*numberOfTiles]->defineSetOfTilesColors("France");
                tilesQml[i + j*numberOfTiles]->setColor();
            }
        }
    }
    colorsList = tempColors;
    indColorOptions = n;
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

QList<QString> GameBoard::readColorsList()
{
    return colorsList;
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
