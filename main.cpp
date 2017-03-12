#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    GameBoard gameBoard;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gameBoard", &gameBoard);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
