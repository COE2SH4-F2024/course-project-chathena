#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    int sizeList, arrayCapacity = 200;
    aList = new arrayCapacity[200];



}

objPosArrayList::~objPosArrayList()
{
    for (int i - 0; i < arrayCapacity; i++)
    {
        delete arrayCapacity[i];
    }  
}

int objPosArrayList::getSize() const
{
return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    
}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{
    
}

objPos objPosArrayList::getHeadElement() const
{
    return head;
}

objPos objPosArrayList::getTailElement() const
{
    return tail;
}

objPos objPosArrayList::getElement(int index) const
{
    return element[index];
    listSize++;
}