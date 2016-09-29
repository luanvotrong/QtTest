#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>
#include <QTreeView>
#include <QApplication>
#include "Classes/Tree/TreeModel.h"
#include "Classes/HTMLHandler.h"

QString data("\
             Getting Started	\t\t\tHow to familiarize yourself with Qt Designer\n\
             \t\tLaunching Designer\t\t\tRunning the Qt Designer application\n\
             \t\tThe User Interface\t\t\tHow to interact with Qt Designer\n"\
                                                                           "");

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(simpletreemodel);

    QApplication app(argc, argv);

    TreeModel model(data);

    QTreeView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Simple Tree Model"));

    view.show();

    /*
    HTMLHandler* htmlHandler = new HTMLHandler();
    htmlHandler->m_engine = &engine;
    htmlHandler->LoadUrl(QUrl(""));
    */

    return app.exec();
}
