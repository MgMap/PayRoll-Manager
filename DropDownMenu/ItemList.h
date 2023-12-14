//
// Created by minau on 4/26/2023.
//

#ifndef SFML_PROJECT_ITEMLIST_H
#define SFML_PROJECT_ITEMLIST_H
#include <list>
#include <iterator>
#include "Item.h"
#include "../Helper/MouseEvents.h"
#include "../Helper/GUIComponents.h"

class ItemList: public GUIComponents
{
public:
    std::list<Item> list;
    int listSize = 0;
    int getSize();
public:
    typedef std::list<Item>::iterator iterator;
    typedef std::list<Item>::const_iterator const_iterator;
    bool empty();

    void push(const Item& listItem);
    void push(const std::string& listItem);

    void setPosition(const sf::Vector2f &pos);
    sf::Vector2f getPosition();

    iterator begin();
    iterator end();
    ~ItemList() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFML_PROJECT_ITEMLIST_H
