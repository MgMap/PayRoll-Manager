//
// Created by minau on 4/26/2023.
//

#include "ItemList.h"


bool ItemList::empty()
{
    return list.empty();
}

void ItemList::push(const Item &listItem)
{
    list.push_back(listItem);
}

void ItemList::push(const std::string &listItem)
{
    list.emplace_back(listItem);
}

void ItemList::setPosition(const sf::Vector2f &pos)
{
    float x = pos.x;
    float y = pos.y;
    auto iter = list.begin();

    while(iter != list.end()) {
        //vertically align
        //same x position
        iter->setPosition({x, y});
        y += (iter->getGlobalBounds().height + 1);
        iter++;
    }
}

ItemList::iterator ItemList::begin()
{
    return list.begin();
}

ItemList::iterator ItemList::end()
{
    return list.end();
}

sf::Vector2f ItemList::getPosition()
{
    return list.begin()->getPosition();
}

ItemList::~ItemList()
{

}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

        auto iter = list.begin();
        while(iter != list.end())
        {
            target.draw(*iter);
            iter++;
        }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

    for(Item& item: list)
    {
        item.addEventHandler(window,event);
    }
}

void ItemList::update()
{

}