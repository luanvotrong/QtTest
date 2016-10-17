#include "HTMLHandler.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QWebEnginePage>
#include <QTreeView>"
#include <iostream>

#include "Document.h"
#include "Selection.h"
#include "Node.h"
#include "Tree/TreeModel.h"

QString data2("\<!DOCTYPE html>\
             <html>\
             <head>\
             <title>Project Template</title>\
             <meta charset=\"utf-8\"></meta>\
        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, maximum-scale=1.0, user-scalable=0\">\
        <link rel=\"stylesheet\" href=\"css/style_debug.css\" />\
        <script src=\"http://game-portal.gameloft.com/2093/v4.0/?_rp_=mig/resource/41907h2s1445312896884/debug\"></script>\
        <script src=\"js/ConfigDebug.js\"></script>\
        <script src=\"js/core/ScriptMgr.js\"></script>\
        <style>\
        html,body,canvas\
{\
                 width: 100%;\
                 height: 100%;\
                 margin: 0px;\
                 padding: 0px;\
                 position: fixed;\
                 left: 0;\
                 top: 0;\
             }\
             </style>\
             </head>\
             <body>\
             <div id=\"gameDiv\">\
        <canvas id=\"canvas\">\
        </canvas>\
        </div>\
        <div id=\"gameDiv2\">\
        <canvas id=\"canvas2\">\
        </canvas>\
        </div>\
        </body></html>");

HTMLHandler::HTMLHandler()
{
    QRect screenRect = QApplication::desktop()->screenGeometry();

    m_treeView = new QTreeView();
    m_treeView->setWindowTitle(QObject::tr("Simple Tree Model"));
    m_treeView->setColumnWidth(0, screenRect.width()/3);
    m_treeView->setColumnWidth(1, screenRect.width()/3*2);
    m_treeView->setFixedSize(screenRect.width(), screenRect.height());
    m_treeView->show();
}

void HTMLHandler::LoadUrl(QUrl url)
{
    m_webPage = new QWebEnginePage();
    QObject::connect(m_webPage, SIGNAL(loadProgress(int)), this, SLOT(handleHTML(int)));
    m_webPage->load(QUrl("http://mangafox.me/"));
}

void HTMLHandler::handleHTML(int isDone)
{
    if(isDone >= 95)
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
    doc.parse(content_char);

    CNode* node = doc.getRootNode();
    qInfo() << qPrintable(node->tag().c_str()) << endl;
    qInfo() << qPrintable(node->text().c_str()) << endl;
    /*
    qInfo() << qPrintable(content) << endl;
    GumboOutput* output = gumbo_parse(content_char);
    std::cout << cleantext(output->root) << std::endl;
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    */
    TreeModel *model = new TreeModel(node);
    m_treeView->setModel(model);

}
