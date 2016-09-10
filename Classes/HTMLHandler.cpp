#include "HTMLHandler.h"

void HTMLHandler::handleHTML(bool isDone)
{
    if(isDone)
    {
        toHtml([](QString str){
            qInfo() << str;
        });
    }
}
