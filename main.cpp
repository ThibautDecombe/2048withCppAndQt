#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);    // On crée l'application QGUI
    GameBoard gameBoard;                // On crée l'objet de la classe GameBoard

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gameBoard", &gameBoard); // On peut appeler gameBoard
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));                // désormais dans le fichier qml

    return app.exec();  // On exécute l'application
}
