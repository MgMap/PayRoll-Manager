//
// Created by minau on 4/20/2023.
//

#ifndef SFML_PROJECT_POSITION_CPP
#define SFML_PROJECT_POSITION_CPP
#include "Position.h"


template<class T, class S>
void Position::left(const T &obj1, S &obj2, float spacing)
{
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();

    obj2.setPosition({b1.left - b2.width - spacing, b1.top});
}

template<class T, class S>
void Position::right(const T &obj1, S &obj2, float spacing) {
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();

    obj2.setPosition({b1.left + b1.width + spacing, b1.top+5 });

}

template<class T, class S>
void Position::rightAndHalfwayDown(const T &obj1, S &obj2, float spacing) {
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();

    obj2.setPosition({b1.left + b1.width + spacing, b1.top + (b1.height/2)});
}


template<class T, class S>
void Position::center(const T &obj1, S &obj2, float spacing) {
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition({b1.left, b1.top});
}

template<class T, class S>
void Position::bottom(const T &obj1, S &obj2, float spacing) {
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition({b1.left, b1.top + b1.height + spacing});

}

template<class T>
void Position::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}

#endif