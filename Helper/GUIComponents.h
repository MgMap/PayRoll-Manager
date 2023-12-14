//
// Created by minau on 4/23/2023.
//

#ifndef SFML_PROJECT_GUICOMPONENTS_H
#define SFML_PROJECT_GUICOMPONENTS_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"

class GUIComponents :public States, public sf::Drawable, public EventHandler
{

};


#endif //SFML_PROJECT_GUICOMPONENTS_H
