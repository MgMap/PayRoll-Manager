//
// Created by minau on 4/26/2023.
//

#ifndef SFML_PROJECT_ITEM_H
#define SFML_PROJECT_ITEM_H
#include "../Helper/GUIComponents.h"
#include "../Helper/MouseEvents.h"
#include "../Font/Fonts.h"
#include "../DEFINITIONS.h"
#include "../Helper/Position.h"

class Item: public GUIComponents
{
private:
    std::string itemName;
    sf::Text text;
    sf::Vector2f pos;

    sf::RectangleShape rect;
public:
    Item();
    Item(const std::string& itemName);

    std::string getString() const;
    void setString(const std::string &string);

    void setPosition(const sf::Vector2f pos);
    sf::Vector2f getPosition();

    void setSize(const sf::Vector2f &size);
    sf::Vector2f getSize();

    sf::FloatRect getGlobalBounds() const;

    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);

    ~Item() override;


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    bool empty();


};


#endif //SFML_PROJECT_ITEM_H
