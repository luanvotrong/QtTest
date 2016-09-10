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
    htmlHandler->load(QUrl("http://www.google.com.vn"));
    htmlHandler->connect(htmlHandler,
                         SIGNAL(loadFinished(bool)),
                         htmlHandler,
                         SLOT(handleHTML(bool)));

    return app.exec();
}
