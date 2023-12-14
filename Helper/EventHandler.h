//
// Created by minau on 4/23/2023.
//

#ifndef SFML_PROJECT_EVENTHANDLER_H
#define SFML_PROJECT_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler
{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event)=0;
    virtual void update()=0;
};


#endif //SFML_PROJECT_EVENTHANDLER_H
