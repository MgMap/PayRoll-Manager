//
// Created by minau on 3/19/2023.
//

#ifndef SFML_PROJECT_CURSOR_H
#define SFML_PROJECT_CURSOR_H
#include <SFML/Graphics.hpp>
#include "../helper/GUIComponents.h"
#include "../Font/Fonts.h"
#include "../helper/States.h"

class cursor: public GUIComponents
{
private:
    sf::Text text;
    sf::Font font;
    sf::Clock clock;
public:
    cursor();
    void setPosition(sf::Vector2f position);
    void setCharSize(int size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    //SnapShot* getSnapshot();
    //void applySnapshot(SnapShot* snapshot);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_CURSOR_H
