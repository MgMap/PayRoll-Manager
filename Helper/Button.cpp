//
// Created by minau on 4/25/2023.
//

#include "Button.h"

Button::Button():Button("button")
{

}
Button::Button(std::string str)
{
    text.setString(str);
    text.setFont(Fonts::getFont(ROBOTOMONO));
    setColor(sf::Color::Black);
    rect.setOutlineThickness(4);
    rect.setSize({text.getGlobalBounds().width+5,text.getGlobalBounds().height+5});
}
void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rect);
    target.draw(text);
}

void Button::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHover(rect,window))
        setColor(sf::Color::Blue);
    else
        setColor(sf::Color::Black);
}

void Button::update()
{

}

Button::~Button()
{

}


sf::Vector2f Button::getPosition()
{
    return rect.getPosition();
}

void Button::setPosition(const sf::Vector2f &position)
{
    rect.setPosition(position);
    Position::centerText(rect,text);
}

void Button::setColor(const sf::Color &color)
{
    rect.setFillColor(sf::Color::White);
    rect.setOutlineColor(color);
    text.setFillColor(color);
}

sf::FloatRect Button::getGlobalBounds() const
{
    return rect.getGlobalBounds();
}

sf::Vector2f Button::getSize()
{
    return rect.getSize();
}

void Button::setSize(const sf::Vector2f &size)
{
    rect.setSize(size);
}

void Button::setString(const std::string &string)
{
    text.setString(string);
    rect.setSize({text.getGlobalBounds().width+5,text.getGlobalBounds().height+5});
}

std::string Button::getString()
{
    return text.getString();
}
