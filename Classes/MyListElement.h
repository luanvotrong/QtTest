#include <QApplication>

class MyListElement : public QObject
{
    Q_OBJECT

private:
    QString m_text;

public:
    MyListElement(QString text);
};
