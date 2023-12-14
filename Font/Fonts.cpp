//
// Created by minau on 4/20/2023.
//

#include "Fonts.h"

// sf::Font Fonts::font;
std::map<fontsEnum, sf::Font> Fonts::map;

void Fonts::load(fontsEnum font)
{
    map[font].loadFromFile((getPath(font)));
}

std::string Fonts::getPath(fontsEnum font)
{
    switch(font)
    {
        case OPEN_SANS: return "Font/OpenSans-Bold (1).ttf";
        case ROBOTOMONO: return "Font/RobotoMono-Medium.ttf";
        case BASLERVILLE: return "Font/LibreBaskerville-Regular.ttf";
        case LAST_FONT:
            break;
    }
}

sf::Font &Fonts::getFont(fontsEnum font)
{
    load(font);
    return map[font];
}

/*
void Fonts::loadFont()
{
    font.loadFromFile("Font/OpenSans-Bold (1).ttf");
}

sf::Font &Fonts::getFont()
{
    loadFont();
    return font;
}*/
