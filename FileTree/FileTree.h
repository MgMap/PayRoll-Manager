//
// Created by minau on 4/23/2023.
//

#ifndef SFML_PROJECT_FILETREE_H
#define SFML_PROJECT_FILETREE_H
#include <SFML/Graphics.hpp>
#include "FileNode.h"
#include "../helper/GUIComponents.h"
#include <sstream>
#include <iostream>
#include <string>

class FileTree : public GUIComponents
{
private:
    FileNode* root = nullptr;
    std::string last_clicked;
    std::vector<std::string> split(std::string filepath);
    FileNode* search(std::string s, FileNode* node);
public:
    const std::string &getLastClicked() const;

    void setLastClicked(const std::string &lastClicked);

    FileTree();
    void setPosition(sf::Vector2f pos);
    void setRootName(std::string name);
    void push(std::string filepath, stateEnum type);
    void treeClickedHandler();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //SFML_PROJECT_FILETREE_H
