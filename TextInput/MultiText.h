//
// Created by minau on 3/16/2023.
//

#ifndef SFML_PROJECT_MULTITEXT_H
#define SFML_PROJECT_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Letter.h"
#include "../Font/Fonts.h"
#include <string>
#include "../Helper/States.h"

class MultiText : public sf::Drawable ,public States{
private:
    std::list<Letter> letterList;
    Letter cursor;
    sf::Font font;
    sf::Vector2f position = {30,30};
    int CharSize = 30;
    sf::Color color = sf::Color::Black;

public:
    typedef std::list<Letter>::iterator iterator;
    typedef std::list<Letter>::const_iterator const_iterator;

    MultiText();


    void setFont(const sf::Font& font);
    void setColor(const sf::Color &color);

    void setCharSize(const int size);
    int getCharSize();

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds();

    bool empty();
    void addLetter(char letter);
    void addLetter(std::string letter);

    void backSpace();

    const std::string& getString();
    unsigned int getSize();
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_MULTITEXT_H
