#include "HTMLHandler.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QWebEnginePage>
#include <QTreeView>"
#include <iostream>


HTMLHandler::HTMLHandler()
{
    QRect screenRect = QApplication::desktop()->screenGeometry();

}

void HTMLHandler::LoadUrl(QUrl url)
{
    m_webPage = new QWebEnginePage();
    QObject::connect(m_webPage, SIGNAL(loadProgress(int)), this, SLOT(handleHTML(int)));
    m_webPage->load(url);
}

void HTMLHandler::handleHTML(int isDone)
{
    if(isDone == 100)
    {
        m_webPage->toHtml([this](QString str){
            this->parseHTML(str);
        });
    }
}

void HTMLHandler::parseHTML(QString content)
{
    QByteArray byte = content.toLocal8Bit();
    std::string str_content(byte.data());
    std::cout << str_content << endl;
}
