#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>  // Pour faire GameBoard hériter de QObject
#include <QDebug>   // Pour débuger
#include <QVector>  // Pour créer des objets QVector
#include "tile.h"   // Pour créer les Tiles
#include <stdlib.h> // Pour la fonction random
#include <time.h>   // Pour initialiser la fonction random
#include <QStringList>
#include <QList>
#include <vector>


class GameBoard : public QObject    // GameBoard hérite QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);    // Constructeur de la classe
    ~GameBoard();                               // Déstructeur de la classe

    Q_INVOKABLE void moveRight();   // Commandes à être appelés depuis qml
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void newGame();
    Q_INVOKABLE void undoGame();
    Q_INVOKABLE void setNumberOfTiles(int n);
    Q_INVOKABLE void defineSetOfColors(int n);

    Q_PROPERTY(int posX READ readPosX NOTIFY tileChanged)   // Propriétés à être utilisés
    int readPosX();                                         // Sur qml
    Q_PROPERTY(int posY READ readPosY NOTIFY tileChanged)
    int readPosY();
    Q_PROPERTY(QString tileNb READ readTileNb NOTIFY tileChanged)
    QString readTileNb();
    Q_PROPERTY(QString tileColor READ readTileColor NOTIFY tileChanged)
    QString readTileColor();
    Q_PROPERTY(QString tileTextColor READ readTileTextColor NOTIFY tileChanged)
    QString readTileTextColor();
    Q_PROPERTY(int numberOfTiles READ readNumberOfTiles NOTIFY tileChanged)
    int readNumberOfTiles();
    Q_PROPERTY(QList<QString> colorsList READ readColorsList NOTIFY tileChanged)
    QList<QString> readColorsList();
    Q_PROPERTY(int score READ readScore NOTIFY tileChanged)   // Propriétés à être utilisés
    int readScore();

signals:
    void tileChanged();     // Signal pour mettre à jour le qml
    //void tileNbChanged();

private:
    int numberOfTiles;
    int indX = 0, indY = 0, indNb = 0, indColor = 0, indTextColor = 0;  // indices pour passer les données au qml

    int indColorOptions = 0;
    QList<QString> colorsList;

    Tile*** tiles;
    Tile** tilesQml;
    int*** matrixNb;

    int score;                //score

    //Tile* tiles[4][4];      // Matrice qui contient les pointeurs des objets crées dynamiquement
    //Tile* tilesQml[16];     // Liste pour passer les infos au qml
    //int* matrixNb[4][4];    // Matrice pour faire la logique des mouvements

    void refreshRef();                                  // On refait les références
    void printInfo();                                   // Print pour debug
    void changePlaces(int i1, int j1, int i2, int j2);  // Changer deux tiles de place

    void createTiles();     // On crée les Tiles
    void deleteTiles();     // On les efface

    void verifyRight();     // Mouvement des tiles
    void verifyLeft();
    void verifyUp();
    void verifyDown();

    void scoreraz();        //remise a zero du score
    void add_score(int a);

    void createNewTile();   // Création d'un nouveau tile aleatoirement
};

#endif // GAMEBOARD_H
