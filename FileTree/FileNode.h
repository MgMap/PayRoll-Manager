//
// Created by minau on 4/23/2023.
//

#ifndef SFML_PROJECT_FILENODE_H
#define SFML_PROJECT_FILENODE_H
#include <SFML/Graphics.hpp>
#include "FileItem.h"
#include "../Helper/GUIComponents.h"
#include "../Helper/MouseEvents.h"
#include "../Helper/Position.h"
#include <iostream>

class FileNode : public GUIComponents
{
public:
    FileItem data;
    std::vector<FileNode*> children;
    int clicks = 0;

    FileItem getData();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event,std::string &name);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void addChild(stateEnum type, std::string name);
    void position() const;
    void reposition() const;

    void setPosition(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds();

};


#endif //SFML_PROJECT_FILENODE_H
