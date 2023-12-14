//
// Created by minau on 4/27/2023.
//

#include "dataSort.h"

dataSort::dataSort()
{

}

dataSort::dataSort(const std::string &filename)
{

    dataReader.readFile(filename);
    this->DataBank = dataReader.getData();
}

void dataSort::readData(const string &filename)
{

    dataReader.readFile(filename);
    this->DataBank = dataReader.getData();
}

void dataSort::setPosition(const sf::Vector2f &pos)
{
    if(!drawableData.empty())
    {
        drawableData[0].setPosition(pos);
        for (int i = 1; i < drawableData.size(); ++i)
        {
            Position::bottom(drawableData[i - 1] , drawableData[i]);
        }
    }

}

void dataSort::clearData()
{
    if(!DataBank.empty())
    {
        DataBank.clear();
    }
}

void dataSort::prioritize(const std::string &tiText, const TextBox &ti)
{
    Heap<employeeData> heap;
    if(!drawableData.empty())
    {
        drawableData.clear();
    }

    if(!tiText.empty())
    {
        for(int i = 0; i < DataBank.size(); i++)
        {
            for (int j = 0; j < tiText.size(); ++j) {
                if (tolower(tiText[j]) == tolower(DataBank[i].getName()[j]))
                {
                    DataBank[i] += 1;
                }
            }
            heap.push(DataBank[i]);
        }
        if(!heap.empty())
        {
            for (int i = 0; i < heap.size(); ++i)
            {
                if (heap.getHeap()[i].getPriority() > 0)
                {
                    drawableData.push_back(heap.getHeap()[i]);
                }
            }
        }
        if(!drawableData.empty())
            std::sort(drawableData.begin(),drawableData.end(),greater<employeeData>());

        if(!drawableData.empty())
            Position::bottom(ti,drawableData[0]);
        for (int i = 1; i < drawableData.size(); ++i)
        {
            Position::bottom(drawableData[i-1] , drawableData[i]);
        }
    }
}

dataSort::~dataSort()
{

}

void dataSort::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int i = 0; i < drawableData.size(); i++)
    {
        target.draw(drawableData[i]);
    }
}

void dataSort::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i = 0; i < drawableData.size();i++)
    {
        drawableData[i].addEventHandler(window,event);
    }
}

void dataSort::update()
{

}

const vector<employeeData> &dataSort::getDataBank() const
{
    return DataBank;
}

void dataSort::setDataBank(const vector<employeeData> &dataBank)
{
    DataBank = dataBank;
}

const vector<employeeData> &dataSort::getDrawableData() const
{
    return drawableData;
}

void dataSort::setDrawableData(const vector<employeeData> &drawableData)
{
    dataSort::drawableData = drawableData;
}

const sf::Vector2f &dataSort::getPos() const
{
    return pos;
}

void dataSort::setPos(const sf::Vector2f &pos)
{
    dataSort::pos = pos;
}

const DataReader &dataSort::getDataReader() const
{
    return dataReader;
}

void dataSort::setDataReader(const DataReader &dataReader)
{
    dataSort::dataReader = dataReader;
}

