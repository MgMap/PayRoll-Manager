//
// Created by minau on 3/16/2023.
//

#include "Typing.h"

Typing::Typing()
{
    text.setFont(Fonts::getFont(ROBOTOMONO));
 /*cursor.addLetter('y');
 cursor.setCharSize(100);*/
}

void Typing::setPosition(sf::Vector2f position)
{
    text.setPosition(position);
    //cursor.setPosition(position);
}

sf::Vector2f Typing::getPosition()
{
    return text.getPosition();
}

bool Typing::empty()
{
    return textstr.empty();
}

void Typing::backSpaceF()
{
    std::string temp = "";
    for(int i=0; i<this->textstr.length()-1; ++i)
    {
        temp += textstr[i];
    }
    textstr = temp;
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if(event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode)
            this->textstr += (static_cast<char>(event.text.unicode));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace) && !textstr.empty())
    {
        backSpaceF();
    }

}

void Typing::update()
{
    text.setString(this->textstr);
}

int Typing::getCharSize()
{
    return text.getCharacterSize();
}

void Typing::setCharSize(const int &size)
{
    text.setCharacterSize(size);
    //cursor.setCharSize(size);
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
    //window.draw(cursor);
}

sf::Color Typing::getColor()
{
    return text.getColor();
}

void Typing::setColor(const sf::Color &color)
{
    text.setFillColor(color);
}

sf::FloatRect Typing::getGlobalBounds()
{
    return text.getGlobalBounds();
}

sf::Font Typing::getFont()
{
    return sf::Font();
}

void Typing::setFont(const sf::Font &font)
{
    text.setFont(font);
}

void Typing::setString(const std::string &string)
{
    textstr = string;
}

std::string Typing::getString()
{
    return text.getString();
}


/*
bool Typing::isOperator(const char &element)
{
    if((element >= 40 && element <= 47) || element == 94)
    {
        return true;
    }
    return false;
}

bool Typing::isNumber(const std::string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if(!isdigit(str[i]))
            return false;
        else
            return true;
    }
}

void Typing::checkKeyword(std::list<Letter>::iterator start, std::list<Letter>::iterator end)
{
    auto start1 = start;
    auto end1 = end;
    std::string x ="";
    for(; start1 != end1; ++start1)
    {
        x += start1->getString();
        if(x == "float" || x == "int" || x == "char" || x =="string" ||x == "double" )
        {
            changeColor(start,end, sf::Color::Blue);
        }
        else if(isOperator(x[0]))
        {
            changeColor(start,end,sf::Color::Green);
        }
        else if(isNumber(x))
        {
            changeColor(start,end,sf::Color::Red);
        }
    }
}

void Typing::changeColor(std::list<Letter>::iterator start, std::list<Letter>::iterator end, sf::Color color)
{
    for(; start != end; ++start)
    {
        start->setFillColor(color);
    }
}
*/

