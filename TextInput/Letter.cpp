//
// Created by minau on 3/16/2023.
//

#include "Letter.h"
#include <SFML/Graphics.hpp>


Letter::Letter()
{
    setFont(Fonts::getFont(OPEN_SANS));
}

Letter::Letter(const sf::Font &font)
{
    setFont(font);
}