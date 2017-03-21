#include "tile.h"
#include "math.h"

Tile::Tile(int x, int y)
{
    defineSetOfTilesColors("Green");
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
        tileColor = setOfColors.at(0);
        textColor = setOfColorsText.at(0);
        return;
    }
    for (int i=1; i <= 11; i++){
        if (number == pow(2,i)){
            tileColor = setOfColors.at(i);
            textColor = setOfColorsText.at(i);
            return;
        }
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

void Tile::defineSetOfTilesColors(QString nameOfTheSet)
{
    QStringList tempSetOfColors, tempSetOfColorsText;

    if (nameOfTheSet == "Green"){

        tempSetOfColors << "#00000000" << "#04f211" << "#ded202" <<
                             "#225594" << "#482294" << "#812294" <<
                             "#229468" << "#c305b9" << "#de020d" <<
                             "#de4b02" << "#0599c3" << "#ffffff";

        tempSetOfColorsText << "#00000000" << "#0a4403" << "#0a4403"
                            << "#ffffff"   << "#0a4403" << "#0a4403"
                            << "#0a4403"   << "#0a4403" << "#0a4403"
                            << "#0a4403"   << "#0a4403" << "#0a4403";
    }
    if (nameOfTheSet == "Classic"){

        tempSetOfColors << "#00000000" << "#eee4dA" << "#ede0c8" <<
                           "#f2b179" << "#f59664" << "#f57d5f" <<
                           "#f55f3c" << "#edcf72" << "#edcf61" <<
                           "#ffff00" << "#ffff00" << "#ffff00";

        tempSetOfColorsText << "#00000000" << "#776e65" << "#776e65"
                            << "#ffffff"   << "#ffffff" << "#ffffff"
                            << "#ffffff"   << "#ffffff" << "#ffffff"
                            << "#ffffff"   << "#ffffff" << "#ffffff";
    }
    if (nameOfTheSet == "Brazil"){

        tempSetOfColors << "#00000000" << "#00700d" << "#20a430" <<
                           "#4fcb5d" << "#5afd3a" << "#96fd3a" <<
                           "#d6fd3a" << "#fbfd3a" << "#fcff0b" <<
                           "#7f85ff" << "#444dff" << "#000cff";

        tempSetOfColorsText << "#00000000" << "#fcff0b" << "#fcff0b"
                            << "#fcff0b"   << "#fcff0b" << "#fcff0b"
                            << "#00700d"   << "#00700d" << "#00700d"
                            << "#ffffff"   << "#ffffff" << "#05053b";
    }
    if (nameOfTheSet == "France"){

        tempSetOfColors << "#00000000" << "#ffffff" << "#b2b2ff" <<
                           "#7a7aff" << "#4a4aff" << "#1313ff" <<
                           "#0000ff" << "#ff9898" << "#ff5555" <<
                           "#ff2020" << "#ff0000" << "#ffffff";

        tempSetOfColorsText << "#00000000" << "#05053b" << "#05053b"
                            << "#ffffff"   << "#ffffff" << "#ffffff"
                            << "#ffffff"   << "#ffffff" << "#ffffff"
                            << "#ffffff"   << "#ffffff" << "#05053b";
    }


    setOfColors = tempSetOfColors;
    setOfColorsText = tempSetOfColorsText;
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
    return textColor;
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
