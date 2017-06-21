#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <QQmlApplicationEngine>
#include <QGuiApplication>

class Manager
        : public QObject
{
    Q_OBJECT
private:
    QGuiApplication* app;
    QQmlApplicationEngine* engine;

public:
    int Start(int argc, char *argv[]);
    Q_INVOKABLE QString LoadPicture();
};

#endif // MANAGER_H
