//
// Created by minau on 3/19/2023.
//

#include "TextBox.h"

TextBox::TextBox() :TextBox("Firstname")
{

}

TextBox::TextBox(std::string label)
{
    Label.setString(label);
    Label.setFont(Fonts::getFont(ROBOTOMONO));
    Label.setFillColor(sf::Color::Black);
    typing.setColor(sf::Color::Black);

    rect.setOutlineThickness(2);
    this->setCharSize(CHARACTER_SIZE);
    rect.setSize({static_cast<float>(typing.getCharSize())*20,static_cast<float>(typing.getCharSize())+5});
    rect.setFillColor(sf::Color::White);
    rect.setOutlineColor(sf::Color::Black);
    Label.setPosition(position);

    this->setPosition({Label.getGlobalBounds().width, position.y});
}

void TextBox::setCharSize(int size)
{
    typing.setCharSize(size);
    c.setCharSize(size);
    Label.setCharacterSize(size);
}
int TextBox::getCharSize()
{
    return Label.getCharacterSize();
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(isClicked(rect,window))
    {
        enableState(HIGHLIGHTED);
        rect.setOutlineThickness(4);
    }
    if(isNotClicked(rect,window))
    {
        disableStates(HIGHLIGHTED);
        rect.setOutlineThickness(2);
    }
    if(checkState(HIGHLIGHTED))
    {
        //TextBoxSnapShot* p = dynamic_cast<TextBoxSnapShot*>(getSnapshot());
        //History::pushHistory({this, p});
        typing.addEventHandler(window, event);
        //if (!typing.empty())
            c.setPosition({typing.getGlobalBounds().width+typing.getGlobalBounds().left,
                           rect.getGlobalBounds().top+typing.getCharSize()/6});
        if(typing.getGlobalBounds().width > rect.getGlobalBounds().width)
            disableStates(HIGHLIGHTED);
    }
}

void TextBox::update()
{
    typing.update();
    c.update();
}

void TextBox::setPosition(sf::Vector2f position)
{
    rect.setPosition(position);
    Label.setPosition(rect.getGlobalBounds().left-Label.getGlobalBounds().width-5, position.y);
    typing.setPosition({position.x+3,position.y});
    c.setPosition({typing.getGlobalBounds().width+typing.getGlobalBounds().left,
                  rect.getGlobalBounds().top-typing.getCharSize()/6});}

/*SnapShot *TextBox::getSnapshot()
{
    TextBoxSnapShot* p = new TextBoxSnapShot;
    p->typing = typing;
    return p;
}

void TextBox::applySnapshot(SnapShot *snapshot)
{
    dynamic_cast<TextBoxSnapShot*>(snapshot);
}*/

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rect);
    target.draw(typing);
    target.draw(Label);
    if(checkState(HIGHLIGHTED))
    target.draw(c);
}

void TextBox::setLabel(std::string label)
{
    this->Label.setString(label);
}

std::string TextBox::getLabel()
{
    return this->Label.getString();
}

void TextBox::setSize(const float &size)
{
    rect.setSize({static_cast<float>(typing.getCharSize())*size,static_cast<float>(typing.getCharSize())+5});
}

sf::Vector2f TextBox::getPosition()
{
    return sf::Vector2f();
}

void TextBox::setString(const std::string &string)
{
    typing.setString(string);
}

std::string TextBox::getString()
{
    return typing.getString();
}

sf::FloatRect TextBox::getGlobalBounds() const
{
    return rect.getGlobalBounds();
}




