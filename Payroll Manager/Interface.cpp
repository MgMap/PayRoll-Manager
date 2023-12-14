//
// Created by minau on 5/1/2023.
//

#include "Interface.h"


Interface::Interface()
{

}

Interface::~Interface()
{

}

void Interface::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    //sc1.addEventHandler(window,event);
    //sc2.addEventHandler(window,event);
    if(sc1.checkState(SHOWN))
    {
        sc2.disableStates(SHOWN);
        sc1.addEventHandler(window, event);
        sc2.enableState(ENABLED);
    }
    if(!sc1.checkState(SHOWN))
    {
        sc2.enableState(SHOWN);

        sc2.addEventHandler(window,event);
        if(!sc2.checkState(SHOWN))
        {
            sc1.setUserName("");
            sc1.setPassword("");
            sc1.enableState(SHOWN);
        }
        if(sc2.checkState(ENABLED))
        {
            sc2.setFilename("Payroll Manager/data/" + sc1.getUserName() + ".txt");
            sc2.readFile(sc2.getFilename());
            sc2.disableStates(ENABLED);
        }
    }



}

void Interface::update()
{
    if(sc1.checkState(SHOWN))
        sc1.update();
    if(sc2.checkState(SHOWN))
        sc2.update();
}

void Interface::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(sc1.checkState(SHOWN))
        target.draw(sc1);
    if(sc2.checkState(SHOWN))
            target.draw(sc2);
}

