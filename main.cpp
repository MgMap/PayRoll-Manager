#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInput/TextBox.h"
#include "FileTree/FileTree.h"

#include "Payroll Manager/Interface.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 900, 32), "PayRoll Manager");
    window.setFramerateLimit(60);

   Interface anInterface;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
           anInterface.addEventHandler(window,event);

        }
       anInterface.update();

        window.clear(sf::Color::White);
        window.draw(anInterface);
        window.display();

    }
    return 0;
}
