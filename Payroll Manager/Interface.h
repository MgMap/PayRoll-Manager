//
// Created by minau on 5/1/2023.
//

#ifndef SFML_PROJECT_INTERFACE_H
#define SFML_PROJECT_INTERFACE_H

#include "Screen1.h"
#include "Screen2.h"

class Interface: public GUIComponents
{
private:
    Screen1 sc1;
    Screen2 sc2;
public:
    Interface();

    ~Interface() override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //SFML_PROJECT_INTERFACE_H
