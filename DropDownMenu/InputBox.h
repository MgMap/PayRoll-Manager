//
// Created by minau on 4/26/2023.
//

#ifndef SFML_PROJECT_INPUTBOX_H
#define SFML_PROJECT_INPUTBOX_H
#include "Item.h"

class InputBox :public GUIComponents
{
public:
    Item firstItem;
public:
    InputBox();
    InputBox(const std::string& firstItem_);

    void changeItem(const std::string& newItem);

    std::string getString();

    void setPosition(const sf::Vector2f& pos);

    void resizeBox(const sf::Vector2f &size);

    sf::FloatRect getGlobalBounds() const;

    ~InputBox() override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

private:

    void update() override;

public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool empty();
};


#endif //SFML_PROJECT_INPUTBOX_H
