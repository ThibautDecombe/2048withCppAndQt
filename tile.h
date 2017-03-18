#ifndef TILE_H
#define TILE_H

#include <QString>
#include <QDebug>
#include <vector>
#include <QStringList>

class Tile
{
public:
    Tile(int x=10, int y=10);           // Constructeur de la classe Tile

    void setPosition(int x=0, int y=0); // Si x ou y = 0 on change seulement l'autre
    void setColor();                    // Mettre les couleurs selon le nombre
    void setFusion(bool f = false);     // Pour vérifier si le Tile a déjà été fusionné
    void multNumber(int n=2);           // Pour multiplier le Tile par 2
    void setNumber(int a=2);            // Pour initialiser le Tile
    void resetTile();                   // Pour mettre le Tile à 0
    void defineSetOfTilesColors(QString nameOfTheSet);

    int getPosition(int a);             // Recupère la position
    QString getColor();                 // Recupère la couleur
    QString getTextColor();             // Recupère la couleur du text
    QString getNumber();                // Recupère le nombre
    bool getFusion();                   // Recupère l'état de fusion
    int *getRefPosVect();               // Recupère la référence de la position
    QString *getRefColor();             // Recupère la référence de la couleur
    int *getRefNumber();                // Recupère la référence du nombre


protected:
    int tilePosition[2];                // Position x,y du Tile
    QString tileColor, textColor;       // Couleur du Tile et du text
    int number;                         // Nombre du Tile
    bool fusion;                        // État de fusion du Tile

    //QVector<QString> setOfColors;
    QStringList setOfColors, setOfColorsText;
};

#endif // TILE_H
