#include "objPosArrayList.h"
#include "objPos.h"
#include <iostream>

using namespace std;

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(const objPosArrayList &d)
{
    listSize = d.listSize;
    arrayCapacity = d.arrayCapacity;

    aList = new objPos[d.arrayCapacity];
    for(int i = 0; i < listSize; i++){
        aList[i] = d.aList[i];
    }
}

objPosArrayList& objPosArrayList::operator=(const objPosArrayList& d)
{
    if (this != &d){
        delete[] aList;

        listSize = d.listSize;
        arrayCapacity = d.arrayCapacity;
        aList = new objPos[d.arrayCapacity];
        for(int i = 0; i < listSize; i++){
        aList[i] = d.aList[i];
        }
    }
    return *this;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity){
        return;
    } 
    
    for (int i = listSize ; i > 0; i--) {
        aList[i] = aList[i - 1];
    }
    
    aList[0] = thisPos;
    listSize++; 
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= arrayCapacity){
        throw std::out_of_range("Index out of bounds");
    }

    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{
    if (listSize <= 0){
        throw std::out_of_range("Index out of bounds");
    } 

    for (int i = 0; i < listSize - 1; i++){
        aList[i] = aList[i + 1];
    }

    listSize--;
    
}

void objPosArrayList::removeTail()
{      
    if (listSize > 0){
        listSize--; 
    }
}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize <= 0){
        throw out_of_range("Index out of bounds");
    }
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize <= 0){
        throw out_of_range("Index out of bounds");
    }
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0){
        index = 0;
    }
     
    else if (index >= arrayCapacity){
        index = listSize - 1;
    } 
    return aList[index];
}

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
