//
// Created by minau on 3/16/2023.
//

#ifndef SFML_PROJECT_TYPING_H
#define SFML_PROJECT_TYPING_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "MultiText.h"
#include "../Helper/EventHandler.h"

class Typing : public sf::Drawable, EventHandler
        {
private:
   sf::Text text;
   sf::Font font;
   std::string textstr;
public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //void changeColor(std::list<Letter>::iterator start, std::list<Letter>::iterator end, sf::Color color);
    //void checkKeyword(std::list<Letter>::iterator start, std::list<Letter>::iterator end);
    void backSpaceF();

    int getCharSize();
    void setCharSize(const int &size);

    sf::Font getFont();
    void setFont(const sf::Font &font);

    sf::Color getColor();
    void setColor(const sf::Color &color);

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    bool empty();

    void setString(const std::string &string);
    std::string getString();

   /* static bool isOperator(const char& element);
    static bool isNumber(const std::string& str);*/
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};
#endif //SFML_PROJECT_TYPING_H
