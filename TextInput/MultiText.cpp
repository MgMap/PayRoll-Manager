//
// Created by minau on 3/16/2023.
//

#include "MultiText.h"

MultiText::MultiText()
{
    font = Fonts::getFont(OPEN_SANS);
}

//Accessors and draw
const std::string& MultiText::getString()
{
    std::string textAsString;
    for(iterator iter = begin(); iter != end(); ++iter){
        textAsString.append(iter->getString());
    }
    return textAsString;
}

unsigned int MultiText::getSize()
{
    return letterList.size();
}

MultiText::iterator MultiText::begin()
{
    return letterList.begin();
}
MultiText::const_iterator MultiText::begin() const
{
    return letterList.cbegin();
}

MultiText::iterator MultiText::end()
{
    return letterList.end();
}
MultiText::const_iterator MultiText::end() const
{
    return letterList.cend();
}


void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(auto iter = begin(); iter != end(); ++iter){
        window.draw(*iter);
    }
}

sf::Vector2f MultiText::getPosition()
{
    return letterList.back().getPosition();
}

void MultiText::setPosition(sf::Vector2f position)
{
    this->position = position;
}

sf::FloatRect MultiText::getGlobalBounds()
{
    return letterList.back().getGlobalBounds();
}

bool MultiText::empty()
{
    return letterList.empty();
}

void MultiText::addLetter(std::string letter){

    Letter brandNew;
    if (letterList.empty()){
        brandNew.setString(letter);
        brandNew.setPosition(position);
    }
    else
    {
        brandNew = letterList.back();
        brandNew.setString(letter);
        brandNew.setPosition(letterList.back().getPosition().x+1,letterList.back().getPosition().y+1);
        letterList.push_back(brandNew);
    }
}

void MultiText::addLetter(char letter)
{
     Letter brandNew;
    if (letterList.empty())
    {
        brandNew.setFont(font);
        brandNew.setFillColor(color);
        brandNew.setCharacterSize(CharSize);
        brandNew.setString(letter);
        brandNew.setPosition(position);
        letterList.push_back(brandNew);
    }
    else
    {
        brandNew = letterList.back();
        brandNew.setCharacterSize(CharSize);
        brandNew.setString(letter);
        brandNew.setPosition(letterList.back().getPosition().x+letterList.back().getGlobalBounds().width,letterList.back().getPosition().y);
        letterList.push_back(brandNew);
    }
}

void MultiText::backSpace()
{
    if (!letterList.empty())
    {
        letterList.pop_back();
    }
}

void MultiText::setCharSize(const int size)
{
    CharSize = size;
}

int MultiText::getCharSize()
{

    return CharSize;
}

void MultiText::setFont(const sf::Font &font)
{
    this->font = font;
}

void MultiText::setColor(const sf::Color &color)
{
    this->color = color;
}