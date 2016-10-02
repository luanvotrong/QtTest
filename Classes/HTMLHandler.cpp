#include "HTMLHandler.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QWebEnginePage>
#include <QTreeView>"
#include <iostream>
#include "Tree/TreeModel.h"
#include "Gumbo/gumbo.h"

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
    m_webPage->load(QUrl("http://www.gogoanime.ch"));
}

void HTMLHandler::handleHTML(int isDone)
{
    if(isDone >= 100)
    {
        m_webPage->toHtml([this](QString str){
            this->parseHTML(str);
        });
    }
}

static std::string cleantext(GumboNode* node)
{
    if (node->type == GUMBO_NODE_TEXT)
    {
        return std::string(node->v.text.text);
    }
    else if (node->type == GUMBO_NODE_ELEMENT &&
             node->v.element.tag != GUMBO_TAG_SCRIPT &&
             node->v.element.tag != GUMBO_TAG_STYLE)
    {
        std::string contents = "";
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i)
        {
            const std::string text = cleantext((GumboNode*) children->data[i]);
            if (i != 0 && !text.empty())
            {
                contents.append(" ");
            }
            contents.append(text);
        }
        return contents;
    }
    else
    {
        return "";
    }
}

void HTMLHandler::parseHTML(QString content)
{
    QByteArray byte = content.toLocal8Bit();
    const char* content_char = byte.data();
    //qInfo() << qPrintable(content) << endl;
    GumboOutput* output = gumbo_parse(content_char);
    //std::cout << cleantext(output->root) << std::endl;
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    TreeModel *model = new TreeModel(output->root);
    m_treeView->setModel(model);
}
