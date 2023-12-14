//
// Created by minau on 4/20/2023.
//

#ifndef SFML_PROJECT_MOUSEEVENTS_H
#define SFML_PROJECT_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents
{
public:
    template<class T>
    static bool isHover(const T& Obj, const sf::RenderWindow &window );
    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow &window );
    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow &window );
};

#include "MouseEvents.cpp"
#endif //SFML_PROJECT_MOUSEEVENTS_H
