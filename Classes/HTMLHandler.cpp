#include "HTMLHandler.h"
#include <QQmlApplicationEngine>
#include <QWebEnginePage>
#include <iostream>
#include "Gumbo/gumbo.h"

HTMLHandler::HTMLHandler()
{
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
    //QByteArray byte = content.toLocal8Bit();
    //const char* content_char = byte.data();
    //qInfo() << qPrintable(content) << endl;
    //GumboOutput* output = gumbo_parse(content_char);
    //std::cout << cleantext(output->root) << std::endl;
    //gumbo_destroy_output(&kGumboDefaultOptions, output);
}
