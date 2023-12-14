//
// Created by minau on 4/27/2023.
//

#include "WordSort.h"
#include <algorithm>
#include <cctype>
#include <string>

void WordSort::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for (int i = 0; i < drawingVec.size(); ++i)
    {
        window.draw(drawingVec[i]); //testing the first 1
    }
}

void WordSort::prioritize(std::string tiText, const TextBox& ti) {
    Heap<Word> heap;

    if (!drawingVec.empty()){
        drawingVec.clear();
    }

    auto wordsStr = fr.getData();
//
    if (!tiText.empty()){
        for (int i = 0; i < wordsStr.size(); ++i)
        {
            Word drawableWord;
            drawableWord.setWord(wordsStr[i]);
            std::transform(wordsStr[i].begin(), wordsStr[i].end(), wordsStr[i].begin(),
                           [](unsigned char c){ return std::tolower(c); });
            for (int j = 0; j < tiText.size(); ++j) {
                if (tiText[j] == wordsStr[i][j]){
                    drawableWord +=1;
                }
            }
//
            std::transform(wordsStr[i].begin(), wordsStr[i].end(), wordsStr[i].begin(), ::toupper);
            for (int j = 0; j < tiText.size(); ++j) {
                if (tiText[j] == wordsStr[i][j]){
                    drawableWord +=1;
                }
            }

            heap.push(drawableWord);
        }
//
        if(!heap.empty())
        {
            for (int i = 0; i < heap.size(); ++i)
            {
                if (heap.getHeap()[i].getPriority() > 0)
                {
                    drawingVec.push_back(heap.getHeap()[i]);
                }
            }
        }
        if(!drawingVec.empty())
            std::sort(drawingVec.begin(),drawingVec.end(),greater<Word>());

        if(!drawingVec.empty())
            Position::bottom(ti,drawingVec[0]);
        for (int i = 1; i < drawingVec.size(); ++i)
        {
            Position::bottom(drawingVec[i-1] , drawingVec[i]);
        }
    }
}

WordSort::WordSort() {
    fr.getData("5000-baby-girl-names.txt");
}

WordSort::WordSort(std::string filename) {
    fr.getData(filename);
}

void WordSort::update() {

}

void WordSort::setPosition(sf::Vector2f position)
{
    this->pos = position;

    if(!drawingVec.empty())
    {
        drawingVec[0].setPosition(pos);
    }
}
