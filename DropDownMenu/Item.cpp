//
// Created by minau on 4/26/2023.
//

#include "Item.h"

Item::Item() :Item("")
{

}

Item::Item(const std::string &itemName)
{
    //this->itemName = itemName;
    text.setString(itemName);
    text.setFont(Fonts::getFont(ROBOTOMONO));
    setPosition({400,400});
    text.setCharacterSize(CHARACTER_SIZE);

    setSize({300,50});
    //setPosition({400,400});
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(5);
   // rect.setOutlineColor(sf::Color::Black);
    setOutlineColor(sf::Color::Black);
}

std::string Item::getString() const
{
    return text.getString();
}

void Item::setString(const std::string &string)
{
    text.setString(string);
    Position::centerText(rect,text);
}

void Item::setPosition(const sf::Vector2f pos)
{
    this->pos = pos;
    rect.setPosition(this->pos);
    Position::centerText(rect,text);
}

sf::Vector2f Item::getPosition()
{
    return rect.getPosition();
}

void Item::setSize(const sf::Vector2f &size)
{
    rect.setSize(size);
    setPosition(this->pos);
    //text.setCharacterSize(size.y);
}

sf::Vector2f Item::getSize()
{
    return rect.getSize();
}

sf::FloatRect Item::getGlobalBounds() const
{
    return rect.getGlobalBounds();
}

void Item::setFillColor(sf::Color color)
{
    rect.setFillColor(color);
}

void Item::setOutlineColor(sf::Color color)
{
    text.setFillColor(color);
    rect.setOutlineColor(color);
}

Item::~Item()
{

}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

        target.draw(rect);
        target.draw(text);

}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHover(rect,window))
    {
        setFillColor(sf::Color::Black);
        setOutlineColor(sf::Color::White);
    }
    else
    {
        setFillColor(sf::Color::White);
        setOutlineColor(sf::Color::Black);
    }
}

void Item::update()
{

}

bool Item::empty()
{
    return text.getString().isEmpty();
}
