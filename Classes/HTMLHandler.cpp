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
    //m_webPage->load(QUrl("http://mangafox.me/"));
    std::string page("<h1><a>some link</a></h1>");
    parseHTML(page.c_str());
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
    CDocument doc;
//    doc.parse(content_char);
//    CSelection c = doc.find("h1 a");
//    std::cout << c.nodeAt(0).text() << std::endl; // some link
}
