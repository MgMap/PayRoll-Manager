//
// Created by minau on 4/26/2023.
//

#include "InputBox.h"

InputBox::InputBox() : InputBox("")
{

}

InputBox::InputBox(const std::string &firstItem_)
{
    firstItem.setString(firstItem_);
}

void InputBox::changeItem(const std::string &newItem)
{
    firstItem.setString(newItem);
}

void InputBox::setPosition(const sf::Vector2f &pos)
{
    firstItem.setPosition(pos);
}

void InputBox::resizeBox(const sf::Vector2f &size)
{
    firstItem.setSize(size);
}

sf::FloatRect InputBox::getGlobalBounds() const
{
    return firstItem.getGlobalBounds();
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(firstItem);
}

InputBox::~InputBox()
{

}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    //firstItem.addEventHandler(window,event);
}

void InputBox::update()
{

}

std::string InputBox::getString()
{
    return firstItem.getString();
}

bool InputBox::empty()
{
    return firstItem.empty();
}
