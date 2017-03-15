#include "tile.h"

Tile::Tile(int x, int y)
{
    tilePosition[0] = x;    // On initialise les positions
    tilePosition[1] = y;
    number = 0;             // On met le nombre à 0 -> tile invisible
    fusion = false;         // Pas fusionnée
    setColor();             // Tile transparent
}

void Tile::setPosition(int x, int y)
{
    if (x != 0){                // Si l'entrée x est différent de 0
        tilePosition[0] = x;    // Alors on change la position x du Tile
    }
    if (y != 0){                // Semblable au x
        tilePosition[1] = y;
    }
}

void Tile::setColor()               // Fonction pour mettre les couleurs selon le nombre
{
    if (number == 0){
        tileColor = "#00000000";
    }
    if (number == 2){
        tileColor = "#04f211";
    }
    if (number == 4){
        tileColor = "#229468";
    }
    if (number == 8){
        tileColor = "#225594";
    }
    if (number == 16){
        tileColor = "#482294";
    }
    if (number == 32){
        tileColor = "#812294";
    }
}

void Tile::setFusion(bool f)    // Change l'état de fusion
{
    fusion = f;
}

void Tile::multNumber(int n)    // On multiplie par n (n=2 par défault)
{
    number *= n;
    setColor();                 // On met à jour la couleur
}

void Tile::setNumber(int a)     // On met le nombre = a (a=2 par défault)
{
    number = a;
    setColor();                 // On met à jour la couleur
}

void Tile::resetTile()          // On resète le Tile
{
    fusion = false;             // Pas fusionnée
    number = 0;                 // Change à 0
    setColor();                 // Couleur = transparent
}

int Tile::getPosition(int a)    // Recupère la position
{
    return tilePosition[a];
}

QString Tile::getColor()        // Recupère la couleur
{
    return tileColor;
}

QString Tile::getTextColor()    // Recupère la couleur du texte
{
    if (number == 0){           // Si nombre = 0
        return "#00000000";     // couleur du texte = transparent
    }
    else                        // Sinon,
        return "#0a4403";       // couleur vert

}

QString Tile::getNumber()       // Recupère le nombre en forme de String
{
    return QString::number(number);
}

bool Tile::getFusion()          // Recupère l'état de fusion
{
    return fusion;
}

int *Tile::getRefNumber()       // Recupère la référence du nombre
{
    int *n = &number;
    return n;
}

int *Tile::getRefPosVect()      // Recupère la référence de la position du tile
{
    int *pvec = &tilePosition[0];
    return pvec;
}

QString *Tile::getRefColor()    // Recupère la référence de la couleur du tile
{
    QString *pcolor = &tileColor;
    return pcolor;
}
