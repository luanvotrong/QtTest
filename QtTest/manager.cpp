#include <QQmlContext>
#include "manager.h"

int Manager::Start(int argc, char *argv[])
{
    app = new QGuiApplication(argc, argv);
    engine = new QQmlApplicationEngine();


    engine->rootContext()->setContextProperty("manager", this);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app->exec();
}

QString Manager::LoadPicture()
{
    return "";
}
