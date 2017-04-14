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
#include <fstream>
#include <string>


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
    Q_INVOKABLE void setwinner();
    Q_INVOKABLE void setgamenormal();
    Q_INVOKABLE void setgamepractice();

    Q_PROPERTY(int winner READ readWinner NOTIFY tileChanged)           // Propriétés à être utilisés sur qml
    int readWinner();
    Q_PROPERTY(int loser READ readLoser NOTIFY tileChanged)
    int readLoser();
    Q_PROPERTY(int posX READ readPosX NOTIFY tileChanged)
    int readPosX();
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
    Q_PROPERTY(int score READ readScore NOTIFY tileChanged)
    int readScore();
    Q_PROPERTY(int bestscore READ readBestScore NOTIFY tileChanged)
    int readBestScore();
    Q_PROPERTY(bool gamemode READ readgamemode NOTIFY tileChanged)
    bool readgamemode();


signals:
    void tileChanged();                                                 // Signal pour mettre à jour le qml

private:
    int numberOfTiles;
    int indX = 0, indY = 0, indNb = 0, indColor = 0, indTextColor = 0;  // indices pour passer les données au qml

    int indColorOptions;
    QList<QString> colorsList;

    Tile*** tiles;
    Tile** tilesQml;
    int*** matrixNb;

    int score;                  // score
    int bestscore;              // best score

    void refreshRef();                                  // On refait les références
    void printInfo();                                   // Print pour debug
    void changePlaces(int i1, int j1, int i2, int j2);  // Changer deux tiles de place

    void createTiles();         // On crée les Tiles
    void deleteTiles();         // On les efface

    void verifyRight();         // Mouvement des tiles
    void verifyLeft();
    void verifyUp();
    void verifyDown();

    void scoreraz();            // remise a zero du score
    void add_score(int a);      // incrementation du score

    void createNewTile();       // Création d'un nouveau tile aleatoirement

    void loadGame();            // Pour recuperer le jeu precedent

    void loadRight();           // On va "rejouer" les mouvements enregistres
    void loadLeft();
    void loadUp();
    void loadDown();

    void saveGame();            // savegarder le jeu lors qu`on ferme la fenetre
    void clearProgress();       // effacer

    std::vector<std::vector<int>> save_moves;   // vecteurs qui vont enregistrer temporairement les mouvements joues et les nombre aleatoires
    std::vector<std::vector<int>> moves;

    std::fstream progress;      // archive pour sauvegarder le progres

    int winner;                 // 0 : score < 2048, 1 : score = 2048, 2 : score > 2048
    int loser;                  // 0 : en train de jouer, 1 : perdu

    bool verifyLost;

    void verifyLostRight();         // Verifier s`il y a des mouvements possibles avec le tableau rempli
    void verifyLostLeft();
    void verifyLostUp();
    void verifyLostDown();

    bool gamemode;              // Practie ou Normal

    int multiplier();           // Dans le mode practice on n`a pas de points


};
#endif // GAMEBOARD_H
