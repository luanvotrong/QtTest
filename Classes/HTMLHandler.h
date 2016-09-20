#include <QApplication>

class QWebEnginePage;

class HTMLHandler : public QObject
{
    Q_OBJECT

private:
    QWebEnginePage *m_webPage;

public:
    HTMLHandler();

public slots:
    void handleHTML(int isDone);
    void parseHTML(QString content);
};
