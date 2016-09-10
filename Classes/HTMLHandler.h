#include <QWebEnginePage>
#include <QApplication>

class HTMLHandler : public QWebEnginePage
{
    Q_OBJECT

public slots:
    void handleHTML(bool isDone);
};
