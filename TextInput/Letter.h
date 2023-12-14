//
// Created by minau on 3/16/2023.
//

#ifndef SFML_PROJECT_LETTER_H
#define SFML_PROJECT_LETTER_H
#include "Letter.h"
#include "../Font/Fonts.h"
#include <SFML/Graphics.hpp>

class Letter : public sf::Text
        {
        public:
    Letter();
    Letter(const sf::Font& font);
};


#endif //SFML_PROJECT_LETTER_H
