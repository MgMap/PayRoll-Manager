//
// Created by minau on 4/26/2023.
//

#ifndef SFML_PROJECT_DROPDOWNMENU_H
#define SFML_PROJECT_DROPDOWNMENU_H
#include "ItemList.h"
#include "Item.h"
#include "InputBox.h"

class DropDownMenu: public GUIComponents
{
private:
    std::string selected;
public:
    InputBox inputBox;
    ItemList list;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

public:
    DropDownMenu();

    void addItem(const Item &item);
    void addItem(const std::string &string);

    void setPosition(const sf::Vector2f &pos);

    void setSize(const sf::Vector2f &pos);

    ~DropDownMenu() override;

    sf::FloatRect getGlobalBounds();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //SFML_PROJECT_DROPDOWNMENU_H
