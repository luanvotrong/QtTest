#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>
#include <QTreeView>
#include <QApplication>
#include <QDesktopWidget>
#include "Classes/HTMLHandler.h"


int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(simpletreemodel);
    QApplication app(argc, argv);

    HTMLHandler* htmlHandler = new HTMLHandler();
    htmlHandler->LoadUrl(QUrl(""));

    return app.exec();
}
