#include <QApplication>

class QWebEnginePage;
class QQmlApplicationEngine;
class QTreeView;

class HTMLHandler : public QObject
{
    Q_OBJECT

private:
    QWebEnginePage *m_webPage;
    QTreeView *m_treeView;

public:
    //temp cheat
    QQmlApplicationEngine *m_engine;

public:
    HTMLHandler();
    void LoadUrl(QUrl url);

public slots:
    void handleHTML(int isDone);
    void parseHTML(QString content);
};
