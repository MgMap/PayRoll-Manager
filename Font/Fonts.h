//
// Created by minau on 4/20/2023.
//

#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H
#include <SFML/Graphics.hpp>


enum fontsEnum
{
    OPEN_SANS,
    ROBOTOMONO,
    BASLERVILLE,
    LAST_FONT
};

class Fonts {
private:
    static std::map<fontsEnum, sf::Font> map;
    static void load(fontsEnum font);
    static std::string getPath(fontsEnum font);
public:
    static sf::Font& getFont(fontsEnum font);
};

/*class Fonts
{
private:
    static sf::Font font;
    static void loadFont();
public:

    static sf::Font& getFont();
};*/


#endif //SFML_PROJECT_FONTS_H
