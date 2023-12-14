//
// Created by minau on 4/25/2023.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include "../Helper/GUIComponents.h"
#include "../Helper/Position.h"
#include "../Helper/MouseEvents.h"
#include "../Font/Fonts.h"

class Button:public GUIComponents
{
private:
    sf::RectangleShape rect;
    sf::Text text;
public:
    Button();
    Button(std::string str);
    ~Button() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

public:

    sf::Vector2f getPosition();
    void setPosition(const sf::Vector2f &position);

    void setString(const std::string &string);
    std::string getString();

    void setColor(const sf::Color &color);

    sf::FloatRect getGlobalBounds() const;

    sf::Vector2f getSize();
    void setSize(const sf::Vector2f &size);
};


#endif //SFML_PROJECT_BUTTON_H
