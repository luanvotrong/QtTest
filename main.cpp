#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>
#include <QApplication>
#include "Classes/HTMLHandler.h"

int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    QtWebEngine::initialize();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    HTMLHandler* htmlHandler = new HTMLHandler();
    htmlHandler->m_engine = &engine;
    htmlHandler->LoadUrl(QUrl(""));

    return app.exec();
}
