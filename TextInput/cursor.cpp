//
// Created by minau on 3/19/2023.
//

#include "cursor.h"

cursor::cursor()
{
    text.setString("|");
    text.setFont(Fonts::getFont(OPEN_SANS));
    text.setFillColor(sf::Color::Black);

    disableStates(HIDDEN);
}

void cursor::setPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

void cursor::setCharSize(int size)
{
    text.setCharacterSize(size);
}

void cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
    target.draw(text);
}

void cursor::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void cursor::update()
{
    if(clock.getElapsedTime().asSeconds() > 0.5)
    {
        toggleState(HIDDEN);
        clock.restart();
    }

}

/*napShot *cursor::getSnapshot()
{
    return nullptr;
}

void cursor::applySnapshot(SnapShot *snapshot)
{

}*/
