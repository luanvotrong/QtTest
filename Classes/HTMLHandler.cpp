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
    //TreeModel *model = new TreeModel(output->root);
    //m_treeView->setModel(model);

}
