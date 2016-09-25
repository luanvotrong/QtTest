#include "MyListElement.h"

MyListElement::MyListElement(QString text)
    : QObject(nullptr)
{
    m_text = text;
}
