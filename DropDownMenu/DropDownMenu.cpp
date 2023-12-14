//
// Created by minau on 4/26/2023.
//

#include "DropDownMenu.h"

DropDownMenu::DropDownMenu()
{

}

void DropDownMenu::addItem(const Item &item)
{
    if(inputBox.empty())
    {
        if (list.empty())
        {
            inputBox.changeItem(item.getString());
        }
        list.push(item);
    }
    if(!inputBox.empty())
        list.push(item);
}

void DropDownMenu::addItem(const std::string &string)
{
    if(!inputBox.empty())
        list.push(string);
    if(inputBox.empty())
    {
        if (list.empty())
        {
            inputBox.changeItem(string);
        }
        list.push(string);
    }

}

void DropDownMenu::setPosition(const sf::Vector2f &pos)
{
    inputBox.setPosition(pos);
    list.setPosition({pos.x, pos.y+51});
}

void DropDownMenu::setSize(const sf::Vector2f &size)
{
    inputBox.resizeBox(size);
    auto iter = list.begin();
    for(;iter != list.end(); iter++)
    {
        iter->setSize(size);
    }
}

DropDownMenu::~DropDownMenu()
{

}

void DropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(inputBox);
    if(list.checkState(SHOWN))
    {
        target.draw(list);
    }
}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    //inputBox.addEventHandler(window,event);
    list.addEventHandler(window, event);

    if (MouseEvents::isClicked(inputBox, window))
    {
        list.enableState(SHOWN);
    }
    if(list.checkState(SHOWN))
    {
        for (Item &item: list.list)
        {
            if (MouseEvents::isClicked(item, window))
            {
                {
                    inputBox.changeItem(item.getString());
                    list.disableStates(SHOWN);
                }
            }
        }
    }
    if (MouseEvents::isNotClicked(inputBox, window))
    {
        list.disableStates(SHOWN);
    }


}

sf::FloatRect DropDownMenu::getGlobalBounds()
{
    return inputBox.getGlobalBounds();
}

void DropDownMenu::update()
{
list.update();
}
