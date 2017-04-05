#include "HTMLHandler.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QWebEnginePage>
#include <QTreeView>"
#include <iostream>

#include "Document.h"
#include "Selection.h"
#include "Node.h"


HTMLHandler::HTMLHandler()
{
    QRect screenRect = QApplication::desktop()->screenGeometry();

}

void HTMLHandler::LoadUrl(QUrl url)
{
    m_webPage = new QWebEnginePage();
    QObject::connect(m_webPage, SIGNAL(loadProgress(int)), this, SLOT(handleHTML(int)));
    m_webPage->load(QUrl("http://mangafox.me/"));
}

void HTMLHandler::handleHTML(int isDone)
{
    if(isDone >= 99)
    {
        m_webPage->toHtml([this](QString str){
            this->parseHTML(str);
        });
    }
}

void HTMLHandler::parseHTML(QString content)
{
    QByteArray byte = content.toLocal8Bit();
    const char* content_char = byte.data();


}
