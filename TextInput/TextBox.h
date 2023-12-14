//
// Created by minau on 3/19/2023.
//

#ifndef SFML_PROJECT_TEXTBOX_H
#define SFML_PROJECT_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "../Helper/GUIComponents.h"
#include "Typing.h"
#include "../Helper/MouseEvents.h"
#include "cursor.h"
#include "../DEFINITIONS.h"
//#include "TextBoxSnapShot.h"
//#include "History.h"

class TextBox: public GUIComponents, public MouseEvents
{
private:
    Typing typing;
    cursor c;
    sf::Text Label;

    int CharSize = 20;
    sf::RectangleShape rect;
    sf::Vector2f position ={30,30};
public:
    TextBox();
    TextBox(std::string label);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    sf::FloatRect getGlobalBounds() const;

    void setLabel(std::string label);
    std::string getLabel();

    void setCharSize(int size);
    int getCharSize();

    void setSize(const float &size);

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    void setString(const std::string &string);
    std::string getString();

   // SnapShot* getSnapshot();
    //void applySnapshot(SnapShot* snapshot);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_TEXTBOX_H
