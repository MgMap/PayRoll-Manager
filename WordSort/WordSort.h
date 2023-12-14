//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_WORDSORT_H
#define SFML_PROJECT_WORDSORT_H

#include <vector>
#include "FileReader.h"
#include "Word.h"
#include "../TextInput/TextBox.h"
#include "../Helper/Position.h"
#include "Heap.h"


class WordSort: public sf::Drawable
{
private:
    std::vector<Word> drawingVec;
    sf::Vector2f pos;


public:
    FileReader<std::string> fr;
    WordSort();
    WordSort(std::string filename);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f position);
    void prioritize(std::string tiText, const TextBox& ti);
    void update();
};


#endif //SFML_PROJECT_WORDSORT_H
